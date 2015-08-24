#include "LoginServer.h"

#include "InfoParser.h"
#include "AgentInfo.h"

#include "LoginUserManager.h"

#include "AllocServer.h"

NetworkObject * CreateServerSideAcceptedObject();
VOID DestroyServerSideAcceptedObject( NetworkObject *pNetworkObject );
VOID DestroyServerSideConnectedObject( NetworkObject *pNetworkObject );

LoginServer * g_LoginServer = NULL;

LoginServer::LoginServer(void)
{
	m_bShutdown = FALSE;
	m_pIOCPServer = NULL;
	
	m_pDBServerSession = NULL;
	m_pAgentServerSession = NULL;
}

LoginServer::~LoginServer(void)
{
	if ( m_pIOCPServer )
		delete m_pIOCPServer;
}

BOOL LoginServer::Init()
{
	LoginFactory::Instance()->Init();
	BOOL bRet = g_InfoParser.Init( "./ServerInfo.ini" ); // LoginServerIni.
	if ( !bRet ) {
		printf("Parse Server Info fail\n");
		return FALSE;
	}
	
	m_pIOCPServer = new IOCPServer;

	SYNCHANDLER_DESC desc[1];
	
	desc[0].dwSyncHandlerKey			= SERVER_SYNCHANDLER;
	desc[0].dwMaxAcceptSession			= 9;
	desc[0].dwMaxConnectSession			= 9;
	desc[0].dwSendBufferSize			= 2000000;
	desc[0].dwRecvBufferSize		 	= 2000000;
	desc[0].dwTimeOut					= 0;
	desc[0].dwNumberOfAcceptThreads		= 0; // Acceot
	desc[0].dwNumberOfIoThreads			= 10; // 假如为1的话，Login连接了Agent与DB后，Agent发给Login的消息无法正常接收
	desc[0].dwNumberOfConnectThreads	= 1; // Connect
	desc[0].dwMaxPacketSize				= 60000; //4096
	desc[0].fnCreateAcceptedObject		= CreateServerSideAcceptedObject;
	desc[0].fnDestroyAcceptedObject		= DestroyServerSideAcceptedObject;
	desc[0].fnDestroyConnectedObject	= DestroyServerSideConnectedObject;

	if ( !m_pIOCPServer->Init(desc, 1) ) {
		return FALSE;
	}

	// Agent Server
	m_pAgentServerSession = LoginFactory::Instance()->AllocAgentServerSession();
	if ( m_pAgentServerSession ) {
		SERVER_INFO info = g_InfoParser.GetServerInfo( AGENT_SERVER );
		m_pAgentServerSession->SetAddr( info.m_strIp, info.m_dwPort ); // Agent Port 7000
	}
	
	// DB Server
	m_pDBServerSession = LoginFactory::Instance()->AllocDBServerSession();
	if ( m_pDBServerSession ) {
		SERVER_INFO info = g_InfoParser.GetServerInfo( DB_SERVER );
		m_pDBServerSession->SetAddr( info.m_strIp, info.m_dwPort ); // DB Port 7300
	}	
	
	LoginUserManager::Instance()->Init(); 
	
	// 设置代理服务器 最大容纳300个玩家
	AllocServer::Instance()->Init(300); 
	
	// 解析 LoginServer.ini 文件
	bRet = g_AgentInfo.Init( "./LoginInfo.ini" );
	if ( !bRet ) {
		printf("Parse LoginServer.ini fail\n");
		return FALSE;
	}
	int nMax = g_AgentInfo.SaveAgentInfo();
	for(int i=0; i<nMax; ++i)
	{
		SERVER_INFO info = g_AgentInfo.GetAgentInfo(i);
		AgentServerSession * pExtrAgent = LoginFactory::Instance()->AllocAgentServerSession();
		pExtrAgent->SetAddr(info.m_strIp, info.m_dwPort);
		printf("AGENT_SERVER_%d: IP = %s, Port = %d\n", i+1, info.m_strIp, info.m_dwPort); // Port: 8100 8200 8300 8400 8500
		AllocServer::Instance()->PUSH(pExtrAgent);
	}

	return TRUE;	
}

BOOL LoginServer::ConnectToServer( ServerSession * pSession, char * pszIP, WORD wPort )
{
	if (pSession == NULL) {
		return FALSE;
	}
	printf("IP = %s, Port = %d\n", pszIP, wPort);
	
	return m_pIOCPServer->Connect( SERVER_SYNCHANDLER, (NetworkObject *)pSession, pszIP, wPort );
}

BOOL LoginServer::MaintainConnection()
{
	if (m_bShutdown) {
		return TRUE;
	}

	if ( m_pAgentServerSession ) {
		if ( m_pAgentServerSession->TryToConnect() ) {
			ConnectToServer( m_pAgentServerSession, (char *)m_pAgentServerSession->GetConnnectIP().c_str(), m_pAgentServerSession->GetConnnectPort() );
		}
	}
	
	if ( m_pDBServerSession ) {
		if ( m_pDBServerSession->TryToConnect() ) {
			ConnectToServer( m_pDBServerSession, (char *)m_pDBServerSession->GetConnnectIP().c_str(), m_pDBServerSession->GetConnnectPort() );
		}
	}
}

BOOL LoginServer::Update( DWORD dwDeltaTick )
{
	if(m_pIOCPServer)
	{
		m_pIOCPServer->Update();
	}

	// Connect other Servers
	MaintainConnection();
	
	return TRUE;
}

//void LoginServer::Release()
//{
//	
//}

BOOL LoginServer::SendToAgentServer( BYTE * pMsg, WORD wSize)
{
	printf("[LoginServer::SendToAgentServer]\n");
	
	if ( m_pAgentServerSession ) {
		return m_pAgentServerSession->Send( pMsg, wSize );
	}
	return FALSE;
}

BOOL LoginServer::SendToDBServer(BYTE * pMsg, WORD wSize)
{
	printf("[LoginServer::SendToDBServer]\n");
	if (m_pDBServerSession != NULL) {
		return m_pDBServerSession->Send(pMsg, wSize);
	}
	return FALSE;
}

/*************************************************/
NetworkObject * CreateServerSideAcceptedObject() {
	printf("[LoginServer::CreateServerSideAcceptedObject]: Alloc TempServerSession.\n");
	#if 0
	TempServerSession * obj = AgentFactory::Instance()->AllocTempServerSession();
	if ( obj == NULL) {
		printf("\nAgentFactory::Instance()->AllocTempServerSession() Fail.\n");
		return NULL;
	}
	return (NetworkObject *)(obj);
	#endif
}

VOID DestroyServerSideAcceptedObject( NetworkObject *pObjs ) {
	printf("[LoginServer::DestroyServerSideAcceptedObject]: Free GameServerSession.\n");
	#if 0
	GameServerSession * obj = (GameServerSession *)pObjs;
	if ( obj ) {
		printf("AgemtFactory::Instance()->FreeGameServerSession()\n");
		AgentFactory::Instance()->FreeGameServerSession(obj);
	}
	#endif
}

VOID DestroyServerSideConnectedObject( NetworkObject *pNetworkObject ) {
	printf("[LoginServer::DestroyServerSideConnectedObject]: Not Used.\n");
}


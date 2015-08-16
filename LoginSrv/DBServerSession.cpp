#include "DBServerSession.h"

//#include "PacketHandler.h"

DBServerSession::DBServerSession()
{	
}

DBServerSession::~DBServerSession()
{
}

void DBServerSession::Init()
{
	ServerSession::Init();
}


void DBServerSession::Release()
{
	ServerSession::Release();
}

void DBServerSession::Update()
{
	ServerSession::Update();
}

void DBServerSession::OnConnect( BOOL bSuccess, DWORD dwSessionIndex )
{
	ServerSession::OnConnect( bSuccess, dwSessionIndex );
	if ( bSuccess ) {
		printf("[DBServerSession::OnConnect] success.\n");
		printf("Send Server Type.\n");
		
		ServerSession::SendServerType();
	}
}

void DBServerSession::OnDisconnect()
{
	printf("LoginServer : [DBServerSession::OnDisconnect]\n");
	ServerSession::OnDisconnect();
}

void DBServerSession::OnRecv(BYTE *pMsg, WORD wSize)
{
	printf("[DBServerSession::OnRecv]\n");
	printf("call g_PacketHandler.ParsePacket_LD function.\n");
	//g_PacketHandler.ParsePacket_LD( this, (MSG_BASE *)pMsg, wSize );
}

void DBServerSession::OnLogString( char * pszLog)
{
	
}
#include "AgentServerSession.h"

#include "PacketHandler.h"

AgentServerSession::AgentServerSession()
{	
}

AgentServerSession::~AgentServerSession()
{
}

void AgentServerSession::Init()
{
	
}

void AgentServerSession::Release()
{
	
}

void AgentServerSession::Update()
{
	
}

void AgentServerSession::OnRecv(BYTE *pMsg, WORD wSize)
{
	printf("[AgentServerSession::OnRecv]\n");
	printf("call g_PacketHandler.ParsePacket_AG function.\n");
	g_PacketHandler.ParsePacket_GA( this, (MSG_BASE *)pMsg, wSize);
}

void AgentServerSession::OnDisconnect()
{
	
}
	
void AgentServerSession::OnConnect( BOOL bSuccess, DWORD dwNetworkIndex )
{
	printf("GameServer : AgentServerSession::OnConnect\n");
	ServerSession::OnConnect( bSuccess, dwNetworkIndex );
	if ( bSuccess ) {
		printf("[AgentServerSession::OnConnect] -> ServerSession::SendServerType()\n");
		ServerSession::SendServerType();
	}	
}

void AgentServerSession::OnLogString( char * pszLog)
{
	
}
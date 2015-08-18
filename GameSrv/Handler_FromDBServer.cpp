#include "Handler_FromDBServer.h"

#include "GameServer.h"
#include "GameUserManager.h"

#include "CommStruct.h"

Handler_FromDBServer::Handler_FromDBServer() 
{
	
}

Handler_FromDBServer::~Handler_FromDBServer() 
{
	
}


HANDLER_IMPL( GD_Login_ANC )
{
	printf("GD_Login_ANC.\n");
	
	MSG_GD_LOGIN_ANC * pRecvMsg = (MSG_GD_LOGIN_ANC *)pMsg;
	DWORD dwUserID = pRecvMsg->m_dwParameter;
	
	// 分配新用户
	GameUser * pUser = GameFactory::Instance()->AllocGameUser();
	if ( pUser == NULL ) {
		printf("GameFactory::Instance()->AllocGameUser() fail\n");
		return;
		
	}	
	pUser->SetHashKey(dwUserID);
	
	
	MSG_AG_LOGIN_ANC msg2;
	msg2.m_playerInfo.m_dwUserKey 		= dwUserID;
	msg2.m_playerInfo.m_uiDBUserID 		= pRecvMsg->uiRootID;
	msg2.m_playerInfo.m_uiFaileds 		= pRecvMsg->uiFaileds;
	msg2.m_playerInfo.m_uiWons 			= pRecvMsg->uiWons;
	msg2.m_playerInfo.m_uiEscape 		= pRecvMsg->uiEscape;
	msg2.m_playerInfo.m_uiScore 		= pRecvMsg->uiScore;

	pUser->SetPlayerInfo(msg2.m_playerInfo);
	
	g_GameServer->SendToAgentServer( (BYTE *)&msg2, sizeof(msg2) );
}

HANDLER_IMPL( GD_Login_NAK )
{
	printf("GD_Login_NAK.\n");
	
}

HANDLER_IMPL( GD_Logout_REQ )
{
	printf("GD_Logout_REQ.\n");
	
	
}
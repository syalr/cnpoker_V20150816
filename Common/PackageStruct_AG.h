#ifndef _PACKAGESTRUCT_GA_H_INCLUDED_
#define _PACKAGESTRUCT_GA_H_INCLUDED_

#include "PackageStruct.h"
#include "Protocol_AG.h"

#include "CommStruct.h"

#pragma pack(push, 1)


struct MSG_AG_LOGIN_REQ : public MSG_BASE_FORWARD
{
	//DWORD   m_dwUserID;
	unsigned int m_uiRootID;
	
	MSG_AG_START_GAME_REQ() 
	{
		memset( this, 0, sizeof(MSG_AG_START_GAME_REQ) );
		
		m_byCategory = AG_Connect; // 10
		m_byProtocol = AG_StartGame_REQ; // 2000
		
		m_dwParameter = 0; // dwUserID
		m_byParameter = 0;
	}
};

struct MSG_AG_LOGIN_ANC : public MSG_BASE_FORWARD
{
	PlayerInfo m_playerInfo;
	//unsigned int m_uiRootID;
	
	MSG_AG_LOGIN_ANC() 
	{
		memset( this, 0, sizeof(MSG_AG_LOGIN_ANC) );
		
		m_byCategory = AG_Connect; // 10
		m_byProtocol = AG_StartGame_ANC; // 2001
		
		m_dwParameter = 0; // dwUserID
		m_byParameter = 0;
	}
};


struct MSG_AG_START_GAME_REQ : public MSG_BASE_FORWARD
{
	//DWORD   m_dwUserID;
	
	MSG_AG_START_GAME_REQ() 
	{
		memset( this, 0, sizeof(MSG_AG_START_GAME_REQ) );
		
		m_byCategory = AG_Connect; // 10
		m_byProtocol = AG_StartGame_REQ; // 2000
		
		m_dwParameter = 0; // dwUserID
		m_byParameter = 0;
	}
};

struct MSG_AG_START_GAME_ANC : public MSG_BASE_FORWARD
{
	//DWORD   m_dwUserID;
	
	MSG_AG_START_GAME_ANC() 
	{
		memset( this, 0, sizeof(MSG_AG_START_GAME_ANC) );
		
		m_byCategory = AG_Connect; // 10
		m_byProtocol = AG_StartGame_ANC; // 2001
		
		m_dwParameter = 0; // dwUserID
		m_byParameter = 0;
	}
};

struct MSG_AG_START_GAME_NAK : public MSG_BASE_FORWARD
{
	//DWORD   m_dwUserID;
	DWORD 	m_dwErrorCode;
	
	MSG_AG_START_GAME_NAK() 
	{
		memset( this, 0, sizeof(MSG_AG_START_GAME_NAK) );
		
		m_byCategory = AG_Connect; // 10
		//m_byProtocol = AG_StartGame_NAK; // ???
		
		m_dwParameter = 0; // dwUserID
		m_byParameter = 0;
	}
};

struct MSG_AG_JOINROOM_REQ : public MSG_BASE_FORWARD
{
	//DWORD   m_dwUserID;
	unsigned int m_uiRoomNumber;
	
	MSG_AG_JOINROOM_REQ() 
	{
		memset( this, 0, sizeof(MSG_AG_JOINROOM_REQ) );
		
		m_byCategory = AG_Connect; // 10
		m_byProtocol = AG_JoinRoom_REQ; // 2002
		
		m_dwParameter = 0; // dwUserID
		m_byParameter = 0;
	}
};

struct MSG_AG_JOINROOM_ANC : public MSG_BASE_FORWARD
{
	//PlayerInfo m_playerInfo;
	//unsigned int m_byRoomNumber;
	
	MSG_AG_JOINROOM_ANC() 
	{
		memset( this, 0, sizeof(MSG_AG_JOINROOM_ANC) );
		
		m_byCategory = AG_Connect; // 10
		m_byProtocol = AG_JoinRoom_ANC; // 2003
		
		m_dwParameter = 0; // dwUserID
		m_byParameter = 0;
	}
};

struct MSG_AG_JOINTABLE_REQ : public MSG_BASE_FORWARD
{
	//DWORD   m_dwUserID;
	unsigned int m_uiTableNumber;
	//unsigned int m_uiSeat;
	
	MSG_AG_JOINTABLE_REQ() 
	{
		memset( this, 0, sizeof(MSG_AG_JOINTABLE_REQ) );
		
		m_byCategory = AG_Connect; // 10
		m_byProtocol = AG_JoinTable_REQ; // 2004
		
		m_dwParameter = 0; // dwUserID
		m_byParameter = 0;
	}
};

struct MSG_AG_JOINTABLE_ANC : public MSG_BASE_FORWARD
{
	unsigned int m_uiTableNumber;
	
	MSG_AG_JOINTABLE_ANC() 
	{
		memset( this, 0, sizeof(MSG_AG_JOINTABLE_ANC) );
		
		m_byCategory = AG_Connect; // 10
		m_byProtocol = AG_JoinTable_ANC; // 2005
		
		m_dwParameter = 0; // dwUserID
		m_byParameter = 0;
	}
};

// 初始化牌
struct MSG_AG_INITCARDS_BRD : public MSG_BASE_FORWARD
{
	//unsigned int m_uiTableNumber;
	BYTE m_byCards[20];
	
	MSG_AG_INITCARDS_BRD() 
	{
		memset( this, 0, sizeof(MSG_AG_INITCARDS_BRD) );
		
		m_byCategory = AG_Connect; // 10
		m_byProtocol = AG_InitCards_BRD; // ???
		
		m_dwParameter = 0; // dwUserID
		m_byParameter = 0;
	}
};

// 明牌
struct MSG_AG_SHOWCARDS_REQ : public MSG_BASE_FORWARD
{
	//unsigned int m_uiTableNumber;
	
	MSG_AG_SHOWCARDS_REQ() 
	{
		memset( this, 0, sizeof(MSG_AG_SHOWCARDS_REQ) );
		
		m_byCategory = AG_Connect; // 10
		m_byProtocol = AG_ShowCards_REQ; // ???
		
		m_dwParameter = 0; // dwUserID
		m_byParameter = 0;
	}
};

struct MSG_AG_SHOWCARDS_ANC : public MSG_BASE_FORWARD
{
	//unsigned int m_uiTableNumber;
	
	MSG_AG_SHOWCARDS_ANC() 
	{
		memset( this, 0, sizeof(MSG_AG_SHOWCARDS_ANC) );
		
		m_byCategory = AG_Connect; // 10
		m_byProtocol = AG_ShowCards_ANC; // ???
		
		m_dwParameter = 0; // dwUserID
		m_byParameter = 0;
	}
};

// 出牌
struct MSG_AG_DISCARDS_REQ : public MSG_BASE_FORWARD
{
	//unsigned int m_uiTableNumber;
	unsigned int m_uiSize;
	BYTE m_byDiscards[CNPOKER_CARD_LEN_2]; // 最多20张
	
	MSG_AG_DISCARDS_REQ() 
	{
		memset( this, 0, sizeof(MSG_AG_DISCARDS_REQ) );
		
		m_byCategory = AG_Connect; // 10
		m_byProtocol = AG_Discards_REQ; // ???
		
		m_dwParameter = 0; // dwUserID
		m_byParameter = 0;
	}
};

struct MSG_AG_DISCARDS_ANC : public MSG_BASE_FORWARD
{
	//unsigned int m_uiTableNumber;
	
	MSG_AG_DISCARDS_ANC() 
	{
		memset( this, 0, sizeof(MSG_AG_DISCARDS_ANC) );
		
		m_byCategory = AG_Connect; // 10
		m_byProtocol = AG_Discards_ANC; // ???
		
		m_dwParameter = 0; // dwUserID
		m_byParameter = 0;
	}
};


#pragma pack(pop)

#endif // _PACKAGESTRUCT_GA_H_INCLUDED_

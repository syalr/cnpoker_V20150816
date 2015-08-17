#ifndef _PROTOCOLAG_H_INCLUDED_
#define _PROTOCOLAG_H_INCLUDED_

/***** 游戏服务器 -> 代理服务器 *****/
/***** Agent -> Game *****/

enum eAG_Connect_Protocol {
	AG_Heartbeat_SYN 		= 1000,
	AG_Heartbeat_ANC,
};

enum eAG_ClientLogin_Protocol {
	AG_Login_SYN, 				// 登入请求：【临时Key值，玩家ID】
	AG_Login_ANC, 				// 登入请求：【临时Key值，玩家游戏ID】
	AG_Logout_REQ, 				// 退出请求：【临时Key值】
	AG_Logout_ANC, 				// 退出请求：【临时Key值】
};

enum eAG_Game_Protocol {
	AG_StartGame_REQ 		= 2000,
	AG_StartGame_ANC,
	AG_JoinRoom_REQ, 				// 加入房间请求：【玩家X】
	AG_JoinRoom_ANC, 				// 加入房间应答：【房间ID, 玩家{1,2,3}】
	AG_JoinTable_REQ, 				// 加入桌子请求
	AG_JoinTable_ANC 		= 2005, // 加入桌子应答
	//AG_JoinGame_REQ, 				// 加入房加：【玩家X】
	//AG_JoinGame_ANC, 				// 加入房加：【房间ID, 玩家{1,2,3}】
	AG_InitCards_BRD, 				// 服务器给所有玩家发牌：【牌数、牌串】
	
	AG_ShowCards_REQ, 				// 明牌
	
	AG_Discards_BRD, 				// 出牌通知：【玩家ID、开始时间，结束时间】
	AG_Discards_SYN, 				// 玩家出牌：【牌数、牌值串】
	AG_Discards_ANC, 				// 出牌应答：0-不合格、1-合格
	AG_MaxCards_BRD, 				// 单圈胜利：0-不合格、1-合格
	AG_WinPlayer_BRD, 				// 单局胜利：0-不合格、1-合格
	AG_EndGame_SYN,
};

#endif // _PROTOCOLGA_H_INCLUDED_

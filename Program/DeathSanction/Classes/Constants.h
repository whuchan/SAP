//
//  Constants_h
//  ActionGame
//
//
//	汎用・定数定義ファイル
//
#pragma once

//文字コード設定
#pragma execution_character_set("utf-8");

//=========================================================================
//	定数やマクロはここから書く
//=========================================================================

// メモリ解放
#define SAFE_DELETE( p_ ) if ( p_ ) { delete p_ ; p_ = NULL ; }
// 配列メモリ解放
#define SAFE_DELETE_ARRAY( p_ ) if ( p_ ) { delete [] p_ ; p_ = NULL ; }

// イテレーターキャパシティのクリア
template <typename Ty>
void ClearAndSwap( Ty p_ ) { p_->clear() ; Ty().swap( *p_ ) ; }
#define CLEAR_AND_SWAP( p_ ) ClearAndSwap( p_ )

//=========================================================================
//	タグ
//=========================================================================
// CGameMain のタグ
#define TAG_GAME_MAIN (1000)
#define TAG_PLAYER_1 (1001)


#define getCurrentLayer( tag_ ) cocos2d::Director::getInstance()->getRunningScene()->getChildByTag( tag_ )

// ウィンドウサイズ
#define WINDOW_LEFT			(0)
#define WINDOW_TOP			(480)
#define WINDOW_RIGHT		(854)
#define WINDOW_BOTTOM		(0)

#define STAGE_MAX_LINE		(2)

//=========================================================================
//	画像ファイルのマクロはここから書く
//=========================================================================

// プレイヤー
#define IMAGE_PLAYER	"Images/player.png"
//敵
#define IMAGE_ENEMY		"Images/kuribo.png"
//ノコノコ
#define IMAGE_NOKONOKO "Images/nokonoko.png"
//パタパタ
#define IMAGE_PATAPATA "Images/patapata.png"
//キラー
#define IMAGE_KILLER "Images/killer.png"
//ノーマル弾
#define IMAGE_NORMAL_BULLET "Images/normalBullet.png"
//ファイアーボール弾
#define IMAGE_FIREBALL_BULLET "Images/fireBall.png"

//ダメージブロックギミック
#define IMAGE_DAMAGEBLOCK_GIMMICK "Images/damageBlock.png"

//回るブロックギミック
#define IMAGE_ROLLBLOCK_GIMMICK "Images/rollBlock.png"

//落ちるブロックギミック
#define IMAGE_TIKUWABLOCK_GIMMICK "Images/tikuwaBlock.png"

//跳ねるブロックギミック
#define IMAGE_NOTEBLOCK_GIMMICK "Images/noteBlock.png"

//キャラクターの出現するブロックギミック
#define IMAGE_HATENABLOCK_GIMMICK "Images/hatenaBlock.png"


//-------------------------------------------------------------------------
//
// 武器
//
//-------------------------------------------------------------------------
//剣
#define IMAGE_WEAPON_SWORD	"Images/Weapon/Weapon.png"
//斧
#define IMAGE_WEAPON_AX		"Images/Weapon/Weapon.png"
//槍
#define IMAGE_WEAPON_SPEAR	"Images/Weapon/Weapon.png"
//ナイフ
#define IMAGE_WEAPON_KNIFE	"Images/Weapon/Weapon.png"


//-------------------------------------------------------------------------
//
// UI
//
//-------------------------------------------------------------------------
#define IMAGE_PLAYER_HP_BAR			"Images/UI/PlayerHp.png"
#define IMAGE_PLAYER_STAMINA_BAR	"Images/UI/PlayerStamina.png"
#define IMAGE_UI_PUSH_ENTER			"Images/UI/Enter.png"
#define IMAGE_TITLE					"Images/UI/Title.png"


//=========================================================================
//	曲名のマクロはここから書く
//=========================================================================
#define BGM_TITLE	("TitleBGM")
#define BGM_STAGE1	("Stage1BGM")


//=========================================================================
//	サウンドファイルのマクロはここから書く
//=========================================================================
#define SOUND_TITLE_BGM			"Sound/chimamire.mp3"
#define SOUND_SYSTEM_DECIDE		"Sound/Decide.wav"
#define SOUND_STAGE_1_BGM		"Sound/k-sishou.mp3"

//=========================================================================
//	フォントのマクロはここから書く
//=========================================================================


//=========================================================================
//	その他の外部ファイルのマクロはここから書く
//=========================================================================
#define MAP_DATA_SAMPLE "MapData/Stage1_Test.tmx"
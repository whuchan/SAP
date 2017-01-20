//
//  Constants_h
//  ActionGame
//
//
//	�ėp�E�萔��`�t�@�C��
//
#pragma once

//�����R�[�h�ݒ�
#pragma execution_character_set("utf-8");

//=========================================================================
//	�萔��}�N���͂������珑��
//=========================================================================

// ���������
#define SAFE_DELETE( p_ ) if ( p_ ) { delete p_ ; p_ = NULL ; }
// �z�񃁃������
#define SAFE_DELETE_ARRAY( p_ ) if ( p_ ) { delete [] p_ ; p_ = NULL ; }

// �C�e���[�^�[�L���p�V�e�B�̃N���A
template <typename Ty>
void ClearAndSwap( Ty p_ ) { p_->clear() ; Ty().swap( *p_ ) ; }
#define CLEAR_AND_SWAP( p_ ) ClearAndSwap( p_ )

//=========================================================================
//	�^�O
//=========================================================================
// CGameMain �̃^�O
#define TAG_GAME_MAIN (1000)
#define TAG_PLAYER_1 (1001)


#define getCurrentLayer( tag_ ) cocos2d::Director::getInstance()->getRunningScene()->getChildByTag( tag_ )

// �E�B���h�E�T�C�Y
#define WINDOW_LEFT			(0)
#define WINDOW_TOP			(480)
#define WINDOW_RIGHT		(640)
#define WINDOW_BOTTOM		(0)

//=========================================================================
//	�摜�t�@�C���̃}�N���͂������珑��
//=========================================================================

// �v���C���[
#define IMAGE_PLAYER	"Images/player.png"
//�G
#define IMAGE_ENEMY		"Images/kuribo.png"
//�m�R�m�R
#define IMAGE_NOKONOKO "Images/nokonoko.png"
//�p�^�p�^
#define IMAGE_PATAPATA "Images/patapata.png"
//�L���[
#define IMAGE_KILLER "Images/killer.png"
//�m�[�}���e
#define IMAGE_NORMAL_BULLET "Images/normalBullet.png"
//�t�@�C�A�[�{�[���e
#define IMAGE_FIREBALL_BULLET "Images/fireBall.png"

//�_���[�W�u���b�N�M�~�b�N
#define IMAGE_DAMAGEBLOCK_GIMMICK "Images/damageBlock.png"

//���u���b�N�M�~�b�N
#define IMAGE_ROLLBLOCK_GIMMICK "Images/rollBlock.png"

//������u���b�N�M�~�b�N
#define IMAGE_TIKUWABLOCK_GIMMICK "Images/tikuwaBlock.png"

//���˂�u���b�N�M�~�b�N
#define IMAGE_NOTEBLOCK_GIMMICK "Images/noteBlock.png"

//�L�����N�^�[�̏o������u���b�N�M�~�b�N
#define IMAGE_HATENABLOCK_GIMMICK "Images/hatenaBlock.png"



//=========================================================================
//	�T�E���h�t�@�C���̃}�N���͂������珑��
//=========================================================================

//=========================================================================
//	�t�H���g�̃}�N���͂������珑��
//=========================================================================


//=========================================================================
//	���̑��̊O���t�@�C���̃}�N���͂������珑��
//=========================================================================
#define MAP_DATA_SAMPLE "MapData/sampleMapData.tmx"
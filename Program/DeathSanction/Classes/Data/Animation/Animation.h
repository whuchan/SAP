#pragma once

#include "cocos2d.h"
#include "Constants.h"

//================================================================
// �`�b�v�f�[�^�N���X
//	�摜�̂P�����̈ʒu�ƃT�C�Y�f�[�^
//================================================================
typedef cocos2d::Rect CChip;

//================================================================
// �A�j���[�V�����N���X
//	�A�j���[�V�����Ԋu�Ɩ��������Ƃ�
//	���݂̃t���[�������v�Z����N���X
//================================================================
class CAnimation
{
protected:
	//�J�E���^�[
	int m_counter	= 0;
	//�؂�ւ��Ԋu
	int m_interval	= 0;
	//�A�j���[�V��������
	int m_number	= 0;
	//���݂̃t���[����
	int m_currentFrame = 0;
	//���[�v���邩�ǂ����̃t���O
	//true...���[�v����
	bool m_isLoop = false;

	//�A�j���[�V�������I���������ǂ����̃t���O
	//true...�I������
	bool m_isEnd = false;

public:
	//�R���X�^���N�^
	CAnimation(int interval, int number, bool isLoop = false) :
		m_interval(interval), m_number(number), m_isLoop(isLoop)
	{
		
	}

	//�f�X�g���N�^
	virtual ~CAnimation()
	{

	}

	//���݂̃t���[���̎擾
	int getCurrentFrame()
	{
		return this->m_currentFrame;
	}

	//�A�j���[�V�������I���������ǂ���
	bool isEnd()
	{
		return this->m_isEnd;
	}

	/**
	* @desc �J�E���^�[�⌻�݂̃t���[�����̃N���A
	*/
	void clear()
	{
		this->m_counter = 0;
		this->m_currentFrame = 0;
	}

	/**
	* @desc �A�j���[�V�����̍X�V����
	* @return �\������t���[����( -1 ���������܂��s���Ă��Ȃ� �j
	*/
	virtual int update()
	{
		//�A�j���[�V�������I�����Ă��Ȃ���΃J�E���^�[�̍X�V���s��
		if (this->m_isEnd == false)
		{
			this->m_counter++;

			//�J�E���^�[�̐����A�j���[�V���������閇���ȏ�ɂȂ�����J�E���^�[�����Z�b�g����
			if (this->m_counter >= this->m_interval * this->m_number)
			{
				//���[�v����A�j���[�V�����̓J�E���^�[�����Z�b�g����
				if (this->m_isLoop == true)
				{
					this->m_counter = 0;
				}
				else
				{
					//�A�j���[�V�������I���������ǂ����̃t���O�ɑ΂���true������
					this->m_isEnd = true;

					//���[�v���Ȃ��A�j���[�V�����ɑ΂��Ĕ�яo���J�E���^�[���f�N�������g����
					this->m_counter--;
				}
			}
		}

		//�\������t���[����
		this->m_currentFrame = this->m_counter / this->m_interval;
		
		return this->m_currentFrame;
	}

	/**
	* @desc �`�b�v�f�[�^�̒ǉ�
	* @param �`�b�v�f�[�^
	*/
	virtual void addChipData(CChip*) = 0;

	/**
	* @desc ���݃t���[���̃`�b�v���擾����
	* @return ���݃t���[���̃`�b�v
	*/
	virtual CChip getCurrentChip() = 0;

};


//===================================================================
//�`�b�v�A�j���[�V�����N���X
//�A�j���[�V��������摜�����ɕ���ł���ꍇ�݂̂Ɍ���
//�A�j���[�V�����N���X�����Ɍ��݂̃t���[������؂���ׂ��摜���擾
//===================================================================
class CChipAnimation :public CAnimation
{
protected:
	//�Q�Ƃ���`�b�v�f�[�^
	CChip* m_pChip = NULL;
public:
	//�R���X�g���N�^
	CChipAnimation(int interval, int number, bool isLoop = false) :
		CAnimation(interval, number, isLoop)
	{

	}

	//�f�X�g���N�^
	virtual ~CChipAnimation()
	{

	}
	/**
	* @desc �`�b�v�f�[�^�̒ǉ�
	* @param �`�b�v�f�[�^
	*/
	void addChipData(CChip* pChip)override
	{
		this->m_pChip = pChip;
	}

	/**
	* ���݂̃t���[���̃`�b�v���擾
	*/
	virtual CChip getCurrentChip()override
	{
		CChip chip(
			this->m_pChip->size.width * this->m_currentFrame,
			this->m_pChip->origin.y,
			this->m_pChip->size.width,
			this->m_pChip->size.height);

		return chip;
	}
};

//============================================================
//�@�`�b�v�m�b�g�A�j���[�V�����N���X
//  �`�b�v�N���X���A�j���[�V�����N���X�ɓ��������̂�
//  �A�j���[�V���������̈ꖇ�G�̉摜�̕\�����s���ׂ̃L�����N�^�[�𐶐����鎖������ɂȂ�B
//�@�������CChipAnimation������if�����g������ꖇ�G���g�p����N���X�̂݃`�b�v�f�[�^�N���X������������ł��ǂ��̂���
//  ����͏�Ԃɂ���ĉ摜�𕡐���������Ƃ��Ă���̂�
//  CAnimation�̔h���N���X�Ƃ��đ��݂��Ă������������₷��
//  �Ȃ̂ŃA�j���[�V�������Ȃ��A�j���[�V�����N���X���P�p�ӂ��Ă�������
//  �X�}�[�g�ŊJ�����₷���Ȃ�
//============================================================
class CChipNotAnimation : public CChipAnimation
{
public:
	//�R���X�g���N�^
	CChipNotAnimation() :CChipAnimation(0, 0, false)
	{

	}
	
	//�f�X�g���N�^
	~CChipNotAnimation()
	{

	}

	/**
	* @desc �X�V�����͍s�킸�Ԃ��l�͕K���P�ɂȂ�
	*/
	int update()override
	{
		return 1;
	}

	/**
	* @desc�@���݂̃t���[���̃`�b�v���擾����
	* @return ���݂̃t���[���̃`�b�v
	*/
	CChip getCurrentChip()override
	{
		return (*this->m_pChip);
	}
};

//==========================================================================
// �`�b�v���X�g�A�j���[�V����
//�@�摜��������x�o���o���ɕ���ł��Ă��Ή��\����
//�@�`�b�v�f�[�^�̃T�C�Y�͓��ꂳ��Ă��Ȃ���΂Ȃ�Ȃ�
//�@�`�b�v�f�[�^�̃T�C�Y�����ꂳ��Ă��Ȃ��ꍇ�͂���ɉ��������S�ʒu��
//�@�v�Z���Ȃ���΂Ȃ�Ȃ��Ƃ��������l�����邱��
//�@�A�j���[�V�����N���X�����Ɍ��݂̃t���[���̃`�b�v�f�[�^�����X�g����擾
//========================================================================
class CChipListAnimation : public CAnimation
{
protected:
	//�A�j���[�V����������`�b�v�f�[�^�̃��X�g
	std::vector<CChip*> m_chipList;
public:
	//�R���X�g���N�^
	CChipListAnimation(int interval, bool isLoop = false) :CAnimation(interval, 0, isLoop)
	{

	}
	//�f�X�g���N�^
	~CChipListAnimation()
	{
		//�`�b�v�̊J��
		std::vector<CChip*>::iterator itr = this->m_chipList.begin();
		while (itr != this->m_chipList.end())
		{
			SAFE_DELETE((*itr));
			itr++;
		}
	}

	/**
	* @desc �`�b�v�f�[�^�̒ǉ�
	* @param �`�b�v�f�[�^
	*/
	void addChipData(CChip* pChip)override
	{
		//�`�b�v�f�[�^��ǉ�����
		this->m_chipList.push_back(pChip);

		//�`�b�v�f�[�^��ǉ�������A�j���[�V�����̍ő吔���X�V����
		this->m_number = this->m_chipList.size();
	}

	/**
	* @desc ���݂̃t���[���̃`�b�v���擾
	* @return ���݂̃t���[���̃`�b�v
	*/
	virtual CChip getCurrentChip()override
	{
		//�Y�����Z�q�Ŏ擾�����f�[�^���̂�CChip*�Ȃ̂ł��̒��g��Ԃ�
		return *(this->m_chipList[this->m_currentFrame]);
	}
};
#include"Collision.h"

//===================================================================
// �_
//===================================================================
/**
* @desc �_�Ɠ_�̏Փ˔���
* @param �_
*/
bool CCollisionPoint::collision(CCollisionPoint* pPt)
{
	if (this->m_pos.x == pPt->m_pos.x)
	{
		if (this->m_pos.y == pPt->m_pos.y)
		{
			return true;
		}
	}
	return false;
}

/**
* @desc �_�Ƌ�`�̏Փ˔���
* @param ��`
*/
bool CCollisionPoint::collision(CCollisionRect* pRect)
{
	if (this->m_pos.x > pRect->m_body.m_left && this->m_pos.x < pRect->m_body.m_right)
	{
		if (this->m_pos.y > pRect->m_body.m_bottom && this->m_pos.y < pRect->m_body.m_top)
		{
			return true;
		}
	}
	return false;
}

//===================================================================
// ��`
//===================================================================
/**
* @desc ���݈ʒu�Ǝ��̂���Փ˔���p�̋�`��ݒ�
* @param ����
* @param �ʒu
*/
CCollisionRect::CCollisionRect(CBody body, cocos2d::Vec2 pos)
{
	this->m_body.set(	body.m_left + pos.x,
						body.m_top + pos.y,
						body.m_right + pos.x,
						body.m_bottom + pos.y);
}

/**
* @desc ��`�Ɠ_�̏Փ˔���
* @param �_
* @tips CPoint��CRect�̏Փ˔����CPoint�N���X�Ɏ������Ă���̂�
* �����Ƃ��Ď󂯎����pPt����collision���Ăяo��
*/
bool CCollisionRect::collision(CCollisionPoint* pPt)
{
	return pPt->collision(this);
}

/**
* @desc ��`�Ƌ�`�̏Փ˔���
* @param�@��`
*/
bool CCollisionRect::collision(CCollisionRect* pRect)
{
	//�����̉E���ƑΏۂ̍����Ǝ����̍����ƑΏۂ̉E��
	if (this->m_body.m_right > pRect->m_body.m_left && this->m_body.m_left < pRect->m_body.m_right)
	{
		//�����̏㑤�ƑΏۂ̉����Ǝ����̉����ƑΏۂ̏㑤
		if (this->m_body.m_top > pRect->m_body.m_bottom && this->m_body.m_bottom < pRect->m_body.m_top)
		{
			return true;
		}
	}
	//�Փ˂��Ă��Ȃ�
	return false;
}
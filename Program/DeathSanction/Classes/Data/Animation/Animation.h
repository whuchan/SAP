#pragma once

#include "cocos2d.h"
#include "Constants.h"

//================================================================
// チップデータクラス
//	画像の１部分の位置とサイズデータ
//================================================================
typedef cocos2d::Rect CChip;

//================================================================
// アニメーションクラス
//	アニメーション間隔と枚数をもとに
//	現在のフレーム数を計算するクラス
//================================================================
class CAnimation
{
protected:
	//カウンター
	int m_counter	= 0;
	//切り替え間隔
	int m_interval	= 0;
	//アニメーション枚数
	int m_number	= 0;
	//現在のフレーム数
	int m_currentFrame = 0;
	//ループするかどうかのフラグ
	//true...ループする
	bool m_isLoop = false;

	//アニメーションが終了したかどうかのフラグ
	//true...終了した
	bool m_isEnd = false;

public:
	//コンスタラクタ
	CAnimation(int interval, int number, bool isLoop = false) :
		m_interval(interval), m_number(number), m_isLoop(isLoop)
	{
		
	}

	//デストラクタ
	virtual ~CAnimation()
	{

	}

	//現在のフレームの取得
	int getCurrentFrame()
	{
		return this->m_currentFrame;
	}

	//アニメーションが終了したかどうか
	bool isEnd()
	{
		return this->m_isEnd;
	}

	/**
	* @desc カウンターや現在のフレーム数のクリア
	*/
	void clear()
	{
		this->m_counter = 0;
		this->m_currentFrame = 0;
	}

	/**
	* @desc アニメーションの更新処理
	* @return 表示するフレーム数( -1 初期化がまだ行われていない ）
	*/
	virtual int update()
	{
		//アニメーションが終了していなければカウンターの更新を行う
		if (this->m_isEnd == false)
		{
			this->m_counter++;

			//カウンターの数がアニメーションさせる枚数以上になったらカウンターをリセットする
			if (this->m_counter >= this->m_interval * this->m_number)
			{
				//ループするアニメーションはカウンターをリセットする
				if (this->m_isLoop == true)
				{
					this->m_counter = 0;
				}
				else
				{
					//アニメーションが終了したかどうかのフラグに対してtrueを入れる
					this->m_isEnd = true;

					//ループしないアニメーションに対して飛び出たカウンターをデクリメントする
					this->m_counter--;
				}
			}
		}

		//表示するフレーム数
		this->m_currentFrame = this->m_counter / this->m_interval;
		
		return this->m_currentFrame;
	}

	/**
	* @desc チップデータの追加
	* @param チップデータ
	*/
	virtual void addChipData(CChip*) = 0;

	/**
	* @desc 現在フレームのチップを取得する
	* @return 現在フレームのチップ
	*/
	virtual CChip getCurrentChip() = 0;

};


//===================================================================
//チップアニメーションクラス
//アニメーションする画像が横に並んでいる場合のみに限る
//アニメーションクラスを元に現在のフレームから切り取るべき画像を取得
//===================================================================
class CChipAnimation :public CAnimation
{
protected:
	//参照するチップデータ
	CChip* m_pChip = NULL;
public:
	//コンストラクタ
	CChipAnimation(int interval, int number, bool isLoop = false) :
		CAnimation(interval, number, isLoop)
	{

	}

	//デストラクタ
	virtual ~CChipAnimation()
	{

	}
	/**
	* @desc チップデータの追加
	* @param チップデータ
	*/
	void addChipData(CChip* pChip)override
	{
		this->m_pChip = pChip;
	}

	/**
	* 現在のフレームのチップを取得
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
//　チップノットアニメーションクラス
//  チップクラスをアニメーションクラスに統合したので
//  アニメーション無しの一枚絵の画像の表示を行う為のキャラクターを生成する事が困難になる。
//　もちろんCChipAnimation内部でif文を使ったり一枚絵を使用するクラスのみチップデータクラスを持たせたりでも良いのだが
//  今回は状態によって画像を複数扱ったりとしているので
//  CAnimationの派生クラスとして存在していた方が扱いやすい
//  なのでアニメーションしないアニメーションクラスを１つ用意しておく方が
//  スマートで開発しやすくなる
//============================================================
class CChipNotAnimation : public CChipAnimation
{
public:
	//コンストラクタ
	CChipNotAnimation() :CChipAnimation(0, 0, false)
	{

	}
	
	//デストラクタ
	~CChipNotAnimation()
	{

	}

	/**
	* @desc 更新処理は行わず返す値は必ず１になる
	*/
	int update()override
	{
		return 1;
	}

	/**
	* @desc　現在のフレームのチップを取得する
	* @return 現在のフレームのチップ
	*/
	CChip getCurrentChip()override
	{
		return (*this->m_pChip);
	}
};

//==========================================================================
// チップリストアニメーション
//　画像がある程度バラバラに並んでいても対応可能だが
//　チップデータのサイズは統一されていなければならない
//　チップデータのサイズが統一されていない場合はそれに応じた中心位置を
//　計算しなければならないという事を考慮すること
//　アニメーションクラスを元に現在のフレームのチップデータをリストから取得
//========================================================================
class CChipListAnimation : public CAnimation
{
protected:
	//アニメーションさせるチップデータのリスト
	std::vector<CChip*> m_chipList;
public:
	//コンストラクタ
	CChipListAnimation(int interval, bool isLoop = false) :CAnimation(interval, 0, isLoop)
	{

	}
	//デストラクタ
	~CChipListAnimation()
	{
		//チップの開放
		std::vector<CChip*>::iterator itr = this->m_chipList.begin();
		while (itr != this->m_chipList.end())
		{
			SAFE_DELETE((*itr));
			itr++;
		}
	}

	/**
	* @desc チップデータの追加
	* @param チップデータ
	*/
	void addChipData(CChip* pChip)override
	{
		//チップデータを追加する
		this->m_chipList.push_back(pChip);

		//チップデータを追加したらアニメーションの最大数も更新する
		this->m_number = this->m_chipList.size();
	}

	/**
	* @desc 現在のフレームのチップを取得
	* @return 現在のフレームのチップ
	*/
	virtual CChip getCurrentChip()override
	{
		//添字演算子で取得したデータ自体がCChip*なのでその中身を返す
		return *(this->m_chipList[this->m_currentFrame]);
	}
};
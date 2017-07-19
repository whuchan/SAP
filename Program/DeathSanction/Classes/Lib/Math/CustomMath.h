#pragma once
#include "cocos2d.h"

namespace CustomMath
{

	/**
	* @desc 2“_ŠÔ‚Ì‹——£‚ğ‹‚ß‚é
	* @return ‹——£
	*/
	inline float distance(cocos2d::Vec2 vec2Start, cocos2d::Vec2 vec2End)
	{
		return sqrt( ( vec2End.x - vec2Start.x ) * (vec2End.x - vec2Start.x) + (vec2End.y - vec2Start.x) * (vec2End.y - vec2Start.x));
	}









}
/****************************************************************************
	Copyright (c) 2014 , AdamWu calvinmankor@gmail.com
	All rights reserved.

	Use, modification and distribution are subject to the "New BSD License"
    as listed at <url: http://www.opensource.org/licenses/bsd-license.php >.

	COMPANY:  
	CREATED:  2014.09.15
****************************************************************************/


#pragma once

#include <cocos2d.h>

USING_NS_CC;

inline CCPoint boundCenter(const CCRect& b)
{
    return ccp(b.origin.x + b.size.width*0.5f, b.origin.y + b.size.height*0.5f);
}

inline CCPoint boundTopLeft(const CCRect& b)
{
    return ccp(b.origin.x, b.origin.y + b.size.height);
}

inline CCPoint boundTopRight(const CCRect& b)
{
    return ccp(b.origin.x + b.size.width, b.origin.y + b.size.height);
}

inline CCPoint boundBottomLeft(const CCRect& b)
{
    return b.origin;
}

inline CCPoint boundBottomRight(const CCRect& b)
{
    return ccp(b.origin.x + b.size.width, b.origin.y);
}


inline ccBezierConfig ccbz(CCPoint a, CCPoint b, CCPoint c)
{
    ccBezierConfig config;
    config.controlPoint_1 = a;
    config.controlPoint_2 = b;
    config.endPosition = c;

    return config;
}


// Random number generators
inline float randf()
{
    return (float)rand() * (1.0f / (float)RAND_MAX);
}

inline float randf(float max)
{
    return randf() * max;
}

inline float randf(float min, float max)
{
    return randf(max - min) + min;
}


inline bool chance(float percentage)
{
    return randf() < percentage;
}


inline float contentScale()
{
    return CCDirector::sharedDirector()->getContentScaleFactor();
}

inline CCScene* runningScene()
{
    return CCDirector::sharedDirector()->getRunningScene();
}

template<typename T>
T clampx(T val, T min, T max)
{
    return std::min(std::max(val, min), max);
}

inline CCPoint getWorldPosition(CCNode* n)
{
    if(n->getParent())
        return n->getParent()->convertToWorldSpace(n->getPosition());
    else
        return n->getPosition();
}

inline CCFiniteTimeAction* AnimPair(CCActionInterval* a)
{
    return CCSequence::create(a, a->reverse(), NULL);
}

// this correctly handles negative numbers
inline int trueMod(int x, int m)
{
    return (x % m + m) % m;
}

inline int ceil_f(float x, int value=1)
{
	return (int(x)/value)*value;
}

inline CCPoint inWorldSpace(CCNode* node)
{
    if(node->getParent())
        return node->getParent()->convertToWorldSpace(node->getPosition());
    return node->getPosition();
}

inline bool easing(CCNode *target, float tX)
{
	if(target->getPositionX() == tX)
		return true;

	float tempX = target->getPositionX();
	target->setPositionX( tempX + (tX - tempX) * 0.25);

	if(fabsf(tX - target->getPositionX())<0.1 ){
		target->setPositionX(tX);
		return true;
	}
	return false;
}

inline cocos2d::CCSprite *GetSprite(const std::string& filename)
{
	CCSprite *psprite = CCSprite::create();

	// Search in the cache, first
	CCSpriteFrameCache *sfc = CCSpriteFrameCache::sharedSpriteFrameCache();
	CCSpriteFrame *psf = sfc->spriteFrameByName( filename.c_str() );

	std::string::size_type pos;
	if (!psf && (pos=filename.find_last_of('/')) != filename.npos)
	{
		std::string lastPart(filename.begin()+pos+1, filename.end());
		psf = sfc->spriteFrameByName( lastPart.c_str() );
	}

	if(psf)
	{
		psprite->initWithSpriteFrame( psf );
	}
	else
	{
		//        CCLog("WARNING : %s not in a PACK!", filename.c_str() );
		if(!psprite->initWithFile( filename.c_str() ))
		{
			CCLog("ERROR: %s is not in resources", filename.c_str());
			return NULL;
		}
	}
	return psprite;
}
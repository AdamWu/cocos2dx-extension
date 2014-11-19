//
//  Singleton.h
//
//  Created by AdamWu on 13-3-13.
//
//
/**
 *  Singleton Class (template class)
 *  every singleton class derived from it
 */

#ifndef __SINGLETON_H__
#define __SINGLETON_H__

#include "cocos2d.h"

template<class subclass>
class Singleton
{
public:
    static subclass* GetInstance()
    {
        if(!s_instance)
        {
            s_instance = new subclass;
        }
        return s_instance;
    };
	static void DeleteInstance()
	{
		if (s_instance) CC_SAFE_DELETE(s_instance);
	}
    
protected:
    Singleton(){};
    
    static subclass *s_instance;
};

template<class subclass>
subclass* Singleton<subclass>::s_instance = NULL;

#endif //__SINGLETON_H__

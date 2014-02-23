//
//  ItemDelegate.h
//  sangokuCutX
//
//  Created by 厳 巍 on 2014/02/11.
//
//

#ifndef __sangokuCutX__ItemDelegate__
#define __sangokuCutX__ItemDelegate__

#include "cocos2d.h"
using namespace cocos2d;


class ItemDelegate{
    public :
       void virtual onCoinGot(CCSprite *sender)=0;
       void virtual onCoinDisappear(CCSprite *sender)=0;
};

#endif /* defined(__sangokuCutX__ItemDelegate__) */

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
       void onCoinGot(CCSprite *sender);
       void onCoinDisappear:(CCSprite *sender);
};

#endif /* defined(__sangokuCutX__ItemDelegate__) */

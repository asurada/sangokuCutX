//
//  CharacterDelegate.h
//  sangokuCutX
//
//  Created by 厳 巍 on 2014/02/10.
//
//

#ifndef __sangokuCutX__CharacterDelegate__
#define __sangokuCutX__CharacterDelegate__

#include "cocos2d.h"
using namespace cocos2d;



class CharacterDelegate{
   public:
     void onCharacterDead(CCPoint location,CCSprite* sender);
     void onBeforeCharacterDead(CCSprite * sender);
     void onInjureGirl(CCSprite * sender);
     void onInjureBoss(CCPoint location,CCSprite* sender,float rate);
     void onKillBoss(CCSprite *sender);
     void onGotCoint(CCSprite *sender);
     void onCoinDisapper(CCSprite *sender);
};



#endif /* defined(__sangokuCutX__CharacterDelegate__) */


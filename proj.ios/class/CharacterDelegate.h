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
     void virtual onCharacterDead(CCPoint location,CCSprite* sender);
     void virtual onBeforeCharacterDead(CCSprite * sender);
     void virtual onInjureGirl(CCSprite * sender);
     void virtual onInjureBoss(CCPoint location,CCSprite* sender,float rate);
     void virtual onKillBoss(CCSprite *sender);
     void virtual onGotCoint(CCSprite *sender);
     void virtual onCoinDisapper(CCSprite *sender);
};



#endif /* defined(__sangokuCutX__CharacterDelegate__) */


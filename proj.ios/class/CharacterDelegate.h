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
     void virtual onCharacterDead(CCPoint location,CCSprite* sender) =0;
     void virtual onBeforeCharacterDead(CCSprite * sender) =0;
     void virtual onInjureGirl(CCSprite * sender) =0;
     void virtual onInjureBoss(CCPoint location,CCSprite* sender,float rate)=0;
     void virtual onKillBoss(CCSprite *sender) =0;
     void virtual onGotCoint(CCSprite *sender) =0;
     void virtual onCoinDisapper(CCSprite *sender) =0;
};



#endif /* defined(__sangokuCutX__CharacterDelegate__) */


//
//  CoinEffect.cpp
//  sangokuCutX
//
//  Created by 厳 巍 on 2014/02/16.
//
//

#include "CoinEffect.h"

CoinEffect* CoinEffect::spriteWithFile(){
    return (CoinEffect *)super::createWithSpriteFrameName("coinGetEffect_1.png");
}


bool CoinEffect::initSprite(){
    char* fn = new char;
    CCArray *normalAnimFrames = CCArray::create();
    for (int i=1; i<=5; i++) {
        sprintf(fn, "coinGetEffect_%d.png", i);
        CCSpriteFrame* pFrame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(fn);
        normalAnimFrames->addObject(pFrame);
    }
    
    CCAnimation *coinAnim = CCAnimation::create(normalAnimFrames, 0.041f);
    CCAnimate *coinAction = CCAnimate::create(coinAnim);
    
    
    CCCallFunc *callback = CCCallFunc::create(this, callfunc_selector(CoinEffect::coinDisappear));
    this->runAction(CCSequence::create(coinAction,callback));
    return true;
    
}

void CoinEffect::coinDisappear(){
    this->removeAllChildrenWithCleanup(true);
}

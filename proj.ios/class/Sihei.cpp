//
//  Sihei.cpp
//  sangokuCutX
//
//  Created by 厳 巍 on 2014/02/11.
//
//

#include "Sihei.h"

using namespace BaseCharacterSpace;
using BaseCharacterSpace::state;
using cocos2d::CCSprite;

BaseCharacter* Sihei::spriteWithFile(){
    return (BaseCharacter*)super::createWithSpriteFrameName("Sihei_normal_1.png");
}


bool Sihei::initSprite(){
     super::BaseCharacter::initSprite();
    _hp = 1;
    _injureHp = 2;
    _intervalSpaceMove = 125;
    _moveUpSpeed =.3f;
    _moveDownSpeed =.3f;
    _waitingTime = .8f;
    _name = "Sihei";
    return true;
    
}


void Sihei::loadInjureAnim(){
    /*
     NSMutableArray *injureAnimFrames = [NSMutableArray array];
     for (int i=1; i<=12; i++) {
     [injureAnimFrames addObject:
     [[CCSpriteFrameCache sharedSpriteFrameCache] spriteFrameByName:
     [NSString stringWithFormat:@"Siheng_injure_%d.png",i]]];
     }
     self.injureAnim = [CCAnimation animationWithSpriteFrames:injureAnimFrames delay:0.033f];
     */
}



void Sihei::loadAttackAnim(){
    /*
     NSMutableArray *attackAnimFrames = [NSMutableArray array];
     for (int i=1; i<=12; i++) {
     [attackAnimFrames addObject:
     [[CCSpriteFrameCache sharedSpriteFrameCache] spriteFrameByName:
     [NSString stringWithFormat:@"zf_attack_%d.png",i]]];
     }
     self.attackAnim = [CCAnimation animationWithSpriteFrames:attackAnimFrames delay:0.033];
     */
}


void Sihei::loadDeadAnim(){
    _deadSound  = "fingerHit_5.caf";
    char* fn = new char;
    CCArray *deadAnimFrames = CCArray::create();
    for (int i=1; i<=56; i++) {
        sprintf(fn, "Sihei_dead_%d.png", i);
        CCSpriteFrame* pFrame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(fn);
        deadAnimFrames->addObject(pFrame);
    }
    _deadAnim = CCAnimation::create(deadAnimFrames, 0.033f);
}


void Sihei::loadNormalAnim(){
    char* fn = new char;
    CCArray *normalAnimFrames = CCArray::create();
    for (int i=1; i<=14; i++) {
        sprintf(fn, "Sihei_normal_%d.png", i);
        CCSpriteFrame* pFrame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(fn);
        normalAnimFrames->addObject(pFrame);
    }
    _normalAnim = CCAnimation::create(normalAnimFrames, 0.033f);
}






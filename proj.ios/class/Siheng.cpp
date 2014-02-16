//
//  Siheng.cpp
//  sangokuCutX
//
//  Created by 厳 巍 on 2014/02/11.
//
//

#include "Siheng.h"
#include "cocos2d.h"

using namespace BaseCharacterSpace;
using BaseCharacterSpace::state;
using cocos2d::CCSprite;

BaseCharacter *Siheng::spriteWithFile(){
    return (BaseCharacter *)super::createWithSpriteFrameName("Siheng_normal_1.png");
}


bool Siheng::initSprite(){
    super::BaseCharacter::initSprite();
    _hp = 1;
    _injureHp = 2;
    _intervalSpaceMove = 125;
    _moveUpSpeed =.3f;
    _moveDownSpeed =.3f;
    _waitingTime = .8f;
    _name = "siheng";
    return true;
}


void Siheng::loadInjureAnim(){
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



void Siheng::loadAttackAnim(){
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



void Siheng::loadDeadAnim(){
    _deadSound  = "fingerHit_6.caf";
    char* fn = new char;
    CCArray *deadAnimFrames = CCArray::create();
    for (int i=1; i<=56; i++) {
        sprintf(fn, "Siheng_dead_%d.png", i);
        CCSpriteFrame* pFrame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(fn);
        deadAnimFrames->addObject(pFrame);
    }
    _deadAnim = CCAnimation::create(deadAnimFrames, 0.03333f);
}


void Siheng::loadNormalAnim(){
    char* fn = new char;
    CCArray *normalAnimFrames = CCArray::create();
    for (int i=1; i<=14; i++) {
        sprintf(fn, "Siheng_normal_%d.png", i);
        CCSpriteFrame* pFrame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(fn);
        normalAnimFrames->addObject(pFrame);
    }
    _normalAnim = CCAnimation::create(normalAnimFrames, 0.03333f);
    
}



/*
void dealloc(){
   
}

*/
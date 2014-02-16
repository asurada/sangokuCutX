//
//  BossZhangjiao.cpp
//  sangokuCutX
//
//  Created by 厳 巍 on 2014/02/11.
//
//

#include "BossZhangjiao.h"
#include "BaseCharacter.h"

using namespace BaseCharacterSpace;
using BaseCharacterSpace::state;
using cocos2d::CCSprite;

BaseCharacter *BossZhangjiao::spriteWithFile(){
    return (BaseCharacter *)super::createWithSpriteFrameName("BossZhangjiao_normal_1.png");
}


bool BossZhangjiao::initSprite(){
    super::BaseCharacter::initSprite();
    _allHp = _hp = 50;
    _injureHp = 2;
    _intervalSpaceMove = 125;
    _moveUpSpeed =.3f;
    _moveDownSpeed =.3f;
    _waitingTime = 1.8f;
    _name = "BossZhangjiao";
    return true;
    
}


void BossZhangjiao::loadInjureAnim(){
    _hidSound = "fingerHit_4.caf";
    char* fn = new char;
    CCArray *injureAnimFrames = CCArray::create();
    for (int i=1; i<=12; i++) {
        sprintf(fn, "BossZhangjiao_injured_%d.png", i);
        CCSpriteFrame* pFrame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(fn);
        injureAnimFrames->addObject(pFrame);
    }
    _injureAnim = CCAnimation::createWithSpriteFrames(injureAnimFrames);
    
}



void BossZhangjiao::loadAttackAnim(){
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



void  BossZhangjiao::loadDeadAnim(){
    _deadSound  = "fingerHit_3.caf";
    char* fn = new char;
    CCArray *deadAnimFrames = CCArray::create();
    for (int i=1; i<=56; i++) {
        sprintf(fn, "BossZhangjiao_dead_%d.png", i);
        CCSpriteFrame* pFrame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(fn);
        deadAnimFrames->addObject(pFrame);
    }
    _deadAnim = CCAnimation::create(deadAnimFrames, 0.033f);
}


void BossZhangjiao::loadNormalAnim(){
    char* fn = new char;
    CCArray *normalAnimFrames = CCArray::create();
    for (int i=1; i<=14; i++) {
        sprintf(fn, "BossZhangjiao_normal_%d.png", i);
        CCSpriteFrame* pFrame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(fn);
        normalAnimFrames->addObject(pFrame);
    }
    _normalAnim = CCAnimation::create(normalAnimFrames, 0.033f);
}





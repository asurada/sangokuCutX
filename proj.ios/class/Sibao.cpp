//
//  Sibao.cpp
//  sangokuCutX
//
//  Created by 厳 巍 on 2014/02/11.
//
//

#include "Sibao.h"

using namespace BaseCharacterSpace;
using BaseCharacterSpace::state;
using cocos2d::CCSprite;

BaseCharacter *Sibao::spriteWithFile(){
    return (BaseCharacter *)super::createWithSpriteFrameName("Sibao_normal_1.png");
}



bool Sibao::initSprite(){
    super::BaseCharacter::initSprite();
    _hp = 10;
    _injureHp = 2;
    _intervalSpaceMove = 125;
    _moveUpSpeed =.3f;
    _moveDownSpeed =.3f;
    _waitingTime = .8f;
    _name = "Sibao";
    return true;
    
}

//
//void BossZhangjiao::injure(){
//    super::BaseCharacter::injure();
//}

void Sibao::loadInjureAnim(){
    _hidSound = "humanVoice_girl.caf";
    char* fn = new char;
    CCArray *injureAnimFrames = CCArray::create();
    for (int i=1; i<=12; i++) {
        sprintf(fn, "Sibao_injured_%d.png", i);
        CCSpriteFrame* pFrame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(fn);
        injureAnimFrames->addObject(pFrame);
    }
    _injureAnim = CCAnimation::createWithSpriteFrames(injureAnimFrames);

}



void Sibao::loadAttackAnim(){
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



void Sibao::loadDeadAnim(){
    /*
     NSMutableArray *deadAnimFrames = [NSMutableArray array];
     for (int i=1; i<=56; i++) {
     [deadAnimFrames addObject:
     [[CCSpriteFrameCache sharedSpriteFrameCache] spriteFrameByName:
     [NSString stringWithFormat:@"Sibao_dead_%d.png",i]]];
     }
     self.deadAnim = [CCAnimation animationWithSpriteFrames:deadAnimFrames delay:0.033f];
     */
}


void Sibao::loadNormalAnim(){
    char* fn = new char;
    CCArray *normalAnimFrames = CCArray::create();
    for (int i=1; i<=27; i++) {
        sprintf(fn, "Sibao_normal_%d.png", i);
        CCSpriteFrame* pFrame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(fn);
        normalAnimFrames->addObject(pFrame);
    }
    _normalAnim = CCAnimation::create(normalAnimFrames, 0.033f);
    
}


void Sibao::finishInjure(){
    super::BaseCharacter::moveDown();
}





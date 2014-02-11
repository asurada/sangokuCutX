//
//  Siheng.cpp
//  sangokuCutX
//
//  Created by 厳 巍 on 2014/02/11.
//
//

#include "Siheng.h"


CCObject Siheng::spriteWithFile(){
    return super::spriteWithSpriteFrameName("Siheng_normal_1.png");
}


bool initSprite(){
    super->initSprite();
    _hp = 1;
    _injureHp = 2;
    _intervalSpaceMove = 125;
    _moveUpSpeed =.3f;
    _moveDownSpeed =.3f;
    _waitingTime = .8f;
    _name = @"siheng";
    return YES;
    
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
    self.deadSound  = @"fingerHit_6.caf";
    NSMutableArray *deadAnimFrames = [NSMutableArray array];
    for (int i=1; i<=56; i++) {
        [deadAnimFrames addObject:
         [[CCSpriteFrameCache sharedSpriteFrameCache] spriteFrameByName:
          [NSString stringWithFormat:@"Siheng_dead_%d.png",i]]];
    }
    self.deadAnim = [CCAnimation animationWithSpriteFrames:deadAnimFrames delay:0.03333f];
}


void Siheng::loadNormalAnim(){
    NSMutableArray *normalAnimFrames = [NSMutableArray array];
    for (int i=1; i<=14; i++) {
        [normalAnimFrames addObject:
         [[CCSpriteFrameCache sharedSpriteFrameCache] spriteFrameByName:
          [NSString stringWithFormat:@"Siheng_normal_%d.png",i]]];
    }
    self.normalAnim = [CCAnimation animationWithSpriteFrames:normalAnimFrames delay:0.03333];
    
}




void dealloc(){
    [super dealloc];
}


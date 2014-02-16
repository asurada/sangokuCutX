//
//  CoinEffect.cpp
//  sangokuCutX
//
//  Created by 厳 巍 on 2014/02/16.
//
//

#include "CoinEffect.h"

BaseCharacter* CoinEffect::spriteWithFile(){
    return (BaseCharacter *)super::createWithSpriteFrameName("coinGetEffect_1.png");
}


bool CoinEffect::initSprite(){
    
    NSMutableArray *normalAnimFrames = [NSMutableArray array];
    for (int i=1; i<=5; i++) {
        [normalAnimFrames addObject:
         [[CCSpriteFrameCache sharedSpriteFrameCache] spriteFrameByName:
          [NSString stringWithFormat:@"coinGetEffect_%d.png",i]]];
    }
    
    id coinAnim = [CCAnimation animationWithSpriteFrames:normalAnimFrames delay:0.041f];
    id coinAction = [CCAnimate actionWithAnimation:coinAnim];
    
    id callback = [CCCallFunc actionWithTarget:self selector:@selector(coinDisappear)];
    [self runAction:[CCSequence actions:coinAction,callback,nil]];
    return YES;
    
}

-(void)coinDisappear{
    [self removeFromParentAndCleanup:YES];
}

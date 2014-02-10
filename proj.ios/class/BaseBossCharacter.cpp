//
//  BaseBossCharacter.cpp
//  sangokuCutX
//
//  Created by 厳 巍 on 2014/02/10.
//
//

#include "BaseBossCharacter.h"
USING_NS_CC;

using namespace BaseCharacterSpace;
using BaseCharacterSpace::state;

float preDirection = 0.0;

void BaseBossCharacter::finishMoveDown(){
    _state = _standby;
    this->stopAction();
}

void BaseBossCharacter::finishDead(){
    this->unscheduleAllSelectors();
    _injureAnim = NULL;
    _normalAnim = NULL;
    _deadAnim = NULL;
    _attackAnim = NULL;
    _normalAction = NULL;
    _injureAction = NULL;
    _deadAction = NULL;
    _attackAction = NULL;
    _upAction = NULL    ;
    _downAction = NULL;
    
    _injureAnim->release();
    _normalAnim->release();
    _deadAnim->release();
    _attackAnim->release();
    _normalAction->release();
    _injureAction->release();
    _deadAction->release();
    _attackAction->release();
    _upAction->release();
    _downAction->release();
    this->removeFromParentAndCleanup(true);
    
}

void dead(float direction){
    if(_state != _dead){
        if(direction >= 0){
            this->setScaleX(1);
        }else{
            this->setScaleX(-1);
        }
        _state = dead;
        [self stopAction];
        self.position = ccp(self.position.x+(3*self.scaleX), self.position.y+50);
        self.zOrder = 10-(self.index/3)*3;//
        [[SimpleAudioEngine sharedEngine] playEffect:self.deadSound];
        [self.charDelegate onBeforeCharacterDead:self];
        [self.charDelegate onKillBoss:self];
        id animation = [CCAnimate actionWithAnimation:self.deadAnim];
        id action = [CCRepeat actionWithAction:animation times:1];
        id callback = [CCCallFunc actionWithTarget:self selector:@selector(finishDead)];
        _deadAction = [[CCSequence actions:action,callback,nil]retain];
        [self runAction:_deadAction];
    }
}


void BaseBossCharacter::injure(float direction){
    if(preDirection == 0 || ((float)preDirection*direction)<0){
        if(direction >= 0){
            self.scaleX = 1;
        }else{
            self.scaleX = -1;
        }
        if(_hp >0){
            _hp--;
        }
        preDirection = direction;
        _state = injure;
        [[SimpleAudioEngine sharedEngine] playEffect:self.hidSound];
        [self stopNormalAction];
        id injureAnimation = [CCAnimate actionWithAnimation:self.injureAnim];
        id injureRepeat = [CCRepeat actionWithAction:injureAnimation times:1];
        id injureCallback = [CCCallFunc actionWithTarget:self selector:@selector(finishInjure)];
        _injureAction = [[CCSequence actions:injureRepeat,injureCallback,nil]retain];
        
        [self runAction:_injureAction];
        [self.charDelegate onInjureBoss:self.position sender:self bossBloodRate:(float)_hp/(float)_allHp];
    }
    
}


void BaseBossCharacter::finishInjure(){
    this->normal();
}


void BaseBossCharacter::stopNormalAction(){
    _normalAction->stop();
    _attackAction->stop();
    // [_injureAction stop];
}



//
//  BaseBossCharacter.cpp
//  sangokuCutX
//
//  Created by 厳 巍 on 2014/02/10.
//
//

#include "BaseBossCharacter.h"
#include <SimpleAudioEngine.h>
USING_NS_CC;

using namespace CocosDenshion;
using namespace BaseCharacterSpace;
using BaseCharacterSpace::state;
using cocos2d::CCSprite;


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

void BaseBossCharacter::dead(float direction){
    if(_state != _dead){
        if(direction >= 0){
            this->CCSprite::setScaleX(1.0f);
        }else{
            this->CCSprite::setScaleX(-1.0f);
        }
        _state = _dead;
        this->stopAction();
        this->setPosition(ccp(this->getPosition().x+(3*this->getPosition().x), this->getPosition().y+50));
        this->setOrderOfArrival((10-_index/3)*3);
        
        SimpleAudioEngine::sharedEngine()->playEffect(_deadSound.data());
        delegate->onBeforeCharacterDead(this);
        delegate->onKillBoss(this);
        
        CCAnimate *animation = CCAnimate::create(_deadAnim);
        CCRepeat *action = CCRepeat::create(animation,1);
        CCCallFunc *callback =  CCCallFunc::create(this, callfunc_selector(BaseCharacter::finishDead));
        _deadAction =  CCSequence::create(action,callback);
        this->runAction(_deadAction);
    }
}


void BaseBossCharacter::injure(float direction){
    if(preDirection == 0 || ((float)preDirection*direction)<0){
        if(direction >= 0){
            this->CCSprite::setScaleX(1.0f);
        }else{
            this->CCSprite::setScaleX(-1.0f);
        }
        if(_hp >0){
            _hp--;
        }
        preDirection = direction;
        _state = _injure;
        SimpleAudioEngine::sharedEngine()->playEffect(_hidSound.data());
        this->stopNormalAction();
      
        CCAnimate *injureAnimation = CCAnimate::create(_injureAnim);
        CCRepeat *injureRepeat = CCRepeat::create(injureAnimation,1);
        CCCallFunc *injureCallback = CCCallFunc::create(this,callfunc_selector(BaseCharacter::finishInjure));
        _injureAction = CCSequence::create(injureRepeat,injureCallback);
        this->runAction(_injureAction);
        delegate->onInjureBoss(this->getPosition(), this, (float)_hp/(float)_allHp);
    }
    
}


void BaseBossCharacter::finishInjure(){
    this->normal();
}


void BaseBossCharacter::stopNormalAction(){
    _normalAction->stop();
    _attackAction->stop();
}



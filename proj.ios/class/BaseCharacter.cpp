//
//  BaseCharacter.cpp
//  sangokuCutX
//
//  Created by Yan Wei on 2014/02/03.
//
//

#include "BaseCharacter.h"
#include <SimpleAudioEngine.h>

using namespace cocos2d;
using namespace CocosDenshion;

USING_NS_CC;
using namespace BaseCharacterSpace;


bool BaseCharacter::initSprite(){
    _state = _standby;
    this-> loadNormalAnim();
    this-> loadInjureAnim();
    this-> loadDeadAnim();
    this-> loadAttackAnim();
    this-> setScaleX();
    original_Y = this->getPosition().y;
    return true;
}


void BaseCharacter::setScaleX(){
    int result = arc4random()%2;
    if(result == 1){
        this->setScale(-1);
    }else{
        this->setScale(1);
    }
}

void BaseCharacter::injure(float direction){
    SimpleAudioEngine::sharedEngine()->playEffect(_hidSound);
    if(_state != _injure){
        if(_hp >0){
            _hp--;
        }
        if(direction >= 0){
            this->setScale(-1);
        }else{
            this->setScale(1);
        }
        

        _state = _injure;
        this->stopAllActions();
        CCAnimate *injureAnimation = CCAnimate::create(_injureAnim);
        CCRepeat *injureRepeat = CCRepeat::create(injureAnimation,1);
        CCCallFunc *injureCallback =  CCCallFunc::create(this, callfunc_selector(BaseCharacter::finishInjure));
        _injureAction = CCSequence::create(injureRepeat,injureCallback);
        this->runAction(_injureAction);
        delegate->onInjureGirl(this);
    }
}


void BaseCharacter::normal(){
    if(_state != _healthy){
        _normalAction = CCRepeatForever::create(CCAnimate::create(_normalAnim));
        this->runAction(_normalAction);
        _state = _healthy;
        
    }
}


void BaseCharacter::dead(float direction){
    if(_state != _dead){
        if(direction >= 0){
            this->setScale(-1);
        }else{
            this->setScale(1);
        }
        _state = _dead;
        this->stopAction();
    
        this->setOrderOfArrival(10-(_index/3)*3);//
        this->setPosition(ccp(this->getPosition().x+(3*this->getScaleX()), this->getPosition().y+50));
        SimpleAudioEngine::sharedEngine()->playEffect(_deadSound);
        delegate->onBeforeCharacterDead(this);
        CCAnimate *animation = CCAnimate::create(_deadAnim);
        CCRepeat *action = CCRepeat::create(animation,1);;
        CCCallFunc *callback = CCCallFunc::create(this,callfunc_selector(BaseCharacter::finishDead));
        _deadAction = CCSequence::create(action,callback);
        this->runAction(_deadAction);
    }
}

void BaseCharacter::attack(){
    if(_state != _attack && _hasAttack){
        _state = _attack;
        this->stopAction();
        _attackAction = CCRepeatForever::create(CCAnimate::create(_attackAnim));
        this->runAction(_attackAction);
    }
    
}

void BaseCharacter::moveUp(){
    original_Y = this->getPosition().y;
    _state = _movingup;
    CCMoveTo *moveTo = CCMoveTo::create(_moveUpSpeed, ccp(this->getPosition().x,this->getPosition().y+_intervalSpaceMove));
    CCCallFunc *callback = CCCallFunc::create(this,callfunc_selector(BaseCharacter::finishMoveUp));
    this->runAction(CCSequence::create(moveTo,callback));
    this->schedule(schedule_selector(BaseCharacter::moveDown), _waitingTime);
}




void BaseCharacter::moveDown(){
    if(_state != _dead){
        _state = _movingdown;
        this->setOrderOfArrival(7-(_index/3)*3);
        this->unscheduleAllSelectors();
        CCMoveTo* moveTo = CCMoveTo::create(_moveDownSpeed,ccp(this->getPosition().x,original_Y));
        CCCallFunc* callback =CCCallFunc::create(this,callfunc_selector(BaseCharacter::finishMoveDown));
        this->runAction(CCSequence::create(moveTo,callback));
    }
    
}


void BaseCharacter::finishMoveDown(){
    this->stopAction();
    _state = _standby;
    this->removeFromParentAndCleanup(true);
}


void BaseCharacter::finishMoveUp(){
    this->normal();
    this->setOrderOfArrival((11-_index/3)*3);

}

void BaseCharacter::finishDead(){
    this->unscheduleAllSelectors();
    _injureAnim = NULL;
    _normalAnim = NULL;
    _deadAnim = NULL;
    _attackAnim = NULL;
    _normalAction = NULL;
    _injureAction = NULL;
    _deadAction = NULL;
    _attackAction = NULL;
    _upAction = NULL;
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
    delegate->onCharacterDead(this->getPosition(),this);
    this->removeFromParentAndCleanup(true);
    
}

void BaseCharacter::finishInjure(){
    this->normal();
}





state BaseCharacter::getState(){
    return _state;
}

void BaseCharacter::setState(state stt){
    _state = stt;
}

void BaseCharacter::hit(float direction){
    if(_hp > 1){
        this->injure(direction);
    }else if(_hp == 1 && _state != _dead){
        this->dead(direction);
    }
}

void BaseCharacter::stopAction(){
    this->stopAllActions();
}

void BaseCharacter::stopNormalAction(){
    _normalAction->stop();
    _attackAction->stop();
    _injureAction->stop();
}
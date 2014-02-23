//
//  Coin.cpp
//  sangokuCutX
//
//  Created by 厳 巍 on 2014/02/16.
//
//

#include "Coin.h"

Coin* Coin::spriteWithFile(){
    return (Coin *)super::create("coin_1.png");// spriteWithSpriteFrameName:@"coin_1.png"];
}

bool Coin::initSprite(){
    char* fn = new char;
    CCArray *normalAnimFrames = CCArray::create(); //[NSMutableArray array];
    for (int i=1; i<=32; i++) {
        sprintf(fn, "coin_%d.png", i);
        CCSpriteFrame* pFrame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(fn);
        normalAnimFrames->addObject(pFrame);
    }
    CCAnimation *coinAnim =  CCAnimation::create(normalAnimFrames, 0.041f); // [CCAnimation animationWithSpriteFrames:normalAnimFrames delay:0.041f];
    coinAction = CCRepeatForever::create(CCAnimate::create(coinAnim));
    this->runAction(coinAction);
    this->schedule(schedule_selector(Coin::blink_slow),2);
    this->schedule(schedule_selector(Coin::blink_fast),4);
    this->schedule(schedule_selector(Coin::coinDisappear),5.3);
    return true;
    
}


void Coin::gotCoin(){
    
    //id moveTo = [CCMoveTo actionWithDuration:.9f position:ccp(100,400)];
    //[self runAction:[CCSequence actions:moveTo,nil]];
    //ballShapeDef.density = 0.0f;
    //ballBody->SetLinearVelocity(b2Vec2(0/PTM_RATIO,1000/PTM_RATIO));
    if(!_hasGot){
        _hasGot = true;
        this->coinDisappear();
    }
}

void Coin::gotoCoin(CCPoint postition){
    if(ballBody != NULL){
        _world->DestroyBody(ballBody);
        ballBody = NULL;
    }
    
    this->stopAllActions();
    
    effect = CoinEffect::spriteWithFile();
    this->getParent()->addChild(effect);
    effect->setPosition(this->getPosition());
    effect->setOrderOfArrival(20);
    effect->initSprite();
    
    CCMoveTo *moveTo = CCMoveTo::create(0.3, postition); // [CCMoveTo actionWithDuration:0.3 position:postition];
    CCCallFunc *enlargeCoin = CCCallFunc::create(this, callfunc_selector(Coin::onEnlargeCoin)); //[CCCallFunc actionWithTarget:self selector:@selector(onEnlargeCoin)];
    CCCallFunc *touchCoin =  CCCallFunc::create(this, callfunc_selector(Coin::onCoinTouch)); //[CCCallFunc actionWithTarget:self selector:@selector(onCoinTouch)];
    this->runAction(CCSequence::create(moveTo,touchCoin,enlargeCoin));
    
}



void Coin::initPhysics(){
    
    ballBodyDef.type = b2_dynamicBody;
    ballBodyDef.position.Set(this->getPosition().x/PTM_RATIO, this->getPosition().y/PTM_RATIO);
    ballBodyDef.userData = this;
    ballBody = _world->CreateBody(&ballBodyDef);
    
    // Create circle shape
    b2CircleShape circle;
    circle.m_radius = 18.0/PTM_RATIO;
    
    // Create shape definition and add to body
    ballShapeDef.shape = &circle;
    ballShapeDef.density = 10.0f;
    ballShapeDef.friction = 0.f;
    ballShapeDef.restitution = 0.6f;
    
    _ballFixture = ballBody->CreateFixture(&ballShapeDef);
    
    // b2Vec2 force = b2Vec2(10, 10);
    // ballBody->ApplyLinearImpulse(force, ballBodyDef.position);
    ballBody->SetAngularVelocity(0);
    // ballBody->SetLinearVelocity(b2Vec2(0/PTM_RATIO,200/PTM_RATIO));
}


void Coin::setVelocityDirection(float direction){
    ballBody->SetLinearVelocity(b2Vec2((0+direction*10)/PTM_RATIO,200/PTM_RATIO));
}

void Coin::blink_slow(){
    CCBlink* blink = CCBlink::create(2, 25);// actionWithDuration:2 blinks:25];//动作声明，一个闪烁动作
    this->runAction(blink);
}

void Coin::blink_fast(){
    CCBlink* blink = CCBlink::create(1.3, 25);// actionWithDuration:1.3 blinks:25];//动作声明，一个闪烁动作
    this->runAction(blink);
}

void Coin::blink(){
    CCBlink* blink_slow = CCBlink::create(1.3,25);//动作声明，一个闪烁动作
    CCBlink* blink_fast = CCBlink::create(1.3,25);//动作声明，一个闪烁动作
    this->runAction(CCSequence::create(blink_slow,blink_fast));
}



void Coin::coinDisappear(){
    _charDelegate->onCoinDisapper(this);
    this->removeFromParentAndCleanup(true);
    _ballFixture = NULL;
    coinAction = NULL;
}

void  Coin::onEnlargeCoin(){
    this->stopAllActions();
    CCSpriteFrameCache* cache = CCSpriteFrameCache::sharedSpriteFrameCache();
    CCSpriteFrame* frame = cache->spriteFrameByName("coin_7.png");
    this->setDisplayFrame(frame);
    CCEaseInOut *scaleUpAction =  CCEaseInOut::create(CCScaleTo::create(0.2,2),2);
    CCFadeOut *fadeOut = CCFadeOut::create(0.2);
    CCCallFunc *callback = CCCallFunc::create(this,callfunc_selector(Coin::coinDisappear));
    CCSequence *scaleSeqEnlarge=  CCSequence::create(scaleUpAction,callback); //[CCSequence actions:scaleUpAction,callback, nil];
    CCSequence *scaleSeqFadeout= CCSequence::create(fadeOut); //[CCSequence actions:fadeOut, nil];
    this->runAction(scaleSeqEnlarge);
    this->runAction(scaleSeqFadeout);
}

void Coin::onCoinTouch(){
    charDelegate->onGotCoint(this);
}
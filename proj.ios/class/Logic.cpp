//
//  Logic.cpp
//  sangokuCutX
//
//  Created by 厳 巍 on 2014/02/11.
//
//
#include "Logic.h"
#include "BaseCharacter.h"
#include "Coin.h"
#include "Siha.h"
#include "Siheng.h"
#include "HuangjinSiha.h"
#include "HuangjinSihei.h"
#include "HuangjinSiheng.h"
#include "BossZhangjiao.h"
#include "Sibao.h"
#include "Sihei.h"
#include "CCPhysicsSprite.h"
#include "Box2D.h"

using namespace BaseCharacterSpace;

Logic* Logic::iniLogic(Logic *lgc){
    this->_logic = lgc;
    return this;
}

void Logic::loadEnmey(){
    _enemyBox = CCArray::create();
  
    for(int index = 0; index < 9;index++){
        // BaseCharacter* enemy = ;[self createEnemey:index];
        _enemyBox->addObject(CCNode::create());
    }
    _enemyBox->retain();
    _coinBox = CCArray::create();
    _coinBox->retain();
}

BaseCharacter* Logic::createEnemy(int index){
    BaseCharacter* enemy = this->getEnemy();
    enemy->setState(_standby);
    if(enemy->initSprite()){
        enemy->setPosition(CCPointMake(50+(index%3)*110,-25+(index/3)*105));
        int z = 8-(index/3)*3;
        enemy->_index = index;
        _layer->addChild(enemy, z);
    }
    return enemy;
}


BaseCharacter* Logic::createBoss(BaseCharacter *boss,int index){
    boss->setState(_standby);
    if(boss->initSprite()){
        this->setSpritePositon(boss,index);
        _layer->addChild(boss);
    }
    return boss;
}

void Logic::setSpritePositon(BaseCharacter *boss, int index){
    if(boss != NULL){
        boss->setPosition(CCPointMake(50+(index%3)*110,-25+(index/3)*105));
        boss->setOrderOfArrival(8-(index/3)*3);//
        boss->_index = index;
    }
}





BaseCharacter* Logic::getEnemy(){
    int ran = arc4random()%7;
    //NSLog(@"回目= %2d",ran);
    switch (0) {
        case 0:
            return (BaseCharacter*)Siheng::spriteWithFile();
        case 1:
            return Siha::spriteWithFile();
        case 2:
            return Sibao::spriteWithFile();
        case 3:
            return Sihei::spriteWithFile();
        case 4:
            return HuangjinSiha::spriteWithFile();
        case 5:
            return HuangjinSihei::spriteWithFile();
        case 6:
            return HuangjinSiheng::spriteWithFile();
        case 7:
            return BossZhangjiao::spriteWithFile();
        default:
            return NULL;
            break;
    }
}

void Logic::onCharacterDead(CCPoint location,CCSprite *sender){
    int index = _enemyBox->indexOfObject(sender);
   // NSLog(@"dead at %d",index);
    _enemyBox->replaceObjectAtIndex(index,NULL);
}


void Logic::onBeforeCharacterDead(CCSprite *sender){
    Coin *coin = Coin::spriteWithFile();
    if(coin->initSprite()){
        coin->setPosition(ccp(sender->getPosition().x,sender->getPosition().y));
        coin->_world= b2World;
        coin->initPhysics();
        coin->setVelocityDirection(sender->getScaleX());
        _layer->addChild(coin, sender->getOrderOfArrival()+10);
    }
    
     charDelegate->onBeforeCharacterDead(sender);
}


void Logic::onInjureGirl(CCSprite *sender){
    charDelegate->onInjureGirl(sender);
}


void Logic::onKillBoss(CCSprite *sender){
    charDelegate->onKillBoss(sender);
}

void Logic::onInjureBoss(CCPoint location ,CCSprite *sender ,float rate){
    charDelegate->onInjureBoss(location,sender,rate);
}

void Logic::onCoinDisappear(CCSprite *sender){
    //CCLock *cl;
    //cl->lockf(<#int#>, <#int#>, <#off_t#>)
    int index = _coinBox->indexOfObject(sender);
    if(index >= 0){
        CCArray *copy =(CCArray* )_coinBox->copy();
        copy->removeObjectAtIndex(index);
        _coinBox = (CCArray*)copy->copy();
        copy->release();
        
    }
   // unlockpt(1)
    
}

int Logic::showEnemey(int tickCnt){
    return 0;
}




int Logic::showEnemey(int tickCnt,int killedCnt){
    return 0;
}


void Logic:: showBoss(){
    
}


void Logic::onGotCoint(CCSprite *sender){
    
}
void Logic::onCoinDisapper(CCSprite *sender){
    
}
void Logic::onCoinGot(CCSprite *sender){
    
}









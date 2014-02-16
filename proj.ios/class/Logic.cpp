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
    _enemyBox = CCArray::create();
    _coinBox = CCArray::create();
    return new Logic();
}

void Logic::loadEnmey(){
    for(int index = 0; index < 9;index++){
        _enemyBox->addObject(NULL);
    }
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
  //  boss->charDelegate = this;
    if(boss->initSprite()){
        this->setSpritePositon(boss,index);
        _layer->addChild(boss);
    }
    return boss;
}

void Logic::setSpritePositon(BaseCharacter *boss, int index){
    if(boss != nil){
        boss->setPosition(CCPointMake(50+(index%3)*110,-25+(index/3)*105));
        boss->setOrderOfArrival(8-(index/3)*3);//
        boss->_index = index;
    }
}





BaseCharacter* Logic::getEnemy(){
    int ran = arc4random()%7;
    //NSLog(@"回目= %2d",ran);
    switch (ran) {
        case 0:
            return (BaseCharacter *) Siheng::spriteWithFile();
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
            return nil;
            break;
    }
}

void Logic::onCharacterDead(CCPoint location,CCSprite *sender){
    int index = _enemyBox->indexOfObject(sender);
   // NSLog(@"dead at %d",index);
    _enemyBox->replaceObjectAtIndex(index,NULL);
}


void CharacterDelegate::onBeforeCharacterDead(CCSprite *sender){
    Coin *coin = Coin::spriteWithFile();
    if([coin initSprite]){
        coin.position = ccp(sender.position.x,sender.position.y);
        coin.world = self.world;
        [coin initPhysics];
        [coin setVelocityDirection:sender.scaleX];
        [_layer addChild:coin z:sender.zOrder+10];
        [_coinBox addObject:coin];
    }
    
    [charDelegate onBeforeCharacterDead:sender];
}


void CharacterDelegate::onInjureGirl(CCSprite *sender){
    charDelegate->onInjureGirl(sender);
}


void CharacterDelegate::onKillBoss(CCSprite *sender){
    [charDelegate onKillBoss:sender];
}

void CharacterDelegate::onInjureBoss(CCPoint location ,CCSprite *sender ,float rate){
    [charDelegate onInjureBoss:location sender:sender bossBloodRate:rate];
}

void ItemDelegate::onCoinDisappear(CCSprite *sender){
    NSLock *arrayLock = [[NSLock alloc] init];
    [arrayLock lock];
    int index = [_coinBox indexOfObject:sender];
    if(index >= 0){
        NSMutableArray *copy = [_coinBox mutableCopy];
        [copy removeObjectAtIndex:index];
        _coinBox = [copy mutableCopy];
        [copy release];
        
    }
    [arrayLock unlock];
}

int Logic::showEnemey:(int tickCnt){
    return 0;
}



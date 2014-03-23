//
//  Logic.h
//  sangokuCutX
//
//  Created by 厳 巍 on 2014/02/11.
//
//

#ifndef __sangokuCutX__Logic__
#define __sangokuCutX__Logic__

#include "Logic.h"
#include "cocos2d.h"
#include "CharacterDelegate.h"
#include "ItemDelegate.h"
#include "Box2D.h"
#include "BaseCharacter.h"
#include "CharacterDelegate.h"
#include "ItemDelegate.h"

using namespace BaseCharacterSpace;
class Logic:public CCObject, public CharacterDelegate, public ItemDelegate{
    
private:

public:
    CCArray *_coinBox;
    int cnt;
    CCArray *_enemyBox;
    CCLayer *_layer;
    Logic *_logic;
    bool isMyTurn;
    CharacterDelegate *charDelegate;
    typedef BaseCharacter super;
    b2World *b2World;
    BaseCharacter* getEnemy();
    Logic* iniLogic(Logic *logic);
    int showEnemey(int tickCnt,int killedCnt);
    
    BaseCharacter *createEnemy(int index);
    BaseCharacter *createBoss(BaseCharacter *boss,int index);
    void setSpritePositon(BaseCharacter *boss,int index);
    void showBoss();
    int showEnemey(int tickCnt);
   
    void  loadEnmey();
    void  onCharacterDead(CCPoint location,CCSprite* sender);
    void  onBeforeCharacterDead(CCSprite * sender);
    void  onInjureGirl(CCSprite * sender);
    void  onInjureBoss(CCPoint location,CCSprite* sender,float rate);
    void  onKillBoss(CCSprite *sender);
    void  onGotCoint(CCSprite *sender);
    void  onCoinDisapper(CCSprite *sender);
    void  onCoinGot(CCSprite *sender);
    void  onCoinDisappear(CCSprite *sender);
};


#endif /* defined(__sangokuCutX__Logic__) */

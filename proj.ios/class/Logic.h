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
class Logic:CCObject,CharacterDelegate,ItemDelegate{
    
private:
    int cnt;
    CCArray *_enemyBox;
    CCArray *_coinBox;
    CCLayer *_layer;
    Logic *_logic;
    bool isMyTurn;
public:
    typedef BaseCharacter super;
    BaseCharacter* getEnemy();
    Logic* iniLogic(Logic *logic);
    int showEnemey(int tickCnt,int killedCnt);
    void loadEnmey();
    BaseCharacter *createEnemy(int index);
    BaseCharacter *createBoss(BaseCharacter *boss,int index);
    void setSpritePositon(BaseCharacter *boss,int index);
    void showBoss();
    virtual void onCharacterDead(CCPoint location,CCSprite *sender);
};


#endif /* defined(__sangokuCutX__Logic__) */

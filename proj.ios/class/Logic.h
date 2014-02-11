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
#include "GLES-Render.h"
#include "BaseCharacter.h"

class Logic{
    
private:
    int cnt;
    NSMutableArray *_enemyBox;
    NSMutableArray *_coinBox;
    CCLayer *_layer;
    Logic *_logic;
    bool isMyTurn;
public:
    Logic* iniLogic:(Logic *logic);
    int showEnemey:(int tickCnt,int killedCnt);
    void loadEnmey();
    BaseCharacter *createEnemy:(int index);
    BaseCharacter *createBoss:(BaseCharacter *boss int index);
    void setSpritePositon:(BaseCharacter *boss,int index);
    void showBoss();
};


#endif /* defined(__sangokuCutX__Logic__) */

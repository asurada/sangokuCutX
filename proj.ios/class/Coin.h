//
//  Coin.h
//  sangokuCutX
//
//  Created by 厳 巍 on 2014/02/16.
//
//

#ifndef __sangokuCutX__Coin__
#define __sangokuCutX__Coin__
#define PTM_RATIO 32

#include "CoinEffect.h"
#include "cocos2d.h"
#include "Box2D.h"
#include "GLES-Render.h"
#include "ItemDelegate.h"
#include "CoinEffect.h"
#include "CharacterDelegate.h"

class Coin : public CCSprite{
    
public:
    b2World *_world;
    b2Fixture *_ballFixture;
    b2BodyDef ballBodyDef;
    b2Body * ballBody;
public:
    CharacterDelegate *_charDelegate;
    b2FixtureDef ballShapeDef;
    CoinEffect *effect;
    bool _hasGot;
    static Coin* spriteWithFile();
    bool initSprite();
    void gotCoin();
    void initPhysics();
    void coinDisappear();
    void setVelocityDirection(float direction);
    void gotoCoin(CCPoint postition);
    void blink_slow();
    void blink_fast();
    void onEnlargeCoin();
    void onCoinTouch();
    void blink();
    typedef CCSprite super;
    CCAction *coinAction;
    CharacterDelegate* charDelegate;
    
};
//@property (nonatomic, strong)  id<CharacterDelegate> charDelegate;
//@property (nonatomic, strong) CCAction *coinAction;
//@property(nonatomic,assign)b2World *world;
//@property(nonatomic,assign)BOOL hasGot;






#endif /* defined(__sangokuCutX__Coin__) */

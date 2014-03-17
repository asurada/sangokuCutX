//
//  GameScene.h
//  sangokuCutX
//
//  Created by 厳 巍 on 2014/03/03.
//
//

#ifndef __sangokuCutX__GameScene__
#define __sangokuCutX__GameScene__

#include "cocos2d.h"
#include "Box2D.h"
#include "CCBlade.h"
#include "GLES-Render.h"
#include "BaseCharacter.h"
#include "CharacterDelegate.h"
#include "Logic_Showup_01.h"
#include "ItemDelegate.h"
#include "NumberLabel.h"
#include "CCPhysicsSprite.h"

using namespace cocos2d;

class GameScene : public cocos2d::CCLayer, public ItemDelegate, public CharacterDelegate{
public:
    typedef CCLayer super;
    virtual ~GameScene();
    virtual bool init();
    static cocos2d::CCScene* scene();
    
    
    
    CREATE_FUNC(GameScene);
    CCTexture2D *spriteTexture_;	// weak ref
	b2World *world;					// strong ref
	GLESDebugDraw *m_debugDraw;		// strong ref
    //variables for the blade effect
    CCArray *_blades;
    CCBlade *_blade;
    float _deltaRemainder;
    //particle effect for the blade
    CCParticleSystemQuad *_bladeSparkle;
    //the sprite cache
    CCArray *_cache;
    CCSprite *_zombiIcon;
    CCSprite *_coinIcon;
    CCSprite *_bossIcon;
    CCSprite *_bossBlood;
    CCSprite *_bossBloodBg;
    CCLabelAtlas *_zombiLabel;
	CCLabelAtlas *_coinLabel;
    //  Zhangfei *zf;
    CCSprite *hit;
    CCAnimation *hitAnim;
    BaseCharacter *hitTarget;
    Logic_Showup_01 *logic;
    NumberLabel *number;
    int coinCount;
    int enemyCount;
    void initPhysics();
    void addNewSpriteAtPosition(CCPoint point);
   
    
    void initHUD();
    void hogehoge();
    void initBackground_iphone5();
    virtual void draw();
    void update(float32 c);
    void hitObject(CCTouch *touch,CCPoint *location);
    virtual void ccTouchesBegan(CCSet *touches, CCEvent *event);
    virtual void ccTouchesMoved(CCSet *touches, CCEvent *event);
    virtual void ccTouchesEnded(CCSet *touches, CCEvent *event);
    void hitFinishedAnimation(CCSprite *mHit);
   
    void playHit(BaseCharacter *enemy);
    void pushSpriteButton(CCSprite *sender);
    
    virtual void onBeforeCharacterDead(CCSprite *sender);
    virtual void onInjureGirl(CCSprite *sender);
    virtual void onKillBoss(CCSprite *sender);
    virtual void onCharacterDead(CCPoint location,CCSprite* sender);
    virtual void onInjureBoss(CCPoint location,CCSprite* sender,float rate);
    virtual void onGotCoint(CCSprite *sender);
    virtual void onCoinDisapper(CCSprite *sender);
    virtual void onCoinGot(CCSprite *sender);
    virtual void onCoinDisappear(CCSprite *sender);
    void createLabel();
//    ~GameScene(){
//        delete world;
//        world = NULL;
//        delete m_debugDraw;
//        m_debugDraw = NULL;
//    }
    //GameScene();
    

};

#endif /* defined(__sangokuCutX__GameScene__) */

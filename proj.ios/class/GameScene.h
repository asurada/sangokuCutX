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
#import "CCBlade.h"
#import "GLES-Render.h"
#import "BaseCharacter.h"
#import "CharacterDelegate.h"
#import "Logic_Showup_01.h"
#import "ItemDelegate.h"
#import "NumberLabel.h"

using namespace cocos2d;

class GameScene : public cocos2d::CCLayer{
public:
    
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
    static CCScene* scene();
    virtual bool init();
    void initBackground_iphone5();
    CREATE_FUNC(GameScene);
};

#endif /* defined(__sangokuCutX__GameScene__) */


//  GameScene.cpp
//  sangokuCutX
//
//  Created by 厳 巍 on 2014/03/03.
//
//

#include "GameScene.h"
#include "CCBlade.h"
#include "Coin.h"
#include "EnemyData.h"
#include "CCButton.h"
#include "SceneStartup.h"
#include "SimpleAudioEngine.h"
#include "NumberLabel.h"
#include "TouchTrailLayer.h"

USING_NS_CC;


enum {
	kTagParentNode = 1,
};


CCRect *particularSpriteRect;
CCRect *halfParticularSpriteRect;
CCRect original;
CCArray * bloods;
int bloodCount = 5;
bool isCutting = false;
//const CGPoint WSSCGPointNull = {(CCFloat)NAN, (CCFloat)NAN};
CCPoint *prePoint = NULL;
float preDirect = 0.0;
int tickCnt;




CCScene* GameScene::scene()
{
    
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    GameScene *layer = (GameScene *)GameScene::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
    
}
    
bool GameScene::init()
{
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();
    

    this->initPhysics();
    
     logic->_layer = this;
     logic->b2World = world;
     logic->charDelegate = this;
        

     this->initBackground_iphone5();
        
        
     CCSize winSize = CCDirector::sharedDirector()->getWinSize();
        
        
        
     // initialize the blade effect
     _deltaRemainder = 0.0;
     _blades = CCArray::createWithCapacity(3);
     CCTexture2D *texture = CCTextureCache::sharedTextureCache()->addImage("Deco_shine_v1.png");
    
    TouchTrailLayer *layer = TouchTrailLayer::create();
    addChild(layer);
    
    /*
    for (int i = 0; i < 3; i++)
    {
    
        CCBlade *blade = CCBlade::bladeWithMaximumPoint(30);
        
        blade->dim(true);
        
        blade->setTexture(texture);
        
        this->addChild(blade,14);
        _blades->addObject(blade);
      }
        */
        
        // initialize the blade sparkle particle effect

    
    _bladeSparkle = CCParticleSystemQuad::create("blade_sparkle.plist");
    
    _bladeSparkle->stopSystem();
    
    
    this->addChild(_bladeSparkle,14);
    
    this->initHUD();
    
    
    this->schedule(schedule_selector(GameScene::hogehoge),0.1f);
        
    
    logic->loadEnmey();
        
    
    this->setTouchEnabled(true);
    
    CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic("bgMusic_loop_5.caf", true);
  
    this->scheduleUpdate();
	

    return true;
}





void GameScene::initPhysics(){
	
	CCSize s = CCDirector::sharedDirector()->getWinSize();

	
	b2Vec2 gravity;
	gravity.Set(0.0f, -40.0f);
	world = new b2World(gravity);
	
	
	// Do we want to let bodies sleep?
	world->SetAllowSleeping(true);
	
	world->SetContinuousPhysics(true);
	
	m_debugDraw = new GLESDebugDraw( PTM_RATIO );
	world->SetDebugDraw(m_debugDraw);
	
	uint32 flags = 0;
	flags += b2Draw::e_shapeBit;
	//		flags += b2Draw::e_jointBit;
	//		flags += b2Draw::e_aabbBit;
	//		flags += b2Draw::e_pairBit;
	//		flags += b2Draw::e_centerOfMassBit;
	m_debugDraw->SetFlags(flags);
	
	
	// Define the ground body.
	b2BodyDef groundBodyDef;
	groundBodyDef.position.Set(0, 0); // bottom-left corner
	
	// Call the body factory which allocates memory for the ground body
	// from a pool and creates the ground box shape (also from a pool).
	// The body is also added to the world.
	b2Body* groundBody = world->CreateBody(&groundBodyDef);
	
	// Define the ground box shape.
	b2EdgeShape groundBox;
	
	// bottom
	
	groundBox.Set(b2Vec2(0,0), b2Vec2(s.width/PTM_RATIO,0));
	groundBody->CreateFixture(&groundBox,0);
	
	// top
	groundBox.Set(b2Vec2(0,s.height/PTM_RATIO), b2Vec2(s.width/PTM_RATIO,s.height/PTM_RATIO));
	groundBody->CreateFixture(&groundBox,0);
	
	// left
	groundBox.Set(b2Vec2(0,s.height/PTM_RATIO), b2Vec2(0,0));
	groundBody->CreateFixture(&groundBox,0);
	
	// right
	groundBox.Set(b2Vec2(s.width/PTM_RATIO,s.height/PTM_RATIO), b2Vec2(s.width/PTM_RATIO,0));
	groundBody->CreateFixture(&groundBox,0);
}

void GameScene::draw()
{
	//
	// IMPORTANT:
	// This is only for debug purposes
	// It is recommend to disable it

	super::draw();

	
	ccGLEnableVertexAttribs( kCCVertexAttribFlag_Position );
	
	kmGLPushMatrix();
	
	world->DrawDebugData();
	
	kmGLPopMatrix();
    
   // if(!CCRectIsEmpty(particularSpriteRect)){
        // glEnable(GL_LINE_SMOOTH);
        //  glColor4ub(255, 255, 255, 255);
        //  glLineWidth(2);
        //  CGPoint vertices2[] = { original.origin, particularSpriteRect.origin};
        //ccDrawPoly(vertices2, 4, YES);
        
        ccDrawColor4B(255, 255,255, 255);
        ccDrawRect(particularSpriteRect->origin, ccpAdd(particularSpriteRect->origin, (ccp(particularSpriteRect->size.width,particularSpriteRect->size.height))));
        //ccDrawRect(particularSpriteRect.origin,ccp(particularSpriteRect.origin.x+particularSpriteRect.size.width, particularSpriteRect.origin.y+particularSpriteRect.size.height));
   // }
    
    //    if(!CGRectIsEmpty(particularSpriteRect)){
    //       CGContextRef ctx = UIGraphicsGetCurrentContext();
    //       CGContextSetRGBFillColor(ctx, 1.0, 0.0, 0.0, 1.0);
    //       CGContextFillRect(ctx, particularSpriteRect);
    //    }
}



void GameScene::hogehoge()
{
    tickCnt++;
    tickCnt = logic->showEnemey(tickCnt,enemyCount);
}





void  GameScene::update(float32 dt)
{
	//It is recommended that a fixed time step is used with Box2D for stability
	//of the simulation, however, we are using a variable time step here.
	//You need to make an informed choice, the following URL is useful
	//http://gafferongames.com/game-physics/fix-your-timestep/
	
	int32 velocityIterations = 8;
	int32 positionIterations = 1;
	
	// Instruct the world to perform a single step of simulation. It is
	// generally best to keep the time step and iterations fixed.
	world->Step(dt, velocityIterations, positionIterations);
	
    for(b2Body *b = world->GetBodyList(); b; b=b->GetNext()) {
        if (b->GetUserData() != NULL) {
            CCSprite *ballData = (CCSprite *)b->GetUserData();
            ballData->setPosition(ccp(b->GetPosition().x * PTM_RATIO,
                                    b->GetPosition().y * PTM_RATIO));
            ballData->setRotation(-1 * CC_RADIANS_TO_DEGREES(b->GetAngle()));
            
        }
    }
}





/*
 * Initializes everything in the background
 */
void GameScene::initBackground_iphone5()
{

    CCSize screen = CCDirector::sharedDirector()->getWinSize();

    int height = 0;
    int diff = 568.0 - screen.height;
    
    CCSpriteBatchNode *spriteSheet = CCSpriteBatchNode::create("bg.png");
    this->addChild(spriteSheet);
    // add the background image
    CCSprite *background_01 =CCSprite::create("layer_1.png");// [CCSprite spriteWithFile:@"Bg_iPhone5_01.png"];
    background_01->setPosition(ccp(screen.width/2,screen.height + diff - background_01->getContentSize().height/2));//415
    this->addChild(background_01,0);
    
    height = background_01->getContentSize().height;
    CCSprite *background_02 = CCSprite::create("layer_2.png");
    background_02->setPosition(ccp(screen.width/2,screen.height + diff - height - background_02->getContentSize().height/2));
    this->addChild(background_02,3);
    
    height = height + background_02->getContentSize().height;
    CCSprite *background_03 = CCSprite::create("layer_3.png");
    background_03->setPosition(ccp(screen.width/2,screen.height + diff - height - background_03->getContentSize().height/2));
    this->addChild(background_03,6);
    
    height = height + background_03->getContentSize().height;
    CCSprite *background_04 = CCSprite::create("layer_4.png");
    background_04->setPosition(ccp(screen.width/2,screen.height + diff - height - background_04->getContentSize().height/2));
    this->addChild(background_04,9);
    
}

#pragma mark - Controls


                               
/*
 * The touch start logic
 */

void GameScene::ccTouchesBegan(CCSet *touches, CCEvent *event)
{
    CCSetIterator it = touches->begin();
    CCTouch* touch;
    
    CCPoint pt;
    for( int iTouchCount = 0; iTouchCount < touches->count(); iTouchCount++ )
    {
        touch = (CCTouch*)(*it);
       // pt = touch->getLocationInView();
       // printf( "ccTouchesBegan id:%i %i,%i\n", touch->getID(), (int)pt.x, (int)pt.y );
       // it++;
        
        CCPoint location = touch->getLocationInView();// [touch locationInView:[touch view]];
        //location = [CCDirector sharedDirector] convertToGL:location];

        
        // move the start and end of the ray cast to the touch
        //startPoint = location;
        //_endPoint = location;
        
        /*
        // get an unused blade and move it to the touch
        CCBlade *blade;
        CCObject *object;
        CCARRAY_FOREACH(_blades, object)
        {
            blade = (CCBlade *)object;
            if (blade->count == 0)
            {
                _blade = blade;
                _blade->push(location);
                break;
            }
        }
        
        // move the sparkle to the touch
        _bladeSparkle->setPosition(location);
        _bladeSparkle->resetSystem();
        
        this->hitObject(touch,&location);
        */

    }

}


void GameScene::hitFinishedAnimation(CCSprite *mHit)
{
    
    mHit->removeFromParent();
    mHit = NULL;
    mHit->release();
}




/*
 * The touch moved logic
 */
void GameScene::ccTouchesMoved(CCSet *touches, CCEvent *event)
{
    CCSetIterator it = touches->begin();
    CCTouch* touch;
    
    CCPoint pt;
    for( int iTouchCount = 0; iTouchCount < touches->count(); iTouchCount++ ){
        touch = (CCTouch*)(*it);
        // pt = touch->getLocationInView();
        // printf( "ccTouchesBegan id:%i %i,%i\n", touch->getID(), (int)pt.x, (int)pt.y );
        // it++;
    
        CCPoint location = touch->getLocation();// [touch locationInView:[touch view]];
        /*
         // end point follows the touch
         _endPoint = location;
         
         // ray cast every 5 points of movement
         if (ccpLengthSQ(ccpSub(_startPoint, _endPoint)) > 25)
         {
         // ray cast twice because a fixture can only be intersected in one direction once per ray cast
         world->RayCast(_raycastCallback,
         b2Vec2(_startPoint.x / PTM_RATIO, _startPoint.y / PTM_RATIO),
         b2Vec2(_endPoint.x / PTM_RATIO, _endPoint.y / PTM_RATIO));
         
         world->RayCast(_raycastCallback,
         b2Vec2(_endPoint.x / PTM_RATIO, _endPoint.y / PTM_RATIO),
         b2Vec2(_startPoint.x / PTM_RATIO, _startPoint.y / PTM_RATIO));
         
         // adjust the start point after the ray cast
         _startPoint = _endPoint;
         }
         */
        // add a point to the blade
        _blade->push(location);
        
        //ccTime deltaTime = _timeCurrent - _timePrevious;
        //_timePrevious = _timeCurrent;
        
        // calculate the velocity (distance / time)

        CCPoint oldPosition = _bladeSparkle->getPosition();
        
        // sparkle follows the touch
        _bladeSparkle->setPosition(location);
        
        this->hitObject(touch, &location);
    

        
        
        
        /*
         // play the sound if velocity is past a certain value
         if (ccpDistance(_bladeSparkle.position, oldPosition) / deltaTime > 1000)
         {
         if (!_swoosh.isPlaying)
         {
         // play sound only if it is not playing
         [_swoosh play];
         }
         }*/
    }
}



void GameScene::onBeforeCharacterDead(CCSprite *sender){
    enemyCount++;
    char* fn = new char;
    sprintf(fn, "Siheng_dead_%d.png", enemyCount);
    _zombiLabel->setString(fn);
    
}

void GameScene::onInjureGirl(CCSprite *sender){

    if(bloods!= NULL && bloods->count() >0){
        CCSprite *blood = (CCSprite *)bloods->objectAtIndex(bloods->count()-1);// objectAtIndex:[bloods count]-1];

        bloods->removeObject(blood);
        blood->removeFromParentAndCleanup(true);
        if(bloods->count() == 0){
            
        }
    }
    
}



void GameScene::onInjureBoss(CGPoint location,CCSprite *sender,float rate){
    // _bossBlood.contentSize.width = _bossBlood.contentSize.width*rate;
    _bossBlood->setScaleX(rate);
    _bossBlood->setPosition(ccp(_bossIcon->getPosition().x + _bossBlood->getContentSize().width*rate/2 + 20,_bossIcon->getPosition().y));

    
}



void GameScene::onKillBoss(CCSprite *sender){
    _bossBlood->setScaleX(0);
}



void GameScene::hitObject(CCTouch *touch ,CCPoint *location){

    float direction = 0;
    if(prePoint == NULL){
        prePoint = location;
    }else{
        direction = location->x-prePoint->x;
        prePoint = location;
    }
    

    CCObject * object;
    CCARRAY_FOREACH(logic->_enemyBox, object){
        BaseCharacter *enemy = (BaseCharacter*)object;
        if(enemy == NULL){
            continue;
        }
        CCPoint touchLocation = this->convertTouchToNodeSpace(touch);

        particularSpriteRect = new CCRect(enemy->getPosition().x-27, enemy->getPosition().y-50, 54,80);
        halfParticularSpriteRect = new CCRect(enemy->getPosition().x-27, enemy->getPosition().y-50, 27,80);
        // original = CGRectMake(enemy.position.x-27, enemy.position.y-50, 0,0);
        if (particularSpriteRect->containsPoint(touchLocation)) {
            if(enemy!= nil &&
               enemy != NULL &&
               enemy->_hp>0 &&
               enemy->getState() != _dead &&
               enemy->getState() != _standby &&
               enemy->getState() != _movingup &&
               enemy->getState() != _movingdown &&!isCutting){

                isCutting = true;
                if(direction != 0){
                    enemy->hit(direction);
                    if(preDirect == 0.0){

                        this->playHit(enemy);

                    }else if(((float)preDirect * direction)<0){
                        this->playHit(enemy);
                    }
                }else{

                    if(halfParticularSpriteRect->containsPoint(touchLocation)){
                        enemy->hit(1);
                    }else{
                        enemy->hit(-1);
                    }
                    this->playHit(enemy);


                }
                preDirect = direction;
            }else{
                
            }
        }else{
            isCutting = false;
        }
    }
    
    
    //NSLog(@"coinBox count: %d",logic.coinBox.count);

    for (int index=0; index<logic->_coinBox->count(); index++) {
        Coin *coin = (Coin *)logic->_coinBox->objectAtIndex(index);
        coin->charDelegate = this;
        CCPoint touchLocation = this->convertTouchToNodeSpace(touch);
        CCRect *particularSpriteRect = new CCRect(coin->getPosition().x, coin->getPosition().y, coin->getContentSize().width,coin->getContentSize().height);
        if (particularSpriteRect->containsPoint(touchLocation)) {
            coin->gotoCoin(ccp(26,510));

            //[_coinLabel setString:[NSString stringWithFormat:@"%d",coinCount]];
            return;
        }
    }
}

void GameScene::playHit(BaseCharacter *enemy){
    hit = CCSprite::create("hit_normal.png");
    hit->setPosition(enemy->getPosition());//ccp(enemy.position.x,enemy.position.y);
    this->addChild(hit,15);
    CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("hit.plist");
    CCArray *hitAnimFrames = CCArray::create();
    
    char* fn = new char;
    for (int i=0; i<=4; i++) {
        sprintf(fn, "sheet_256x256_%d.png", i);
        hitAnimFrames->addObject(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(fn));
    }
    
    hitAnim = CCAnimation::create(hitAnimFrames, 0.07f);
    CCAnimate *hitAnimation = CCAnimate::create(hitAnim);
    CCRepeat *repeat = CCRepeat::create(hitAnimation,1);
    CCCallFuncO *callback = CCCallFuncO::create(hit, callfuncO_selector(CCNode::removeFromParentAndCleanup),CCNode::getParent());
    CCSequence *sequence = CCSequence::create(repeat,callback);
    hit->runAction(sequence);
}


/*
 * The touch end logic
 */
void GameScene::ccTouchesEnded(CCSet *touches,CCEvent *event)
{
    /*
    CCSetIterator it = touches->begin();
    CCTouch* touch;
    
    CCPoint pt;
    
	//Add a new body/atlas sprite at the touched location
    for( int iTouchCount = 0; iTouchCount < touches->count(); iTouchCount++ ){
        touch = (CCTouch*)(*it);
    	CCPoint location = touch->getLocation();

        
        // remove all entry and exit points from all polygons
        // [self clearSlices];
        
        // fade the blade
        _blade->dim(true);
        
        // sparkle effect stops
        _bladeSparkle->stopSystem();
        isCutting = false;
        prePoint = NULL;
        preDirect = 0;
        
	}
     */
}





// Add these methods
void GameScene::initHUD()
{
    
    CCSize screen = CCDirector::sharedDirector()->getWinSize();
    
    /*
     CCSprite *pasueIcon = [CCSprite spriteWithFile:@"btn_pause.png"];
     CCSprite *selectedSprite = [CCSprite spriteWithFile:@"btn_pause.png"];
     CCButton *button =[CCButton buttonWithNormalSprite:pasueIcon selectedSprite:selectedSprite target:self action:@selector(touchUpInSide:) forEvent:buttonEvent_TouchUpInside];
     [button setTarget:self action:@selector(touchDown:) forEvent:buttonEvent_TouchDown];
     button.position = ccp(screen.width - pasueIcon.contentSize.width/2-5, screen.height - pasueIcon.contentSize.height/2-5);
     [self addChild:button];*/
    
    CCMenuItem * pasueIcon = CCMenuItemImage::create("btn_pause.png", "btn_pause.png", this, menu_selector(GameScene::pushSpriteButton));
    pasueIcon->setTag(11);
    CCMenu * menu  = CCMenu::create(pasueIcon,nil);
    menu->alignItemsHorizontallyWithPadding(20);
    menu->setPosition(ccp(screen.width - pasueIcon->getContentSize().width/2-5, screen.height - pasueIcon->getContentSize().height/2-5));
    this->addChild(menu);
    
    
    
    
    //CCSprite *pasueIcon = [CCSprite spriteWithFile:@"btn_pause.png"];
    //pasueIcon.position = ccp(screen.width - pasueIcon.contentSize.width/2-5, screen.height - pasueIcon.contentSize.height/2-5);
    //[self addChild:pasueIcon];
    bloods = CCArray::create();
    for (int i = 0; i < 3; i++)
    {
        CCSprite *blood = CCSprite::create("Icon_heart.png");
        blood->setPosition(ccp(screen.width-pasueIcon->getContentSize().width*1.5-blood->getContentSize().width/2-(blood->getContentSize().width+2)*i,screen.height-blood->getContentSize().height/2-5));
        bloods->addObject(blood);
        this->addChild(blood,12);
    }
    
    
    _zombiIcon = CCSprite::create("Icon_zombie.png");
    _zombiIcon->setPosition(ccp(_zombiIcon->getContentSize().width/2+10,screen.height-_zombiIcon->getContentSize().height/2-5));
    this->addChild(_zombiIcon,12);
    
    
    CCSpriteBatchNode *spriteSheet = CCSpriteBatchNode::create("numpic.png");
    this->addChild(spriteSheet);
    
    
    _coinIcon = CCSprite::create("Icon_coin.png");//:@"Icon_coin.png"
    _coinIcon->setPosition(ccp(_coinIcon->getContentSize().width/2+10,_zombiIcon->getPosition().y - _coinIcon->getContentSize().height-5));
    this->addChild(_coinIcon,12);
    
    
    _bossIcon = CCSprite::create("Icon_boss.png");
    _bossIcon->setPosition(ccp(_bossIcon->getContentSize().width/2+10,_coinIcon->getPosition().y - _bossIcon->getContentSize().height-5));
    this->addChild(_bossIcon,12);
    
    
    
    _bossBloodBg = CCSprite::create("Loading_bloodBg.png");
    _bossBloodBg->setPosition(ccp(_bossIcon->getPosition().x + _bossBloodBg->getContentSize().width/2+20,_bossIcon->getPosition().y));
    this->addChild(_bossBloodBg,12);
    
    _bossBlood = CCSprite::create("Loading_blood.png");
    _bossBlood->setPosition(ccp(_bossIcon->getPosition().x + _bossBlood->getContentSize().width/2+20,_bossIcon->getPosition().y));
    this->addChild(_bossBlood,12);
    
    
    this->createLabel();
    
}



void GameScene::pushSpriteButton(CCSprite *sender)
{
    switch(sender->getTag()){
        case 11:
           // CCLOG(@"spriteButtonUseSelector_pushed");
            printf("");
            CCDirector::sharedDirector()->replaceScene(SceneStartup::scene());
          //  [[CCDirector sharedDirector] replaceScene:[CCTransitionFade transitionWithDuration:1.0 scene:[SceneStartup scene] ]];
            break;
        case 22:
           // CCLOG(@"spriteButtonUseBlock_pushed");
            break;
        default:
           // CCLOG(@"???");
            break;
    }
}



void GameScene::onGotCoint(CCSprite *sender){
    coinCount++;
    number->showNum(coinCount);
    CCEaseInOut *scaleUpAction =  CCEaseInOut::create(CCScaleTo::create(0.2, 1.4,1.4), 2.0f);
    CCEaseInOut *scaleDownAction = CCEaseInOut::create(CCScaleTo::create(0.1,0.8,0.8), 2.0f);
    CCEaseInOut *scaleUpAction2 = CCEaseInOut::create(CCScaleTo::create(0.1,1.0,1.0), 2.0f);
    CCSequence *scaleSeq = CCSequence::create(scaleUpAction, scaleDownAction, scaleUpAction2);
    _coinIcon->runAction(scaleSeq);
}


void GameScene::onCoinDisappear(CCSprite *sender){
    
    
}

void GameScene::createLabel()
{
	if( _zombiLabel) {
		CCTexture2D *texture = _zombiLabel->getTexture();
		_zombiLabel->release();
        CCTextureCache::sharedTextureCache()->removeTexture(texture);
		_zombiLabel = NULL;
	}
    
    
	CCTexture2DPixelFormat currentFormat = CCTexture2D::defaultAlphaPixelFormat();
    CCTexture2D::setDefaultAlphaPixelFormat(kCCTexture2DPixelFormat_RGBA4444);
	_zombiLabel =  CCLabelAtlas::create("0", "numbers.png",20,32,0);
    //[[CCLabelAtlas alloc]  initWithString:@"0" charMapFile:@"numbers.png" itemWidth:20 itemHeight:32 startCharMap:'.'];
	//_coinLabel =  [[CCLabelAtlas alloc]  initWithString:@"0" charMapFile:@"numbers.png" itemWidth:20 itemHeight:32 startCharMap:'.'];
    
    
    CCTexture2D::setDefaultAlphaPixelFormat(currentFormat);
    _zombiLabel->setPosition(ccp(_zombiIcon->getPosition().x+20,_zombiIcon->getPosition().y-15));
    //_coinLabel.position = ccp(_coinIcon.position.x+20,_coinIcon.position.y-15);
    
    
    number = (NumberLabel *)NumberLabel::create();
    this->addChild(number,14);
    number->setPosition(ccp(_coinIcon->getPosition().x+30,_coinIcon->getPosition().y));
    number->showNum(0);
    
    this->addChild(_zombiLabel,14);
    //   [self addChild:_coinLabel z:14];
	
}


/*

bool WSSCGPointIsNull(CGPoint point ){
    return std::isnan(point.x) && std::isnan(point.y);
}



#pragma mark GameKit delegate

-(void) achievementViewControllerDidFinish:(GKAchievementViewController *)viewController
{
	AppController *app = (AppController*) [[UIApplication sharedApplication] delegate];
	[[app navController] dismissModalViewControllerAnimated:YES];
}

-(void) leaderboardViewControllerDidFinish:(GKLeaderboardViewController *)viewController
{
	AppController *app = (AppController*) [[UIApplication sharedApplication] delegate];
	[[app navController] dismissModalViewControllerAnimated:YES];
}

@end
*/

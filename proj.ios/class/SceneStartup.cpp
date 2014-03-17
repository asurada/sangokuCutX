//
//  SceneStartup.cpp
//  sangokuCutX
//
//  Created by Yan Wei on 2014/02/03.
//
//

#include "SceneStartup.h"
#include "GameScene.h"

USING_NS_CC;


CCScene* SceneStartup::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    SceneStartup *layer = SceneStartup::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool SceneStartup::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();
    
    
    
    if(visibleSize.width == 568){
        this->initBackground_iphone5();
    }else{
        this->initBackground_iphone4();
    }
    this->setTouchEnabled(true);
    
    this->iniHUD();

    
    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.
    
//    // add a "close" icon to exit the progress. it's an autorelease object
//    CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
//                                                          "CloseNormal.png",
//                                                          "CloseSelected.png",
//                                                          this,
//                                                          menu_selector(SceneStartup::menuCloseCallback));
//    
//	pCloseItem->setPosition(ccp(origin.x + visibleSize.width - pCloseItem->getContentSize().width/2 ,
//                                origin.y + pCloseItem->getContentSize().height/2));
//    
//    // create menu, it's an autorelease object
//    CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
//    pMenu->setPosition(CCPointZero);
//    this->addChild(pMenu, 1);
    
    /////////////////////////////
    // 3. add your codes below...
    
    // add a label shows "Hello World"
    // create and initialize a label
    
    //CCLabelTTF* pLabel = CCLabelTTF::create("Hello World", "Arial", TITLE_FONT_SIZE);
    
    // position the label on the center of the screen
    //pLabel->setPosition(ccp(origin.x + visibleSize.width/2,
    //                        origin.y + visibleSize.height - pLabel->getContentSize().height));
    
//    // add the label as a child to this layer
//    this->addChild(pLabel, 1);
//    
//    // add "HelloWorld" splash screen"
//    CCSprite* pSprite = CCSprite::create("HelloWorld.png");
//    
//    // position the sprite on the center of the screen
//    pSprite->setPosition(ccp(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
//    
//    // add the sprite as a child to this layer
//    this->addChild(pSprite, 0);
    
    return true;
}



void SceneStartup::iniHUD(){
    CCSize screen = CCDirector::sharedDirector()->getVisibleSize();
    CCSpriteBatchNode *spriteSheet = CCSpriteBatchNode::create("ResourceImage.png");
    this->addChild(spriteSheet,0);
    

    CCMenuItem *v1 = CCMenuItemImage::create("Icon_battle_nameBg.png","Icon_battle_nameBg.png",this,menu_selector(SceneStartup::pushSpriteButton));
    v1->setTag(11);
    CCMenu * menu = CCMenu::create(v1,NULL);
    menu->alignItemsHorizontallyWithPadding(20);
    menu->setPosition(ccp(screen.width/2 - 50, screen.height/2 + 130));
    this->addChild(menu);

    
    CCMenuItem *v2 = CCMenuItemImage::create("Icon_battle_nameBg.png","Icon_battle_nameBg.png",this,menu_selector(SceneStartup::pushSpriteButton));

    v2->setTag(11);
    CCMenu *menu2 = CCMenu::create(v2,NULL);
    menu2->alignItemsHorizontallyWithPadding(20);
    menu2->setPosition(ccp(screen.width/2 - 50, screen.height/2 + 70));
    this->addChild(menu2);
    
    
    CCMenuItem *v3 = CCMenuItemImage::create("Icon_battle_nameBg.png","Icon_battle_nameBg.png",this,menu_selector(SceneStartup::pushSpriteButton));

    v3->setTag(11);
    CCMenu *menu3 = CCMenu::create(v3,NULL);
    menu3->alignItemsHorizontallyWithPadding(20);
    menu3->setPosition(ccp(screen.width/2 +100, screen.height/2 + 100));
    this->addChild(menu3);
    

    CCMenuItem *v4 = CCMenuItemImage::create("Icon_battle_nameBg.png","Icon_battle_nameBg.png",this,menu_selector(SceneStartup::pushSpriteButton));

    v4->setTag(11);
    CCMenu *menu4 = CCMenu::create(v4,NULL);
    menu4->alignItemsHorizontallyWithPadding(20);
    menu4->setPosition(ccp(screen.width/2 +70, screen.height/2 + 170));
    this->addChild(menu4);
    
    
    CCMenuItem *v5 = CCMenuItemImage::create("Icon_battle_nameBg.png","Icon_battle_nameBg.png",this,menu_selector(SceneStartup::pushSpriteButton));

    v5->setTag(11);
    CCMenu *menu5 = CCMenu::create(v5,NULL);
    menu5->alignItemsHorizontallyWithPadding(20);
    menu5->setPosition(ccp(screen.width/2 +70, screen.height/2 + 20));
    this->addChild(menu5);
    
    
    CCMenuItem *v6 = CCMenuItemImage::create("Icon_battle_nameBg.png","Icon_battle_nameBg.png",this,menu_selector(SceneStartup::pushSpriteButton));

    v6->setTag(11);
    CCMenu *menu6 = CCMenu::create(v6,NULL);
    menu6->alignItemsHorizontallyWithPadding(20);
    menu6->setPosition(ccp(screen.width/2 +90, screen.height/2 - 40));
    this->addChild(menu6);
    
    
    CCMenuItem *v7 = CCMenuItemImage::create("Icon_battle_nameBg.png","Icon_battle_nameBg.png",this,menu_selector(SceneStartup::pushSpriteButton));

    v7->setTag(11);
    CCMenu *menu7 = CCMenu::create(v7,NULL);
    menu7->alignItemsHorizontallyWithPadding(20);
    menu7->setPosition(ccp(screen.width/2 - 80, screen.height/2 - 10));
    this->addChild(menu7);

    
    CCMenuItem *v8 = CCMenuItemImage::create("Icon_battle_nameBg.png","Icon_battle_nameBg.png",this,menu_selector(SceneStartup::pushSpriteButton));

    v8->setTag(11);
    CCMenu *menu8 = CCMenu::create(v8,NULL);
    menu8->alignItemsHorizontallyWithPadding(20);
    menu8->setPosition(ccp(screen.width/2 + 70 , screen.height/2 - 140));
    this->addChild(menu8);
    
}

void SceneStartup::initBackground_iphone5()
{
     CCSize screen = CCDirector::sharedDirector()->getVisibleSize();
    //int height = 0;
    //int diff = 568.0 - screen.height;

    CCSprite *background_01 = CCSprite::create("Page_battle_v1_iPhone5.png");
    background_01->setPosition(ccp(screen.width/2,screen.height/2));
    this->addChild(background_01,0);
}

void SceneStartup::initBackground_iphone4()
{
    CCSize screen = CCDirector::sharedDirector()->getVisibleSize();
    
    CCSprite *background_01 = CCSprite::create("Page_battle_v1_iPhone5.png");// [CCSprite spriteWithFile:@"Bg_iPhone5_01.png"];
    background_01->setPosition(ccp(screen.width/2,screen.height/2));//415
    this->addChild(background_01,0);
}



void SceneStartup::pushSpriteButton(CCObject* pSender)
{
    CCNode *node = (CCNode*)pSender;
    switch(node->getTag()){
        case 11:{
            CCScene *gameScene = GameScene::scene();
            CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(1.0f,gameScene));
            gameScene->init();
            break;
        }
        case 22:
            CCLOG("spriteButtonUseBlock_pushed");
            break;
        default:
            CCLOG("???");
            break;
    }
}



void SceneStartup::menuCloseCallback(CCObject* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT) || (CC_TARGET_PLATFORM == CC_PLATFORM_WP8)
	CCMessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
#else
    CCDirector::sharedDirector()->end();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
#endif
}

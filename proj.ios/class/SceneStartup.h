//
//  SceneStartup.h
//  sangokuCutX
//
//  Created by Yan Wei on 2014/02/03.
//
//

#ifndef __sangokuCutX__SceneStartup__
#define __sangokuCutX__SceneStartup__


#include "cocos2d.h"


class SceneStartup : public cocos2d::CCLayer
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::CCScene* scene();
    
    // a selector callback
    void menuCloseCallback(CCObject* pSender);
    
    void iniHUD();
    void pushSpriteButton(CCObject* pSender);
    void initBackground_iphone5();
    void initBackground_iphone4();
    
    // implement the "static node()" method manually
    CREATE_FUNC(SceneStartup);
};

#endif // __HELLOWORLD_SCENE_H__
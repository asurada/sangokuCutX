//
//  BaseCharacter.h
//  sangokuCutX
//
//  Created by Yan Wei on 2014/02/03.
//
//

#ifndef __sangokuCutX__BaseCharacter__
#define __sangokuCutX__BaseCharacter__

#include "cocos2d.h"
using namespace cocos2d;


class BaseCharacter : CCSprite
{
    
private:
    float _hp;
    float _allHp;
    float _injureHp;
    float _moveUpSpeed;
    float _moveDownSpeed;
    float _waitingTime;
    float _intervalSpaceMove;
    int   _index;
    float original_Y;
    
    std::string _name;
    //CCObject<CharacterDelegate> _charDelegate;
    //state _state;
    bool _hasAttack;
    
    CCAnimation *_injureAnim;
    CCAnimation  *_normalAnim;
    CCAnimation  *_deadAnim;
    CCAnimation  *_attackAnim;
    
    
    CCAnimation  *_normalAction;
    CCAnimation  *_injureAction;
    CCAnimation  *_deadAction;
    CCAnimation  *_attackAction;
    CCAnimation  *_upAction;
    CCAnimation  *_downAction;
    CCAnimation  *_hidSound;
    std::string *_deadSound;

    
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    
    
    
    // implement the "static node()" method manually
    CREATE_FUNC(BaseCharacter);
};

#endif
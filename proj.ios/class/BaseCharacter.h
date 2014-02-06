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


enum state {
    _movingup,
    _movingdown,
    _standby,
    _healthy,
    _attack,
    _injure,
    _dead
};


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

    CCObject spriteWithFile();
    bool initSprite;
    void injure(float direction);
    void dead(float direction);
    void attack();
    void normal();
    void action();
    void hit(float direction);
    void moveUp();
    void moveDown();
    void loadNormalAnim();
    void loadInjureAnim();
    void loadDeadAnim();
    void loadAttackAnim();
    void finishDead();
    void stopAction();
    state getState();
    void setState(state stt);
    void stopNormalAction();
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    
    
    
    // implement the "static node()" method manually
    CREATE_FUNC(BaseCharacter);
};

#endif
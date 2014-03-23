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
#include "CharacterDelegate.h"
using namespace cocos2d;
using namespace std;


namespace BaseCharacterSpace {

enum state {
    _movingup,
    _movingdown,
    _standby,
    _healthy,
    _attack,
    _injure,
    _dead
};


class BaseCharacter : public CCSprite
{
    
    
private:
    bool _hasAttack;
    void attack();
    void action();
    
    void setScaleX();
public:
    int   _index;
    state _state;
    
    float _moveUpSpeed;
    float _moveDownSpeed;
    float _waitingTime;
    float _intervalSpaceMove;
    float original_Y;

    float _hp;
    float _allHp;
    float _injureHp;
    std::string  _hidSound;
    std::string  _deadSound;
    std::string  _name;
    
    void hit(float direction);
    CCAnimation *_injureAnim;
    CCAnimation  *_normalAnim;
    CCAnimation  *_deadAnim;
    CCAnimation  *_attackAnim;
    CCRepeatForever  *_normalAction;
    CCSequence   *_injureAction;
    CCSequence   *_deadAction;
    CCRepeatForever  *_attackAction;
    CCAnimation  *_upAction;
    CCAnimation  *_downAction;
    virtual void injure(float direction);
    void finishDead();
    void setState(state stt);
    state getState();
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    bool initSprite();
    virtual void finishMoveDown();
    virtual void finishMoveUp();
    virtual void dead(float direction);
    virtual void moveUp();
    virtual void moveDown();
    static BaseCharacter *spriteWithFile();
    void finishInjure();
    void stopAction();
    void normal();
    void stopNormalAction();
    CharacterDelegate *delegate;
    void loadNormalAnim();
    void loadInjureAnim();
    void loadDeadAnim();
    void loadAttackAnim();

    // implement the "static node()" method manually
    CREATE_FUNC(BaseCharacter);
};

    
}
#endif
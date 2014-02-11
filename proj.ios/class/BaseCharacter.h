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
  
    float _moveUpSpeed;
    float _moveDownSpeed;
    float _waitingTime;
    float _intervalSpaceMove;
   
    float original_Y;
    
    std::string _name;
    
    bool _hasAttack;
    
    
    

   
   
    void attack();
    
    void action();
    void hit(float direction);
    void moveUp();
    void moveDown();
    void loadNormalAnim();
    void loadInjureAnim();
    void loadDeadAnim();
    void loadAttackAnim();
   
    

    state getState();
    void setScaleX();
    void setState(state stt);
public:
    int   _index;
    state _state;
    
    float _hp;
    float _allHp;
    float _injureHp;
    char  *_hidSound;
    char  *_deadSound;
    
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
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    virtual bool initSprite();
    virtual void finishMoveDown();
    virtual void finishMoveUp();
    virtual void dead(float direction);
    
    CCObject spriteWithFile();
    void finishInjure();
    void stopAction();
    void normal();
    void stopNormalAction();
    CharacterDelegate *delegate;

    // implement the "static node()" method manually
    CREATE_FUNC(BaseCharacter);
};

    
}
#endif
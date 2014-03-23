//
//  NullChar.h
//  sangokuCutX
//
//  Created by 厳 巍 on 2014/03/23.
//
//



#include "BaseCharacter.h"


using BaseCharacterSpace::BaseCharacter;

class NullChar:public BaseCharacter{
    
public:
    typedef BaseCharacter super;
    static NullChar* spriteWithFile();
    virtual bool initSprite();
    virtual void loadInjureAnim();
    virtual void loadAttackAnim();
    virtual void loadDeadAnim();
    virtual void loadNormalAnim();
    void finishInjure();
};
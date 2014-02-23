//
//  Sibao.h
//  sangokuCutX
//
//  Created by 厳 巍 on 2014/02/11.
//
//

#ifndef __sangokuCutX__Sibao__
#define __sangokuCutX__Sibao__

#include "BaseCharacter.h"

using BaseCharacterSpace::BaseCharacter;

class Sibao:public BaseCharacter{
    
public:
    typedef BaseCharacter super;
    static BaseCharacter* spriteWithFile();
    bool initSprite();
    virtual void loadInjureAnim();
    virtual void loadAttackAnim();
    virtual void loadDeadAnim();
    virtual void loadNormalAnim();
    void finishInjure();
};

#endif /* defined(__sangokuCutX__Sibao__) */

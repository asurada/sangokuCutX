//
//  Sihei.h
//  sangokuCutX
//
//  Created by 厳 巍 on 2014/02/11.
//
//

#ifndef __sangokuCutX__Sihei__
#define __sangokuCutX__Sihei__

#include "BaseCharacter.h"


using BaseCharacterSpace::BaseCharacter;

class Sihei:public BaseCharacter{
    
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


#endif /* defined(__sangokuCutX__Sihei__) */

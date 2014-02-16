//
//  Siheng.h
//  sangokuCutX
//
//  Created by 厳 巍 on 2014/02/11.
//
//

#ifndef __sangokuCutX__Siheng__
#define __sangokuCutX__Siheng__

#include "BaseCharacter.h"

using namespace BaseCharacterSpace;

class Siheng: protected BaseCharacter{
    
public:
    typedef BaseCharacter super;
    static BaseCharacter* spriteWithFile();
    bool initSprite();
    virtual void loadInjureAnim();
    virtual void loadAttackAnim();
    virtual void loadDeadAnim();
    virtual void loadNormalAnim();
};

#endif /* defined(__sangokuCutX__Siheng__) */

//
//  HuangjinSiha.h
//  sangokuCutX
//
//  Created by 厳 巍 on 2014/02/11.
//
//

#ifndef __sangokuCutX__HuangjinSiha__
#define __sangokuCutX__HuangjinSiha__

#include "BaseCharacter.h"

using BaseCharacterSpace::BaseCharacter;

class HuangjinSiha:public BaseCharacter{
public:
    typedef BaseCharacter super;
    static BaseCharacter * spriteWithFile();
    bool initSprite();
    virtual void loadInjureAnim();
    virtual void loadAttackAnim();
    virtual void loadDeadAnim();
    virtual void loadNormalAnim();
};

#endif /* defined(__sangokuCutX__HuangjinSiha__) */

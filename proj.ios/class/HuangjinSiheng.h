//
//  HuangjinSiheng.h
//  sangokuCutX
//
//  Created by 厳 巍 on 2014/02/11.
//
//

#ifndef __sangokuCutX__HuangjinSiheng__
#define __sangokuCutX__HuangjinSiheng__

#include "BaseCharacter.h"

using BaseCharacterSpace::BaseCharacter;

class HuangjinSiheng:public BaseCharacter{
    
public:
    typedef BaseCharacter super;
    static BaseCharacter *spriteWithFile();
    bool initSprite();
    virtual void loadInjureAnim();
    virtual void loadAttackAnim();
    virtual void loadDeadAnim();
    virtual void loadNormalAnim();
};


#endif /* defined(__sangokuCutX__HuangjinSihei__) */
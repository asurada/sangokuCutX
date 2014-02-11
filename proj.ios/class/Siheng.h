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

class Siheng:BaseCharacter{
    
public:
    typedef BaseCharacter super;
    CCObject spriteWithFile();
    virtual void loadInjureAnim();
    virtual void loadAttackAnim();
    virtual void loadDeadAnim();
    virtual void loadNormalAnim();
};

#endif /* defined(__sangokuCutX__Siheng__) */

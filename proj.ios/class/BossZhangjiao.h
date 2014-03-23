//
//  BossZhangjiao.h
//  sangokuCutX
//
//  Created by 厳 巍 on 2014/02/11.
//
//

#ifndef __sangokuCutX__BossZhangjiao__
#define __sangokuCutX__BossZhangjiao__

#include "BaseCharacter.h"
#include "BaseBossCharacter.h"


class BossZhangjiao:public BaseBossCharacter{
    
public:
    typedef BaseCharacter super;
    static BaseCharacter* spriteWithFile();
    virtual bool initSprite();
    virtual void loadInjureAnim();
    virtual void loadAttackAnim();
    virtual void loadDeadAnim();
    virtual void loadNormalAnim();
};


#endif /* defined(__sangokuCutX__HuangjinSihei__) */
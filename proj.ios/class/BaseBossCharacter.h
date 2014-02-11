//
//  BaseBossCharacter.h
//  sangokuCutX
//
//  Created by 厳 巍 on 2014/02/10.
//
//

#ifndef __sangokuCutX__BaseBossCharacter__
#define __sangokuCutX__BaseBossCharacter__
#include "cocos2d.h"
#include "BaseCharacter.h"

using namespace BaseCharacterSpace;

class BaseBossCharacter:public BaseCharacter{
    private:
    
    public:
    virtual void finishMoveDown();
    virtual void finishMoveUp();
    virtual void finishDead();
    virtual void dead(float direction);
    virtual void injure(float direction);
    virtual void finishInjure();
    virtual void stopNormalAction();
};


#endif /* defined(__sangokuCutX__BaseBossCharacter__) */

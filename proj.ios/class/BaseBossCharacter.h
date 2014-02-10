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
};


#endif /* defined(__sangokuCutX__BaseBossCharacter__) */

//
//  CoinEffect.h
//  sangokuCutX
//
//  Created by 厳 巍 on 2014/02/16.
//
//

#ifndef __sangokuCutX__CoinEffect__
#define __sangokuCutX__CoinEffect__
#include "BaseCharacter.h"

using namespace BaseCharacterSpace;

class CoinEffect:CCSprite{
   
public:
    typedef BaseCharacter super;
    static BaseCharacter* spriteWithFile();
    bool initSprite();

};

#endif /* defined(__sangokuCutX__CoinEffect__) */

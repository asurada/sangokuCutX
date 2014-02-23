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

class CoinEffect:public CCSprite{
   
public:
    typedef BaseCharacter super;
    static CoinEffect* spriteWithFile();
    bool initSprite();
    void coinDisappear();

};


#endif /* defined(__sangokuCutX__CoinEffect__) */

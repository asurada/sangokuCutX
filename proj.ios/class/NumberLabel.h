//
//  NumberLabel.h
//  sangokuCutX
//
//  Created by 厳 巍 on 2014/02/16.
//
//

#ifndef __sangokuCutX__NumberLabel__
#define __sangokuCutX__NumberLabel__
#include "BaseCharacter.h"
using namespace BaseCharacterSpace;

class NumberLabel:CCSprite{
  public:
    int number;
    CCArray* numList;
    void showNum(int num);
    typedef BaseCharacter super;
    static NumberLabel* spriteWithFile(string name);
    virtual CCSprite* create();
};

#endif /* defined(__sangokuCutX__NumberLabel__) */

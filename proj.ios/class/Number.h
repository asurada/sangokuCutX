//
//  Number.h
//  sangokuCutX
//
//  Created by 厳 巍 on 2014/02/16.
//
//

#ifndef __sangokuCutX__Number__
#define __sangokuCutX__Number__
#include "BaseCharacter.h"
using namespace BaseCharacterSpace;

class Number : public CCSprite{
  public :
    int curcount;
    int dstCount;
    bool initSprite();
    bool showNum(int num);
    bool showNumAnimation(int num);
    typedef BaseCharacter super;
    static Number* spriteWithFile(string name);
    bool showNextNum();

};

#endif /* defined(__sangokuCutX__Number__) */

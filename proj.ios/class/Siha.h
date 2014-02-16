//
//  Siha.h
//  sangokuCutX
//
//  Created by 厳 巍 on 2014/02/11.
//
//

#ifndef __sangokuCutX__Siha__
#define __sangokuCutX__Siha__


#include "BaseCharacter.h"

using BaseCharacterSpace::BaseCharacter;

class Siha:public BaseCharacter{
   
 public:
     typedef BaseCharacter super;
     static BaseCharacter *spriteWithFile();
     bool initSprite();
     virtual void loadInjureAnim();
     virtual void loadAttackAnim();
     virtual void loadDeadAnim();
     virtual void loadNormalAnim();
};


#endif /* defined(__sangokuCutX__Siha__) */

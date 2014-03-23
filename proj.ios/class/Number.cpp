//
//  Number.cpp
//  sangokuCutX
//
//  Created by 厳 巍 on 2014/02/16.
//
//

#include "Number.h"



bool Number::initSprite(){
    curcount =-1;
    dstCount =-1;
    return true;
}


bool Number::showNum(int num){
    dstCount = num;
    if(dstCount > curcount){
        curcount++;
        return this->showNumAnimation(curcount);
    }else if(dstCount < curcount){
        curcount = num;
        return this->showNumAnimation(curcount);
    }else{
        char* fn = new char;
        sprintf(fn, "num_%d.png", num);
        this->setTexture(CCTextureCache::sharedTextureCache()->addImage(fn));
        return true;
    }
}

bool Number::showNumAnimation(int num){
    char* fn = new char;
    sprintf(fn, "num_%d.png", num);
    this->setTexture(CCTextureCache::sharedTextureCache()->addImage(fn));
    this->setScale(4);
    
    CCEaseInOut *scaleDownAction = CCEaseInOut::create(CCScaleTo::create(0.1,0.5,0.5),1.0);
    CCEaseInOut *scaleDownNormal = CCEaseInOut::create(CCScaleTo::create(0.1,1,1),1.0);
    CCSequence *scaleSeq =  CCSequence::create(scaleDownAction,scaleDownNormal);
    CCCallFunc *callback = CCCallFunc::create(this, callfunc_selector(Number::showNextNum));// actionWithTarget:self selector:@selector(showNextNum)];
    this->runAction(CCSequence::create(scaleSeq,callback));
    return true;
    
}



bool Number::showNextNum(){
    if(dstCount > curcount){
        curcount++;
        return this->showNumAnimation(curcount);
    }else if(dstCount < curcount){
        curcount = dstCount;
        return this->showNumAnimation(curcount);
    }
    return false;
    
}

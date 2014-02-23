//
//  NumberLabel.cpp
//  sangokuCutX
//
//  Created by 厳 巍 on 2014/02/16.
//
//

#include "NumberLabel.h"
#include "Number.h"


CCSprite* NumberLabel::create(){
    numList = CCArray::create();
    /// Number *numlabel = [Number spriteWithFile:@"num_0.png"];
    /// [numList addObject:numlabel];
    // [self addChild:numlabel];
    return super::create();
}

NumberLabel* NumberLabel::spriteWithFile(string name){

    return (NumberLabel *)super::createWithSpriteFrameName(name.c_str());// spriteWithFile:name];
}



void NumberLabel::showNum(int num){
    number = num;
    //一旦 NSNumber型にキャストする
   // Number *numberValue = [[NSNumber alloc] initWithInt:num];
    
    //桁数を求める
    int digits = (int)log10(num) + 1;
    
    if(num == 0){
        Number *numlabel = Number::spriteWithFile("num_0.png"); //[Number spriteWithFile:@"num_0.png"];
        numlabel->setPosition(ccp(numlabel->getPosition().x, numlabel->getPosition().y));
        numList->addObject(numlabel);
        this->addChild(numlabel);
        return;
    }
    
    for(int index = 0; index< digits;index++){
        if(numList->count()<index+1){
            Number *numlabel = Number::spriteWithFile("num_1.png");
            if(numlabel->initSprite()){
                numlabel->setPosition(ccp(numlabel->getPosition().x + 20 * index, numlabel->getPosition().y));
                numList->addObject(numlabel);
                this->addChild(numlabel);
            }
        }
        int value = 0;
        if(index == 0){
            value = num/pow(10, digits-1);
        }else{
            value = ((int)(num/pow(10, digits-index-1)) % 10);
        }
        Number *numlabel = (Number*)numList->objectAtIndex(index);
        numlabel->showNum(value);
    }
}

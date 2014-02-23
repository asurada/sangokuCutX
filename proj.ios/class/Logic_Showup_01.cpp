//
//  Logic_Showup_01.cpp
//  sangokuCutX
//
//  Created by 厳 巍 on 2014/02/23.
//
//

#include "Logic_Showup_01.h"
#include "BossZhangjiao.h"
#define KILLCOUNT ((int)30)




int Logic_Showup_01::getPosition(){
    CCArray *result = CCArray::create();
    if(prePosition == -1){
        prePosition = arc4random()%9;
        return prePosition;
    }else{
        int mainIndex =-1;
        for (int index = 0; index < 9; index++) {
            if(prePosition == arr[index]){
                mainIndex = index;
                break;
            }
        }
        for(int index = 0;index < 4;index++){
            if(posDiff > 0){
                if(matrix[mainIndex][index] > 0 && prePosition != 8){
                    result->addObject(CCInteger::create((int)matrix[mainIndex][index]));
                }else if(prePosition == 8 && matrix[mainIndex][index] != 0){
                    result->addObject(CCInteger::create((int)matrix[mainIndex][index]));
                }
                
            }else if(posDiff < 0){
                if(matrix[mainIndex][index] < 0 && prePosition != 0){
                     result->addObject(CCInteger::create((int)matrix[mainIndex][index]));
//[result addObject:[NSNumber numberWithInteger:matrix[mainIndex][index]]];
                    
                }else if(prePosition == 0 && matrix[mainIndex][index] != 0){
                     result->addObject(CCInteger::create((int)matrix[mainIndex][index]));
//                    [result addObject:[NSNumber numberWithInteger:matrix[mainIndex][index]]];
                }
            }else{
                if(matrix[mainIndex][index] != 0){
                     result->addObject(CCInteger::create((int)matrix[mainIndex][index]));
 //                   [result addObject:[NSNumber numberWithInteger:matrix[mainIndex][index]]];
                }
            }
        }
        
        posDiff = (int)result->objectAtIndex(arc4random()%(result->count()));// [[result objectAtIndex:(arc4random()%([result count]))]integerValue];
        prePosition = prePosition + posDiff;
        return prePosition;
    }
    
    
}

bool Logic_Showup_01::create(){
    
    _enemyCount = KILLCOUNT;
    _enemyMoveUpSpeed = .3;
    _enemyMoveDownSpeed=.3;
    _bossMoveUpSpeed=.3;
    _bossMoveDownSpeed=.3;
    _intervalTime= 20;
    _enemyWaitingTime = .8;
    _bossWaitingTime = 2;
    return super::create();
}





int Logic_Showup_01::showEnemey(int tickCnt,int killedCnt){
    
    if(killedCnt == 5 && sequence == 0){
        sequence = arc4random()% 7 +1 ;
    }else if(killedCnt == 11 && sequence == 0){
        sequence = arc4random()% 27 +1 ;
    }else if(killedCnt == 15 && sequence == 0){
        sequence = arc4random()% 9 +1 ;
    }else if(killedCnt == 20 && sequence == 0){
        sequence = arc4random()% 20 +1 ;
    }
    
    
    if(sequence > 0){
        _intervalTime = 2;
    }else{
        _intervalTime = 20;
        isSequenceRun = false;
    }
    BaseCharacter *enemy = NULL;
    if(tickCnt >= _intervalTime){
        int position = 0;
        tickCnt = 0;
        if(_intervalTime > 2){
            position = arc4random()%9;
        }else{
            if(cnt > 9){
                cnt = 0;
            }
            position = this->getPosition(); //;arr[cnt];
            cnt++;
            sequence --;
            
        }
        if(killedCnt < _enemyCount){//cnt < 14 &&
           // NSLog(@"look at %d",position);
            enemy = (BaseCharacter *)_enemyBox->objectAtIndex(position);
            if(enemy != NULL && enemy->getState()==_standby && !enemy->isRunning()){
                enemy->removeFromParentAndCleanup(true);
                enemy = this->createEnemy(position);
                _enemyBox->replaceObjectAtIndex(position,enemy,true);
                enemy->_waitingTime = _enemyWaitingTime;
                enemy->_moveUpSpeed = _enemyMoveUpSpeed;
                enemy->_moveDownSpeed = _enemyMoveDownSpeed;
                enemy->moveUp();
            }else if(enemy == NULL){
                //NSLog(@"insert at %d",position);
                enemy = this->createEnemy(position);
                _enemyBox->replaceObjectAtIndex(position,enemy);
                enemy->_waitingTime = _enemyWaitingTime;
                enemy->_moveUpSpeed = _enemyMoveUpSpeed;
                enemy->_moveDownSpeed = _enemyMoveDownSpeed;
                enemy->moveUp();
            }else{
                tickCnt = 20;
            }
        }else if(killedCnt >= _enemyCount){
            if(!_bossAppear){
                CCObject *allEnemy = NULL;
                CCARRAY_FOREACH(_enemyBox, allEnemy){
                    BaseCharacter* baseChar = (BaseCharacter*)_enemyBox;
                    if(baseChar != NULL && baseChar->getState() == _healthy){
                        baseChar->moveDown();
                    }
                }
                _bossAppear = true;
            }else{
                this->showBoss();
            }
        }else{
            
        }
    }
    
    return tickCnt;
    
}


void Logic_Showup_01::showBoss(){
    if(_bossAppear){
        if(boss == NULL){
            boss = BossZhangjiao::spriteWithFile();
            boss = this->createBoss(boss,3);
            _enemyBox->addObject(boss);
            
        }
        if(boss != NULL && boss->getState() == _standby){
            boss->setState(_standby);
            int ran = arc4random()%8;
            this->setSpritePositon(boss,ran);
            boss->_waitingTime = _bossWaitingTime;
            boss->_moveUpSpeed = _bossMoveUpSpeed;
            boss->_moveDownSpeed = _bossMoveDownSpeed;
            boss->moveUp();
        }
    }
}

void Logic_Showup_01::loadEnmey(){
    Logic::loadEnmey();
}


void bossAppear(int killedcnt){
    
}

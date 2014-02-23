//
//  Logic_Showup_01.h
//  sangokuCutX
//
//  Created by 厳 巍 on 2014/02/23.
//
//

#ifndef __sangokuCutX__Logic_Showup_01__
#define __sangokuCutX__Logic_Showup_01__

#include "Logic.h"

class Logic_Showup_01 : public Logic{

 public:
    int   _enemyClearCount;
    float _enemyMoveUpSpeed;
    float _enemyMoveDownSpeed;
    float _enemyWaitingTime;
    float _bossWaitingTime;
    float _bossMoveUpSpeed;
    float _bossMoveDownSpeed;
    float _intervalTime;
    int _enemyCount;
    typedef BaseCharacter super;
    bool stateMove;
    bool _bossAppear;
    int cnt = 0;
    BaseCharacter *boss;
    bool isSequenceRun = false;
    int arr[9] = {
        0, 1, 2, 5, 4, 3, 6, 7, 8,
    };
    int matrix[9][4]={
        {3,1,0,0},{1,-1,3,0},{-1,3,0,0},{3,-3,-1,0},{1,-1,3,-3},{3,-3,1,0},{-3,1,0,0},{1,-1,-3,0}, {-1,-3,0,0},
    };
    int prePosition = -1;
    int posDiff = 0;
    int sequence = 0;
public:
    bool virtual create();
    int getPosition();
    int showEnemey(int tickCnt,int killedCnt);
    void showBoss();
    void virtual loadEnmey();
    void bossAppear(int killedcnt);
    

};


#endif /* defined(__sangokuCutX__Logic_Showup_01__) */

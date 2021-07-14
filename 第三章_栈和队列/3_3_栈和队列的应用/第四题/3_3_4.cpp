//
// Created by kaiven on 2021/7/14.
//

#include "../public.h"

/*
 * 一次只能十辆车
 * 先到先上
 * 每上四辆客车，就允许上一辆货车
 * 等待客车没有四辆，就让货车上
 *
 * 1 表示货车
 * 0 表示客车
 *
 * 将两种车放在两个不同的队列中
 * */
void ferry(int cars[], int len){
    SqQueue car;
    SqQueue track;
    SqQueue_init(car);
    SqQueue_init(track);
    int temp;

    // 将两种车型入队
    for (int i = 0; i < len; ++i) {
        if (cars[i] == 0){
            enQueue(car,0);
        } else if (cars[i] == 1){
            enQueue(track,1);
        }
    }

    if (len > 10){
        len = 10;
    }

    int cnt = 0;
    for (int i = 0; i < len; ++i) {
        // 前面已经有4个客车进去了
        if (cnt == 4){
            cnt = 0;
            // 确保还有客车
            if (deQueue(track, temp)){
                cout << temp << ' ';
                continue;
            }
        }

        // 客车进去
        if (deQueue(car,temp)){
            cout << temp << ' ';
            cnt++;
        } else{
            // 说明没有客车了，现在卡车可以进去的
            deQueue(track,temp);
            cout << temp << ' ';
        }
    }

}


int main(){
    int cars[] = {0,1,1,1,0,1,0,0,0,0,0,0,0};
    ferry(cars, 13);
    return 0;
}
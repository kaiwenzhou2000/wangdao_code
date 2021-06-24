//
// Created by kaiven on 2021/6/21.
//

#ifndef WANGDAO_CODE_2_2_2_H
#define WANGDAO_CODE_2_2_2_H

#include "../第一题/2_2_1.h"

// O(1)的算法空间复杂度，将L元素逆序
void reverse_list(Sqlist &L){
    int temp;
    for (int i = 0; i < L.length / 2; ++i) {
        temp = L.data[i];
        L.data[i] = L.data[L.length-1-i];
        L.data[L.length-1-i] = temp;
    }
}

#endif //WANGDAO_CODE_2_2_2_H

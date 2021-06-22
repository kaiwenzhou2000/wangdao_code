//
// Created by kaiven on 2021/6/22.
//

#ifndef WANGDAO_CODE_2_2_6_H
#define WANGDAO_CODE_2_2_6_H

#include "../第一题/2_2_1.h"
#include "../第四题/2_2_4.h"

// 删除重复元素，顺序表示有序的
bool delete_repeat(Sqlist &L){
    if (L.length == 0){
        return false;
    }
    int k = 1;
    for (int i = 1; i < L.length; ++i) {
        // i位置的元素不等于k-1位置的元素，表明现在是不重复的
        if (L.data[i] != L.data[k-1]){
            L.data[k++] = L.data[i];
        }
    }
    L.length = k;
    return true;
}

#endif //WANGDAO_CODE_2_2_6_H

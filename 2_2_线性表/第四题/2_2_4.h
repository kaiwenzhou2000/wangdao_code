//
// Created by kaiven on 2021/6/21.
//

#ifndef WANGDAO_CODE_2_2_4_H
#define WANGDAO_CODE_2_2_4_H

#include "../第一题/2_2_1.h"

// 生成顺序表 [1, 2, 3, 4, 10]
Sqlist make_seq_list(){
    Sqlist L;
    L.length = 5;
    L.data[0] = 1;
    L.data[1] = 2;
    L.data[2] = 3;
    L.data[3] = 4;
    L.data[4] = 10;
    return L;
}

bool delete_range(Sqlist &L, int s, int t){
    // s与t的关系错误
    if (s >= t){
        return false;
    }
    // 空表
    if (L.length <= 0){
        return false;
    }

    // 开始删除区间元素
    /*
     * 删除元素大于s and 小于 t
     * */
    int k = 0;
    for (int i = 0; i < L.length; ++i) {
        // 符合留在原顺序表的元素留下
        if (L.data[i]<=s || L.data[i]>=t){
            L.data[k] = L.data[i];
            k++;
        }
    }
    L.length = k;
    return true;
}

#endif //WANGDAO_CODE_2_2_4_H

//
// Created by kaiven on 2021/6/21.
//

#ifndef WANGDAO_CODE_2_2_3_H
#define WANGDAO_CODE_2_2_3_H

#include "../第一题/2_2_1.h"

// 删除顺序表中指定的所有元素
bool delete_all(Sqlist &L, int delete_num){
    int k = 0;              // 在遇到不要删除的元素的时候，k++，记录的是修改之后顺序表的索引
    for (int i = 0; i < L.length; ++i) {
        if (L.data[i] != delete_num){
            L.data[k] = L.data[i];
            k++;
        }
    }
    L.length = k;
    return true;
}

#endif //WANGDAO_CODE_2_2_3_H

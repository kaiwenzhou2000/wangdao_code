//
// Created by kaiven on 2021/6/22.
//

#ifndef WANGDAO_CODE_2_2_7_H
#define WANGDAO_CODE_2_2_7_H

#include "../第四题/2_2_4.h"

// 将两个有序的顺序表中合并成一个有序的顺序表，并由函数返回结构顺序表
// 这里是升序排列
Sqlist merge_sqlist(Sqlist L1, Sqlist L2){
    Sqlist res;
    init_list(res);         // 初始化res
    int L1_index = 0;           // 指向L1的索引
    int L2_index = 0;           // 指向L2的索引

    // 确保L1和L2的index都没有越界
    while(L1_index < L1.length && L2_index < L2.length){
        if (L1.data[L1_index] < L2.data[L2_index]){
            // 由于是升序，所以填入小的
            sqlist_append(res,L1.data[L1_index++]);
        } else{
            sqlist_append(res,L2.data[L2_index++]);
        }
    }

    // 其余剩下的元素
    while (L1_index < L1.length){
        sqlist_append(res,L1.data[L1_index++]);
    }

    while (L2_index < L2.length){
        sqlist_append(res,L2.data[L2_index++]);
    }
    return res;
}

#endif //WANGDAO_CODE_2_2_7_H

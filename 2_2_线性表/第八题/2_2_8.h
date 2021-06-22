//
// Created by kaiven on 2021/6/22.
//

#ifndef WANGDAO_CODE_2_2_8_H
#define WANGDAO_CODE_2_2_8_H

#include "../第一题/2_2_1.h"

bool show_arr(int a[], int len){
    if (len == 0){
        return false;
    }

    for (int i = 0; i < len; ++i) {
        cout << a[i] << ' ';
    }
    cout << endl;
    return true;
}

// 交换两个顺序表的位置
/*
 * 需要输入
 *      一个数组A
 *      divide 表示位序的分界线
 *      len 表示顺序表的总长度
 * */
bool exchange_sqlist(int a[], int divide, int len){
    // 进行非法数值的检验
    if (len <= 0 || divide == 0){
        return false;
    }
    if (divide >= len){
        return false;
    }

    // 下面进行分割
    // 将需要向后移动的数组进行保存
    int temp[divide];
    for (int i = 0; i < divide; ++i) {
        temp[i] = a[i];
    }

    // 将后面的元素向前面移动divide个位置
    for (int i = divide; i < len; ++i) {
        a[i-divide] = a[i];
    }

    // 将temp中的元素补充进a数组
    int temp_index = 0;
    for (int i = len-divide; i < len; ++i) {
        a[i] = temp[temp_index++];
    }

    return true;
}

#endif //WANGDAO_CODE_2_2_8_H

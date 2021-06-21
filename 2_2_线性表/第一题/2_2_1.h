//
// Created by kaiven on 2021/6/21.
//

#ifndef WANGDAO_CODE_2_2_1_H
#define WANGDAO_CODE_2_2_1_H

#define Maxsize 50

#include <iostream>
using namespace std;

// 定义顺序表的结构
typedef struct{
    int data[Maxsize];
    int length;
}Sqlist;


// 初始化顺序表
bool init_list(Sqlist &L){
    L.length = 0;
    return true;
}

// 生成顺序表 [43, 10, 9, 3, 99]
Sqlist make_list(){
    Sqlist L;
    L.length = 5;
    L.data[0] = 43;
    L.data[1] = 10;
    L.data[2] = 99;
    L.data[3] = 3;
    L.data[4] = 99;
    return L;
}


// 展示顺序表
/*
 * 输入顺序表L
 * 返回值：
 *      true 表示打印成功
 *      false 表示空表
 * */
bool show_list(Sqlist L){
    if(L.length == 0){
        return false;
    }

    for (int i = 0; i < L.length; ++i) {
        cout << L.data[i] << ' ';
    }
    cout << endl;
    return true;
}


// 第一题要求的代码
/*
 * 找到最小值，并返回，然后将最后一个元素移到被返回的元素上面
 * */
int find_min(Sqlist &L){
    // 判空
    if(L.length == 0){
        return -1;
    }

    // 查找最小值，并找到索引
    int index = 0;
    int current_min = L.data[0];
    for (int i = 1; i < L.length; ++i) {
        if(current_min > L.data[i]){
            index = i;
            current_min = L.data[i];
        }
    }

    // 将最后一个元素放到index这个位置上
    L.data[index] = L.data[L.length-1];
    L.length--;
    return current_min;
}

#endif //WANGDAO_CODE_2_2_1_H

//
// Created by kaiven on 2021/6/22.
//

#ifndef WANGDAO_CODE_2_2_9_H
#define WANGDAO_CODE_2_2_9_H

#include "../第五题/2_2_5.h"

// 折半查找
/*
 * 成功则返回索引
 * 失败返回-1
 * */
int find_by_divide(Sqlist &L, int e){
    int low = 0;
    int high = L.length-1;
    int mid;
    while (low <= high){
        mid = (low+high)/2;
        // 成功通过mid找到e元素
        if (L.data[mid] == e){
            return mid;
        } else if (L.data[mid] > e){            // 中间值大于需要查找的值，下一步查询左边比较小的数字
            high = mid - 1;
        } else{
            low = mid + 1;
        }
    }
    return -1;              // 查找失败
}

// 交换前一个元素和后一个元素（给出索引值）,如果a是顺序表中的最后的元素则什么都不干
bool exchange_item(Sqlist &L, int a){
    if (a == L.length-1){
        return true;
    }
    int temp = L.data[a];
    L.data[a] = L.data[a+1];
    L.data[a+1] = temp;
    return true;
}

// 在顺序表中插入元素
bool insert_sqlist(Sqlist &L, int e){
    // 无法插入元素
    if (L.length == Maxsize){
        return false;
    }
    // 有剩余空间插入，从后向前面遍历，将每个元素向后移动
    for (int i = L.length; i >= 0; --i) {
        L.data[i+1] = L.data[i];
        if (L.data[i] < e){     // 找到插入点
            L.data[i] = e;
            break;
        }
    }
    L.length++;
    return true;
}

// 顺序表的查找可以使用有序的顺序查找或者折半查找，这里要求时间最短，应使用折半查找
bool find_exchange(Sqlist &L, int e){
    if (L.length == 0){
        return false;
    }
    int pos = find_by_divide(L, e);
    if (pos == -1){
        // 查找失败
        insert_sqlist(L, e);
    } else{
        // 查找成功
        exchange_item(L, pos);
    }
    return true;
}

#endif //WANGDAO_CODE_2_2_9_H

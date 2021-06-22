//
// Created by kaiven on 2021/6/22.
//

#ifndef WANGDAO_CODE_2_2_10_H
#define WANGDAO_CODE_2_2_10_H

#include "../第八题/2_2_8.h"
/*
 * 将一个数组添加到另一个数组的头部
 * 我首先想到的一次移动原来的数据，
 * 将原有数据向后移动n个位置，
 * 再将需要添加在数组放在头部，
 * 但是很明显，这个会有多余的空间开销（类似于第八题）
 *
 * 王道书上的解是通过数组的转置，下面我来用代码实现
 * 这种算法的时间复杂度是O(n)，空间复杂度是O(1)
 * */

// 这是转置函数，将数组转置传入开始的索引和结束的索引
void reverse_arr(int a[], int from, int to){
    int temp;
    while(from < to){
        temp = a[from];
        a[from] = a[to];
        a[to] = temp;
        from++;
        to--;
    }
}

// 先将前面和后面的数组转置
// 再将数组整体转置
/*
 * n 表示第一个数组结束的位序
 * p 表示第二个数组结束的位序
 * */
void converse_arr(int a[], int n, int p){
    // 前面的数组进行反转
    reverse_arr(a, 0, n-1);
    // 后面的数组进行反转
    reverse_arr(a, n, p-1);
    // 整体数组进行反转
    reverse_arr(a, 0, p-1);

}

#endif //WANGDAO_CODE_2_2_10_H

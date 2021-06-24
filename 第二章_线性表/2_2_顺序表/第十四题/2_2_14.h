//
// Created by kaiven on 2021/6/23.
//

#ifndef WANGDAO_CODE_2_2_14_H
#define WANGDAO_CODE_2_2_14_H

#include "iostream"
using namespace std;

// 绝对值
int abs_(int a){
    if(a < 0){
        return -a;
    }
    return a;
}

// 计算距离
int get_D(int a, int b, int c){
    return abs_(a-b) + abs_(b-c) + abs_(c-a);
}

/*
 * 暴力破解法
 * 没啥技术含量，
 * 时间复杂度为O(n^3)
 * 空间复杂度为O(1)
 *
 * */
int find_min_D(int s1[], int s1_len, int s2[], int s2_len, int s3[], int s3_len){
    int min = get_D(s1[0], s2[0], s3[0]);
    int temp;
    for (int i = 0; i < s1_len; ++i) {
        for (int j = 0; j < s2_len; ++j) {
            for (int k = 0; k < s3_len; ++k) {
                temp = get_D(s1[i], s2[j], s3[k]);
                if(min > temp){
                    min = temp;
                }
            }
        }
    }
    return min;
}

/*
 * 王道书上的解法
 * 时间复杂度为O(n)，空间复杂度为O(1)
 *
 * 看P26页的图可知，时间上D的距离就是
 * 两倍的最远的两个数的差的绝对值
 * 注意这里的值都是递增的
 * 最小值为a，最大值c，
 * c不变，不断的更新a，让D变得最小
 *
 * */

#define MAX_INT 0x7fffffff      // 宏定义的足够大的整数

// 判断a是不是里面最小的元素
bool xls_min(int a, int b, int c){
    if (a <=b && a <= c){
        return true;
    }
    return false;
}

// 寻找最小的D
int findMinOfTrip(int a[], int n, int b[], int m, int c[], int p){
    // i, j, k分别表示数组a, b, c的角标，而D_min指的是当前的最小距离, D是用来承接后面的临时变量的
    int i = 0, j = 0, k = 0, D_min = MAX_INT, D;
    /*
     * 解释一下为什么这个D_min要大于0，
     * 因为当a, b, c相等时，路径最短为0，
     * 这种情况可以直接退出循环
     * */
    while (i < n && j < m && k < p && D_min > 0){
        D = get_D(a[i], b[j], c[k]);
        if (D_min > D){
            D_min = D;              // 发现比D_min还要小的值，更新D
        }
        if (xls_min(a[i], b[j], c[k])){
            i++;                    // a是最小值更新a
        } else if (xls_min(b[j], a[i], c[k])){
            j++;                    // b是最小值，更新b
        } else{
            k++;
        }
    }
    return D_min;
}

#endif //WANGDAO_CODE_2_2_14_H

//
// Created by kaiven on 2021/6/23.
//

#ifndef WANGDAO_CODE_2_2_11_H
#define WANGDAO_CODE_2_2_11_H

#include "iostream"
using namespace std;

/*
 * 我的想法是新创建一个数组，将两个数组按照大小顺序排入
 * 然后在再新的数组中查找中位数
 * 算法时间复杂度是O(n)
 * 算法空间复杂度为O(n)
 *
 * 王道书上的代码好像有点复杂，感觉考场上我肯定想不到，还不如用我直观的想法
 * */
int find_min_num(int s1[], int s2[], int len){
    int a[len*2];
    int a_index = 0;
    int s1_index = 0;
    int s2_index = 0;
    while(s1_index < len && s2_index < len){
        // 从小到大排列，小的先入数组
        if (s1[s1_index] > s2[s2_index]){
            a[a_index++] = s2[s2_index++];
        } else{
            a[a_index++] = s1[s1_index++];
        }
    }

    // 添加剩余的元素
    while(s1_index < len){
        a[a_index++] = s1[s1_index++];
    }
    while(s2_index < len){
        a[a_index++] = s1[s2_index++];
    }

    return a[(a_index-1)/2];
}

#endif //WANGDAO_CODE_2_2_11_H

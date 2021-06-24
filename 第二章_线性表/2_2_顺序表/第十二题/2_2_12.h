//
// Created by kaiven on 2021/6/23.
//

#ifndef WANGDAO_CODE_2_2_12_H
#define WANGDAO_CODE_2_2_12_H

#include "iostream"
using namespace std;

/*
 * 我的方法，算法时间复杂度复杂度为O(n^2)，空间复杂度为O(n^2)
 * 但是好在思维简单直观，虽然不能的满分
 * 但是，用我这种方法也能拿到10分左右，下面王道的解法可以拿11分
 * 花费太多时间去优化这种传统的题目是不划算的
 *
 * */
int find_main_element(int a[], int n){
    if (n <= 0){
        return -1;
    }

    // 利用二维数组存放元素以及元素的个数
    // 第一层存放元素本身
    // 第二层存放元素的个数
    int cnt[2][10];
    int cnt_len = 0;
    int flag = false;           // 用来判断是否找到相同的元素
    int m = n/2;
    // 完成cnt表的填写
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < cnt_len; ++j) {
            // 找到相同的元素
            if (cnt[0][j] == a[i]){
                cnt[1][j]++;
                flag = true;
            }
        }
        // 这个元素在cnt中没有，下面进行添加操作
        if (flag == false){
            cnt[0][cnt_len] = a[i];
            cnt[1][cnt_len] = 1;
            cnt_len++;
        }
        flag = false;
    }

    // 在cnt表中查询有没有cnt大于m的主元素
    for (int i = 0; i < cnt_len; ++i) {
        // 查询成功
        if (cnt[1][i] > m){
            return cnt[0][i];
        }
    }
    return -1;
}


/*
 * 王道书给出的解法
 *      1. 先找到可能能成为主元素的解
 *          由于主元素的个数一定大于n/2，所以将首先遇到元素记为c
 *          下一个不等于c的话，cnt-1，如果等于c的话，cnt+1
 *          cnt要是等于0的话，说明这个元素肯定不是候选点
 *      2. 再检验重复的次数有没有达到n/2
 * */
int Majority(int a[], int n){
    int i, c, cnt = 1;
    c = a[0];
    for(i = 1; i < n; i++){
        // 查看下一个元素是不是与c相等
        if (c == a[i]){
            cnt++;
        } else{
            cnt--;
        }
        // 检验cnt是不是为0
        if (cnt == 0){
            c = a[i];
            cnt = 1;
        }
    }

    cnt = 0;
    for (int j = 0; j < n; ++j) {
        if (a[j] == c){
            cnt++;
        }
    }
    if (cnt > n/2){
        return c;
    }
    return -1;
}

#endif //WANGDAO_CODE_2_2_12_H

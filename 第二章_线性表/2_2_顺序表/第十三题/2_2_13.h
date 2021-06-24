//
// Created by kaiven on 2021/6/23.
//

#ifndef WANGDAO_CODE_2_2_13_H
#define WANGDAO_CODE_2_2_13_H

#include "iostream"
using namespace std;

// 冒泡排序
void arr_sort(int a[], int len){
    int temp;
    for (int i = 0; i < len; ++i) {
        for (int j = i; j < len; ++j) {
            if(a[i] > a[j]){
                temp = a[j];
                a[j] = a[i];
                a[i] = temp;
            }
        }
    }
}

/*
 * 寻找最小的正整数
 *
 * 我的想法：
 *      1. 先将数组进行排序
 *      2. 再从后向前扫描，找到最小的非负
 *          - 最小不为1则返回min-1
 *          - 最小为1，则往后搜索，找最小的整数
 *
 * 时间复杂度为O(n^2)，主要是我采用了冒泡排序
 * 空间复杂度为O(1)，没有额外的空间开销
 * */
int find_min_num(int a[], int len){
    arr_sort(a, len);
    bool flag = false;          // 用来判断是否遇到1
    for (int i = 0; i < len; ++i) {
        if(!flag){              // 没有遇到1
            if(a[i] <= 0){
                // 遇到小于等于0的继续向后扫描
                continue;
            } else if(a[i] > 1){
                // 遇到大于1的直接返回1
                return 1;
            } else{
                // 遇到1这种特殊情况了
                flag = true;
            }
        } else{                 // 遇到1以后的特殊情况
            /*
             * 在遇到一之后，看后面的数字是否大于前面的数字-1
             * */
            if(a[i] == a[i-1]+1){
                continue;
            }
            return a[i-1]+1;
        }
    }
    return a[len-1]+1;
}


/*
 * 王道书上的答案，方法很巧妙
 * 先说算法复杂度：
 * 时间复杂度为O(1)
 * 空间复杂度为O(n)
 * 是一种空间换时间的做法
 * 数组的长度为n，
 * 这数组中最的整数值不可能超过n
 * 所以将最小值的候选点放入数组b中
 *
 * */
int findMissMin(int a[], int n){
    int i, *b;                                        // 标记数组
    b = (int *) malloc(sizeof(int)*n);          // 分配空间
    memset(b, 0, sizeof(int)*n);                // 赋初值为0
    for(i = 0; i < n; i++){
        if (a[i] > 0 && a[i] <= n){
            b[a[i]-1] = 1;                          // 1表示被标记，数组中存在这个值
        }
    }
    // 找标记数组中第一个为0的就可以了
    for(i = 0; i < n; i++){
        if (b[i] == 0){
            break;
        }
    }
    return i+1;

}

#endif //WANGDAO_CODE_2_2_13_H

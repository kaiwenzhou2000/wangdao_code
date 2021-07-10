//
// Created by kaiven on 2021/7/10.
//

#ifndef WANGDAO_CODE_2_3_23_H
#define WANGDAO_CODE_2_3_23_H

#include "../第二十二题/2_3_22.h"

/*
 * 去除重复的绝对值相同的元素
 * n 表示data的范围
 * */
void remove_same_abs(LinkList &LA, int n){
    int arr[n+1];
    LNode *pa = LA->next;
    LNode *pa_pre = LA;
    memset(arr, 0, sizeof(arr));
    while(pa){
        if (arr[abs(pa->data)] == 1){
            // 说明这个元素在链表中出现过，要去除
            pa_pre->next = pa->next;
            free(pa);
            pa = pa_pre->next;
        } else{
            // 没有出现过
            arr[abs(pa->data)] = 1;
            pa = pa->next;
            pa_pre = pa_pre->next;
        }
    }
}

#endif //WANGDAO_CODE_2_3_23_H

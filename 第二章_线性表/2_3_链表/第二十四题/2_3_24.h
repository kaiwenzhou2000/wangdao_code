//
// Created by kaiven on 2021/7/10.
//

#ifndef WANGDAO_CODE_2_3_24_H
#define WANGDAO_CODE_2_3_24_H

#include "../第二十三题/2_3_23.h"

/*
 * 判断链表是否有环
 * 找出出入口
 *
 * 王道书上的算法好复杂。。。
 * */
LNode* find_loop_link_list(LinkList LA){
    LNode* arr[99];
    int arr_index = 0;
    LNode *pa = LA->next;
    while (pa){
        for (int i = 0; i < arr_index; ++i) {
            if (arr[i] == pa){
                return pa;
            }
        }
        // 添加元素
        arr[arr_index++] = pa;
        pa = pa->next;
    }
    return nullptr;
}

#endif //WANGDAO_CODE_2_3_24_H

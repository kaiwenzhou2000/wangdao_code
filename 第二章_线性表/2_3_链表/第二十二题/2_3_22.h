//
// Created by kaiven on 2021/7/10.
//

#ifndef WANGDAO_CODE_2_3_22_H
#define WANGDAO_CODE_2_3_22_H

#include "../第二十一题/2_3_21.h"

/*
 * 因为要看相同的后缀
 * 要有相同的后缀的前提条件就是长度要相同
 * 首先保证两个链表开始扫描时候的长度相同
 *
 * */

LNode* comm_pos(LinkList LA, LinkList LB){
    int LA_len = link_list_len(LA);
    int LB_len = link_list_len(LB);
    LNode* pa = LA->next;
    LNode* pb = LB->next;

    if (LA_len > LB_len){
        for (int i = 0; i < LA_len - LB_len; ++i) {
            pa = pa->next;
        }
    } else{
        for (int i = 0; i < LB_len - LA_len; ++i) {
            pb = pb->next;
        }
    }

    while (pa != pb){
        pa = pa->next;
        pb = pb->next;
    }
    return pa;
}


#endif //WANGDAO_CODE_2_3_22_H

//
// Created by kaiven on 2021/6/27.
//

#ifndef WANGDAO_CODE_2_3_15_H
#define WANGDAO_CODE_2_3_15_H

#include "../第十四题/2_3_14.h"

/*
 * 求两个链表的交集，
 * 并存放在链表LA中
 *
 * */
void cross(LinkList &LA, LinkList &LB){
    LNode *pa = LA->next;
    LNode *pa_pre = LA;
    LNode *pb = LB->next;
    while (pa && pb){
        if (pa->data < pb->data){
            // 去掉pa这个节点
            pa_pre->next = pa->next;
            free(pa);
            pa = pa_pre->next;
        } else if (pa->data > pb->data){
            pb = pb->next;
        } else{
            pa = pa->next;
            pa_pre = pa_pre->next;
            pb = pb->next;
        }
    }
}

#endif //WANGDAO_CODE_2_3_15_H

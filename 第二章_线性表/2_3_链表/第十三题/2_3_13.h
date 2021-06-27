//
// Created by kaiven on 2021/6/27.
//

#ifndef WANGDAO_CODE_2_3_13_H
#define WANGDAO_CODE_2_3_13_H

#include "../第十一题/2_3_11.h"
#include "../第十二题/2_3_12.h"

/*
 * 我的想法是先顺序合并，在逆置链表
 * 王道书上用的头插法，然后在插得时候逆序
 *
 * */
void merge_and_reverse(LinkList &L1, LinkList &L2){
    LNode *p = L1->next;
    LNode *p_pre = L1;
    LNode *t = L2->next;
    LNode *t_pre = L2;
    while (p && t){
        if (p->data < t->data){
            p = p->next;
            p_pre = p_pre->next;
        } else{
            // t节点插入p之前
            t_pre->next = t->next;
            t->next = p;
            p_pre->next = t;
            p_pre = p_pre->next;
            t = t_pre->next;
        }
    }
    // L2中是否还有值
    if (t){
        p_pre->next = t;
    }
    reverse_LinkList(L1);
}

#endif //WANGDAO_CODE_2_3_13_H

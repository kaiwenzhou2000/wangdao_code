//
// Created by kaiven on 2021/6/26.
//

#ifndef WANGDAO_CODE_2_3_10_H
#define WANGDAO_CODE_2_3_10_H

#include "../第二题/2_3_2.h"

// 判断是不是偶数
bool is_double(int num){
    if (num%2 == 0){
        return true;
    }
    return false;
}

/*
 * 将一个链表,变成两个，一个是奇数，一个是偶数
 *
 * */
LinkList spilit_LinkList(LinkList &L1){
    LinkList L2;
    Link_list_init_with_head(L2);
    LNode *p = L2;                  // p用来指向L2链表的
    LNode *t = L1->next;            // t是用来指向L1链表的
    LNode *t_pre = L1;

    while (t){
        if (is_double(t->data)){
            // 偶数的情况下，将t指向的元素放到L2链表中
            t_pre->next = t->next;
            p->next = t;
            p = p->next;
            p->next = nullptr;
            t = t_pre->next;
        } else{
            // 奇数的情况下，t向后移动
            t = t->next;
            t_pre = t_pre->next;
        }
    }
    return L2;
}

#endif //WANGDAO_CODE_2_3_10_H

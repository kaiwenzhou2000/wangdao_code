//
// Created by kaiven on 2021/6/26.
//

#ifndef WANGDAO_CODE_2_3_7_H
#define WANGDAO_CODE_2_3_7_H

#include "../第六题/2_3_6.h"

/*
 * 删除指定区间的值
 * 本质上还是遍历链表，
 * 删除指定的值
 *
 * */
void delete_range(LinkList &L, int from, int to){
    LNode *p = L->next;
    LNode *pre = L;
    LNode *s;
    while(p){
        // 满足删除条件
        if (p->data > from && p->data < to){
            s = p;
            p = p->next;
            pre->next = p;
            free(s);
            continue;
        }
        pre = pre->next;
        p = p->next;
    }
}


#endif //WANGDAO_CODE_2_3_7_H

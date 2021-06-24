//
// Created by kaiven on 2021/6/24.
//

#ifndef WANGDAO_CODE_2_3_5_H
#define WANGDAO_CODE_2_3_5_H

#include "../第二题/2_3_2.h"

void LinkList_reverse_locate(LinkList &L){
    LNode *p = L->next;
    LNode *pre = L;
    LNode *s;
    LNode *tail = L->next;              // 逆置之后的尾节点
    while (p){
        s = p->next;
        p->next = pre;
        pre = p;
        p = s;
    }
    L->next = pre;
    tail->next = nullptr;
}

#endif //WANGDAO_CODE_2_3_5_H

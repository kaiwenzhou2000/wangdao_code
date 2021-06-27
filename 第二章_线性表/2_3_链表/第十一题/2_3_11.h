//
// Created by kaiven on 2021/6/27.
//

#ifndef WANGDAO_CODE_2_3_11_H
#define WANGDAO_CODE_2_3_11_H

#include "../第二题/2_3_2.h"

/*
 * 这道题实际上就是一个拆分+逆置的题目
 * */
void reverse_LinkList(LinkList &L){
    LNode *p = L->next->next;
    LNode *p_pre = L->next;
    LNode *temp;

    // 处理第一个节点
    p_pre->next = nullptr;
    while (p){
        temp = p->next;
        p->next = p_pre;
        p_pre = p;
        p = temp;
    }
    L->next = p_pre;
}

void spilit_reverse_LinkList(LinkList &L1, LinkList &L2){
    LNode *p = L1->next;
    LNode *p_pre = L1;
    LNode *t = L2;
    int cnt = 0;
    while (p){
        if (cnt%2!=0){
            // 添加到L2
            p_pre->next = p->next;
            t->next = p;
            t = t->next;
            t->next = nullptr;
            p = p_pre->next;
        } else{
            // 保留在L1
            p = p->next;
            p_pre = p_pre->next;
        }
        cnt++;
    }

    // 逆置
    reverse_LinkList(L1);
    reverse_LinkList(L2);
}

#endif //WANGDAO_CODE_2_3_11_H

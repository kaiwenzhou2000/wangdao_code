//
// Created by kaiven on 2021/6/27.
//

#ifndef WANGDAO_CODE_2_3_12_H
#define WANGDAO_CODE_2_3_12_H

#include "../第二题/2_3_2.h"

/*
 * 将数组转换为Linklist
 * */
LinkList arr2LinkList(int a[], int len){
    LinkList L;
    Link_list_init_with_head(L);
    LNode *p = L;
    LNode *s;
    for (int i = 0; i < len; ++i) {
        s = (LNode*) malloc(sizeof(LNode));
        s->data = a[i];
        p->next = s;
        p = p->next;
        p->next = nullptr;
    }
    return L;
}

/*
 * 在有序的链表中去掉重复的元素
 * 实际上只要比较前一个元素和后一个元素是不是相等就可以了
 *
 * */
void delete_repeat(LinkList &L){
    LNode *p = L->next->next;
    LNode *p_pre = L->next;
    LNode *s;
    while (p){
        if (p_pre->data == p->data){
            // 去掉p元素
            s = p;
            p = p->next;
            p_pre->next = p;
            free(s);
        } else{
            p = p->next;
            p_pre = p_pre->next;
        }
    }
}
#endif //WANGDAO_CODE_2_3_12_H

//
// Created by kaiven on 2021/6/25.
//

#ifndef WANGDAO_CODE_2_3_6_H
#define WANGDAO_CODE_2_3_6_H

#include "../第二题/2_3_2.h"

// 生成长度为10的带头结点的链表
LinkList get_LinkList_with_head_random(){
    LinkList L;
    Link_list_init_with_head(L);
    LNode *p = L;
    LNode *s;
    for (int i = 0; i < 10; ++i) {
        s = (LNode*) malloc(sizeof(LNode));
        s->data = rand()/10000000;
        s->next = p->next;
        p->next = s;
        p = p->next;
        p->next = nullptr;
    }
    return L;
}


// 使带头节点的链表有序增加
/*
 * 看了王道书
 * 书上是使用类似插入排序的思想
 * 就是先取出一个节点，
 * 然后不断的向之前的链表中根据元素的大小添加元素
 * */
void sort_LinkList(LinkList &L){
    LNode *p = L->next->next;             // 用来原来链表的后面的节点
    LNode *s = L->next;                   // s用来指向新的节点
    LNode *pre = L;                       // 用来表示s之前的节点
    LNode *temp;                          // 用来临时保存p后面的节点

    // 解决第一个头节点的问题
    pre->next = s;
    s->next = nullptr;

    while (p){
        // p指向的元素的值小于s指向的元素的值，则进入循环（说明没有符合条件）
        s = L->next;
        pre = L;
        while(p->data > s->data){
            s = s->next;
            pre = pre->next;
            // s不存在的情况下跳出循环
            if (!s){
                break;
            }
        }
        // 将p插入到s之前
        temp = p->next;              // 保存p后面的节点
        p->next = s;
        pre->next = p;

        // p节点向后移动
        p = temp;
    }

}

#endif //WANGDAO_CODE_2_3_6_H

//
// Created by kaiven on 2021/7/9.
//

#ifndef WANGDAO_CODE_2_3_18_H
#define WANGDAO_CODE_2_3_18_H

#include "../第十五题/2_3_15.h"

/*
 * 连接两个循环链表
 * */

void loop_link_list_init(LinkList &LA){
    LA = (LNode*) malloc(sizeof(LNode));
    LA->data = -1;
    LA->next = LA;
}


// 添加元素（头插法）
void loop_link_list_push(LinkList LA, int e){
    LNode *p = (LNode*) malloc(sizeof(LNode));
    p->data = e;
    p->next = LA->next;
    LA->next = p;
}

void show_loop_link_list(LinkList LA){
    LNode *p = LA->next;
    while (p->data != -1){
        cout << p->data << ' ';
        p = p->next;
    }
    cout << endl;
}


// 将LB合并在LA的后面
void merge_loop_link_list(LinkList &LA, LinkList &LB){
    // 寻找LA的尾指针
    LNode *pa_tail = LA;
    while (pa_tail->next != LA){
        pa_tail = pa_tail->next;
    }

    // 寻找LB的尾指针
    LNode *pb_tail = LA;
    while (pb_tail->next != LA){
        pb_tail = pb_tail->next;
    }

    pb_tail->next = LA;
    pa_tail->next = LB->next;
    free(LB);
}

#endif //WANGDAO_CODE_2_3_18_H

//
// Created by kaiven on 2021/7/10.
//

#ifndef WANGDAO_CODE_2_3_25_H
#define WANGDAO_CODE_2_3_25_H

#include "../第二十四题/2_3_24.h"

/*
 * 1, 2, 3, 4, 5
 * */
void remerge(LinkList &LA){
    LNode *p = LA->next;
    LNode *p_pre = LA;
    LNode *tail;
    LNode *tail_pre;
    while (p){
        tail = p;
        tail_pre = p_pre;
        // 找到尾指针
        while(tail->next){
            tail_pre = tail_pre->next;
            tail = tail->next;
        }
        tail_pre->next = nullptr;
        tail->next = p->next;
        p->next = tail;
        // 指正向后移动两位
        p = p->next->next;
        p_pre = p_pre->next->next;
    }

}

#endif //WANGDAO_CODE_2_3_25_H

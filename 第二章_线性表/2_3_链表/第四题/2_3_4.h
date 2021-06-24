//
// Created by kaiven on 2021/6/24.
//

#ifndef WANGDAO_CODE_2_3_4_H
#define WANGDAO_CODE_2_3_4_H

#include "../第二题/2_3_2.h"

// 删除最小节点
void delete_min(LinkList &L){
    LNode *p=L->next;                   // 用来遍历的节点
    LNode *pre=L;                       // 用来遍历的节点,之前的指针
    LNode *min = L->next;               // 存放最小节点的指针
    LNode *min_pre = L;                 // 最小节点指正的之前的一个指针（便于删除）

    while (p){
        // 最小节点要小于现在扫描的节点
        if (p->data < min->data){
            min = p;
            min_pre = pre;
        }
        p = p->next;
        pre = pre->next;
    }

    // 下面开始删除min指向的元素
    min_pre->next = min->next;
    free(min);
}

#endif //WANGDAO_CODE_2_3_4_H

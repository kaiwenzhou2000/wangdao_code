//
// Created by kaiven on 2021/6/26.
//

#ifndef WANGDAO_CODE_2_3_9_H
#define WANGDAO_CODE_2_3_9_H

#include "../第八题/2_3_8.h"
#include "../第六题/2_3_6.h"

/*
 * 不准使用数组的情况下递增输出链表的值，并释放节点空间
 * 我的想法是不断的输出最小值
 *
 * */
void show_LinkList_increase(LinkList &L){
    LNode *p = L->next;
    LNode *pre_p = L;
    LNode *min = L->next;               // 最小的元素
    LNode *min_pre = L;                 // 最小的元素的前面一个元素（方便删除元素）
    int len = LinkList_len(L);          // 链表的长度
    for (int i = 0; i < len; ++i) {
        p = L->next;
        pre_p = L;
        min = L->next;
        min_pre = L;
        while (p){
            // 需要跟换min的值
            if (p->data < min->data){
                min = p;
                min_pre = pre_p;
            }
            pre_p = pre_p->next;
            p = p->next;
        }
        // 输出min
        if (min){
            // 输出min，释放min
            cout << min->data << ' ';
            min_pre->next = min->next;
            free(min);
        }
    }

}

#endif //WANGDAO_CODE_2_3_9_H

//
// Created by kaiven on 2021/7/9.
//

#ifndef WANGDAO_CODE_2_3_19_H
#define WANGDAO_CODE_2_3_19_H

#include "../第十八题/2_3_18.h"

void find_min_loop(LinkList &LA){
    LNode *pa = LA->next;         // 指向LA的指针
    LNode *pa_pre = LA;           // 指向LA前驱的指针

    // 下面两个节点是指向最小的节点，并方便删除
    LNode *pa_min = LA->next;
    LNode *pa_min_pre = LA;

    // 当pa->next != pa说明之后一个头结点了
    while (pa->next != pa){
        if (pa == LA){
            // 说明遍历到头结点了
            // 输出最小值，并删除元素
            cout << pa_min->data << ' ';
            pa_min_pre->next = pa_min->next;
            free(pa_min);
            // 重置最小值
            pa_min = LA->next;
            pa_min_pre = LA;
        }else if (pa->data < pa_min->data){
            // 发现更小的节点
            pa_min = pa;
            pa_min_pre = pa_pre;
        }
        // 继续向后走
        pa = pa->next;
        pa_pre = pa_pre->next;
    }
    free(pa);
}

#endif //WANGDAO_CODE_2_3_19_H

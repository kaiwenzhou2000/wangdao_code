//
// Created by kaiven on 2021/6/27.
//

#ifndef WANGDAO_CODE_2_3_14_H
#define WANGDAO_CODE_2_3_14_H

#include "../第十三题/2_3_13.h"

LinkList get_common_LinkList(LinkList &LA, LinkList &LB){
    LNode *pa = LA->next;
    LNode *pa_pre = LA;
    LNode *pb = LB->next;
    LNode *pb_pre = LB;
    LNode *s;
    LinkList LC;
    Link_list_init_with_head(LC);
    LNode *pc = LC;
    while (pa && pb){
        if (pa->data < pb->data){
            pa = pa->next;
            pa_pre = pa_pre->next;
        } else if (pa->data > pb->data){
            pb = pb->next;
            pb_pre = pb_pre->next;
        } else{
            // 相等的情况
            s = (LNode*) malloc(sizeof(LNode));
            s->data = pa->data;
            pc->next = s;
            pc = pc->next;
            pc->next = nullptr;
            pa = pa->next;
            pb = pb->next;
        }
    }
    return LC;
}

#endif //WANGDAO_CODE_2_3_14_H

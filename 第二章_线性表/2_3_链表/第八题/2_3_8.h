//
// Created by kaiven on 2021/6/26.
//

#ifndef WANGDAO_CODE_2_3_8_H
#define WANGDAO_CODE_2_3_8_H

#include "../第二题/2_3_2.h"

// 生成两个有公共节点的链表，公共节点中的元素值是2
void make_two_LinkList(LinkList &L1, LinkList &L2){
    L1 = get_LinkList_with_head();
    Link_list_init_with_head(L2);
    LNode *p = L2;
    LNode *s;
    s = (LNode*) malloc(sizeof(LNode));
    s->data = -1;
    s->next = L1->next->next;
    p->next = s;
}

// 计算链表的长度
int LinkList_len(LinkList L){
    LNode *p = L;
    int cnt = 0;
    while(p){
        cnt++;
        p = p->next;
    }
    return cnt;
}

/*
 * 找两个链表的公共节点
 * 这里的公共节点指的是地址相同的节点，不单单是值相等
 * 其实有没有公共节点，就只要看看最后节点是不是公共的就行了
 * 因为在公共节点之后的所有节点都是公共的
 *
 * */
LNode* find_common_node(LinkList L1, LinkList L2){
    int L1_len = LinkList_len(L1);
    int L2_len = LinkList_len(L2);
    LNode *p = L1->next;
    LNode *t = L2->next;
    // 找到长度相同的节点
    if (L1_len > L2_len){
        for (int i = 0; i < L1_len - L2_len; ++i) {
            p = p->next;
        }
    } else{
        for (int i = 0; i < L2_len - L1_len; ++i) {
            t = t->next;
        }
    }

    // 开始比较元素节点
    while(p){
        if (p == t){
            return p;
        }
        p = p->next;
        t = t->next;
    }
    return nullptr;
}
#endif //WANGDAO_CODE_2_3_8_H

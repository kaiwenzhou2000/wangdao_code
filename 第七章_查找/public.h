//
// Created by kaiven on 2021/8/31.
//

#ifndef WANGDAO_CODE_PUBLIC_H
#define WANGDAO_CODE_PUBLIC_H

#include "iostream"
#include "cstdlib"

using namespace std;


// 链表数据结构
typedef struct LNode{
    int data;
    struct LNode *next;
}LNode, *LinkList;

// 带头结点的链表初始化
void Link_list_init_with_head(LinkList &L){
    L = (LNode*) malloc(sizeof(LNode));
    L->next = nullptr;
}

// 生成长度为10的带头结点的链表
LinkList get_LinkList_with_head(){
    LinkList L;
    Link_list_init_with_head(L);
    LNode *p = L;
    LNode *s;
    for (int i = 0; i < 10; ++i) {
        s = (LNode*) malloc(sizeof(LNode));
        s->data = i;
        s->next = p->next;
        p->next = s;
        p = p->next;
        p->next = nullptr;
    }
    return L;
}

void show_LinkList_with_head(LinkList L){
    LNode *p = L->next;
    while (p){
        cout << p->data << ' ';
        p = p->next;
    }
    cout << endl;
}

#define maxN 100

#endif //WANGDAO_CODE_PUBLIC_H

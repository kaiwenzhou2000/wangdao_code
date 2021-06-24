//
// Created by kaiven on 2021/6/24.
//

#ifndef WANGDAO_CODE_2_3_2_H
#define WANGDAO_CODE_2_3_2_H


#include "../第一题/2_3_1.h"
using namespace std;

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

// 删除带头结点链表的指定值
bool delete_LinkList_item_value(LinkList &L, int e){
    if (L->next == nullptr){
        return false;
    }
    /*
     * 一定要设置两个指针
     * 一个指向前面的元素，
     * 一个指向后面的元素
     *
     * */
    LNode *p = L;
    LNode *s = L->next;

    while(s){
        if (s->data == e){
            p->next = s->next;
            free(p->next);
        }
        p = p->next;
        s = s->next;
    }
    return true;
}

void show_LinkList_with_head(LinkList L){
    LNode *p = L->next;
    while (p){
        cout << p->data << ' ';
        p = p->next;
    }
    cout << endl;
}

#endif //WANGDAO_CODE_2_3_2_H

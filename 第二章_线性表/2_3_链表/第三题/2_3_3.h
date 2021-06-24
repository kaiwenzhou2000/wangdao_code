//
// Created by kaiven on 2021/6/24.
//

#ifndef WANGDAO_CODE_2_3_3_H
#define WANGDAO_CODE_2_3_3_H

#include "../第二题/2_3_2.h"
#define MAXSIZE 50

void show_LinkList_reverse(LinkList L){
    LNode *p = L->next;
    int a[MAXSIZE];
    int len = 0;
    while (p){
        a[len++] = p->data;
        p = p->next;
    }
    for (int i = len-1; i >= 0; --i) {
        cout << a[i] << ' ';
    }
    cout << endl;
}

/*
 * 时间复杂度是一样的
 * 但是空间复杂度少
 * */
void show_linkList_reverse_recursion(LinkList L){
    // 递归的退出条件
    if (L->next == nullptr){
        return;
    }
    show_linkList_reverse_recursion(L->next);
    cout << L->next->data << ' ';
}

#endif //WANGDAO_CODE_2_3_3_H

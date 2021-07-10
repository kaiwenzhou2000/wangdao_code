//
// Created by kaiven on 2021/7/10.
//

#ifndef WANGDAO_CODE_2_3_21_H
#define WANGDAO_CODE_2_3_21_H

#include "../第十五题/2_3_15.h"

/*
 * 查找倒数第k个元素
 * 我的想法是，首先要知道链表的长度，
 * 然后通过作差的方式，知道元素的位置
 *
 * 或者通过数组来存放临时的变量，
 * 但是那样的话就会有额外的空间开销
 *
 * */


// 计算链表的总长度
int link_list_len(LinkList L){
    LNode *p = L->next;
    int cnt = 0;
    while (p){
        cnt++;
        p = p->next;
    }
    return cnt;
}

/*
 * 找出倒数的指定元素
 * */
int find_element_reverse(LinkList L, int n){
    int len = link_list_len(L);
    // 计算出是正数第几个
    int pos = len - n + 1;
    // 确保pos的值是合法的
    if (pos <= 0){
        return 0;
    }

    LNode *p = L;
    // 开始寻找pos所在位置的元素
    for (int i = 0; i < pos; ++i) {
        p = p->next;
    }
    cout << p->data << endl;
    return 1;
}

/*
 * 王道书上的写法非常的好
 * 主要是运用了两个指正，
 * 这样只要遍历一边就可以
 * 我这里来实现以下
 * */

int search_k(LinkList L, int n){
    LNode *p = L->next;
    LNode *q = L->next;
    // 先让p走n个位置
    for (int i = 0; i < n-1; ++i) {
        p = p->next;
    }
    // 说明链表里面没有n个元素
    if (p == nullptr){
        return 0;
    }

    // p，q同时向后走，知道p的是尾指针
    while(p->next != nullptr){
        p = p->next;
        q = q->next;
    }

    cout << q->data << endl;
    return 1;

}

#endif //WANGDAO_CODE_2_3_21_H

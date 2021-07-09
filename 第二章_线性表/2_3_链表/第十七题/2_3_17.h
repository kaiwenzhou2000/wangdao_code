//
// Created by kaiven on 2021/7/9.
//

#ifndef WANGDAO_CODE_2_3_17_H
#define WANGDAO_CODE_2_3_17_H

#include "iostream"
#include "cstdlib"

using namespace std;

typedef struct double_node{
    int data;
    struct double_node* pre;
    struct double_node* next;
}double_node, *double_link_list;

void double_link_list_init(double_link_list &LA){
    LA = (double_node*) malloc(sizeof(double_node));
    LA->data = -1;
    LA->next = LA;
    LA->pre = LA;
}


// 给双向链表添加元素（头插法）
void double_link_list_push(double_link_list &LA, int e){
    double_node* p = (double_node*) malloc(sizeof(double_node));
    p->data = e;
    p->next = LA->next;
    p->pre = LA;
    LA->next->pre = p;
    LA->next = p;
}


// 展示双向循环链表
void show_double_link_list(double_link_list LA){
    double_node *p = LA->next;
    while (p->data != -1){
        cout << p->data << ' ';
        p = p->next;
    }
    cout << endl;
}

bool is_symmetrical(double_link_list LA){
    double_node *pa_next = LA->next;           // 不断向后面遍历
    double_node *pa_pre = LA->pre;            // 不断向前面遍历
    // 要考虑奇偶情况
    while (pa_next->next != pa_pre || pa_pre == pa_next){
        if (pa_next->data != pa_pre->data){
            return false;
        }
        pa_next = pa_next->next;
        pa_pre = pa_pre->pre;
    }
    return true;

}


#endif //WANGDAO_CODE_2_3_17_H

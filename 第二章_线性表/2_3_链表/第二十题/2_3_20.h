//
// Created by kaiven on 2021/7/9.
//

#ifndef WANGDAO_CODE_2_3_20_H
#define WANGDAO_CODE_2_3_20_H

#include "iostream"
#include "cstdlib"

using namespace std;

typedef struct doube_node{
    int data;
    struct doube_node* pred;
    struct doube_node* next;
    int freq;
}doube_node, *double_link_list;

void double_link_list_init(double_link_list &L){
    L = (doube_node*) malloc(sizeof(doube_node));
    L->next = nullptr;
    L->pred = nullptr;
    L->data = -1;
    L->freq = -1;
}


// 插入元素（头插法）
void double_link_list_push(double_link_list &L, int e){
    doube_node* p = (doube_node*) malloc(sizeof(doube_node));
    p->data = e;
    p->freq = 0;

    // 指针指向
    p->next = L->next;
    p->pred = L;
    L->next = p;
}

void show_double_link_list(double_link_list L){
    doube_node* p = L->next;
    while (p){
        cout << p->data << ' ';
        p = p->next;
    }
    cout << endl;
}

doube_node Locate(double_link_list L, int x){
    doube_node *p = L->next;
    while (L){
        if (p->data == x){
            
            return p;
        }
        p = p->next;
    }

}

#endif //WANGDAO_CODE_2_3_20_H

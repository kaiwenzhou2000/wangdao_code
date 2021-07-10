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
    // p是最后一个元素的情况
    if (p->next != nullptr){
        p->next->pred = p;
    }
}

void show_double_link_list(double_link_list L){
    doube_node* p = L->next;
    while (p){
        cout << p->data << ' ';
        p = p->next;
    }
    cout << endl;
}

doube_node* Locate(double_link_list L, int x){
    doube_node *p = L->next;        // p所指向的元素是要被改变的元素
    doube_node *pre;                // 前探指针
    while (L){
        // 找到需要改变的节点
        if (p->data == x){
            p->freq++;
            // 指定pre
            pre = p->pred;
            // 移除p元素
            if (p->next == nullptr){
                // 是最后一个节点
                p->pred->next = nullptr;
            } else{
                // 不是最后一个节点
                p->pred->next = p->next;
                p->next->pred = p->pred;
            }
            while (pre != L){
                if (pre->freq > p->freq){
                    p->next = pre->next;
                    p->pred = pre;
                    pre->next->pred = p;
                    pre->next = p;
                    return p;
                }
                pre = pre->pred;
            }
            // 表明pre现在是头结点
            p->next = pre->next;
            p->pred = pre;
            pre->next->pred = p;
            pre->next = p;
            return p;
        }
        p = p->next;
    }
    return nullptr;
}

#endif //WANGDAO_CODE_2_3_20_H

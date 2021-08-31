//
// Created by kaiven on 2021/8/31.
//

#include "../public.h"

/*
 * 将找到的元素与前面的元素互换
 * */

// 链表中交换两个元素
void swap_link_list(LinkList &L, LNode *pre, LNode *p){
    int temp;
    // 保证不与头结点交换位置
    if (pre != L){
        temp = pre->data;
        pre->data = p->data;
        p->data = temp;
    }
}

// 链表
void search_link_list(LinkList &L, int num){
    LNode *pre = L;
    LNode *p = L->next;

    while (p){
        if (p->data == num){
            // 找到元素
            cout << p->data << endl;
            // 调整位置
            swap_link_list(L, pre, p);
            return;
        }
        p = p->next;
        pre = pre->next;
    }
}

void swap_array(int a[], int i){
    int temp;
    if (i > 0){
        temp = a[i];
        a[i] = a[i-1];
        a[i-1] = temp;
    }
}

// 顺序表
void search_array(int a[], int num){
    for (int i = 0; i < 10; ++i) {
        if (a[i] == num){
            cout << a[i] << endl;
            swap_array(a, i);
        }
    }
}

int main(){
    LinkList L = get_LinkList_with_head();
    int a[10];
    for (int i = 0; i < 10; ++i) {
        a[i] = i;
    }
    search_array(a, 4);
    search_link_list(L, 4);
    show_LinkList_with_head(L);
    for (int i = 0; i < 10; ++i) {
        cout << a[i] << ' ';
    }
    return 0;
}
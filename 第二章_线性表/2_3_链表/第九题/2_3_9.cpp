//
// Created by kaiven on 2021/6/26.
//

#include "2_3_9.h"

int main(){
    LinkList L = get_LinkList_with_head_random();
    cout << "原来的链表" << endl;
    show_LinkList_with_head(L);
    cout << "顺序输出的链表" << endl;
    show_LinkList_increase(L);
}
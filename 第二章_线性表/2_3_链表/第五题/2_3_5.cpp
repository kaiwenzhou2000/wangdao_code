//
// Created by kaiven on 2021/6/24.
//

#include "2_3_5.h"

int main(){
    LinkList L = get_LinkList_with_head();
    cout << "展示链表" << endl;
    show_LinkList_with_head(L);
    LinkList_reverse_locate(L);
    cout << "转置后的链表" << endl;
    show_LinkList_with_head(L);
    return 0;
}
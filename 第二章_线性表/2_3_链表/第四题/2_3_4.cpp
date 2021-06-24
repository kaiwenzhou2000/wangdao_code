//
// Created by kaiven on 2021/6/24.
//

#include "2_3_4.h"


int main(){
    LinkList L = get_LinkList_with_head();
    cout << "展示链表" << endl;
    show_LinkList_with_head(L);
    delete_min(L);
    cout << "展示删除后的链表" << endl;
    show_LinkList_with_head(L);
    return 0;
}
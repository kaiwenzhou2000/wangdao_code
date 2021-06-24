//
// Created by kaiven on 2021/6/24.
//

#include "2_3_3.h"

int main(){
    LinkList L = get_LinkList_with_head();
    cout << "链表展示" << endl;
    show_LinkList_with_head(L);
    cout << "链表逆序" << endl;
    show_LinkList_reverse(L);
    cout << "使用递归逆序" << endl;
    show_linkList_reverse_recursion(L);
    return 0;
}
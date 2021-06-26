//
// Created by kaiven on 2021/6/26.
//

#include "2_3_8.h"

int main(){
    LinkList L1;
    LinkList L2;
    make_two_LinkList(L1, L2);
    cout << "L1链表" << endl;
    show_LinkList_with_head(L1);
    cout << "L2链表" << endl;
    show_LinkList_with_head(L2);
    cout << "共同的元素是" << find_common_node(L1, L2)->data << endl;
}

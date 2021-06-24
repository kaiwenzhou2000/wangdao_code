//
// Created by kaiven on 2021/6/24.
//

#include "2_3_1.h"

int main(){
    LinkList L = get_LinkList_without_head();
    cout << "生成链表" << endl;
    show_link_list_without_head(L);
    delete_item_value_recursion(L, 3);
    cout << "删除之后的链表（存在不能删除最后一个节点的bug）" << endl;
    show_link_list_without_head(L);
    Del_X_3(L, 9);
    cout << "王道书上删除之后的链表(非常完美)" << endl;
    show_link_list_without_head(L);
    return 0;
}
//
// Created by kaiven on 2021/6/24.
//

#include "2_3_2.h"

int main(){
    LinkList L = get_LinkList_with_head();
    cout << "生成链表" << endl;
    show_LinkList_with_head(L);
    delete_LinkList_item_value(L, 9);
    cout << "删除之后的链表" << endl;
    show_LinkList_with_head(L);
    return 0;
}
//
// Created by kaiven on 2021/6/27.
//

#include "2_3_11.h"

int main(){
    LinkList L1 = get_LinkList_with_head();
    LinkList L2;
    Link_list_init_with_head(L2);
    cout << "L1链表" << endl;
    show_LinkList_with_head(L1);
    cout << "拆分+逆置链表" << endl;
    spilit_reverse_LinkList(L1, L2);
    cout << "L1链表" << endl;
    show_LinkList_with_head(L1);
    cout << "L2链表" << endl;
    show_LinkList_with_head(L2);
    return 0;
}

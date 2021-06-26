//
// Created by kaiven on 2021/6/26.
//

#include "2_3_10.h"

int main(){
    LinkList L1 = get_LinkList_with_head();
    cout << "分割之前的L1链表" << endl;
    show_LinkList_with_head(L1);
    // 进行分割
    LinkList L2 = spilit_LinkList(L1);

    cout << "分割之后的L1链表" << endl;
    show_LinkList_with_head(L1);
    cout << "分割之后的L2链表" << endl;
    show_LinkList_with_head(L2);
    return 0;
}
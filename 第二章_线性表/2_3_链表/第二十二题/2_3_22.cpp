//
// Created by kaiven on 2021/7/10.
//

#include "2_3_22.h"


int main(){
    int a1[6] = {1, 2, 4, 5, 7, 8};
    int a2[3] = {10, 9, 8};
    LinkList LA = arr2LinkList(a1, 6);
    LinkList LB = arr2LinkList(a2, 6);
    LB->next->next->next->next = LA->next->next->next;
    cout << "LA" << endl;
    show_LinkList_with_head(LA);
    cout << "LB" << endl;
    show_LinkList_with_head(LB);
    cout << "公共节点的地址和值" << endl;
    cout << comm_pos(LA,LB) << endl;
    cout << comm_pos(LA,LB)->data << endl;
    return 0;
}
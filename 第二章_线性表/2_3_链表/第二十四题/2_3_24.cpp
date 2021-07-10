//
// Created by kaiven on 2021/7/10.
//

#include "2_3_24.h"

int main(){
    int a1[6] = {1, 2, 4, 5, 7, 8};
    LinkList LA = arr2LinkList(a1, 6);
    cout << find_loop_link_list(LA) << endl;
    // 创造一个有环的链表
    LNode *p = LA;
    // 找到最后的一个元素
    while (p->next){
        p = p->next;
    }
    p->next = LA->next->next;
    cout << find_loop_link_list(LA) << endl;
    cout << find_loop_link_list(LA)->data << endl;
    return 0;
}
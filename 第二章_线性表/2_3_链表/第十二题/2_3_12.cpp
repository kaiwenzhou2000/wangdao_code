//
// Created by kaiven on 2021/6/27.
//

#include "2_3_12.h"

int main(){
    int a[10] = {7, 10, 10, 21, 30, 42, 42, 42, 51, 70};
    LinkList L = arr2LinkList(a, 10);
    cout << "L链表展示" << endl;
    show_LinkList_with_head(L);
    cout << "去掉重复的值之后的链表" << endl;
    delete_repeat(L);
    show_LinkList_with_head(L);
    return 0;
}
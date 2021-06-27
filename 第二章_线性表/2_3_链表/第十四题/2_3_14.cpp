//
// Created by kaiven on 2021/6/27.
//

#include "2_3_14.h"

int main(){
    int a[10] = {7, 10, 10, 21, 30, 42, 42, 42, 51, 70};
    LinkList L1 = arr2LinkList(a, 10);
    LinkList L2 = get_LinkList_with_head();
    cout << "L1展示" << endl;
    show_LinkList_with_head(L1);
    cout << "L2展示" << endl;
    show_LinkList_with_head(L2);
    cout << "合并之后的结果" << endl;
    show_LinkList_with_head(get_common_LinkList(L1, L2));
    return 0;
}
//
// Created by kaiven on 2021/6/22.
//

#include "2_2_7.h"

int main(){
    Sqlist L1;
    init_list(L1);
    sqlist_append(L1,1);
    sqlist_append(L1,2);
    sqlist_append(L1,3);
    Sqlist L2;
    init_list(L2);
    sqlist_append(L2,1);
    sqlist_append(L2,2);
    sqlist_append(L2,4);
    sqlist_append(L2,5);
    cout << "L1展示" << endl;
    show_list(L1);
    cout << "L2展示" << endl;
    show_list(L2);
    cout << "合并之后" << endl;
    show_list(merge_sqlist(L1, L2));
}
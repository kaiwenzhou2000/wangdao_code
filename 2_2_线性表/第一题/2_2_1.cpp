//
// Created by kaiven on 2021/6/21.
//

#include "2_2_1.h"
#include "iostream"

int main(){
    Sqlist L = make_list();
    cout << "======删除之前======" << endl;
    show_list(L);
    cout << "被删除的元素是" << find_min(L) << endl;
    cout << "======删除之后======" << endl;
    show_list(L);
    return 0;
}
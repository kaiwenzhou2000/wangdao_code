//
// Created by kaiven on 2021/6/21.
//

#include "2_2_3.h"

int main(){
    Sqlist L = make_list();
    cout << "======原始顺序表======" << endl;
    show_list(L);
    delete_all(L,99);
    cout << "======删除后的顺序表======" << endl;
    show_list(L);
    return 0;
}
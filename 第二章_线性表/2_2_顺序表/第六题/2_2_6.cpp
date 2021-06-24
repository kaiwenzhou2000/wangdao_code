//
// Created by kaiven on 2021/6/22.
//

#include "2_2_6.h"

int main(){
    Sqlist L = make_seq_list();
    cout << "======原始顺序表======" << endl;
    show_list(L);
    delete_repeat(L);
    cout << "======删除后的顺序表======" << endl;
    show_list(L);
    return 0;
}
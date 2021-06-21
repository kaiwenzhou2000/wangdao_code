//
// Created by kaiven on 2021/6/21.
//

#include "2_2_4.h"

int main(){
    Sqlist L = make_seq_list();
    cout << "======原始顺序表======" << endl;
    show_list(L);
    delete_range(L,1, 4);
    cout << "======删除后的顺序表======" << endl;
    show_list(L);
    return 0;
}
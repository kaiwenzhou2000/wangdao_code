//
// Created by kaiven on 2021/6/21.
//

#include "2_2_2.h"

int main(){
    Sqlist L = make_list();
    cout << "======原始顺序表======" << endl;
    show_list(L);
    reverse_list(L);
    cout << "======逆序顺序表======" << endl;
    show_list(L);
    return 0;
}
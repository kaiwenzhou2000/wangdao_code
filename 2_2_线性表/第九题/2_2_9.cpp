//
// Created by kaiven on 2021/6/22.
//

#include "2_2_9.h"

int main(){
    Sqlist L = make_seq_list();
    cout << "======原始顺序表======" << endl;
    show_list(L);
    find_exchange(L,3);
    cout << "======查找成功顺序表======" << endl;
    show_list(L);
    Sqlist L1 = make_seq_list();
    cout << "======原始顺序表======" << endl;
    show_list(L1);
    find_exchange(L1,100);
    cout << "======查找失败顺序表======" << endl;
    show_list(L1);
    return 0;
}
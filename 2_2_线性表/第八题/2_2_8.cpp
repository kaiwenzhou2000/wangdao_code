//
// Created by kaiven on 2021/6/22.
//

#include "2_2_8.h"

int main(){
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8};
    cout << "交换之前" << endl;
    show_arr(a, 8);
    cout << "将前面四个和后面四个进行交换，交换之后" << endl;
    exchange_sqlist(a, 4, 8);
    show_arr(a, 8);
    return 0;
}
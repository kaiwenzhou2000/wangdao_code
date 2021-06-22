//
// Created by kaiven on 2021/6/22.
//

#include "2_2_10.h"

int main(){
    int a[8] = {1, 2, 3, 4};
    int b[] = {5, 6, 7, 8};
    // 合并两个数组
    for (int i = 0; i < 4; ++i) {
        a[i+4] = b[i];
    }
    cout << "展示原有数组" << endl;
    show_arr(a, 8);
    cout << "反转之后的数组" << endl;
    converse_arr(a, 4, 8);
    show_arr(a, 8);
    return 0;
}
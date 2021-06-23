//
// Created by kaiven on 2021/6/23.
//

#include "2_2_13.h"

int main(){
    int a1[] = {-5, 3, 2, 3};
    int a2[] = {1, 2, 3};
    int a3[] = {-4, 1000, 2000, 4000};
    cout << "a1的结果是" <<find_min_num(a1, 4) << endl;
    cout << "a2的结果是" <<find_min_num(a2, 3) << endl;
    cout << "a3的结果是" <<find_min_num(a3, 4) << endl;
    cout << "王道给出的结果" << endl;
    cout << "a1的结果是" <<findMissMin(a1, 3) << endl;
    cout << "a2的结果是" <<findMissMin(a2, 4) << endl;
    cout << "a3的结果是" <<findMissMin(a3, 4) << endl;
    return 0;
}
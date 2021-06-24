//
// Created by kaiven on 2021/6/23.
//

#include "2_2_12.h"

int main(){
    int a1[8] = {0, 5, 5, 3, 5, 7, 5, 5};
    int a2[8] = {0, 5, 5, 3, 5, 1, 5, 7};
    cout << "a1的测试结果是" << find_main_element(a1, 8) << endl;
    cout << "a2的测试结果是" << find_main_element(a2, 8) << endl;

    cout << "王道代码a1的测试结果是" << Majority(a1, 8) << endl;
    cout << "王道代码a2的测试结果是" << Majority(a2, 8) << endl;
    return 0;
}
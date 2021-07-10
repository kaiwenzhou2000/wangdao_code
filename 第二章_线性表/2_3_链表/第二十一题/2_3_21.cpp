//
// Created by kaiven on 2021/7/10.
//

#include "2_3_21.h"


int main(){
    int a1[6] = {1, 2, 4, 5, 7, 8};
    LinkList LA = arr2LinkList(a1, 6);
    // 寻找倒数第一个元素
    find_element_reverse(LA, 1);
    // 寻找倒数第二个元素
    find_element_reverse(LA, 2);

    cout << "=========" << endl;
    search_k(LA, 1);
    search_k(LA, 2);
}
//
// Created by kaiven on 2021/7/7.
//

#include "2_3_16.h"

int main(){
    int a1[6] = {1, 2, 4, 5, 7, 8};
    int a2[9] = {0, 1, 2, 4, 5, 7, 8, 23, 45};
    int a3[9] = {0, 1, 2, 4, 5, 7, -10, 1, 45};
    LinkList LB = arr2LinkList(a1, 6);
    LinkList LA1 = arr2LinkList(a2, 9);
    LinkList LA2 = arr2LinkList(a3, 9);
    cout << is_common_subString(LA1, LB) << endl;
    cout << is_common_subString(LA2, LB) << endl;
    cout << pattern(LA1, LB) << endl;
    cout << pattern(LA2, LB) << endl;
}
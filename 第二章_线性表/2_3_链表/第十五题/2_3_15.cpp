//
// Created by kaiven on 2021/6/27.
//

#include "2_3_15.h"

int main(){
    int a1[6] = {1, 2, 4, 5, 7, 8};
    int a2[8] = {0, 2, 7, 8, 10, 12, 23, 45};
    LinkList LA = arr2LinkList(a1, 6);
    LinkList LB = arr2LinkList(a2, 6);
    cout << "LA" << endl;
    show_LinkList_with_head(LA);
    cout << "LB" << endl;
    show_LinkList_with_head(LB);
    cout << "交集" << endl;
    cross(LA, LB);
    show_LinkList_with_head(LA);
}
//
// Created by kaiven on 2021/7/9.
//

#include "2_3_17.h"

int main(){
    double_link_list LA;
    double_link_list_init(LA);
    double_link_list_push(LA,1);
    double_link_list_push(LA,2);
    double_link_list_push(LA,3);
    double_link_list_push(LA,4);
    double_link_list_push(LA,4);
    double_link_list_push(LA,3);
    double_link_list_push(LA,2);
    double_link_list_push(LA,1);
    cout << "展示双向循环链表" << endl;
    show_double_link_list(LA);
    cout << "是否对称" << endl;
    cout << is_symmetrical(LA) << endl;
    return 0;
}
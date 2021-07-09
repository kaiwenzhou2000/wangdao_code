//
// Created by kaiven on 2021/7/9.
//

#include "2_3_18.h"

int main(){
    LinkList LA;
    loop_link_list_init(LA);
    loop_link_list_push(LA,1);
    loop_link_list_push(LA,1);
    loop_link_list_push(LA,10);
    loop_link_list_push(LA,11);
    cout << "展示LA" << endl;
    show_loop_link_list(LA);

    LinkList LB;
    loop_link_list_init(LB);
    loop_link_list_push(LB,34);
    loop_link_list_push(LB,13);
    loop_link_list_push(LB,134);
    loop_link_list_push(LB,14);
    cout << "展示LB" << endl;
    show_loop_link_list(LB);

    cout << "合并LA和LB" << endl;
    merge_loop_link_list(LA, LB);
    show_loop_link_list(LA);
    return 0;
}
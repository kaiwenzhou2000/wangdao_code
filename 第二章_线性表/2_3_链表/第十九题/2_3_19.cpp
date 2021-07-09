//
// Created by kaiven on 2021/7/9.
//

#include "2_3_19.h"

int main(){
    LinkList LA;
    loop_link_list_init(LA);
    loop_link_list_push(LA,1);
    loop_link_list_push(LA,1);
    loop_link_list_push(LA,10);
    loop_link_list_push(LA,11);
    cout << "展示LA" << endl;
    show_loop_link_list(LA);
    find_min_loop(LA);
}
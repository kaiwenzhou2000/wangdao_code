//
// Created by kaiven on 2021/7/9.
//

#include "2_3_20.h"

int main(){
    double_link_list L;
    double_link_list_init(L);
    double_link_list_push(L,1);
    double_link_list_push(L,2);
    double_link_list_push(L,3);
    show_double_link_list(L);
    cout << Locate(L, 1) << endl;
    cout << Locate(L, 3) << endl;
    cout << Locate(L, 3) << endl;
    show_double_link_list(L);
    return 0;
}
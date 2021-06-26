//
// Created by kaiven on 2021/6/26.
//

#include "2_3_7.h"

int main(){
    LinkList L = get_LinkList_with_head_random();
    show_LinkList_with_head(L);
    delete_range(L, 0, 100);
    show_LinkList_with_head(L);
    return 0;
}
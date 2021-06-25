//
// Created by kaiven on 2021/6/25.
//

#include "2_3_6.h"

int main(){
    LinkList L = get_LinkList_with_head_random();
    show_LinkList_with_head(L);
    sort_LinkList(L);
    show_LinkList_with_head(L);
    return 0;
}
//
// Created by kaiven on 2021/8/16.
//

#include "../public.h"

/*
 * 将叶节点从左到右形成链表
 * 可以采用三种递归遍历方式中的任意一种
 * */

Link_list L;
void leaves2link_list(BiTree T){
    if (T == nullptr){
        return;
    }
    if (T->rchild == nullptr && T->lchild == nullptr){
        insert_link_list(L,T);
    }
    leaves2link_list(T->lchild);
    leaves2link_list(T->rchild);
}

int main(){
    BiTree T = get_tree();
    ini_link_list(L);
    leaves2link_list(T);
    show_link_list(L);
    return 0;
}
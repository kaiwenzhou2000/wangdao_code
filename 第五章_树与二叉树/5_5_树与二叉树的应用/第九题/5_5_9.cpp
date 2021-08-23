//
// Created by kaiven on 2021/8/23.
//

#include "../public.h"

/*
 * 求出二叉排序树中最小，和最大的关键字
 *
 * 算法思想
 *  左子树肯定小于右子树
 *  右子树肯定大于左子树
 * */
int find_min(BiTree T){
    BiTNode* p = T->lchild;
    BiTNode* pre = T;

    while (p != nullptr){
        p = p->lchild;
        pre = pre->lchild;
    }
    return pre->data;
}

int find_max(BiTree T){
    BiTNode* p = T->rchild;
    BiTNode* pre = T;

    while (p != nullptr){
        p = p->rchild;
        pre = pre->rchild;
    }
    return pre->data;
}

int main(){
    BiTree T = get_balance_tree();
    cout << find_min(T) << endl;
    cout << find_max(T) << endl;
    return 0;
}
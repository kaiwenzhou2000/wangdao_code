//
// Created by kaiven on 2021/8/14.
//

#include "../public.h"

/*
 * 左右子树交换
 *  算法思想
 *      其实就是遍历每一个节点，然后将孩子互相交换
 *      前中后序三种递归遍历方式都可以
 * */
void swap_tree(BiTree &p){
    if (p == nullptr){
        return;
    }
    swap_tree(p->lchild);
    swap_tree(p->rchild);
    BiTNode* temp = p->rchild;
    p->rchild = p->lchild;
    p->lchild = temp;
}


int main(){
    BiTree T = get_tree();
    cout << "交换前" << endl;
    show_pre_tree(T);
    swap_tree(T);
    cout << endl;
    cout << "交换后" << endl;
    show_pre_tree(T);
    return 0;
}
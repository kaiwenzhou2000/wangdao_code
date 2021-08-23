//
// Created by kaiven on 2021/8/23.
//

#include "../public.h"

/*
 * 在二叉排序树中从大到小输出比指定k大的值
 *
 * 二叉排序树通过中序遍历可以得到从小到大的顺序
 * 可以将大于k的用栈保存起来，然后再输出
 *
 * 王道书上是先遍历右子树，在遍历左子树
 * */
int stack[maxN];
int stack_top = -1;
void find_bigger(BiTree T, int k){
    if (T == nullptr){
        return;
    }

    find_bigger(T->lchild, k);
    if (T->data > k){
        stack[++stack_top] = T->data;
    }
    find_bigger(T->rchild, k);
}


int main(){
    BiTree T = get_balance_tree();
    find_bigger(T, 1);
    for (int i = 0; i <= stack_top; ++i) {
        cout << stack[i] << ' ';
    }
}
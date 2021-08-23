//
// Created by kaiven on 2021/8/22.
//

#include "../public.h"

/*
 * 判断是不是二叉排序树只要将其中序遍历
 * 看看之前的节点是不是小于之后的节点就可以了
 *
 * 返回0表示不是二叉排序树
 * 返回1表示是二叉排序树
 *
 * */

int predt = -1;     // 表示前面的值，设为1，表示是最小值
bool is_BST(BiTree T){
    int r_val, l_val;       // 右子树和左子树的是否为二叉排序树
    if (T == nullptr){
        return true;
    }

    l_val = is_BST(T->lchild);

    // 检查前面一个的值，是不是小于后面一个的值
    if (predt >= T->data || l_val == 0){
        // 这里有两个条件，分别是：
        // predt < T->data 表示前面的值大于等于后面的，这显然不是二叉排序树
        // l_val == 0 表示已经不是在上次的判断中已经可以确定不是二叉排序树了，所以退出
        return false;
    }

    // 如果能通过上面的检查，说明目前来说，这是一个二叉排序树，并跟新之前的值
    predt = T->data;
    r_val = is_BST(T->rchild);      // 判断右子树
    // 解释一下这个为什么要返回r_val
    // 其实，这个r_val的值只有两种可能性，要不是true，要不是false
    // true表示右子树是二叉排序树，false反之
    return r_val;                   // 返回右子树的结果
}



int main(){
    BiTree T = get_tree();
    BiTree T1 = get_balance_tree();
    cout << is_BST(T) << endl;
    predt = -1;
    cout << is_BST(T1) << endl;
    return 0;
}
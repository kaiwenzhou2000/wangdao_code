//
// Created by kaiven on 2021/8/22.
//

#include "../public.h"

/*
 * 判断是否为平衡二叉树
 * 平衡二叉树指的是左右子树的高度相差不超过1
 * 可以通过递归来实现
 * 这道题让我想起来了5.4.6两题可以对照起来看
 * balance表示二叉树是否平衡
 * h表示当前子树的高度
 *
 * 算法思想
 *  当T是空树d的时候，balance = 1, h = 1
 *  当T是叶子节点的时候，balance = 1，h = 1
 *  其他的时候：
 *      首先比较左右两边的高度，
 *      如果两边差小于等于1，说明此时高度是满足平衡的，
 *      但是这个时候还要注意，在之前是否发生过不平衡的情况，
 *      也就是左右子树的balance是都都为1
 *
 *
 * */
void is_balance(BiTree T, int &balance, int &h){
    // 分别表示左右子树的高度和是否平衡
    int b1_balance, b2_balance, b1_h, b2_h;
    if (T == nullptr){
        // 空树的情况
        balance = 1;
        h = 0;
    } else if (T->lchild == nullptr && T->rchild == nullptr){
        // 叶子节点的情况
        balance = 1;
        h = 1;
    } else{
        // 普通的情况
        is_balance(T->lchild, b1_balance, b1_h);
        is_balance(T->lchild, b2_balance, b2_h);

        // 看看左右子树谁的高度大，作为当前分支最高的高度
        if (b1_h+1 > b2_h){
            h = b1_h+1;
        } else{
            h = b2_h;
        }
        // 现在已经知道了左右子树的高度和balance的情况，现在看看当前的节点，满不满足balance的条件
        if (abs(b1_h-b2_h) <= 1){
            // 高度满足条件
            // 现在检查左右子树之前有没有balance
            balance = b1_balance&&b2_balance;
        } else{
            balance = 0;
        }

    }


}

int main(){
    BiTree T = get_balance_tree();
    int h = 0;
    int b = 0;
    is_balance(T, b, h);
    cout << b << endl;
    return 0;
}
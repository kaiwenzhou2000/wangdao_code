//
// Created by kaiven on 2021/8/16.
//

#include "../public.h"

/*
 * 判断两棵树是否相似
 * 相似的条件四
 *  两个数都是二叉树，或者都只有一个根节点
 *  左子树相似，右子树相似
 *
 *  算法思想
 *      这一看就是递归的题目
 *      递归的出口在于两个都是空树，或者两个都只有一个节点
 * */
bool is_similar(BiTree T1, BiTree T2){
    bool left_ans, right_ans;
    // 递归出口
    if (T1 == nullptr && T2 == nullptr){
        return true;
    }

    if (T1->lchild == nullptr && T1->rchild == nullptr && T2->lchild == nullptr && T2->rchild == nullptr){
        return true;
    }

    left_ans = is_similar(T1->lchild, T2->lchild);
    right_ans = is_similar(T1->rchild, T2->rchild);
    return left_ans&&right_ans;
}

int main(){
    BiTree T = get_tree();
    cout << is_similar(T, T) << endl;

    return 0;
}
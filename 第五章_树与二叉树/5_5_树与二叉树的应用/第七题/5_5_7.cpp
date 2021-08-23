//
// Created by kaiven on 2021/8/22.
//

#include "../public.h"
/*
 * 指定节点在二叉树中的层次
 * 其实这道题可以直接遍历，然后算层次的
 * 但是王道书上给的答案是用搜索来完成的
 * 我感觉这个方法效率要更加高一点
 * 下面我来实现以下
 *
 * */
int level_show = -1;
void search_BiTree(BiTree T, int target, int level){
    if (T == nullptr){
        return;
    }
    if (T->data == target){
        level_show = level;
        return;
    } else if (T->data > target){
        search_BiTree(T->lchild, target, level+1);
    } else{
        search_BiTree(T->rchild, target, level+1);
    }
}


int main(){
    BiTree T = get_balance_tree();
    search_BiTree(T, 3, 1);
    cout << level_show << endl;
    return 0;
}
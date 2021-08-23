//
// Created by kaiven on 2021/8/19.
//

#include "../public.h"

/*
 * 以孩子兄弟节点存储的
 * 递归计算树的深度
 *
 * 算法思想
 *  计算孩子兄弟表示法存放的树的高度
 *  左边是孩子，右边是兄弟
 *  也就是节点左边的高度就是二叉树的高度，
 *  右边是兄弟的个数
 *
 *  使用递归来完成计算
 *  这里采用的后序遍历，后序遍历实际上就是从下面，往上遍历，适合我们统计高度
 *
 *  递归出口是，遍历到根节点的时候
 *  每次都比较左右的高度，
 *  左边的高度是fc+1，因为要加上根节点
 *  右边的高度数ns，是右子树的高度
 *  比较那边的高度大，那个大返回哪一个
 *  知道遍历的空节点，返回0，表示此时的高度为0
 *
 *
 * */
int height_tree(CSTree T){
    if (T == nullptr){
        return 0;
    }

    int fc = height_tree(T->firstchild);        // 第一个节点孩子的高度
    int ns = height_tree(T->nextsibling);       // 兄弟节点的高度
    if (fc+1 > ns){
        return fc+1;
    } else{
        return ns;
    }
}
int main(){
    CSTree T = get_CSTree();
    cout << height_tree(T) << endl;
    return 0;
}

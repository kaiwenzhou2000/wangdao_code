//
// Created by kaiven on 2021/8/16.
//

#include "../public.h"

/*
 *  叶子节点带权路径长度之和，实际上就是考虑两个问题
 *      - 叶子节点确定
 *      - 叶子的层次
 *  之前我都是使用层次遍历，王道书上使用了先序遍历，我感觉这个方法好像更加简单
 *
 *  带权路径长度 = 叶子的权重 * 树的高度
 *
 *
 * */
#define weight 1        // 这里将权重设为定值1
int cnt = 0;            // 记录wpl
void wpl(BiTree T, int deep){
    // 递归出口
    if (T == nullptr){
        return;
    }

    // 说明现在的T是叶子节点
    if (T->rchild == nullptr && T->lchild == nullptr){
        cnt += deep*weight;
    }
    wpl(T->lchild, deep+1);
    wpl(T->rchild, deep+1);

}


int main(){
    BiTree T = get_tree();
    wpl(T, 1);
    cout << cnt << endl;
    return 0;
}
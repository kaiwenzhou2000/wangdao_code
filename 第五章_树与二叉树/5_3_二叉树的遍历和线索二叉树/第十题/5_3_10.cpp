//
// Created by kaiven on 2021/8/14.
//

#include "../public.h"

/*
 * 输出指定先序序列的值
 * T表示要查询的树
 * num表示要查询的第几个元素
 * current表示显示查询到的是第几个
 * ans表示最后输出的结果
 *
 * 用flag来保证初次访问
 * */
bool flag = true;
void find_pre(BiTNode *p, int num, int current, char &ans){
    if (p == nullptr){
        return;
    }
    if (num == current && flag){
        ans = p->data;
        flag = false;
    }
    current++;
    find_pre(p->lchild, num, current, ans);
    find_pre(p->rchild, num, current, ans);
}

/*
 * 王道书上的算法与我的有稍微的不同
 * 我这里来详细说明一下
 *  k表示查找元素的位置
 *  i是一个全局变量，表示现在查找到的地方
 *
 * */
int i = 1;
char preNode(BiTNode *p, int k){
    char ch;
    if (p == nullptr){
        // 递归出口
        // 表示此时是空节点
        return '#';
    }
    if (k == i){
        // 表示找到k号元素
        return p->data;
    }
    i++;        // 先序遍历，先visit
    ch = preNode(p->lchild, k);
    if (ch != '#'){
        // 说明此时已经找到第k的节点
        return ch;
    }
    // 说明第k个节点肯定还在右子树中
    ch = preNode(p->rchild, k);
    return ch;
}

int main(){
    BiTree T = get_tree();
    char ans;
    show_pre_tree(T);
    cout << endl;
    find_pre(T, 3, 1, ans);
    cout << ans << endl;
    cout << "王道方法" << endl;
    cout << preNode(T, 3) << endl;
    return 0;
}
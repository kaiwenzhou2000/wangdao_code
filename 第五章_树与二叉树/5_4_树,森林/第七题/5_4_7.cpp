//
// Created by kaiven on 2021/8/19.
//

#include "../public.h"

/*
 * 已知一棵树的层次遍历和每一个节点的度
 * 生成二叉链表
 * 算法思想
 *  level_tree 表示的是一个数的层序遍历
 *  degree 表示每个节点的度
 *  len 表示的数的节点个数
 *
 *
 * */
CSTree make_level_tree(int level_tree[], int degree[], int len){
    // 初始化的根节点
    CSTree T = (CSNode*) malloc(sizeof(CSNode));
    int level_tree_index = 0;
    T->data = level_tree[level_tree_index++];
    CSNode *p;  // 用来保存树
    CSNode *q;  // 用来分配内存空间

    // 使用数组来存放所有的节点，使得每个节点方便定位
    CSNode *level_tree_node[len];
    for (int i = 0; i < len; ++i) {
        q = (CSNode*) malloc(sizeof(CSNode));
        q->data = level_tree[i];
        level_tree_node[i] = q;
    }

    for (int i = 0; i < len; ++i) {

        // 首先将p指向现在要正在查看度的那个节点
        p = level_tree_node[i];
        level_tree_index = i+1;

        // 在度中，第一个肯定是节点指向上个节点的左指针（孩子节点），
        // 而后面的也是孩子节点，但是只能指向左指针的右边的节点，表示是兄弟关系
        if (degree[i]!=0){
            p->firstchild = level_tree_node[level_tree_index++];
            p = p->firstchild;
            for (int j = 2; j <= degree[i]; ++j) {
                p->nextsibling = level_tree_node[level_tree_index++];
                p = p->nextsibling;
            }
        }

    }
    return T;
}

// 先序遍历看看结果
void pre_tree(CSTree T){
    if (T == nullptr){
        return;
    }

    cout << T->data << ' ';
    pre_tree(T->firstchild);
    pre_tree(T->nextsibling);
}


int main(){
    int level_tree[] = {1, 2, 3, 4, 5, 6, 7};
    int degree[] = {3, 1, 1, 1, 0, 0, 0};
    CSTree T = make_level_tree(level_tree, degree, 7);
    pre_tree(T);
    return 0;
}
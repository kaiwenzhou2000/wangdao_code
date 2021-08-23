//
// Created by kaiven on 2021/8/22.
//

#ifndef WANGDAO_CODE_PUBLIC_H
#define WANGDAO_CODE_PUBLIC_H

#include "iostream"
#include "cstdlib"

using namespace std;

#define maxN 100

// 定义二叉树的数据结构
typedef struct BiTNode{
    int data;
    struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;


/*
 *  使用二叉链表生成二叉树
 *  使用先序和中序序列
 *  pre_order_array 表示先序序列
 *  pre_order_array 表示中序序列
 *  pre_head 表示目前先序的第一个元素的位置
 *  pre_rear 表示目前先序的最后一个元素的位置
 *  in_head 表示目前中序的第一个元素的位置
 *  in_rear 表示目前中序的最后一个元素的位置
 *
 * */
BiTree pre_in_create(int pre_order_array[], int in_order_array[], int pre_head, int pre_rear, int in_head, int in_rear){
    // 创建根，并根据先序序列先给根赋值
    BiTNode *root = (BiTNode*) malloc(sizeof(BiTNode));
    root->data = pre_order_array[pre_head];

    // 通过根的值，找到在后序序列的中根的位置
    int i;
    for (i = in_head; in_order_array[i] != root->data; i++);

    // 计算左子树和右子树的大小，若大小为1表明不需要再递归细分了
    int llen = i-in_head;       // 左子树的长度
    int rlen = in_rear-i;       // 右子树的长度

    if (llen > 0){
        root->lchild = pre_in_create(pre_order_array, in_order_array, pre_head+1, pre_head+llen, in_head, i-1);
    } else{
        root->lchild = nullptr;
    }

    if (rlen > 0){
        root->rchild = pre_in_create(pre_order_array, in_order_array, pre_head+llen+1, pre_rear, i+1, in_rear);
    } else{
        root->rchild = nullptr;
    }

    return root;
}

/*
 * 先序遍历
 * 递归
 * */
void show_pre_tree(BiTree T){
    if (!T){
        return;
    }

    cout << T->data << ' ';
    show_pre_tree(T->lchild);
    show_pre_tree(T->rchild);
    return;
}

/*
 * 中序遍历
 * 递归
 * */
void show_in_tree(BiTree T){
    if (!T){
        return;
    }

    show_pre_tree(T->lchild);
    cout << T->data << ' ';
    show_pre_tree(T->rchild);
    return;
}

/*
 * 后序遍历
 * 递归
 * */
void show_post_tree(BiTree T){
    if (!T){
        return;
    }

    show_pre_tree(T->lchild);
    show_pre_tree(T->rchild);
    cout << T->data << ' ';
    return;
}

/*
 * 获得一棵树
 * 定义如下
 *      char pre_order_array[9] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I'};
 *      char in_order_array[9] = {'B', 'C', 'A', 'E', 'D', 'G', 'H', 'F', 'I'};
 *
 * */
BiTree get_tree(){
    int pre_order_array[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int in_order_array[9] = {2, 3, 1, 5, 4, 7, 8, 6, 9};
    return pre_in_create(pre_order_array, in_order_array, 0, 8, 0, 8);
}

BiTree get_balance_tree(){
    int pre_order_array[3] = {2, 1, 3};
    int in_order_array[3] = {1, 2, 3};
    return pre_in_create(pre_order_array, in_order_array, 0, 2, 0, 2);
}

#endif //WANGDAO_CODE_PUBLIC_H

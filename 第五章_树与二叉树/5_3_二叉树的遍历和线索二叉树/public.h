//
// Created by kaiven on 2021/8/13.
//

#ifndef WANGDAO_CODE_PUBLIC_H
#define WANGDAO_CODE_PUBLIC_H


#include "iostream"
#include "cstdlib"

using namespace std;

#define maxN 100

// 定义二叉树的数据结构
typedef struct BiTNode{
    char data;
    struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;


/*=========================== 关于栈 ===========================*/

// 存放二叉树节点的栈
typedef struct stack{
    BiTNode *data[maxN];
    int top = -1;
}stack;


/*
 * 一下关于栈的操作不严谨
 * 只保证了一些必要的操作
 *
 * */

// 初始化栈
void ini_stack(stack &ss){
    ss.top = -1;
}

// 向栈中push元素
void push(stack &ss, BiTNode *node){
    ss.data[++ss.top] = node;
}

// 向栈外pop元素,并展示
void pop(stack &ss){
    cout << ss.data[ss.top]->data << ' ';
    ss.top--;
}

// 判断栈是不是空的
bool is_empty_stack(stack ss){
    if (ss.top == -1){
        return true;
    }
    return false;
}

// 获得栈顶的值
BiTNode* get_top(stack ss){
    return ss.data[ss.top];
}

/*=========================== 关于栈 ===========================end*/

/*=========================== 关于队列 ===========================*/

// 循环队列定义
typedef struct Quene{
    BiTNode *data[maxN];
    int head;
    int rear;
}Quene;

// 初始化
void ini_Quene(Quene &q){
    q.rear = 0;
    q.head = 0;
    for (int i = 0; i < maxN; ++i) {
        q.data[i] = nullptr;
    }
}

// 判断队列是不是空的
bool is_empty_quene(Quene q){
    if (q.head == q.rear){
        return true;
    }
    return false;
}

bool is_full_quene(Quene q){
    if (q.head == (q.rear+1)%maxN){
        return true;
    }
    return false;
}

// 入队
void enter_quene(Quene &q, BiTNode *node){
    if (!is_full_quene(q)){
        q.data[q.rear] = node;
        q.rear = (q.rear+1)%maxN;
    }
}


// 出队
BiTNode* exit_quene(Quene &q){
    BiTNode *p = q.data[q.head];
    if (!is_empty_quene(q)){
        q.head = (q.head+1)%maxN;
    }
    return p;
}

// 获得队尾元素
BiTNode* get_rear(Quene &q){
    return q.data[q.rear-1];
}


/*=========================== 关于队列 ===========================end*/

/*=========================== 关于链表 ===========================*/

typedef struct link_node{
    BiTNode *data;
    struct link_node* next;
}link_node, *Link_list;

void ini_link_list(Link_list &L){
    L = (link_node*) malloc(sizeof(link_node));
    L->next = nullptr;
}

void insert_link_list(Link_list &L, BiTNode *node){
    link_node *p, *pre, *data;
    data = (link_node*) malloc(sizeof(link_node));
    data->data = node;
    data->next = nullptr;
    p = L->next;
    pre = L;
    while (p){
        p = p->next;
        pre = pre->next;
    }

    pre->next = data;
}

void show_link_list(Link_list L){
    link_node *p;
    p = L->next;
    while (p){
        cout << p->data->data << ' ';
        p = p->next;
    }

    cout << endl;
}

/*=========================== 关于链表 ===========================end*/


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
BiTree pre_in_create(char pre_order_array[], char in_order_array[], int pre_head, int pre_rear, int in_head, int in_rear){
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
    char pre_order_array[9] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I'};
    char in_order_array[9] = {'B', 'C', 'A', 'E', 'D', 'G', 'H', 'F', 'I'};
    return pre_in_create(pre_order_array, in_order_array, 0, 8, 0, 8);
}

/*
 * 实现树的层序遍历
 *  算法思想
 *      首先先将根节点入队
 *      如果队列中只有只有一个元素，则将这个元素出队，然后将这元素的孩子节点入队
 *
 *
 * */
void show_level_tree(BiTree T){
    Quene q;
    ini_Quene(q);
    BiTNode *p = T;
    // 将根元素先进入队列
    enter_quene(q, p);
    while (!is_empty_quene(q)){
        p = exit_quene(q);
        // 打印需要输出的节点
        cout << p->data << ' ';
        // 如果有左右孩子，就入队列,先左，后右
        if (p->lchild){
            enter_quene(q, p->lchild);
        }
        if (p->rchild){
            enter_quene(q, p->rchild);
        }
    }
}


// 找公共祖先
void find_ancestor(BiTree T, char ch, BiTNode* ancestor[], int &ancestor_index){
    stack ss;
    ini_stack(ss);
    BiTNode *p = T;
    BiTNode *recent_visit = nullptr;
    while (!is_empty_stack(ss) || p){
        if (p){
            if (p->data == ch){
                // 找到节点
                cout << endl;
                for (int i = 0; i <= ss.top; ++i) {
                    ancestor[ancestor_index++] = ss.data[i];
                }
                cout << "======="<< endl;
                return;
            }
            push(ss,p);
            p = p->lchild;
        } else{
            p = get_top(ss);
            if (p->rchild && p->rchild != recent_visit){
                p = p->rchild;
            } else{
                pop(ss);
                recent_visit = p;
                p = nullptr;
            }
        }
    }
}

// 中序线索二叉树
typedef struct ThreadNode{
    char data;
    struct ThreadNode *lchild, *rchild;
    int ltag = 0, rtag = 0;     // 0 表示没有线索，1指向的线索
}ThreadNode, *ThreadTree;

// 创建线索二叉树，此时只是建立树，并没有线索化
ThreadTree pre_in_create_ThreadTree(char pre_order_array[], char in_order_array[], int pre_head, int pre_rear, int in_head, int in_rear){
    // 创建根，并根据先序序列先给根赋值
    ThreadNode *root = (ThreadNode*) malloc(sizeof(ThreadNode));
    root->data = pre_order_array[pre_head];

    // 通过根的值，找到在后序序列的中根的位置
    int i;
    for (i = in_head; in_order_array[i] != root->data; i++);

    // 计算左子树和右子树的大小，若大小为1表明不需要再递归细分了
    int llen = i-in_head;       // 左子树的长度
    int rlen = in_rear-i;       // 右子树的长度

    if (llen > 0){
        root->lchild = pre_in_create_ThreadTree(pre_order_array, in_order_array, pre_head+1, pre_head+llen, in_head, i-1);
    } else{
        root->lchild = nullptr;
    }

    if (rlen > 0){
        root->rchild = pre_in_create_ThreadTree(pre_order_array, in_order_array, pre_head+llen+1, pre_rear, i+1, in_rear);
    } else{
        root->rchild = nullptr;
    }

    return root;
}

// 获得一颗线索二叉树
// 线索化的过程在5.3.18中
ThreadTree get_tree_with_thread(){
    char pre_order_array[9] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I'};
    char in_order_array[9] = {'B', 'C', 'A', 'E', 'D', 'G', 'H', 'F', 'I'};
    return pre_in_create_ThreadTree(pre_order_array, in_order_array, 0, 8, 0, 8);
}

#endif //WANGDAO_CODE_PUBLIC_H

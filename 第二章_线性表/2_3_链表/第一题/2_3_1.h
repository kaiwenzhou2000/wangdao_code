//
// Created by kaiven on 2021/6/24.
//

#ifndef WANGDAO_CODE_2_3_1_H
#define WANGDAO_CODE_2_3_1_H

#include "iostream"
using namespace std;

typedef struct LNode{
    int data;
    struct LNode *next;
}LNode, *LinkList;

void LinkList_init_without_head(LinkList L){
    L = nullptr;
}


LinkList get_LinkList_without_head(){
    LinkList L;
    LinkList_init_without_head(L);
    LNode *p;               // p用来表示尾指针
    LNode *s;                   // s用来存放想要插入的值

    // 生成一个长度为10的链表
    // 第一个节点单独设置
    L = (LNode*) malloc(sizeof(LNode));
    L->data = 0;
    L->next = nullptr;
    p = L;
    for (int i = 1; i < 10; ++i) {
        s = (LNode*) malloc(sizeof(LNode));
        s->data = i;
        s->next = p->next;
        p->next = s;
        p = p->next;
    }
    return L;
}

bool show_link_list_without_head(LinkList L){
    // 链表判空操作
    if (L == nullptr){
        return false;
    }

    // 展示链表
    LNode *p = L;
    while(p){
        cout << p->data << ' ';
        p = p->next;
    }
    cout << endl;
    return true;
}

// 使用递归删除所有为x的节点
void delete_item_value_recursion(LNode *p, int e){
    // 递归的停止条件
    if (p == nullptr){
        return;
    }

    // 判断元素是否相等
    if(p->data == e){
        // 元素删除操作
        /*
         * 由于不知道前面的指针
         * 只能将原来后面的元素向前移动，
         * 再删除后面的哪一个节点
         * 这里有个bug，不能删除最后一个节点
         *
         * */
        LNode *s = p->next;
        p->data = s->data;
        p->next = s->next;
        free(s);
    } else{
        delete_item_value_recursion(p->next, e);
    }
}


/*
 * 王道书的做法
 * 我一开始以为会断链
 * 但是实测不会，书上说这是因为参数里面用的是引用
 * 这里用引用真的是太妙了
 * 我一开始看书上没有看懂，但是看了讲解之后恍然大悟
 * 总结出来一句话就是本层的L实际上是上一层的L->next
 * 所以是上一层next纸箱下一个节点，不会发生断链
 * 不同的同学可以去看看王道的习题课
 * 但是我建议又不会的再去看看
 * 以为我感觉太浪费时间了
 *
 * */
void Del_X_3(LinkList &L, int x){
    LNode *p;
    if (L == nullptr){
        return;
    }
    if (L->data == x){
        p = L;
        L = L->next;
        free(p);
        Del_X_3(L, x);
    } else{
        Del_X_3(L->next, x);
    }
}

// 删除第二个元素
void test(LinkList &L){
    free(L->next);
}

#endif //WANGDAO_CODE_2_3_1_H

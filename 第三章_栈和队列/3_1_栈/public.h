//
// Created by kaiven on 2021/7/12.
//

#ifndef WANGDAO_CODE_PUBLIC_H
#define WANGDAO_CODE_PUBLIC_H

#include "iostream"
#include "cstdlib"

#define maxN 100
using namespace std;

/*=========================char类型的链表====================================*/

/*
 * 链表节点定义
 * 节点中存放的数据类型是char
 *
 * */
typedef struct LNode_char{
    char data;
    struct LNode_char *next;
}LNode_char, *LinkList_char;

/*
 * 通过数组来生成链表（字符数组）
 * */
LinkList_char make_LinkList(char arr[], int len){
    LinkList_char head = (LNode_char*) malloc(sizeof(LNode_char));
    LNode_char* p = head;
    LNode_char* s;
    for (int i = 0; i < len; ++i) {
        s = (LNode_char*) malloc(sizeof(LNode_char));
        s->data = arr[i];
        p->next = s;
        p = s;
        p->next = nullptr;
    }
    return head;
}

/*
 * 展示单链表(字符)
 * */
void show_link_list(LinkList_char LA){
    LNode_char* p = LA->next;
    while (p){
        cout << p->data << ' ';
        p = p->next;
    }
    cout << endl;
}

/*
 * 计算带头结点单链表的长度（字符）
 * */
int link_list_len(LinkList_char LA){
    LNode_char *p = LA->next;
    int cnt = 0;
    while (p){
        cnt++;
        p = p->next;
    }
    return cnt;
}

/*=========================char类型的链表====================================end*/



/*=========================char类型的栈=========================================*/

/*
 * 结构定义
 * */
typedef struct stack_char{
    char data[maxN];
    int top;
}stack_char;

/*
 * 初始化
 * */
void stack_init(stack_char s){
    s.top = -1;
}


/*
 * 压栈
 * */
bool push(stack_char &s, char e){
    // 栈满
    if (s.top == maxN-1){
        return false;
    }

    // 压栈
    s.data[++s.top] = e;
    return true;
}

/*
 * 弹出栈
 * */
bool pop(stack_char &s, char &e){
    // 栈空
    if (s.top == -1){
        return false;
    }

    // 弹出站，并带回元素
    e = s.data[s.top--];
    return true;
}

/*=========================char类型的栈=========================================end*/

#endif //WANGDAO_CODE_PUBLIC_H

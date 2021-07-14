//
// Created by kaiven on 2021/7/13.
//

#ifndef WANGDAO_CODE_PUBLIC_H
#define WANGDAO_CODE_PUBLIC_H

#include "iostream"
#include "cstdlib"

#define maxN 100

using namespace std;

/*=========================栈====================================*/

// 栈结构定义
typedef struct SqStack{
    int data[maxN];
    int top;            // top永远指向的是栈顶元素
}SqStack;

// 栈的初始化
void SqStack_init(SqStack &S){
    S.top = -1;
}

// 弹出
bool pop(SqStack &S, int &e){
    // 查看栈内是否为空
    if (S.top == -1){
        return false;
    }

    // 弹出元素
    e = S.data[S.top--];
    return true;
}

// 插入
bool push(SqStack &S, int e){
    // 查看栈是不是满的
    if (S.top == maxN-1){
        return false;
    }

    S.data[++S.top] = e;
    return true;
}


// 判断栈是不是空的
bool is_empty_stack(SqStack S){
    if (S.top == -1){
        return true;
    }
    return false;
}

// 判断栈是不是满的
bool is_full_stack(SqStack S){
    if (S.top == maxN-1){
        return true;
    }
    return false;
}

/*=========================栈====================================end*/

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
void stack_init(stack_char &s){
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


/*=========================队列====================================*/

/*
 * 说明一下
 * 这个队列是一个循环队列
 * 牺牲一个存储元素，用来判断队列的状态
 * */

// 队列的结构定义
typedef struct SqQueue{
    int front;          // 头指针，用来出队
    int rear;           // 尾指针，用来入队
    int data[maxN];
}SqQueue;


// 队列的初始化
void SqQueue_init(SqQueue &Q){
    Q.front = 0;
    Q.rear = 0;
}

// 出队
bool deQueue(SqQueue &Q, int &res){
    // 判断队列是否是空
    if (Q.front == Q.rear){
        return false;
    }

    // 出队
    res = Q.data[Q.front];
    Q.front = (Q.front+1)%maxN;
    return true;
}


// 入队
bool enQueue(SqQueue &Q, int e){
    // 判断队列中是不是已满
    if (Q.front == (Q.rear+1)%maxN){
        return false;
    }

    // 入队
    Q.data[Q.rear] = e;
    Q.rear = (Q.rear+1)%maxN;
    return true;
}

void show_queue(SqQueue Q){
    int res;
    while (deQueue(Q, res)){
        cout << res << ' ';
    }
    cout << endl;
}

/*
 * 通过数组来初始化队列
 * */
bool make_queue(SqQueue &Q, int arr[], int len){
    if (len > maxN){
        return false;
    }

    SqQueue_init(Q);
    for (int i = 0; i < len; ++i) {
        enQueue(Q,arr[i]);
    }
    return true;
}

/*=========================队列====================================end*/

#endif //WANGDAO_CODE_PUBLIC_H

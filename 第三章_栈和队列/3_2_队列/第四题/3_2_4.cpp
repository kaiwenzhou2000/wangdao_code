//
// Created by kaiven on 2021/7/13.
//

#include "iostream"
#include "cstdlib"

using namespace std;

/*
 * 本题要求能够动态的分配空间，
 * 所以一定是链栈，
 * 要求大小只加不减，所以是循环链栈
 *
 * */

typedef struct LNode{
    int data;
    struct LNode* next;
}LNode;

typedef struct link_queue{
    LNode* front;
    LNode* rear;
}link_queue;

// 判空操作，只要两个指针指向同一个区域，
// 我就认为是满的，类似于之前的判断方法
bool is_empty_link_queue(link_queue Q){
    if (Q.rear == Q.front){
        return true;
    }
    return false;
}

// 判满操作，只要rear->next = front 我就认为是满的
bool is_full_link_queue(link_queue Q){
    if (Q.rear->next == Q.front){
        return true;
    }
    return false;
}


void link_queue_init(link_queue &Q){
    LNode* s = (LNode*) malloc(sizeof(LNode));
    s->data = -1;
    s->next = s;
    Q.front = s;
    Q.rear = s;
}

// 出队
bool delete_link_queue(link_queue &Q, int &res){
    // 判断链表是否为空
    if (is_empty_link_queue(Q)){
        return false;
    }

    res = Q.front->data;
    Q.front = Q.front->next;
}

// 入队
bool enter_link_queue(link_queue &Q, int e){
    // 需要增加空间
    if (is_full_link_queue(Q)){
        Q.rear->data = e;
        LNode* s = (LNode*) malloc(sizeof(LNode));
        s->next = Q.rear->next;
        Q.rear->next = s;
        Q.rear = s;
    } else{
        Q.rear->data = e;
        Q.rear = Q.rear->next;
    }
    return true;
}

int main(){
    link_queue Q;
    int res;
    link_queue_init(Q);
    enter_link_queue(Q,1);
    enter_link_queue(Q,2);
    enter_link_queue(Q,3);
    enter_link_queue(Q,4);
    delete_link_queue(Q,res);
    cout << res << endl;
    delete_link_queue(Q,res);
    cout << res << endl;
    delete_link_queue(Q,res);
    cout << res << endl;
    enter_link_queue(Q,100);
    delete_link_queue(Q,res);
    cout << res << endl;
    return 0;
}

//
// Created by kaiven on 2021/7/12.
//

#include "../public.h"

/*
 * 这道题我的思维局限在了递归上上面，导致没想明白
 * 实际上这是一个很简答的问题
 * 可以通过栈来完成
 *     1 先将链表中的一半元素放在栈中
 *     2 在一次弹出元素进行比较
 *
 * */
bool dc(LinkList_char LA){
    int len = link_list_len(LA);
    LNode_char* p = LA;

    // 关于栈的定义
    stack_char s;           // 存放链表中一半的元素
    stack_init(s);          // 初始化栈
    char temp;              // 保存pop出来的变量

    // 先前进到链表中间
    for (int i = 0; i < len / 2; ++i) {
        p = p->next;
        push(s, p->data);
    }

    if (len%2 != 0){
        // 说明是奇数
        p = p->next;
    }

    // 开始进行比较
    while (p->next){
        p = p->next;
        pop(s,temp);
        if (temp != p->data){
            // 发现有不相等的元素
            return false;
        }
    }
    return true;
}

int main(){
    LinkList_char LA = make_LinkList("XYZZYX", 6);
    show_link_list(LA);
    cout << dc(LA) << endl;
    return 0;
}


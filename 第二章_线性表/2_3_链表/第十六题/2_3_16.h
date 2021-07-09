//
// Created by kaiven on 2021/7/7.
//

#ifndef WANGDAO_CODE_2_3_16_H
#define WANGDAO_CODE_2_3_16_H

#include "../第十五题/2_3_15.h"

/*
 * 判断LB是不是LA的连续子串
 * 只需要不断的遍历LA，看看LA里面中的元素是不是跟LB相同就行了
 * */
bool is_common_subString(LinkList LA, LinkList LB){
    LNode *pa = LA->next;
    LNode *pb = LB->next;
    LNode *temp;
    while (pa != nullptr){
        temp = pa;
        while (pb != nullptr){
            if (pb->data == temp->data){
                pb = pb->next;
                temp = temp->next;
                if (pb == nullptr){
                    return true;
                }
            } else{
                break;
            }
        }
        pa = pa->next;
        pb = LB->next;
    }
    return false;
}

/*
 * 王道书上的写法更加简洁，
 * 主要是通过模式串的匹配来写的
 * 其让指向LA， LB的两个指针一起向后移动，
 * LA和LB的指针不要嵌套循环
 *
 * */
bool pattern(LinkList LA, LinkList LB){
    LNode *pa = LA->next;           // pa指向LA
    LNode *pa_pre = LA;             // 指向pa的之前的元素
    LNode *pb = LB->next;           // 指向LB
    while (pa && pb){
        if (pa->data == pb->data){
            pa = pa->next;
            pb = pb->next;
        } else{
            pa_pre = pa_pre->next;
            pa = pa_pre->next;
            pb = LB->next;
        }
    }

    // 循环之后判断pb有没有走到底，
    // 要是pb走到底，说明已经全部对比完毕
    if (pb == nullptr){
        return true;            // 是子列
    } else{
        return false;           // 不是子列
    }
}

#endif //WANGDAO_CODE_2_3_16_H

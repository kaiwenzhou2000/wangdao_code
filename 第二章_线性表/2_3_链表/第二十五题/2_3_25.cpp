//
// Created by kaiven on 2021/7/10.
//

#include "2_3_25.h"

int main(){
    int a1[6] = {1, 2, 4, 5, 7, 8};
    LinkList LA = arr2LinkList(a1, 6);
    show_LinkList_with_head(LA);
    remerge(LA);
    show_LinkList_with_head(LA);
    return 0;
}

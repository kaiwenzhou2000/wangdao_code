//
// Created by kaiven on 2021/8/13.
//

#include "../public.h"

int main(){
    char pre_order_array[9] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I'};
    char in_order_array[9] = {'B', 'C', 'A', 'E', 'D', 'G', 'H', 'F', 'I'};
    BiTree T = pre_in_create(pre_order_array, in_order_array, 0, 8, 0, 8);
    show_pre_tree(T);
    return 0;
}

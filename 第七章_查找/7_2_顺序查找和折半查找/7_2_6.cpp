//
// Created by kaiven on 2021/8/31.
//

#include "../public.h"

/*
 * 使用递归实现折半查找
 *
 * */
void half_search(int a[], int low, int height, int num){
    int mid;
    // 递归退出条件
    if (low > height){
        cout << "查找失败" << endl;
        return;
    }
    // 计算mid
    mid = (height+low)/2;
    if (a[mid] == num){
        // 成功找到
        cout << a[mid] << endl;
        return;
    } else if (a[mid] > num){
        // 中间的mid的值大于所要找的值
        // 需要减小mid的值，height要向左移动
        height = mid-1;
        half_search(a, low, height, num);
    } else{
        // 中间的mid的值小于所要找的值
        // 需要增大mid的值，height要向右移动
        low = mid+1;
        half_search(a, low, height, num);
    }
}


int main(){
    int a[7] = {-1, 0, 1, 2, 3, 4, 5};
    half_search(a, 1, 6, 3);
    half_search(a, 1, 6, 100);
    return 0;
}
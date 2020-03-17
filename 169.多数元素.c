/*
 * @lc app=leetcode.cn id=169 lang=c
 *
 * [169] 多数元素
 */

// @lc code=start


// int cmp(const void* a,const void* b) {
//     return *(int*)a - *(int*)b;
// }

// int majorityElement(int* a, int sz){
//     qsort(a,sz,sizeof(int),cmp);
//     return a[sz/2];
// }

int majorityElement(int* a,int sz) {
    int maj = -1;
    int cnt = 0;
    for (int i=0;i<sz;++i) {
        if (a[i] == maj)
            ++cnt;
        else if (--cnt < 0) {
            maj = a[i];
            cnt = 1;
        }
    }
    return maj;
}

// @lc code=end


#include <stdio.h>
#include <stdlib.h>


// int cmp(const void* a,const void* b) {
//     return *(int*)a - *(int*)b;
// }

// int majorityElement(int* a, int sz) {
//     qsort(a,sz,sizeof(int),cmp);
//     return a[sz/2];
// }

//Boyer-Moore ????
// int majorityElement(int* a, int sz) {
//     int cnt=1,maj=a[0];
//     for (int i=1;i<sz;++i) {
//         if (cnt==0) {
//             maj=a[i];
//         }
//         cnt += (maj==a[i]) ? 1 : -1;
//     }
//     return maj;
// }




int main() {
    //int nums[10] = {1,5,9,5,3,5,4,5,5,5};
    int nums[7]={2,2,1,1,1,2,2};
    int me=majorityElement(nums,7);
    

    printf("me=%d\n",me);

}
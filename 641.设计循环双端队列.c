/*
 * @lc app=leetcode.cn id=641 lang=c
 *
 * [641] 设计循环双端队列
 */

// @lc code=start
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//head: 首元素
//end: 尾元素的下一个
//size: 元素个数
typedef struct {
    int* data;
    int beg;
    int end;
    int size;
} MyCircularDeque;

/** Initialize your data structure here. Set the size of the deque to be k. */

/** Checks whether the circular deque is empty or not. */
bool myCircularDequeIsEmpty(MyCircularDeque* pcd) {
    return pcd->beg == pcd->end;
}

/** Checks whether the circular deque is full or not. */
bool myCircularDequeIsFull(MyCircularDeque* pcd) {
    return pcd->beg == ((pcd->end+1) % pcd->size);
}

MyCircularDeque* myCircularDequeCreate(int k) {
    MyCircularDeque* pcd=malloc((k+1)*sizeof(MyCircularDeque));
    pcd->data=malloc((k+1)*sizeof(int));
    pcd->beg=0;
    pcd->end=0;
    pcd->size=k+1;
    return pcd;
}

/** Adds an item at the front of Deque. Return true if the operation is successful. */
bool myCircularDequeInsertFront(MyCircularDeque* pcd, int value) {
    if (myCircularDequeIsFull(pcd)) return false;
    pcd->beg=(pcd->beg + pcd->size - 1) % pcd->size;
    *(pcd->data + pcd->beg)=value;
    return true;
}

/** Adds an item at the rear of Deque. Return true if the operation is successful. */
bool myCircularDequeInsertLast(MyCircularDeque* pcd, int value) {
    if (myCircularDequeIsFull(pcd)) return false;
    *(pcd->data + pcd->end)=value;
    pcd->end=(pcd->end + 1) % pcd->size;
    return true;
}

/** Deletes an item from the front of Deque. Return true if the operation is successful. */
bool myCircularDequeDeleteFront(MyCircularDeque* pcd) {
    if (myCircularDequeIsEmpty(pcd)) return false;
    pcd->beg=(++pcd->beg)% pcd->size;
    return true;
}

/** Deletes an item from the rear of Deque. Return true if the operation is successful. */
bool myCircularDequeDeleteLast(MyCircularDeque* pcd) {
    if (myCircularDequeIsEmpty(pcd)) return false;
    pcd->end=(pcd->end -1 + pcd->size)%pcd->size;
    return true;
}

/** Get the front item from the deque. */
int myCircularDequeGetFront(MyCircularDeque* pcd) {
    if (myCircularDequeIsEmpty(pcd)) return -1;
    return *(pcd->data + pcd->beg);
}

/** Get the last item from the deque. */
int myCircularDequeGetRear(MyCircularDeque* pcd) {
    if (myCircularDequeIsEmpty(pcd)) return -1;
    return *(pcd->data + (pcd->end-1+pcd->size) % pcd->size);
}


void myCircularDequeFree(MyCircularDeque* pcd) {
    free(pcd->data);
    free(pcd);
    return;
}

/**
 * Your MyCircularDeque struct will be instantiated and called as such:
 * MyCircularDeque* obj = myCircularDequeCreate(k);
 * bool param_1 = myCircularDequeInsertFront(obj, value);
 
 * bool param_2 = myCircularDequeInsertLast(obj, value);
 
 * bool param_3 = myCircularDequeDeleteFront(obj);
 
 * bool param_4 = myCircularDequeDeleteLast(obj);
 
 * int param_5 = myCircularDequeGetFront(obj);
 
 * int param_6 = myCircularDequeGetRear(obj);
 
 * bool param_7 = myCircularDequeIsEmpty(obj);
 
 * bool param_8 = myCircularDequeIsFull(obj);
 
 * myCircularDequeFree(obj);
*/
// @lc code=end


int main(void) {
    MyCircularDeque* pcd = myCircularDequeCreate(6);
    bool b1=myCircularDequeInsertFront(pcd,1);
    bool b2=myCircularDequeInsertFront(pcd,2);
    bool b3=myCircularDequeInsertLast(pcd,3);
    bool b4=myCircularDequeInsertLast(pcd,4);
    bool b5=myCircularDequeIsEmpty(pcd);
    bool b6=myCircularDequeIsFull(pcd);
    int a=myCircularDequeGetFront(pcd);
    int b=myCircularDequeGetRear(pcd);
    myCircularDequeFree(pcd);
    printf("b1=%d,b2=%d,b3=%d,b4=%d,b5=%d,b6=%d\n",b1,b2,b3,b4,b5,b6);
    printf("a=%d,b=%d\n",a,b);

    return 0;
}
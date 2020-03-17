/*
 * @lc app=leetcode.cn id=50 lang=c
 *
 * [50] Pow(x, n)
 */

// @lc code=start
#include <stdio.h>
#include <stdlib.h>

double func(double x,int n) {
    if (n==0) return 1;
    if (n==1) return x;
    //return (n&1 ? func(x*x,n/2)*x : func(x*x,n/2));
    if (n%2==0) return func(x*x,n/2);
    else return func(x*x,n/2)*x;
}

double myPow(double x, int n){
    // if (n == 0 || x == 1) return 1;
    // else if (n == 1) return x;
    // else if (n < 0) return 1 / myPow(x, -(n + 1)) / x;
    // else if (n % 2 == 0) return myPow(x * x, n / 2);
    // else return myPow(x * x, n / 2) * x;

    if (n<0) x=1/x;
    return func(x,n);
}


// @lc code=end

int main(void) {
    double x=1.2;
    int n=3;
    double rt=myPow(x,n);
    printf("rt=%f\n",rt);


    return 0;
}
#include <stdio.h>
// 喜欢在这里空行~
void swap1(int *a, int *b) // 通过指针交换两数，大大滴好
{                          // 函数通过指针指向a,b的地址交换a，b的值，对主函数中的变量会产生影响
    int t;
    t = *a;
    *a = *b;
    *b = t;
}
// 喜欢在函数之间空行~
void swap2(int c, int d) // 使用形参交换，达咩
{                        // 函数会交换c，d的值，对主函数中的变量不会产生影响
    int t;
    t = c;
    c = d;
    d = t;
}
// 喜欢在函数之间空行~
int main()
{
    int a, b;
    int c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    swap1(&a, &b); // 调用函数传递了a,b的地址
    swap2(c, d);   // 调用函数会将c，d的值传递给swap2函数中的c，d
    printf("%d %d %d %d", a, b, c, d);
    // 喜欢在return 0;前面空行
    return 0;
}
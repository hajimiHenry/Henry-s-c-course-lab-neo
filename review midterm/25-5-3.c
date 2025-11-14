#include <stdio.h>
#include <math.h>  // 声明了三角函数 sin

// 计算给定角度（单位：度）的正弦值，并输出到小数点后 2 位
// 题目要求：必须调用库函数 sin(x)，其中 x 必须是“弧度”而不是“角度”

#define PI 3.1415926  // 圆周率常量，用于角度与弧度的转换

int main(void) {
    int a;            // 用来存放输入的角度（整数，单位：度）

    // 读入一个整数角度 a
    if (scanf("%d", &a) != 1) {
        return 0;     // 读入失败时直接结束程序（简单处理即可）
    }

    // 将角度 a 换算成弧度：
    // 弧度 = 角度 × π / 180
    double radian = a * PI / 180.0;

    // 调用数学库函数 sin(x) 计算正弦值，此时参数必须是弧度
    double result = sin(radian);

    // 按要求输出 1 个实数，保留小数点后 2 位
    printf("%.2f", result);

    return 0;
}


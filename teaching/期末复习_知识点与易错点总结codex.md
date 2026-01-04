# C语言期末考试复习总结

> 本讲义根据 Henry 整个学期的学习材料整理，涵盖所有知识点、难点、易错点和考前建议。

---

## 一、核心知识点汇总

### 1. 基础输入输出

#### 1.1 scanf 格式控制符
| 格式符 | 类型 | 示例 |
|--------|------|------|
| `%d` | int | `scanf("%d", &n);` |
| `%lld` | long long | `scanf("%lld", &x);` |
| `%f` | float | `scanf("%f", &f);` |
| `%lf` | double | `scanf("%lf", &d);` |
| `%c` | char | `scanf(" %c", &c);` **注意前面的空格** |
| `%s` | 字符串 | `scanf("%s", str);` **不加&** |
| `%11s` | 限长字符串 | `scanf("%11s", phone);` 最多读11个字符 |

#### 1.2 printf 格式控制符
| 格式符 | 含义 | 示例 |
|--------|------|------|
| `%d` | 整数 | `printf("%d", n);` |
| `%4d` | 宽度4右对齐 | `printf("%4d", n);` |
| `%-4d` | 宽度4左对齐 | `printf("%-4d", n);` |
| `%.2f` | 保留2位小数 | `printf("%.2f", 3.14159);` → `3.14` |
| `%10s` | 宽度10右对齐 | `printf("%10s", name);` |

---

### 2. 数组

#### 2.1 一维数组
```c
int arr[100];          // 定义
arr[0] = 10;           // 访问第1个元素（下标从0开始）
arr[99]                // 最后一个元素
```

#### 2.2 二维数组
```c
int a[5][5];           // 5行5列
a[i][j]                // 第i行第j列
*(*(a+i)+j)            // 等价于 a[i][j]（指针写法）
```

#### 2.3 字符数组（字符串）
```c
char str[12];          // 可存11个字符 + '\0'
scanf("%11s", str);    // 读入字符串
printf("%s", str);     // 输出字符串
strlen(str)            // 字符串长度（不含'\0'）
```

---

### 3. 字符与ASCII码

#### 3.1 字符本质是整数
```c
'A' == 65
'a' == 97
'0' == 48
```

#### 3.2 字符数字转数值
```c
char ch = '7';
int digit = ch - '0';      // digit = 7

int n = 5;
char ch = n + '0';         // ch = '5'
```

#### 3.3 字母循环
```c
// 'a' 的前一个是 'z'
if (cur == 'a') cur = 'z';
else if (cur == 'A') cur = 'Z';
else cur--;
```

#### 3.4 判断字符类型
```c
// 判断是否为数字
if (ch >= '0' && ch <= '9')

// 判断是否为小写字母
if (ch >= 'a' && ch <= 'z')

// 判断是否为大写字母
if (ch >= 'A' && ch <= 'Z')
```

---

### 4. 函数

#### 4.1 函数声明与定义
```c
// 声明（放在main之前）
int add(int a, int b);

// 定义
int add(int a, int b) {
    return a + b;
}
```

#### 4.2 值传递 vs 指针传参

**值传递**：函数拿到的是副本，修改不影响原变量
```c
void change(int x) {
    x = 100;  // 只改了副本
}

int a = 5;
change(a);    // a 仍然是 5
```

**指针传参**：可以修改原变量
```c
void change(int *x) {
    *x = 100;  // 修改原变量
}

int a = 5;
change(&a);   // a 变成 100
```

#### 4.3 输出参数（需要返回多个值时）
```c
void getPrices(int S, int *p1, int *p2, int *p3) {
    if (S == 1) {
        *p1 = 8; *p2 = 12; *p3 = 20;
    } else {
        *p1 = 2; *p2 = 6; *p3 = 8;
    }
}

// 调用
int price1, price2, price3;
getPrices(1, &price1, &price2, &price3);
```

---

### 5. 指针

#### 5.1 基本概念
```c
int x = 10;
int *p = &x;     // p 指向 x

*p = 20;         // 通过指针修改 x 的值
printf("%d", x); // 输出 20
```

#### 5.2 数组与指针
```c
int arr[5] = {1, 2, 3, 4, 5};

arr          // 等价于 &arr[0]，首元素地址
arr + i      // 等价于 &arr[i]
*(arr + i)   // 等价于 arr[i]
```

#### 5.3 二维数组传参（重点难点）
```c
// 函数形参写法（两种等价）
void func(int (*a)[5]);    // 指向一行的指针
void func(int a[][5]);     // 等价写法

// 调用
int matrix[5][5];
func(matrix);              // matrix 退化为 &matrix[0]

// 函数内访问
a[i][j]           // 下标写法
*(*(a+i)+j)       // 指针写法（等价）
```

#### 5.4 为什么第二维必须写死
```c
// 编译器计算 a[i][j] 的地址需要知道每行多宽
// &a[i][j] = 首地址 + (i * 每行元素数 + j) * sizeof(int)
```

---

### 6. 结构体

#### 6.1 定义与使用
```c
typedef struct {
    char name[20];
    int score;
    int age;
} Student;

Student s;
s.score = 90;
strcpy(s.name, "Tom");
```

#### 6.2 结构体数组
```c
Student students[100];
students[0].score = 85;
scanf("%s", students[i].name);      // 数组名不加&
scanf("%d", &students[i].score);    // 普通变量加&
```

#### 6.3 结构体排序（冒泡排序）
```c
for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - 1 - i; j++) {
        if (students[j].score < students[j+1].score) {
            // 交换整个结构体
            Student tmp = students[j];
            students[j] = students[j+1];
            students[j+1] = tmp;
        }
    }
}
```

---

### 7. 常用算法

#### 7.1 求最大值
```c
int max = arr[0];
for (int i = 1; i < n; i++) {
    if (arr[i] > max) max = arr[i];
}
```

#### 7.2 求最小值
```c
int min = arr[0];
for (int i = 1; i < n; i++) {
    if (arr[i] < min) min = arr[i];
}
```

#### 7.3 素数判断
```c
int isPrime(int n) {
    if (n < 2) return 0;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}
```

#### 7.4 回文判断（双指针法）
```c
int isPalindrome(const char *s) {
    int left = 0, right = strlen(s) - 1;
    while (left < right) {
        if (s[left] != s[right]) return 0;
        left++;
        right--;
    }
    return 1;
}
```

#### 7.5 顺序去重
```c
int uniq[100], m = 0;

while (scanf("%d", &x) == 1 && x != -1) {
    int found = 0;
    for (int j = 0; j < m; j++) {
        if (uniq[j] == x) {
            found = 1;
            break;
        }
    }
    if (!found) {
        uniq[m++] = x;
    }
}
```

#### 7.6 子串查找（双循环法）
```c
char *search(char *s, char *t) {
    for (char *p = s; *p != '\0'; p++) {
        char *ps = p;
        char *pt = t;
        while (*ps != '\0' && *pt != '\0' && *ps == *pt) {
            ps++;
            pt++;
        }
        if (*pt == '\0') return p;  // 找到了
    }
    return NULL;  // 没找到
}
```

#### 7.7 阶梯计费
```c
// N 小时的费用，分三档：p1(前2h), p2(第3h), p3(超过3h)
int h1 = (N >= 2) ? 2 : N;
int h2 = (N >= 3) ? 1 : 0;
int h3 = (N > 3) ? (N - 3) : 0;
double total = h1 * p1 + h2 * p2 + h3 * p3;
```

---

## 二、重点难点详解

### 难点1：scanf 传参规则

| 类型 | 是否加 `&` | 示例 |
|------|-----------|------|
| `int`, `double` 等基本类型 | **加** | `scanf("%d", &x);` |
| 字符数组（字符串） | **不加** | `scanf("%s", str);` |
| 数组元素（int） | **加** | `scanf("%d", &arr[i]);` |
| 结构体成员（int） | **加** | `scanf("%d", &s.score);` |
| 结构体成员（数组） | **不加** | `scanf("%s", s.name);` |

### 难点2：%c 读字符要加空格
```c
int n;
char c;
scanf("%d", &n);
scanf(" %c", &c);   // %c 前的空格吃掉换行符
```

### 难点3：二维数组指针等价式
```c
// 假设 int a[5][5];
a[i][j]     ==  *(*(a+i)+j)
&a[i][j]    ==  *(a+i)+j
a[i]        ==  *(a+i)       // 第i行首地址
```

### 难点4：swap 函数必须传地址
```c
// 错误：不会真正交换
void swap(int a, int b) {
    int t = a; a = b; b = t;
}

// 正确：传地址
void swap(int *a, int *b) {
    int t = *a; *a = *b; *b = t;
}

// 调用
swap(&x, &y);
```

### 难点5：整数除法 vs 浮点除法
```c
125830 / 10000      // = 12（整数除法，小数丢失）
125830 / 10000.0    // = 12.583（浮点除法）
(double)125830 / 10000  // = 12.583（强制类型转换）
```

---

## 三、易错点清单

### 1. scanf 忘加 &
```c
// 错误
scanf("%d", x);      // 程序崩溃

// 正确
scanf("%d", &x);
```

### 2. 判断写成赋值
```c
// 错误
if (a = 1) { ... }   // 这是赋值，永远为真

// 正确
if (a == 1) { ... }
```

### 3. 变量未初始化
```c
// 错误
int sum;
sum += x;            // sum 是随机值

// 正确
int sum = 0;
sum += x;
```

### 4. 数组越界
```c
// 错误：手机号11位，只开了11格，没地方放'\0'
char phone[11];

// 正确：11位 + '\0' = 12
char phone[12];
```

### 5. 字符串数组传参加了&
```c
// 错误
scanf("%s", &str);

// 正确
scanf("%s", str);
```

### 6. 去重时边查边插
```c
// 错误：内层循环里插入会导致混乱
for (j = 0; j < m; j++) {
    if (arr[j] != x) arr[m++] = x;
}

// 正确：先查完，再决定是否插入
int found = 0;
for (j = 0; j < m; j++) {
    if (arr[j] == x) { found = 1; break; }
}
if (!found) arr[m++] = x;
```

### 7. 输出换行位置错误
```c
// 正确：每10个换行
for (int i = 0; i < m; i++) {
    printf("%4d", arr[i]);
    if ((i + 1) % 10 == 0) printf("\n");
}
// 最后一行不足10个，补换行
if (m % 10 != 0) printf("\n");
```

### 8. 结构体排序只换部分字段
```c
// 错误：只换了分数，名字没换
int tmp = p[j].score;
p[j].score = p[j+1].score;
p[j+1].score = tmp;

// 正确：换整个结构体
Player tmp = p[j];
p[j] = p[j+1];
p[j+1] = tmp;
```

### 9. void函数返回值
```c
// 错误
void func() {
    return 0;   // void函数不能返回值
}

// 正确
void func() {
    return;     // 可以直接return;或不写
}
```

### 10. 有效长度变量混乱
```c
// 错误：用多个变量表示同一个含义
int count1, count2;
for (j = 0; j < count1; j++) ...
arr[count2++] = x;

// 正确：只用一个变量
int m = 0;
for (j = 0; j < m; j++) ...
arr[m++] = x;
```

---

## 四、常用代码模板

### 模板1：读入n个数并求最大值
```c
int n, x, max;
scanf("%d", &n);
scanf("%d", &max);  // 第一个数作为初始最大值
for (int i = 1; i < n; i++) {
    scanf("%d", &x);
    if (x > max) max = x;
}
printf("%d\n", max);
```

### 模板2：读取手机号并处理
```c
char phones[10][12];  // 最多10个，每个11位+'\0'
int n;
scanf("%d", &n);
for (int i = 0; i < n; i++) {
    scanf("%11s", phones[i]);
}
```

### 模板3：结构体数组输入
```c
typedef struct {
    char name[20];
    int score;
} Student;

Student s[100];
int n;
scanf("%d", &n);
for (int i = 0; i < n; i++) {
    scanf("%19s%d", s[i].name, &s[i].score);
}
```

### 模板4：判断一组数是否全满足条件
```c
int all = 1;  // 先假设全满足
for (int i = 0; i < n; i++) {
    if (!check(arr[i])) {
        all = 0;  // 发现一个不满足就置0
        // 不要再把all改回1
    }
}
if (all) printf("YES\n");
else printf("NO\n");
```

### 模板5：找字典序最大的字符串
```c
char maxstr[50] = "";
for (int i = 0; i < n; i++) {
    char s[50];
    scanf("%49s", s);
    if (i == 0 || strcmp(s, maxstr) > 0) {
        strcpy(maxstr, s);
    }
}
printf("%s\n", maxstr);
```

### 模板6：二维数组找最大值位置
```c
int *pmax = &a[0][0];
for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
        if (a[i][j] > *pmax) {
            pmax = &a[i][j];
        }
    }
}
// pmax 现在指向最大值的位置
```

---

## 五、考前自检清单

做完题后，按以下清单检查：

- [ ] 所有 `scanf` 的 `%d` 都配了 `&` 吗？
- [ ] 所有 `scanf` 的 `%s` 都**没加** `&` 吗？
- [ ] `%c` 前面加了空格吗（如果前面有其他输入）？
- [ ] 数组开够大了吗？（字符串要多1给 `'\0'`）
- [ ] 所有变量都初始化了吗？
- [ ] 判断条件用的是 `==` 不是 `=` 吗？
- [ ] 循环边界对吗？（`< n` 还是 `<= n`）
- [ ] 输出格式符合题目要求吗？（宽度、小数位、换行）
- [ ] 浮点输出用的是 `/10000.0` 而不是 `/10000` 吗？

---

## 六、考试策略

1. **先通读全部题目**，标记有把握的先做
2. **审题要仔细**：看清输入格式、输出格式、下标从0还是1
3. **写完后用脑子跑一遍**：模拟一组简单输入，心算输出
4. **边界情况要测试**：N=0, N=1, N=最大值
5. **不会的题先跳过**，不要死磕一道题

---

## 七、你这学期踩过的主要坑（复盘）

1. **scanf传参**：好几次因为忘加`&`导致程序崩溃
2. **去重题**：用了两个变量表示有效长度，导致越界
3. **%c读字符**：没加空格，读到了换行符
4. **条件判断**：`if (j = 0)` 写成了赋值
5. **二维数组传参**：不理解 `int (*a)[5]` 的含义
6. **字符和数字**：忘了 `ch - '0'` 转换

这些坑你都已经踩过并解决了，考试时不要再犯！

---

**祝考试顺利！**

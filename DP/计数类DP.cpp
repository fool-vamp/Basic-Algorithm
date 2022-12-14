// acwing 整数划分 一个东西可以无限拿,就是完全背包问题
// 恰好等于j的方案数:
//     f[0][0]=1表示从1-0中选(一个数都不选),体积恰好为0的方案数为1.一个数不选,体积自然就是0,方案是存在的
//     f[0][1]表示从1-0中选(一个数都不选)，体积恰好为1的方案数为0 所以除了f[0][0]=1，其他都初始化为0
// 体积小于等于j的方案数：
//     f[0][j]表示从1-0中选(一个数都不选)，体积不超过j的方案数 应该全部初始化成0
#include <iostream>
using namespace std;
const int N = 1010, mod = 1e9 + 7;

int f[N][N];

int main()
{

    int n;
    scanf("%d", &n);

    //前i个数总和是0：f[i][0] = 1 (即只有1种方案，就是1个都不选)
    for (int i = 0; i <= n; i++)
        f[i][0] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int k = 0; k * i <= j; k++)
                f[i][j] = (f[i][j] + f[i - 1][j - k * i]) % mod;
        }
    }
    // 两重循环版本
    // f[i][j] = f[i - 1][j] + f[i - 1][j - i] + f[i - 1][j - 2i] + ...
    // f[i][j - 1] =           f[i - 1][j - i] + f[i - 1][j - 2i] + ...
    // 所以可以进行替换 f[i][j] = f[i - 1][j] + f[i][j - 1];
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= n; j++)
    //     {
    //         因为我们这里没有了k，f[i][j]已经包含不了f[i-1][j]这种情况(当k=0)
    //         因此，我们需要让f[i][j]=f[i-1][j]
    //         f[i][j] = f[i - 1][j] % mod; // 特殊 f[0][0] = 1
    //         if (j >= i)
    //             f[i][j] = (f[i - 1][j] + f[i][j - i]) % mod;
    //     }
    // }
    printf("%d", f[n][n]);

    return 0;
}
// for(int i = 1 ; i <= n ; i++)  和完全背包的优化方式一样
//     for(int j = i ; j <= n; j++)
//         f[j] = (f[j]+f[j-i]) % mod;
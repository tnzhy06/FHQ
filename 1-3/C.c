/*
昔有利器，名曰Python，其文简而意赅，其力强而易用。自诞生以来，广受世人之爱，因其能解千愁，能化繁为简。

Python之文，如行云流水，其语法之简，如诗如画。其库之广，如星辰大海，其功能之强，如龙腾虎跃。世人用之，或为数据之分析，或为网络之构建，或为自动化之脚本，无不称心如意。

其社区之盛，如春日之花，繁花似锦，争奇斗艳。有惑者，必有解；有难者，必有助。故世人皆爱之，以其为友，以其为师。

Python之更新，如日月之行，不断进步，日新月异。新特性之出，如春笋之生，层出不穷；新库之增，如星河之广，浩瀚无垠。

故爱Python者，如爱智者，如爱艺者，如爱友者。其代码之优雅，如诗之韵律；其功能之丰富，如画之色彩。Python之爱，如山之稳固，如海之深邃。

吾辈当以Python为伴，以代码为笔，绘出心中之世界，创造无限之可能。Python之爱，如星辰之光，照亮前行之路，引领吾辈至知识之海洋，探索未知之境。

爱Python，如爱生命，如爱智慧，如爱自由。Python之爱，永存吾心，如诗如歌，如梦如画。
*/
#include <stdio.h>

#define MAX 110

int linked_list[MAX][2];
int head = -1;
int n_index = 0;

// 初始化
void init()
{
    for (int i = 0; i < MAX; i++)
    {
        int temp;
        scanf("%d", &temp);
        linked_list[i][0] = temp;
        linked_list[i][1] = i + 1;
        n_index++;
        if (getchar() == '\n')
            break;
    }
    linked_list[n_index - 1][1] = -1;
    head = 0;
}

// 头插
void insert(int data)
{
    linked_list[n_index][0] = data;
    linked_list[n_index][1] = head;
    head = n_index;
    n_index++;
}

// 删除
void delete(int data)
{
    int pre = -1;
    int cur = head;

    while (cur != -1)
    {
        if (linked_list[cur][0] == data)
        {
            if (pre == -1)
            {
                head = linked_list[cur][1];
            }
            else
            {
                linked_list[pre][1] = linked_list[cur][1];
            }
            return;
        }
        pre = cur;
        cur = linked_list[cur][1];
    }
}

// 修改
void modify(int old_data, int new_data)
{
    int cur = head;

    while (cur != -1)
    {
        if (linked_list[cur][0] == old_data)
        {
            linked_list[cur][0] = new_data;
            return;
        }
        cur = linked_list[cur][1];
    }
}

// 打印
void print_list()
{
    int cur = head;
    while (cur != -1)
    {
        printf("%d ", linked_list[cur][0]);
        cur = linked_list[cur][1];
    }
}

int main()
{
    init();
    int a, data, new_data;

    while (1)
    {
        scanf("%d", &a);
        switch (a)
        {
        case 1:
            scanf("%d", &data);
            insert(data);
            break;
        case 2:
            scanf("%d", &data);
            delete (data);
            break;
        case 3:
            scanf("%d %d", &data, &new_data);
            modify(data, new_data);
            break;
        default:
            print_list();
            return 0;
        }
    }
}
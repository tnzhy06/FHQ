#include <stdio.h>
#include <string.h>

#define SIZE 10

struct people
{
    int x;
    int y;
    char id;
    int order;
};

// 初始化地图
void init(char map[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            map[i][j] = '0';
        }
    }
}

void printMap(char map[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            printf("%c", map[j][i]);
        }
        printf("\n");
    }
}

int main()
{
    struct people team[4];
    char actions[100];
    char map[SIZE][SIZE];

    for (int i = 0; i < 4; i++)
    {
        scanf("%d %d", &team[i].x, &team[i].y);
        team[i].y = -team[i].y;
        team[i].id = (i == 0) ? 'S' : '0' + i;
        team[i].order = 0;
    }

    scanf("%s", actions);

    init(map);

    int teamSize = 1;
    int len = strlen(actions);

    for (int i = 0; i < len; i++)
    {
        if (actions[i] == 'W')
        {
            team[0].y--;
        }
        else if (actions[i] == 'S')
        {
            team[0].y++;
        }
        else if (actions[i] == 'A')
        {
            team[0].x--;
        }
        else if (actions[i] == 'D')
        {
            team[0].x++;
        }

        // 检查是否遇到小伙伴
        for (int j = 1; j < 4; j++)
        {
            if (team[0].x == team[j].x && team[0].y == team[j].y && team[j].order == 0)
            {
                team[j].order = teamSize++;
            }
        }
    }

    // 逆推
    for (int j = 1; j < 4; j++)
    {

        int o = len - 1;
        if (team[j].order > 0)
        {
            team[j].x = team[0].x;
            team[j].y = team[0].y;
        }
        while (team[j].order > 0)
        {
            if (actions[o] == 'W')
            {
                team[j].y++;
            }
            else if (actions[o] == 'S')
            {
                team[j].y--;
            }
            else if (actions[o] == 'A')
            {
                team[j].x++;
            }
            else if (actions[o] == 'D')
            {
                team[j].x--;
            }
            team[j].order--;
            o--;
            // printf("%d\n", o);
        }
    }

    init(map);

    for (int i = 0; i < 4; i++)
    {
        map[team[i].x][team[i].y] = team[i].id;
    }

    printMap(map);

    return 0;
}
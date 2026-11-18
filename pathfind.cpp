#include "pathfind.h"
#include <queue>
#include <cstring>
#include<vector>
#include<algorithm>

// 四个方向：上下左右
const int dr[] = {-1, 1, 0, 0};
const int dc[] = {0, 0, -1, 1};

std::vector<Point> BFSFindPath(const Maze& maze, Point start, Point end)
{
    const int SIZE = 20;
    // 前驱记录，用来回溯路径；-1代表无父节点
    int prev[SIZE][SIZE];
    memset(prev, -1, sizeof(prev));
    bool visited[SIZE][SIZE] = {false};
    std::queue<Point> q;

    q.push(start);
    visited[start.r][start.c] = true;

    bool found = false;
    while (!q.empty())
    {
        Point cur = q.front();
        q.pop();

        if (cur.r == end.r && cur.c == end.c)
        {
            found = true;
            break;
        }

        for (int i = 0; i < 4; ++i)
        {
            int nr = cur.r + dr[i];
            int nc = cur.c + dc[i];
            Coordinate checkCoor{nc, nr}; // x=nc列，y=nr行！
            if (nr >= 0 && nr < SIZE && nc >=0 && nc < SIZE
                && !visited[nr][nc]
                && maze.get_tile_type(checkCoor) != WALL)
            {
                visited[nr][nc] = true;
                prev[nr][nc] = i;
                q.push(Point(nr, nc));
            }
        }

    }

    // 回溯，从终点往起点倒推
    std::vector<Point> path;
    if (!found) return path;

    Point p = end;
    // 先把终点放进路径
    path.push_back(p);
    while (!(p.r == start.r && p.c == start.c))
    {
        int dir = prev[p.r][p.c];
        p.r -= dr[dir];
        p.c -= dc[dir];
        path.push_back(p);
    }
    // 此时path是【终点 → 起点】，反转变成【起点 → 终点】
    std::reverse(path.begin(), path.end());
    return path;
}

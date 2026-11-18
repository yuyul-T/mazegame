#ifndef BFS_H
#define BFS_H

#include <vector>
#include "maze.h"

//坐标结构体，和你Coordinate保持一致
struct Point
{
    int r;
    int c;
    Point(int r_ = 0, int c_ = 0) : r(r_), c(c_) {}
};

//从start到end搜索，返回路径（从起点到终点），无路则返回空vector
std::vector<Point> BFSFindPath(const Maze& maze, Point start, Point end);

#endif

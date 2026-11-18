#include <raylib.h>
#include <format>
#include "maze.h"
#include "player.h"
#include"pathfind.h"
bool showPath=false;
std::vector<Point> path;

int main(){
    InitWindow(1280, 1280, "HBUT 程序设计综合实践项目：maze");
    Maze maze("../assets/maze0.txt");
    Player player(maze);

    while (!WindowShouldClose()){

        player.update();

        if(IsKeyPressed(KEY_SPACE))
        {
            showPath=!showPath;
            if(showPath)
            {
                Coordinate playerPos=player.get_curr_coord();
                Coordinate endPos=maze.get_end_coord();
                path=BFSFindPath(maze,Point(playerPos.y,playerPos.x),Point(endPos.y,endPos.x));
            }
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);

        maze.draw();
        player.draw();

        //绘制路径：画小圆点标记路径
        if(showPath)
        {
            for(auto& pt:path)
            {
                float px=pt.c*TILE_WIDTH+TILE_WIDTH/2.0f;
                float py=pt.r*TILE_HEIGHT+TILE_HEIGHT/2.0f;
                DrawCircle(px,py,12,GREEN);
            }
        }
            
        DrawText(std::format("FPS: {}", GetFPS()).c_str(), 5, 5, 20, WHITE);
        DrawText("SPACE:Toggle Path",5,30,20,BLACK);
        //DrawText("Use arrow keys to move", 1300, 600, 24, BLACK);
        EndDrawing();
    }
    CloseWindow(); 
    return 0;
}
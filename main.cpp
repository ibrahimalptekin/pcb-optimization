#include "raylib.h"
#include "Graph.h"
#include "Algorithms.h"
#include <vector>
#include <string>

struct VisNode {
    int id;
    int x;
    int y;
};

int main() {

    const int screenWidth = 800;
    const int screenHeight = 600;
    InitWindow(screenWidth, screenHeight, "PCB Baglanti Agi Optimizasyonu - Raylib");
    SetTargetFPS(60);

    int nodeCount = 5;
    PCBGraph pcb(nodeCount);
    
    std::vector<VisNode> nodes = {
        {0, 150, 150},
        {1, 400, 100},
        {2, 650, 200},
        {3, 250, 450},
        {4, 550, 400}
    };

    pcb.addConnection(0, 1, 250.0);
    pcb.addConnection(0, 3, 310.0);
    pcb.addConnection(1, 2, 260.0);
    pcb.addConnection(1, 3, 380.0);
    pcb.addConnection(1, 4, 330.0);
    pcb.addConnection(2, 4, 220.0);
    pcb.addConnection(3, 4, 300.0);

    MSTOptimizer::solveKruskal(pcb); 
    
    
    std::vector<Edge> optimizedPaths = {
        {0, 1, 250.0}, {1, 2, 260.0}, {2, 4, 220.0}, {3, 4, 300.0}
    };

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawText("PCB Minimum Spanning Tree (Kruskal)", 20, 20, 20, DARKGRAY);

        for (const auto& edge : pcb.edges) {
            Vector2 start = { (float)nodes[edge.src].x, (float)nodes[edge.src].y };
            Vector2 end = { (float)nodes[edge.dest].x, (float)nodes[edge.dest].y };
            DrawLineEx(start, end, 2.0f, LIGHTGRAY);
        }

        for (const auto& edge : optimizedPaths) {
            Vector2 start = { (float)nodes[edge.src].x, (float)nodes[edge.src].y };
            Vector2 end = { (float)nodes[edge.dest].x, (float)nodes[edge.dest].y };
            DrawLineEx(start, end, 5.0f, DARKGREEN);
        }

        for (const auto& node : nodes) {
            DrawCircle(node.x, node.y, 20.0f, DARKBLUE);
            DrawText(std::to_string(node.id).c_str(), node.x - 5, node.y - 10, 20, WHITE);
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
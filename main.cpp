#include "raylib.h"
#include "Graph.h"
#include "Algorithms.h"
#include <string>

int main() {
    const int screenWidth = 1024;
    const int screenHeight = 768;
    InitWindow(screenWidth, screenHeight, "PCB Optimizasyonu - Etkilesimli Arayuz");
    SetTargetFPS(60);

    PCBGraph pcb;
    std::vector<Edge> mstEdges;
    double totalCost = 0.0;
    bool isOptimized = false;

    while (!WindowShouldClose()) {
        
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            Vector2 mousePos = GetMousePosition();
            if (mousePos.y > 70) {
                pcb.addNode(mousePos.x, mousePos.y);
                isOptimized = false; 
                mstEdges.clear();
            }
        }

        if (IsKeyPressed(KEY_SPACE) && pcb.nodes.size() > 1) {
            mstEdges = MSTOptimizer::solveKruskal(pcb, totalCost);
            isOptimized = true;
        }

        if (IsKeyPressed(KEY_R)) {
            pcb.clear();
            mstEdges.clear();
            totalCost = 0.0;
            isOptimized = false;
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawRectangle(0, 0, screenWidth, 60, DARKGRAY);
        DrawText("Fare Sol Tik: Bilesen Ekle  |  SPACE: Optimizasyonu Calistir  |  R: Sifirla", 20, 20, 20, LIGHTGRAY);

        for (const auto& edge : pcb.edges) {
            Vector2 start = { pcb.nodes[edge.src].x, pcb.nodes[edge.src].y };
            Vector2 end = { pcb.nodes[edge.dest].x, pcb.nodes[edge.dest].y };
            DrawLineEx(start, end, 1.0f, LIGHTGRAY);
        }

        if (isOptimized) {
            for (const auto& edge : mstEdges) {
                Vector2 start = { pcb.nodes[edge.src].x, pcb.nodes[edge.src].y };
                Vector2 end = { pcb.nodes[edge.dest].x, pcb.nodes[edge.dest].y };
                DrawLineEx(start, end, 4.0f, DARKGREEN);
            }
            
            std::string costText = "Toplam Bakir Maliyeti: " + std::to_string((int)totalCost) + " birim";
            DrawText(costText.c_str(), 20, screenHeight - 40, 24, MAROON);
        }

        for (const auto& node : pcb.nodes) {
            DrawCircle(node.x, node.y, 16.0f, DARKBLUE);
            DrawText(std::to_string(node.id).c_str(), node.x - 5, node.y - 10, 20, WHITE);
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
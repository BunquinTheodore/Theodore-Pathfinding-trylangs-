#include <iostream>
#include <vector>
#include "graph.h"
#include "Solver.h"
#include <fstream>
#include <limits>

using namespace std;

void displayAllMazes(const vector<Graph>& mazes);
int getUserChoice(const string& prompt, int maxChoice);
void loadMaze(Graph& maze);

int main() {
    vector<Graph> mazes;

    Graph maze("../maze1.txt");
    mazes.push_back(maze);

    displayAllMazes(mazes);

    int mazeChoice = getUserChoice("Choose a maze (enter 1): ", mazes.size());
    mazeChoice--;

    int algorithmChoice = getUserChoice("Choose an algorithm:\n1. Depth-First Search (DFS)\nEnter choice: ", 1);

    if (algorithmChoice == 1) {
        Graph maze1 = mazes[mazeChoice];
        cout << maze.Start << endl;
        cout << maze.End << endl;

        vector<string> path = DepthFirstSearch(maze1);
        cout << "Path found by DFS:" << endl;
        for(int i = 0; i < path.size(); i++)
        {
            cout << path[i] << " ";
        }
        cout << endl;
    } else {
        cout << "Invalid choice!" << endl;
    }

    return 0;
}

void displayAllMazes(const vector<Graph>& mazes) {
    cout << "Loaded Mazes:" << endl;
    for (vector<Graph>::size_type i = 0; i < mazes.size(); ++i) {
        cout << i + 1 << ". Maze" << endl;
    }
    cout << endl;
}


int getUserChoice(const string& prompt, int maxChoice) {
    int choice;
    while (true) {
        cout << prompt;
        cin >> choice;
        if (choice >= 1 && choice <= maxChoice) {
            break;
        } else {
            cout << "Invalid choice. Please enter a valid number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    return choice;
}

void loadMaze(Graph& maze) {
    ifstream file("maze1.txt");
    if (!file.is_open()) {
        cerr << "Error opening maze data file." << endl;
        return;
    }

    string line;
    string mazeData;
    while (getline(file, line)) {
        mazeData += line + "\n";
    }

    maze.LoadGraph(mazeData);
}
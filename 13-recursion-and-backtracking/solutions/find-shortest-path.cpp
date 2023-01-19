#include <iostream>

using namespace std;

const int N = 5;  // size of the maze

int maze[N][N] = {{0, 0, 0, 0, 1},
                  {0, 1, 1, 0, 1},
                  {0, 0, 0, 0, 0},
                  {0, 1, 1, 1, 1},
                  {0, 0, 0, 0, 1}};

int destinationX = 0;
int destinationY = 4;
int shortestPathLength =
    N * N;  // initialize the shortest path length to a large number

// function to check if a point is within the bounds of the maze and is a free
// cell
bool isValid(int x, int y) {
  return x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 0;
}

// function to find the shortest path through the maze
void findShortestPath(int x, int y, int pathLength, int path[][N]) {
  // check if the current position is the destination
  if (x == destinationX && y == destinationY) {
    // update the shortest path length if the current path is shorter
    if (pathLength < shortestPathLength) {
      shortestPathLength = pathLength;
    }
    return;
  }

  // check if the current position is a wall or has already been visited
  if (!isValid(x, y) || path[x][y] == 1) {
    return;
  }

  // mark the current position as visited
  path[x][y] = 1;

  // try moving to the next position in each direction
  findShortestPath(x - 1, y, pathLength + 1, path);  // try moving left
  findShortestPath(x + 1, y, pathLength + 1, path);  // try moving right
  findShortestPath(x, y - 1, pathLength + 1, path);  // try moving up
  findShortestPath(x, y + 1, pathLength + 1, path);  // try moving down

  // backtrack and remove the current position from the path
  path[x][y] = 0;
}

int main() {
  int path[N][N] = {0};  // 2D array to store the path
  findShortestPath(0, 0, 0, path);
  cout << "The shortest path length is: " << shortestPathLength << endl;
  return 0;
}

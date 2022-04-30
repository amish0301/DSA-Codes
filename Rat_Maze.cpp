#include <bits/stdc++.h>
using namespace std;

bool isSafe(int x, int y, int n, vector<vector<int>> &visited, vector<vector<int>> &maze)
{
    /*
    we have to check 3 condition:

    1. Our x,y are lying in the maze matrix
    2. Our Maze coordinate must be 1 --> to move ahead
    3. Our Visited must be intially 0(unmarked)

    */

    if ((x >= 0 && x < n) && (y >= 0 && y < n) && maze[x][y] == 1 && visited[x][y] == 0)
        return true;

    return false;
}

void solve(vector<vector<int>> &maze, int n, vector<vector<int>> &visited, vector<string> &ans, string path, int &x, int &y)
{
    // base case
    if (x == n - 1 && y == n - 1)
    {
        ans.push_back(path);
        return;
    }

    // here we reached means our visited marked must be 1
    visited[x][y] = 1;

    // I have 4 Choices to move -> D,L,R,U

    // Down
    int newx = x + 1; // when we goes down our x index will Increase and y index will be same
    int newy = y;

    // check if we safe to move or not
    if (isSafe(newx, newy, n, visited, maze))
    {
        path.push_back('D');
        solve(maze, n, visited, ans, path, newx, newy);
        path.pop_back();
    }

    // Left
    int newx = x; // when we goes left our x index will be same and y intdex will be decrease
    int newy = y - 1;

    if (isSafe(newx, newy, n, visited, maze))
    {
        path.push_back('L');
        solve(maze, n, visited, ans, path, newx, newy);
        path.pop_back();
    }

    // Right
    int newx = x; // when we goes Right our x index will be same and y intdex will be Increase
    int newy = y + 1;

    if (isSafe(newx, newy, n, visited, maze))
    {
        path.push_back('R');
        solve(maze, n, visited, ans, path, newx, newy);
        path.pop_back();
    }

    // Up
    int newx = x - 1; // when we goes Up our x index will be Decrease and y intdex will be Same
    int newy = y;

    if (isSafe(newx, newy, n, visited, maze))
    {
        path.push_back('U');
        solve(maze, n, visited, ans, path, newx, newy);
        path.pop_back();
    }
    visited[x][y] = 0; // make sure to clear the marked (1) before return the function
}

vector<string> rat_maze(vector<vector<int>> &maze, int n)
{
    int srcx = 0, srcy = 0; // initialise starting index
    vector<string> ans;
    vector<vector<int>> visited = maze;

    // if your Starting Index is 0 then you can't move anywhere
    if (maze[0][0] == 0)
        return ans;

    // initialise visited vector with 0
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            visited[i][j] = 0;
        }
    }

    string path = ""; // taking string to store the path
    solve(maze, n, visited, ans, path, srcx, srcy);
    sort(ans.begin(), ans.end());
    return ans;
}

int main()
{
    int n;
    vector<vector<int>> maze = {{1, 0, 0, 0}, {1, 1, 0, 1}, {1, 1, 0, 0}, {0, 1, 1, 1}};
    rat_maze(maze, n);

    return 0;
}
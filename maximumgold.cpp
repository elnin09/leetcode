/*
In a gold mine grid of size m * n, each cell in this mine has an integer representing the amount of gold in that cell, 0 if it is empty.

Return the maximum amount of gold you can collect under the conditions:

Every time you are located in a cell you will collect all the gold in that cell.
From your position you can walk one step to the left, right, up or down.
You can't visit the same cell more than once.
Never visit a cell with 0 gold.
You can start and stop collecting gold from any position in the grid that has some gold.
*/

/*
Variation 
what if we can only start from first column and only move (right,rightup,righdown)
*/

using namespace std;
int maxnumber(int a, int b)
{
    if (a > b)
        return a;
    return b;
}

int maxCoinsHelper(vector<vector<int> > &mines, vector<vector<int> > &maxcoins, vector<vector<int> > &visited, int i, int j)
{
    if (i >= mines.size() || j >= mines[0].size() || i < 0 || j < 0 || mines[i][j] == 0 || visited[i][j] == 1)
    {
        return 0;
    }

    visited[i][j] = 1; 
    // mark it visited so if we encounter a loop here in this path only because a loop is possible
    int right = maxCoinsHelper(mines, maxcoins, visited, i, j + 1);
    int down = maxCoinsHelper(mines, maxcoins, visited, i + 1, j);
    int up = maxCoinsHelper(mines, maxcoins, visited, i - 1, j);
    int left = maxCoinsHelper(mines, maxcoins, visited, i, j - 1);

    visited[i][j] = 0; 
    //mark it unvisited because we may get to this node from a different path
    return mines[i][j] + maxnumber(maxnumber(right, left), maxnumber(up, down));
}

int getMaximumGold(vector<vector<int> > &grids)
{
    vector<vector<int> > mines = grids;
    int m = mines.size();
    if (m == 0)
        return 0;
    int n = mines[0].size();

    vector<vector<int> > maxcoins(m, vector<int>(n, -1));

    int retval = INT_MIN;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            vector<vector<int> > visited(m, vector<int>(n, 0));
            int currentval = maxCoinsHelper(mines, maxcoins, visited, i, j);
            if (currentval > retval)
            {
                retval = currentval;
            }
        }
    }
    return retval;

}

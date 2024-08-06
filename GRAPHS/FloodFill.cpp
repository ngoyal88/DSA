#include <iostream>
#include <vector>
using namespace std;

bool isSafe(int nrow, int ncol, int n, int m, vector<vector<int>> image, vector<vector<int>> ans, int newColor, int initial)
{
    if ((nrow >= 0 && nrow < n) && (ncol >= 0 && ncol < m) && (image[nrow][ncol] == initial && ans[nrow][ncol] != newColor))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void dfs(int row, int col, vector<vector<int>> &image, vector<vector<int>> &ans, int newColor, int delRow[], int delCol[], int initial)
{
    ans[row][col] = newColor;
    int n = image.size();
    int m = image[0].size();
    for (int i = 0; i < 4; i++)
    {
        int nrow = row + delRow[i];
        int ncol = col + delCol[i];
        if (isSafe(nrow, ncol, n, m, image, ans, newColor, initial))
        {
           dfs(nrow,ncol,image,ans,newColor,delRow,delCol,initial);
        }
    }
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
{
    int initial = image[sr][sc];
    vector<vector<int>> ans = image;
    int delRow[] = {-1, 0, 1, 0};
    int delCol[] = {0, 1, 0, -1};
    dfs(sr,sc,image,ans,newColor,delRow,delCol,initial);
    return ans;
}

//{ Driver Code Starts.
int main(){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		
		vector<vector<int>> ans = floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	return 0;
}
// } Driver Code Ends
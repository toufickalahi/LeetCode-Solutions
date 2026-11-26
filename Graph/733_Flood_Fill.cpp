// Problem: Flood Fill
// LeetCode: 733
// Difficulty: Easy
// Topic: Graph, DFS
// Approach: DFS
// Time Complexity: O(N*M)
// Space Complexity: O(N*M)
class Solution {
private:
   void dfs(int row,int col,int color,int inicolor ,vector<vector<int>>&ans, vector<vector<int>>& image,int delrow[],int delcol[])
   {
    int m=image[0].size();
    int n=image.size();
    ans[row][col]=color;
    for(int i=0; i<4; i++)
    {
        int nrow=row+delrow[i];
        int ncol=col+delcol[i];
        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && ans[nrow][ncol]!=color && image[nrow][ncol]==inicolor)
        {
            dfs(nrow,ncol,color,inicolor,ans,image,delrow,delcol);
        }
    }

   }
 
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int inicolor=image[sr][sc];
        vector<vector<int>> ans=image;

        if(inicolor == color)
          return image;
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        dfs(sr,sc,color,inicolor,ans,image,delrow,delcol);
        return ans;
    }
};
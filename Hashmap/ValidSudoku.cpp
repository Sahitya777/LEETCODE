class Solution {
private:
    bool isValid(int row,int col,vector<vector<char>>& board,char c)
    {
        int count1=0,count2=0,count3=0;
        for(int i=0;i<9;i++)
        {
            if(board[row][i]==c)
                count1++;
            if(board[i][col]==c)
                count2++;
            else if(board[3* (row/3)+(i/3)][3* (col/3)+(i%3)]==c)
                count3++;
        }
        if(count1>1 || count2>1 || count3>1)
            return false;
        return true;
    }
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++)
            {
                if(board[i][j]!='.')
                {
                    char c=board[i][j];
                    if(isValid(i,j,board,c)==false)
                    {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
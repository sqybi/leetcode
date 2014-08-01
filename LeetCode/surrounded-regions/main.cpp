#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    void solve(vector<vector<char>> &board) {
        n = board.size();
        if (n == 0)
        {
            return;
        }
        m = board[0].size();
        vector<vector<char>> originalBoard = board;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                board[i][j] = xChar;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (originalBoard[i][0] == oChar && board[i][0] == xChar)
            {
                fill(i, 0, originalBoard, board);
            }
            if (originalBoard[i][m - 1] == oChar && board[i][m - 1] == xChar)
            {
                fill(i, m - 1, originalBoard, board);
            }
        }
        for (int i = 1; i < m - 1; i++)
        {
            if (originalBoard[0][i] == oChar && board[0][i] == xChar)
            {
                fill(0, i, originalBoard, board);
            }
            if (originalBoard[n - 1][i] == oChar && board[n - 1][i] == xChar)
            {
                fill(n - 1, i, originalBoard, board);
            }
        }
    }

private:
    int n, m;
    int p[4][2] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
    const char xChar = 'X', oChar = 'O';

    void fill(int x, int y, vector<vector<char>> &originalBoard, vector<vector<char>> &board)
    {
        stack<pair<int, int>> st;
        st.push(make_pair(x, y));
        board[x][y] = oChar;
        while (!st.empty())
        {
            x = st.top().first;
            y = st.top().second;
            st.pop();
            for (int i = 0; i < 4; i++)
            {
                int xx = x + p[i][0];
                int yy = y + p[i][1];
                if (isValid(xx, yy) && originalBoard[xx][yy] == oChar && board[xx][yy] == xChar)
                {
                    st.push(make_pair(xx, yy));
                    board[xx][yy] = oChar;
                }
            }
        }
    }

    bool isValid(int x, int y)
    {
        return x >= 0 && x < n && y >= 0 && y < m;
    }
};

int main()
{
    return 0;
}
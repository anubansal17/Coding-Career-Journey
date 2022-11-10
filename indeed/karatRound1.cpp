/* 

A nonogram is a logic puzzle, similar to a crossword, in which the player is given a blank grid and has to color it according to some instructions. Specifically, each cell can be either black or white, which we will represent as 'B' for black and 'W' for white.

+------------+
| W  W  W  W |
| B  W  W  W |
| B  W  B  B |
| W  W  B  W |
| B  B  W  W |
+------------+

For each row and column, the instructions give the lengths of contiguous runs of black ('B') cells. For example, the instructions for one row of [ 2, 1 ] indicate that there must be a run of two black cells, followed later by another run of one black cell, and the rest of the row filled with white cells.

These are valid solutions: [ W, B, B, W, B ] and [ B, B, W, W, B ] and also [ B, B, W, B, W ]
This is not valid: [ W, B, W, B, B ] since the runs are not in the correct order.
This is not valid: [ W, B, B, B, W ] since the two runs of Bs are not separated by Ws.

Your job is to write a function to validate a possible solution against a set of instructions. Given a 2D matrix representing a player's solution; and instructions for each row along with additional instructions for each column; return True or False according to whether both sets of instructions match.

Example instructions #1

matrix1 = [[ W, W, W, W ],
           [ B, W, W, W ],
           [ B, W, B, B ],
           [ W, W, B, W ],
           [ B, B, W, W ]]
rows1_1    =  [], [1], [1,2], [1], [2]
columns1_1 =  [2,1], [1], [2], [1]
validateNonogram(matrix1, rows1_1, columns1_1) => True

Example solution matrix:
matrix1 ->
                                   row
                +------------+     instructions
                | W  W  W  W | <-- []
                | B  W  W  W | <-- [1]
                | B  W  B  B | <-- [1,2]
                | W  W  B  W | <-- [1]
                | B  B  W  W | <-- [2]
                +------------+
                  ^  ^  ^  ^
                  |  |  |  |
  column       [2,1] | [2] |
  instructions      [1]   [1]
       

Example instructions #2

(same matrix as above)
rows1_2    =  [], [], [1], [1], [1,1]
columns1_2 =  [2], [1], [2], [1]
validateNonogram(matrix1, rows1_2, columns1_2) => False

The second and third rows and the first column do not match their respective instructions.

Example instructions #3

(same matrix as above)
rows1_3    = [], [1], [3], [1], [2]
columns1_3 = [3], [1], [2], [1]
validateNonogram(matrix1, rows1_3, columns1_3) => False

The third row and the first column do not match their respective instructions.

Example instructions #4

(same matrix as above)
rows1_4    =  [], [1,1], [1,2], [1], [2]
columns1_4 =  [2,1], [1], [2], [1]
validateNonogram(matrix1, rows1_4, columns1_4) => False

The second row does not match the respective instructions

Example instructions #5

matrix2 = [
 [ W, W ],
 [ B, B ],
 [ B, B ],
 [ W, B ]
]
rows2_1    = [], [2], [2], [1]
columns2_1 = [1, 1], [3]
validateNonogram(matrix2, rows2_1, columns2_1) => False

The black cells in the first column are not separated by white cells.

Example instructions #6

(same matrix as above)
rows2_2    = [], [2], [2], [1]
columns2_2 = [3], [3]
validateNonogram(matrix2, rows2_2, columns2_2) => False

The first column has the wrong number of black cells.

Example instructions #7

(same matrix as above)
rows2_3    = [], [], [], []
columns2_3 = [], []
validateNonogram(matrix2, rows2_3, columns2_3) => False

All of the instructions are empty

All Test Cases:
validateNonogram(matrix1, rows1_1, columns1_1) => True
validateNonogram(matrix1, rows1_2, columns1_2) => False
validateNonogram(matrix1, rows1_3, columns1_3) => False
validateNonogram(matrix1, rows1_4, columns1_4) => False
validateNonogram(matrix2, rows2_1, columns2_1) => False
validateNonogram(matrix2, rows2_2, columns2_2) => False
validateNonogram(matrix2, rows2_3, columns2_3) => False

n: number of rows in the matrix
m: number of columns in the matrix

*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;
bool isValid(vector<vector<int>> &grid, int i, int j, unordered_set<int> &st) {
  int n = grid.size();
  if(grid[i][j] < 1 || grid[i][j] > n || st.find(grid[i][j]) != st.end())
    return 0;
  return 1;
}
bool validate(vector<vector<int>> &grid) {
  int n = grid.size();
  for(int i=0; i<n; i++) {
    unordered_set<int> st;
    for(int j=0; j<n; j++) {
      if(!isValid(grid, i, j, st)) {
        return 0;
      } else {
        st.insert(grid[i][j]);
      }
    }
  }
  // column
    for(int i=0; i<n; i++) {
    unordered_set<int> st;
    for(int j=0; j<n; j++) {
      if(!isValid(grid, j, i, st)) {
        return 0;
      } else {
        st.insert(grid[j][i]);
      }
    }
  }
  return 1;
  
}


bool validateInstructions(vector<vector<char>> grid, vector<vector<int>> rows, vector<vector<int>> cols) {
  int n = grid.size();
  int m = grid[0].size();
  vector<int> rowCount(n, 0);
  vector<int> colCount(m, 0);
  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      if(grid[i][j] == 'B')
        rowCount[i]++;
    }
  }
  
    for(int i=0; i<n; i++) {
      for(int j=0; j<m; j++) {
        if(grid[j][i] == 'B')
          colCount[i]++;
    }
  }
  int rowSize = rows.size();
  for(int i=0; i<rowSize; i++) {
    if(rows[i].size() == 0) {
      if(rowCount[i] != 0)
        return 0;
    }
    else {
      int start = 0;
      int count = 0;
      int j = 0;
      while(j<m) {
        if(start == rows[i].size()) {
          break;
        }
        if(grid[i][j] == 'B')
          count++;
        else
          count = 0;
        if(count == rows[i][start])
          start++;
        j++;
      }
      if(start != rows[i].size()) {
        return 0;
      }
    }
  }
  
  int colSize = cols.size();
  for(int i=0; i< colSize; i++) {
    if(cols[i].size() == 0) {
      if(colCount[i] != 0)
        return 0;
    }
    else {
      int start = 0;
      int count = 0;
      int j = 0;
      while(j<m) {
        if(start == cols[i].size()) {
          break;
        }
        if(grid[j][i] == 'B')
          count++;
        else
          count = 0;
        if(count == cols[i][start])
          start++;
        j++;
      }
      if(start != cols[i].size()) {
        return 0;
      }
    }
  }
  return 1;
}
int main() {
  
  vector<vector<char>> matrix1 = {
    {'W','W','W','W'},
    {'B','W','W','W'},
    {'B','W','B','B'},
    {'W','W','B','W'},
    {'B','B','W','W'}
  };
  
  vector<vector<int>> rows1_1 = {{},{1},{1,2},{1},{2}};
  vector<vector<int>> columns1_1 = {{2,1},{1},{2},{1}};

  vector<vector<int>> rows1_2 = {{},{},{1},{1},{1,1}};
  vector<vector<int>> columns1_2 = {{2},{1},{2},{1}};

  vector<vector<int>> rows1_3 = {{},{1},{3},{1},{2}};
  vector<vector<int>> columns1_3 = {{3},{1},{2},{1}};

  vector<vector<int>> rows1_4 = {{},{1,1},{1,2},{1},{2}};
  vector<vector<int>> columns1_4 = {{2,1},{1},{2},{1}};

  vector<vector<char>> matrix2 = {
    {'W','W'},
    {'B','B'},
    {'B','B'},
    {'W','B'}
  };

  vector<vector<int>> rows2_1 = {{},{2},{2},{1}};
  vector<vector<int>> columns2_1 = {{1,1},{3}};

  vector<vector<int>> rows2_2 = {{},{2},{2},{1}};
  vector<vector<int>> columns2_2 = {{3},{3}};

  vector<vector<int>> rows2_3 = {{},{},{},{}};
  vector<vector<int>> columns2_3 = {{},{}};
  
  cout<<validateInstructions(matrix1, rows1_1, columns1_1);

  
  /* vector<vector<int>> grid1 = {
    {2, 3, 1},
    {1, 2, 3},
    {3, 1, 2},
  };
  vector<vector<int>> grid2 = {
    {1, 2, 3},
    {3, 2, 1},
    {3, 1, 2},
  };
  vector<vector<int>> grid3 = {
    {2, 2, 3},
    {3, 1, 2},
    {2, 3, 1},
  };
  vector<vector<int>> grid4 = {
    {1},
  };
  vector<vector<int>> grid5 = {
    {-1, -2, -3},
    {-2, -3, -1},
    {-3, -1, -2},
  };
  vector<vector<int>> grid6 = {
    {1, 3, 3},
    {3, 1, 2},
    {2, 3, 1},
  };
  vector<vector<int>> grid7 = {
    {1, 2, 3, 4},
    {4, 3, 2, 1},
    {1, 3, 2, 4},
    {4, 2, 3, 1},
  };
  vector<vector<int>> grid8 = {
    {0, 3},
    {3, 0},
  };
  vector<vector<int>> grid9 = {
    {0, 1},
    {1, 0},
  };
  vector<vector<int>> grid10 = {
    {0, 2},
    {2, 0},
  };
  vector<vector<int>> grid11 = {
    {1, 2, 3, 4},
    {2, 3, 1, 4},
    {3, 1, 2, 4},
    {4, 2, 3, 1},
  };
  vector<vector<int>> grid12 = {
    {-1, -2, 12, 1},
    {12, -1, 1, -2},
    {-2, 1, -1, 12},
    {1, 12, -2, -1},
  };
  vector<vector<int>> grid13 = {
    {2, 3, 3},
    {1, 2, 1},
    {3, 1, 2},
  };
  vector<vector<int>> grid14 = {
    {1, 3},
    {3, 1},
  };
  
  
  
  bool answer;
  // answer = validate(grid2);
  // cout<<answer<<endl;
  cout<<validate(grid1)<<endl;
  cout<<validate(grid2);
  cout<<validate(grid3);
  cout<<validate(grid4);
  cout<<validate(grid5);
  cout<<validate(grid6);
  cout<<validate(grid7);
  cout<<validate(grid8);
  cout<<validate(grid9);
  cout<<validate(grid10);
  cout<<validate(grid11);
  cout<<validate(grid12);
  cout<<validate(grid13);
  cout<<validate(grid14); */
  return 0;
}

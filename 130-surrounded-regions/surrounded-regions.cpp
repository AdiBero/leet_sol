class Solution {
public:

    void bfs(vector<vector<char>>& board, vector<vector<bool>> &check,queue<pair<int,int>> &q){

     int n = q.size();
        int rows = board.size();
        int cols = board[0].size();

        while(!q.empty()){

            pair<int,int> temp = q.front();
            q.pop();

            
            int row = temp.first;
            int col = temp.second;

           
            
    // up
        
    if(row > 0 ){
        if(board[row-1][col] == 'O' && !check[row-1][col]){
            check[row-1][col] = true;
            q.emplace(row-1,col);
        }
    }

    // Down
    if(row + 1 < rows){
        if(board[row+1][col] == 'O'&& !check[row+1][col]){
            check[row+1][col] = true;

            q.emplace(row+1,col);
        }
    }

    // Left
    if(col > 0 ){
        if(board[row][col-1] == 'O'&& !check[row][col-1]){
             check[row][col-1] = true;

            q.emplace(row,col-1);
        }
    }

    // Right
    if(col + 1 < cols ){
        if(board[row][col+1] == 'O' && !check[row][col+1]){
            check[row][col+1] = true;
  
            q.emplace(row,col+1);
        }
    }
}//while ends


    }
        



    
    void solve(vector<vector<char>>& board) {
        int row = board.size();
        int col = board[0].size();

        vector<vector<bool>> check(row,vector<bool>(col,false));
        queue<pair<int,int>> q;

        //top row
        for(int i = 0; i<col;i++){
            if(board[0][i] == 'O'){
                check[0][i] = true;
                q.emplace(0,i);
            }
        }
        //bottom row
         for(int i = 0; i<col;i++){
            if(board[row-1][i] == 'O'){
                 check[row-1][i] = true;

                q.emplace(row - 1,i);
            }
        }
        // left col
         for(int i = 0; i<row;i++){
            if(board[i][0] == 'O'){
                check[i][0] = true;

                q.emplace(i,0);
            }

        }
        
        //right col
        
         for(int i = 0; i<row;i++){
            if(board[i][col-1] == 'O'){
                check[i][col-1] = true;

                q.emplace(i,col-1);
            }

        }

        bfs(board,check,q);

        //final check

        for(int i = 0; i < row ; i++){
            for(int j = 0; j < col ; j++){
                if(board[i][j]== 'O' && check[i][j]==false){
                    board[i][j] = 'X';
                }


            }
        }







        
    }
};
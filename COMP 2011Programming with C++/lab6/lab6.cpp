#include <stdlib.h>
#include <iostream>
using namespace std;
const int MAX_HEIGHT=6;
const int MAX_WIDTH=6;

void print(int board[][MAX_WIDTH], int height, int width){
    cout<< "board is: " << endl;
    for (int i=0;i<height;i++){
        for (int j=0;j<width;j++){
            if (j == width-1){
                cout << board[i][j] <<endl;
            }
            else{
            cout << board[i][j] << " ";}
        }
    }
}

bool findUncoveredGrid(int board[][MAX_WIDTH], int height, int width, int& r_id, int& c_id){
    // to be completed
    //

    for (int i=0;i<height;i++){
        for (int j=0;j<width;j++){
            if (board[i][j]==0){r_id = i;c_id = j;return true;}
        }
    }
    return false;
}



int numberLayout(int board[][MAX_WIDTH], int height, int width){
    int result = 0;
    // to be completed
    //
    int r_id;
    int c_id;
    int boardA[height][MAX_WIDTH];
    int boardB[height][MAX_WIDTH];
    for (int i=0;i<height;i++){
        for (int j=0;j<width;j++){
            boardA[i][j] = board[i][j];
            boardB[i][j] = board[i][j];
        }
    }
    
    if (findUncoveredGrid(board,height,width,r_id,c_id)==true){
        if (c_id+1 < width && board[r_id][c_id+1]!=1){
        boardA[r_id][c_id] = 1;
        boardA[r_id][c_id+1] = 1;
        result += numberLayout(boardA,height,width);
        }
        if (r_id+1 < height && board[r_id+1][c_id]!=1){
        boardB[r_id][c_id] = 1;
        boardB[r_id+1][c_id] = 1;
        result += numberLayout(boardB,height,width);
        }
    }
    else 
    {
        result++;
    }
    
    return result;
}


int main(){
    int width, height;
    int board[MAX_HEIGHT][MAX_WIDTH] = {};

    // enter the height (number of rows)
    do{
    cout << "Please enter the height [1, " << MAX_HEIGHT << "]:" << endl;
    cin >> height;
    }
    while((height < 1)||(height > MAX_HEIGHT));

    // enter the width (number of columns)
    do{
    cout << "Please enter the width [1, " << MAX_WIDTH << "]:" << endl;
    cin >> width;
    }while((width < 1)||(width > MAX_WIDTH));

    cout << "The number of layouts is " << numberLayout(board, height, width) << "." << endl;
    
    return 0;
}
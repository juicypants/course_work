#include <iostream>
#include "consts.h"
#include "lab8.h"

using namespace std;

// TODO 1: initialize the cells of the game
// The cells should start with id 0 (this cell is out of the gameboard), and there would be another MAP_SIDE_LEN*MAP_SIDE_LEN cells on the gameboard
// The default value of a cell's to_cell_id should be -1 and that of a cell's landslide should be false
// LINK_ENDS in consts.h provides the starting cell ids and ending cell ids of links, you may want to modify some cell's to_cell_id
// Example: {4, 13} indicates we want a link from cell 4 to cell 13 (this is actually a ladder), then you should change cell 4's to_cell_id to 13
// LANDSLIDE_LOCS in consts.h provides the cell id that would trigger landslide, you may want to modify some cells's landslide
void init_game(Cell* cell_ptrs[]) {
    for (int i=0;i<MAP_SIDE_LEN*MAP_SIDE_LEN+1;i++){
        cell_ptrs[i]->to_cell_id = -1;
        cell_ptrs[i]->landslide = false;
        for(int j=0; j<sizeof(LINK_ENDS)/sizeof(LINK_ENDS[0]);j++){
            if(i == LINK_ENDS[j][0]){
            cell_ptrs[i]->to_cell_id = LINK_ENDS[j][1];
            }
        }     
    }
    for(int k=0; k<sizeof(LANDSLIDE_LOCS)/sizeof(LANDSLIDE_LOCS[0]);k++){ 
        cell_ptrs[LANDSLIDE_LOCS[k]]->landslide = true;
        }
}


// TODO 2: move the player using the given number of moves
// Move the player according to the given parameter by changing the player's position.
// You will need to check whether the player should be "bounced back" by the ending cell.
// Example: For a player who moves 5 cells from cell 21, if cell 25 is the ending cell, then the player will have 1 more cell to move when reaches cell 25. The player will then be "bounced back" by 1 cell and goes to cell 24.
// You will also need a checking for ladders and snakes at the player's new position. If the player locates at the bottom cell of a ladder or the top cell of a snake after movement, perform corresponding movement mentioned in the previous section.
// Example: For a player who moves 6 cells from cell 10, if cell 16 has a snake to cell 6, then the player will be relocated to cell 6 immediately after his movement.
// After all the works mentioned above, check whether the player's new cell triggers landslide, and call the function for landslide if needed
void move(Cell* cell_ptrs[], int& cur_cell_id, int num_moves) {
    cur_cell_id = cur_cell_id + num_moves;
    if(cur_cell_id > 25){
        cur_cell_id = 25 - (cur_cell_id-25);
    }
    
    if(cell_ptrs[cur_cell_id]->to_cell_id != -1){
        
        cur_cell_id = cell_ptrs[cur_cell_id]->to_cell_id;
        
    }
    if(cell_ptrs[cur_cell_id]->landslide == true){
        landslide(cell_ptrs,cur_cell_id);
    }

}


// TODO 3: trigger landslide for the current cell location
// The player's current row has its cells left circularly rotated by one cell.
// Example: For a link from cell 4 to cell 13, and another link from cell 14 to cell 20, after the rotation for row from cell 11 to cell 15, instead of the original links we will have a link from cell 4 to cell 12, and another link from cell 13 to cell 20.
// Notice that the player's location will not change in the landslide.
// Illustartion of the example can also be found on the website's Fig 4.
// Try your best not to copy the Cell's, the method might work in this lab but will not work in practice for much larger structs or classes.
// You may instead try to modify the pointers to Cells.
void landslide(Cell* cell_ptrs[], int cur_cell_id) {
    int level = (cur_cell_id/5);
    
    Cell *temp_tid_ptr;
    temp_tid_ptr = cell_ptrs[level*5+1];
    
    for (int i=level*5+1;i<level*5+MAP_SIDE_LEN+1;i++){
        if (i == level*5+MAP_SIDE_LEN){
            cell_ptrs[i] = temp_tid_ptr;
        }
        else{
            cell_ptrs[i] = cell_ptrs[i+1];
        }
    }
    for (int i=level*5+1;i<level*5+MAP_SIDE_LEN+1;i++){
        for (int j=0;j<MAP_SIDE_LEN*MAP_SIDE_LEN+1;j++){
            if(cell_ptrs[j]->to_cell_id == i){
                if(i == level*5+1){
                    cell_ptrs[j]->to_cell_id = level*5+MAP_SIDE_LEN;
                    break;
                }
                else{
                    cell_ptrs[j]->to_cell_id = i-1;
                    break;
                }
            }
        }
    }
}

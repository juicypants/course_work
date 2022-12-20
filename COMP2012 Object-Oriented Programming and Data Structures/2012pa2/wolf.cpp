#include "wolf.h"
#include "sheep.h"
#include "grass.h"
#include "helper.h"

/**
 * TODO: TASK 4
 * 
 * Place a copy of this Wolf onto nextGrid at the specified position.
 * You may implement this similar to Sheep::putSelf().
*/
void Wolf::putSelf(Grid* nextGrid, const int x, const int y) {
    putAnimal(new Wolf(*this),nextGrid,x,y);
}

/**
 * TODO: TASK 4
 * 
 * Place a brand new Wolf onto nextGrid at the specified position.
 * You may implement this similar to Sheep::putClone().
*/
void Wolf::putClone(Grid* nextGrid, const int x, const int y) const {
    putAnimal(new Wolf(this->getBoard()),nextGrid,x,y);
}

/**
 * TODO: TASK 4
 * 
 * Implement this function similar to Sheep::eat().
 * The only difference is that Wolf eats Sheep instead of Grass.
*/
void Wolf::eat(Grid* nextGrid) {
    for (int i=0; i<9; ++i) {
        if (i == 4) continue;
        int adjX = getX() + getAdjX(i);
        int adjY = getY() + getAdjY(i);
        Entity* adjEntity = getBoard()->getGrid()->getCell(adjX, adjY);

        if (!adjEntity) {
            // Out of bounds or empty space, ignore
            continue;
        }
        if (dynamic_cast<Sheep*>(adjEntity) && (adjEntity->isRemoved()!=true)){
            adjEntity->removeSelf(nextGrid);
            this->setHungerCounter(SHEEP_HUNGER_COOLDOWN);
            return;        
        }
        // ?
    }
}

/**
 * TODO: TASK 4
 * 
 * Implement this function similar to Sheep::breed().
 * The only difference is that Wolf breeds by finding a Wolf instead of Sheep.
*/
void Wolf::breed(Grid* nextGrid) {
    for (int i=0; i<9; ++i) {
        if (i == 4) continue;
        int adjX = getX() + getAdjX(i);
        int adjY = getY() + getAdjY(i);
        Entity* adjEntity = getBoard()->getGrid()->getCell(adjX, adjY);

        if (!adjEntity) {
            // Out of bounds or empty space, ignore
            continue;
        }
        if (dynamic_cast<Wolf*>(adjEntity)){
            int temp = getRandomMovementIndex(nextGrid);
            if(temp!=-1){
                if (temp == 0){
                    putClone(nextGrid,this->getX()-1,this->getY()-1);
                }
                else if (temp == 1){
                    putClone(nextGrid,this->getX()-1,this->getY());
                }
                else if (temp == 2){
                    putClone(nextGrid,this->getX()-1,this->getY()+1);
                }
                else if (temp == 3){
                    putClone(nextGrid,this->getX(),this->getY()-1);
                }
                else if (temp == 5){
                    putClone(nextGrid,this->getX(),this->getY()+1);
                }
                else if (temp == 6){
                    putClone(nextGrid,this->getX()+1,this->getY()-1);
                }
                else if (temp == 7){
                    putClone(nextGrid,this->getX()+1,this->getY());
                }
                else if (temp == 8){
                    putClone(nextGrid,this->getX()+1,this->getY()+1);
                }
                return;
            }
        }
        // ?
    }
}

/**
 * TODO: TASK 4
 * 
 * If there is at least one Sheep on the board, Wolf tries to move towards it.
 * 
 * You should loop over the board in the same order as Board calling update(), 
 * calculate Euclidean distance to each cell containing a Sheep, and keep track of the shortest distance found.
 * Ignore sheeps that have been eaten (removed).
 * No need to keep track of Sheeps with the same distance as shortest one found so far.
 * 
 * If a Sheep is found, move to the adjacent cell closest to that Sheep. If that cell is occupied with another Animal,
 * the Wolf stays at its position.
 * 
 * If no Sheep is found, the Wolf moves randomly like a Sheep.
 * 
 * You may follow the structure below to implement the function.
*/
int euclidean_calculation(int x1, int x2, int y1, int y2){
    
    return (((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2)));
    
}
void Wolf::move(Grid* nextGrid) {
    // First, find a sheep to target
    int max_dis = 999999;
    Entity* temp_sheep = nullptr;
    // ?
    for (int x=0; x<BOARD_SIZE_W; ++x) {
        for (int y=0; y<BOARD_SIZE_H; ++y) {
            
            Entity* ent = this->getBoard()->getGrid()->getCell(x,y);
            
            if (dynamic_cast<Sheep*>(ent)){
                if(ent->isRemoved()!=true){
                    int cal_dis = euclidean_calculation(this->getX(),ent->getX(),this->getY(),ent->getY());
                    
                    if (cal_dis < max_dis){
                    
                        max_dis = cal_dis;
                        temp_sheep = ent;
                    }
                }
             
            }
              
            // ?

        }
    }
    

    if (temp_sheep) { // Edit this line with the appropriate condition
        // If a sheep with the closest distance is found, try to move towards it
        int shortest_dis = 99999;
        int shortest_x = 999999;
        int shortest_y = 999999;
        for (int i=0; i<9; ++i) {
            
            if (i == 4) continue;
            
            int adjX = getX() + getAdjX(i);
            int adjY = getY() + getAdjY(i);
            if (nextGrid->outOfBounds(adjX, adjY)) {
                // Out of bounds, ignore
                continue;
            }

            Entity* adjEntity = getBoard()->getGrid()->getCell(adjX, adjY);
            if (dynamic_cast<Animal*>(adjEntity)) {
                // Adjacent cell is an animal, cannot move over
                continue;
            }

            Entity* adjNextEntity = nextGrid->getCell(adjX, adjY);
            if (dynamic_cast<Animal*>(adjNextEntity)) {
                // Adjacent cell in next grid has an animal, cannot move over
                continue;
            }
            
            int cal_dis = euclidean_calculation(adjX,temp_sheep->getX(),adjY,temp_sheep->getY());
            
            if (cal_dis<shortest_dis){
                shortest_dis = cal_dis;
                shortest_x = adjX;
                shortest_y = adjY;    
            }
                
        }
        if(shortest_dis!=99999){
            putSelf(nextGrid,shortest_x,shortest_y);}
        else{
            putSelf(nextGrid,this->getX(),this->getY());
        }





        // ?
    }
    else {
        // No sheep found, move randomly
        int temp = getRandomMovementIndex(nextGrid);
    
        if(temp!=-1){
            if (temp == 0){
                putSelf(nextGrid,this->getX()-1,this->getY()-1);
            }
            else if (temp == 1){
                putSelf(nextGrid,this->getX()-1,this->getY());
            }
            else if (temp == 2){
                putSelf(nextGrid,this->getX()-1,this->getY()+1);
            }
            else if (temp == 3){
                putSelf(nextGrid,this->getX(),this->getY()-1);
            }
            else if (temp == 5){
                putSelf(nextGrid,this->getX(),this->getY()+1);
            }
            else if (temp == 6){
                putSelf(nextGrid,this->getX()+1,this->getY()-1);
            }
            else if (temp == 7){
                putSelf(nextGrid,this->getX()+1,this->getY());
            }
            else if (temp == 8){
                putSelf(nextGrid,this->getX()+1,this->getY()+1);
            }
            return;
        }
        else{
            putSelf(nextGrid,this->getX(),this->getY());
        }
        // ?  
    }
}
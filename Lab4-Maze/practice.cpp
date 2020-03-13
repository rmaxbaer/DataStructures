// New function:

bool Pathfinder::validPath(int x, int y, int z){ // what if it's 2? // what if x - 1 is out of bounds
    if(x == 0){
        if(mazeCopy[x+1][y][z] == 1){
            return true;
        }
    }else if(x == 4){
        if(mazeCopy[x-1][y][z] == 1){
            return true;
        }
    }else if(y == 0){
        if(mazeCopy[x][y+1][z] == 1){
            return true;
        }
    }else if(y == 4){
        if(mazeCopy[x][y-1][z] == 1){
            return true;
        }
    }else if(z == 0){
        if(mazeCopy[x][y][z+1] == 1){
            return true;
        }
    }else if(z == 4){
        if(mazeCopy[x][y][z] == 1){
            return true;
        }
    }else if ((mazeCopy[x+1][y][z] == 1) || (mazeCopy[x-1][y][z] == 1) || (mazeCopy[x][y+1][z] == 1) || (mazeCopy[x][y-1][z] == 1) || (mazeCopy[x][y][z+1] == 1) || (mazeCopy[x][y][z-1] == 1)){
        return true;
    }else{
        return false;
    }
    
    
//Old Function

bool Pathfinder::validPath(int x, int y, int z){ // what if it's 2? // what if x - 1 is out of bounds
    if((mazeCopy[x+1][y][z] == 1) || (mazeCopy[x-1][y][z] == 1) || (mazeCopy[x][y+1][z] == 1) || (mazeCopy[x][y-1][z] == 1) || (mazeCopy[x][y][z+1] == 1) || (mazeCopy[x][y][z-1] == 1)){ 
        return true;
    }
    else{
        return false;
    }
}





//Block, row, column
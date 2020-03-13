#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <deque>
#include "Pathfinder.h"

string Pathfinder:: toString() const{
    stringstream ss;
    for(int z = 0; z <5; ++z){
        for(int y = 0; y <5; ++y){
            for(int x = 0; x <5; ++x){
                if(mazeExists){
                    if(x < 4){
                        ss << myMaze[z][y][x] << " ";
                    }else{
                        ss << myMaze[z][y][x];
                    }
                }else{
                    if(x<4){
                        ss << "1 ";
                    }else{
                        ss << "1";
                    }
                }
            }
            ss << endl;
        }
        if(z < 4){ // We don't want a trailing newline
            ss << endl;
        }
    }
    
    return ss.str();
}

void Pathfinder:: createRandomMaze(){
    for(int z = 0; z <5; ++z){
        for(int y = 0; y <5; ++y){
            for(int x = 0; x <5; ++x){
                myMaze[z][y][x] = rand() % 2;
                
            }
        }
    }
    myMaze[0][0][0] = 1;
    myMaze[4][4][4] = 1;
    mazeExists = true;
}

bool Pathfinder:: importMaze(string file_name){
    deque<int> myInts;
    bool valid = false;
    string token;
    int next;
    ifstream file(file_name);
    while(getline(file, token)){
        // If token == /n, increase number of layers
        istringstream line(token);
        while(line >> next){
            myInts.push_back(next);
        }
    }
    
    if((myInts.size() == 125) && (myInts.at(0) == 1) && myInts.at(124) == 1){
        for(int i = 0; i <5; ++i){
            for(int j = 0; j <5; ++j){
                for(int k = 0; k <5; ++k){
                    myMaze[i][j][k] = myInts.front();
                    myInts.pop_front();
                
                }
            }
        }
        
        valid = true;
        mazeExists = true;
    }
    else{
        valid = false;
    }
    
    return valid;
}
//-----------------------------------------------------------------------------------------

//Part 3-----------------------------------------------------------------------------------
/*
* solveMaze
*
* Attempts to solve the current maze and returns a solution if one is found.
*
* A solution to a maze is a list of coordinates for the path from the entrance to the exit
* (or an empty vector if no solution is found). This list cannot contain duplicates, and
* any two consecutive coordinates in the list can only differ by 1 for only one
* coordinate. The entrance cell (0, 0, 0) and the exit cell (4, 4, 4) should be included
* in the solution. Each string in the solution vector must be of the format "(x, y, z)",
* where x, y, and z are the integer coordinates of a cell.
*
* Understand that most mazes will contain multiple solutions
*
* Returns:		vector<string>
*				A solution to the current maze, or an empty vector if none exists
*/
vector<string> Pathfinder::solveMaze(){
    P = vector<string> () ;
    for(int z = 0; z <5; ++z){
        for(int y = 0; y <5; ++y){
            for(int x = 0; x <5; ++x){
                mazeCopy[x][y][z] = myMaze[x][y][z];
            }
        }
    }
    
    bool solved = findPath(0,0,0);
    return P;
}

bool Pathfinder::onMaze(int z, int y, int x){ // Do these helper functions need to be above the ones that use it?
    if(((x < 5) && (x > -1)) && ((y < 5) && (y > -1)) && ((z < 5) && (z > -1))){
        return true;
    }
    else{
        return false;
    }
}

bool Pathfinder::validPath(int x, int y, int z){ // what if it's 2? // what if x - 1 is out of bounds
    if(x == 0){
        if(mazeCopy[x+1][y][z] == 1){
            return true;
        }
    }
    if(x == 4){
        if(mazeCopy[x-1][y][z] == 1){
            return true;
        }
    }
    if(y == 0){
        if(mazeCopy[x][y+1][z] == 1){
            return true;
        }
    }
    if(y == 4){
        if(mazeCopy[x][y-1][z] == 1){
            return true;
        }
    }
    if(z == 0){
        if(mazeCopy[x][y][z+1] == 1){
            return true;
        }
    }
    if(z == 4){
        if(mazeCopy[x][y][z] == 1){
            return true;
        }
    }
    if ((mazeCopy[x+1][y][z] == 1) || (mazeCopy[x-1][y][z] == 1) || (mazeCopy[x][y+1][z] == 1) || (mazeCopy[x][y-1][z] == 1) || (mazeCopy[x][y][z+1] == 1) || (mazeCopy[x][y][z-1] == 1)){
        return true;
    }else{
        return false;
    }
}

bool Pathfinder::findPath(int x, int y, int z){
 
    stringstream ss;
    ss << "(" << z << ", " << y << ", " << x << ")";
    P.push_back(ss.str());
    
    // Base Cases
    
    if((onMaze(x,y,z) == false) || (validPath(x, y, z) == false) || mazeCopy[x][y][z] == 2 || mazeCopy[x][y][z] != 1 ){//if (outside of maze || on an invalid path || have been here before)
        P.pop_back();
        return false;
    }
    if((x == 4) && (y == 4) && (z == 4)){ //if(end of maze)

        return true;
    }
    //recursive part:
    mazeCopy[x][y][z] = 2;
    if((findPath((x+1), y, z)) || (findPath((x-1), y, z)) || (findPath(x, (y+1), z)) || (findPath(x, (y-1), z))|| (findPath(x, y, (z+1))) || (findPath(x, y, (z-1))) ){
        // return true; on the right path
        return true;
    }
    else{
        P.pop_back();
        return false;
    }
}


//-----------------------------------------------------------------------------------------


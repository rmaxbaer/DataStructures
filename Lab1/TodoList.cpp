#include "TodoList.h"
#include "TodoListInterface.h"

#include <fstream>
#include <sstream>
#include <vector>

TodoList::TodoList(){
        // Makes a current list of what the TodoList file has
        vector<string> currentList;
        
        ifstream file("TODOList.txt");
        string line;
        while (getline(file, line))
        {
                currentList.push_back(line);
                
        }
        file.close();
        
        for(int i = 0; i < currentList.size(); ++i){
                if((i % 2) == 0){
                        dueDates.push_back(currentList.at(i));
                }
                else{
                        taskNames.push_back(currentList.at(i));
                }
        }
        

}
TodoList::~TodoList()
{
        // write to the file, remove things, update todolist
        ofstream outFS;
        outFS.open("TODOList.txt");
        for(int i = 0; i < dueDates.size(); ++i){
                outFS << dueDates.at(i) << endl;
                outFS << taskNames.at(i) << endl;
        }
        outFS.close();
}

void TodoList::add(string _duedate, string _task){
        //Currently, this adds to the bottom- it does not recognize days already used and add to them
        dueDates.push_back(_duedate);
        taskNames.push_back(_task);
        
        /*
        ofstream outFS;
        
        outFS.open("TODOList.txt", ios_base::app);
        outFS << _duedate << endl;
        outFS << _task << endl;
        outFS.close();
        */
}

int TodoList::remove(string _task){
        //   Returns 1 if it removes an item, 0 otherwise
        int myInt = 0;
        
        for(int i = 0; i < taskNames.size(); ++i){
                if(taskNames.at(i) == _task){
                        taskNames.erase(taskNames.begin() + i);
                        dueDates.erase(dueDates.begin() + i);
                        myInt = 1;  
                }
        }
        
        
        
        /*
        int myInt = 0;
        vector<string> currentList;
        
        ifstream file("TODOList.txt");
        string line;
        while (getline(file, line))
        {
                currentList.push_back(line);
                
        }
        file.close();
        
        for(int i = 0; i < currentList.size(); ++i){
                if(currentList.at(i) == _task){
                        currentList.erase(currentList.begin() + i - 1, currentList.begin() + i + 1);
                        myInt = 1;
                }
        }
        
        ofstream outFS;
        outFS.open("TODOList.txt");
        for(int i = 0; i < currentList.size(); ++i){
        outFS << currentList.at(i) << endl;
        }
        outFS.close();
        
        */
        return myInt;
}

void TodoList::printTodoList(){
        for (int i = 0; i < dueDates.size(); ++i){
                cout << dueDates.at(i) << endl;
                cout << taskNames.at(i) << endl;
        }
        /*
        vector<string> currentList;
        
        ifstream file("TODOList.txt");
        string line;
        while (getline(file, line))
        {
                currentList.push_back(line);
                
        }
        file.close();
        
        for(int i = 0; i < currentList.size(); ++i){
                cout << currentList.at(i) << endl;
        }
        */
}

void TodoList::printDaysTasks(string _date){
        for (int i = 0; i < dueDates.size(); ++i){
                if(dueDates.at(i) == _date){
                        cout << taskNames.at(i) << endl;
                }
        }
        
        
        /*
        vector<string> currentList;
        
        ifstream file("TODOList.txt");
        string line;
        while (getline(file, line))
        {
                currentList.push_back(line);
                
        }
        file.close();
        
        for(int i = 0; i < currentList.size(); ++i){
                if(currentList.at(i) == _date){
                        cout << currentList.at(i+1) << endl;
                }
        }
        */
}
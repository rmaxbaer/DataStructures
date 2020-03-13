#ifndef TODO_LIST_H
#define TODO_LIST_H

#include "TodoListInterface.h"
#include <vector>

class TodoList: public TodoListInterface {
    public:
        TodoList();
        ~TodoList();
        void add(string _duedate, string _task);
        int remove(string _task);
        void printTodoList();
        void printDaysTasks(string _date);
    
    private:
        vector<string> dueDates;
        vector<string> taskNames;
      
    
};
#endif
    
    
    
  
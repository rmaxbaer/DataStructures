#include <iostream>
#include <fstream>
#include <string>
#include "TodoList.h"
using namespace std;

int main(int argc, char *argv[]){
  TodoList newList;
  string operation = argv[1];
  if(operation == "add"){
    newList.add(argv[2], argv[3]);
  }else if(operation == "remove"){
    newList.remove(argv[2]);
  }else if(operation == "printList"){
    newList.printTodoList();      
  }else if(operation == "printDay"){
    newList.printDaysTasks(argv[2]);
  }
  return 0;
}

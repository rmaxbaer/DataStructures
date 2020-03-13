#include "ExpressionManager.h"
#include <sstream>
#include <string>

bool ExpressionManager::isBalanced(string expression){
    bool balanced = 1;
    stack<char> myStack;
    char topChar;
    char character;
    
    for (int i = 0; i < expression.size(); ++i){
        character = expression.at(i);
        if ((character == '(' ) || (character == '{' ) || (character == '[' ) ){
            myStack.push(character);
        }
        
        if ((character == ')' ) || (character == '}' ) || (character == ']' ) ){
            if(myStack.size() > 0){ 
                topChar = myStack.top();
            }
            else{ // If there is a closed parenthese added but we have nothing on the stack, set topChar to 'd' so the code does not use the pop function on an empty stack
                topChar = 'd';
                myStack.push(topChar);
            }
            if( ((character == ')' ) && (topChar == '(' )) || ((character == '}' ) && (topChar == '{' )) || ((character == ']' ) && (topChar == '[' )) ){
                myStack.pop();
            }
        }
    }
    if(myStack.empty()){
        balanced = 1;
    }
    else{
        balanced = 0;
    }
    cout << "isBalanced"  << expression << endl;
    return balanced;
}

string ExpressionManager:: postfixEvaluate(string postfixExpression){
    stack<int> myStack;
    int intOne;
    int intTwo;
    int result;
    
    istringstream iss(postfixExpression);
    string next;
    while(iss >> next){
        if(isdigit(next.at(0))){
            myStack.push(stoi(next));
        }
        else if (myStack.size() >= 2) {
            
            intTwo = myStack.top();
            myStack.pop();
            
            intOne = myStack.top();
            myStack.pop();
            
                if(next == "+"){
                    result = intOne + intTwo;
                }
                else if(next == "-"){
                    result = intOne - intTwo;
                }
                else if(next == "*"){
                    result = intOne * intTwo;
                }
                else if(next == "/"){
                    if(intTwo == 0){
                        break;
                    }
                    result = intOne / intTwo;
                }
                else if(next == "%"){
                    result = intOne % intTwo;
                }
                myStack.push(result);
            }
            else{
                //Invalid
                break;
            }
            
        }
    
    if(myStack.size() == 0){
        return "invalid";
    }
    else{
        return to_string(myStack.top());
    }
}


string ExpressionManager::postfixToInfix(string postfixExpression){
    stack<string> myStack;
    string operandOne;
    string operandTwo;
    string myEquation = "";
    bool success;
    
    
    istringstream iss(postfixExpression);
    string next;
    while(iss >> next){
        if(isdigit(next.at(0))){
            success = 1;
            for (int i = 0; i < next.size(); ++i){
                if(!isdigit(next.at(i))){
                    success = 0;
                    break;
                }
            }
            if(success == 1){
                myStack.push(next);
            }
        }
        else if (myStack.size() >= 2) {
            
            operandTwo = myStack.top();
            myStack.pop();
            
            operandOne = myStack.top();
            myStack.pop();
            myEquation = "( " + operandOne + " " + next + " " + operandTwo + " )";
            
            myStack.push(myEquation);


        }
        else{
            //Invalid
            myStack.push("error");
            myStack.push("error");
            break;
        }
            
    }
    if(myStack.size() != 1){
        return "invalid";
    }
    else{
        return myStack.top();
    }
        
}

int ExpressionManager::getPrecedence(string myOperator){
    int precedence;
    if((myOperator == ")") || (myOperator == "]") || (myOperator == "}")){
        precedence = 3;
    }
    else if((myOperator == "*") || (myOperator == "/") || (myOperator == "%")){
        precedence = 2;
    }
    else if((myOperator == "+") || (myOperator == "-")){
        precedence = 1;
    }
    else if((myOperator == "(") || (myOperator == "[") || (myOperator == "{")){
        precedence = 0;
    }
    else{
        precedence = 5;
    }
    return precedence;
}

bool ExpressionManager::process_operator(stack<string> &opStack, string &postfix, string &op) {

    if((opStack.empty()) || (opStack.top() == "(") || (op == "(")){
        opStack.push(op);
        return 1;
    }
    else if(getPrecedence(op) == 3){
        while(getPrecedence(opStack.top()) != 0){
            postfix = postfix + opStack.top() + " ";
            opStack.pop();
            
            if(opStack.empty()){
                return 0;
                break;
            }
        }
        opStack.pop();
        return 1;
    }
    else{
        while(getPrecedence(op) <= getPrecedence(opStack.top())){
            postfix = postfix + opStack.top() + " ";
            opStack.pop();
            if(opStack.empty()){
                break;
            }
        }
        opStack.push(op);
        return 1;
    }    
}


string ExpressionManager::infixToPostfix(string infixExpression){
    stack<string> opStack;
    bool success = 1;
    string postfix = "";
    int testOperand = 0;
    int testOperator = 0;
    
    istringstream iss(infixExpression);
    string op;
    while(iss >> op){
        if(isdigit(op.at(0))){
            success = 1;
            for(int i = 0; i < op.size(); ++i){
                if(!isdigit(op.at(i))){
                    success = 0;
                    break;
                }
            }
            postfix = postfix + op + " ";
        }
        else{
            if((!process_operator(opStack, postfix, op)) || (getPrecedence(op) == 5)){
                //invalid
                success = 0;
                break;
            }
        }
            
    }
    while(!opStack.empty()){
        postfix = postfix + opStack.top() + " ";
        opStack.pop();
    }
    // Another test is to see if there are more operators than operands
    for(int i = 0; i < postfix.size(); ++i){
        if((getPrecedence(string(1,postfix.at(i))) == 3) || (getPrecedence(string(1,postfix.at(i))) == 0)){
            success = 0;
            break;
        }
        if(isdigit(postfix.at(i))){
            testOperand = testOperand + 1;
        }
        if((getPrecedence(string(1,postfix.at(i))) == 1) || (getPrecedence(string(1,postfix.at(i))) == 2)){
            testOperator = testOperator + 1;
        }
        if(testOperator >= testOperand){
            success = 0;
        }
        
    }

    if(postfixEvaluate(postfix) == "invalid"){
        success = 0;
    }
    
    if(success == 1){
        cout << "infixToPostfix " << infixExpression << endl;
        return postfix;
    }
    else{
        return "invalid";
    }
}

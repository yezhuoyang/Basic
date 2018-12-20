/*
 * File: statement.cpp
 * -------------------
 * This file implements the constructor and destructor for
 * the Statement class itself.  Your implementation must do
 * the same for the subclasses you define for each of the
 * BASIC statements.
 */

#include <string>
#include "statement.h"
#include "../StanfordCPPLib/tokenscanner.h"
#include "../StanfordCPPLib/simpio.h"
/* Implementation of the Statement class */

Statement::Statement() { 
   /* Empty */
}

Statement::~Statement() {
   delete exp;
}

void Statement::execute(EvalState  &state){
}


Comment::Comment(){}

StatementType Comment::getType(){
    return COMMENT;
}

Assignment::Assignment(Expression *expr){exp=expr;}

StatementType Assignment::getType(){
    return ASSIGNMENT;
}

void Assignment::execute(EvalState  &state){
    exp->eval(state);
}

Print::Print(Expression *expr){exp=expr;}


StatementType Print::getType(){
    return PRINT;
}

void Print::execute(EvalState  &state){
    std::cout<<exp->eval(state)<<std::endl;
}

Input::Input(string var):var(var){}


StatementType Input::getType(){
    return INPUT;
}

void Input::execute(EvalState  &state){
    int value;
    std::cout<<"? ";
    TokenScanner scanner;
    scanner.ignoreWhitespace();
    scanner.setInput(getLine());
    scanner.scanNumbers();
    string token = scanner.nextToken();
    TokenType type = scanner.getTokenType(token);
    if(type!=NUMBER||scanner.hasMoreTokens()){
        error("INVALID NUMBER");
    }
    value=stringToInteger(token);
    state.setValue(var, value);
}


StatementType End::getType(){
    return END;
}


End::End(){}

void End::execute(EvalState  &state){
    state.quit=true;
}

Goto::Goto(const int& linenum){linenumber=linenum;}

StatementType Goto::getType(){
    return GOTO;
}

If::If(const int& linenumbe,Expression *expr){linenumber=linenumbe;exp=expr;}


StatementType If::getType(){
    return IF;
}

Run::Run(){}

StatementType Run::getType(){
    return RUN;
}

List::List(){}

StatementType List::getType(){
    return LIST;
}

Clear::Clear(){}

StatementType Clear::getType(){
    return CLEAR;
}

Quit::Quit(){}

StatementType Quit::getType(){
    return QUIT;
}

Help::Help(){}

StatementType Help::getType(){
    return HELP;
}


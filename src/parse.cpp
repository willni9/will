#include <iostream>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include "base.h"
#include "command.h"
#include "parse.h"

using namespace std;

class Base;
class Command;

class Parse::operationening(){
	root->execute;
}

Base *Parse::parsing(string &str){
	string temp = " ";
  string cmd = "";
  stack<string> counter;
  stack<string> operationeration;

	bool cmd = false;	
	bool quote = false;
  bool bracket = false;
 
  for(unsigned i = 0; i < str.size(); ++i) {
    if(str.at(i) == '\"') {
      quote = true;
    }

    if(!quote) {
      if (str.at(i) == '(') {
        pcounter.push("(");
      }
    }
  }
	
  quote = false;

	stringstream ss(str);
	while(ss >> temp){
		if(!quote && temp.at(0) == '#'){
			break;
		}	
	}

  if(temp.at(0) == '\"') {
    quote = true;  
  }
  
  if(temp == "("){
    operationeration.push(temp);
  }else if(temp.at(0) == "("){
    string paren = "(";
    int index = 0;
    for(unsigned i = 0; i < temp.size; ++i){
      if(temp.at(i) == "("){
      operation.push(paran);
      }else{
      index = i;
      break;
      }
      cmd = cmd + temp.substr(index, temp.size() - 1);
  }
  
  if(temp.find(')') != string::npos) {
      paren = true;
      int count = 0;

      for(unsigned i = 0; i < temp.size(); ++i) {
        if(temp.at(i) == ')'){
          count++;
      }
  }
      
  if(quote){
    cmd = cmd + " " + temp.substr(0, temp.find('\"'));
  }else{
    cmd = cmd + " " + temp.substr(0, temp.find(')'));
  }
  
        while (!operation.empty() && !pcounter.empty() && (operation.toperation() != "(")) {
        if (command != "") {
          argVec.push_back(command);
          command = "";
        }

        argVec.push_back(operation.toperation());
        operation.poperation();

        if (operation.toperation() == "(" && count != 1) {
          operation.poperation();
          pcounter.poperation();
          count--;
        }
      }

      if ((operation.toperation() == "(") && !(operation.empty()) && !pcounter.empty()) {
        operation.poperation();
        pcounter.poperation();

        if (!(operation.empty())) {
        }
      }
    }

    if (temp.at(0) != '(' && temp.at(temp.size() - 1) != ')') {
        if (quote) {
          if (temp.at(0) == '\"') {
            temp = temp.substr(1, temp.size() - 1);
          }
          command = command + " " + temp;

          if (command.find('\"') != string::npos) {
            command = command.substr(0, command.find('\"'));
            quote = false;
          }
        } else {
          if (command == "") {
            command = command + temp;

          } else {
            command = command + " " + temp;
          }
        }
      }
    }
  }

  if (!bracket) {
    argVec.push_back(command);
    command = "";
  }

  if (command != "") {
    argVec.push_back(command);
    command = "";
  }

  while (!(operation.empty())) {
    if (operation.toperation() != "(") {
      argVec.push_back(operation.toperation());
      operation.poperation();
    } else {
      operation.poperation();
    }
  }
  
}
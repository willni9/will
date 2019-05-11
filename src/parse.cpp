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

class Parse::opening(){
	root->execute;
}

Base *Parse::parsing(string &str){
	string temp = " ";
  string cmd = "";
  stack<string> counter;
  stack<string> op;

	bool cmd = false;	
	bool quote = false;
  bool paren = false;
 
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
    op.push(temp);
  }else if(temp.at(0) == "("){
    string paren = "(";
    int index = 0;
    for(unsigned i = 0; i < temp.size; ++i){
      if(temp.at(i) == "("){
      op.push(paran);
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
      
}

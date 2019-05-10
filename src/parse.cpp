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

class Parse::opening(){
	root->execute;
}

Base *Parse::parsing(string &str){
	string temp = " ";
	bool cmd = false;	
	bool quote = false;
	
	stringstream ss(str);
	while(ss >> temp){
		if(!quote && temp.at(0) == '#'){
			break;
		}	
	}
}

#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fstream>
#include <iostream>
#include <queue>
#include <sstream>
#include <string>
#include <stack>
#include <vector>
#include <limits>
#include "base.h"
#include "command.h"
#include "connector.h"
#include "and.h"
#include "or.h"
#include "semicolon.h"
#include "rshell.h"


using namespace std;

class Base;
class Command;
class Parse;

void rShell::Display(){
	cout << "$ ";
}

void rShell::run_execute(){
  root->execute();
}



void rShell::the_input(){
   std::getline(std::cin, theinput);
}

void rShell::parse()
{
   note();
   temp = "";
   arg.clear(); 
   string rest_input = theinput;
   int index = find_connector(rest_input);
   string connector = "";
 
   while (index != -1) {
	cout << "in while" << endl;
	cout << "index: " << index << endl; 
	arg.push_back(rest_input.substr(0,index));
	rest_input = rest_input.substr(index);
	if (rest_input[0] == ';')
	{
		arg.push_back(rest_input.substr(0,1));
		rest_input = rest_input.substr(1);
	}
	else 
	{
        	arg.push_back(rest_input.substr(0,2));
		rest_input = rest_input.substr(2);
	}
        index = find_connector(rest_input);
   } 
   if (rest_input != "")	arg.push_back(rest_input);
   
   unsigned int size = arg.size();
   vector<string> vec1;
   vector<string> vec2;
   for (unsigned int i = 0; i < size; ++i) {
	if ( is_connector(arg[i])) {
		while(!vec1.empty()) {
			vec2.push_back(vec1.back());
			vec1.pop_back();
		}
		vec1.push_back(arg[i]);
		while(!vec2.empty()){
			vec1.push_back(vec2.back());
			vec2.pop_back();
		}	
	}	
	else {
		vec1.push_back(arg[i]);
	}
   }
   arg = vec1;
   reverse(arg.begin(), arg.end());
}
Base* rShell::build_tree()
{
	string temp = arg.back();
	Base *result;
	arg.pop_back();
	if(is_connector(temp)) {
		Connector *r;
		if (temp == "&&")
		{
			r = new And();
		}
		else if (temp == "||")
		{
			r = new Or();
		}
		else if (temp == ";")
		{
			r = new Semicolon();
		}
		else {}
		
		r->left = build_tree();
		r->right = build_tree();
		result = r;
	}
	else {
		Command *c = new Command(temp);
		result = c;
	}
	return result;
}

void rShell::build_tree_helper()
{
	this->root = build_tree();	
}

int rShell::find_connector(string input) {
	int in1, in2, in3, index, max;
	max = numeric_limits<int>::max();
	in1 = input.find("&&");
	if (in1 == -1)
		in1 = max;
	in2 = input.find("||");
	if (in2 == -1)
		in2 = max;
	in3 = input.find(";");
	if (in3 == -1)
		in3 = max;
	index = min(in1, min(in2, in3));	
	if (index == max) {
		return -1;
	}
	else {
		return index;
	}
}



void rShell::note()
{
   for (size_t i = 0; i < theinput.size(); i++) {
      if (theinput[i] == '"') {
         while (theinput[++i] != '"') {}
      }
        
      if (theinput[i] == '#') {
         theinput.erase(theinput.begin() + i, theinput.end());
         break;
      }
        
      if (theinput[i] == '(') {
         theinput.insert(i + 1, " ");
         i++;
      }
        
      if (theinput[i] == ')' || theinput[i] == ';') {
         theinput.insert(i, " ");
         i++;
      }
   }
}


Base* rShell::Tree(){
	int index = 0;
	root = new Command(arg[0]);
}


bool rShell::is_connector(string input) 
{
	bool result = false;
	if (input == "&&") 
	{
		result = true;
	}
	else if (input == "||") 
	{
		result = true;
	}
	else if (input == ";") 
	{
		result = true;	
	}
	return result;

}

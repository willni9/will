#include <stdio.h>
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

/*void rShell::Display(){
	cout << "$ ";
}*/

void rShell::run_execute(){
  root->execute();
}



void rShell::the_input(){
   std::getline(std::cin, theinput);
/*   while(theinput != "exit"){
        Display(); 
        getline(cin, theinput);
        cout<<endl;
        if(theinput =="exit"){
        break;
    }
  }
*/
}

void rShell::parse()
{
   note();
   temp = "";
    
   for (size_t i = 0; i < theinput.size(); i++) {
      if (theinput[i] == '"') {
         while (true) {
            if (theinput[++i] == '"') {
               if (i == theinput.size() - 1) {
                  arg.push_back(temp);
                  return;
               }
               i++;
               break;
            }
            temp += theinput[i];
         }
      }
        
      if (theinput[i] != ' ') {
         temp += theinput[i];
      }
      else {
         arg.push_back(temp);
         temp = "";
      }
        
      if (i == theinput.size() - 1) {
         arg.push_back(temp);
      }
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


//maybe can use for next?
/*Base* rShell::Tree(){
	Base* root;
	Base* next;
	
	while (List < vect.size()){
		if (!root){
			if (vect[List] == "(" ) {
				List++;
				root = Tree();
			}
		} else {
			std::string connector = vect[List];
			if (connector == ")" ) {
				List++;
				return root;
			}
			List++;
			if (vect[List] == "(" ){
				List++;
				next = Tree();
			}
			
			if (connector == "||"){
				root = new Or(root, next);
		        }else if (connector == "&&") {
            			root = new And(root, next);
         		}else if (connector == ";") {
            			root = new Semicolon(root, next);
        }		
      }
   }
   return root;
}*/



/*Base* rShell::get_command()
{
   std::vector<std::string> com_command_line;
   Base* com;
   while (index < vect.size()) {
      if (vect[index] == "&&" || vect[index] == "||" || vect[index] == ";" || vect[index] == ")") {
         com = new Command(com_command_line);
         return com;
      }
      else {
         com_command_line.push_back(vect[index]);
      }
      index++;
   }
   com = new Command(com_command_line);
   return com;
}*/

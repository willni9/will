#include "rshell.h"
#include "parse.h"
#include "semicolon.h"
#include "or.h"
#include "connector.h"
#include "and.h"
#include "command.h"
#include "base.h"
#include "iostream"

rShell::rShell(){}

void rShell::Display(){
	cout << "$ ";
}

Base* rShell::Tree(){
	Base* root;
	Base* next;
	
	while (List < vector.size()){
		if (!root){
			if (vector[List] == "(" ) {
				List++;
				root = Tree();
			}
		} else {
			std::string connector = vector[List];
			if (connector == ")" ) {
				List++;
				return root;
			}
			List++;
			if (vector[List] == "(" ){
				List++;
				next = Tree;
			}
			
			if (connector == "||"){
				root = new And(root, next);
		        }else if (connector == "||") {
            			root = new Or(root, next);
         		}else if (connector == ";") {
            			root = new Semicolon(root, next);
        }		
      }
   }
   return root;
}


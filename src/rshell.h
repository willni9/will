#ifndef RSHELL_H
#define RSHELL_H
#include "base.h"
#include "and.h"
#include "or.h"
#include "semicolon.h"
#include "connector.h"
#include "command.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class rShell{
  protected:
    Base *root;
    vector<string> arg;

	public:
    std::string theinput;
		rShell(){}
		Base* Tree();
		std::string get_vect(int);
		void Display(); 
    void run_execute();
    void the_input();
    void run_tree();
    void note();
    void parse();
    void get_command();
    void input_preparation();
    void set_input(std::string);  
  private:
     std::string temp;
     int List;
     std::vector<std::string> vect;
};

#endif

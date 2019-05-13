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
  public:
    Base *root;
    vector<string> arg;
    std::string theinput;
    rShell(){}
    Base* Tree();
    std::string get_vect(int);
    void Display(); 
    void run_execute();
    void the_input();
   // void run_tree();
    void note();
    void parse();
    void get_command();
    void input_preparation();
    void set_input(std::string);
    void build_tree_helper();
    Base* build_tree();
    int find_connector(string input);
    bool is_connector(string input);
  private:
     std::string temp;
     int List;
     std::vector<std::string> vect;
};

#endif

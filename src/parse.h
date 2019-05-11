#ifndef PARSE_H
#define PARSE_H
#include <iostream>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class Base;

class Parse{
	protected:
		Base *root;
		string opcmd;
    vector<string> arg;


	public:
		Parse():root(0){}
		Parse(string &opcmd):opcmd(opcmd){}
		void open();
		Base *parsing(string &);
};

#endif

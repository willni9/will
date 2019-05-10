#ifndef PARSE_H
#define PARSE_H
#include <string>
#include <vector>

using namespace std;

class Base;

class Parse{
	protected:
		Base *root;
		string opcmd;
		vector<string> avec;
	public:
		Parse():root(0){}
		Parse(string &opcmd): opcmd(opcmd){}
		Base *parsing(string &);
};

#endif

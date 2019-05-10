#ifndef BASE_H
#define BASE_H
#include <string>
#include "base.h"

using namespace std;

class Command:public Base{
	protected:
		string cmd;
	public:
		Command(){};
		Command(string &cmd):cmd(cmd){};
		virtual bool execute();
		string get_cmd(){
			return cmd;
	}
};

#endif

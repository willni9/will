#ifndef _COMMAND_H_
#define _COMMAND_H_
#include <string>
#include "base.h"

using namespace std;

class Command : public Base {
	protected:
		string cmd;
	public:
		Command(){}
		Command(string cmd) : cmd(cmd) {}
	  bool execute();
		string get_cmd(){
			return cmd;
		}
};

#endif

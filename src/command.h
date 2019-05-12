#ifndef COMMAND_H
#define COMMAND_H
#include <string>
#include "base.h"

using namespace std;

class Command : public Base {
	protected:
		string cmd;
	public:
		Command(){}
		Command(string cmd) : cmd(cmd) {}
		bool execute(){
			return true;
		}
		string get_cmd(){
			return cmd;
		}
};

#endif

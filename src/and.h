#ifndef AND_H
#define AND_H
#include "connector.h"
#include "base.h"
using namespace std;
class And : public Connector{

public:
And(){}
And(Base*left, Base* right): Connector(left,right){}

bool execute()
{
	if(left->execute()){
		return right->execute();
	}
	return false;
}

string get_cmd()
{
	return "";
}

};
#endif

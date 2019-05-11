#ifndef AND_H
#define AND_H
#include "connector.h"

using namespace std;
class And : public Connector{
And(){}
And:And(Base*left, Base* right): Connector(l,r){}

bool isConnector()
{
	return true;
}

bool execute()
{
	if(left->execute()){
	return right->execute()
}
	return false;
}

	string get_cmd()
{
	return "";}

#endif

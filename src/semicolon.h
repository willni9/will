#ifndef SEMICOLON_H
#define SEMICOLON_H
#include "base.h"
#include "connector.h"
using namespace std;


class Semicolon :public Connector
{
public:
Semicolon(){}
Semicolon(Base*left, Base*right):Connector(left,right){}

bool execute()
{
	left->execute();
	return right->execute();
}

string get_cmd()
{	
 	return "";
}
};
#endif

#ifndef SEMICOLON_H
#define SEMICOLON_H

#include "connector.h"
using namespace srd;

class Semicolon :public Connector
{
 public:
Semicolon()
{}
Semicolon::Semicolon(Base*left, Base*right):Connector(left,right)
{}

bool isConnector()
{
	return true;}

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

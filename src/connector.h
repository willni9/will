#ifndef CONNECTOR_H
#define CONNECTOR_H
#include "base.h"
#include "command.h"

using namespace std;

class Connector : public Base
{
public:
Base* left; 
Base* right;
Connector(){}
Connector(Base* left, Base*right):left(left), right(right){}

virtual bool execute() = 0;
virtual string get_cmd() = 0;
};
#endif


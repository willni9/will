#ifndef CONNECTOR_H
#define CONNECTOR_H
#include "command.h"
#include "base.h"

using namespace std;

class Connector : public Base
{
protected:
 Base* left; 
 Base* right;

public:
Connector();
Connector(Base* left, Base*right):left(left), right(right){}

virtual bool execute() = 0;
virtual string get_cmd() = 0;
};
#endif


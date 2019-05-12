#ifndef CONNECTOR_H
#define CONNECTOR_H

#include "base.h"

using namespace std;

class Connector : public Base()
{
protected:
 Base* left; 
 Base* right;

public:
Connector();
Connector(Base* left, Base*right);

virtual bool execute() = 0;
virtual string get_cmd() = 0;
virtual bool IsConnector() = 0;
};
#endif


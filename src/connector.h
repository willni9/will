#ifndef CONNECTOR_H
#define CONNECOTR_H

#include "base.h"

using namespace std;

class Connector : public Base()
{
protected:
 Base* l; 
 Base* r;

public:

nnector(): l(0), r(0){};

virtual bool execute() = 0;
virtual string get_cmd() = 0;
virtual bool IsConnector() = 0;

#endif


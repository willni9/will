#ifndef OR_H
#define OR_H
#include "connector.h"
#include "base.h"

using namespace std;

class Or: public Connector{
public:
Or(){}
Or(Base* left,Base* right): Connector(left,right){}

bool execute()
  {
    return (left->execute())||(right->execute());
  }
  
string get_cmd()
{	
 	return "";
}
};
#endif

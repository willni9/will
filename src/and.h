#ifndef AND_H
#define AND_H
#include "connector.h"

using namespace std;
class And : public Connector{
And(){}
bool isConnector(){
return true;
}
bool execute(){
if(l->execute()){
return r->execute()
}
return false;
}

string get_cmd(){
return "";}

#endif

#ifndef SEMICOLON_H
#define SEMICOLON_H

#unclude "connector.h"
using namespace srd;

class Semicolon :public Connector{
        public:
        Semicolon(){}
bool isConnector(){
return true;}

bool execute(){
l->execute();
r->execute();
}
string get_cmd()
{ return "";}
#endif

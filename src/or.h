#ifndef OR_H
#define OR_H
#include "connector.h"
using namespace std;
class Or: public Connect{
public:
Or(){}
bool isConnecotr(){
return true;
}
bool execute(){
if(!(l->execute()){
return r->execute();
}
string get_cmd(){
return ""}

#endif

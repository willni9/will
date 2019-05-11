#ifndef OR_H
#define OR_H
#include "connector.h"
using namespace std;
class Or: public Connect{
public:

Or()
{}
Or::Or(Base* left,base* right): Connector(left,right)
{}

bool isConnecotr()
{
return true;
}
bool execute()
{
if(!(left->execute())
{
return right->execute();
}
string get_cmd()
{
return ""}

#ndif

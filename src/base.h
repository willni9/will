#ifndef BASE_H
#define BASE_H

#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

class Base{
	private : 

	public:
		Base(){};
		virtual void setBase(Base*, Base*) = 0;
		virtual bool execute() = 0;
		virtual string get_cmd() = 0;
		virtual bool isConnector() = 0;
		
};

#endif

#ifndef BASE_H
#define BASE_H

#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

class Base{
	public:
		Base(){};
		
		virtual bool execute() = 0;
		virtual string get_commit() = 0;
}

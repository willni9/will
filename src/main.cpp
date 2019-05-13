#include <iostream>
#include <string>
#include "rshell.h"
#include "base.h"

using namespace std;

int main()
{
  	rShell rShell;
 	string theinput;
	while(theinput != "exit")
	{	
        	rShell.Display();
        	rShell.the_input();
        	if(theinput =="exit")
    		{
        		break;
    		}
        	rShell.parse();
       		rShell.build_tree_helper();
        	rShell.run_execute();
  	}  
	return 0 ;
}

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fstream>
#include <iostream>
#include <string>
#include <sys/wait.h>
#include <signal.h>
#include <stdlib.h>
#include "base.h"
#include "command.h"

using namespace std;

class Base;
class Command;

bool Command::execute(){
	int status;
	pid_t adjust  = fork();
	
	if(adjust == -1){
		perror("fork");
		exit(1);
	}

	if(adjust == 0){
		perror("exe");
		exit(1);
	}

	if(adjust > 0){
		waitpid(adjust, &status, 0);
		ifWEITSTATUS(status) > 0){
			return false;
		}else if(WEXITSTATUS(status) == 1){
			return false;
		}else if(WEXITSTUTAS(status) == 0){
			return true;
		}
	}
	return false:
}

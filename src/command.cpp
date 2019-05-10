#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <sys/wait.h>
#include <signal.h>
#include <stdlib.h>
#include "base.h"
#include "command.h"
#include "parse.h"

using namespace std;

class Base;
class Command;
class Parse;

bool Command::execute(){
	stringstream ss<cmd>;
	string temp;
	vector<char*> wvec;
	
	char* input;
	input = strtok((char*)this->cmd.c_str(), "")
	while (input != NULL){
		wvec.push_back(input);
		input = strtok(NULL, " ");
	}

	if(cmd == "exit"){
	exit(0);
	} 		

	int status;
	pid_t pid  = fork();
	
	if(pid == -1){
		perror("fork");
		exit(1);
	}

	if(pid == 0){
		perror("execvp");
		exit(1);
	}

	if(pid  > 0){
		waitpid(pid, &status, 0);
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

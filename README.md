# CS 100 Programming Project 
# Project Information: CS100 RShell, Jianbin Li, 862074304  Weier Ni,   862019075

# Introduction:
For this program, it should be able to output the command prompt properly, whichis followed by a short description. the project should be able to run the command( fork, execvp, waitpid) properly, project should be able to connect multiple commends by using connectors(||,&&,;) we will be using composite design pattern on this project to combine between unit tests and classes.
# Diagram:
    ![UML] (https://github.com/cs100/spring_2019_assignment_cs100_w_j/blob/master/images/Design%20document.png?raw=true)


# classes:
* main class
 * we will compute the test, then execute an fully functionality example, combine classes in the main and then execute an lab.exe file
* commend class
 * this class, we will focus on the three commends to execute files
  * subclass 1: execvp(), duplicate the actions of the shell in searching for an executable file if the specific filename does not contain slash character.
  * subclass 2: fork(), creating a new process which will execute untill terminates.
  * subclass 3: waitpid (), calling process until a specifc process terminates, when the process ends, the process is stored in the location pointed to by satusPtr and the calling process resume execution.
* connector class
 * this class will contain three sub class, and or, and semiclone
  * subclass 1: and: in order to let next commend to be executed, the first commend must success.  	
  * subclass 2: or : in order to let next commend to be executed, the first commend must fail.
  * subclass 3: semiclone: no matter the first commend is executed or not, the next commend will always be executed. 
* unit test class 
 * this class is for test each function works properly or not, and also test after these classes interact correctly or not.

# Prototypes/Reasearch: 
* Execvp
```c++
	 int main(int argc, char * argv[]){
	char * ls_args[] = { "ls" , "-l", NULL};
	execvp(   ls_args[0],     ls_args);

	perror("execv");
	return 2;
	};
```	
* we will test this function, if this function searching a correct executable file or not, and we will test this commend is followed by multiple other commend, to test if it works properly or not. 


* Fork
```c++
   	int main(){
	pid_t c_pid;
	c_pid = fork();
	if(c_pid == 0){
	printf("Child: %d", c_pid);
	}else if(c_pid > 0){
		printf("Parent: %d", c_pid);
	}else{
		perror(fork failed");
		_exit(2);
	}
	return 0;
	}
```	
* we will test function if this function returns properly or not, if the process returns 0, is is in child process, if it returns greater than 0, then it is in parent process, if it returns -1, then it is fail. and we create a wait function to test if it is in child process or turn in to zombie. Notes:cannot write fork function into loops
* Pid
```c++
    	int main(){
	pid_t c_pid;
	pid = getpid();
	ppid = getppid();
	
	printf("Pid is %d", pid);
	printf("Parent's pid is	%d", ppid);
	
	return 0;
	}
```
* if function tests pass, waitpid returns the process ID of the terminated process whose status was reported. if unsuccessful, a -1 is returned.
# Development and Testing Roadmap
 1. connector class implementation, each function will be separated, and test separatedly, then test after comine them into on single class. 
  1. subclass 1, and function implementation 
	1. includes unit test function
  2. subclass 2, or function implementation
	1. includes unit test function 
  3. subclass 3, semiclone class implementation
	1. includes unit test function
 2. commend class implementation, each commend will be implemented, to ensure each commend execute file correctly, and also each commend function call will be tested.
  1. execvp(), ensure function called and execute file
  	1. includes unit test function 
  2. fork(), ensure function called and execute file
  	1. includes unit test function
  3. waitpid(), ensure function called and execute file
	1. includes unit test function 
 3.  unit test class implementation, test each function works properly. combine all the unit test, and put into a class called unit test class, each time when we test a function, and connect function to this class. 



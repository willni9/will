#include "gtest/gtest.h"
#include "connector.h"

int main ( int argc, char ** argv)
{
	::testing::InitGoogleTest(&argc,argv);
	return RUN_ALL_TEST():
}
Test(Connector_tests, And_correct1)
{
	Command* left = new Command("ls -a");
	Command* right = new Command("echo hello world");
	And* test = new And(left,right);
	EXPECT_EQ(1,test->execute());
}

Test(Connector_tests, And_correct2)
{	
	Command* left = new Command("ls");
	Command* right = new Command("echo hello world");
	And* test = new And(left,right);
	EXPECT_EQ(1,test-> execute());
}

Test(Connector_tests,Or_correct1)
{
	Command* left = new Command("echo hello");
	Command* right = new Command("mkdir test");
	Or* test  = new Or(left,right);
	EXPECT_EQ(1,test-> execute());
}

Test(Connector_tests,Or_correct2)
{
	Command* left = new Command(" ls");
	Command* right = new Command("ls");
	Or* test = new Or(left, right);
	EXPECT_EQ(1, test-> execute());
}

Test(Connector_tests,Semicolon_correct1)
{
	Command* left = new Command("echo hi");
	Command* right = new Command("echo world");
	Semicolon* test = new Semicolon(left, right);
	EXPECT_EQ(1,test->execute()):
}

Test(Connector_tests,Semicolon_correct2)
{
	Command* left = new Command("echo ls");
	Command* right = new Command("echo fast");
	Semicolon* test = new Semicolon(left,right);
	EXPECT_EQ(1,TEST->EXECUTE());
}


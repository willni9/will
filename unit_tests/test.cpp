#include "gtest/gtest.h"
#include "../src/connector.h"
#include "../src/command.h"
#include "../src/parse.h"
#include "../src/and.h"
#include "../src/or.h"
#include "../src/semicolon.h"
#include "../src/base.h"

TEST(TestCommand, LsCommand) {
  string s1 = "ls -a";
  Command *test1 = new Command(s1);
  EXPECT_TRUE(test1->execute());
}

TEST(TestCommand, ExitCommand) {
  string s1 = "exit";
  Command *test1 = new Command(s1);
  EXPECT_TRUE(test1->execute());
}

TEST(TestCommand, SimpleCommand) {
  string testing = "test -d src";  
  Command *test = new Command(testing);
  EXPECT_TRUE(test->execute());
}

TEST(Connector_tests, And_correct1)
{
	Base* left = new Command("ls -a");
	Base* right = new Command("echo hello world");
	Base* test = new And(left,right);
	EXPECT_EQ(1,test->execute());
}

TEST(Connector_tests, And_correct2)
{	
	Base* left = new Command("ls");
	Base* right = new Command("echo hello world");
	Base* test = new And(left,right);
	EXPECT_EQ(1,test-> execute());
}

TEST(Connector_tests,Or_correct1)
{
	Base* left = new Command("echo hello");
	Base* right = new Command("mkdir test");
	Base* test  = new Or(left,right);
	EXPECT_EQ(1,test-> execute());
}

TEST(Connector_tests,Or_correct2)
{
	Base* left = new Command(" ls");
	Base* right = new Command("ls");
	Base* test = new Or(left, right);
	EXPECT_EQ(1, test-> execute());
}

TEST(Connector_tests,Semicolon_correct1)
{
	Base* left = new Command("echo hi");
	Base* right = new Command("echo world");
	Base* test = new Semicolon(left, right);
	EXPECT_EQ(1,test->execute());
}

TEST(Connector_tests,Semicolon_correct2)
{
	Base* left = new Command("echo ls");
	Base* right = new Command("echo fast");
	Base* test = new Semicolon(left,right);
	EXPECT_EQ(1,test->execute());
}

int main ( int argc, char ** argv)
{
	::testing::InitGoogleTest(&argc,argv);
	return RUN_ALL_TESTS();
}

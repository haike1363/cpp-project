#include "google_lib.hpp"
#include "../../include/say_hello.h"

class SayHelloTest : public testing::Test {

};

TEST_F(SayHelloTest, sayHello)
{
	SayHello();
}

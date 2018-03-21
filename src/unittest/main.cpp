#include "google_lib.hpp"

class UnittestEnvironment: public testing::Environment {
public:
    virtual void SetUp() {
    }
    virtual void TearDown() {
    }
};

int main(int argc, char **argv) {
    InitGoogle(argc, argv);
    testing::AddGlobalTestEnvironment(new UnittestEnvironment);
    int ret = RUN_ALL_TESTS();
    UninitGoogle();
    return ret;
}

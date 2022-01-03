#include "gtest/gtest.h"
#include "logs.h"

class LOG_UNITTEST : public ::testing::Test{
	protected:
		virtual void SetUp(){
		}
		virtual void TearDown(){
		}
};

// Not sure that we need to test this at all. Not sure why this is here.\
// I guess just that we can include it.
TEST_F(LOG_UNITTEST, LOG_INIT){
	ASSERT_EQ(1,1);
}

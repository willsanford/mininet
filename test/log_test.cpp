#include "gtest/gtest.h"
#include "logs.h"

class LOG_UNITTEST : public ::testing::Test{
	protected:
		virtual void SetUp(){
		}
		virtual void TearDown(){
		}
};

TEST_F(LOG_UNITTEST, LOG_INIT){
	ASSERT_EQ(1,1);
}

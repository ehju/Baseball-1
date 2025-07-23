#include "gmock/gmock.h"
#include "baseball.cpp"

class BaseballFixture : public testing::Test {
public:
	Baseball game{ "123" };
	void assertIlligalArgument(string guessNumber) {
		try {
			game.guess(guessNumber);
			FAIL();
		}
		catch (exception e) {
			// PASS
		}
	}
};

TEST_F(BaseballFixture, ThrowExceptionWhenInvalidCase) {
	assertIlligalArgument("12");
	assertIlligalArgument("12s");
	assertIlligalArgument("121");
}
TEST_F(BaseballFixture, ReturnSolvedResultIfMatchedNumber) {
	GuessResult result = game.guess("123");
	EXPECT_TRUE(result.solved);
	EXPECT_EQ(3, result.strikes);
	EXPECT_EQ(0, result.balls);
}
TEST_F(BaseballFixture, TwoStrikeNoBallTest) {
	GuessResult result = game.guess("129");
	EXPECT_FALSE(result.solved);
	EXPECT_EQ(2, result.strikes);
	EXPECT_EQ(0, result.balls);
}
TEST_F(BaseballFixture, TwoStrikeNoBallTest2) {
	GuessResult result = game.guess("523");
	EXPECT_FALSE(result.solved);
	EXPECT_EQ(2, result.strikes);
	EXPECT_EQ(0, result.balls);
}
TEST_F(BaseballFixture, TwoStrikeNoBallTest3) {
	GuessResult result = game.guess("163");
	EXPECT_FALSE(result.solved);
	EXPECT_EQ(2, result.strikes);
	EXPECT_EQ(0, result.balls);
}

int main() {
	::testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}
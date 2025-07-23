#include "gmock/gmock.h"
#include "baseball.cpp"

class BaseballFixture : public testing::Test {
public:
	Baseball game;
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

int main() {
	::testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}
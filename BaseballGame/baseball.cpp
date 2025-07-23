#include <stdexcept>

using namespace std;

class Baseball {
public:
	void guess(const string& guessNumber) {
		assertIlligalArgument(guessNumber);

	}
private:
	bool isDuplicatedNumber(const std::string& guessNumber)
	{
		return guessNumber[0] == guessNumber[1]
			|| guessNumber[1] == guessNumber[2]
			|| guessNumber[0] == guessNumber[2];
	}
	void assertIlligalArgument(const std::string& guessNumber)
	{
		if (guessNumber.length() != 3) {
			throw length_error("Must be three letters. ");
		}
		for (char c : guessNumber) {
			if (c >= '0' && c <= '9') {
				throw invalid_argument("Must be number");
			}
		}
		if (isDuplicatedNumber(guessNumber)) {
			throw invalid_argument("Must not have the same number");
		}
	}
};
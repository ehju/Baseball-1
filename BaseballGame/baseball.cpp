#include <stdexcept>

using namespace std;

struct GuessResult {
	bool solved;
	int strikes;
	int balls;
};

class Baseball {
public:
	explicit Baseball(const string& question) : question(question) {}
	GuessResult guess(const string& guessNumber) {
		assertIlligalArgument(guessNumber);
		if (guessNumber == question) {
			return { true,3,0 };
		}
		else {
			if (ifFirstTwoCorrect(guessNumber)) {
				return { false, 2, 0 };
			}
			else {
				return { false,0,0 };
			}
		}
	}
	bool ifFirstTwoCorrect(const std::string& guessNumber)
	{
		return guessNumber[0] == question[0]
			&& guessNumber[1] == question[1]
			&& guessNumber[2] != question[2];
	}
private:
	string question;
	bool isDuplicatedNumber(const string& guessNumber)
	{
		return guessNumber[0] == guessNumber[1]
			|| guessNumber[1] == guessNumber[2]
			|| guessNumber[0] == guessNumber[2];
	}
	void assertIlligalArgument(const string& guessNumber)
	{
		if (guessNumber.length() != 3) {
			throw length_error("Must be three letters. ");
		}
		for (char ch : guessNumber) {
			if (ch >= '0' && ch <= '9')  continue;
			throw invalid_argument("Must be number");
		}
		if (isDuplicatedNumber(guessNumber)) {
			throw invalid_argument("Must not have the same number");
		}
	}
};
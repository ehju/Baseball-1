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
			return getSolvedResult();
		}
		else {
			return getUnsolvedResult(guessNumber);
		}
	}
private:
	string question;
	GuessResult getSolvedResult() {
		return {true, 3, 0};
	}
	GuessResult getUnsolvedResult(const string& guessNumber) {
		return {false,getStrikeCnt(guessNumber),getBallCnt(guessNumber) };
	}
	int getBallCnt(const string& guessNumber)
	{
		int ballcnt = 0;
		for (int i = 0; i < 3;i++) {
			for (int j = 0; j < 3;j++) {
				if ((i != j) && (guessNumber[i] == question[j]))
					ballcnt++;
			}
		}
		return ballcnt;
	}
	int getStrikeCnt(const string& guessNumber)
	{
		int strikecnt = 0;
		for (int i = 0;i < 3;i++) {
			if (guessNumber[i] == question[i])
				strikecnt++;
		}
		return strikecnt;
	}

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
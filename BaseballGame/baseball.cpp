#include <stdexcept>

using namespace std;

class Baseball {
public:
	void guess(const string& guessNumber) {
		if (guessNumber.length() != 3) {
			throw length_error("Must be three letters. ");
		}
		for (char c :guessNumber) {
			if (c < '0' || c >'9') {
				throw invalid_argument("Must be number");
			}
		}
	}
};
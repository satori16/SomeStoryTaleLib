#include "SomeStoryTaleLib.h"


bool TimedQuestion(const std::string S, const SomeStoryTaler::TimeType Time) {

	std::cout << S.c_str() << std::endl;

	std::this_thread::sleep_for(Time);


	return true;
}

bool WaitableQuestion(const std::string& S) {

	std::cout << S.c_str() << std::endl << "plz hit key." << std::endl;

	_getch();

	return true;

}

bool TimeWaiting(const SomeStoryTaler::TimeType Time) {

	std::this_thread::sleep_for(Time);
	return true;
}

bool NewLine() {
	std::cout << std::endl;

	return true;
}

bool SimpleQuestion(const std::string& S) {
	std::cout << S.c_str() << std::endl;

	return true;
}

int TimeoutInput(const SomeStoryTaler::TimeType Time) {
	std::this_thread::sleep_for(Time);

	return _getch_nolock();//‚Æ‚Á‚Ä‚àŠÂ‹«ˆË‘¶HH
}

int WaitingInput() {
	return _getch();
}
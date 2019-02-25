#pragma once

#include <iostream>
#include <chrono>
#include <thread>
#include <conio.h>//ŠÂ‹«ˆË‘¶

namespace SomeStoryTaler {
	typedef std::chrono::milliseconds TimeType;
}
namespace SomeStoryTaler {
	namespace Shower {
		bool TimedQuestion(const std::string S, const TimeType Time);
		bool WaitableQuestion(const std::string& S);
		bool SimpleQuestion(const std::string& S);
		bool NewLine();
	}
	namespace Waiter {
		bool TimeWaiting(const TimeType Time);
		int TimeoutInput(const TimeType Time);
		int WaitingInput();
	}
}



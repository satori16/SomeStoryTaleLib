#pragma once

#include <iostream>
#include <chrono>
#include <thread>
#include <string>
#include <conio.h>//環境依存

#include "WindowsSetting.h"//ウインドウズ用の設定？？

namespace SomeStoryTaler {
	typedef std::chrono::milliseconds TimeType;
	namespace Shower {

		//bool TimedQuestion(const std::string S, const SomeStoryTaler::TimeType Time) {
		bool Timed(const std::string S, const SomeStoryTaler::TimeType Time) {
			std::cout << S.c_str() << std::endl;

			std::this_thread::sleep_for(Time);


			return true;
		}

		//bool WaitableQuestion(const std::string& S) {
		bool Waitable(const std::string& S) {
			std::cout << S.c_str() << std::endl << "plz hit key." << std::endl;

			_getch();

			return true;

		}
		//bool SimpleQuestion(const std::string& S) {
		bool Simple(const std::string& S) {
			std::cout << S.c_str() << std::endl;

			return true;
		}
		bool NewLine() {
			std::cout << std::endl;

			return true;
		}
		bool CarriageReturn() {
			std::cout << '\r';
			return true;
		}
	}
	namespace Writer {
		bool MoveCursor(std::size_t X, std::size_t Y) {
			std::string P = "\x1b[" + std::to_string(Y) + ';' + std::to_string(X) + 'H';
			std::cout << P;
			return true;
		}
		bool WriteText(std::size_t X, std::size_t Y, char S) {
			std::string P = "\x1b[" + std::to_string(Y) + ';' + std::to_string(X) + 'H';
			std::cout << P << S;
			return true;
		}

		bool WriteText(std::size_t X, std::size_t Y, std::string S) {
			std::string P = "\x1b[" + std::to_string(Y) + ';' + std::to_string(X) + 'H';
			std::cout << P << S;
			return true;
		}
		bool WriteText(std::size_t X, std::size_t Y, std::int32_t S) {
			std::string P = "\x1b[" + std::to_string(Y) + ';' + std::to_string(X) + 'H';
			std::cout << P << S;
			return true;
		}
		bool ClearScreen() {
			std::cout << "\x1b[2J";
			return true;
		}
	}
	namespace Input {
		int WithTimeout(const SomeStoryTaler::TimeType Time) {//とっても環境依存？？
			std::this_thread::sleep_for(Time);

			if (_kbhit()) {
				return _getch();
			}
			return 0;
		}
		int GetKey() {
			if (_kbhit()) {
				return _getch();
			}

			return 0;
		}
	}
	namespace Waiter {
		bool TimeWaiter(const SomeStoryTaler::TimeType Time) {

			std::this_thread::sleep_for(Time);
			return true;
		}

		int InputWaiter() {
			return _getch();
		}

	}
}

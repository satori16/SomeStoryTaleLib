#pragma once

#include <iostream>
#include <chrono>
#include <thread>
#include <string>
#include <random>
#include <algorithm>
#include <numeric>
#include <conio.h>//環境依存

#include "StopWatch.h"
#include "WindowsSetting.h"//ウインドウズ用の設定？？

namespace SomeStoryTaler {
	typedef std::chrono::milliseconds TimeType;
	namespace Shower {
		bool ClearScreen() {//エスケープシーケンスが必要です。
			std::cout << "\x1b[2J";
			return true;
		}
		//bool TimedQuestion(const std::string S, const SomeStoryTaler::TimeType Time) {
		bool Timed(const std::string S, const SomeStoryTaler::TimeType Time) {
			std::cout << S.c_str() << std::endl;

			std::this_thread::sleep_for(Time);

			return true;
		}

		//bool WaitableQuestion(const std::string& S) {
		bool Waitable(const std::string& S) {
			std::cout << S.c_str()<< std::endl << std::endl << "plz hit key." << std::endl;

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
		}	namespace WithPosition {
		bool Cursor(std::size_t X, std::size_t Y) {
			std::string P = "\x1b[" + std::to_string(Y) + ';' + std::to_string(X) + 'H';
			std::cout << P;
			return true;
		}
		bool Character(std::size_t X, std::size_t Y, char ch) {
			std::string P = "\x1b[" + std::to_string(Y) + ';' + std::to_string(X) + 'H';
			std::cout << P << ch;
			return true;
		}
		bool Float(std::size_t X, std::size_t Y, double d) {
			std::string P = "\x1b[" + std::to_string(Y) + ';' + std::to_string(X) + 'H';
			std::cout << P << d;
			return true;
		}		
		bool Text(std::size_t X, std::size_t Y, std::string S) {
			std::string P = "\x1b[" + std::to_string(Y) + ';' + std::to_string(X) + 'H';
			std::cout << P << S;
			return true;
		}
		bool Number(std::size_t X, std::size_t Y, std::int32_t S) {
			std::string P = "\x1b[" + std::to_string(Y) + ';' + std::to_string(X) + 'H';
			std::cout << P << S;
			return true;
		}

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
		int TimeOuter(SomeStoryTaler::TimeType Time) {
			for (StopWatch SW; SW.Ellipse<>() < Time;) {
				std::this_thread::sleep_for(std::chrono::milliseconds(1));
				if (_kbhit()) {
					return _getch();
				}
			}
			return 0;
		}

	}
	namespace Random {

		std::random_device rd;//実装依存・環境依存ランダム
		std::minstd_rand mr(rd());

		template<class YI=std::size_t>
		YI GetRandom(YI Min, YI Max) {
			if (Min > Max)std::swap(Min, Max);
			std::uniform_int_distribution<YI> UID(Min, Max);

			return UID(mr);
		}
		template<class YI=std::size_t>
		YI GetRandom() {
			std::uniform_int_distribution<YI> UID((std::numeric_limits<YI>::min)(), (std::numeric_limits<YI>::max)());

			return UID(mr);
		}
		template<class YI=double>
		YI GetRandomF(YI Min, YI Max) {
			if (Min > Max)std::swap(Min, Max);
			std::uniform_real_distribution<YI> UID(Min, Max);

			return UID(mr);
		}
		template<class YI=double>
		YI GetRandomF() {
			std::uniform_real_distribution<YI> UID((std::numeric_limits<YI>::min)(), (std::numeric_limits<YI>::max)());

			return UID(mr);
		}
	}
}

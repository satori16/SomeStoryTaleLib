#include "SomeStoryTaleLib.h"

//main unit.

int main() {

	InitializeDisplayMode();

	SomeStoryTaler::TimeType Time(3000);

	SomeStoryTaler::Shower::Simple("�ق�������P�A�͂�������Q");
	if (SomeStoryTaler::Input::WithTimeout(Time) ==  '1') {
		SomeStoryTaler::Shower::Simple("����Ղ���");
	}
	else {
		SomeStoryTaler::Shower::Simple("����Ղ��ƁH�H");
	}

	SomeStoryTaler::Writer::WriteText(10, 10, "�ق�������B");

	return 0;

}
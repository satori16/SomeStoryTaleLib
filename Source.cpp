#include "SomeStoryTaleLib.h"

//main unit.

int main() {

	InitializeDisplayMode();

	SomeStoryTaler::TimeType Time(3000);

	SomeStoryTaler::Shower::Simple("ほげらった１、はげらった２");
	if (SomeStoryTaler::Input::WithTimeout(Time) ==  '1') {
		SomeStoryTaler::Shower::Simple("いんぷっと");
	}
	else {
		SomeStoryTaler::Shower::Simple("いんぷっと？？");
	}

	SomeStoryTaler::Writer::WriteText(10, 10, "ほげらった。");

	return 0;

}
#include "lib/SomeStoryTaleLib.h"

//main unit.

int main() {

	InitializeDisplayMode();

	SomeStoryTaler::TimeType Time(3000);

	SomeStoryTaler::Shower::Simple("ÇŸÇ∞ÇÁÇ¡ÇΩÇPÅAÇÕÇ∞ÇÁÇ¡ÇΩÇQ");
	if (SomeStoryTaler::Input::WithTimeout(Time) ==  '1') {
		SomeStoryTaler::Shower::Simple("Ç¢ÇÒÇ’Ç¡Ç∆");
	}
	else {
		SomeStoryTaler::Shower::Simple("Ç¢ÇÒÇ’Ç¡Ç∆ÅHÅH");
	}

	SomeStoryTaler::Shower::WithPosition::Text(10, 10, "ÇŸÇ∞ÇÁÇ¡ÇΩÅB");

	return 0;

}
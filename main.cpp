#include "Deck.h"
#include <map>
#include <iostream>
#include <random>
#include <chrono>
#include "Familiar.h"

bool check(CARD_CLASS &criteria, size_t turn, const CDeck &deck)
{
	return deck.checkHand(turn, &criteria);
}

int main()
{
	CARD_CLASS MyMap;
	MyMap["manadork"] = 14;
	MyMap["forest"] = 18;
	MyMap["key1"] = 4;
	MyMap["key2"] = 2;
	MyMap["ramp"] = 8;
	MyMap["other"] = 14;

	std::random_device rd;
	CDeck mydeck(MyMap, rd);
	mydeck.shuffle();

	CARD_CLASS test;
	test["forest"] = 2;
	test["manadork"] = 1;
	test["key1"] = 1;
	test["key2"] = 1;
	test["ramp"] = 1;

	std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
	
	size_t TEST_RUN = 10000;
	int count = 0;
	for (int i = 0; i < TEST_RUN; i++)
	{
		if (check(test, 2, mydeck))
			count++;
		mydeck.shuffle();
	}
	cout << count << " / " << TEST_RUN << " = " << (count / (float)TEST_RUN) << endl;

	std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();

	auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count();
	cout << duration << " ms" << endl;
	CFamiliar f(mydeck);	





	return EXIT_SUCCESS;
}
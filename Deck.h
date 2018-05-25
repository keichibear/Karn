#pragma once
#include <vector>
#include <map>
#include <random>
#include <string>
using namespace std;

typedef std::map<string, size_t> CARD_CLASS;

class CDeck
{
public:
	CDeck(CARD_CLASS &cards, std::random_device &rd);
	~CDeck();
	void shuffle();
	bool checkHand(size_t turn, const CARD_CLASS *rule) const;
	void show() const;
	void show(size_t number) const;
private:
	std::vector<string> m_library;

	std::default_random_engine m_rnd;
};


#pragma once
#include "Deck.h"

class CFamiliar
{
public:
	CFamiliar(CDeck &deck) :m_deck(deck){};
	~CFamiliar();

	void test();

private:
	CDeck m_deck;

};


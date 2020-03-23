#include <bits/stdc++.h>

using namespace std;

#define pic pair<int,char>
#define pbi pair<bool,int>
#define set multiset // I added this because I found that there could be repetitive cards in the same hand

enum PokerHand {
	highCard = 1,
	pairHand = 2,
	twoPairs = 3,
	threeOfAKind = 4,
	straight = 5,
	flushHand = 6,
	fullHouse = 7,
	fourOfAKind = 8,
	straightFlush = 9
};

const string SUITS = "CDHS";
const string WHITE_WINS = "White wins.";
const string BLACK_WINS = "Black wins.";
const string TIE = "Tie.";

inline int cardValue(char c) {
	if(isdigit(c)) return c-'0';
	if(c == 'T') return 10;
	if(c == 'J') return 11;
	if(c == 'Q') return 12;
	if(c == 'K') return 13;
	return 14;
}

pbi hasStraightFlush(set<pic> cards) {
	for(char suit : SUITS) {
		for(int value = 2; value <= 10; value ++) {

			bool good = true;
			for(int cardValue = value; cardValue < value + 5; cardValue ++) {
				if(cards.find( pic(cardValue, suit) ) == cards.end()) {
					good = false;
					break;
				}	
			}

			if(good) {
				return pbi(true, value+4);
			}
		}
	}

	return pbi(false, -1);
}

int countValue(int value, set<pic> &cards) {
	int result = 0;
	for(char suit : SUITS) {
		result += cards.count( pic(value, suit) );
	}
	return result;
}

pbi hasFourOfAKind(set<pic> &cards) {
	for(int value = 2; value <= 14; value ++) {
		if(countValue(value, cards) == 4) {
			return pbi(true, value);
		}
	}
	return pbi(false, -1);
}

map<int, int> getValueFreq(set<pic> &cards) {
	map<int, int> valueFreq;
	for(auto card : cards) {
		valueFreq[card.first] ++;
	}
	return valueFreq;
}

pbi hasFullHouse(set<pic> &cards) {
	map<int, int> valueFreq = getValueFreq(cards);

	bool two = false;
	bool three = false;
	int threeValue = -1;
	for(auto element : valueFreq) {
		if(element.second == 2) {
			two = true;
		} else if(element.second == 3) {
			three = true;
			threeValue = element.first;
		}
	}

	return pbi(two && three, threeValue);
}

map<char, int> getSuitFreq(set<pic> &cards) {
	map<char, int> suitFreq;
	for(pic card : cards) {
		suitFreq[card.second] ++;
	}
	return suitFreq;
}

bool hasFlush(set<pic> &cards) {
	map<char, int> suitFreq = getSuitFreq(cards);
	return suitFreq.size() == 1;
}

bool containsValue(int value, set<pic> &cards) {
	for(char suit : SUITS) {
		if(cards.find(pic(value, suit)) != cards.end()) {
			return true;
		}
	}

	return false;
}

bool hasStraight(set<pic> &cards) {
	for(int value = 2; value <= 10; value ++) {
		bool good = true;
		for(int cardValue = value; cardValue < value + 5; cardValue ++) {
			if(!containsValue(cardValue, cards)) {
				good = false;
				break;
			}
		}

		if(good) {
			return true;
		}
	}

	return false;
}

pbi hasThreeOfAKind(set<pic> &cards) {
	map<int, int> valueFreq = getValueFreq(cards);
	for(auto element : valueFreq) {
		if(element.second == 3) {
			return pbi(true, element.first);
		}
	}

	return pbi(false, -1);
}

bool hasTwoPairs(set<pic> &cards) {
	map<int, int> valueFreq = getValueFreq(cards);
	int pairCount = 0;
	for(auto element : valueFreq) {
		if(element.second == 2) {
			pairCount ++;
		}
	}

	return pairCount == 2;
}

bool hasPair(set<pic> &cards) {
	map<int, int> valueFreq = getValueFreq(cards);
	int pairCount = 0;
	for(auto element : valueFreq) {
		if(element.second == 2) {
			pairCount ++;
		}
	}
	
	return pairCount == 1;
}

PokerHand getBest(set<pic> &cards) {
	if(hasStraightFlush(cards).first)	return PokerHand::straightFlush;
	if(hasFourOfAKind(cards).first)		return PokerHand::fourOfAKind;
	if(hasFullHouse(cards).first)		return PokerHand::fullHouse;
	if(hasFlush(cards))					return PokerHand::flushHand;
	if(hasStraight(cards))				return PokerHand::straight;
	if(hasThreeOfAKind(cards).first)	return PokerHand::threeOfAKind;
	if(hasTwoPairs(cards))				return PokerHand::twoPairs;
	if(hasPair(cards)) 					return PokerHand::pairHand;
	return PokerHand::highCard;
}

set<pic> convert(vector<string> v) {
	set<pic> result;
	for(string card : v) {
		result.insert( pic(cardValue(card[0]), card[1]) );
	}

	return result;
}

string compareOneHighCard(int firstHigh, int secondHigh) {
	if(firstHigh > secondHigh) {
		return BLACK_WINS;
	} else if(firstHigh < secondHigh) {
		return WHITE_WINS;
	} else {
		return TIE;	
	}
}

string compareStraightFlush(set<pic> &first, set<pic> &second) {
	int firstHigh = hasStraightFlush(first).second;
	int secondHigh = hasStraightFlush(second).second;
	return compareOneHighCard(firstHigh, secondHigh);
}

string compareFourOfAKind(set<pic> &first, set<pic> &second) {
	int firstHigh = hasFourOfAKind(first).second;
	int secondHigh = hasFourOfAKind(second).second;
	return compareOneHighCard(firstHigh, secondHigh);
}

string compareFullHouse(set<pic> &first, set<pic> &second) {
	int firstHigh = hasFullHouse(first).second;
	int secondHigh = hasFullHouse(second).second;
	return compareOneHighCard(firstHigh, secondHigh);
}

string compareHighCard(set<pic> &first, set<pic> &second) {
	for(int value = 14; value >= 2; value --) {
		bool firstContains = containsValue(value, first);
		bool secondContains = containsValue(value, second);

		if(firstContains && !secondContains) {
			return BLACK_WINS;
		} else if(!firstContains && secondContains) {
			return WHITE_WINS;
		}
	}

	return TIE;
}

string compareFlush(set<pic> &first, set<pic> &second) {
	return compareHighCard(first, second);
}

string compareStraight(set<pic> &first, set<pic> &second) {
	return compareHighCard(first, second);
}

string compareThreeOfAKind(set<pic> &first, set<pic> &second) {
	int firstHigh = hasThreeOfAKind(first).second;
	int secondHigh = hasThreeOfAKind(second).second;
	return compareOneHighCard(firstHigh, secondHigh);
}

vector<int> getPairPresentation(set<pic> &first) {
	vector<int> presentation;
	for(int value = 14; value >= 2; value --) {
		if(countValue(value, first) == 2) {
			presentation.push_back(value);
		}
	}

	for(int value = 14; value >= 2; value --) {
		if(countValue(value, first) == 1) {
			presentation.push_back(value);
		}
	}
	return presentation;
}

string compareTwoPairs(set<pic> &first, set<pic> &second) {
	vector<int> firstPresentation = getPairPresentation(first);
	vector<int> secondPresentation = getPairPresentation(second);

	for(int i = 0; i < secondPresentation.size(); i ++) {
		if(firstPresentation[i] > secondPresentation[i]) {
			return BLACK_WINS;
		} else if(firstPresentation[i] < secondPresentation[i]) {
			return WHITE_WINS;
		}
	}

	return TIE;
}

string comparePair(set<pic> &first, set<pic> &second) {
	return compareTwoPairs(first, second);
}

string gameResult(set<pic> &first, set<pic> &second) {
	PokerHand firstHand = getBest(first);
	PokerHand secondHand = getBest(second);

	if(firstHand > secondHand) {
		return BLACK_WINS;
	} else if(firstHand < secondHand) {
		return WHITE_WINS;
	} else {
		switch(firstHand) {
			case straightFlush:
				return compareStraightFlush(first, second);

			case fourOfAKind:
				return compareFourOfAKind(first, second);

			case fullHouse:
				return compareFullHouse(first, second);

			case flushHand:
				return compareFlush(first, second);

			case straight:
				return compareStraight(first, second);

			case threeOfAKind:
				return compareThreeOfAKind(first, second);

			case twoPairs:
				return compareTwoPairs(first, second);

			case pairHand:
				return comparePair(first, second);

			default:
				return compareHighCard(first, second);
		}

		return TIE;
	}
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    vector<string> x(5), y(5);
    set<pic> first, second;
    while(cin >> x[0]) {
    	for(int i = 1; i < 5; i ++) {
    		cin >> x[i];
    	}

    	for(int j = 0; j < 5; j ++) {
    		cin >> y[j];
    	}

    	first = convert(x);
    	second = convert(y);

    	cout << gameResult(first, second) << endl;
    }

	return 0;
}
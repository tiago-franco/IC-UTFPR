#include <iostream>
#include <vector>
#include "Strategy.hpp"
#include "Downing.hpp"
#include "TitForTat.hpp"
#include "Random.hpp"
#include "Defector.hpp"
#include "Cooperator.hpp"
#include "Joss.hpp"
#include "Tournament.hpp"


using namespace std;

int main () {

	vector<Strategy *> strategys;

	
	strategys.push_back(new TitForTat);
	strategys.push_back(new Downing);
	strategys.push_back(new Joss);
	strategys.push_back(new Random);
	strategys.push_back(new Defector);
	strategys.push_back(new Cooperator);
	
	Tournament tournament;

	tournament.setStrategys(strategys);

	tournament.play();

	return 1;
}
#include <stdlib.h> 
#include <time.h>
class Random: public Strategy {

	public:
		Random(): Strategy("Random"){
			srand(time(NULL));
		};

		int move(vector<int> OpponentHistory){ 
			return rand() % 2;
	  }
};

#include <stdlib.h> 
#include <time.h>

class Joss: public Strategy {

	public:

		Joss(): Strategy("Joss"){
			srand(time(NULL));
		}

		int move(vector<int> OpponentHistory){ 
			int n = OpponentHistory.size();
			if(n == 0){
				return 0;
			} else {
				if(OpponentHistory[(n-1)] == 1){
					return 1;
				} else {
					int prob = rand() % 11;

					if(prob <= 9){
						return 0;
					} else {
						return 1;
					}
				}
				
			}
		}

		void resetStrategy(){
			clearHistory();
		}

};

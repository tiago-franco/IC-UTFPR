class Downing: public Strategy {

	public:
		Downing(): Strategy("Downing"){
			reset();
		}

		void reset(){
			revised = 1;
			good = 1.0;
			bad = 0.0;
			nice1 = 0;
			nice2 = 0;
			total_C = 0; // note the same as cooperations
			total_D = 0; // note the same as defections
		}
		int move(vector<int> OpponentHistory){ 

			vector<int> history = getHistory();	

			int n = history.size();

			// According to internet sources, the original implementation defected
			// on the first two moves. Otherwise it wins (if this code is removed
			// and the comment restored.
			// http://www.sci.brooklyn.cuny.edu/~sklar/teaching/f05/alife/notes/azhar-ipd-Oct19th.pdf
			if(revised){
				if(n == 0){
					return 0;
				}
			} else {
				if(n <= 1){
					return 1;
				}
			}

			if(n > 1){
				if (history[(n-1)] == 1){
					if (OpponentHistory[(n-1)] == 0){
						nice2 += 1;
					}
					total_D += 1;
					bad = ( nice2 / total_D);
				} else {
					if (OpponentHistory[(n-1)] == 0){
						nice1 += 1;
					}
					total_C += 1;
					good = (nice1 / total_C);
				}
			}

			// Make a decision based on the accrued counts

			int c = ((6 * good) - (8 * bad) - 2);
			int alt = ((4 * good) - (5 * bad) - 1);
			if (c >= 0 && c >= alt){
				return 0;
			} else if ((c >= 0 && c < alt) || (alt >= 0)) {

				if(history[(n-1)] == 1){
					return 0;
				} else {
					return 1;
				}
			} else{
				return 1;
			}
		}

		void resetStrategy(){
			clearHistory();
			reset();
		}
	private: 
		int revised, good, bad, nice1, nice2, total_C, total_D;
};
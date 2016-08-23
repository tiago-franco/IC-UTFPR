class TitForTat: public Strategy {

	public:

		TitForTat(): Strategy("TitForTat"){}

		int move(vector<int> OpponentHistory){ 
			int n = OpponentHistory.size();
			if(n == 0){
				return 0;
			} else {
				return OpponentHistory[(n-1)];
			}
		}

		void resetStrategy(){
			clearHistory();
		}

};

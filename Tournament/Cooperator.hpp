class Cooperator: public Strategy {

	public:
		Cooperator(): Strategy("Cooperator"){
		}
		int move(vector<int> OpponentHistory){ 
			return 0;
		}
};
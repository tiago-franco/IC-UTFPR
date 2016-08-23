class Defector: public Strategy {

	public:
		Defector(): Strategy("Defector"){
		}
		int move(vector<int> OpponentHistory){ 
			return 1;
		}
};
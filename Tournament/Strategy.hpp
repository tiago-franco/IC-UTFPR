#include <vector>
#include <string>

using namespace std;

class Strategy {
	public:
		Strategy(string name){
			this->name  = name;
		};

		virtual int move(vector<int> OpponentHistory){ 
			return -1;
		}

		virtual void resetStrategy(){ 
			return;
		}

		void setHistory(int move){
			history.push_back(move);
		};

		void clearHistory(){
			history.clear();
		};

		vector<int> getHistory(){
			return history;
		};

		string getName(){
			return name;
		}

		int getScore(){
			return score;
		}

		int setScore(int score){
			this->score = score;
		}

	private:
		string name;
		int score;
		vector<int> history;
};
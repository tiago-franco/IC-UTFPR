#include <fstream>

class Tournament {
	public:
		Tournament(){
			moves = 200;
		};

		void setMoves(int m){
			moves = m;
		};

		void setStrategys(vector<Strategy *> strategys){
			this->strategys = strategys;
		};

		int getMoves(){
			return moves;
		};


		vector<Strategy *> getStrategys(){
			return strategys;
		};

		void play(){
			ofstream myfile;
			myfile.open ("scores.csv");
			myfile << ";";
			for (int i = 0; i < strategys.size(); ++i){
				myfile << strategys[i]->getName()<< ';';
			}
			myfile << "\n";
			int c[2];
			int score;
			for (int i = 0; i < strategys.size(); ++i){
				myfile << strategys[i]->getName()<< ';';
				for (int j = 0; j < strategys.size(); ++j){
					// cout << '\n' << strategys[i]->getName() << " x " << strategys[j]->getName()<< '\n';
					score = 0;
					strategys[i]->resetStrategy();
					strategys[j]->resetStrategy();
					for (int k = 0; k < moves; ++k){
						
						c[0] = strategys[i]->move(strategys[j]->getHistory());
						c[1] = strategys[j]->move(strategys[i]->getHistory());

						// cout << c[0] << " x " << c[1] << "\n";
						strategys[i]->setHistory(c[0]);
						strategys[j]->setHistory(c[1]);
						
						if (c[0] == c[1]){
							if (c[0] == 0){
								score += 3;
							} else {
								score += 1;
							}
						} else{
							if (c[0] > c[1]){
								score += 5;
							} else {
								score += 0;
							}
						}
					}
					// cout << "Score: " << score;
					myfile << score << ";";
				}
				myfile << "\n";
			}

			myfile.close();
		};

	private:
		int moves;
		vector<Strategy *> strategys;
};
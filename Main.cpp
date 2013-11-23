#include <iostream>

using namespace std;
enum Modes { NAIVE_BAYES, TAN };

string train_file, test_file;
int mode;

void processArgs(int argc, char *argv[]) {
	if(argc != 4) {
		cerr << "Insufficient number of arguments." << endl;
		cout << "Usage: " << argv[0] << " training_file.arff test_file.arff <n|t> (n for naive bayes, t for TAN)" << endl;
		exit(-1);
	}
	train_file = argv[1];
	test_file = argv[2];
	if(string(argv[3]) == "n")
		mode = NAIVE_BAYES;
	else if(string(argv[3]) == "t")
		mode = TAN;
	else {
		cerr << "Illegal mode." << endl;
		exit(-1);
	}
}

int main(int argc, char *argv[]) {
	processArgs(argc, argv);
	cout << mode << endl;
}




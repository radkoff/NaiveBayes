#include <iostream>
#include "ArffParse.h"
#include "NaiveBayes.h"

using namespace std;
enum Modes { NAIVE_BAYES, TAN };
void evaluate(Learner & learner, vector<Instance> & tests);

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
	ArffParse train_parse(train_file), test_parse(test_file);
	vector<Attribute> attribs = train_parse.getAttributes();
	vector<Instance> training_instances = train_parse.getInstances();
	vector<Instance> test_instances = test_parse.getInstances();
	
	if( mode == NAIVE_BAYES ) {
		NaiveBayes bayes( & attribs );
		bayes.train( training_instances );
		evaluate(bayes, test_instances);
	}
}

void evaluate(Learner & learner, vector<Instance> & tests) {
	int correct = 0;
	learner.print();
	cout << endl;
	for(int i=0; i<tests.size(); i++) {
		string answer = tests[i].valueOf("class");
		pair<string, double> result = learner.classify(tests[i]);
		cout << result.first << " " << answer << " " << result.second << endl;
		if(answer == result.first) correct++;
	}
	cout << endl << correct << endl;
}


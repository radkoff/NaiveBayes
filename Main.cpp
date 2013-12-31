// Evan Radkoff
// Implements Naive Bayes classification with categorical data found in ARFF files

#include <iostream>
#include "ArffParse.h"
#include "NaiveBayes.h"

using namespace std;
void evaluate(Learner & learner, vector<Instance> & tests);

string train_file, test_file;

void processArgs(int argc, char *argv[]) {
	if(argc != 3) {
		cerr << "Insufficient number of arguments." << endl;
		cout << "Usage: " << argv[0] << " training_file.arff test_file.arff" << endl;
		exit(-1);
	}
	train_file = argv[1];
	test_file = argv[2];
}

int main(int argc, char *argv[]) {
	processArgs(argc, argv);
	ArffParse train_parse(train_file), test_parse(test_file);
	vector<Attribute> attribs = train_parse.getAttributes();
	vector<Instance> training_instances = train_parse.getInstances();
	vector<Instance> test_instances = test_parse.getInstances();
	
	NaiveBayes bayes( & attribs );
	bayes.train( training_instances );
	evaluate(bayes, test_instances);
}

/*
 *  Evaluates the performance of a learner given a vector of test instances
 */
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


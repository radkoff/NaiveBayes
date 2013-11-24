#include "NaiveBayes.h"

using namespace std;
typedef vector<int> vi;

NaiveBayes::NaiveBayes(const vector<Attribute> * _attribs)
	: attribs(_attribs), class_values(_attribs->back().getValues()) {
}

void NaiveBayes::train(const vector<Instance> & instances) {
	int num_classes = class_values.size();
	// Counts the occurances of each class
	vi class_counts(num_classes, 0);
	// Counts the occurances of each value of each attribute, for each class
	// Class < Attribute < Value
	vector< vector< vi > > val_counts(num_classes, vector< vi >(attribs->size()-1, vi()));
	for(int i=0; i<val_counts.size(); i++)
		for(int j=0; j<val_counts[i].size(); j++)
			val_counts[i][j].resize(attribs->at(j).getValues().size(), 0);
	// Iterate over instances
	for(int i=0; i<instances.size(); i++) {
		// Iterate over possible class label values
		for(auto it = class_values.begin(); it != class_values.end(); it++) {
			for(
		}
	
}

string NaiveBayes::classify(const Instance & instance) {

}


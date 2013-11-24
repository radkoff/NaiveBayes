#include "NaiveBayes.h"

using namespace std;
typedef vector<int> vi;

NaiveBayes::NaiveBayes(const vector<Attribute> * _attribs)
	: attribs(_attribs), class_values(_attribs->back().getValues()) {
}

void NaiveBayes::train(const vector<Instance> & instances) {
	// Maintains counts of the # of occurances for each class
	int_dict class_counts;
	count_classes(class_counts, instances);
	// Counts the occurances of each value of each attribute, for each class
	// Class < Attribute < Value
	//vector< vector< int_dict > > val_counts(num_classes, vector< vi >(attribs->size()-1, vi()));
	/*for(int i=0; i<val_counts.size(); i++)
		for(int j=0; j<val_counts[i].size(); j++)
			val_counts[i][j].resize(attribs->at(j).getValues().size(), 0);*/
	cout << class_counts["malign_lymph"] << " " << class_counts["metastases"] << endl;
}

int_dict & NaiveBayes::count_classes(int_dict & counts, const vector<Instance> & instances) {
	for(us::const_iterator it = class_values.begin(); it!=class_values.end(); it++)
		counts.insert( make_pair<string, int>(*it, 0) );
	for(int i=0; i<instances.size(); i++) {
		counts[ instances[i].valueOf("class") ] += 1;
	}
}

string NaiveBayes::classify(const Instance & instance) {

}


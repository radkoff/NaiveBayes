#ifndef _NAIVEBAYES_H_
#define _NAIVEBAYES_H_

#include "Instance.h"
#include "Learner.h"

using namespace std;

typedef tr1::unordered_map<string, int> int_dict;
typedef tr1::unordered_map<string, double> double_dict;

class NaiveBayes : public Learner {
private:
	const vector<Attribute> * attribs;
	const us class_values; // An unordered set of the possible class labels

	int_dict & count_classes(int_dict & counts, const vector<Instance> & instances);

	double_dict priors;
	vector< vector< double_dict > > probs; 	// Class < Attribute < Value > > >
public:
	NaiveBayes(const vector<Attribute> * _attribs);
	void train(const vector<Instance> & instances);
	string classify(const Instance & instance);
};

#endif

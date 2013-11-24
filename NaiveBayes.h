#ifndef _NAIVEBAYES_H_
#define _NAIVEBAYES_H_

#include "Instance.h"
#include "Learner.h"

using namespace std;

class NaiveBayes : public Learner {
private:
	const vector<Attribute> * attribs;
	const vs class_values; // A vector of the possible class labels

	vector<double> priors;
	vector< vector< vector<double> > > probs; 	// Class < Attribute < Value > > >
public:
	NaiveBayes(const vector<Attribute> * _attribs);
	void train(const vector<Instance> & instances);
	string classify(const Instance & instance);
};

#endif

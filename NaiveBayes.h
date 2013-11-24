#ifndef _NAIVEBAYES_H_
#define _NAIVEBAYES_H_

#include "Instance.h"

using namespace std;

class NaiveBayes : public Learner {
private:
	const vector<Attribute> * attribs;
	const Attribute to_predict; // The "class" attribute to predict. Initialized to attribs.last()

	vector<double> priors;
	vector< vector< vector<double> > > probs; 	// Class < Attribute < Value > > >
public:
	NaiveBayes(const vector<Attribute> * _attribs);
	void NaiveBayes::train(const vector<Instance> * instances);
	string NaiveBayes::classify(const Instance & instance);
};

#endif

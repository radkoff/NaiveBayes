#ifndef _NAIVEBAYES_H_
#define _NAIVEBAYES_H_

#include "Instance.h"
#include "Learner.h"

using namespace std;

typedef tr1::unordered_map<string, int> int_dict;
typedef tr1::unordered_map<string, double> double_dict;
typedef tr1::unordered_map<string, vector< int_dict > > count_keeper;
typedef tr1::unordered_map<string, vector< double_dict > > prob_keeper;

class NaiveBayes : public Learner {
private:
	const vector<Attribute> * attribs;
	const us class_values; // An unordered set of the possible class labels

	void count_classes(int_dict & counts, const vector<Instance> & instances);
	void count_values(count_keeper & counts, const vector<Instance> & instances);
	void calc_probs(count_keeper & val_counts);
	double_dict normalize(int_dict & counts);
	void print_counts(count_keeper & counts);
	void print_probs();

	double_dict priors;
	prob_keeper probs; 	// Class < Attribute < Value > > >
public:
	NaiveBayes(const vector<Attribute> * _attribs);
	void train(const vector<Instance> & instances);
	string classify(const Instance & instance);
};

#endif

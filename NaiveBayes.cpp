#include "NaiveBayes.h"

using namespace std;
//typedef vector<int> vi;

NaiveBayes::NaiveBayes(const vector<Attribute> * _attribs)
	: attribs(_attribs), class_values(_attribs->back().getValues()) {
}

void NaiveBayes::train(const vector<Instance> & instances) {
	// Maintains counts of the # of occurances for each class label
	int_dict class_counts;
	count_classes(class_counts, instances);
	// Maintains counts of the # of occurances for each attribute value (for each class label)
	// vector<vector<map<string,int>>>
	count_keeper val_counts;
	count_values(val_counts, instances);

	priors = normalize(class_counts);
	calc_probs(val_counts);
	//print_counts(val_counts);
	//print_probs();
}

void NaiveBayes::count_classes(int_dict & counts, const vector<Instance> & instances) {
	for(us::const_iterator it = class_values.begin(); it!=class_values.end(); it++)
		counts[*it] = 0;
	for(int i=0; i<instances.size(); i++) {
		counts[ instances[i].valueOf("class") ] += 1;
	}
}

void NaiveBayes::count_values(count_keeper & counts, const vector<Instance> & instances) {
	for(us::const_iterator it = class_values.begin(); it!=class_values.end(); it++) {
		vector< int_dict > features;
		for(int i=0; i<attribs->size() - 1; i++) {
			int_dict attrib_counts;
			for(us::const_iterator it2 = attribs->at(i).getValues().begin(); it2 != attribs->at(i).getValues().end(); it2++)
				attrib_counts[*it2] = 0;
			features.push_back( attrib_counts );
		}
		counts[*it] = features;
	}
	for(int i=0; i<instances.size(); i++) {
		string label = instances[i].valueOf("class");
		for(int j=0; j<attribs->size() - 1; j++) {
			counts[label][j][ instances[i].valueOf(attribs->at(j).getName()) ] += 1;
		}
	}
}

// Responsible for populating the probs data member
void NaiveBayes::calc_probs(count_keeper & val_counts) {
	for(us::const_iterator it = class_values.begin(); it!=class_values.end(); it++) {
		vector<double_dict> features;
		for(int i=0; i<attribs->size() - 1; i++) {
			features.push_back(normalize( val_counts[*it][i] ));
		}
		probs[*it] = features;
	}
}

// Also adds LaPlace estimation
double_dict NaiveBayes::normalize(int_dict & counts) {
	double_dict dd;
	int total = 0;
	for(int_dict::iterator it = counts.begin(); it != counts.end(); it++)
		total += it->second;
	for(int_dict::iterator it = counts.begin(); it != counts.end(); it++)
		dd[it->first] = (it->second+1)/((double)counts.size() + total);
	return dd;
}

pair<string, double> NaiveBayes::classify(const Instance & instance) {
	double_dict results;
	for(us::const_iterator it = class_values.begin(); it!=class_values.end(); it++) {
		double prob = priors[*it];
		for(int i=0; i<attribs->size() - 1; i++)
			prob *= probs[*it][i][instance.valueOf(attribs->at(i).getName())];
		results[*it] = prob;
	}
	double total = 0.0;
	for(double_dict::iterator it = results.begin(); it != results.end(); it++)
		total += it->second;
	double_dict::iterator best = results.begin();
	for(double_dict::iterator it = results.begin(); it != results.end(); it++) {
		it->second = it->second / total;
		if(it->second > best->second)
			best = it;
	}
	return *best;
}

void NaiveBayes::print() {
	for(int i=0; i<attribs->size() - 1; i++)
		cout << attribs->at(i).getName() << " class" << endl;
}

/*void NaiveBayes::print_counts(count_keeper & counts) {
	for(us::const_iterator it = class_values.begin(); it!=class_values.end(); it++) {
		cout << *it << ":\n";
		for(int i=0; i<attribs->size() - 1; i++) {
			cout << attribs->at(i).getName() << ":\t\t";
			for(us::const_iterator it2 = attribs->at(i).getValues().begin(); it2 != attribs->at(i).getValues().end(); it2++)
				cout << *it2 << ": " << counts[*it][i][*it2] << "\t";
			cout << endl;
		}
		cout << endl;
	}
}

void NaiveBayes::print_probs() {
	for(us::const_iterator it = class_values.begin(); it!=class_values.end(); it++) {
		cout << *it << ":\n";
		for(int i=0; i<attribs->size() - 1; i++) {
			cout << attribs->at(i).getName() << ":\t\t";
			for(us::const_iterator it2 = attribs->at(i).getValues().begin(); it2 != attribs->at(i).getValues().end(); it2++)
				cout << *it2 << ": " << probs[*it][i][*it2] << "\t";
			cout << endl;
		}
		cout << endl;
	}
}*/

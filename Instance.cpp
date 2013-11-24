#include "Instance.h"

using namespace std;

void Instance::parse(string input) {
	// Verify the correct number of values (except maybe no class)
}

/* Parses a comma separated line of data from an arff file */
Instance::Instance(string input, const vector<Attribute> * _attribs) : attribs(_attribs) {
	parse(input);
}

string Instance::valueOf(string key) const {

}


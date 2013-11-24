#include "Instance.h"

using namespace std;

void Instance::parse(string input) {
	// Verify the correct number of values (except maybe no class)
	istringstream iss(input);
	int i=0;
	for(string token; getline(iss, token, ','); i++) {
		// Trim white space from value
                stringstream trimmer;
                trimmer << token;
                token.clear();
                trimmer >> token;
		if(i >= attribs->size()) {
			cerr << "The following instance has too many data members:\n";
			cerr << input << endl;
			exit(-1);
		}
		if(!attribs->at(i).inValues(token)) {
			cerr << token << " is not a valid value of attribute " << attribs->at(i).getName() <<endl;
			exit(-1);
		} else {
			values.insert( make_pair<string,string>(attribs->at(i).getName(), token) );
		}
	}
}

/* Parses a comma separated line of data from an arff file */
Instance::Instance(string input, const vector<Attribute> * _attribs) : attribs(_attribs) {
	parse(input);
}

string Instance::valueOf(string key) const {
	//return values.at(key);
	string result = "";
	ss_map::iterator it = values.find(key);
	if(it != values.end())
		result = it->second;
	return result;
}


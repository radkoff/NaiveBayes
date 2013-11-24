#include "ArffParse.h"

using namespace std;

ArffParse::ArffParse(string arff_file) {
	ifstream ifs(arff_file.c_str(), ifstream::in);
	if(!ifs.is_open()) {
		cerr << "ARFF file " << arff_file << " not found.\n";
		exit(-1);
	}
	
	bool getting_data = false;
	while(ifs.good()) {
		string line;
		getline(ifs, line);
		if(line[0] == '%') continue;
		if(getting_data) {
			instances.push_back( Instance(line, &attribs) );
		} else if(line.substr(0,10) == "@attribute")
			attribs.push_back( Attribute(line) );
		else if(line == "@data")
			getting_data = true;
	}
}
	
vector<Attribute> ArffParse::getAttributes() const {
	return attribs;
}
vector<Instance> ArffParse::getInstances() const {
	return instances;
}



#ifndef _INSTANCE_H_
#define _INSTANCE_H_

#include "Attribute.h"
#include <vector>
#include <tr1/unordered_map>

using namespace std;
typedef tr1::unordered_map<string, string> ss_map;

class Instance {
private:
	ss_map values;
	const vector<Attribute> * attribs;
	
	void parse(string input);
public:
	/* Parses a comma separated line of data from an arff file */
	Instance(string input, const vector<Attribute> * _attribs);
	
	string valueOf(string key) const;
};

#endif _INSTANCE_H_

#ifndef _INSTANCE_H_
#define _INSTANCE_H_

#include "Attribute.h"
#include <tr1/unordered_map>

typedef unordered_map<std::string, std::string> ss_map;

class Instance {
private:
	ss_map values;
public:
	/* Parses a comma separated line of data from an arff file */
	Instance(std::string input);
	
	const std::string valueOf(std::string key);
};

#endif _INSTANCE_H_

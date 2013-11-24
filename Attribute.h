#ifndef _ATTRIBUTE_H_
#define _ATTRIBUTE_H_

#include <tr1/unordered_set>
#include <iostream>
#include <sstream>
#include <vector>

typedef std::vector<std::string> vs;

class Attribute {
private:
	std::string name;
	// A set of values used for constant verification of values' existence
	std::tr1::unordered_set<std::string> value_set;
	// The values in a vector
	vs values;
	
	std::string parseName(std::string line);
public:
	Attribute(const std::string line);
	bool inValues(const std::string & key) const;

	const std::string & getName() const;
	const vs & getValues() const;
};


#endif


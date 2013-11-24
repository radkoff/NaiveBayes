#ifndef _ATTRIBUTE_H_
#define _ATTRIBUTE_H_

#include <tr1/unordered_set>
#include <iostream>
#include <sstream>
typedef std::tr1::unordered_set<std::string> us;

class Attribute {
private:
	std::string name;
	us values;
	
	std::string parseName(std::string line);
public:
	Attribute(const std::string line);
	bool inValues(const std::string & key) const;

	const std::string & getName() const;
	const us & getValues() const;
};


#endif


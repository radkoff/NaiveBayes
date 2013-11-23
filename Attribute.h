#ifndef _ATTRIBUTE_H_
#define _ATTRIBUTE_H_

#include <vector>
#include <string>
typedef std::vector<std::string> vs;

class Attribute {
private:
	std::string name;
	vs values;
public:
	Attribute(std::string _name, vs _values);
	
	const std::string getName() const;
	const vs getValues() const;
};


#endif


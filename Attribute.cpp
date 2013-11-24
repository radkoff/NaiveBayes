#include "Attribute.h"

using namespace std;

Attribute::Attribute(const string line) {
	// Set the name
	string remainder = parseName(line);
	// Eat up the '{' and '}'
	remainder = remainder.substr( remainder.find('{') + 1);
	remainder = remainder.substr( 0, remainder.find('}') );

	// Parse each possible value from the comma separated list
	// Store each in the unordered_set 'values'
	istringstream iss(remainder);
	for(string token; getline(iss, token, ',') ;) {
		// Trim white space from value
		stringstream trimmer;
		trimmer << token;
		token.clear();
		trimmer >> token;
		
		values.insert(token);
	}
}

/* Responsible for setting the name and returns the remainder of the line */
string Attribute::parseName(string line) {
	string parsing = line.substr(line.find('\'') + 1);
	int name_ends = parsing.find('\'');
	name = parsing.substr(0, name_ends);
	return parsing.substr(name_ends + 1);
}

string Attribute::getName() const {
	return name;
}

bool Attribute::inValues(const string & key) const {
	if( values.find(key) == values.end() )
		return false;
	else return true;
}

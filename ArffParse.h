#ifndef _ARFFPARSE_H_
#define _ARFFPARSE_H_

#include "Attribute.h"
#include "Instance.h"
#include <fstream>
#include <iostream>

using namespace std;

class ArffParse {
private:
	vector<Attribute> attribs;
	vector<Instance> instances;
	
public:
	ArffParse(string arff_file);
	
	vector<Attribute> getAttributes() const;
	vector<Instance> getInstances() const;
};

#endif


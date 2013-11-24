#ifndef _LEARNER_H_
#define _LEARNER_H_

#include "Attribute.h"
#include "Instance.h"

class Learner {
public:
	virtual Learner(const std::vector<Attribute> * attribs);
	virtual void train(const std::vector<Instance> * instances);
	virtual std::string classify(const Instance & instance);
}

#endif

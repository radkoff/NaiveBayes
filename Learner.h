#ifndef _LEARNER_H_
#define _LEARNER_H_

#include "Instance.h"

class Learner {
public:
	virtual void train(const std::vector<Instance> & instances) = 0;
	virtual std::pair<std::string, double> classify(const Instance & instance) = 0;
	virtual void print() = 0;
};

#endif

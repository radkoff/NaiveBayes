#ifndef _LEARNER_H_
#define _LEARNER_H_

#include "Instance.h"

class Learner {
public:
	virtual void train(const std::vector<Instance> & instances) = 0;
	virtual std::string classify(const Instance & instance) = 0;
};

#endif

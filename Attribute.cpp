#include "Attribute.h"

Attribute::Attribute(std::string _name, vs _values) : name(_name), values(_values) {

}

const std::string Attribute::getName() const {
	return name;
}

const vs Attribute::getValues() const {
	return values;
}

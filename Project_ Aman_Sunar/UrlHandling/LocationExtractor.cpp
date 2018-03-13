
#include "LocationExtractor.h"

LocationExtractor::LocationExtractor(const std::string & value)
	:_value(value)
{

	if (value.at(0) == '/' & value.at(1) == '/' & value.at(2) == '/') {
		_hasLocation = false;
	}
	else if (value.at(0) == '/' & value.at(1) == '/') {
		_hasLocation = true;
	}
	

	if (HasComponent()) {
		int counter = 0;
		int i;
		if (value.at(0) == '/' & value.at(1) == '/') {
			 i = 2;
		}
		else if (value.at(0) == '/') {
			i = 1;
		}
		else {
		
			i = 0;
		}
		for (i; i < value.length();i++) {
			counter = i;
			if (value.at(i) != '/') {
				_component = _component + value.at(i);
			}
			else {
				break;
			}
		}
		for (counter; counter < value.length();counter++) {
			_base = _base + value.at(counter);
		}
	}
	

	
}

bool LocationExtractor::HasComponent() const
{
	if (_hasLocation) {
		return true;
	}
	return false;
}

const std::string & LocationExtractor::GetBase() const
{
	return _base;
	// TODO: insert return statement here
}

const std::string & LocationExtractor::GetComponent() const
{
	return _component;
	// TODO: insert return statement here
}

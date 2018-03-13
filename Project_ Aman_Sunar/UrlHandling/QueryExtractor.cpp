
#include "QueryExtractor.h"

QueryExtractor::QueryExtractor(const std::string & value)
	:_value(value)
{
	if (HasComponent()) {
		for (int i = 0; i < value.find("?"); i++) {
			_base = _base + value.at(i);
		}

		for (int i = value.find("?") + 1; i < value.length();i++)
		{
			_component = _component + value.at(i);
		}

		

	}


}

bool QueryExtractor::HasComponent() const
{
	
	for (int i = 0; i < _value.length(); i++) {
		if (_value.at(i) == '?') {
			return true;
		}
	
	}
	return false;
}

const std::string & QueryExtractor::GetBase() const
{
	return _base;

	// TODO: insert return statement here
}

const std::string & QueryExtractor::GetComponent() const
{
	return _component;
	// TODO: insert return statement here
}

const std::vector<std::string>& QueryExtractor::GetQueryParameters() const
{
	return _parameters;

	// TODO: insert return statement here
}

void QueryExtractor::FindParameters()
{
	if (HasComponent()) {

		_temp = "";
		for (int i = 0; i < _component.length();i++) {
				_temp = _temp + _component.at(i);
				if (_component.at(i) == '&') {
					_parameters.push_back(_temp); // adding parameter to vactor
					_temp.clear();  // clearing the temp  variable for next parameter
				}
				_parameters.push_back(_temp); // addding last parameter to vector 
	
		
		}
	}
}

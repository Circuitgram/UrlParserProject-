#include "FragmentExtractor.h"

FragmentExtractor::FragmentExtractor(const std::string & value)
	: _value(value)
{
	if (HasComponent()) {
		for (int i = 0; i < value.find("#"); i++) {
			_base = _base + value.at(i);
		}

		for (int i = value.find("#") + 1; i < value.length();i++)
		{
			_component = _component + value.at(i);

		}
	}
}
	



bool FragmentExtractor::HasComponent() const
{
	for (int i = _value.length() - 1 ;i >= 0;i--) {
		if (_value.at(i) == '#') {
			return true;
		}
	}

	return false; // TODO return true if a fragment was found

}

const std::string & FragmentExtractor::GetBase() const
{
	return _base;
}

const std::string & FragmentExtractor::GetComponent() const
{
	return _component;
}

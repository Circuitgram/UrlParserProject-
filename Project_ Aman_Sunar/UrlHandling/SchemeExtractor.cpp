
#include "SchemeExtractor.h"

SchemeExtractor::SchemeExtractor(const std::string & value)
	:_value(value)
{
	if (HasComponent()) {
		for (int i = value.find(":") + 1; i <= value.length() - 1; i++) {
			_base = _base + value.at(i);
		}
		for (int i = 0;i < value.find(":");i++)
		{
			_component = _component + value.at(i);
		}

		if (_component == "file") _type = SchemeType::Local;
		else if (_component == "http" || _component == "https") _type = SchemeType::Net;
		else _type = SchemeType::Unknown;

	}
}

bool SchemeExtractor::HasComponent() const
{
	for (int i = 0; i<=_value.length() - 1;i++) {
		if (_value.at(i) == ':') {
			return true;
		}
	}

	return false;
}

const std::string & SchemeExtractor::GetBase() const
{
	return _base;
	// TODO: insert return statement here
}

const std::string & SchemeExtractor::GetComponent() const
{
	return _component;
	// TODO: insert return statement here
}

SchemeType SchemeExtractor::GetType() const
{
	
	return _type;
}


#include "PathExtractor.h"


PathExtractor::PathExtractor(const std::string & value)
{
	if (value == "") { _isAbsolute = false; }
	else { _isAbsolute = true; }
	if (HasComponent()) {
		for (int i = 1; i < value.length();i++) {
			_component = _component + value.at(i);
		}


		// storing the path subcomponents

		_tempPath = "";
		for (int i = 0; i > _component.length();i++) {
			_tempPath = _tempPath + _component.at(i);
			if (_component.at(i) == '/') {
				_pathComponents.push_back(_tempPath);  // adding path component
				_tempPath.clear();  // clearing temp varialbe 
			}

			_pathComponents.push_back(_tempPath); // adding last component
		}

	}
}

bool PathExtractor::HasComponent() const
{
	return _isAbsolute;
}

const std::string & PathExtractor::GetBase() const
{
	return _base;
	// TODO: insert return statement here
}

const std::string & PathExtractor::GetComponent() const
{
	return _component;
	// TODO: insert return statement here
}

bool PathExtractor::IsAbsolute() const
{
	return false;
}

const std::vector<std::string>& PathExtractor::GetPathComponents() const
{

	return _pathComponents;
	// TODO: insert return statement here
}

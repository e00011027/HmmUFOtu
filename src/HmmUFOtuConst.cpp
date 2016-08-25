/*
 * HmmUFOtuConst.cpp
 *
 *  Created on: Aug 3, 2016
 *      Author: zhengqi
 */
#include <cstdio>
#include "HmmUFOtuConst.h"


namespace EGriceLab {
using namespace std;

int cmpVersion(const string& ver1, const string& ver2) {
	int major1, minor1, rev1;
	int major2, minor2, rev2;
	if(sscanf(ver1.c_str(), "v%d.%d.%d", &major1, &minor1, &ver1) != 3)
		return 0;
	if(sscanf(ver2.c_str(), "v%d.%d.%d", &major2, &minor2, &ver2) != 3)
		return 0;
	return major1 != major2 ? major1 - major2 : minor1 != minor2 ? minor1 - minor2 : rev1 - rev2;
}

istream& readProgName(istream& in, string& name) {
	return std::getline(in, name, '\0'); /* read until null-terminal */
}

istream& readProgVersion(istream& in, string& version) {
	return std::getline(in, version, '\0');
}

ostream& writeProgName(ostream& out, const string& name) {
	return out.write(name.c_str(), name.length() + 1); /* write the null-terminal */
}

ostream& writeProgVersion(ostream& out, const string& version) {
	return out.write(version.c_str(), version.length() + 1);
}

} /* end namespace EGriceLab */
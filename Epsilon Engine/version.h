#ifndef VERSION_H
#define VERSION_H

namespace AutoVersion{
	
	//Date Version Types
	static const char DATE[] = "05";
	static const char MONTH[] = "03";
	static const char YEAR[] = "2018";
	static const char UBUNTU_VERSION_STYLE[] =  "18.03";
	
	//Software Status
	static const char STATUS[] =  "Alpha";
	static const char STATUS_SHORT[] =  "a";
	
	//Standard Version Type
	static const long MAJOR  = 9;
	static const long MINOR  = 9;
	static const long BUILD  = 9744;
	static const long REVISION  = 53149;
	
	//Miscellaneous Version Types
	static const long BUILDS_COUNT  = 28580;
	#define RC_FILEVERSION 9,9,9744,53149
	#define RC_FILEVERSION_STRING "9, 9, 9744, 53149\0"
	static const char FULLVERSION_STRING [] = "9.9.9744.53149";
	
	//These values are to keep track of your versioning state, don't modify them.
	static const long BUILD_HISTORY  = 44;
	

}
#endif //VERSION_H

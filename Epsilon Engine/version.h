#ifndef VERSION_H
#define VERSION_H

namespace AutoVersion{
	
	//Date Version Types
	static const char DATE[] = "06";
	static const char MONTH[] = "12";
	static const char YEAR[] = "2016";
	static const char UBUNTU_VERSION_STYLE[] =  "16.12";
	
	//Software Status
	static const char STATUS[] =  "Alpha";
	static const char STATUS_SHORT[] =  "a";
	
	//Standard Version Type
	static const long MAJOR  = 7;
	static const long MINOR  = 1;
	static const long BUILD  = 6737;
	static const long REVISION  = 36624;
	
	//Miscellaneous Version Types
	static const long BUILDS_COUNT  = 18669;
	#define RC_FILEVERSION 7,1,6737,36624
	#define RC_FILEVERSION_STRING "7, 1, 6737, 36624\0"
	static const char FULLVERSION_STRING [] = "7.1.6737.36624";
	
	//These values are to keep track of your versioning state, don't modify them.
	static const long BUILD_HISTORY  = 37;
	

}
#endif //VERSION_H

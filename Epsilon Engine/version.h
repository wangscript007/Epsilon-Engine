#ifndef VERSION_H
#define VERSION_H

namespace AutoVersion{
	
	//Date Version Types
	static const char DATE[] = "16";
	static const char MONTH[] = "12";
	static const char YEAR[] = "2017";
	static const char UBUNTU_VERSION_STYLE[] =  "17.12";
	
	//Software Status
	static const char STATUS[] =  "Alpha";
	static const char STATUS_SHORT[] =  "a";
	
	//Standard Version Type
	static const long MAJOR  = 9;
	static const long MINOR  = 4;
	static const long BUILD  = 9239;
	static const long REVISION  = 50372;
	
	//Miscellaneous Version Types
	static const long BUILDS_COUNT  = 26680;
	#define RC_FILEVERSION 9,4,9239,50372
	#define RC_FILEVERSION_STRING "9, 4, 9239, 50372\0"
	static const char FULLVERSION_STRING [] = "9.4.9239.50372";
	
	//These values are to keep track of your versioning state, don't modify them.
	static const long BUILD_HISTORY  = 39;
	

}
#endif //VERSION_H

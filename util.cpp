#include <iostream>
#include <sstream>
#include <cctype>
#include <algorithm>
#include "util.h"

using namespace std;
std::string convToLower(std::string src)
{
    std::transform(src.begin(), src.end(), src.begin(), ::tolower);
    return src;
}

/** Complete the code to convert a string containing a rawWord
    to a set of words based on the criteria given in the assignment **/
std::set<std::string> parseStringToWords(string rawWords)
{
	std::set<std::string> ret;
	string lowerraw = convToLower(rawWords);
	lowerraw = trim(lowerraw);
	int i = 0;
	int j = 0;
	while (i + j < lowerraw.size()) {
		if (std::isalpha(lowerraw[i + j])) {
			j++;
		} else {
			if (j >= 2) {
            	// cout << lowerraw.substr(i, j) << endl << endl;
				ret.insert(lowerraw.substr(i, j));
			}
			i = i + j + 1;
			j = 0;
		}
		// cout << i << " " << j << " " << ret.size() << endl;
	}
	if (j >= 2) {
		ret.insert(lowerraw.substr(i, j));
        // cout << lowerraw.substr(i, j) << endl << endl;
	}
    return ret;
}

/**************************************************
 * COMPLETED - You may use the following functions
 **************************************************/

// Used from http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
// trim from start
std::string &ltrim(std::string &s) {
    s.erase(s.begin(), 
	    std::find_if(s.begin(), 
			 s.end(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))));
    return s;
}

// trim from end
std::string &rtrim(std::string &s) {
    s.erase(
	    std::find_if(s.rbegin(), 
			 s.rend(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))).base(), 
	    s.end());
    return s;
}

// trim from both ends
std::string &trim(std::string &s) {
    return ltrim(rtrim(s));
}

/* CMPS 2010 Fall 2019 - Lab 8
 * Name: Jonathan Doolittle
 * The purpose of this lab is to implement functions that
 * would be used in a string handling library. You do not
 * need to change anything in main(); only in the provided
 * function bodies
*/

#include <iostream>

using namespace std;

// Returns the length of str, not counting the null character
int length(const char * str)
{
	if(* str == '\0') return 0;
	int length = 1;
	while(* (str + length) != '\0') length++;
    return length;
}

// Returns a copy of the original string
char * copy(const char * original)
{
	int l = length(original);
	char * c = new char[l];
	for(int i = 0; i <= l; i++) *(c + i) = *(original + i);
	return c;
}

// Reverses str in-situ
void reverse(char * str)
{
	int l = length(str);
	char * c = copy(str);
	for(int i = 0; i < l; i++) *(str + i) = *(c + (l-(i+1)));
	delete [] c;
}

// Returns true if s1 and s2 are equal, false otherwise
bool equal(const char * s1, const char * s2)
{
	int l = length(s1);
	if(l == length(s2)) {
		for(int i = 0; i < l; i++) if(*(s1+i) != *(s2+i)) return false;
		return true;
	}
	return false;
}

// Returns true if the string is the same forwards and backwards
bool palindrome(const char * str)
{
	bool p = false;
	char * c = copy(str);
	reverse(c);
	if(equal(str, c)) p = true;
	delete [] c;
	return p;
}

// Returns a new string consisting of the characters between
// start and start + len in the original string.
char * substr(const char * str, int start, int len)
{
	char * s = new char[len];
	for(int i = 0; i < len; i++) *(s+i) = *(str+i+start);
	*(s + len) = '\0';
	return s;
}

void doThings(const char * s)
{
    cout << "String: " << s << endl;
    int l = length(s);
    cout << "Length: " << l << endl;
    char * sr = copy(s);
    reverse(sr);
    char * ss = substr(s, 3, l - 3);
    cout << "Substring: " << ss << endl;
    cout << "Reversed: " << sr << endl;
    cout << "Is palindrome? " << (palindrome(s) ? "Yes" : "No") << "\n\n";

    if (sr) delete [] sr;
    if (ss) delete [] ss;
}

/*
String: This is a string!
Length: 17
Substring: s is a string!
Reversed: !gnirts a si sihT
Is palindrome? No
 */

int main()
{
    doThings("This is a string!");
    doThings("Heeeeeeere's Johnny!");
    doThings("racecar");
    doThings("wow bob wow");

    char buffer[80];
    cout << "Enter your own string: ";
    cin.getline(buffer, 80);
    doThings(buffer);

    return 0;
}

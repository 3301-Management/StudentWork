#pragma once
#include <string>

using namespace std;

class call
{
public:
	call(string start, string end, string name);
	~call();
private:
	string s, e, zone;
};

class callarr
{
public:
	callarr(string icallurl);
	string* search(string in);
	~callarr();

private:
	string url;

};



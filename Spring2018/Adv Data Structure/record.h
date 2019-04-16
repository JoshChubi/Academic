#pragma once
#ifndef RECORD_H
#define RECORD_H

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

const unsigned NAMESIZE = 20;

class record
{
	int id;
	char name[NAMESIZE];
public:
	record();
	record(int inId, char inName[]);

	int getId() const;

	string getName() const;
};

#endif // !RECORD_H
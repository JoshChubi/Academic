#pragma once
#ifndef BUCKET_H
#define BUCKET_H

#include "record.h"

const int BUCKET_CAPACITY = 2;

class bucket
{
	int capacity = BUCKET_CAPACITY;
	record recData[BUCKET_CAPACITY];
public:
	void setRecord(int pos, record r);
	record getRecord(int pos)const;
};

#endif // !BUCKET_H

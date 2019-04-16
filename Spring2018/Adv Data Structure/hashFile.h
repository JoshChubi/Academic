#pragma once
#ifndef HASHFILE_H
#define HASHFILE_H

#include "bucket.h"

class hashFile
{
	fstream raf;

	int numBucket;
	int bucketCapacity = BUCKET_CAPACITY;
	int bucketSize;
	bucket myBucket;
public:
	hashFile(string fileName, int inNumBucket);

	int h(int k);
	int h2(int k);
	int insert(record r);

	int isRoom();

	void revealTable();
	void close();

	record retrive(int key);
};

#endif // !HASHFILE_H
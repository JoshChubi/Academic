#include "hashFile.h"

hashFile::hashFile(string fileName, int inNumBucket)
{
	numBucket = inNumBucket;

	bucketSize = sizeof(bucket);

	raf.open(fileName, ios::in | ios::out | ios::trunc | ios::binary);
	for (int i = 0; i < numBucket; i++)
	{
		raf.write((char *)&myBucket, bucketSize);
	}
}

int hashFile::h(int k)
{
	return k % numBucket;
}

int hashFile::h2(int k)
{
	return k % (numBucket - 2) + 1;
}

int hashFile::insert(record r)
{
	int i = 0;
	int bucketNum = (h(r.getId()) + i * h2(r.getId())) % numBucket;
	int homeBucket = bucketNum;
	int space;

	while (true)
	{
		raf.seekg(bucketNum*bucketSize);
		raf.read((char *)&myBucket, bucketSize);
		space = isRoom();
		if (space != -1)
		{
			myBucket.setRecord(space, r);
			raf.seekp(bucketSize*bucketNum);
			raf.write((char *)&myBucket, bucketSize);
			return bucketNum;
		}

		i++;
		bucketNum = (h(r.getId()) + i * h2(r.getId())) % numBucket;

		if (bucketNum == homeBucket)
		{
			cout << "ERROR: TABLE IS FULL" << endl;
			system("pause");
			exit(EXIT_FAILURE);
		}
	}
}

int hashFile::isRoom()
{

	for (int i = 0; i < bucketCapacity; i++)
	{
		if (myBucket.getRecord(i).getId() == 0)
		{
			return i;
		}
	}
	return -1;
}

void hashFile::revealTable()
{
	raf.seekg(0);
	for (int i = 0; i < numBucket; i++)
	{
		raf.read((char *)&myBucket, bucketSize);

		cout << "Bucket " << i << endl;
		for (int j = 0; j < bucketCapacity; j++)
		{
			cout << "\tRecord: " << j + 1 << " id=" << left << setw(8) << myBucket.getRecord(j).getId();
			if (myBucket.getRecord(j).getId())
				cout << "name=" << myBucket.getRecord(j).getName();
			cout << endl;
		}

	}
}

void hashFile::close()
{
	raf.close();
}

record hashFile::retrive(int key)
{
	int i = 0;
	int bucketNum = (h(key) + i * h2(key)) % numBucket;
	int homeBucket = bucketNum;

	while (true)
	{
		raf.seekg(bucketNum*bucketSize);
		raf.read((char *)&myBucket, bucketSize);

		for (int j = 0; j < bucketCapacity; j++)
		{
			if (myBucket.getRecord(j).getId() == key)
			{
				return myBucket.getRecord(j);
			}
		}

		i++;
		bucketNum = (h(key) + i * h2(key)) % numBucket;
		if (bucketNum == homeBucket)
			return record();
	}
}
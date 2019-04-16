#include "bucket.h"

void bucket::setRecord(int pos, record r)
{
	recData[pos] = r;
}

record bucket::getRecord(int pos)const
{
	return recData[pos];
}

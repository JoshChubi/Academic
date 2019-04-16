#include "record.h"

record::record()
{
	id = 0;
	for (int i = 0; i < NAMESIZE; i++)
	{
		name[i] = '\0';
	}
}

record::record(int inId, char inName[])
{
	id = inId;

	for (int i = 0; i < NAMESIZE; i++)
	{
		name[i] = inName[i];
	}
}

int record::getId()const
{
	return id;
}

string record::getName()const
{
	return name;
}
#include "hashFile.h"

int main()
{
	hashFile myHash("raf", 7);
	record desiredRec;

	int id;
	char name[NAMESIZE];

	cout << "Please Enter ID | Name: ";
	while (cin >> id && id != 0)
	{
		cin >> name;

		record data(id, name);

		cout << "ID: " << left << setw(14) << data.getId() << "Name: " << left << setw(15) << data.getName() << "Bucket: " << myHash.insert(data) << endl << endl;
		cout << "Please Enter ID | Name: ";
	}

	cout << endl;
	myHash.revealTable();
	cout << endl;

	cout << "Please Enter Desired ID: ";
	while (cin >> id && id != 0)
	{
		desiredRec = myHash.retrive(id);

		if (desiredRec.getId() != 0)
			cout << "ID: " << left << setw(14) << desiredRec.getId() << "Name: " << left << setw(15) << desiredRec.getName() << endl;
		else
			cout << "ID: " << id << " (not found)" << endl;
		cout << endl << "Please Enter Desired ID: ";
	} 

	myHash.close();
	system("pause");
	return 0;
}
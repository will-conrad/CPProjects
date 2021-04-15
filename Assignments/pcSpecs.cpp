#include<iostream>
using namespace std;

#define newl cout<<endl; //newl = new line

struct specs {
	//CPU
	char cpuModel[50];
	string isIntel;
	int cpuCores;
	//GPU
	string gpuModel;
	string isNvidia;
	//RAM
	int memory;
	//Storage
	double storage;
	//Power
	int psuWattage;
	//Extra
	string RGB;
	string isWaterCooled;
	string overclocked;
};

int main() {
	char in;
	specs pc;
	specs pc2;


	cout << "Enter CPU model: ";
	cin >> pc.cpuModel;

	cout << "Is it Intel? (y/n): ";
	cin >> in;
	if (in == 'y') {
		pc.isIntel = "Intel";
	}
	else {
		pc.isIntel = "AMD";
	}

	cout << "How many cores does your CPU have? ";
	cin >> pc.cpuCores;

	cout << "Enter GPU model: ";
	cin >> pc.gpuModel;

	cout << "Is it Nvidia? (y/n): ";
	cin >> in;
	if (in == 'y') {
		pc.isNvidia = "Nvidia";
	}
	else {
		pc.isNvidia = "Radeon";
	}

	cout << "Enter memory (GB): ";
	cin >> pc.memory;

	cout << "Enter storage capacity (GB): ";
	cin >> pc.storage;

	cout << "Enter wattage: ";
	cin >> pc.psuWattage;

	cout << "Does your computer have RGB lighting? (y/n): ";
	cin >> in;
	if (in == 'y') {
		pc.RGB = "has";
	}
	else {
		pc.RGB = "does not have any";
	}

	cout << "Is your computer water-cooled? (y/n): ";
	cin >> in;
	if (in == 'y') {
		pc.isWaterCooled = "water cooled";
	}
	else {
		pc.isWaterCooled = "not water cooled";
	}

	cout << "Is your computer overclocked? (y/n): ";
	cin >> in;
	if (in == 'y') {
		pc.overclocked = "overclocked";
	}
	else {
		pc.overclocked = "not overclocked";
	}

	newl;

	cout << "===================================================================" <<endl;
	cout << "PC SPECS | COMPUTER 1:" <<endl;
	cout << "CPU: " << pc.cpuCores << "-core " << pc.isNvidia << " " << pc.cpuModel <<endl;
	cout << "GPU: " << pc.isNvidia << " " << pc.gpuModel <<endl;
	cout << pc.memory << "GB of RAM" <<endl;
	cout << pc.storage << "GB of storage" <<endl;
	cout << "This computer " << pc.RGB << " juicy RBG goodness" <<endl;
	cout << "This computer is " << pc.isWaterCooled <<endl;
	cout << "This computer is " << pc.overclocked <<endl;
	
	newl;


	
	cout << "Enter CPU model: ";
	cin >> pc2.cpuModel;

	cout << "Is it Intel? (y/n): ";
	cin >> in;
	if (in == 'y') {
		pc2.isIntel = "Intel";
	}
	else {
		pc2.isIntel = "AMD";
	}

	cout << "How many cores does your CPU have? ";
	cin >> pc2.cpuCores;

	cout << "Enter GPU model: ";
	cin >> pc2.gpuModel;

	cout << "Is it Nvidia? (y/n): ";
	cin >> in;
	if (in == 'y') {
		pc2.isNvidia = "Nvidia";
	}
	else {
		pc2.isNvidia = "Radeon";
	}

	cout << "Enter memory (GB): ";
	cin >> pc2.memory;

	cout << "Enter storage capacity (GB): ";
	cin >> pc2.storage;

	cout << "Enter wattage: ";
	cin >> pc2.psuWattage;

	cout << "Does your computer have RGB lighting? (y/n): ";
	cin >> in;
	if (in == 'y') {
		pc2.RGB = "has";
	}
	else {
		pc2.RGB = "does not have any";
	}

	cout << "Is your computer water-cooled? (y/n): ";
	cin >> in;
	if (in == 'y') {
		pc2.isWaterCooled = "water cooled";
	}
	else {
		pc2.isWaterCooled = "not water cooled";
	}

	cout << "Is your computer overclocked? (y/n): ";
	cin >> in;
	if (in == 'y') {
		pc2.overclocked = "overclocked";
	}
	else {
		pc2.overclocked = "not overclocked";
	}

	newl;

	cout << "===================================================================" <<endl;
	cout << "PC SPECS | COMPUTER 2:" <<endl;
	cout << "CPU: " << pc2.cpuCores << "-core " << pc2.isNvidia << " " << pc2.cpuModel <<endl;
	cout << "GPU: " << pc2.isNvidia << " " << pc2.gpuModel <<endl;
	cout << pc2.memory << "GB of RAM" <<endl;
	cout << pc2.storage << "GB of storage" <<endl;
	cout << "This computer " << pc2.RGB << " juicy RBG goodness" <<endl;
	cout << "This computer is " << pc2.isWaterCooled <<endl;
	cout << "This computer is " << pc2.overclocked <<endl;
	
	newl;

	return 0;
}
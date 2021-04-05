using namespace std;

#define GITPTABLE system("open https://tamalweb.github.io/periodic-table/")
#define PTABLE system("open https://ptable.com/")
int AtomicNumber(string e) { //C to 6
	if (e == "H") {
		return 1;
	}
	else if (e == "He") {
		return 2;
	}
	else if (e == "Li") {
		return 3;
	}
	else if (e == "Be") {
		return 4;
	}
	else if (e == "B") {
		return 5;
	}
	else if (e == "C") {
		return 6;
	}
	else if (e == "N") {
		return 7;
	}
	else if (e == "O") {
		return 8;
	}
	else if (e == "F") {
		return 9;
	}
	else if (e == "Ne") {
		return 10;
	}
	else if (e == "Na") {
		return 11;
	}
	else if (e == "Mg") {
		return 12;
	}
	else if (e == "Al") {
		return 13;
	}
	else if (e == "Si") {
		return 14;
	}
	else if (e == "P") {
		return 15;
	}
	else if (e == "S") {
		return 16;
	}
	else if (e == "Cl") {
		return 17;
	}
	else if (e == "Ar") {
		return 18;
	}
	return 0;
}
double AtomicMass(string a) { //C to 12.011
	if (a == "H") {
		return 1.008;
	}
	else if (a == "He") {
		return 4.0026;
	}
	else if (a == "Li") {
		return 6.94;
	}
	else if (a == "Be") {
		return 9.0122;
	}
	else if (a == "B") {
		return 10.81;
	}
	else if (a == "C") {
		return 12.011;
	}
	else if (a == "N") {
		return 14.007;
	}
	else if (a == "O") {
		return 15.999;
	}
	else if (a == "F") {
		return 18.998;
	}
	else if (a == "Ne") {
		return 20.180;
	}
	else if (a == "Na") {
		return 22.990;
	}
	else if (a == "Mg") {
		return 24.305;
	}
	else if (a == "Al") {
		return 26.982;
	}
	else if (a == "Si") {
		return 28.085;
	}
	else if (a == "P") {
		return 30.974;
	}
	else if (a == "S") {
		return 32.06;
	}
	else if (a == "Cl") {
		return 35.45;
	}
	else if (a == "Ar") {
		return 39.948;
	}
	return 0;
}
string AtomicSymbol(string n) { //Carbon to C
	if (n == "Hydrogen") {
		return "H";
	}
	else if (n == "Helium") {
		return "He";
	}
	else if (n == "Lithium") {
		return "Li";
	}
	else if (n == "Beryllium") {
		return "Be";
	}
	else if (n == "Boron") {
		return "B";
	}
	else if (n == "Carbon") {
		return "C";
	}
	else if (n == "Nitrogen") {
		return "N";
	}
	else if (n == "Oxygen") {
		return "O";
	}
	else if (n == "Fluorine") {
		return "F";
	}
	else if (n == "Neon") {
		return "Ne";
	}
	else if (n == "Sodium") {
		return "Na";
	}
	else if (n == "Magnesium") {
		return "Mg";
	}
	else if (n == "Aluminium") {
		return "Al";
	}
	else if (n == "Silicon") {
		return "Si";
	}
	else if (n == "Phosphorus") {
		return "P";
	}
	else if (n == "Sulfur") {
		return "S";
	}
	else if (n == "Chlorine") {
		return "Cl";
	}
	else if (n == "Argon") {
		return "Ar";
	}
	return "Not valid";
}
string AtomicName(string s) { //C to Carbon
	if (s == "H") {
		return "Hydrogen";
	}
	else if (s == "He") {
		return "Helium";
	}
	else if (s == "Li") {
		return "Lithium";
	}
	else if (s == "Be") {
		return "Beryllium";
	}
	else if (s == "B") {
		return "Boron";
	}
	else if (s == "C") {
		return "Carbon";
	}
	else if (s == "N") {
		return "Nitrogen";
	}
	else if (s == "O") {
		return "Oxygen";
	}
	else if (s == "F") {
		return "Fluorine";
	}
	else if (s == "Ne") {
		return "Neon";
	}
	else if (s == "Na") {
		return "Sodium";
	}
	else if (s == "Mg") {
		return "Magnesium";
	}
	else if (s == "Al") {
		return "Aluminium";
	}
	else if (s == "Si") {
		return "Silicon";
	}
	else if (s == "P") {
		return "Phosphorus";
	}
	else if (s == "S") {
		return "Sulfur";
	}
	else if (s == "Cl") {
		return "Chlorine";
	}
	else if (s == "Ar") {
		return "Argon";
	}
	return "Not valid";
}
int IonicCharge(string e) { //N to -3
	if (e == "H") {
		return 1;
	}
	else if (e == "He") {
		//return 2;
	}
	else if (e == "Li") {
		return 1;
	}
	else if (e == "Be") {
		return 2;
	}
	else if (e == "B") {
		return 3;
	}
	else if (e == "C") {
		return 4;
	}
	else if (e == "N") {
		return -3;
	}
	else if (e == "O") {
		return -2;
	}
	else if (e == "F") {
		return 1;
	}
	else if (e == "Ne") {
		//return 10;
	}
	else if (e == "Na") {
		return 1;
	}
	else if (e == "Mg") {
		return 2;
	}
	else if (e == "Al") {
		return 3;
	}
	else if (e == "Si") {
		return 4;
	}
	else if (e == "P") {
		return -3;
	}
	else if (e == "S") {
		return -2;
	}
	else if (e == "Cl") {
		return -1;
	}
	else if (e == "Ar") {
		//return 18;
	}
	return 0;
}

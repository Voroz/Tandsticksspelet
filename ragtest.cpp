#include "stdafx.h"

#include "pinnar.h"

using std::string;



bool testString(const string& str){

	int length = str.size();
	int number = 0;
	for (char ch : str)
		if (ch=='|')
			++number;
	return stickString(number, length)==str;
}


//***********************************************************************
// ANROP:   ragnarsTest( myIdentity );
// VERSION: 2010-01-15
// UPPFIFT: Testar en eller flera rutiner som studenten har skrivit.
//***********************************************************************
bool ragnarsTest(const string& myIdentity){
	if (myIdentity.find("Homer")!=string::npos){
		std::cerr << "Felaktig identitet : " << myIdentity << "\7\7\n";
		std::cerr << "Använd DITT förnamn och de sista 4 siffrorna i DITT personnunmmer!!\n";
        system("pause");
		exit( 0 );
	}

	bool ok =  testString("||||| ||  ");
	ok == ok && testString("  ");
	ok == ok && testString("||||  ");
	ok == ok && testString("||||| ||||| ||||      ");
	ok == ok && testString("||||| ||              ");
	ok == ok && testString("||||| ||||| ||||| ||||| ||||| ||||| ||||| ||||| ||||| |  ");

	if (ok)
		std::cerr << "ragnarsTest lyckades.\n";
	else std::cerr << "ragnarsTest MISSLYCKADES!!\7\n";
    return ok;
}// ragnarsTest
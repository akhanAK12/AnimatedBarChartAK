/*
 Project 3  Animated Bar Chart
 File name: test.cpp Author: Arij Khan  NetId: akhan342  Course: CS 251
 System: Visual Studio
*/

#include <iostream>
#include "barchartanimate.h"
#include <fstream>
using namespace std;


bool testBarDefaultConstructor() { 
	Bar b;

    if (b.getName() != "") {
    	cout << "testBarDefaultConstructor: getName failed" << endl;
    	return false;
    } else if (b.getValue() != 0) {
    	cout << "testBarDefaultConstructor: getValue failed" << endl;
    	return false;
    } else if (b.getCategory() != "") {
    	cout << "testBarDefaultConstructor: getCategory failed" << endl;
    	return false;
    }
    cout << "testBarDefaultConstructor: ALL PASSED!"  << endl;
    return true;
}

bool testBarParamConstructor() {
	Bar b("Chicago", 9234324, "US");
    if (b.getName() != "Chicago") {
    	cout << "testBarParamConstructor: getName failed" << endl;
    	return false;
    } else if (b.getValue() != 9234324) {
    	cout << "testBarParamConstructor: getValue failed" << endl;
    	return false;
    } else if (b.getCategory() != "US") {
    	cout << "testBarParamConstructor: getCategory failed" << endl;
    	return false;
    }
    cout << "testBarParamConstructor:  ALL PASSED!" << endl;
    return true;
}

bool testBarChartDefaultConstructor() { 
	 BarChart bc; 
	 bc.setFrame(""); 
    if (bc.getSize() != 0) {
    	cout << "testBarDefaultConstructor: getName failed" << endl;
    	return false;
    } else if (bc.getFrame() != "") {
    	cout << "testBarDefaultConstructor: getValue failed" << endl;
    	return false;
    }
    cout << "testBarChartDefaultConstructor:  ALL PASSED!" << endl;
    return true;
}

bool testBarChartConstructor() {
	 BarChart bc(10); 
    if (bc.getSize() != 0) {
    	cout << "testBarDefaultConstructor: getName failed" << endl;
    	return false;
    } else if (bc.getFrame() != "") {
    	cout << "testBarDefaultConstructor: getValue failed" << endl;
    	return false;
    }
    cout << "testBarChartConstructor:  ALL PASSED!" << endl;
    return true;
}

bool testBarChartCopyConstructor(){

	BarChart bc1(10);
	bc1.setFrame("1950"); 
	bc1.addBar("Chicago", 1020, "USA"); 
	bc1.addBar("NYC", 1300, "US");
	
 
	BarChart bc2(bc1); 

    if(bc1.getSize() != bc2.getSize())
	{
		cout << "barChartCopyConstructor: getSize failed" << endl; 
		return false; 
	}
	else if(bc1.getFrame() != bc2.getFrame())
	{
		cout << "barChartCopyConstructor: getFrame failed" << endl; 
		return false;
	}
	else if(bc1[0].getCategory() != bc2[0].getCategory())
	{
		cout << "barChartCopyConstructor: getValue failed" << endl; 
		return false;
	}

	else if(bc1[0].getValue() != bc2[0].getValue())
	{
		cout << "barChartCopyConstructor: getValue failed" << endl; 
		return false;
	}
	else if(bc1[0].getName() != bc2[0].getName())
	{
		cout << "barChartCopyConstructor: getValue failed" << endl; 
		return false;
	}
	else if(bc1[1].getCategory() != bc2[1].getCategory())
	{
		cout << "barChartCopyConstructor: getValue failed" << endl; 
		return false;
	}
	else if(bc1[1].getValue() != bc2[1].getValue())
	{
		cout << "barChartCopyConstructor: getValue failed" << endl; 
		return false;
	}
	else if(bc1[1].getName() != bc2[1].getName())
	{
		cout << "barChartCopyConstructor: getValue failed" << endl; 
		return false;
	}

	else{
		cout << "testBarChartCopyConstructor: ALL PASSED!" << endl; 
		cout << endl;
		return true; 
	}

}

bool testBarChartCopyOperator(){
	BarChart bc(3);
	bc.setFrame("1950"); 
	bc.addBar("Berlin", 1400, "Germany"); 
	bc.addBar("Mr.Beast", 2017, "Youtube"); 
	BarChart bc2; 
	bc2 = bc; 
	
	if(bc.getSize() != bc2.getSize())
	{
		cout << "testBarChartCopy operator: FAILED" << endl; 
		return false; 
	}
	else if(bc.getFrame() != bc2.getFrame())
	{
		cout << "testBarChartCopy operator: FAILED" << endl; 
		return false; 
	}
	cout << "OPERATOR 1: " << endl;
	bc.dump(cout); 
	cout << endl; 
	cout << "COPIED OPERATOR: " << endl; 
	bc2.dump(cout);
	cout << "testBarChartCopy operator: ALL PASSED!" << endl;
	cout << endl;  
	return true; 

}

bool testBarChartClear(){
	BarChart bc (10); 
	bc.clear();

	if(bc.getSize() != 0)
	{
		cout << "testBarChartClear: getSize failed " << endl;
		return false;  
	} 
	else if(bc.getFrame() != "")
	{
		cout << "testBarChartClear: getFrame failed " << endl; 
		return false;
	}
	else{
		 cout << "testBarChartClear: ALL PASSED!" << endl;
    	return true;
	}
}

bool testBarChartAddBar(){ 
	
	BarChart bc(3); 
	 
	bc.addBar("Dehli", 1020, "India"); 
	bc.addBar("Hyderabad", 1300, "India");
	bc.addBar("Berlin", 1200, "Germany");

	if(bc[0].getName() != "Dehli" || bc[0].getValue() != 1020 || bc[0].getCategory() != "India")
	{
		cout << "testBarChartAddBar:  failed" << endl; 
		return false; 
	}
	else if(bc[1].getName() != "Hyderabad" || bc[1].getValue() != 1300 || bc[1].getCategory() != "India")
	{
		cout << "testBarChartAddBar:  failed" << endl; 
		return false; 
	}

	else if(bc[2].getName() != "Berlin" || bc[2].getValue() != 1200 || bc[2].getCategory() != "Germany")
	{
		cout << "testBarChartAddBar:  failed" << endl; 
		return false; 
	}
	
		cout << "testBarAddBar: ALL PASSED" << endl; 
 	    return true; 
	

}

bool testBarTestSetFrame(){
	BarChart bc(3); 
	bc.setFrame("1950"); 

	if(bc.getFrame() != "1950")
	{
		cout << "testBarTestSetFrame: FAILED getFrame " << endl; 
		return false; 
	}

	else{
		cout << "testBarTestSetFrame: ALL PASSED!" << endl; 
		return true; 
	}
	cout << endl; 
}

bool testBarChartTestDump(){
	BarChart bc(10);

	bc.setFrame("1950"); 
	bc.addBar("Chiefs", 21, "West");
	bc.addBar("Steelers", 1, "West");
	bc.addBar("Bears", 27, "North");
	cout << endl; 
	bc.dump(cout);  
	if(bc.getFrame() != "1950")
	{
		cout << "barChartTestDump: FAILED getFrame" << endl; 
		return false; 
	}
	else if(bc[0].getName() != "Bears")
	{
		cout << "barChartTestDump: FAILED getName27" << endl; 
		return false; 
	}
	else if(bc[1].getName() != "Chiefs")
	{
		cout << "barChartTestDump: FAILED getName21" << endl; 
		return false; 
	}
	else if(bc[2].getName() != "Steelers")
	{
		cout << "barChartTestDump: FAILED getName1" << endl; 
		return false; 
	}
	else if(bc[0].getValue() != 27)
	{
		cout << "barChartTestDump: FAILED getValue" << endl; 
		return false; 
	}
	else if(bc[1].getValue() != 21)
	{
		cout << "barChartTestDump: FAILED getValue" << endl; 
		return false; 
	}
	else if(bc[2].getValue() != 1)
	{
		cout << "barChartTestDump: FAILED getValue" << endl; 
		return false; 
	}
	else{
		cout << "barChartTestDump: ALL PASSED!" << endl;
		cout << endl; 
		return true; 
	}
}

bool testBarCapacity(){

	BarChart bc(2); //capacity = 2
	bc.addBar("SpiderMan", 2002, "Marvel"); 
	bc.addBar("Captain America", 1941, "Marvel"); 
	bc.addBar("Batman", 1939, "DC");

	//If our if condtion fails within the function 
	if(bc.getSize() > 2)
	{
		cout << "testBarCapacity: FAILED" << endl; 
		return false; 
	}

	else if(bc.getSize() == 2)
	{
		cout << "testBarCapacity: ALL PASSED!" << endl; 
		return true; 
	}

}

bool testBarChartAnimate(){ 
	string filename = "cities.txt";
	ifstream inFile(filename);
	string line; 
	string title;
	getline(inFile, title); //reads title line
	string xlabel;
	getline(inFile, xlabel);//reads in xlabel line
	string source;
	getline(inFile, source);//reads in source line
	getline(inFile, line); //reads in empty line

	BarChartAnimate bca(title, xlabel, source);
	if(!inFile.is_open())
	{
		cout << "testBarChartAnimate: file failed to open" << endl; 
		return false;  
	}
	while(!inFile.eof())
	{
		bca.addFrame(inFile); 
	}

	if(title == "" || xlabel == "" || source == "")
	{ 
		cout << "testBarChartAnimate: failed to store in strings from file" << endl; 
		return false; 
	}
	else if(bca.getSize() == 0)
	{ 
		cout << "testBarChartAnimate: getSize failed" << endl; 
		return false; 
	}
	else if(bca.getSize() != 519)
	{
		cout << "testBarCharAnimate: getSize failed" << endl; 
	}
	else if(title != "The most populous cities in the world from 1500 to 2018"){
		
		cout << "testBarChartAnimate: TITLE NOT READ IN CORRECTLY" << endl; 
		return false; 
	}
	else if(xlabel != "Population (thousands)")
	{
		cout << "testBarChartAnimate: XLABEL NOT READ IN CORRECTLY" << endl; 
		return false; 
	}
	else if(source != "Sources: SEDAC; United Nations; Demographia")
	{
		cout << "testBarChartAnimate: SOURCE NOT READ IN CORRECTLY" << endl; 
		return false; 
	}
	else{
		cout << endl; 
		cout << "FILE READ IN CORRECTLY" << endl; 
		cout << "testBarCharAnimate: ALL PASSED!" << endl;
		cout << endl; 
		return true; 
	} 

}

bool testBarChartTestGraph(){

	BarChart bc(3); 
	string red("\033[1;36m");
	string blue("\033[1;33m");
	map<string, string> colorMap;

	bc.addBar("Chicago", 1020, "US");
	bc.addBar("NYC", 1300, "US");
	bc.addBar("Paris", 1200, "France");
	bc.setFrame("1950"); 
	
	colorMap["US"] = red;
	colorMap["France"] = blue;
	bc.graph(cout, colorMap, 3); 
	cout << endl; 

	return true; 
}



int main() {

	testBarDefaultConstructor(); //->
	testBarParamConstructor(); //->
	testBarChartDefaultConstructor(); //->
	testBarChartConstructor(); //->
	testBarChartCopyConstructor();
	testBarChartCopyOperator(); 
	testBarChartClear(); 
	testBarChartAddBar(); 
	testBarTestSetFrame();
	testBarChartTestDump(); 
	testBarCapacity(); 
	testBarChartAnimate(); 
	testBarChartTestGraph();

    return 0;
}
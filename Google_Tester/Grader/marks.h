#pragma once
//////////////////////////////////////////////////////////////
// CIS 554 Grading for HW1                                  //
// Fall 2020                                                //
// Abel Armede - agarmede@syr.edu                           //
//////////////////////////////////////////////////////////////
#include "pch.h"
#include "Windows.h"
//#include "../Tester/HW1.h"
#include <fstream>

/////////////////////////////////////////////////////
// Grading Creteria
// group() 15 marks.
/////////////////////////////////////////////////////
//group()
#define	GROUP_AN_EMPTY_LIST 1
#define	GROUP_A_SMALL_GROUPED_LIST 2
#define GROUP_RANDOM_LIST 3
#define GROUP_FROM_TAIL 4
#define GROUP_LARGE_LIST 5
/////////////////////////////////////////////////////

#define MEMORY_LEAK 1
#define ADDED_MORE_NODES 2

//static ofstream myfile;

class Marks {
public:
	static int Rmarks;
	static int Mmarks;
	static std::string addRMark(int num) {
		//HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		//SetConsoleTextAttribute(hConsole, 14);
		std::string result = "\n Add " + std::to_string(num) + " marks... \n";
		std::cout << result ;
		//myfile << "\x1B[36m" + result + "\033[0m\t";
		Rmarks += num;
		return " ";
	}
	static std::string deductRMark(int num) {
		//HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		//SetConsoleTextAttribute(hConsole, 14);
		std::string result = "\n Deduct " + std::to_string(num) + " marks... \n";
		std::cout <<  result ;
		//myfile << "\x1B[36m" + result + "\033[0m\t";
		Rmarks -= num;
		return " ";
	}
	static std::string addMMark(int num) {
		//HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		//SetConsoleTextAttribute(hConsole, 14);
		std::string result = "\n Add " + std::to_string(num) + " marks... \n";
		std::cout << result ;
		//myfile << "\x1B[36m" + result + "\033[0m\t";
		Mmarks += num;
		return " ";
	}
	static std::string deductMMark(int num) {
		//HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		//SetConsoleTextAttribute(hConsole, 14);
		std::string result = "\n Deduct " + std::to_string(num) + " marks... \n";
		std::cout << result ;
		//myfile << "\x1B[36m" + result + "\033[0m\t";
		Mmarks -= num;
		return " ";
	}
};



#include "pch.h"
#include "marks.h"
#include <fstream>

int Marks::Rmarks = 0;
int Marks::Mmarks = 0;
//ofstream myfile (out_file);

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	
	//myfile.open(out_file);
	int result = RUN_ALL_TESTS();
	if (Marks::Rmarks < 0) Marks::Rmarks = 0;
	if (Marks::Mmarks < 0) Marks::Mmarks = 0;
	std::string finalMark = "\n The Final Mark is " + std::to_string(Marks::Rmarks + Marks::Mmarks);

	std::cout << finalMark << "\n";
	//myfile << finalMark << "\n";
	//std::cout << "\n If the test case throw exception, grade it manually.";
	//myfile.close();
	getchar();
	getchar();
	return result;
}
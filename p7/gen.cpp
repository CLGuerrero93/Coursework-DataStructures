// Author:         Cassandra Guerrero
// Creation Date:  01 December 2014
// Due Date:       04 December 2014
// Course:         CSC 237
// Professor:      Dr. Schaper
// Assignment:     #7
// Filename:       gen.cpp
// Purpose:        creates four .dat files containing 1000
//		   randomly generated rationals

#include <iostream>
#include <fstream>
#include "/export/home/student/cguer715/237/CodeBase/DataTypes/Rational/rational.h"
#include "/export/home/student/cguer715/237/CodeBase/RandomData/randomData.h"

using namespace std;

typedef int dT;

void createFile(ofstream& file);

int main()
{
  ofstream file;

  file.open("d1.dat");
  createFile(file);
  file.close();

  file.open("d2.dat");
  createFile(file);
  file.close();

  file.open("d3.dat");
  createFile(file);
  file.close();

  file.open("d4.dat");
  createFile(file);
  file.close();
 
  return 0;
}

void createFile(ofstream &file)
{
  randomData<dT> sequence;
  size_t index = 0;

  while (index < 1000)
    {
      if (index == 0)
	file<<sequence.getNextDataValue() << ' ';
      else if (index % 9 == 0)
	file<<sequence.getNextDataValue() << '\n';
      else 
	file<<sequence.getNextDataValue() << ' ';
      index++;
    }
  file<<endl;
}

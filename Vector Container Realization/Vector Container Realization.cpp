#include <iostream>
#include "Vector.h"
#include <locale.h>
#include <vector>
using namespace std;

int main()
{
	Vector<int> vec1;
	Vector<string> vec2(3, "numbers");

	for (int i = 0; i < 3; i++) {
		cout << vec2[i] << " ";
	}

	cout << "\n";
	cout << vec1.isempty();
	cout << "\n";

	Vector<int> vec4{ 1,2,3,4 };
	Vector<int> vec5(vec4);

	for (int i = 0; i < 4; i++) {
		cout << vec5[i] << " ";
	}

	cout << "\n";
	Vector<int> vec6{ 1,2,3,4,5 };
	Vector<int> vec7{ 1,2,3,4 };
	Vector<int> vec8{ 1,2,3,4,5 };

	cout << "Result of comparing two vectors(vec6, vec7): " << (vec6 == vec7) << "\n";
	cout << "Result of comparing two vectors(vec6, vec8): " << (vec6 == vec8) << "\n";

	Vector<int> vec9{ 1,2,3 };
	cout << "Capasity of vec9 before reserve: " << vec9.getCapacity() << "\n";
	vec9.reserve(10);
	cout << "Capasity of vec9 after reserve: " << vec9.getCapacity() << "\n";

	cout << "\n";

	cout << "Clear vec9 . . . ";

	vec9.clear();

	cout << "vec9 empty?: " << vec9.isempty() << "\n\n";

	Vector<int> vec10;

	vec10.reserve(5);

	cout << "Capacity of vec10: " << vec10.getCapacity() << "\n\n";


	Vector<int> vec11;

	vec11.push_back(1);

	cout << "Added number: " << vec11[0] << " Size: " << vec11.getSize() << " Capacity: " << vec11.getCapacity() << "\n";

	vec11.push_back(2); vec11.push_back(3);

	cout << "Added numbers: " << vec11[1] << " " << vec11[2] << " Size: " << vec11.getSize() << " Capacity: " << vec11.getCapacity() << "\n";

	vec11.pop_back();
	for (int i = 0; i < vec11.getSize(); i++) {
		cout << vec11[i] << " ";
	}

	cout << "\n\n";

	Vector<int> vec12{ 1,2,3,4,5,6,7,8,9,10 };

	cout << "vec12 after resize: ";
	for (int i = 0; i < vec12.getSize(); i++) {
		cout << vec12[i] << " ";
	}
	cout << "\n";
	vec12.resize(8);
	cout << "vec12 before resize: ";
	for (int i = 0; i < vec12.getSize(); i++) {
		cout << vec12[i] << " ";
	}
	cout << "\n";
	vec12.resize(12);
	cout << "vec12 before resize: ";
	for (int i = 0; i < vec12.getSize(); i++) {
		cout << vec12[i] << " ";
	}
	cout << "\n\n";

	Vector<int> vec13;

	vec13.reserve(3);
	vec13[0] = 1;

	cout << "vec13[0]: " << vec13[0];

	vec13[4] = 25;


	return 0;
}


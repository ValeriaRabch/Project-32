#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Line {
	char arr[100];
public:
	Line() {
		strcpy(arr, "");
	}
	Line(char* arr2) {
		strcpy(arr, arr2);
	}
	void SetArr(char* arr2) { strcpy(arr, arr2); };
	char* GetArr() { return arr; }
	void SetElement(int index, char element) { arr[index] = element; }
	char GetElement(int index) { return arr[index]; }

	Line operator * (Line arr2) {
		Line arr3;

		int index = 0;

		for (int i = 0; i < strlen(arr); i++) {
			for (int j = 0; j < strlen(arr2.GetArr()); j++) {

				if (arr[i] == arr2.GetElement(j)) {
					arr3.SetElement(index, arr[i]);
					index ++;
				}
			}
		}
		return arr3;
	}
	void Print() {
		for (int i = 0; i < strlen(arr); i++) {
			cout << arr[i] << ' ';
		}
		cout << endl;
	}
};

int main() {

	Line myarray1, myarray2, myarray3;

	char array[100];;

	cout << "Enter array 1 "; cin >> array;
	myarray1.SetArr((char*)array);
	myarray1.Print();

	cout << "Enter array 2 "; cin >> array;
	myarray2.SetArr((char*)array);
	myarray2.Print();

	myarray3 = myarray1 * myarray2;
	myarray3.Print();


	return 0;
}
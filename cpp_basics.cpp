#include <iostream>
#include <cstdlib>
#include <array>
#include <fstream>
using namespace std;

// to compile and execute:
// g++ cpp_basics.cpp && ./a.out

void display(int array[], int n){
	cout << "[ ";
	for(int i = 0; i < n; i++){
		cout << array[i] << " ";
	}
	cout << " ]" << endl << endl;
}

void triCroissant(int array[], int n){
	cout << "Sorting list by ascending order:" << endl;
	int temp = 0;

	// littéralement le tri à bulles
    for (int i = 0; i < n-1; ++i){
        for (int j = 0; j < n - i - 1; ++j){
            if (array[j] > array[j+1]) {
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
		}
    }
}

void triDécroissant(int array[], int n){
	cout << "Sorting list by descending order:" << endl;
	int temp;

    for (int i = 0; i < n-1; ++i){
        for (int j = 0; j < n - i - 1; ++j){
            if (array[j] < array[j+1]) {
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
		}
    }
}

void writeInTextFile(string filename){
	// Create and open a text file
	ofstream MyFile(filename);
	cout << "Writing in a text file: ";
	MyFile << "Lorem ispum dolor sit amet";
	MyFile.close();
	cout << "done !";
}

void readTextFile(string filename){
	string myText;
	ifstream MyReadFile(filename);

	while (getline (MyReadFile, myText)) {
		cout << myText << endl;
	}
	MyReadFile.close();
}

void displayWordByWord(string filename){
    fstream file;
    string word, t, q;
    file.open(filename.c_str());

    while (file >> word){
        cout << word << endl;
    }
}

int main(){
	readTextFile("header.txt");

	// cout << "CPP Basics: " << endl << endl;
	cout << endl << "- Arrays:" << endl;
	int randomNum = rand() % 101;
	int n = 5; // array size
	cout << "Enter a size for your array: ";
	cin >> n;

	cout << "Selected size is " << n << endl << endl;

	int* array = new int[n];

	for(int i = 0; i < n; i++){
		array[i] = rand() % 101;
	}

	cout << "Displaying array:" << endl;
	display(array, n);

	triCroissant(array, n);
	display(array, n);

	triDécroissant(array, n);
	display(array, n);

	cout << "Used for: 'simple' data structure, arrays of different types, sorting algorithms, graphs, etc" << endl << endl;

	cout << "- Matrix:" << endl;

	cout << "Displaying a matrix:" << endl;
	int matrix[4][4] = {
        {0, 1, 0, 1},
        {1, 0, 1, 0},
        {0, 1, 0, 0},
        {1, 0, 1, 0}
    };

    for(int i = 0; i < 4; i++){
		for(int j= 0; j < 4; j++){
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	cout << "Used for: graphs, adjacency matrix, etc" << endl << endl;
	

	cout << "- Text files:\nUsing filename.txt" << endl << endl;
	writeInTextFile("filename.txt");

	cout << "\nReading a text file: " << endl;
	readTextFile("filename.txt");

	cout << "\nDisplaying the text file word by word:" << endl;
	displayWordByWord("filename.txt");
	cout << endl;

	cout << "Used for: storing lots of data somewhere (in general). Can be used in graphs (if you have a set of vertices, edges and/or weights) and data structures and algorithms if you have a data set you want to have not hard-coded." << endl;
	
	return 0;
}
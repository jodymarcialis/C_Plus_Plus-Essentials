#include <iostream>
#include <array>
#include <string>
#include <fstream>
using namespace std;

//To compile and execute:
// clear && g++ algorithms.cpp && ./a.out

enum class EnumTris {
    triTas,
    triRapide,
    triBulle,
    triInsertion,
    triFusion,
    invalide
};

// Used to display the header in terminal
void readTextFile(string filename){
    string myText;
    ifstream MyReadFile(filename);

    while (getline (MyReadFile, myText)) {
        cout << myText << endl;
    }
    MyReadFile.close();
}

void display(int array[], int n){
	cout << "[ ";
	for(int i = 0; i < n; i++){
		cout << array[i] << " ";
	}
	cout << " ]" << endl << endl;
}

void TriBulle(int arr[], int n) {
	cout << "• Tri à bulles ~ Complexité: O(n²)" << endl;
    cout << "\nExplications: On parcours le tableau, et si l'élément courant est supérieur au suivant, on échange les deux en utilisant une variable tampon." << endl;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
          
            // Swap if the element found is greater than the next element
            if (arr[j] > arr[j + 1]) 
                swap(arr[j],arr[j+1]);
        }
    }
}

void TriInsertion(int arr[], int n)
{
	cout << "• Tri insertion ~ Complexité:" << endl;
	cout << "Meilleurs cas: O(n) | Cas moyen: O(n²) | Pire cas: O(n²)" << endl;
	cout << "\nExplications: on parcours le tableau de gauche à droite. Chaque élément parcouru du tableau est inséré à la bonne place parmi les éléments déjà triés" << endl;
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;

        /* Move elements of arr[0..i-1], that are
           greater than key, to one position ahead
           of their current position */
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Sépare le tableau en argument en deux tableaux
// un allant de left à mid, l'autre allant de mid à right
void merge(int array[], int left, int mid, int right){
                         
    int n1 = mid - left + 1;
    int n2 = right - mid;

  	//  vector<int> L(n1), R(n2); 
    int tempArray1[n1], tempArray2[n2];
    // ^ Deux tableaux temporaires pour le découpage dichotomique du tableau "parent"

    // Copy data to temp vectors L[] and R[]
    for (int i = 0; i < n1; i++)
        tempArray1[i] = array[left + i];
    for (int j = 0; j < n2; j++)
        tempArray2[j] = array[mid + 1 + j];

    int i = 0, j = 0;
    int k = left;

    // Merge the temp vectors back 
    // into arr[left..right]
    while (i < n1 && j < n2) {
        if (tempArray1[i] <= tempArray2[j]) {
            array[k] = tempArray1[i];
            i++;
        }
        else {
            array[k] = tempArray2[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of tempArray1[], if there are any
    while (i < n1) {
        array[k] = tempArray1[i];
        i++;
        k++;
    }

    // Copy the remaining elements of tempArray2[], if there are any
    while (j < n2) {
        array[k] = tempArray2[j];
        j++;
        k++;
    }
}

void TriFusion(int array[], int left, int right){
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;
    TriFusion(array, left, mid);
    TriFusion(array, mid + 1, right);
    merge(array, left, mid, right);
}

// utile pour le tri rapide
int partition(int array[], int a, int b) {
    int pivot = array[b];
  
    // undex of smaller element and indicates 
    // the right position of pivot found so far
    int i = a - 1;

    for (int j = a; j <= b - 1; j++) {
        if (array[j] < pivot) {
            i++;
            swap(array[i], array[j]);
        }
    }
    
    swap(array[i + 1], array[b]);  
    return i + 1;
}

// the QuickSort function implementation
void TriRapide(int array[], int a, int b) {
    if (a < b) {
      
        // pi is the partition return index of pivot
        int pi = partition(array, a, b);

        // recursion calls for smaller elements
        // and greater or equals elements
        TriRapide(array, a, pi - 1);
        TriRapide(array, pi + 1, b);
    }
}

// On transforme le tas/la liste en tas max
void heapify(int array[], int n, int i){
    int plusGros = i;

    // left index = 2*i + 1
    int gauche = 2 * i + 1;

    // right index = 2*i + 2
    int droit = 2 * i + 2;

    // If left child is larger than root
    if (gauche < n && array[gauche] > array[plusGros])
        plusGros = gauche;

    // If right child is larger than largest so far
    if (droit < n && array[droit] > array[plusGros])
        plusGros = droit;

    // If largest is not root
    if (plusGros != i) {
        swap(array[i], array[plusGros]);

        heapify(array, n, plusGros);
    }
}

void TriTas(int array[], int n){
	cout << "Tri tas ~ complexité: O(n log n)" << endl;
	cout << "\nExplications: On transforme la liste en tas max, dont on prend la racine successivement, qu'on met à la fil du tableau jusqu'à ce qu'il soit trié." << endl << endl;

    // Build heap (rearrange vector)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(array, n, i);

    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--) {
        swap(array[0], array[i]);
        heapify(array, i, 0);
    }
}

EnumTris stringToEnum(const std::string& str) {
       if (str == "triBulle") {
           return EnumTris::triBulle;
       } else if (str == "triInsertion") {
           return EnumTris::triInsertion;
       } else if (str == "triRapide") {
           return EnumTris::triRapide;
       } else if (str == "triTas") {
           return EnumTris::triTas;
       } else if (str == "triFusion") {
           return EnumTris::triFusion;
       }{
           // Handle the case when the input string is not recognized
           // You can throw an exception or return a default value
       	return EnumTris::invalide;
       }
 }

int main(){
    readTextFile("header2.txt");

	cout << "• Algorithmes de tris" << endl << endl;
	int randomNum = rand() % 101;
	int n = 15;

	int* array = new int[n];

	for(int i = 0; i < n; i++){
		array[i] = rand() % 101;
	}

	string triSelectionne = "";

	cout << "Sélectionnez un tri à effectuer:\ntriBulle, triInsertion, triRapide, triFusion, triTas\n>>>";
	cin >> triSelectionne;

	cout << "Affichage de la liste avant le tri:" << endl;
	display(array, n);

	EnumTris value = stringToEnum(triSelectionne);

	switch(value){
		case(EnumTris::triBulle):
			TriBulle(array,n);
			display(array, n);
			break;
		case(EnumTris::triInsertion):
			TriInsertion(array, n);
			display(array, n);
			break;
		case(EnumTris::triRapide):

            cout << "• Tri rapide ~ Complexité: \nPire cas: O(n²) | Cas moyen: O(n log n) | Meilleurs cas: O(n log n)" << endl;
            cout << "Complexité: Meilleurs cas: O(n log n) | Cas moyen: O(n log n) | Pire cas: O(n²) \n(on parcours les éléments n fois à droite et n fois à gauche?)" << endl;
            cout << "\nExplications: On choisit une valeur pivot, puis un trie la partie à gauche du pivot, puis celle de droite en les partitionnant au prélable" << endl << endl;
			TriRapide(array, 0, n-1);
			display(array, n);
			break;
		case(EnumTris::triTas):
			TriTas(array, n);
			display(array, n);
			break;
		case(EnumTris::triFusion):
            cout << "Tri fusion ~ Complexité: O(O log n) (Meilleur/moyen/pire cas)" << endl;
            cout << "\nExplications: on divise le tableau en 2 récursivement jusqu'à ce qu'on ait plus que 2 valeurs dans le tableau. On compare ces deux valeurs (ce qui donnt un sous-tableau trié), et on fusionne ces séquences triées, pour avoir à la fin un tableau trié." << endl << endl;
			TriFusion(array, 0, n-1);
			display(array, n);
			break;
		default:
			cout <<endl;
	}


    readTextFile("complexity.txt");

	return 0;
}
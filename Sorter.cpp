#include <iostream>
#include <thread> 
#include <chrono> 
#include <iomanip> 
using namespace std;
using namespace std::chrono;

class Sort {
private:
    int *arr;
    int size, i, j, temp;

public:
    void input();
    void display();
    void BubbleSort();
    void InsertionSort();
    void QuickSort(int low, int high);
    int Partition(int low, int high);
    int getSize() const;
};

/////////////////////////////////////////////////

void Sort::input() {

    cout<<"\n****************Sorter******************\n";
    cout << "\nEnter size of array : ";
    cin >> size;

    cout << endl << "add numbers  \n";
    arr = new int[size];
    for (i = 0; i < size; i++) {
        cout << "number[" << i << "]: ";
        cin >> arr[i];
    }
}

/////////////////////////////////////////////////

void Sort::BubbleSort() {
    for (i = 0; i < size - 1; i++)
        for (j = 0; j < size - 1; j++)
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
}

/////////////////////////////////////////////////

void Sort::InsertionSort() {
    for (int i = 1; i < size; i++) {
        temp = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > temp) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = temp;
    }
}

/////////////////////////////////////////////////

void Sort::QuickSort(int low, int high) {
    if (low < high) {
        j = Partition(low, high);
        QuickSort(low, j - 1);
        QuickSort(j + 1, high);
    }
}

/////////////////////////////////////////////////

int Sort::Partition(int low, int high) {
    int pivot = arr[high]; 
    int i = (low - 1); 

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++; 
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return (i + 1);
}

/////////////////////////////////////////////////

int Sort::getSize() const {
    return size;
}

/////////////////////////////////////////////////

void Sort::display() {
    for (i = 0; i < size; i++)
        cout << arr[i] << "\t";
    cout << endl;
}

/////////////////////////////////////////////////

int main() {
    int sel;
    Sort sort;
    sort.input();

    cout<<"\n****************************************\n";
    cout<<"1.Bubble Sort \n";
    cout<<"2.Insertion Sort \n";
    cout<<"3.Quick Sort \n";
    cout<<"select :";
    cin>>sel;
    cout<<"\n****************************************\n";

    switch (sel)
    {
        case 1:{
            cout <<"      Bubble Sort"<<endl;
            cout << "Sorted array without threads:" << endl;
            auto start = high_resolution_clock::now(); 
            sort.BubbleSort();
            auto stop = high_resolution_clock::now(); 
            auto duration = duration_cast<microseconds>(stop - start);
            sort.display();
            cout << "Sorted array without threads time: " << fixed << setprecision(8) << duration.count() / 1000000.0 << " seconds" << endl;
            cout << endl;

            cout << "Sorted array with threads:" << endl;
            start = high_resolution_clock::now(); 
            sort.BubbleSort();
            stop = high_resolution_clock::now(); 
            duration = duration_cast<microseconds>(stop - start);
            sort.display(); 
            cout << "Sorted array with threads time: " << fixed << setprecision(8) << duration.count() / 1000000.0 << " seconds" << endl;
            break;
        }

        case 2:{
            cout <<"      Insertion Sort"<<endl;
            cout << "Sorted array without threads:" << endl;
            auto start = high_resolution_clock::now(); 
            sort.InsertionSort();
            auto stop = high_resolution_clock::now(); 
            auto duration = duration_cast<microseconds>(stop - start);
            sort.display();
            cout << "Sorted array without threads time: " << fixed << setprecision(8) << duration.count() / 1000000.0 << " seconds" << endl;
            cout << endl;

            cout << "Sorted array with threads:" << endl;
            start = high_resolution_clock::now(); 
            sort.InsertionSort();
            stop = high_resolution_clock::now(); 
            duration = duration_cast<microseconds>(stop - start);
            sort.display(); 
            cout << "Sorted array with threads time: " << fixed << setprecision(8) << duration.count() / 1000000.0 << " seconds" << endl;
            break;
            } 

        case 3:{
            cout <<"      Quick Sort"<<endl;
            cout << "Sorted array without threads:" << endl;
            auto start = high_resolution_clock::now(); 
            sort.QuickSort(0, sort.getSize() - 1);
            auto stop = high_resolution_clock::now(); 
            auto duration = duration_cast<microseconds>(stop - start);
            sort.display();
            cout << "Sorted array without threads time: " << fixed << setprecision(8) << duration.count() / 1000000.0 << " seconds" << endl;
            cout << endl;

            cout << "Sorted array with threads:" << endl;
            start = high_resolution_clock::now(); 
            sort.QuickSort(0, sort.getSize() - 1);
            stop = high_resolution_clock::now(); 
            duration = duration_cast<microseconds>(stop - start);
            sort.display(); 
            cout << "Sorted array with threads time: " << fixed << setprecision(8) << duration.count() / 1000000.0 << " seconds" << endl;
            break;
            } 
        
        default:
            cout<<"The entered number is not correct \n";
            break;
        }

    // cout << "Sorted array without threads:" << endl;
    // auto start = high_resolution_clock::now(); 
    // sort.QuickSort(0, sort.getSize() - 1);
    // auto stop = high_resolution_clock::now(); 
    // auto duration = duration_cast<microseconds>(stop - start);
    // sort.display();
    // cout << "Sorted array without threads took: " << fixed << setprecision(8) << duration.count() / 1000000.0 << " seconds" << endl;
    // cout << endl;

    // cout << "Sorted array with threads:" << endl;
    // start = high_resolution_clock::now(); 
    // sort.QuickSort(0, sort.getSize() - 1);
    // stop = high_resolution_clock::now(); 
    // duration = duration_cast<microseconds>(stop - start);
    // sort.display(); 
    // cout << "Quick sort with threads took: " << fixed << setprecision(8) << duration.count() / 1000000.0 << " seconds" << endl;

    return 0;
}

#include <bits/stdc++.h>
using namespace std;


int arr[100];
int n=0;
void create() {

    cout << "Enter array length ";
    cin >> n;
    cout << "Enter numbers"<<endl;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
}

void display() {
    cout << "Displaying Array";
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void insert() {
    int index;
	int value;
    cout << "Enter position ";
    cin >> index;
    cout << "Enter value: ";
    cin >> value;
    for(int i = n; i > index; i--)
        arr[i] = arr[i - 1];
    arr[index] = value;
	n++;
}

void del() {
    int pos;
    cout << "Enter position ";
    cin >> pos;
   
    for(int i = pos; i < n - 1; i++)
        arr[i] = arr[i + 1];
    n--;
}

void linear_search() {
    int b;
    cout << "Enter value to search: ";
    cin >> b;
    for(int i = 0; i < n; i++) {
        if(arr[i] == b) {
            cout << "Found at index " << i << endl;
        }
    }

}

int main() {
    int choice;
    do {
        cout << "1.CREATE\n2.DISPLAY\n3.INSERT\n4.DELETE\n5.LINEAR SEARCH\n6.EXIT"<<endl;
        cin >> choice;
        switch(choice) {
            case 1: 
                create(); 
                break;
            case 2: 
                display(); 
                break;
            case 3: 
                insert(); 
                break;
            case 4: 
                del(); 
                break;
            case 5:
                linear_search();
                break;
            case 6: 
                break;
            default: cout << "Invalid choice!\n";
        }
    } while(choice!=6);
    return 0;
}

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

void addStudent(){
    ofstream f("db.txt",ios::app); //ifstream = input, db.txt = file name, ios = choice mode, append = adding in last
    // instead of ifstream we write ofstream because we need to give output in form of "f" given below so we dont need of ifstream
    string rn,name,div,add; //string = characters

    cout<<"Enter Student roll no.: ";
    cin>>rn;
    cout<<"Enter Name of Student: ";
    cin>>name;
    cout<<"Enter Division of Student: ";
    cin>>div;
    cout<<"Enter Address of the Student: ";
    cin>>add;

    f << left << setw(20) << rn << setw(20) << name << setw(20) << div << setw(20) << add << endl;

    f.close();

    cout<<"Student Added Successfully!\n";
}

void deleteStudent(){ //take data of file into memory, delete the line which not wanted 
// reprint the data in the file 
    ifstream f("db.txt"); 
    string line;

    string rn;
    cout << "Enter roll no. of Student to Delete: ";
    cin >> rn;

    string fileData;

    while(getline(f,line)){
        if(line.find(rn) == string::npos) //line.find() = line me find karo roll no. he ya nahi
        // npos = non position, when we not get right roll no. it will return npos
        {
           fileData += line;
           fileData += "\n";
        }
    } // here we eliminate desired roll no. result in deletion 
    f.close();

    ofstream f1("db.txt",ios::out); // for delete previous data 
    f1 << fileData;
    f1.close();

    // basicall we reset the file:
    //1. copy the lines except the line contain the roll no. which the user want to delete to memory 
    //2. clear all data from file 
    //3. re-write all the data from memory to file 
    // which results into deletion of desired roll no.

}

void searchStudent(){
    ifstream f("db.txt"); 
    string line;

    string rn;
    cout << "Enter roll no. of Student to Search: ";
    cin >> rn;

    bool found = false;

    while(getline(f,line)){
        if(line.find(rn) != string::npos)
        //if we skip != string::npos we will get the top line which contain roll no.,name,div,adr
        //line.find() = line me find karo roll no. he ya nahi
        // npos = non position, when we not get right roll no. it will return npos
        {
            cout<<"Student Details:"<<endl;
            cout<<line<<endl;
            found = true;
            break;
        }
    }
    f.close();

    if(!found){
        cout<<"Student Doesn't Exist!"<<endl;
    }
}

void printStudent(){
    ifstream f("db.txt"); 
    string line;
    cout<<"\nPrinting file data..."<<endl;
    while(getline(f,line)){
        cout<<line<<endl;
    }
    cout<<"Printing complete!\n";
    f.close();
}


int main(){

    ofstream f("db.txt",ios::out); // for clearning old existing data, jevha apn navin veles program run karu tevha
    f << left << setw(20) << "roll no." << setw(20) << "Name" << setw(20) << "Division" << setw(20) << "Address"<<endl; // it get already printed at begging/top of the txt file
    // basically left = for starting at very begging or for removal of space at begging
    f.close();

    int ip;
    while(ip != -1){
        cout << "\n\nEnter your choice\n1. Add student\n2. Delete student \n3. Search student \n4. Print data \n5. Exit\n---> ";
        cin>>ip;
        switch(ip){
            case 1:
                addStudent();
                break;
            case 2:
                deleteStudent();
                break;
            case 3:
                searchStudent();
                break;
            case 4:
                printStudent();
                break;
            case 5:
                return 0; // without return 0 it will doesn't exit from the program
                break;
            default:
                cout<<"Please re-enter your choice: ";
                break;
        }
    }
}

/*In summary, the space complexity is O(n) (where n is the number of students), 
and the time complexity of each operation can be considered as O(n) or O(1) depending on the specific operation.*/
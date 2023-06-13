#include<iostream>
using namespace std;
#define max 20

class stud
{
int mks[max]; //array of marks   max is nothing but the array size which we define.

public:
    stud() //constructor  which is initializing the array over here.
    {
    for(int i=0;i<max;i++)
      mks[i]=0; //in initializing the array we insert 0's from 1st to last position in array.
    }

    void insertheap(int tot); //to insert element into heap. 
    void displayheap(int tot); //to display data from heap.
    void showmax(int tot); //to show max heap.
    void showmin(); // to show min heap.
};

// We declare some function in the class stud,
// And now we are writing the defination of the function outside the class.

void  stud::insertheap(int tot) // the count total from main function we just pass here as int tot.
{
 for(int i=1;i<=tot;i++) //eg. tot=10 so it will as 10 times to enter the marks.
 {
   cout<<"enter marks";
   cin>>mks[i];

    int j=i; //eg. i = 1 so j = 1 here 1 is the position in array not marks.
    int par=j/2;  //eg. par = 1/2 = 0.5 = 0 (integer), par = 2/2 = 1.
    while(mks[j]<=mks[par] && j!=0) // here it will compare the marks of j and marks of partition 
     {
        int tmp = mks[j]; // here we use swapping technique
        mks[j]=mks[par];
        mks[par]=tmp;
        j=par; // again we comparing and swapping the position until first position or 0.
        par=j/2;
     }       
 }
}

void stud::displayheap(int tot)
{
int i=1,space=6;
cout<<endl;
while(i<=tot)
{
    if(i==1 || i==2 || i==4 || i==8 || i==16)
    {
    cout<<endl<<endl;
    for(int j=0;j<space;j++)
         cout<<" ";
    space-=2;   
    }
   cout<<" "<<mks[i];i++;
         
}
}

void stud::showmax(int tot)
{
    int max1=mks[1];
    for(int i=2;i<=tot;i++)
    {
        if(max1<mks[i])
        max1= mks[i];
    }
    cout<<"Max marks:"<<max1;
}

void stud::showmin() //
{
    cout<<"Min marks:"<<mks[1];
}


int main(){
int ch,count,total;
stud s1; //we creat s1 object of class stud so we can access the member functions.

do
{
cout<<endl<<"Menu";
cout<<endl<<"1.Read marks of the student: ";
cout<<endl<<"2.Display Min heap: "; // min heap = root element is less than child element.
cout<<endl<<"3.Find Max Marks: ";
cout<<endl<<"4.Find Min Marks: ";
cout<<endl<<"Enter Your Choice: ";
cin>>ch;
switch(ch)
{
case 1:
    cout<<"how many students";
    cin>>total;
    s1.insertheap(total); // Call insert function to insert elements. 
    break;
case 2:
    s1.displayheap(total); // Call display function.
    break;
case 3:    
    s1.showmax(total); // To find max element.
    break;
case 4:
    s1.showmin(); // To find min element.
    break;
}
cout<<endl<<"do u want to continue?(1 for continue)";
cin>>count;
}while(count==1);
return 0; // it is an intiger main so it returning 0.
}


/*
The space complexity of this code is O(max), where max is the constant defined as 20. 
This is because the array mks has a fixed size of max, and no additional memory is dynamically allocated.

The time complexity of the insertheap function is O(totlog(tot)), where tot is the total number of students
*/
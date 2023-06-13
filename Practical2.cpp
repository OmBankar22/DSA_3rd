/*Consider telephone book database of N clients. Make use of a hash table implementation to quickly look up client‘s telephone number. 
Make use of two collision handling techniques and compare them using number of comparisons required to find a set of telephone number*/

#include<iostream>
#define max 10
using namespace std;

struct phonebook{
    string name;
    long long int phone;
}; //end of the structure

class Hashtable{
    phonebook ht[max]; //array for/of hash table

    public:
    Hashtable() //constructor
    {
        for(int i=0;i<max;i++){
            ht[i].name = "No Name";
            ht[i].phone = 0;
        }
    }

    int hash(long long int); // for hash function, phone is our key and name is our value //function for returing the index value
    void insert(string,long long int);
    void del(long long int);
    void search(long long int);
    void display();
};

int Hashtable::hash(long long int phone){ // Hash-function = for returning the index position in the table using phone no.
    return (phone%max);
}

void Hashtable::insert(string name,long long int phone) //Normal 
{
    int index = hash(phone);
    if(ht[index].phone==0){
        ht[index].phone=phone;
        ht[index].name=name;
        cout<<"\nInformation Added successfully"<<endl;
    }

    else //collision 
    {
        int choice;
        cout<<"\n collision occured"<<endl;
        cout<<"1.Linear \n2.Qudratic "<<endl;
        cin>>choice;

        if(choice==1) // linear
        {
            for(int i = (index+1)%max;(i%max)<max;(i++)%max){
                if(ht[i].phone==0)
                {
                    ht[i].phone = phone;
                    ht[i].name = name;
                    cout<<"Information added successfully"<<endl;
                    break;
                }
            }
        }
    }

}

void Hashtable::del(long long int phone){

    cout<<"Enter phone number to be deleted: ";
    cin>>phone;

    int index = hash(phone);

    if(ht[index].phone==phone){
        ht[index].phone=0;
        ht[index].name="No Name";
        cout<<"Successfully Deleted!"<<endl;
    }

    else //for other indexes
    {
        for(int i=(index+1)%max;(i%max)<max;(i++)%max){
            if(ht[i].phone==phone){
                ht[i].phone=0;
                ht[i].name="No Name";
                cout<<"Successfully Deleted !"<<endl;
                break;
                
            }
        }
    }
}

void Hashtable::search(long long int phone){
    cout<<"Enter the phone no. to be searched: ";
    cin>>phone;

    bool found = false;

    int index = hash(phone);

    if(ht[index].phone==phone){
        found = true;
        cout<<"Position of the desired phone no. is: "<<index<<endl;
        cout<<"Name associated with the phone no. is: "<<ht[index].name<<endl;
       
    }

    else{// checking for rest of index in table
        for(int i=(index+1)%max;(i%max)<max;(i++)%max){
            if(ht[i].phone==phone){
                found = true;
                index = i;
                cout<<"Position of the desired phone no. is: "<<index<<endl;
                cout<<"Name associated with the phone no. is: "<<ht[index].name<<endl;
                break;
            }
        }
    }
    if(!found){
        cout<<"Phone no. is invalide please re-enter!"<<endl;
    }
}


void Hashtable::display(){
    cout<<"\nDisplaying the PhoneBook......."<<endl;
    cout<<"Sr no.   Name            phone"<<endl;
    
    for(int i=0;i<max;i++){
        cout<<i<<"       "<<ht[i].name<<"            "<<ht[i].phone<<endl;
    }

}


int main(){

    string name;
   long long int ch,phone;
    Hashtable h1;

    do{
        cout<<"\nMenu \n1.Insert \n2.Delete \n3.Search \n4.Display \n5.Exit \n-----> ";
        cin>>ch;

        switch(ch){
            case 1: 
                cout<<"Enter Name: ";
                cin>>name;
                cout<<"Enter Phone No.: ";
                cin>>phone;
                h1.insert(name,phone);
                break;
            
            case 2: 
                h1.del(phone);
                break;

            case 3:
                h1.search(phone);
                break;

            case 4: 
                h1.display();
                break;

            case 5:
                return 0;
                break;

            default: 
                cout<<"Enter Valide Option!"<<endl;
                break;
        }
    }while(ch!=-1);
    return 0;
}


/* The time complexity of the code is O(N) for insertion, deletion, and search operations, 
and the space complexity is O(N) due to the fixed-size hash table and the storage requirements for each element.
*/
/*There are flight paths between cities. If there is a flight between city A and city B then there is an edge between the cities. 
The cost of the edge can be the time that flight take to reach city B from A, or the amount of fuel used for the journey. 
Represent this as a graph. The node can be represented by airport name or name of the city. 
Use adjacency list representation of the graph or use adjacency matrix representation of the graph.
Check whether the graph is connected or not. Justify the storage representation used.
*/


#include<iostream> 
#include<string.h>
#include<queue>
using namespace std;

class flight
{ 	 
	public:
		int am[10][10]; //amount array
        char city_index[10][10]; //city array
		flight(); //constructor
	   	int create();
	   	void display(int city_count);
        bool check(int city_count);
};

flight::flight() //constructor of class flight
{
	int i,j;
	for(i=0;i<10;i++)
	{
		strcpy(city_index[i],"xx");
	}
	for(i=0;i<10;i++)
	{
		for(j=0;j<10;j++)
		{
			am[i][j]=0;
		}
	}
}

int flight::create()
{
	int city_count=0,j,si,di,wt;
	char s[10],d[10],c;
	do
	{
		cout<<"\n\tEnter Source City      : ";
		cin>>s;
		cout<<"\n\tEnter Destination City : ";
		cin>>d;
		for(j=0;j<10;j++)
		{
			if(strcmp(city_index[j],s)==0) // it will compare,
			break; // if the source city is already available, then break
		}
		if(j==10)
		{
			strcpy(city_index[city_count],s); //if not present,
			city_count++; // then copy that source city 
		} // initially city.count = 0;

		for(j=0;j<10;j++) 
		{
			if(strcmp(city_index[j],d)==0)
			break;
		}

		if(j==10)
		{
			strcpy(city_index[city_count],d);
			city_count++;
		}

		cout<<"\n\t Enter Distance From "<<s<<" And "<<d<<": ";
		cin>>wt;

		for(j=0;j<10;j++)
		{
			if(strcmp(city_index[j],s)==0)
				si=j; // getting the position of source city 
			if(strcmp(city_index[j],d)==0)
				di=j; // getting the position of destination city
		} 

		am[si][di]=wt;
		cout<<"\n\t Do you want to add more cities.....(y/n) : ";
		cin>>c;	
	}while(c=='y'||c=='Y');
 return(city_count); // without return it will into loop
 // we already declare this funtion as an integer so it return something 
} // how many no. of city we enter 


void flight::display(int city_count)
{
	int i,j;
	cout<<"\n\t Displaying Adjacency Matrix :\n\t";

	for(i=0;i<city_count;i++){ // for printing horitozontly city name (j)
		cout<<"\t"<<city_index[i];}
	cout<<"\n";

	for(i=0;i<city_count;i++) // for printing verticaly city name and amount/cost (i)
	{
		cout<<"\t"<<city_index[i];
		for(j=0;j<city_count;j++)
		{
		  	cout<<"\t"<<am[i][j];	
		}
		cout<<"\n";
	}
}

bool flight::check(int city_count){
	bool visited[10] = {false};
	visited[0]= true;

	queue<int>q;
	q.push(0);

	while(!q.empty()){
		int current = q.front();
		q.pop();

		for(int i=0;i<city_count;i++){
			if(am[current][i]!=0 && !visited[i]){
				visited[i]=true;
				q.push(i);
			}
		}
	}

	for(int i =0;i<city_count;i++){
		if(!visited[i]){
			return false;
		}
	}

	return true;
}

int main()
{
	flight f;
	int n,city_count;
	char c;
	do
	{
		cout<<"\n\t*** Flight Main Menu *****";
		cout<<"\n\t1. Create \n\t2. Adjacency Matrix\n\t3. check\n\t4. Exit";
		cout<<"\n\t.....Enter your choice : ";
		cin>>n;
		switch(n)
		{
			case 1:
					city_count=f.create(); //call create function which returns count
					break;
			case 2:
					f.display(city_count);
					break;
			case 3:
					if(f.check(city_count)){
						cout<<"Graph is connected!";
					}
					else{
						cout<<"Graph is not connected!";
					}
					break;
			case 4:
					return 0;
		}
		cout<<"\n\t Do you Want to Continue in Main Menu....(y/n) : ";
		cin>>c;
	}while(c=='y'||c=='Y');
	return 0;
}

// time complexity = O(m^2)
// space complexity of the code is O(1)
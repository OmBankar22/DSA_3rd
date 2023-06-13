/*
Therefore, the overall time complexity of the code depends on the specific operation being performed, ranging from O(1) to O(n^2 + e), 
and the space complexity is O(n^2) for the adjacency matrix and O(n) for auxiliary data structures used in different operations.
*/

#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int main() {
	int n,e; int ch; int type;
	cout<<"Enter type of graph\n1. Directed Graph\n2. Undirected Graph\nEnter your choice: ";
	cin>>type;

	" input - - - - - - - - - - - - - - - - -";

    cout<<"No. of vertices: ";
    cin>>n;
    bool adj_mat[n+1][n+1] = {};

    cout<<"No. of edges: ";
    cin>>e;
    
    cout<<"Enter edges:\n";
    for(int k=0;k<e;k++) {
        int i,j;
        cin>>i>>j;
        adj_mat[i][j] = 1;
        if(type==2) {
            adj_mat[j][i] = 1;
        }
    }
	
	// - - - - - - - - - - - - - - - - -

	while(1) {
		cout<<"* * * * Menu * * * *\n";
		cout<<"\n1. Adjacency Matrix\n2. Adjacency List\n3. BFS\n4. DFS\n5. Exit\nEnter your choice: ";
		cin>>ch;
		switch(ch) {
			case 1:		// adjacency matrix - - - - - - - - - - - - - - - - -
			{
				cout<<"\n\nThe adjacent matrix is\n\t";
				for(int i=1;i<=n;i++) cout<<i<<"\t";
				
				cout<<endl;
				for(int i=1;i<=n;i++) {
					cout<<i<<"\t";
					for(int j=1;j<=n;j++) {
						cout<<adj_mat[i][j]<<"\t";
					}
					cout<<endl;
				}
			}
			break;
			// - - - - - - - - - - - - - - - - -

			case 2:		// adjacency list - - - - - - - - - - - - - - - - -
			{
				cout<<"\n\nThe adjacency list is\n";
				for(int i=1;i<=n;i++) {
					cout<<i;
					for(int j=1;j<=n;j++) {
						if(adj_mat[i][j]) {
							cout<<" --> "<<j;
						}
					}
					cout<<endl;
				}
			}
			break;
			// - - - - - - - - - - - - - - - - -

			case 3:			// bfs traversal - - - - - - - - - - - - - - - - -
			{
				int v;
				bool visited[n+1] = {};
				visited[0]=true;
				queue<int> q;
				
				cout<<"Starting vertex for bfs traversal: ";
				cin>>v;
				cout<<"\nThe bfs traversal is ";
				q.push(v);
				visited[v] = 1;

				while(!q.empty()) {
					v=q.front();
					cout<<v;
					q.pop();
					for(int k=1;k<=n;k++) {
						if(adj_mat[v][k] && !visited[k]) {
							q.push(k);
							visited[k]=1;
						}
					}
				}
				cout<<"\n\n";
			}
			break;
			// - - - - - - - - - - - - - - - - -

			case 4:		// dfs traversal - - - - - - - - - - - - - - - - -
			{
				int v;
				bool visited[n+1] = {};
				stack<int> s;
				cout<<"Starting vertex for dfs traversal: ";
				cin>>v;
				cout<<"\nThe dfs traversal is ";
				s.push(v);
				visited[v] = 1;

				while(!s.empty()) {
					v=s.top();
					cout<<v;
					s.pop();
					for(int k=1;k<=n;k++) {
						if(adj_mat[v][k] && !visited[k]) {
							s.push(k);
							visited[k]=1;
						}
					}
				}
				cout<<"\n\n";
			}

			break;
			// - - - - - - - - - - - - - - - - -

			case 5:		//Exit - - - - - - - - - - - - - - - - -
			cout<<"\n\n";
			return 0;

			default:
			cout<<"Invalid choice!\nPlease try again\n";
			// - - - - - - - - - - - - - - - - -
		}
	}
}
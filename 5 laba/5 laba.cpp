#include <iostream>
#include <queue>
using namespace std;
int main()
{
	queue<int> Queue; //announce the queue
	const int n = 7;
	//adjacency matrix
	int mas[n][n] = {
	{ 0, 1, 0, 0, 0, 1, 0 },
	{ 1, 0, 0, 1, 0, 0, 0 },
	{ 0, 0, 0, 1, 0, 0, 0 },
	{ 0, 1, 1, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 1 },
	{ 0, 0, 0, 0, 1, 1, 0 } };
	int tops[n]; //graph vertices
	for (int i = 0; i < n; i++)
		tops[i] = 0; //all vertices are not yet open (0)
	Queue.push(0); //select the first vertex, put it in the queue
	cout << "Traversal of the graph: " << endl;
	while (!Queue.empty()) // if the queue is not empty
	{
		int top = Queue.front(); //top of the queue
		Queue.pop();
		tops[top] = 2; //the top is reached
		for (int j = 0; j < n; j++)
		{ //search for adjacent vertices (passing along the line where the number is the number of the vertex + 1)
			if (mas[top][j] == 1 && tops[j] == 0)//if the vertex is adjacent and not reached

			{
				Queue.push(j); //add a vertex to the queue
				tops[j] = 1; //the top is open
			}
		}
		cout << top + 1 << endl; //vertex number
	}
	system("pause");
	return 0;
}

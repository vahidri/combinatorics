#include<iostream>
#include<vector>

using namespace std;

int permutations(int n, vector<int> a)
{
	static int num_permutations=0;
	if (n==(a.size() - 1))
	{
		for (int i=0; i<a.size(); i++)
			cout<<a[i]<<" ";
		cout<<endl;
		num_permutations++;
	}
	else
	{
	for (int i=n+1; i<=a.size(); i++)
	{
		permutations(n+1, a);
		if (i<a.size())
		{
			int temp=a[n];
			a[n]=a[i];
			a[i]=temp;
		}
	}
	return num_permutations;
	}
}
int main()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	cout<<permutations(0, v);
	return 0;
}


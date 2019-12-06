/*
Vahid Ramazani
the 4 coding questions
*/

#include<iostream>
#include<vector>
using namespace std;

#define ull unsigned long long
#define ui unsigned int

#define OneOverE 0.36787944117144232159552377016146

ull fact (ui k);
ull comb (ui n, ui r);
ull catalan(ui n);
ull surj(ui m , ui n);

//1 to 12  [ n>12 => memory overflow ]
ull derangementCount(ui n);
ull derangementApproxCount(ui n);

ull power(ui b , ui p);

void derangedPermutations(ui n, vector<ui> a);
bool isDeranged(vector<ui> a);
void derangementPrint(ui n);

ui q3Permutations(ui n, vector<int> a);
int sgn(int inp);
bool q3Condition(vector<int> a);
ull Q3(ui n);

void Q4(ui m, ui n , ui j);

int main()
{
	cout<<"94222035\nExer2\nChoose an Option:\n";
	cout<<"1. Q1: Printing Derangements for 1 to n" <<endl;
	cout<<"2. Q2: Catalan 1 to 20" <<endl;
	cout<<"3. Q3" <<endl;
	cout<<"4. Q4" <<endl;
	cout<<endl;
	
	ui opt=0;
	cin>>opt;
	
	ui n;

	switch(opt)
	{
		case 1:
			cout<<"Enter n ";
			cin>>n;
			cout<<"Count: "<<derangementCount(n)<<endl;
			derangementPrint(n);
			break;
		case 2:
			for(ui i=1;i<20;i++)
				cout<<"Catalan("<<i<< ") = "<< catalan(i) <<endl;
			break;
		case 3:
			/*
			cout<<"L[0] - L[1]"<<endl;
			cout<<"(2n-1)! - Sigma[i=0 to n-1] : (-1)^i * comb(i,0) * S[i+1]" << endl;
			*/
			cout<<"Enter n ";
			cin>>n;
			cout<<"\nCount: "<<Q3(n)<<endl;
			break;
		case 4:
			cout<<"Enter m n j"<<endl;
			ui m,j;
			cin>>m>>n>>j;
			Q4(m , n , j);
			break;		
		default:
			cout<<"Wrong Input"<<endl;
			break;
	}
	
return 0;
}

ull power(ui b , ui p)
{
	ull o=b;
	for(ui k=2; k<=p ; k++)
		o*=b;
	return o;
}

ull fact (ui k)
{
	ull o=1;
	for(ull i=2;i<=k;i++)
		o*=i;
	return o;
}

ull comb (ui n, ui r)
{
	return fact(n)/fact(r)/fact(n-r);
}

ull catalan(ui n)
{
	double o=1;
	for(ui k=2*n ; k>n ; k--)
		o*=(double)k/(k-n);
	o/=n;
return o;	
}

ull surj(ui m , ui n)
{
	ull o=0;
	int s=1;
	for(ui k=0; k<=n; k++)
	{
		o+= s * comb(n , n-k) * power(n-k , m);
		s=-s;
	}
	return o;
}

void Q4(ui m , ui n , ui j)
{
	if(m<n){
		cout<<"Wrong Input: m<n"<<endl;
		return;
	}
	cout<< surj(m-1 , n-1) + surj(m-1 , n)<<endl;
}

ull derangementApproxCount(ui n)
{
	double aprox = 0;
	aprox = OneOverE * fact(n);
	if(0==n%2)
		return 1+ (long) (aprox);
	//else
		return (long) (aprox);
}

ull derangementCount(ui n)
{
	double a=0;
	int s=1;
	for(ui i=0; i<=n; i++)
	{
		a+= s / (double) (fact(i));
		s=-s;
	}
	a*=fact(n);
	return a;
}

void derangedPermutations(ui n, vector<ui> a)
{
	static ui count=0;
	if (isDeranged(a) && n==(a.size() - 1))
	{
		count++;
		cout<<count<<". ";
		for (ui i=0; i<a.size(); i++)
			cout<<a[i]<<" ";
		cout<<endl;
	}
	else
		for (ui i=n+1; i<=a.size(); i++)
		{
			derangedPermutations(n+1, a);
			if (i<a.size())
			{
				ui temp=a[n];
				a[n]=a[i];
				a[i]=temp;
			}
		}
}

bool isDeranged(vector<ui> a)
{
	for(ui i=0; i<a.size() ; i++)
		if(i+1==a[i])
			return 0;
	return 1;
}

void derangementPrint(ui n)
{
	vector<ui> ve;
	for(ui i=1;i<=n;i++)
		ve.push_back(i);
	derangedPermutations(0,ve);
}

ui q3Permutations(ui n, vector<int> a)
{
	static ui count=0;
	if (q3Condition(a) && n==(a.size() - 1))
	{
		count++;
		cout<<count<<". ";
		for (ui i=0; i<a.size(); i++)
			cout<<a[i]<<" ";
		cout<<endl;
	}
	else
		for (ui i=n+1; i<=a.size(); i++)
		{
			q3Permutations(n+1, a);
			if (i<a.size())
			{
				int temp=a[n];
				a[n]=a[i];
				a[i]=temp;
			}
		}
	return count;
}

bool q3Condition(vector<int> a)
{
	//0 false
	//1 true (OK)
	if(  sgn(a[0]) == sgn( a[a.size()-1] )  ) //first and last(<= round table) , same gender?
		return 0;

	if( a[0] == -a[a.size()-1] )  //first and last(<= round table) , couple?
		return 0;

	
	for(ui i = 0; i< a.size()-1 ; i++)
		if( sgn(a[i]) == sgn(a[i+1]) ) // adjacent same gender?
			return 0;
	
	for(ui i = 0 ; i <a.size()-1 ; i++)
		if (a[i] == -a[i+1] ) // adjacent couple?
			return 0;

	return 1;
}

ull Q3(ui n)
{
	vector<int> coup;
	for(int i = 1; i<=n;i++)
	{
		coup.push_back(-i);
		coup.push_back(i);
	}
	return q3Permutations( 0 , coup);
}

int sgn(int inp)
{
	if(inp==0)
		return 0;
	if(inp>0)
		return 1;
	if(inp<0)
		return -1;
}


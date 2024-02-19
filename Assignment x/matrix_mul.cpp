#include <iostream>
#include <climits>
using namespace std;
int main()
{
	int n;
	cout<<"Enter the no of matrix";
	cin>>n;
	
	int dim[2*n];
	cout<<"Enter dimensions"<<endl;
	int idk[n][n] = {0};
	int kmat[n][n] = {0};
	int m,x;
	
	for(int o=0;o<2*n;o= o+2)
	{
		cout<<"Matrix "<<o+1;
		cin>>dim[o];
		cin>>dim[o+1];
	}
	int f = 0,j=0,i=-1;
	while(true)
	{
		//cout<<"1 enter";
		i = i+1;
		j = i+1;
		j = j + f;
		
			//cout<<"2 enter"
			cout<<"__"<<f<<"__";
			m = INT_MAX;
			for(int k=i;k<j;k++)
			{
				//cout<<"3 enter";
				x = idk[i][k] + idk[k+1][j] + dim[2*(i+1) - 2]*dim[2*(k+1) - 1]*dim[2*(j+1)-1];
						
				if(x<m)
				{
					m = x;
					kmat[i][j] = k+1;
					idk[i][j] = x;
				}
				
			}
		if(i == 0 && j == n-1) break;
		if(j==3)
		{
			i =-1;
			f++;
		}
	}
	
	for(int i = 0;i<n;i++)
	{
		cout<<endl;
		for(int j=0;j<n;j++)
		{
				cout<<idk[i][j]<<"    ";
		}
		cout<<endl;
    }
    
    for(int i = 0;i<n;i++)
	{
		cout<<endl;
		for(int j=0;j<n;j++)
		{
				cout<<kmat[i][j]<<"    ";
		}
		cout<<endl;
    }
    cout<<"((";
    int g = 0;
    for(int p=0;p<n;p++)
    {
    	cout<<"A"<<p+1;
    	if(kmat[0][p] == kmat[0][p+1] && g == 0) {g=1; continue;}
    	else if (p+1 == 4) cout<<")";
    	else if (g == 1) cout<<"))(";	
    	else cout<<")(";	
	}

	return 0;
}
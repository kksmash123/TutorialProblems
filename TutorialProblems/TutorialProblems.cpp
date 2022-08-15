#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;


int LargestElement(vector<int> v) 
{
	int max_ele1=INT_MIN;
	int max_ele2 = INT_MIN;

	for (int x : v)
		cout << x << " ";
	cout << endl;

	//basic method
	for (int i = 0;i < v.size();i++)
		max_ele1 = v[i] > max_ele1 ?v[i] : max_ele1;
	cout << "Max element (method 1) -> " << max_ele1 << endl;

	//in built function to find max element 
	max_ele2 = *max_element(v.begin(), v.end());
	cout <<"Max element (method 2) -> " << max_ele1<<endl;

	// for normal array 
	int a[] = { -2,3,4,-1,5,-12,6,1,-13 };
	int n = sizeof(a) / sizeof(a[0]);

	cout <<"using max_element -> " << *max_element(a, a + n) << endl;
	cout <<"using min_element -> " << *min_element(a, a + (n - 1)) << endl;

	//single line code without using the variable
	return *max_element(v.begin(), v.end());
}







//using kadane's algorithm in maximum subarray sum -> o(n) time complexity

int subarraySum3(int a[],int n )
{
	int cs = 0, ms = 0;

	for (int i = 0;i < n;i++)
	{
		cs += a[i];
		cs = cs < 0 ? 0:cs;
		ms = max(ms, cs);
	}
	return ms;
}



//Using prefix array to reduce the time complexity 
//calculate sum using the prefix array with O(1) time complexity

void subarraySum2()
{
	int a[] = { -2,3,4,-1,5,-12,6,1,3 };
	int n = sizeof(a) / sizeof(a[0]);
	int sum = 0, maxsum = 0;
	int p[] = { 0,0,0,0,0,0,0,0,0 };

	for (int i = 0;i < n;i++)
	{
		p[i] = (i > 0) ? (p[i - 1] + a[i]) : a[i];
	}
	
	/*for (int x : p)
		cout << x << " ";
	*/

	for (int i = 0;i < n;i++)
	{
		for (int j = i;j < n;j++)
		{
			sum = i > 0 ? p[j]-p[i-1] : p[j];
			maxsum = max(sum, maxsum);
		}
		
	}
	//Display the output -- maximum 
	cout << "Maximum subarray sum " << endl;
	cout << maxsum << endl;
}


// Brute force approach --Approach 1 to the problem subarray sum maximum value

void subarraySum1()
{
	int a[] = { -2,3,4,-1,5,-12,6,1,3 };
	int n = sizeof(a) / sizeof(a[0]);
	int sum = 0, maxsum = 0;

	for (int i = 0;i < n;i++)
	{
		for (int j = i;j < n;j++)
		{
			for (int k = i;k <= j;k++)
			{
				sum += a[k];

			}
			maxsum = max(sum, maxsum);
			sum = 0;

		}
	}

	// Display output
	cout << "Maximum Subarray sum " << endl;
	cout << maxsum << endl;


}


int main()
{
	//subarraySum1();
	//subarraySum2();

	/*int a[] = { -2,3,4,-1,5,-12,6,1,3 };
	int n = sizeof(a) / sizeof(a[0]);

	cout<<subarraySum3(a, n);*/

	vector<int> v = { -2,3,4,-1,5,-12,6,1,3 };
	cout<<"output -> " << LargestElement(v);

}
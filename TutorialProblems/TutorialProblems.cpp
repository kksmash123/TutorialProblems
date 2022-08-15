#include<iostream>

using namespace std;




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
	subarraySum1();

}
/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>


using namespace std;

void
print_vect (vector < int >vec, int n)
{
  for (int i = 0; i < n; i++)
    {
      cout << vec[i];
    }
}

int
binary_search (vector < int >arr, int low, int high, int key)
{
  if (high < low)
    {
      return -1;
    }
  int mid = (low + high) / 2;
  if (key == arr[mid])
    {
      return mid;
    }
  if (key > arr[mid])
    {
      return binary_search (arr, mid + 1, high, key);
    }
  return binary_search (arr, low, mid - 1, key);

}

int
main ()
{
  vector < int >vect
  {
  1, 2, 3, 4, 5, 6, 7, 8, 9};
  int key = 3;
  int n = vect.size ();

  int element_pos = binary_search (vect, 0, n, key);
  cout << element_pos << endl;


  return 0;
}

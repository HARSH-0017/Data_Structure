/*Bubble sort is a simple sorting algorithm that continuously steps through the list and compares the adjacent pairs to
  sort the elements. In contrast, selection sort is a sorting algorithm that takes the smallest
  value (considering ascending order) in the list and moves it to the proper position in the array.
  1)NO. OF COMPARISONS:
      Selection sort performs a smaller number of swaps compared to bubble sort.
      The total number of comparisons in bubble sort is, therefore, is (n - 1) + (n - 2)... (2) + (1) = n(n - 1)/2 or O(n2)
      Number of selection sort comparisons  =  1/2(N2+N)
  2)NO. OF SWAPS:
      Selection sort performs (at most) n – 1 swaps between data elements,
      while the bubble sort swaps n * (n – 1) / 2 elements in the worst case (when the list is sorted in reverse order).

*/
#include <iostream>
using namespace std;
//Function Implementing Bubble Sort Algorithm
void bubble_sort(int arr[],int n){
    int i=0,j=1,t=n-1;
    int no_of_swap=0;
    int no_of_comp=0;
    while(t>0){
        while(j<=t){
            if(arr[i]>arr[j]){swap(arr[i],arr[j]);no_of_swap++;}
            i++,j++;
            no_of_comp++;
        }
        t--;
        i=0,j=1;
    }
    cout<<" . Number of SWAP:"<<no_of_swap<<endl;
    cout<<" . Number of COMPARISON:"<<no_of_comp<<endl;
    cout<<" . [INPLACE SORTING ALGORITHM USED]"<<endl;
}

//Function that returns index of minimum value in an array
int min_ind(int arr[],int si,int ei){
    //Initialising minimum value as first element of array
    int m=arr[si];             //m=minimum value in array
    int min_ind=si;           //min_ind=index holding minimum value
    for(int i=si;i<=ei;i++){
        int min_prev=m;
        m=min(m,arr[i]);
        if(m<min_prev){min_ind=i;}
    }
    return min_ind;
}

//Function Implementing Selection-Sort Algorithm
void selection_sort(int arr[],int n){
    //si=starting index
    //ei=ending index
    int si=0,ei=n-1;
    int no_of_swap=0;
    int no_of_comp=0;
    while(si<ei){
    int mi=min_ind(arr,si,ei);  //mi=index holding minimum value
    no_of_comp=no_of_comp+(ei-si+1);
    if(si!=mi){swap(arr[si],arr[mi]);
    no_of_swap++;}
    si++;
    }
    cout<<" . Number of SWAP:"<<no_of_swap<<endl;
    cout<<" . Number of COMPARISON:"<<no_of_comp<<endl;
    cout<<" . [INPLACE SORTING ALGORITHM USED]"<<endl;
}

//Function to print the array
void pfun(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    //n=number of elements in the array
    int n;
    //taking number of elements as input from the user
    cout<<"Enter number of elements in array:";cin>>n;
    //array of size n
    int arr1[n];int arr2[n];
    //taking array as input from the user
    cout<<"Enter elements of array:";
    for(int i=0;i<n;i++){int a;cin>>a;arr1[i]=a;arr2[i]=a;}
    //printing array before sorting
    cout<<"\nARRAY before sorting:";pfun(arr1,n);
    cout<<endl;
    //sorting array using bubble sort and printing it
    cout<<"BUBBLE SORT"<<endl;
    bubble_sort(arr1,n);
    cout<<" . ARRAY After Sorting Using Bubble Sorting:";pfun(arr1,n);
    cout<<endl;
    //sorting array using insertion sort and printing it
    cout<<"SELECTION SORT"<<endl;
    selection_sort(arr2,n);
    cout<<" . ARRAY After Sorting Using Selection Sorting:";pfun(arr2,n);
}
/*

BONUS QUESTION

TIME COMPLEXITY OF BUBBLE SORT
   In the worst-case scenario, the outer loop runs O(n) times.
   As a result, the worst-case time complexity of bubble sort is O(n x n) = O(n x n) (n2).


TIME COMPLEXITY OF SELECTION SORT
   The worst case is when the array is completely unsorted or sorted in descending order. So, we will traverse the entire
   array for checking, and in each iteration, we will perform the searching operation. After searching, we will swap the
   element at its correct position. As we know that the swapping only takes a constant amount of time i.e. O(1)O(1) so
   the worst time complexity of selection sort also comes out to be O(N^2).

*/

#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED

#include "infor.h"

void swap(InfoMember *a, InfoMember *b)
{
    InforMember temp = *a;
    *a = *b;
    *b = temp;
}


int partition (InfoMember **arr, int low, int high)
{
	int pindex = low;			// cac phan tu trong doan 0->pindex-1 la  partion < pivot
	InfoMember *pivot = *(arr+high);		// arr[high] = (con tro chua dia chi thanh vien thu high)
	int i;

	// Duyet mang arr : gap phan tu be hon pivot thi doi cho no voi arr[pindex], pindex cuoi cung se la vi tri cho pivot
	for (i = low; i <= high; i++) {
		if (arr[i]->id < pivot->id) {
			swap(arr[i], arr[pindex]);
			pindex++;
		}
	}
	swap(arr[pindex], arr[high]);

	return pindex;


}


/*  
    a[][] is the array, p is starting index, that is 0, 
    and r is the last index of array.  
*/
void quickSort(InfoMember **a, int p, int r)    
{
    if(p < r)
    {
        int q;
        q = partition(a, p, r);
        quickSort(a, p, q-1);
        quickSort(a, q+1, r);
    }
}

// call quickSort(members, 0, nmember-1);

#endif // SORT_H_INCLUDED

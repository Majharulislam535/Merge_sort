#include<bits/stdc++.h>

using namespace std;

 void merges(int ar[],int l,int r,int mid){

       int l_size = mid - l +1;
       int r_size = r-mid;

       int L[l_size+1];
       int R[r_size+1];

       for(int i=l,j=0;i<=mid;i++,j++){
           L[j]=ar[i];
       }
       for(int i=mid+1,j=0;i<=r;i++,j++){
          R[j]=ar[i];
       }

       L[l_size] = INT_MAX;
       R[r_size] = INT_MAX;

       int lp = 0 ,rp=0;
       for(int i=l;i<=r;i++){
         if(L[lp]<=R[rp]){
             ar[i] = L[lp];
             lp++;
         }
         else{
             ar[i] =R[rp];
             rp++;
         }
       }
 }

 void merge_sort(int ar[],int l,int r){
     if(l == r){
         return;
     }

     int mid = (l+r)/2;
     merge_sort(ar,l,mid);
     merge_sort(ar,mid+1,r);

     merges(ar,l,r,mid);

 }



int main()
{

     int n = 8;
     int ar[]={12,7,3,9,2,5,4,18};
     merge_sort(ar,0,n);

     for(int i:ar){
         cout<<i<<" ";
     }

    return 0;
}



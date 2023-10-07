#include<bits/stdc++.h>

using namespace std;

void merges(int ar[],int l,int m,int r){
    int lsize = m-l+1;
    int rsize = r-m;

     int L[lsize],R[rsize];

     int k=0;
     for(int i=0;i<lsize;i++){
         L[k]=ar[i];
         k++;
     }

     k=0;
     for(int i=m+1;i<=r;i++){
          R[k]=ar[i];
          k++;
     }

     int i=0,j=0;
      int cur=l;
     while(i<lsize && j<rsize){

          if(L[i] <= R[j]){
               ar[cur]=L[i];
              i++;
          }
          else{
             ar[cur]=R[j];
             j++;
          }
          cur++;
     }

     while(i<lsize){
         ar[cur]=L[i];
         i++;
         cur++;
     }
     while(j<rsize){
         ar[cur]=R[j];
         j++;
         cur++;
     }

}


int main() {


  int n;
  cin>>n;
  int ar[n];

  for(int i=0;i<n;i++){
      cin>>ar[i];
  }

  merges(ar,0,3,n-1);



  for(int i=0;i<n;i++){
      cout<<ar[i]<<" ";
  }
    return 0;
}

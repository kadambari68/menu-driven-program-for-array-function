#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<limits.h>
int a[80],b[80],c[80];
int m,n,p,i,j,ele,pos,temp,v;
int enter();
void display();
int search();
void insert();
void del();
void merge();
int sort();
int lsearch(int[], int, int);
int BSearch(int[],int,int);
void bubblesort(int[], int);
void insort(int[],int);
void selsort(int[],int);
int find(int[],int,int);
int insertsorted(int[], int,int,int) ;
int find_ele(int[],int,int);
int delete_ele(int[],int,int);
void merg(int[],int,int[],int,int[]);

void main()
{
clrscr();
   int choice;
   char c;
   do {
	cout<<"\n********************MENU********************\n";
	cout<<" [1] Input\n [2] Display\n [3] Search (Linear and Binary)\n [4]Sort (Insertion,Selection,Bubble)\n [5]Insert(Sorted and Unsorted)\n [6] Delete(Sorted and Unsorted)\n [7]Merge sort\n";
	cout<<"********************************************";
	cout<<"\nEnter your choice:";
	cin>>choice;
      switch(choice)
     {
	 case 1:  n=enter();
		  break;

	 case 2: display();
		  break;

	 case 3: n=search();
		  getch();
		  break;

	 case 4:  n=sort();
		  getch();
		  break;

	 case 5:  insert();
		  break;

	 case 6:  del();
		  break;

	 case 7:  merge();
		   break;
	default:  break;

      }
       cout<<"\nDo you want to continue(y/n)?:";
       cin>>c;

   }while(c!='n');
}
 int enter()
 {  clrscr();
    cout<<"\nEnter the size of the array elements:\t";
    cin>>n;
    cout<<"\nEnter the elements for the array:\n";
       for(i=0; i<n; i++)
	    cin>>a[i];
   // getch();
   return n;
  }
  void display()
  {
  clrscr();
     int i;
     cout<<"\nThe array's elements are:\n";
       for(i=0; i<n; i++)
	    cout<<a[i];
  getch();
  }
  int search()
 {
 clrscr();
     n=enter();
  int ch,index;

    cout<<"\n[1] Linear search\n [2] Binary search";
    cout<<"\nEnter your choice:";
    cin>>ch;
     if(ch==1)
  {
   cout<<"\nEnter the element to be searched: ";
    cin>>ele;
    index = lsearch(a,n,ele);
    if(index==-1)
      cout<<"\nSorry!!The element could not be found";
      else
      cout<<"\nThe element is present at position:"<<index+1<<endl;

  }
   else if(ch==2)
 {
    cout<<"\nEnter the element to be searched: ";
    cin>>ele;
index = BSearch(a,n,ele);
  if(index==-1)
   cout<<"\nSorry!!element could not be found";
  else
   cout<<"\nElement found at the position:"<<index+1;
 }
 return n;

}
int lsearch(int a[], int n, int ele)
{
 for(int i=0; i<n; i++)
    {
       if(a[i]==ele)
	  return i;
    }
    return -1;
}

int BSearch(int a[],int n, int ele)
  {
  int beg,last,mid;
   last=n-1;  beg=0;
while(beg<=last)
   {
     mid = (beg+last)/2 ;
   if(ele==a[mid])
     return mid;
   else if(ele>a[mid])
     beg = mid+1;
   else
      last = mid-1;
   }
   return-1;

}
  int sort()
 {
 int ch;
 clrscr();
  n= enter();
cout<<"[1] Bubble sort\n[2] Insertion\n[3] Selection sort";
cout<<"\nEnter your choice(1-3):";
cin>>ch;
  if (ch==1)
  {
  bubblesort(a,n);
 cout<<"\n The sorted array is...\n";
   for(i=0; i<n; i++)
  cout<<a[i]<<endl;
  }


 else if(ch==2)
 {
 insort(a,n);
 cout<<"\n The sorted array is...\n";
  for(i=1; i<=n; i++)
   cout<<a[i]<<" "<<endl;
  }
  else
  {
  selsort(a,n);
  cout<<"\n The sorted array is..\n";
  for(i=0; i<n; i++)
    cout<<a[i]<<" "<<endl;
  }
  return n;
  }
  void bubblesort(int a[], int n)
{
  int temp=0,ctr=0;
 for(i=0; i<n; i++)
   {
      for(j=0; j<(n-1)-i; j++)
	 {   if(a[j]>a[j+1])
	       {
		 temp=a[j];
		 a[j]=a[j+1];
		 a[j+1]=temp;
	       }
	  }
 cout<<"\nAfter iteration"<<++ctr<<" the array elements are:";
  for(int k=0; k<n; k++)
  cout<<a[k]<<endl;
    }
 }
 void insort(int a[],int n)
 {
 int tmp,i,j;
   a[0]=INT_MIN;
   for(i=1; i<=n; i++)
     {
       tmp = a[i];
       j   = i-1;
  while(tmp<a[j])
    {
      a[j+1] = a[j];
      j--;
    }
    a[j+1] = tmp;
    cout<<"Array after pass"<<i<<"is";
    for(int k=0; k<=n; k++)
       cout<<a[k]<<endl;
     }
 }
void selsort(int a[],int n)
{
 int small,pos,tmp;
  for(i=0; i<n; i++)
   {
     small = a[i];
     pos   = i;
      for(j=i+1; j<n; j++)
	{
	  if(a[j]<small)
	    {
	       small=a[j];
	       pos  =j;
	    }
	 }
       tmp = a[i];
       a[i]= a[pos];
       a[pos]=tmp;
     cout<<"\nArray after pass-"<<i+1<<"-is";
     for(j=0; j<n; j++)
 cout<<a[j]<<endl;
    }
}

 void insert()
  {
 clrscr();
 int ch;
 cout<<"\n[1]sorted\n[2]unsorted";
 cout<<"\nEnter your choice:";
 cin>>ch;
 if (ch==1)
 {
  int n,a[80],inde,ele;
  cout<<"\nEnter the no. of elements: ";
  cin>>n;
  cout<<"\nEnter the array elements:";
  for(int i=0; i<n; i++)
     cin>>a[i];
  char ch='y';
   while(ch=='y')
   {
    cout<<"\n Enter element to be inserted:";
    cin>>ele;
    inde = find(a,n,ele);
 for(i=n; i>inde; i--)
    {  a[i] = a[i-1];  }
 a[inde] = ele;
 n+=1;   int ch;
 cout<<"\nWant to insert more elements(y/n)?";
 cin>>ch;
   }
cout<<"\nThe array now is..\n";
 for(i=0; i<n; i++)
  cout<<a[i]<<" "<<endl;
 }
else if(ch==2)
 {
  int arr[20],n,i,key;
  int cap = sizeof(arr)/sizeof(arr[0]);
  cout<<"enter the no of elements:";
  cin>>n;
  cout<<"\nenter the arrays elements:";
   for(i=0; i<n; i++)
  cin>>arr[i];
  cout<<"enetr the element you want to insert:";
  cin>>key;
n = insertsorted(arr,n,key,cap);
cout<<"\nafter insertion:";
 for(i=0; i<n; i++)
   cout<<arr[i]<<" ";
}
else
cout<<"\nWrong choice!!!";
}

 int find(int a[],int n,int ele)
 {
 int pos;
 if(ele<a[0])   pos=0;
 else
 {
   for(int i=0; i<n-1; i++)
      {
	 if(a[i]<=ele&&ele<a[i+1])
	   {
	     pos=i+1;   break;
	   }
      }
      if(i==n-1)
      pos = n;
 }
 return pos;
 }
 int insertsorted(int arr[20], int n,int key,int cap)
{
  if(n>=cap)
  return n;
arr[n] = key;
  return(n+1);
}

void del()
  {
  clrscr();

  cout<<"\n[1]Sorted\n[2]Unsorted";
  cout<<"\nEnter your choice:";
int ch;
cin>>ch;
    if(ch==2)
  {
    int i,arr[20],key;
    int n= sizeof(arr)/sizeof(arr[0]);
    cout<<"\nenter the elements of array:";
      for(i=0; i<n; i++)
	cin>>arr[i];
    cout<<"\nenter the element to be deleted:";
	cin>>key;
  n = delete_ele(arr,n,key);
    cout<<"\nArray after deletion";
      for(i=0; i<n; i++)
	cout<<arr[i]<<" ";
  }
 getch();
  }
delete_ele(int arr[20], int n,int key)
{
  int pos = find_ele(arr,n,key);
   if(pos==-1)
    {
      cout<<"\nElement not found";
      return n;
    }
   int i;
    for(i=pos; i<n-1; i++)
      arr[i] = arr[i+1];
      return n-1;
 }
 int find_ele(int arr[],int n, int key)
 {
   for(int i=0; i<n; i++)
     if(arr[i]==key)
       return i;

   return -1;
  }

 void merge()
 {
  clrscr();
  int mn=0;
  cout<<"\nHow many elements do you want to create in first array:";
  cin>>m;
  cout<<"\nEnter first array's elements(asc order):";
   for(i=0; i<m; i++)
     cin>>a[i];
  cout<<"\nEnter the no of elements of second array:";
  cin>>n;
  mn = m+n;
  cout<<"\nEnter second array's elements(desc order): ";
   for(i=0; i<n; i++)
     cin>>b[i];
  merg(a,m,b,n,c);
  cout<<"\n\nThe merged arrays..";
  for(i=0; i<mn; i++)
     cout<<c[i]<<" "<<endl;
  }
  void merg(int a[],int m,int b[],int n,int c[])
  {
   int p,q,r;
   for(p=0,q=-1,r=0; p<m && q>=0; )
     {
       if(a[p]<=b[q])
	c[r++]=a[p++];
       else
       c[r++]=b[q--];
     }
    if(p<m)
      {
	while(p<m)
	  c[r++] = a[p++];
      }
    else
      {
	while(q>=0)
	  c[r++] = b[q--];
      }
  }
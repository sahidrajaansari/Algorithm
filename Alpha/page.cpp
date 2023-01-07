#include<iostream>
using namespace std;
#include<string.h>
#include<algorithm>


//print array 
void Print(int a[],int n)
{
     
    for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
    cout<<endl;
}
// optimal page replacement algorithm 
void opt(string s,int F[],int f,int l)
{
   int i,j=0,k,m,flag=0,cnt=0,temp[10];

//    printf("\n\tPAGE\t    FRAMES\t  FAULTS");
   for(i=0;i<10;i++)
     temp[i]=0;

   for(i=0;i<f;i++)
     F[i]=-1;

   for(i=0;i<l;i++)
    {
       for(k=0;k<f;k++)
    {
      if(F[k]==s[i]-'0')
        flag=1;
    }

       if(j!=f && flag==0) // F array not full and  element is new
    {
      F[j]=s[i]-'0';
      j++;
    }

       else if(flag==0) // j==f
    {
       for(m=0;m<f;m++)
        {
          for(k=i+1;k<l;k++)
           {
          if(F[m]!=s[k]-'0')
           {
             temp[m]=temp[m]+1;
           }
          else
           break;
           }
        }

       m=0;
       for(k=0;k<f;k++)
        {
           if(temp[k]>temp[m])
        {
          m=k;
        }
        }

       F[m]=s[i]-'0';
    }

    //    printf("\n\t%c\t",s[i]);
    //    for(k=0;k<f;k++)
    // {
    //    printf("  %d",F[k]);
    // }
    Print(F,f);
    if(flag==0)
    {
    //   printf("Page fault %d\n",cnt);
      cout<<"Page fault "<<endl;
      cnt++;
    }
    else
    //  printf("page hit\n");
       cout<<"page hit "<<endl;
       flag=0;
       for(k=0;k<10;k++)
       temp[k]=0;
     }
}


//main function 
int main()
{
    string Ref_string;
    cout<<"Enter the reference string "<<"\n";
    cin>>Ref_string;
    int no_of_frame;
    cout<<"Enter the no of frame \n";
    cin>>no_of_frame;
    int frame_status[no_of_frame];
    
    for(int i=0;i<no_of_frame;i++)
    {
        frame_status[i]=-1;// -1 means that it is empty 
    }
    cout<<"Choose Which algorithm wants to Run "<<"\n";
    cout<<"1. FIFO \n2. LRU\n3.opt"<<"\n";
    int in;
    cin>>in;
    // fifo page replacement algorithm
    if(in==1)
    {
      int k=0;int hit=0,miss=0;
      for(int i=0;Ref_string[i]!='\0';i++)
      {
         int page=Ref_string[i]-'0';int h=0;
         for(int j=0;j<no_of_frame && frame_status[j]!=-1;j++)
         {
             if(page==frame_status[j])
             {
                 cout<<"Page hit"<<"\n";
                 h=1;hit++;break;
             }
         }
         if(h==0){
             if(k>=no_of_frame)
             k=0;
             miss++;
             cout<<"Page fault\n";
             frame_status[k]=page;k++;
         }
         
         Print(frame_status,no_of_frame);
      }
      cout<<"No of Hit is:"<<hit<<endl<<"No of Miss is:"<<miss<<endl;

    }
    else if(in==3)
    {
    
    int s=0;
    for(int i=0;Ref_string[i]!='\0';i++)
    s++;
    opt(Ref_string,frame_status,no_of_frame,s);
    
    }
    //LRU(least Recently used algorithm) it is in between fifo and optimal algorithm
    else if(in==2)
    {
     int hit=0,miss=0;
     for(int i=0;Ref_string[i]!='\0';i++)
     {
         bool check=false;
         int page=Ref_string[i]-'0';
         for(int j=0;j<no_of_frame && frame_status[j]!=-1;j++)
         {
             if(page==frame_status[j])
             {
                 hit++;
                 cout<<"Page hit"<<endl;
                 for(int k=j+1;k<no_of_frame;k++)
                 {
                     frame_status[k-1]=frame_status[k];
                 }
                 frame_status[no_of_frame-1]=page;
                 check=true;
                 break;
             }
         }
         if(check==false)
         {
             miss++;
             cout<<"Page fault "<<endl;
             for(int j=1;j<no_of_frame;j++)
             {
                 frame_status[j-1]=frame_status[j];
             }
             frame_status[no_of_frame-1]=page;
         }
      Print(frame_status,no_of_frame);
     
     }
     cout<<"No of Hit is:"<<hit<<endl<<"No of Miss is:"<<miss<<endl;    

    }
    
    else
    cout<<"Sorry wrong input please press 1 or 2 "<<"\n"<<"Thank you have a good day"<<endl;
    return 0;

}
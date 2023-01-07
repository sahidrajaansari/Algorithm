#include<iostream>

using namespace std;


bool check(int *available,int **remainingNeed, int i, int nr ){
    for(int j=0;j<nr;j++)
        if(available[j]<remainingNeed[i][j])
        return false;
    
    return true;

}
void updateAvail(int *available, int **allocated, int i ,int nr){
    for(int j=0;j<nr;j++){
        available[j]=available[j]+allocated[i][j];
    }
}

int main(){
   
   int np, nr;

   cout<<"Enter no of processes: ";
   cin>>np;
   cout<<"Enter no of resources: ";
   cin>>nr;

   int **maxNeed = new int*[np];
   int **allocated = new int*[np];
   int **remainingNeed = new int*[np];
   int *available = new int[nr];
   int *totalRes = new int[nr];
   int *totalAllocated = new int[nr];
   bool *processDone = new bool[np];

   for(int i=0;i<np;i++){
       maxNeed[i] = new int[nr];
       allocated[i] = new int[nr];
       remainingNeed[i] = new int[nr];
   }

   cout<<"Enter max need matrix:"<<endl;
   for(int i=0;i<np;i++){
    for(int j=0;j<nr;j++){
       cin>>maxNeed[i][j];
    }
   }

      cout<<"Enter allocated matrix:"<<endl;
      for(int i=0;i<np;i++){
          for(int j=0;j<nr;j++){
            cin>>allocated[i][j];
            }

     }
     //for remaining need 
   for(int i=0;i<np;i++){
    for(int j=0;j<nr;j++){
     remainingNeed[i][j] = maxNeed[i][j]- allocated[i][j];
    }
    //initialize all process done to false
    processDone[i]=false;
   }

     
   cout<<"Enter total resources of each type: ";
   for(int i=0;i<nr;i++){
    cin>>totalRes[i];
    totalAllocated[i]=0;
    
   }

   for(int i=0;i<nr;i++){
    for(int j=0;j<np;j++){
        totalAllocated[i]= totalAllocated[i]+allocated[j][i];
    }
   }

   for(int i =0;i<nr;i++){
available[i] = totalRes[i]-totalAllocated[i];
   }

 cout<<"Avaiable resources: "<<endl;
for(int i =0;i<nr;i++){
   
     cout<<available[i]<<" ";
   }


   

   int x=0;
cout<<"\nSafe sequence is: "<<endl;
   while (x<np)
   {
    bool isSafe=false;
      for(int i=0;i<np;i++){
        if(processDone[i]==false && check(available, remainingNeed,i, nr)){
            x++;
            
           updateAvail(available,allocated,i,nr);
           isSafe=true;
           processDone[i]=true;
           cout<<"P"<<i<<"-> ";
        }
      }
      if(!isSafe)
      break;
   }
   if(x==np)
   cout<<"\nAll processes are safely allocated";
   else
   cout<<"\nAll processes cannot be allocated";

    return 0;
}
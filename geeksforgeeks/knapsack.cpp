int knapsack(int val[],int wt[],int n,int weight)
{
   int **k=new int *[n+1];
   for(int i=0;i<=n;i++)
   k[i]=new int [weight+1];
   
   for(int i=0;i<=n;i++)
   {
       for(int w=0;w<=weight;w++)
       {
           if(i==0||w==0)
           k[i][w]=0;
           else if(wt[i-1]<=w)
           k[i][w]=max(val[i-1]+k[i-1][w-wt[i-1]],k[i-1][w]);
           else
           k[i][w]=k[i-1][w];
       }
   }
   return k[n][weight];
}

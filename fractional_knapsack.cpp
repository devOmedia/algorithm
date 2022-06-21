#include <bits/stdc++.h>
using namespace std;


struct Item
{
  int profit;
  int weight;
};

bool cmp(Item a, Item b){

  double r1 = (double )a.profit/a.weight;
  double r2 = (double )b.profit/b.weight;

  return r1>r2;
}

double knapsack(Item *ary, int totalCapacity, int n){

  ///Sort the given array of items according to
  ///weight / profit(W /V) ratio in descending order.
  sort(ary, ary+n, cmp);

  int cur_weight = 0; ///remaining wight
  double totalProfit = 0.0; ///result
  int remain;

  for(int i=0; i<n; i++){
    if(cur_weight + ary[i].weight <= totalCapacity){
      cur_weight += ary[i].weight;
      totalProfit += ary[i].profit;
    } else {
    ///adding fractional part
      remain = totalCapacity - cur_weight;
      totalProfit += ary[i].profit * ((double)remain / ary[i].weight);
    }
  }

  return totalProfit;
}


int main()
{
  int totalCapacity = 50;
  Item ary[] = { { 60, 10 }, { 100, 20 }, { 120, 30 } };
  int n = sizeof(ary) / sizeof(ary[0]);

  cout << "Maximum profit we can obtain = "
         << knapsack(ary, totalCapacity, n) << endl;
    return 0;
}

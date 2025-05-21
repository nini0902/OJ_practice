#include <bits/stdc++.h>
#include <fstream>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  ifstream fin("swap.in");
  ofstream fout("swap.out");
  
  int n,k, cycle = 0;
  int A1, A2, B1, B2;
  fin >> n >> k >> A1 >> A2 >> B1 >> B2;
  vector<vector<int>> seqs;
  
  vector<int> ori_seq(n), cur_seq(n);
  for(int i = 0; i < n; i++) ori_seq[i] = i+1;
  cur_seq = ori_seq;
  seqs.push_back(ori_seq);
  
  // find the loop
  do {
    reverse(cur_seq.begin() + (A1-1), cur_seq.begin() + A2);
    reverse(cur_seq.begin() + (B1-1), cur_seq.begin() + B2);
    seqs.push_back(cur_seq);
  } while(cur_seq != ori_seq);
  
  cycle = seqs.size()-1;
  for(int v : seqs[k%cycle]) fout << v << '\n';
  return 0;
}

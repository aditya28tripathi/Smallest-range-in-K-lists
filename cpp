class Solution{
    public:
    #define p pair<int, pair<int, int>> 
    pair<int,int> findSmallestRange(int KSortedArray[][N], int n, int k)
    
    
    
    
    {
          //code here
          priority_queue<p, vector<p>, greater<p>> q;
          int maxx = INT_MIN;int minn = INT_MAX;int range = INT_MAX;int low = 0;
          
          int high = 0;
          for(int i = 0; i < k; i++)
          {
              
              q.push({KSortedArray[i][0], {i, 0}});
              maxx = max(maxx, KSortedArray[i][0]);
              minn = min(minn, KSortedArray[i][0]);
          }
          while(1)
          {
              p top = q.top();
              q.pop();
              if(maxx-minn < range)
              {
                  low = minn;
                  high = maxx;
                  range = high-low;
              }
              if(top.second.second+1 >= n) break;
              int temp = KSortedArray[top.second.first][top.second.second+1];
              
              
              
              
              q.push({temp, {top.second.first, top.second.second+1}
                  
              });
              
              minn = q.top().first;
              
              maxx = max(maxx, temp);
          }
          return {low, high};
    }
};

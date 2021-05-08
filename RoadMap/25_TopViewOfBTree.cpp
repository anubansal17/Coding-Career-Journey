class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
   Node* cur = root;
   map <int, int> distanceMap;
   int d = 0;
   queue<pair<Node*, int>> que;
   que.push({cur, d});
   while(cur != NULL and !que.empty()) {
       pair<Node*, int> current = que.front();
       que.pop();
       if(distanceMap.find(current.second) == distanceMap.end())
            distanceMap[current.second] = current.first->data;
       if(current.first->left != NULL) {
           que.push({current.first->left, current.second - 1});
       }
       if(current.first->right != NULL) {
           que.push({current.first->right, current.second + 1});
       }
   }
   vector <int> tView;
   for (auto it: distanceMap) {
       tView.push_back(it.second);
   }
   return tView;
    }

};

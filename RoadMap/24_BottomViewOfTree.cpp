// Method that returns the bottom view.
vector <int> bottomView(Node *root)
{
  // Using map to store elements at different horizontal distance
  vector<int> bottomView;
  map<int, int> disMap;
  queue<pair<Node*, int>> que;
  if(root == NULL) {
      return bottomView;
  }
  que.push({root, 0});
  while(!que.empty()) {
      pair<Node*, int> current = que.front();
      que.pop();
      int hd = current.second;
      disMap[hd] = current.first->data;
      if(current.first->left) {
          que.push({current.first->left, hd-1});
      } 
      if(current.first->right) {
          que.push({current.first->right, hd+1});
      }
  }
  for (auto it=disMap.begin(); it != disMap.end() ; it++) {
      bottomView.push_back(it->second);
  }
  return bottomView;
}


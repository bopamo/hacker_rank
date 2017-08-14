/*
struct node
{
    int data;
    node* left;
    node* right;
}*/

void levelOrder(node * root) {
  
    if(!root) return;
    
    queue<node*> q;
    
    node *ptr = root;
    
    q.push(ptr);
    
    while(!q.empty()) {
        
        ptr = q.front();
        q.pop();
        
        if(ptr) {
            q.push(ptr->left);
            q.push(ptr->right);
            cout << ptr->data << " ";
        }
    }
  
}

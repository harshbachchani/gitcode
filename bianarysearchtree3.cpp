#include <iostream>
#include <queue>
#include <map>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;
        Node(int x){
            data = x;
            left=NULL;
            right=NULL;
        }
        ~Node(){
            if(left){
                delete left;
            }
            if(right){
                delete right;
            }
        }
};

Node* inserttoBST(Node* &root,int x){
    if(root==NULL){
        root=new Node(x);
        return root;
    }
    if(x> root->data){
        //insert in right
        root->right=inserttoBST(root->right,x);
    }
    else{
        //insert in left part
        root->left=inserttoBST(root->left,x);
    }
    return root;
}
void takeInput(Node* &root){
    cout<<"Enter the data to insert in binary Search Tree"<<endl;
    int x;
    cin>>x;
    while(x!=-1){
        root=inserttoBST(root,x);
        cin>>x;
    }
}
void levelOrderTraversal(Node* root){
    queue<Node* > q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* temp=q.front();
        q.pop();
        if(temp==NULL){
            cout<<endl;   
            if(!q.empty()){
                q.push(NULL);
            } 
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left!=NULL){
                q.push(temp->left); 
            }
            if(temp->right!=NULL){
                q.push(temp->right);
            }
        }
    }
}

/*

function to check whether the sum of two nodes in binary search tree is equals to given target or not
bool chkTarget(Node* root,int X){
    if(root==NULL){
        return false;
    }
    vector<int> val;
    inorder(root,val);
    int i=0;
    int j=val.size()-1;
    int sum=val[i]+val[j];
    while(i<=j){
        if(sum<X){
            i++;
        }
        else if(sum>X){
            j--;
        }
        else{
            return true;
        }
    }
    return false;
}
*/


//function to make a linked list from binary search tree
/*
Node* FlattedBST(Node* root){
    
    vector<Node*> val;
    inorder(root,val);
    Node* newNode=val[0];
    Node* curr=newNode;
    int i=1;
    while(i<val.size()){
        Node* temp =val[i];
        curr->left=NULL;
        curr->right=temp;
        curr=temp;
        i++;
    }
    curr->right=NULL;
    curr->left=NULL;
    return newNode;
}

//function to check the binary tree is balanced or not
pair<int,bool> chkBalanced(Node* root){
    if(root==NULL){
        pair<int,bool>ans= make_pair(0,true);
        return ans;
    }
    pair<int,bool>left=chkBalanced(root->left);
    pair<int,bool>right=chkBalanced(root->right);
    int i=left.first-right.first;
    if(abs(i)>1){
        return make_pair(max(left.first,right.first)+1,false);
    }
    return make_pair(max(left.first,right.first)+1,left.second&& right.second);
}

*/
//function to make balanced tree from a binary search tree
// Node* solve(int s,int e,vector<int> val){
//     if(s>e){
//         return NULL;
//     }
//     int mid=s+(e-s)/2;
//     Node* root=new Node(val[mid]);
//     root->left=solve(s,mid-1,val);
//     root->right=solve(mid+1,e,val);
//     return root;
// }
// Node* makeBalanceTree(Node* root){
//     vector<int> val;
//     inorder(root,val);
//     return solve(0,val.size()-1,val);
// }

//function to make binary search tree from preorder
// Node* solve(vector<int> &preorder,int &i,int max){
//     if(i>=preorder.size()){
//         return NULL;
//     }
//     if(preorder[i]>max){
//         return NULL;
//     }
//     Node* root=new Node(preorder[i++]);
//     root->left=solve(preorder,i,root->data);
//     root->right=solve(preorder,i,max);
//     return root;

// }
// Node* PreOrderTree(Node* root,vector<int> &preorder){
//     int max=INT16_MAX;
//     int s=0;
//     return solve(preorder,s,max);
// }

/*
//function to merge two binary search trees
void inorder(Node* root,vector<int > &val){
    if(root==NULL){
        return;
    }
    inorder(root->left,val);
    val.push_back(root->data);
    inorder(root->right,val);
}
vector<int> mergeArray(vector<int> tree1,vector<int> tree2){
    //function to merge two sorted arrays
    vector<int> ans;
    int i=0,j=0;
    while(i<tree1.size()&&j<tree2.size()){
        if(tree1[i]<tree2[j]){
            ans.push_back(tree1[i++]);
        }
        else{
            ans.push_back(tree2[j++]);
        }
    }
    while(i<tree1.size()){
        ans.push_back(tree1[i++]);
    }
    while(j<tree2.size()){
        ans.push_back(tree2[j++]);
    }
}
Node* constructTree(vector<int> arr,int s,int e){
    //function to construct binary search tree from inorder
    if(s>e){
        return NULL;
    }
    int mid=s+(e-s)/2;
    Node* root=new Node(arr[mid]);
    root->left=constructTree(arr,s,mid-1);
    root->right=constructTree(arr,mid+1,e);
    return root;
}
Node* merge(Node* root1,Node* root2){
    vector<int> tree1,tree2;
    inorder(root1,tree1);
    inorder(root2,tree2);
    vector<int> mergedArray=mergeArray(tree1,tree2);
    return constructTree(mergedArray,0,mergedArray.size()-1);
}
*/

//function to merge two binary search tree

//step1 -- convert binary search tree into sorted doubly linked list using recursion
void convertIntoDoublyLL(Node* root,Node* &head){
    //base case
    if(root==NULL){
        return; 
    }
    convertIntoDoublyLL(root->right,head);
    root->right=head;
    if(head!=NULL){
        head->left=root;
    }
    head=root;
    convertIntoDoublyLL(root->left,head); 
}


//step 2 -- merge two sorted linked list into 1
Node* mergeLinkedList(Node* head1,Node* head2){
    Node* head=NULL;
    Node* tail=NULL;

    while(head1!=NULL && head2!=NULL){
        if(head1->data <= head2->data){
            if(head==NULL){
                head=head1;
                tail=head1;
                head1=head1->right;
            }
            else{
                tail->right=head1;
                head1->left=tail;
                tail=head1;
                head1=head1->right;
            }
        }
        else{
            if(head==NULL){
                head=head2;
                tail=head2;
                head2=head2->right;
            }
            else{
                tail->right=head2;
                head2->left=tail;
                tail=head2;
                head2=head2->right;
            }
        }
    }
    while(head1!=NULL){
        tail->right=head1;
        head1->left=tail;
        tail=head1;
        head1=head1->right;
    }
    while(head2!=NULL){
        tail->right=head2;
        head2->left=tail;
        tail=head2;
        head2=head2->right;
    }
}

int countNodes(Node* head){
    int cnt=0;
    Node* temp=head;
    while(temp!=NULL){
        cnt++;
        temp=temp->right;
    }
    return cnt;
}

Node* SortedLLToBST(Node* &head,int n){
    if(n<=0 || head==NULL){
        return NULL;
    }
    Node* left=SortedLLToBST(head,n/2);
    Node* root=head;
    root->left=left;
    head=head->right;
    root->right=SortedLLToBST(head,n-n/2-1);
    return root;
}

Node* MergeBST(Node* root1,Node* root2){
    //convert bst into sorted doubly linked list
    Node* head1=NULL;
    convertIntoDoublyLL(root1,head1);
    head1->left=NULL;
    Node* head2=NULL;
    convertIntoDoublyLL(root1,head2);
    head2->left=NULL;

    //step2 merge sorted linked list
    Node* head=mergeLinkedList(head1,head2);

    //step3 convert sorted linked list into BST
    return SortedLLToBST(head,countNodes(head)); 
}

//function to return maxsize BST from a binary tree
class info{
    public:
        int maxi;
        int mini;
        bool isBST;
        int size;
};

info solve(Node* root,int &maxsize){
    //base case
    if(root==NULL){
        return {INT16_MIN,INT16_MAX,true,0}; 
    }

    info left=solve(root->left,maxsize);
    info right=solve(root->right,maxsize);
    info currentNode;
    currentNode.size=left.size+right.size+1;
    currentNode.maxi=max(root->data,right.maxi);
    currentNode.mini=min(root->data,left.mini);
    bool ans=left.isBST && right.isBST && ((root->data>left.maxi) && (root->data<right.mini));
    currentNode.isBST=ans;

    if(currentNode.isBST){
        maxsize=max(maxsize,currentNode.size);
    }
    return currentNode;    
}
int largestBST(Node* root){
    int maxsize=0;
    info temp=solve(root,maxsize);
    return maxsize;
}
int main(){
    Node* root1=NULL;
    Node* root2=NULL;
    takeInput(root1);
    takeInput(root2);
    // cout<<chkTarget(root,20);
    // Node* temp=FlattedBST(root);
    // while(temp!=NULL){
    //     cout<<temp->data<<" ";
    //     temp=temp->right;
    // }
    // pair<int,bool> ans=chkBalanced(root);
    // cout<<ans.second<<endl;
    // vector<int> preorder={10,5,3,4,7,6,9,18,16,20};
    // root=PreOrderTree(root,preorder);
    // levelOrderTraversal(root);
    // Node* ans=NULL;
    // ans=merge(root1,root2);
    
    return 0;
}
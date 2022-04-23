#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <stdlib.h>  
#include <time.h>  
#include <math.h>  
#include <list>  
      
using namespace std;
   
typedef struct Node {
    int key;
    int height;
    int i;
    struct Node* left;
    struct Node* right;
} Node;
   
void build_tree(int i, Node *&root, vector<vector<int>> &tree) {
    int left_idx = tree[i][1];
    int right_idx = tree[i][2];
   
    if (left_idx != -1) {
        Node* left = new Node();
        left->key = tree[left_idx][0];
        left->height = tree[left_idx][3];
        left->left = 0;
        left->right = 0;
        build_tree(left_idx, left, tree);
        root->left = left;
    }
   
    if (right_idx != -1) {
        Node* right = new Node();
        right->key = tree[right_idx][0];
        right->height = tree[right_idx][3];
        right->left = 0;
        right->right = 0;
        build_tree(right_idx, right, tree);
        root->right = right;
    }
}
   
void update_height(Node *&root) {
    int left_height = 0, right_height = 0;
 
    if (root->left != 0) {
        left_height = root->left->height;
    } 
    if (root->right != 0) {
        right_height = root->right->height;
    } 
 
    root->height = max(left_height, right_height) + 1;
}
 
int calculate_balance(Node *root) {
    if (root == 0) {
        return 0;
    }
     
    int left_height = 0, right_height = 0;
 
    if (root->left != 0) {
        left_height = root->left->height;
    } if (root->right != 0) {
        right_height = root->right->height;
    }
 
    return right_height - left_height;
}
 
Node* left_rotation(Node *&root) {  
    int root_right_child_balance = calculate_balance(root->right);
    Node* A = root;
    Node* B = root->right;
   
    if (root_right_child_balance == -1) {
        Node* C = B->left;
        A->right = C->left;
        B->left = C->right;
        C->left = A;
        C->right = B;
 
        update_height(A);
        update_height(B);
        update_height(C);
   
        return C;
    } else {
        A->right = B->left;
        B->left = A;
 
        update_height(A);
        update_height(B);
   
        return B;
    }
}
   
Node* right_rotation(Node *&root) {
    int root_left_child_balance = calculate_balance(root->left);
    Node* A = root;
    Node* B = root->left;
   
    if (root_left_child_balance == 1) {
        Node* C = B->right;
        A->left = C->right;
        B->right = C->left;
        C->right = A;
        C->left = B;
 
        update_height(A);
        update_height(B);
        update_height(C);
   
        return C;
    } else {
        A->left = B->right;
        B->right = A;
 
        update_height(A);
        update_height(B);
   
        return B;
    }
}
  
Node* balance_tree(Node *&root) {
    int root_right_height = 0;
    int root_left_height = 0;
   
    if (root->right != 0) {
        root_right_height = root->right->height;
    }
   
    if (root->left != 0) {
        root_left_height = root->left->height;
    }
   
    int root_balance = root_right_height - root_left_height;
      
    if (root_balance < -1) {
        root = right_rotation(root);
    } else if (root_balance > 1) {
        root = left_rotation(root);
    }
  
    return root;
}
  
Node* insert_node(int X, Node *&root) {
    if (root == 0) {
        Node* node = new Node();
        node->key = X;
        node->height = 1;
        node->left = 0;
        node->right = 0;
  
        return node;
    }
  
    int Y = root->key;
  
    if (X < Y) {
        root->left = insert_node(X, root->left);
    } else {
        root->right = insert_node(X, root->right);
    }
  
    update_height(root);
    root = balance_tree(root);
    return root;
}
 
int most_right_node(Node *node) {
    while (node->right != 0) {
        node = node->right;
    }
 
    return node->key;
}
 
Node* delete_node(int X, Node *&root) {
    int Y = root->key;
     
    if (X < Y) {
        root->left = delete_node(X, root->left);
    } else if (Y < X) {
        root->right = delete_node(X, root->right);
    } else {
        if (root->left == 0 && root->right == 0) {
            return 0;
        } else if (root->left == 0) {
            return root->right;
        } else {
            int R = most_right_node(root->left);
            root->left = delete_node(R, root->left);
            root->key = R;
        }
    }
 
    update_height(root);
    root = balance_tree(root);
    return root;
}
 
bool exists_node(int X, Node *&root) {
    if (root == 0) {
        return false;
    } else if (root->key == X) {
        return true;
    } else if (X < root->key) {
        return exists_node(X, root->left);
    } else {
        return exists_node(X, root->right);
    }
}
   
void make_indexes(int &i, Node *&root) {
    if (root == 0) {
        return;
    }
       
    root->i = i;
    ++i;
    make_indexes(i, root->left);
    make_indexes(i, root->right);
}
   
void print_tree(Node *root, ofstream &out) {
    if (root == 0) {
        return;
    }
   
    out << root->key;
   
    if (root->left == 0) {
        out << " 0";
    } else {
        out << ' ' << root->left->i;
    }
   
    if (root->right == 0) {
        out << " 0";
    } else {
        out << ' ' << root->right->i;
    }
   
    out << '\n';
    print_tree(root->left, out);
    print_tree(root->right, out);
}
   
void print_tree(Node *root) {
    if (root == 0) {
        return;
    }
   
    cout << root->key;
   
    if (root->left == 0) {
        cout << " 0";
    } else {
        cout << ' ' << root->left->i;
    }
   
    if (root->right == 0) {
        cout << " 0";
    } else {
        cout << ' ' << root->right->i;
    }
   
    cout << '\n';
    print_tree(root->left);
    print_tree(root->right);
}
    
int main() {
    ifstream in("avlset.in");
    ofstream out("avlset.out");
    int N, x;
    char op;
    Node *root = 0;
    in >> N;
 
    for (int i = 0; i < N; ++i) {
        in >> op >> x;
        bool exists = exists_node(x, root);
 
        if (op == 'C') {
            out << (exists ? 'Y' : 'N');
        } else if (op == 'A') {
            if (!exists) {
                root = insert_node(x, root);
            }
 
            out << calculate_balance(root);
        } else {
            if (exists) {
                root = delete_node(x, root);
            }
 
            out << calculate_balance(root);
        }
 
        out << '\n';
    }
}
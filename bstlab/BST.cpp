#include "BST.h"
    /*
	* Returns the root node for this tree
	*
	* @return the root node for this tree.
	*/
	NodeInterface * BST::getRootNode() const 
	{
		if(root == NULL){
			cout << "root is NULL" << endl;
		}
		return root;
	    cout << "getRootNode"<<endl;
	}

	/*
	* Attempts to add the given int to the BST tree
	*
	* @return true if added
	* @return false if unsuccessful (i.e. the int is already in tree)
	*/
	bool BST::add(int data)
	{
		// first traverse the tree.  if we find the data, don't do anything and return false
		//Node* newNode = new Node(data);
		cout << "adding data: " << data << " done" << endl;
		if(root == NULL){ // if there is nothing in the tree..
			cout << "root is null; storing " << data << " as root" << endl;
		//	root = Node;
			
		}else{
			cout << "root is NOT null" << endl;
		}
		if(insert(root, data)){
			cout << "returning true to insert and then add" << endl;
			return true;
		}else{
			cout << "returning false to insert and then false to add" << endl;
			return false;
		}
		
		//return insert(root, data);

		
	}

	/*
	* Attempts to remove the given int from the BST tree
	*
	* @return true if successfully removed
	* @return false if remove is unsuccessful(i.e. the int is not in the tree)
	*/
	bool BST::remove(int data)
	{
	    cout << "remove: " << data <<endl;
	    return erase(root, data);
	}

	/*
	* Removes all nodes from the tree, resulting in an empty tree.
	*/
	void BST::clear()
	{
	    cout << "clearing"<< endl;
	    postorder(root);
	}
	bool BST::insert(Node*& local_root, int myData){
		if (local_root == NULL){
			//local_root = new Node(myData); Which line should I have?
			cout << "adding " << myData << endl;
			local_root = new Node(myData);
			return true;
		} else {
			if(myData < local_root->data){ // if the new data to be added is less than the local pointer data..
				cout << "send: " << myData << " to left of: " << local_root->data << endl;
				return insert(local_root->leftChild, myData); // send the new data down the left; it will go until it finds it's null place
			}else if(myData > local_root->data){
				cout << "send: " << myData << " to right of: " << local_root->data << endl;
				return insert(local_root->rightChild, myData);
			}else{
				return false;
			}
		}
	}
	
	bool BST::erase(Node*& local_root, int myData){ // when I removed 10, i removed everything under it
		if(myData == 9){
			//cout << "removing: " << myData << endl;
		}
		if(local_root == NULL){ // if we are checking a root that has nothing there..
			cout << "error 3" << endl;
			return false; // the thing we are trying to delete is not in our tree
		}else{
			if(myData < local_root->data){
				cout << myData << " less than: " << local_root->data << endl;
				cout << " first erase" << endl;
				return erase(local_root->leftChild, myData); // take our data to be deleted and go find it in the left tree
			}else if(myData > local_root->data){ // 87
				cout << myData << " greater than : " << local_root->data << endl;
				cout << "87: myData is: " << myData <<" and my other is: " << local_root->data << endl;
				cout << "myData: " << myData << " and local_root-.data: " << local_root->data << endl;
				cout << " second erase" << endl;
				cout << "Local root right child: " << endl;
				if(local_root->rightChild == NULL){
					cout << "oh heeeeellllll nah" << endl; // why is this null? it should be 6 pointing to 10
				}
				//cout << local_root->rightChild->data << endl;
				return erase(local_root->rightChild, myData); // THIS IS THE PROBLEM; it has a dump here
			}else{ // if myData is not less than, or greater than, and it's not NULL, we have found it
				//Found item
				cout << "found item: " << myData << " matches root: " <<  local_root->data << endl;
				cout << "Passed 1" << endl;
				Node* old_root = local_root;
				cout << "Passed 2" << endl;
				if(local_root->leftChild == NULL){// if there is no left child to our node..
					cout << "Passed 3" << endl;
					local_root = local_root->rightChild; // replace it with it's right child
				}else if(local_root->rightChild == NULL){// if there is no right child to our node..
					cout << "Passed 4" << endl;
					local_root = local_root->leftChild;// replace it with it's left child MAKING IT NULL???
				}else{ // if the node has a left child and a right child...
					cout << "Passed 5" << endl;
					replace_parent(old_root, old_root->leftChild); // call the replace function
				}
				cout << "Passed 6" << endl;
				delete old_root;
				old_root = NULL;
				cout << "Passed 7" << endl;
				
				/*
				//TESTING
				Node* testing = root;
				if(root == NULL){
					cout << "root is NULL" << endl;
					return false;
				}
				testing = testing->leftChild; // pass on to 2
				 if(testing == NULL){
					cout << "14 is missing" << endl;	
					return false;
				}
				testing = testing->leftChild; // pass to 3
				 if(testing == NULL){
					cout << "7 is missing" << endl;	
					return false;
				}
				Node* testing9 = testing->rightChild;
				if(testing9 == NULL){
					cout << "9 is missing" << endl;
					return false;
				}
				Node* testing8 = testing9->leftChild;
				if(testing8 == NULL){
					cout << "8 is missing" << endl;
					return false;
				}
				Node* testing12 = testing9->rightChild;
				if(testing12 == NULL){
					cout << "12 is missing" << endl;
					return false;
				}
				Node* testing11 = testing12->leftChild;
				Node* testing10 = testing11->leftChild;
				if(testing11 == NULL){
					cout << "11 is missing" << endl;
					return false;
				}
				if(testing10 == NULL){
					cout << "10 is missing" << endl;
					return false;
				}
				Node* testing13 = testing12->rightChild;
				
				if(testing13 == NULL){
					cout << "13 is missing" << endl;
					return false;
				}
				
				testing = testing->leftChild; // pass to 4
				 if(testing == NULL){
					cout << "5 is missing" << endl;	
					return false;
				}
				Node* testing6 = testing->rightChild;
				if(testing6 == NULL){
					cout << "6 is missing" << endl;
					return false;
				}
				testing = testing->leftChild; // pass to 5
				 if(testing == NULL){
					cout << "1 is missing" << endl;
					return false;
				}
				if((testing->rightChild != NULL) || (testing->rightChild != NULL) ){
					cout << "woops" << endl;
					return false;
				}
				testing = testing->rightChild; // pass to 8
				 if(testing == NULL){
					cout << "8 is missing" << endl;	
					return false;
				}
				testing = testing->leftChild; // pass to 7
				 if(testing == NULL){
					cout << "7 is missing" << endl;	
					return false;
				}
				*/
				
				return true;
			}
		}
	}
	
	/*
	This function finds the rightmost local root that 
      does not have a right child. The data in this local_root
      replaces the data in old_root. The pointer to local_root
      is then saved in old_root and local_root is replaced
      by its left child.
	
	A better strategy would be to
	
		Find the rightmost local root that does not have a right child and call it local_root
		Replace the data in old_root with the data in local root.
		Call delete on the left subtree of old_root to delete the local root node
	
	*/
	
	void BST::replace_parent(Node*& old_root, Node*& local_root){
		cout << "replacing:" << endl;
		cout << "old_root: " << old_root->data << " local_root: " << local_root->data << endl;
		if(local_root->rightChild != NULL){
			replace_parent(old_root, local_root->rightChild);
		}else{
			// WORKING CODE
			//old_root->data = local_root->data;// This
			//old_root = local_root;			// Code
			//local_root = local_root->leftChild;//Works
			
			// ATTEMPT AT BETTER SOLUTION
			old_root->data = local_root->data; // This is straight from the instructions

			
			//Call delete on the left subtree of old_root to delete the local root node
			//Is this right?  Go to the left subtree and delete the node that we just moved to replace the removed data?
		
			if(erase(old_root->leftChild, local_root->data)){
				cout << "erased!" << endl << endl;
			}
				
			
		

		}
	}
	
	void BST::postorder(Node*& local_root){
		if(local_root == NULL){
			cout << "postorder local root is NULL" << endl;
			return;
		}
		postorder(local_root->leftChild);
		postorder(local_root->rightChild);
		cout << "deleting: " << local_root->data << endl;
		delete local_root;
		local_root = NULL;
	}
	
	
	
	
	
	
	
	
	
	
	
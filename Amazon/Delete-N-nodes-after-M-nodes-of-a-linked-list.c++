#include<algorithm>
#include<cmath>
#include<cstdio>
#include<iostream>
#include<sstream>
#include<random>
#include<string>
#include<vector>

using namespace std;

struct Node{
	int data;
	Node* next;

	Node(int x){
		data = x;
		next = NULL;
	}
};


void printList(Node* head){
	Node* temp = head;
	while (temp != NULL){
		printf("%d", temp->data);
		temp = temp->next;
	}
	printf("\n");
}



class Solution {
  public:
    Node* linkdelete(Node* head, int n, int m) {
        Node *current = head;
        Node *temp = head;

        while(current != nullptr){

            for(int i = 1; i < m && current != nullptr; i++){
                current = current->next;
            }


            if(current == nullptr) break;

            Node *delet = current->next;
            for(int i = 0; i < n && delet != nullptr; i++){
                temp = delet;
                delet = delet->next;
                delete temp;
            }

            current->next = delet;

            current = delet;

        }

        return head;
    }
};


int main(){
	int t;
	cin >> t;
	cin.ignore();

	while(t--){
		vector<int> arr;
		string input;

		getline(cin, input);
		stringstream ss(input);

		int number;

		while (ss >> number){
			arr.push_back(number);
		}

		int n = arr2[0], m = arr2[1];

		if(arr.empty()){
			cout << "empty" << endl;
			continue;
		}

		Node* head = new Node(arr[0]);
		Node* tail = head;

		for(int i = 1; i < arr.size(); i++){
			tail->next = new Node(arr[i]);
			tail = tail->next;
		}

		Solution ob;
		head = ob.linkedelete(head, n, m);

		printList(head);

		while(head != NULL){
			Node* temp = head;
			head = head->next;
			delete temp;
		}
	}

	return 0;
}


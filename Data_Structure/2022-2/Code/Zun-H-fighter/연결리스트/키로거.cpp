#include <iostream>
#include <string>
using namespace std;

struct Node{
    char data;
    Node *prev = NULL, *next = NULL;
};

class keylogin{
	
private:
	Node *head;
	Node *node;
	Node *tail;
public:
	keylogin(){
		head = new Node;
		tail = new Node;
		head->next = tail;
		tail->prev = head;
		node = head;
	}

	void incert(char ch){
		Node *newnode = new Node;
		newnode->data = ch;
		newnode->prev = node;
		newnode->next = node->next;
		node->next->prev = newnode;
		node->next = newnode;
		node = newnode;
	}
	
	void erase(){
		if(node != head){
			node->prev->next = node->next;
			node->next->prev = node->prev;
			node = node->prev;
		}
	}
	
	void Right(){
		if(node->next != tail)
			node = node->next;
	}
	
	void Left(){
		if(node != head)
			node = node->prev;
	}
	
	void printall(){
		for(Node* c_n = head->next; c_n != tail; c_n = c_n->next)
			cout << c_n->data;
		cout<<'\n';
	}

};




int main(){
	int n;
	string str1;
	
	cin >> n;
	for(int i=0; i<n; i++){
		keylogin a;
		cin >> str1;
		
		for(int j = 0; j < str1.size(); j++){
            if(str1[j] == '-'){
                a.erase();
            }else if(str1[j] == '<'){
                a.Left();
            }else if(str1[j] == '>'){
                a.Right();
            }else{
                a.incert(str1[j]);
            }
        }
        a.printall();
	}
	return 0;
}

#include<iostream>
using namespace std;
struct TreeNode
{
	char data;
	TreeNode* first;
	TreeNode* sibling;
};
TreeNode* newNode(int x)
{
	TreeNode* q = new TreeNode();
	q->data = x;
	q->first = NULL;
	q->sibling = NULL;
	return q;
}
TreeNode* addchild(TreeNode* p, char x)
{
	TreeNode* q = newNode(x);
	if (p == NULL) p = q;
	else if (p->first != NULL)
	{
		q->sibling = p->sibling;
		p->sibling = q;
	}
	else p->first = q;
	return q;
}
TreeNode* addsibling(TreeNode* p, char x)
{
	TreeNode* q = newNode(x);
	if (p == NULL) p = q;
	else 
	{
		q->sibling = p->sibling;
		p->sibling = q;
	}
	return q;
}
void preOrder(TreeNode* p)
{
	if (p != NULL)
	{
		TreeNode* q = p->first;
		cout << p->data << '-';
		preOrder(q);
		if (q != NULL)
		{
			q = q->sibling;
			while (q != NULL)
			{
				preOrder(q);
				q = q->sibling;
			}
		}
	}
}
void inOrder(TreeNode* p)
{
	if (p != NULL)
	{
		TreeNode* q = p->first;
		inOrder(q);
		cout << p->data << '-';
		if (q != NULL)
		{
			q = q->sibling;
			while (q != NULL)
			{
				inOrder(q);
				q = q->sibling;
			}
		}
	}
}
void postOrder(TreeNode* p)
{
	if (p != NULL)
	{
		TreeNode* q = p->first;
		postOrder(q);
		if (q != NULL)
		{
			q = q->sibling;
			while (q != NULL)
			{
				postOrder(q);
				q = q->sibling;
			}
		}
		cout << p->data << '-';
	}
}
TreeNode* find(TreeNode* T, char x)
{
	if (T == NULL) return NULL;
	TreeNode* p;
	if (T->data == x) { p = T; return p; }
	TreeNode* q = T->first;
	p = NULL;
	while (p == NULL && q != NULL)
	{
		p = find(q, x);
		q = q->sibling;
	}
	return p;
}
int main()
{
	TreeNode* T = newNode('A');
	int luachon ;
	do
	{
		cout << "nhan 1 them nut con" << endl;
		cout << "nhan 2 them nut anh em" << endl;
		cout << "nhan 3 xuat cay theo thu tu preorder" << endl;
		cout << "nhan 4 xuat cay theo thu tu inorder" << endl;
		cout << "nhan 5 xuat cay theo thu tu postorder" << endl;
		cout << "nhan 6 de ket thuc" << endl;
		cin >> luachon;
		switch (luachon)
		{
		case 1:
		{
			system("cls");
			TreeNode* t;
			char x,y;
			cout << "nhap nut cha: " << endl;
			cin >> x;
			cout << "nhap nut con: " << endl;
			cin >> y;
			t = newNode(x);
			addchild(t, y);
			break;
		}
		case 2:
		{
			system("cls");
			TreeNode* t;
			char x, y;
			cout << "nhap nut cha: " << endl;
			cin >> x;
			cout << "nhap nut con: " << endl;
			cin >> y;
			t = newNode(x);
			addsibling(t, y);
			break;
		}
		case 3:
		{
			system("cls");
			cout << "PREORDER" << endl;
			preOrder(T);
			break;
		}
		case 4:
		{
			system("cls");
			cout << "INORDER" << endl;
			inOrder(T);
			break;
		}
		case 5:
		{
			system("cls");
			cout << "POSTORDER" << endl;
			postOrder(T);
			break;
		}
		default:
			cout << "ket thuc chuong trinh!" << endl;
			break;
		}

	} while (luachon != 6);

	cout<<"xin chao anh em";
	// TreeNode *A =T, *B, *C, *D, *E, *F, *G, *H, *I, *J, *K, *L, *M, *N, *P, *Q; 
	// B = addchild(A, 'B'); 
	// C = addsibling(B, 'C'); 
	// D = addsibling(C, 'D');
	// E = addsibling(D, 'E');
	// F = addsibling(E, 'F');
	// G = addsibling(F, 'G');
	// H = addchild(D, 'H');
	
	// I = addchild(E, 'I');
	// J = addsibling(I, 'J');
	// P = addchild(J, 'P');
	// Q = addsibling(P, 'Q');
	

	// K = addchild(F, 'K');
	// L = addsibling(K, 'L');
	// M = addsibling(L, 'M');
	 
	// N = addchild(G, 'N');

	
	
	 

}
#include "list.h"

List::List() 
{
	head = new Node;
	tail = new Node(-1, head, NULL);
	head->next = tail;
}

List::List(int n)
{
	head = new Node;
	tail = new Node(-1, head, NULL);
	head->next = tail;
	for (int i = 0; i < n; i++)
	{	
		int x = rand() % 50;
		AddToTail(x);
	}
}    

List::List (int *a, int n)
{
	head = new Node;
	tail = new Node(-1, head, NULL);
	head->next = tail;
	for (int i = 0; i < n; i++)
	{	

		AddToTail(a[i]);
	}
}  

List::List(const List &S)
{
	head = new Node;
	tail = new Node(-1, head, NULL);
	head->next = tail;

	Node* t = S.head->next;    // бегунок по списку t
	while (t != S.tail)
	{
		AddToTail(t->key);
		t = t->next;
	}
}

List::~List() 
{
	Clear();
	delete head;
	delete tail;
}

List & List::operator= (const List &s)
{
	if (this == &s)
		return *this;
	Clear();
	Node* p = s.head->next;
	while (p != s.tail)
	{
		AddToTail(p->key);
		p = p->next;
	}
	return *this;

}

void List::AddAfter (int k, Node* pr)
{
	Node *q=new Node;
	q->key=k;
	q->prev=pr;
	q->next=pr->next;
	//вместо этих 4-х строк можно записать одну
	//Node *q=new Node(k,pr, pr->next);
	pr->next=q;
	q->next->prev=q;
}

void List::AddToTail (int x)
{
	AddAfter(x, tail->prev);
}

void List::AddToHead (int x)
{
	AddAfter(x, head);
}

void List::AddToTail (List S)
{
	try
	{
		if (S.Empty())
			throw "Вы пытаетесь добавить пустой список, так нельзя!!";
		Node* p = S.head->next;
		while (p != S.tail)
		{
			AddToTail(p->key);
			p = p->next;
		}
	}
	catch (const char* exception)
	{
		std::cout << exception << std::endl;
	}
}

void List::AddToHead (List S)
{
	try
	{
		if (S.head->next == S.tail)
			throw "Вы пытаетесь добавить пустой список, так нельзя!!";
		Node* p = S.tail->prev;
		while (p != S.head)
		{
			AddToHead(p->key);
			p = p->prev;
		}
	}
	catch (const char* exception)
	{
		std::cout << exception << std::endl;
	}
}


void List::Del (Node *p)
{
	Node* t1;
	Node* t2;
	t1 = p->prev;
	t2 = p->next;
	t1->next = t2;
	t2->prev = t1;
	// or
	// p->prev->next = p->next;
	// p->next->prev = p->prev;
	delete p;
}

void List::DelTail()
{
	if (head->next == tail)
		puts("Список пустой");
	else
		Del(tail->prev);
}

void List::DelHead()
{
	if(head->next==tail)
		std::cout << "list is empty" << std::endl;
	else
		Del(head->next);
}

Node* List::FindKey (int k)
{
	try 
	{
		if (head->next == tail)
			throw "Список пустой!";
		Node* p = head->next;
		while (p != tail && p->key != k)
			p = p->next;
		if (p == tail)
			return NULL;
		else
			return p;
	}
	catch (const char* exception)
	{
		std::cout << exception << std::endl;
	}
	return NULL;
}

Node* List::FindPos (int pos)
{
	int i=1;
	if (head->next == tail)
	{
		puts("Список пустой!");
		return NULL;
	}
	else
	{
		Node* p = head->next;
		while ((p != tail) && (i < pos))
		{
			i++;
			p = p->next;
		}
		if (p == tail)
		{
			std::cout << "В списке элементов меньше, чем " << pos << std::endl;
			return NULL;
		}
		else
			return p;
	}
}

bool List::Empty()
{
	if (head->next == tail)
		return true;
	else
		return false;
}

bool List::NotEmpty()
{
	if (head->next != tail)
		return true;
	else
		return false;
}

void List::Clear()
{
	while (head->next != tail)
		DelHead();
}

bool List::operator == (List S)
{
	try
	{
		if (S.Empty() or Empty())
			throw "Один из списков пустой!";
		Node* p1 = head->next;
		Node* p2 = S.head->next;
		while ((p1 != tail) and (p2 != S.tail) and (p1->key == p2->key))
		{
			p1 = p1->next;
			p2 = p2->next;
		}
		if ((p1 == tail) or (p2 == S.tail))
			return true;
	}
	catch (const char* exception)
	{
		std::cout << exception << std::endl;
	}
	return false;
}

bool List::operator != (List S)
{
	try
	{
		if (S.Empty() or Empty())
			throw "Один из списков пустой!";
		Node* p1 = head->next;
		Node* p2 = S.head->next;
		while ((p1 != tail) and (p2 != S.tail) and (p1->key == p2->key))
		{
			p1 = p1->next;
			p2 = p2->next;
		}
		if ((p1 == tail) or (p2 == S.tail))
			return false;
	}
	catch (const char* exception)
	{
		std::cout << exception << std::endl;
	}
	return true;
}

Node *List::Max()
{
	Node* M = NULL;
	Node* t = head->next;
	if (t == tail)
	{
		std::cout << "Список пустой" << std::endl;
		return M;
	}
	M = t; t = t->next;
	while (t != tail)
	{
		if (t->key > M->key)
			M = t;
		t = t->next;
	}
	return M;
}

Node *List::Min()
{
	Node* M = NULL;
	Node* t = head->next;
	if (t == tail)
	{
		std::cout << "Список пустой" << std::endl;
		return M;
	}
	M = t; t = t->next;
	while (t != tail)
	{
		if (t->key < M->key)
			M = t;
		t = t->next;
	}
	return M;
}

void List::Scan(int n)
{
	Clear();
	std::cout << "Введите " << n << " элементов списка\n";
	int x;
	for (int i = 0; i < n; i++)
	{	
		std::cin >> x;
		AddToTail(x);
	}

}

void List::Print()
{
	try
	{
		if (Empty())
			throw "Список пустой, выводить нечего!";
		Node* p = head->next;
		while (p != tail)
		{
			std::cout << p->key << " ";
			p = p->next;
		}
		std::cout << std::endl;
	}
	catch (const char* exception)
	{
		std::cout << exception << std::endl;
	}
}

std::ostream & operator << (std::ostream &r, List &X)
{
	X.Print();
	return r;
}

std::istream & operator >> (std::istream &r, List &X)
{
	int N;
	std::cout << "Введите количество элементов списка " << std::endl;
	std::cin >> N;
	X.Scan(N);
	return r;
}

bool List::Inside(int el)
{
	Node* q = FindKey(el);
	if (q)
		return true;
	return false;
}
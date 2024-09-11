#include <iostream>
using namespace std;

struct queue {
	int num;
	queue* next, * prev;
};

void inQfront(queue**, int);
void inQback(queue**, int);
void viewFront(queue*);
void viewBack(queue*);
void divide(queue**, queue**, queue*);
void del(queue**);

int main()
{
	int n, i, kod, el;
	queue* begin = NULL, * end = NULL, * evenF = NULL, * evenE = NULL, * unevenF = NULL, * unevenE = NULL, * t = new queue;

	while (1) {
		cout << "Welcome to the menu!\n 1 - create queue\n 2 - add to queue (to begin)\n 3 - add to queue (to end)\n 4 - view queue (from begin)\n 5 - view queue(from end)\n 6 - MaGiC sTufF\n 7 - exit\n";
		cin >> kod;
		switch (kod) {
		case 1: cout << "Enter the first element\n";
			cin >> el;
			t->num = el;
			t->next = t->prev = NULL;
			begin = end = t;
			cout << "The queue has been made\n";
			system("pause");
			system("cls");
			break;
		case 2: if (begin == NULL && end == NULL) {
			cout << "Create a queue first!\n";
			system("pause");
			system("cls");
			break;
		}
			  cout << "Enter the number of elements you want to add\n";
			  cin >> n;
			  for (i = 1; i <= n; i++) {
				  cout << "Enter the element ";
				  cin >> el;
				  inQfront(&begin, el);
			  }
			  cout << "The element have been addded\n";
			  system("pause");
			  system("cls");
			  break;
		case 3:if (begin == NULL && end == NULL) {
			cout << "Create a queue first!\n";
			system("pause");
			system("cls");
			break;
		}
			  cout << "Enter the number of elements you want to add\n";
			  cin >> n;
			  for (i = 1; i <= n; i++) {
				  cout << "Enter the element ";
				  cin >> el;
				  inQback(&end, el);
			  }
			  cout << "The element have been addded\n";
			  system("pause");
			  system("cls");
			  break;
		case 4: if (begin == NULL && evenF == NULL && unevenF == NULL) {
			cout << "No queue to view!\n";
			system("pause");
			system("cls");
			break;
		}
			  if (evenF == NULL && unevenF == NULL) {
				  cout << "The numbers are\n";
				  viewFront(begin);
			  }
			  else {
				  if (unevenF != NULL) {
					  cout << "Uneven numbers are\n";
					  viewFront(unevenF);
				  }
				  if (evenF != NULL) {
					  cout << "Even numbers are\n";
					  viewFront(evenF);
				  }
			  }
			  system("pause");
			  system("cls");
			  break;
		case 5: if (end == NULL && evenE == NULL && unevenE == NULL) {
			cout << "No queue to view!\n";
			system("pause");
			system("cls");
			break;
		}
			  if (evenE == NULL && unevenE == NULL) {
				  cout << "The numbers are\n";
				  viewBack(end);
			  }
			  else {
				  if (unevenE != NULL) {
					  cout << "Uneven numbers are\n";
					  viewBack(unevenE);
				  }
				  if (evenE != NULL) {
					  cout << "Even numbers are\n";
					  viewBack(evenE);
				  }
			  }
			  system("pause");
			  system("cls");
			  break;
		case 6: if (begin == NULL) {
			cout << "No queue to divide!\n";
			system("pause");
			system("cls");
			break;
		}
			  if (evenF != NULL || unevenF != NULL) {
				  cout << "The stack has been already divided\n";
				  system("pause");
				  system("cls");
				  break;
			  }
			  t = begin->next;
			  while (t->next != NULL) {
				  if (t->num % 2 == 0) {
					  t = t->next;
					  divide(&evenF, &evenE, t->prev);
				  }
				  else t = t->next;
			  }
			  if (begin->num % 2 == 0) {
				  queue* e_buf = begin;
				  begin = begin->next;
				  begin->prev = NULL;
				  if (evenE == NULL) {
					  e_buf->next = e_buf->prev = NULL;
					  evenF = evenE = e_buf;
				  }
				  else {
					  e_buf->next = evenF;
					  e_buf->prev = NULL;
					  evenF->prev = e_buf;
					  evenF = e_buf;
				  }
			  }
			  if (end->num % 2 == 0) {
				  queue* e_buf = end;
				  end = end->prev;
				  end->next = NULL;
				  if (evenE == NULL) {
					  e_buf->next = e_buf->prev = NULL;
					  evenF = evenE = e_buf;
				  }
				  else {
					  e_buf->next = NULL;
					  e_buf->prev = evenE;
					  evenE->next = e_buf;
					  evenE = e_buf;
				  }
			  }

			  unevenF = begin;
			  unevenE = end;
			  cout << "stack has been divided\n";
			  system("pause");
			  system("cls");
			  break;
		case 7: del(&begin);
			del(&evenF);
			del(&unevenF);
			return 0;
		}
	}
}

void inQfront(queue** begin, int n) {
	queue* t = new queue;
	t->num = n;
	t->prev = NULL;
	t->next = *begin;
	(*begin)->prev = t;
	*begin = t;
}

void inQback(queue** end, int n) {
	queue* t = new queue;
	t->num = n;
	t->next = NULL;
	t->prev = *end;
	(*end)->next = t;
	*end = t;
}

void viewFront(queue* begin) {
	queue* t = begin;
	while (t != NULL) {
		cout << t->num << endl;
		t = t->next;
	}
}

void viewBack(queue* end) {
	queue* t = end;
	while (t != NULL) {
		cout << t->num << endl;
		t = t->prev;
	}
}

void divide(queue** begin, queue** end, queue* e) {
	queue* t = e;
	(e->prev)->next = e->next;
	(e->next)->prev = e->prev;
	if (*end == NULL) {
		t->next = t->prev = NULL;
		*begin = *end = t;
	}
	else {
		t->next = NULL;
		t->prev = *end;
		(*end)->next = t;
		*end = t;
	}
}

void del(queue** p) {
	queue* t;
	while (*p != NULL) {
		t = *p;
		*p = (*p)->next;
		(*p)->prev = NULL;
		delete t;
	}
}

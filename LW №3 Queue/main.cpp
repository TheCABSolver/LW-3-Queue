#include <iostream>
#include <conio.h>
#include <ctime>

using namespace std;

struct List
{
	double data;
	List *prev, *next;
} *begin, *end;

void MainGui();
void View(List* p, char mode);
void Del_All(List*&);
List* Average(List*);

int main()
{
	setlocale(0, "ru");
	List *begin = NULL, *end = NULL;
	char choose;

	do
	{
		MainGui();
		choose = _getch();
		if (choose == '1')
		{
			system("cls");
			srand(time(0));
			int data, num;
			
			cout << " ������� ���-�� ���������: ";
			cin >> num;
			for (int i = 0; i < num; i++)
			{
				data = rand() % 21 - 10;
				
			}
		}
		else
			if (choose == '2')
			{
				system("cls");
				if (!begin)
				{
					cout << " \t! ���� ���� ! " << endl;
					continue;
				}
				else
				{
					cout << "\n �������� ������ ��������� ������: "
						<< "\n 1. � ������ \n"
						<< " 2. � ����� \n";
					choose = _getch();
						system("cls");
						View();
						cout << endl;
				}
			}
			else
				if (choose == '3')
				{
					system("cls");
					if (!begin)
					{
						cout << "\t! ���� ���� !\n";
						continue;
					}

					system("cls");
					cout << " �� ����� ������ ������� ����? \n"
						<< "  1. �� \n"
						<< "  ����� ������ - ��� \n";
					choose = _getch();
					system("cls");
					if (choose == '1')
					{
						Del_All(begin);
						cout << " \t! ���� ������ !\n";
					}
					else
						cout << " \t! �������� �������� !\n";
				}
				else
					if (choose == '4')
					{
						system("cls");
						if (!begin)
						{
							cout << "\t! ���� ���� !\n";
							continue;
						}

					}
					else
						if (choose == '5')
						{
							system("cls");
							if (!begin)
							{
								cout << "\t! ���� ���� !\n";
								continue;
							}

							system("cls");
							cout << "\t! ������� �������������� ��������� ����� !\n";
							begin = Average(begin);
						}
						else
						if (choose != 27)
							{
								system("cls");
								cout << "\t ! ����������� ���� !\n";
							}
	} while (choose != 27);
	Del_All(begin);
	return 0;
}

void MainGui()
{
	cout << " ------------ ������ ------------\n"
		<< " |\t1. ���������� ��������� \t|\n"
		<< " |\t2. �������� \t\t|\n"
		<< " |\t3. �������� \t\t|\n"
		<< " |\t4. ���������� \t\t|\n"
		<< " |\t5. ������� �������.\t|\n"
		<< " |\t Esc - ����� \t\t|\n"
		<< " --------------------------------"
		<< endl;
}

void PushBack(List** b, List **e, double in)
{
	List* t = new List;
	t->data = in;
	if (!*b)
	{
		t->next = t->prev = NULL;
		*b = *e = t;
	}
	t->next = NULL;
	t->prev = *e;
	(*e)->next = t;
	*e = t;
}

void PushForward(List** b, List** e, double in)
{
	List* t = new List;
	t->data = in;
	if (!*b)
	{
		t->next = t->prev = NULL;
		*b = *e = t;
	}
	t->prev = NULL;
	t->next = *b;
	(*b)->prev = t;
	*b = t;
}

//void OutStack(List*& p, double* out)
//{
//	List* t = p;
//	*out = p->data;
//	p = p->next;
//	delete t;
//}

void View(List* p, char mode)
{
	List* t = p;
	if (mode == '1')
	{
		while (t)
		{
			cout << " �������� ������ � ������: " << t->data << " ";
			t = t->next;
		}
		cout << endl;
	}
	else
		if (mode == '2')
		{
			while (t)
			{
				cout << " �������� ������ � �����: " << t->data << " ";
				t = t->prev;
			}
			cout << endl;
		}
		else
			cout << " ������������ ����!\n";
}

//void Del_All(List*& p)
//{
//	List* t;
//	while (p)
//	{
//		t = p;
//		p = p->next;
//		delete t;
//	}
//}
//
//List* Average(List* p)
//{
//	InStack(&p, 20);
//	List* t = p->next;
//
//	int i = 0;
//	double aver = 0;
//	while (t != NULL)
//	{
//		aver += t->data;
//		i++;
//		t = t->next;
//	}
//
//	t = p;
//	p = p->next;
//	p->data = aver / i;
//	delete t;
//	return p;
//}
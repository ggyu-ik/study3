#include "Inventory.h"
#include "Item.h"

using namespace std;

int main()
{
	Item Sword("��", 70);
	Item Shield("����", 50);
	Item Bow("Ȱ", 100);

	Inventory<Item> inv1(3); // ������ Ŭ������ ���ҷ� �޴� �κ��丮 Ŭ���� �ν��Ͻ�ȭ

	inv1.AddItem(Sword);
	inv1.AddItem(Shield);
	inv1.AddItem(Bow);

	cout << "������ ���" << endl;
	cout << "====================" << endl;
	inv1.PrintAllItems(); // �������� �߰� �� ��� ������ ���

	inv1.RemoveLastItem(); // ������ �������� Ȱ ����

	inv1.AddItem(Sword); // �� �߰�
	
	cout << "������ ���" << endl;
	cout << "====================" << endl;
	inv1.PrintAllItems(); // Ȱ ����, �� �߰� �� ��� ������ ���
	cout << "������ �ִ� ũ��: " << inv1.GetCapacity() << endl; // ���� inv1�� capacity

	inv1.AddItem(Bow); // size = Capacity �� �� ������ �߰�

	cout << "Ȱ �߰� �� ������ �ִ� ũ��: " << inv1.GetCapacity() << endl; // size > Capacity �� �� inv1�� capacity

	inv1.AddItem(Sword); // size 6���� ������ ä��
	inv1.AddItem(Shield); // size 6���� ������ ä��

	cout << "������ ���" << endl;
	cout << "====================" << endl;
	inv1.PrintAllItems();
	cout << "������ �ִ� ũ��: " << inv1.GetCapacity() << endl; // ���� capacity, size �Ѵ� 6

	inv1.Resize(4); // capacity = 4�� ���� 5,6��° ������ Sword�� Shield�� ����

	cout << "������ ���" << endl;
	cout << "====================" << endl;
	inv1.PrintAllItems(); // capacity 4�� ���� �� ������ ���
	cout << "������ �ִ� ũ��: " << inv1.GetCapacity() << endl;

	Inventory<Item> inv2(inv1); // inv2�� inv1�� �����ϸ� ����

	cout << "inv2 ������ ���" << endl;
	cout << "====================" << endl;
	inv2.PrintAllItems(); // inv2�� ������ ���
	cout << "���� ������ �ִ� ũ��: " << inv2.GetCapacity() << endl; // inv2�� capacity

	inv2.SortItems(); // inv2 ������ ���ݱ��� ������������ ����

	cout << "inv2 ������ ���(���� ��)" << endl;
	cout << "====================" << endl;
	inv2.PrintAllItems(); // ���� �� inv2�� ������ ���

	cout << "inv1 ������ ���(���� ��)" << endl;
	cout << "====================" << endl;
	inv1.Assign(inv2); // inv1�� ���ݼ����� ���ĵ� inv2 ����
	inv1.PrintAllItems(); // ���� �� inv1 ������ ���
}
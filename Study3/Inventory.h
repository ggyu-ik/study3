#pragma once
#include <iostream>

template<typename T>
class Inventory
{
private:	
	T* pItems; // �������� ���� ���� �迭
	int capacity; // ���� �ִ� ����
	int size; // ������ ����

public:
	Inventory(int cap = 10) : capacity((cap <= 0) ? cap = 1 : cap), size(0)
	{
		pItems = new T[cap];
	}

	// ���� ������
	Inventory(const Inventory<T>& other) // other�� �κ��丮 ��ü
	{
		capacity = other.capacity;
		size = other.size;
		pItems = new T[capacity];
		for (int i = 0; i < size; ++i) // size��ŭ
		{
			pItems[i] = other.pItems[i]; // ����
		}
		cout << "�κ��丮 ���� �Ϸ�" << endl;
	}

	// ���� ���� �Լ�
	void Assign(const Inventory<T>& other)
	{
		delete[] pItems; // ��ü�� ���� �������ִ� �迭 ����.

		capacity = other.capacity; // ���� ������ �� ��ü���� ������� ���� ������.
		size = other.size;
		pItems = new T[capacity]; // �迭 ���� ����.
		for (int i = 0; i < size; ++i)
		{
			pItems[i] = other.pItems[i];
		}
	}
	
	void AddItem(const T& item)
	{
		if (size < capacity) // �ʼ� ��ɰ� �����ϰ� item�� pItems�� ���ҷ� ����
		{
			pItems[size] = item;
			++size;
		}
		else // size�� capacity �̻��̸�
		{
			capacity = capacity * 2; // capacity ���� 2��
			T* newItems = new T[capacity]; // ���ο� �迭 ����
			for (int i = 0; i < size; ++i) // size��ŭ ���ο� �迭�� ���� ����
			{
				newItems[i] = pItems[i];
			}
			
			newItems[size] = item;
			++size;

			delete[] pItems; // ���� �ִ� �迭 ������ ����.
			pItems = newItems; // �迭 �����Ϳ� newItems�� �ּ� ����.
		}
	}

	void RemoveLastItem()
	{
		if (size > 0)
		{
			--size;
		}
		else
		{
			std::cout << "�κ��丮�� ����ֽ��ϴ�." << std::endl;
		}
	}

	void Resize(int newCapacity)
	{
		if (newCapacity <= 0) // ���ο� ������ 0���ϸ� 1�� ����
		{
			newCapacity = 1;
		}

		T* newItems = new T[newCapacity]; // ���ο� �迭�� newCapacity ũ��� ����

		if (size > newCapacity) // ���Ҵ�� ������ ���� ������ �������� ������
		{
			size = newCapacity; // size�� ���Ҵ�� �������� ���缭 �� ���� ������ ���Ҵ� ����
		}

		for (int i = 0; i < size; ++i) // size ��ŭ ���ο� �迭�� ���� ����
		{
			newItems[i] = pItems[i];
		}

		delete[] pItems; // ���� �� ���� �ִ� �迭 �ּ� �޸𸮿��� ����

		pItems = newItems; // ���ο� �迭 �ּ� ����
		capacity = newCapacity;
	}

	bool compareItemsByPrice(const Item& a, const Item& b)
	{
		return a.GetPrice() < b.GetPrice(); // a�� �տ� ���� ����, �����ſ��� ū������ -> ��������
	}

	void SortItems()
	{
		std::sort(pItems, pItems + size, compareItemsByPrice); // �迭 �����ּҺ��� ������ ������ ���� �ּұ���
	}

	int GetSize() const
	{
		return size;
	}

	int GetCapacity() const
	{
		return capacity;
	}

	void PrintAllItems() const
	{
		for (int i = 0; i < size; ++i)
		{
			std::cout << "[�̸�: " << pItems[i].name << ", ����: " << pItems[i].price << "G]" << std::endl;
		}
	}

	~Inventory()
	{
		delete[] pItems;
		pItems = nullptr;
	}
};
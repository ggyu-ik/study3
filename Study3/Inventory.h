#pragma once
#include <iostream>

template<typename T>
class Inventory
{
private:	
	T* pItems; // 아이템을 받을 동적 배열
	int capacity; // 가방 최대 공간
	int size; // 아이템 개수

public:
	Inventory(int cap = 10) : capacity((cap <= 0) ? cap = 1 : cap), size(0)
	{
		pItems = new T[cap];
	}

	// 복사 생성자
	Inventory(const Inventory<T>& other) // other는 인벤토리 객체
	{
		capacity = other.capacity;
		size = other.size;
		pItems = new T[capacity];
		for (int i = 0; i < size; ++i) // size만큼
		{
			pItems[i] = other.pItems[i]; // 복사
		}
		cout << "인벤토리 복사 완료" << endl;
	}

	// 대입 역할 함수
	void Assign(const Inventory<T>& other)
	{
		delete[] pItems; // 객체가 원래 가지고있던 배열 삭제.

		capacity = other.capacity; // 값을 가지고 올 객체에서 멤버변수 값을 대입함.
		size = other.size;
		pItems = new T[capacity]; // 배열 새로 생성.
		for (int i = 0; i < size; ++i)
		{
			pItems[i] = other.pItems[i];
		}
	}
	
	void AddItem(const T& item)
	{
		if (size < capacity) // 필수 기능과 동일하게 item을 pItems의 원소로 받음
		{
			pItems[size] = item;
			++size;
		}
		else // size가 capacity 이상이면
		{
			capacity = capacity * 2; // capacity 공간 2배
			T* newItems = new T[capacity]; // 새로운 배열 생성
			for (int i = 0; i < size; ++i) // size만큼 새로운 배열에 원소 복사
			{
				newItems[i] = pItems[i];
			}
			
			newItems[size] = item;
			++size;

			delete[] pItems; // 원래 있던 배열 포인터 삭제.
			pItems = newItems; // 배열 포인터에 newItems의 주소 대입.
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
			std::cout << "인벤토리가 비어있습니다." << std::endl;
		}
	}

	void Resize(int newCapacity)
	{
		if (newCapacity <= 0) // 새로운 공간이 0이하면 1로 보정
		{
			newCapacity = 1;
		}

		T* newItems = new T[newCapacity]; // 새로운 배열을 newCapacity 크기로 생성

		if (size > newCapacity) // 재할당된 공간이 기존 아이템 개수보다 작으면
		{
			size = newCapacity; // size를 재할당된 공간으로 맞춰서 그 뒤의 아이템 원소는 삭제
		}

		for (int i = 0; i < size; ++i) // size 만큼 새로운 배열로 원소 복사
		{
			newItems[i] = pItems[i];
		}

		delete[] pItems; // 복사 후 원래 있던 배열 주소 메모리에서 삭제

		pItems = newItems; // 새로운 배열 주소 대입
		capacity = newCapacity;
	}

	bool compareItemsByPrice(const Item& a, const Item& b)
	{
		return a.GetPrice() < b.GetPrice(); // a가 앞에 오는 원소, 작은거에서 큰순으로 -> 오름차순
	}

	void SortItems()
	{
		std::sort(pItems, pItems + size, compareItemsByPrice); // 배열 시작주소부터 마지막 원소의 다음 주소까지
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
			std::cout << "[이름: " << pItems[i].name << ", 가격: " << pItems[i].price << "G]" << std::endl;
		}
	}

	~Inventory()
	{
		delete[] pItems;
		pItems = nullptr;
	}
};
#include "Inventory.h"
#include "Item.h"

using namespace std;

int main()
{
	Item Sword("검", 70);
	Item Shield("방패", 50);
	Item Bow("활", 100);

	Inventory<Item> inv1(3); // 아이템 클래스를 원소로 받는 인벤토리 클래스 인스턴스화

	inv1.AddItem(Sword);
	inv1.AddItem(Shield);
	inv1.AddItem(Bow);

	cout << "아이템 목록" << endl;
	cout << "====================" << endl;
	inv1.PrintAllItems(); // 아이템을 추가 후 모든 아이템 출력

	inv1.RemoveLastItem(); // 마지막 아이템인 활 삭제

	inv1.AddItem(Sword); // 검 추가
	
	cout << "아이템 목록" << endl;
	cout << "====================" << endl;
	inv1.PrintAllItems(); // 활 삭제, 검 추가 후 모든 아이템 출력
	cout << "가방의 최대 크기: " << inv1.GetCapacity() << endl; // 현재 inv1의 capacity

	inv1.AddItem(Bow); // size = Capacity 일 때 아이템 추가

	cout << "활 추가 후 가방의 최대 크기: " << inv1.GetCapacity() << endl; // size > Capacity 일 때 inv1의 capacity

	inv1.AddItem(Sword); // size 6까지 아이템 채움
	inv1.AddItem(Shield); // size 6까지 아이템 채움

	cout << "아이템 목록" << endl;
	cout << "====================" << endl;
	inv1.PrintAllItems();
	cout << "가방의 최대 크기: " << inv1.GetCapacity() << endl; // 현재 capacity, size 둘다 6

	inv1.Resize(4); // capacity = 4로 조정 5,6번째 원소인 Sword와 Shield는 삭제

	cout << "아이템 목록" << endl;
	cout << "====================" << endl;
	inv1.PrintAllItems(); // capacity 4로 조정 후 아이템 출력
	cout << "가방의 최대 크기: " << inv1.GetCapacity() << endl;

	Inventory<Item> inv2(inv1); // inv2에 inv1을 복사하며 생성

	cout << "inv2 아이템 목록" << endl;
	cout << "====================" << endl;
	inv2.PrintAllItems(); // inv2의 아이템 출력
	cout << "현재 가방의 최대 크기: " << inv2.GetCapacity() << endl; // inv2의 capacity

	inv2.SortItems(); // inv2 아이템 가격기준 오름차순으로 정렬

	cout << "inv2 아이템 목록(정렬 후)" << endl;
	cout << "====================" << endl;
	inv2.PrintAllItems(); // 정렬 후 inv2의 아이템 출력

	cout << "inv1 아이템 목록(대입 후)" << endl;
	cout << "====================" << endl;
	inv1.Assign(inv2); // inv1에 가격순으로 정렬된 inv2 대입
	inv1.PrintAllItems(); // 대입 후 inv1 아이템 출력
}
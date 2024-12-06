/**
 * Problem 2
 */

#include <iostream>
#include <string>
#include <initializer_list>

struct ListNode
{
    ListNode() : val{ 0 }, next{ nullptr } { }
    ListNode(int x) : val{ x }, next{ nullptr } { }
    ListNode(int x, ListNode* next) : val{ x }, next{ next } { }

    int val;
    ListNode* next;
};

void PrintLinkedList(std::string prefix, ListNode* pHead)
{
    if (not prefix.empty()) std::cout << prefix << ' ';
    std::cout << "LinkedList{ ";
    while (pHead)
    {
        std::cout << pHead->val << ' ';
        pHead = pHead->next;
    }
    std::cout << "}\n";
}

class Solution
{
public:
    ListNode* AddTwoNumbers(ListNode* l1, ListNode* l2)
    {
        int overflow = 0; // can be 0 or 1

        ListNode* pHead = new ListNode{};
        ListNode* pCurr = pHead;

        while (l1 or l2 or overflow == 1)
        {
            int sum = overflow;
            sum += l1 ? l1->val : 0;
            sum += l2 ? l2->val : 0;

            overflow = sum / 10;
            pCurr->val = sum % 10;

            bool l1HasNext = l1 and l1->next;
            bool l2HasNext = l2 and l2->next;

            if (l1HasNext or l2HasNext or overflow == 1)
            {
                ListNode* pNewEntry = new ListNode{};
                pCurr->next = pNewEntry;
                pCurr = pCurr->next;
            }

            l1 = l1HasNext ? l1->next : nullptr;
            l2 = l2HasNext ? l2->next : nullptr;
        }

        return pHead;
    }
};

ListNode* GenerateLinkedList(std::initializer_list<int> il)
{
    if (il.size() == 0) return nullptr;

    ListNode* pHead = new ListNode{};
    ListNode* pCurr = pHead;

    std::size_t ilSize = il.size();
    std::size_t insertedCount = 0;
    for (const auto& val : il)
    {
        pCurr->val = val;

        if (insertedCount < ilSize - 1)
            pCurr->next = new ListNode{};

        pCurr = pCurr->next;

        ++insertedCount;
    }

    return pHead;
}

struct LinkedListComparator
{
    bool operator()(ListNode* lhs, ListNode* rhs)
    {
        if (not lhs and not rhs) return true;
        if (not lhs or not rhs) return false;

        while (lhs)
        {
            if (lhs->val != rhs->val) return false;
            if ((not lhs->next and rhs->next) or
                (lhs->next and not rhs->next)) return false;

            lhs = lhs->next;
            rhs = rhs->next;
        }

        return true;
    }
};

int main()
{
    Solution sol{};

    {
        std::cout << "Test 1" << std::endl;

        auto pHead_1 = GenerateLinkedList({2, 4, 3});
        PrintLinkedList("    pHead_1  ", pHead_1);

        auto pHead_2 = GenerateLinkedList({5, 6, 4});
        PrintLinkedList("    pHead_2  ", pHead_2);

        auto pHeadWant = GenerateLinkedList({7, 0, 8});
        PrintLinkedList("    pHeadWant", pHeadWant);

        auto pHeadGot = sol.AddTwoNumbers(pHead_1, pHead_2);
        PrintLinkedList("    pHeadGot ", pHeadGot);

        if (not LinkedListComparator{}(pHeadWant, pHeadGot))
            std::cout << "Test 1 failed" << std::endl;
        else
            std::cout << "Test 1 success" << std::endl;
    }

    {
        std::cout << "\nTest 2" << std::endl;
        auto pHead_1 = GenerateLinkedList({0});
        PrintLinkedList("    pHead_1  ", pHead_1);

        auto pHead_2 = GenerateLinkedList({0});
        PrintLinkedList("    pHead_2  ", pHead_2);

        auto pHeadWant = GenerateLinkedList({0});
        PrintLinkedList("    pHeadWant", pHeadWant);

        auto pHeadGot = sol.AddTwoNumbers(pHead_1, pHead_2);
        PrintLinkedList("    pHeadGot ", pHeadGot);

        if (not LinkedListComparator{}(pHeadWant, pHeadGot))
            std::cout << "Test 2 failed" << std::endl;
        else
            std::cout << "Test 2 success" << std::endl;
    }

    {
        std::cout << "\nTest 3" << std::endl;
        auto pHead_1 = GenerateLinkedList({9, 9, 9, 9, 9, 9, 9});
        PrintLinkedList("    pHead_1  ", pHead_1);

        auto pHead_2 = GenerateLinkedList({9, 9, 9, 9});
        PrintLinkedList("    pHead_2  ", pHead_2);

        auto pHeadWant = GenerateLinkedList({8, 9, 9, 9, 0, 0, 0, 1});
        PrintLinkedList("    pHeadWant", pHeadWant);

        auto pHeadGot = sol.AddTwoNumbers(pHead_1, pHead_2);
        PrintLinkedList("    pHeadGot ", pHeadGot);

        if (not LinkedListComparator{}(pHeadWant, pHeadGot))
            std::cout << "Test 3 failed" << std::endl;
        else
            std::cout << "Test 3 success" << std::endl;
    }

    {
        std::cout << "\nTest 4" << std::endl;
        auto pHead_1 = GenerateLinkedList({5});
        PrintLinkedList("    pHead_1  ", pHead_1);

        auto pHead_2 = GenerateLinkedList({5});
        PrintLinkedList("    pHead_2  ", pHead_2);

        auto pHeadWant = GenerateLinkedList({0, 1});
        PrintLinkedList("    pHeadWant", pHeadWant);

        auto pHeadGot = sol.AddTwoNumbers(pHead_1, pHead_2);
        PrintLinkedList("    pHeadGot ", pHeadGot);

        if (not LinkedListComparator{}(pHeadWant, pHeadGot))
            std::cout << "Test 4 failed" << std::endl;
        else
            std::cout << "Test 4 success" << std::endl;
    }

    return 0;
}

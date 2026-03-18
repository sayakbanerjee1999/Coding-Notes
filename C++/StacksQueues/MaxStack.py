from typing import Optional
from sortedcontainers import SortedList


class Node:
    """Node for doubly linked list."""

    def __init__(self, val: int = 0) -> None:
        self.val: int = val
        self.prev: Optional['Node'] = None
        self.next: Optional['Node'] = None


class DoublyLinkedList:
    """Doubly linked list with sentinel nodes for efficient operations."""

    def __init__(self) -> None:
        # Create sentinel head and tail nodes
        self.head: Node = Node()
        self.tail: Node = Node()
        # Connect sentinels
        self.head.next = self.tail
        self.tail.prev = self.head

    def append(self, val: int) -> Node:
        """
        Append a new node with given value to the end of the list.
        Returns the newly created node.
        """
        node = Node(val)
        # Insert before tail sentinel
        node.next = self.tail
        node.prev = self.tail.prev
        self.tail.prev = node
        node.prev.next = node
        return node

    @staticmethod
    def remove(node: Node) -> Node:
        """
        Remove a node from the list by updating its neighbors' pointers.
        Returns the removed node.
        """
        node.prev.next = node.next
        node.next.prev = node.prev
        return node

    def pop(self) -> Node:
        """
        Remove and return the last node (before tail sentinel).
        """
        return self.remove(self.tail.prev)

    def peek(self) -> int:
        """
        Return the value of the last node without removing it.
        """
        return self.tail.prev.val


class MaxStack:
    """
    Stack data structure that supports retrieving the maximum element.
    Supports O(log n) push, pop, top, peekMax, and popMax operations.
    """

    def __init__(self) -> None:
        # Doubly linked list to maintain stack order
        self.stack: DoublyLinkedList = DoublyLinkedList()
        # Sorted list to efficiently track maximum elements
        # Stores references to nodes, sorted by their values
        self.sorted_list: SortedList = SortedList(key=lambda x: x.val)

    def push(self, x: int) -> None:
        """
        Push element x onto the stack.
        """
        # Add node to the end of the stack
        node = self.stack.append(x)
        # Add node reference to sorted list for max tracking
        self.sorted_list.add(node)

    def pop(self) -> int:
        """
        Remove and return the top element from the stack.
        """
        # Remove from stack
        node = self.stack.pop()
        # Remove from sorted list
        self.sorted_list.remove(node)
        return node.val

    def top(self) -> int:
        """
        Get the top element without removing it.
        """
        return self.stack.peek()

    def peekMax(self) -> int:
        """
        Get the maximum element in the stack without removing it.
        """
        # Last element in sorted list is the maximum
        return self.sorted_list[-1].val

    def popMax(self) -> int:
        """
        Remove and return the maximum element from the stack.
        """
        # Get and remove max node from sorted list
        node = self.sorted_list.pop()
        # Remove the same node from the stack
        DoublyLinkedList.remove(node)
        return node.val

class Solution:
    def mergeNodes(self, head: Optional[ListNode]) -> Optional[ListNode]:
        current = head
        while current:
            cont = current.next
            s = current.val
            while cont and cont.val != 0:
                s += cont.val
                cont = cont.next
            current.val = s
            current.next = cont.next
            current =  current.next
        return head

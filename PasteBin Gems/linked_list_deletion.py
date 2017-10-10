def remove1(self, item):
    previous_node = self.head
    current_node = previous_node.next
    while current_node is not None:
        if current_node.data == item:
            if self.head == previous_node:
                self.head.next = current_node.next
            else:
                previous_node.next = current_node.next
            return
        previous_node = current_node
        current_node = current_node.next
    return None


def remove2(self, item):
    previous_node = self.head
    current_node = previous_node.next
    while current_node is not None:
        if current_node.data == item:
            break
        previous_node = current_node
        current_node = current_node.next
    if current_node is None:
        return None
    
    if self.head == previous_node:
        self.head.next = current_node.next
    else:
        previous_node.next = current_node.next
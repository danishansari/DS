
class Node(object):
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

class BST(object):
    def __init__(self):
        self.root = None

    def insert(self, node, root=None):
        if root is None:
            root = self.root
        if self.root is None:
            self.root = node
        elif node.data <= root.data:
            if root.left is None:
                root.left = node
            else:
                self.insert(node, root.left)
        else:
            if root.right is None:
                root.right = node
            else:
                self.insert(node, root.right)

    def search(self, node, root=None):
        if root is None:
            root = self.root
        if node.data == root.data:
            return 1
        elif node.data < root.data:
            if root.left is not None:
                return self.search(node, root.left)
        else:
            if root.right is not None:
                return self.search(node, root.right)
        return 0

    def traverse_in(self, root=None):
        data = []
        if root is None:
            root = self.root
        if root.left is not None:
            data += self.traverse_in(root.left)
        data.append(root.data)
        if root.right is not None:
            data += self.traverse_in(root.right)
        return data

    def delete(self, node, root=None, parent=None):
        if root == None:
            root = self.root
        if node.data == root.data:
            if root.left == None and root.right == None: # leaf node; no child present
                if parent is not None:
                    if root.data < parent.data:
                        parent.left = None
                    else:
                        parent.right = None
            elif root.left == None: # only right child present
                if root.data < parent.data:
                    parent.right = root.right
                else:
                    parent.left = root.right 
            elif root.right == None: # only left child present
                if root.data < parent.data:
                    parent.left = root.left
                else:
                    parent.right = root.left 
            else: # both child present
                d = self.traverse_in(root.right)
                n = Node(d[0])
                self.delete(n)
                root.data = n.data
        elif node.data < root.data:
            self.delete(node, root.left, root)
        else:
            self.delete(node, root.right, root)

def main():
    arr = list(map(int, input('arr>> ').strip().split()))
    if len(arr) == 0:
        arr = [2, 8, 3, 9, 1, 7, 5, 6]
    print ('arr:', arr)
    bst = BST()
    for a in arr:
        print ('inserting:', a)
        node = Node(a)
        bst.insert(node)
    data = bst.traverse_in()
    print ('traverse bst:', data)
    while True:
        inp = input('action(i/d/s): ')
        if inp == 'q':
            break
        elif inp in ['i', 'd', 's']:
            v = int(input('value: '))
            node = Node(v)
            if inp == 'i':
                if bst.search(node) == 0:
                    bst.insert(node)
                else:
                    print ('value already exists!!')
            elif inp == 'd':
                if bst.search(node) == 1:
                    bst.delete(node)
                else:
                    print ('value does not exists!!')
            else:
                print ('Value %d found ='%v, bst.search(node))
        else:
            print ('invalid input!!')
        print (bst.traverse_in())


if __name__=='__main__':
    main()

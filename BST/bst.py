import pdb

class BST(object):
    def __init__(self, data=None):
        self.data = data
        self.left = None
        self.right = None

    def insert(self, n):
        if self.data is None:
            self.data = n
        else:
            if n <= self.data:
                if self.left is not None:
                    self.left.insert(n)
                else:
                    self.left = BST(n)
            else:
                if self.right is not None:
                    self.right.insert(n)
                else:
                    self.right = BST(n)


    def traverse_in(self, n=-1):
        if n < self.data:
            self.left.traverse_in(n)
        elif n > self.data:
            self.right.traverse_in(n)
        return self

def main():
    keys = list(map(int, input().split()))
    bst = BST()
    for k in keys:
        bst.insert(k)
    bst.traverse_in()
        #x = input('>')

if __name__=='__main__':
    main()

#include <iostream>
#include <memory>

template <class T>
class BinarySearchtree
{
public:
    BinarySearchtree();
    BinarySearchtree(T leaf);
    std::shared_ptr<BinarySearchtree<T>> BST_Insert(std::shared_ptr<BinarySearchtree<T>>& Root, T leaf);
    std::shared_ptr<BinarySearchtree<T>> BSt_Search(std::shared_ptr<BinarySearchtree<T>>& Root, T leaf);
    void Inorder(std::shared_ptr<BinarySearchtree> Root);

    T getData();
    std::shared_ptr<BinarySearchtree<T>> getRightChild(std::shared_ptr<BinarySearchtree<T>>& Root);
    std::shared_ptr<BinarySearchtree<T>> getleftChild(std::shared_ptr<BinarySearchtree<T>>& Root);




private:
    T data;
    std::shared_ptr<BinarySearchtree<T>> right, left;
};

template <class T>
BinarySearchtree<T>::BinarySearchtree()
    : data(0), right(nullptr), left(nullptr) {}

template <class T>
BinarySearchtree<T>::BinarySearchtree(T leaf)
    : data(leaf), right(nullptr), left(nullptr) {}

template <class T>
std::shared_ptr<BinarySearchtree<T>>  BinarySearchtree<T>::BST_Insert(std::shared_ptr<BinarySearchtree<T>>& Root, T leaf)
{
         
        if (!Root)
        {
            return std::make_shared<BinarySearchtree<T>>(leaf);
            std::cout << leaf << "is the root" << std::endl;

        }
        if (leaf > Root->data)
        {
            Root->right= BST_Insert(Root->right, leaf);
            std::cout << leaf << " right inserted" << std::endl;
        }
        else
        {
            Root->left = BST_Insert(Root->left, leaf);
            std::cout << leaf << " left inserted" << std::endl;

        }

        return Root;
}


template <class T>
T BinarySearchtree<T>::getData()
{
    return this->data;
}

template <class T>
std::shared_ptr<BinarySearchtree<T>>  BinarySearchtree<T>::getRightChild(std::shared_ptr<BinarySearchtree<T>>& Root)
{
    return Root->right;
}

template <class T>
std::shared_ptr<BinarySearchtree<T>>  BinarySearchtree<T>::getleftChild(std::shared_ptr<BinarySearchtree<T>>& Root)
{
    return Root->left;
}


template <class T>
std::shared_ptr<BinarySearchtree<T>>  BinarySearchtree<T>::BSt_Search(std::shared_ptr<BinarySearchtree<T>>& Root, T leaf)
{
    if (Root == nullptr || Root->data == leaf)
    {
        return Root;
    }
    if (Root->data > leaf)
    {
        return BSt_Search(Root->left, leaf);
    }
    else
    {
        return BSt_Search(Root->right, leaf);
    }
}


template <class T>
void  BinarySearchtree<T>::Inorder(std::shared_ptr<BinarySearchtree> Root)
{
    if (!Root){ return;}
    Inorder(Root->left);
    std::cout << Root->data << std::endl;
    Inorder(Root->right);
}


int main()
{
    BinarySearchtree<int> b;
    std::shared_ptr<BinarySearchtree<int>> root; 

    root = b.BST_Insert(root, 50);
    b.BST_Insert(root, 30);
    b.BST_Insert(root, 20);
    b.BST_Insert(root, 40);
    b.BST_Insert(root, 70);
    b.BST_Insert(root, 60);
    b.BST_Insert(root, 80);

    b.Inorder(root);
    auto keyChild = b.BSt_Search(root,70);
    if (keyChild->getData() == 70)
    {
        std::cout << "key: " << keyChild->getData()  << " found." << std::endl;
    }
    else
        std::cout << "key: " << keyChild->getData() << " not found." << std::endl;

    return 0;
}
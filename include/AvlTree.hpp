#pragma once

#include "Node.hpp"

template <typename DataType>
class AvlTree
{
public:
    using NodeType = Node<DataType>;
    using CallBackFunc = void (*)(const DataType&);
public:
    ~AvlTree()
    {   
        free(this->_root);
    }

    void add(const DataType& data)
    {
        NodeType* node = new NodeType(data);
        this->doAdd(this->_root, node);
        this->doBalance(this->_root);
    }

    void innerOrderTraverse(CallBackFunc cb)
    {
        doInnerOrderTraverse(this->_root, cb);
    }

    void preOrderTraverse(CallBackFunc cb)
    {
        doPreOrderTraverse(this->_root, cb);
    }

    void postOrderTraverse(CallBackFunc cb)
    {
        doPostOrderTraverse(this->_root, cb);
    }

    const int height()
    {
        return height(this->_root);
    }

    const int leftHeight()
    {
        if(!this->_root)
        {
            return 0;
        }

        return height(this->_root->left());
    }

    const int rightHeight()
    {
        if(!this->_root)
        {
            return 0;
        }

        return height(this->_root->right());
    }

protected:
    void doAdd(NodeType* &root, NodeType* node)
    {
        if (!root)
        {
            root = node;
            return;
        }

        if (root->data() > node->data())
        {
            doAdd(root->left(), node);
        }
        else
        {
            doAdd(root->right(), node);
        }
    }

    void doBalance(NodeType* &root)
    {
        if (!root)
        {
            return;
        }
        
        NodeType* &leftRoot = this->_root->left();
        NodeType* &rightRoot = this->_root->right();

        int leftHeight = height(leftRoot);
        int rightHeight = height(rightRoot);

        if(leftHeight > (rightHeight + 1))
        {
            if (height(leftRoot->right()) > height(leftRoot->left()))
            {
                this->doLeftRotate(leftRoot);
            }
            
            this->doRightRotate(this->_root);

            return;
        }

        if (rightHeight > (leftHeight + 1))
        {
            if (height(rightRoot->left()) > height(rightRoot->right()))
            {
                this->doRightRotate(rightRoot);
            }

            this->doLeftRotate(this->_root);

            return;
        }
    }

    void doRightRotate(NodeType* &root)
    {
        NodeType *oldRoot = root;
        root = oldRoot->left();
        oldRoot->left() = root->right();
        root->right() = oldRoot;
    }

    void doLeftRotate(NodeType* &root)
    {
         NodeType *oldRoot = root;
         root = oldRoot->right();
         oldRoot->right() = root->left();
         root->left() = oldRoot;
    }

    void doInnerOrderTraverse(const NodeType* root, CallBackFunc cb)
    {
        if (!root)
        {
            return;
        }

        doInnerOrderTraverse(root->left(), cb);
        cb(root->data());
        doInnerOrderTraverse(root->right(), cb);
    }

    void doPreOrderTraverse(const NodeType* root, CallBackFunc cb)
    {
        if (!root)
        {
            return;
        }

        cb(root->data());
        doPreOrderTraverse(root->left(), cb);
        doPreOrderTraverse(root->right(), cb);
    }

    void doPostOrderTraverse(const NodeType* root, CallBackFunc cb)
    {
        if (!root)
        {
            return;
        }

        doPostOrderTraverse(root->left(), cb);
        doPostOrderTraverse(root->right(), cb);
        cb(root->data());
    }

    int height(const NodeType* root)
    {
        if (!root)
        {
            return 0;
        }
        
        int lh{0}, rh{0};
        lh = height(root->left());
        rh = height(root->right());
        
        return ((lh > rh ? lh : rh) + 1);
    }

    void free(NodeType* &root)
    {
        if (!root)
        {
            return;
        }
        
        free(root->left());
        free(root->right());
        delete root;
        root = nullptr;
    }
    
private:
    NodeType* _root{nullptr};
};

#pragma once

template <typename DataType>
class Node
{
public:
    Node(const DataType& v)
    {
        this->_data = v;
    }

    const Node<DataType>* left() const
    {
        return _left;
    }

    Node<DataType>* &left()
    {
        return _left;
    }

    const Node<DataType>* right() const
    {
        return _right;
    }

    Node<DataType>* &right()
    {
        return _right;
    }

    const DataType& data() const
    {
        return _data;
    }

    DataType& data()
    {
        return _data;
    }

private:
    DataType _data;
    Node<DataType>* _left{nullptr};
    Node<DataType>* _right{nullptr};
};
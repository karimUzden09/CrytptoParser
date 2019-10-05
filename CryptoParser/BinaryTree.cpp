#include "BinaryTree.hpp"
#include<iostream>
void Tree::add(std::string data, Brunch*&  Brunch_ptr)
{
	//Если  веток не существует
	if (!Brunch_ptr)
	{// Создадим ее и задаим в нее данные
		Brunch_ptr = new Brunch;
		Brunch_ptr->data.push_back(data);
		Brunch_ptr->leftBrunch = nullptr;
		Brunch_ptr->rightBrunch = nullptr;
		return;
	}
	if (Brunch_ptr->data.size() == 0)
	{
		add(data, Brunch_ptr->leftBrunch);
	}
	else
	{
		add(data, Brunch_ptr->rightBrunch);
	}
}
size_t tabs = 0;
void Tree::print(Brunch* Brunch_ptr)
{
	if (!Brunch_ptr)
	{
		//std::cout << "Tree is nullptr" << std::endl;
		return;
	}
	tabs++;
	print(Brunch_ptr->leftBrunch);
	for (size_t i = 0; i < tabs; i++) std::cout << " ";
	for (auto var : Brunch_ptr->data)
	{
		std::cout << var << std::endl;
	}
	
	print(Brunch_ptr->rightBrunch);
	tabs--;
	return;
}

void Tree::FreeTree(Brunch* Brunch_ptr)
{
	if (!Brunch_ptr)
	{
	//	std::cout << "Error free Tree nullptr" << std::endl;
		return;
	}
	FreeTree(Brunch_ptr->leftBrunch);
	FreeTree(Brunch_ptr->rightBrunch);
	delete Brunch_ptr;
	return;
}

//TreeV2::btree::btree()
//{
//	root = nullptr;
//}
//
//TreeV2::btree::~btree()
//{
//	destroy_tree();
//}
//
//void TreeV2::btree::insert(std::string data)
//{
//	
//}
//
//void TreeV2::btree::destroy_tree(Node* leaf)
//{
//	if (leaf!=nullptr)
//	{
//		destroy_tree(leaf->LeftNode);
//		destroy_tree(leaf->RightNode);
//		delete leaf;
//	}
//}
//
//void TreeV2::btree::insert(std::string key, Node* leaf)
//{
//	if (leaf->data.empty())
//	{
//		if (leaf->LeftNode!=nullptr)
//		{
//			insert(key, leaf->LeftNode);
//		}
//		else
//		{
//			leaf->LeftNode = new Node;
//			leaf->LeftNode->data.push_back("null");
//			leaf->LeftNode->LeftNode = nullptr;
//			leaf->LeftNode->RightNode = nullptr;
//		}
//	}
//	else if (!leaf->data.empty())
//	{
//		if (leaf->RightNode!=nullptr)
//		{
//			insert(key, leaf->RightNode);
//		}
//		else
//		{
//			leaf->RightNode = new Node;
//			leaf->RightNode->data.push_back(key);
//			leaf->RightNode->RightNode = nullptr;
//			leaf->RightNode->LeftNode = nullptr;
//		}
//	}
//}

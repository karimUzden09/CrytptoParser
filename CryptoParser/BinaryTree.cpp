// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com
#include "BinaryTree.hpp"
#include<iostream>
void Tree::add(const std::string& data, Brunch*&  Brunch_ptr)
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


TreeV2::Btree::Btree()
{
	root = nullptr;
}

void TreeV2::Btree::freeTree()
{

	destroi_tree(root);
}

void TreeV2::Btree::add_data(const std::string& data)
{
	add(data, root);
}

void TreeV2::Btree::print_tree()
{
	print_tree(root);
}

TreeV2::Btree::~Btree()
{
	destroi_tree(root);
}

void TreeV2::Btree::destroi_tree(Brunch* leaf)
{
	if (leaf != nullptr)
	{
		destroi_tree(leaf->leftBrunch);
		destroi_tree(leaf->rightBrunch);
		delete leaf;
	}
}

void TreeV2::Btree::add(const std::string& data, Brunch*& Brunch_ptr)
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

void TreeV2::Btree::print_tree(Brunch* Brunch_ptr)
{
	if (!Brunch_ptr)
	{
		//std::cout << "Tree is nullptr" << std::endl;
		return;
	}
	tabs++;
	print_tree(Brunch_ptr->leftBrunch);
	for (size_t i = 0; i < tabs; i++) std::cout << " ";
	for (auto var : Brunch_ptr->data)
	{
		std::cout << var << std::endl;
	}

	print_tree(Brunch_ptr->rightBrunch);
	tabs--;
	return;
}
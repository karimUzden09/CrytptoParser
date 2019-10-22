#include "BinaryTree.hpp"
#include<iostream>
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

void TreeV2::Btree::print_tree() noexcept
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

	if (!Brunch_ptr)
	{
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

void TreeV2::Btree::print_tree(Brunch* Brunch_ptr) noexcept
{
	if (!Brunch_ptr)
	{
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
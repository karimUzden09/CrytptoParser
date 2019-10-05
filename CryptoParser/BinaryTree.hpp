#pragma once
#include<string>
#include<vector>
namespace Tree {
	struct Brunch
	{
		std::vector<std::string> data;
		Brunch* leftBrunch;
		Brunch* rightBrunch;
	};

	void add(std::string data, Brunch*& Brunch_ptr);
	void print(Brunch* Brunch_ptr);
	void FreeTree(Brunch* Brunch_ptr);
}

//namespace TreeV2
//{
//	struct Node
//	{
//		std::vector<std::string> data;
//		Node* LeftNode;
//		Node* RightNode;
//	};
//
//	class btree
//	{
//	public:
//		btree();
//		~btree();
//
//		void insert(std::string data);
//		Node* search(std::string key);
//		void destroy_tree();
//		void inorder_print();
//		void postorder_print();
//		void preorder_print();
//	private:
//		void destroy_tree(Node* leaf);
//		void insert(std::string key, Node* leaf);
//		Node* search(std::string key, Node* leaf);
//		void inorder_print(Node* leaf);
//		void postorder_print(Node* leaf);
//		void preorder_print(Node* leaf);
//
//		Node* root;
//	};
//}
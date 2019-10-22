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

	void add(const std::string& data, Brunch*& Brunch_ptr);
	void print(Brunch* Brunch_ptr);
	void FreeTree(Brunch* Brunch_ptr);

	

}

namespace TreeV2
{
	struct Brunch
	{
		std::vector<std::string> data;
		Brunch* leftBrunch;
		Brunch* rightBrunch;
	};
	class Btree
	{
	public:
		Btree();
		void freeTree();
		void add_data(const std::string& data);
		void print_tree();
		~Btree();

	private:
		Brunch* root;
		void destroi_tree(Brunch* leaf);
		void add(const std::string& data, Brunch*& Brunch_ptr);
		void print_tree(Brunch* Brunch_ptr);
	};
	
}
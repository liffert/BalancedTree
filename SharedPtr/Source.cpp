#include <iostream>
#include <memory>
template <typename type>
class Tree {
private:
	struct El {
		type data;
		std::shared_ptr<El> left = nullptr;
		std::shared_ptr<El> right = nullptr;
		El(type data) noexcept : data(data) {};
	};
	using element = struct El;
	std::shared_ptr<element> head = nullptr;

	void add(type data, std::shared_ptr<element>& ptr) {
		if (ptr == nullptr) {
			ptr = std::make_shared<element>(element(data));
		}
		else if (data > ptr->data) {
			this->add(data, ptr->right);
		}
		else if (data < ptr->data) {
			this->add(data, ptr->left);
		}
		else {
			ptr->data = data;
		}
	}
	std::shared_ptr<element> find(type key, std::shared_ptr<element> ptr) {

		if (ptr == nullptr) {
			return nullptr;
		}
		if (ptr->data == key) {
			return ptr;
		}
		else if (ptr->data < key) {
			return find(key, ptr->right);
		}
		else {
			return find(key, ptr->left);
		}
	}
	void print(std::shared_ptr<element> ptr, std::string sep) {
		if (ptr != nullptr) {
			std::cout << sep << ptr->data << std::endl;
			print(ptr->left, sep + "--");
			print(ptr->right, sep + "--");
		}
		else {
			std::cout << sep << "Nullptr" << std::endl;
		}
	}

public:
	Tree() noexcept {}
	Tree(type data) {
		add(data);
	}
	void add(type data) {
		add(data, head);
	}
	std::shared_ptr<element> find(type key) {
		return find(key, head);
	}
	void print() {
		print(head, "");
	}
	void print(std::shared_ptr<element> tree) {
		print(tree, "");
	}
};


int main() {
	Tree<int> temp;
	temp.add(10);
	temp.add(12);
	temp.add(9);
	temp.add(7);
	temp.add(15);
	temp.add(2);
	temp.print(temp.find(15));

	temp.print();
}
#include <iostream>

template <typename type>
class Tree {
private:
	struct El {
		type data;
		El* left = nullptr;
		El* right = nullptr;
		El(type data) noexcept : data(data) {};
	};
	using element = struct El;
	element* head = nullptr;

	void add(type data, element*& ptr) {
		if (ptr == nullptr) {
			ptr = new element(data);
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
	element* find(type key, element* ptr) {

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
	void print(element* ptr, std::string sep) {
		if (ptr != nullptr) {
			std::cout << sep << ptr->data << std::endl;
			print(ptr->left, sep + "--");
			print(ptr->right, sep + "--");
		}
		else {
			std::cout << sep << "Nullptr" << std::endl;
		}
	}

	void del(element *&ptr) noexcept {
		if (ptr != nullptr) {
			del(ptr->left);
			del(ptr->right);
			std::cout << ptr->data << std::endl;
			delete ptr;
		}
	}

public:
	Tree() noexcept {}
	~Tree() {
		del(head);
	}
	void add(type data) {
		add(data, head);
	}
	element* find(type key) {
		return find(key, head);
	}
	void print() {
		print(head, "");
	}
	void print(element* ptr) {
		print(ptr, "");
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
	temp.print(temp.find(23));

	//temp.print();
}
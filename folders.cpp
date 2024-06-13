#include <string>
#include <iostream>
#include "Array.h"

struct File {
	std::string name;
	std::string content;
};

struct Folder {
	std::string name;
	Array<Folder> folders;
	Array<File> files;
};

void print(
	const Folder& folder, 
	int max_depth = 100,
	int depth = 0
) {
	std::cout << std::string(depth * 2, ' ')
		<< folder.name << '\n';
	for (size_t i = 0; i < folder.files.size(); i++) {
		std::cout << std::string(depth * 2 + 2, ' ')
			<< folder.files[i].name << '\n';
	}

	depth++;

	if (depth >= max_depth) {
		return;
	}

	for (size_t i = 0; i < folder.folders.size(); i++) {
		print(folder.folders[i], max_depth, depth);
	}
}

struct Node {
	int value;
	Node* next_node;
};

int main() {
	Folder root {
		"root",
		{}, {}
	};

	root.files.append({
		"fileroot.1",
		"contentroot.1",
	});

	root.folders.append({
		"folder1",
		{}, {}
	});

	root.folders[0].files.append({
		"file1.1",
		"content1.1"
	});

	root.folders.append({
		"folder2",
		{}, {}
	});

	root.folders[1].files.append({
		"file2.1",
		"content2.1"
	});

	root.folders[1].files.append({
		"file2.2",
		"content2.2"
	});

	root.folders[1].folders.append({
		"folder3",
		{}, {}
	});

	root.folders[1].folders[0].files.append({
		"file2_1.1",
		"content2_1.1"
	});

	print(root);

	return 0;
}

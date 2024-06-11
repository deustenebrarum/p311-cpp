#include <string>
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

int main() {
	Folder root {
		"root",
		{}, {}
	};

	append(root.folders, {
		"folder1",
		{}, {}
	});

	append(get(root.folders, 1).files, {
		"file1.1",
		"content1.1"
	});

	append(root.folders, {
		"folder2",
		{}, {}
	});

	append(root.files, {
		"fileroot.1",
		"contentroot.1"
	});

	return 0;
}

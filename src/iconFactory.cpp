




// TODO implementation



#include "iconFactory.h"



Icon IconFactory::createRedIcon() {
    return createRedIcon(1, 1);
}
Icon IconFactory::createRedIcon(int width, int height) {
	Icon icon;


	for (int i = 0; i < height; ++i) {
		std::vector<Cell> row;
		for (int j = 0; j < width; ++j) {
			row.emplace_back(Color::RED, "SK");
		}
		icon.push_back(row);
	}
	return icon;
}


Icon IconFactory::createCyanIcon() {
    return createRedIcon(1, 1);
}
Icon IconFactory::createCyanIcon(int width, int height) {
	Icon icon;
	for (int i = 0; i < height; ++i) {
		std::vector<Cell> row;
		for (int j = 0; j < width; ++j) {
			row.emplace_back(Color::CYAN, "FD");
		}
		icon.push_back(row);
	}
	return icon;
}

Icon IconFactory::createGreenIcon() {
    return createRedIcon(1, 1);
}
Icon IconFactory::createGreenIcon(int width, int height) {
	Icon icon;
	for (int i = 0; i < height; ++i) {
		std::vector<Cell> row;
		for (int j = 0; j < width; ++j) {
			row.emplace_back(Color::GREEN, "OS");
		}
		icon.push_back(row);
	}
	return icon;
}

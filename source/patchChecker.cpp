#include "pch.h"
#include "patchChecker.h"


patchChecker::patchChecker()
{
}


patchChecker::~patchChecker()
{
}

bool patchChecker::encountersCheck(std::string path)
{
	initialise();
	maxByte = 32;
	file.open(path, std::ios::in | std::ios::out | std::ios::binary);
	while (!file.bad()) {
		file.read(reinterpret_cast<char*>(&buffer), sizeof(buffer));
		byte += 1;
		if (byte == maxByte) {
			int val = (int)buffer;
			if (val == 01) {
				found = true;
			}
			else {
				writeByte(1);
			}
			break;
		}
	}
	file.close();
	return found;
}

bool patchChecker::expgoldCheck(std::string path)
{
	initialise();
	maxByte = 33;
	file.open(path, std::ios::in | std::ios::out | std::ios::binary);
	while (!file.bad()) {
		file.read(reinterpret_cast<char*>(&buffer), sizeof(buffer));
		byte += 1;
		if (byte == maxByte) {
			int val = (int)buffer;
			if (val == 01) {
				found = true;
			}
			else {
				writeByte(1);
			}
			break;
		}
	}
	file.close();
	return found;
}

bool patchChecker::fastTextCheck(std::string path, std::string version)
{
	initialise();
	maxByte = 34;
	file.open(path, std::ios::in | std::ios::out | std::ios::binary);
	while (!file.bad()) {
		file.read(reinterpret_cast<char*>(&buffer), sizeof(buffer));
		byte += 1;
		if (byte == maxByte) {
			int val = (int)buffer;
			if (version == "new") {
				if (val == 01) {
					found = true;
				}
				else {
					writeByte(1);
				}
			}
			else if (version == "old") {
				if (val == 02) {
					found = true;
				}
				else {
					writeByte(2);
				}
			}
			break;
		}
	}
	file.close();
	return found;
}

bool patchChecker::itemsCheck(std::string path, std::string version)
{
	initialise();
	maxByte = 35;
	file.open(path, std::ios::in | std::ios::out | std::ios::binary);
	while (!file.bad()) {
		file.read(reinterpret_cast<char*>(&buffer), sizeof(buffer));
		byte += 1;
		if (byte == maxByte) {
			int val = (int)buffer;
			if (version == "itemsscript") {
				if (val == 01) {
					found = true;
				}
				else {
					writeByte(1);
				}
			}
			else if (version == "itemsspells") {
				if (val == 02) {
					found = true;
				}
				else {
					writeByte(2);
				}
			}
			break;
		}
	}
	file.close();
	return found;
}

bool patchChecker::monstersCheck(std::string path)
{
	initialise();
	maxByte = 36;
	file.open(path, std::ios::in | std::ios::out | std::ios::binary);
	while (!file.bad()) {
		file.read(reinterpret_cast<char*>(&buffer), sizeof(buffer));
		byte += 1;
		if (byte == maxByte) {
			int val = (int)buffer;
			if (val == 01) {
				found = true;
			}
			else {
				writeByte(1);
			}
			break;
		}
	}
	file.close();
	return found;
}

bool patchChecker::scriptCheck(std::string path)
{
	initialise();
	maxByte = 37;
	file.open(path, std::ios::in | std::ios::out | std::ios::binary);
	while (!file.bad()) {
		file.read(reinterpret_cast<char*>(&buffer), sizeof(buffer));
		byte += 1;
		if (byte == maxByte) {
			int val = (int)buffer;
			if (val == 01) {
				found = true;
			}
			else {
				writeByte(1);
			}
			break;
		}
	}
	file.close();
	return found;
}

bool patchChecker::statsCheck(std::string path)
{
	initialise();
	maxByte = 38;
	file.open(path, std::ios::in | std::ios::out | std::ios::binary);
	while (!file.bad()) {
		file.read(reinterpret_cast<char*>(&buffer), sizeof(buffer));
		byte += 1;
		if (byte == maxByte) {
			int val = (int)buffer;
			if (val == 01) {
				found = true;
			}
			else {
				writeByte(1);
			}
			break;
		}
	}
	file.close();
	return found;
}

bool patchChecker::arenaCheck(std::string path)
{
	initialise();
	maxByte = 39;
	file.open(path, std::ios::in | std::ios::out | std::ios::binary);
	while (!file.bad()) {
		file.read(reinterpret_cast<char*>(&buffer), sizeof(buffer));
		byte += 1;
		if (byte == maxByte) {
			int val = (int)buffer;
			if (val == 01) {
				found = true;
			}
			else {
				writeByte(1);
			}
			break;
		}
	}
	file.close();
	return found;
}

void patchChecker::writeByte(int num)
{
	uint64_t marker = 0;
	if (num == 1) {
		marker = 0x1;
	}
	else if (num == 2) {
		marker = 0x2;
	}
	file.seekp(maxByte, std::ios::beg);
	file.write(reinterpret_cast<char*>(&marker), sizeof(marker));
}

void patchChecker::initialise()
{
	found = false;
	buffer = 0;
	byte = -1;
}

void patchChecker::markVersion(std::string path)
{
	initialise();
	maxByte = 40;
	file.open(path, std::ios::in | std::ios::out | std::ios::binary);
	while (!file.bad()) {
		file.read(reinterpret_cast<char*>(&buffer), sizeof(buffer));
		byte += 1;
		if (byte == maxByte) {
			writeByte(3);
			break;
		}
	}
	file.close();
}

void patchChecker::markSubVersion(std::string path)
{
	initialise();
	maxByte = 41;
	file.open(path, std::ios::in | std::ios::out | std::ios::binary);
	while (!file.bad()) {
		file.read(reinterpret_cast<char*>(&buffer), sizeof(buffer));
		byte += 1;
		if (byte == maxByte) {
			writeByte(0);
			break;
		}
	}
	file.close();
}

bool patchChecker::scriptVerify(std::string path)
{
	initialise();
	maxByte = 37;
	file.open(path, std::ios::in | std::ios::out | std::ios::binary);
	while (!file.bad()) {
		file.read(reinterpret_cast<char*>(&buffer), sizeof(buffer));
		byte += 1;
		if (byte == maxByte) {
			int val = (int)buffer;
			if (val == 01) {
				found = true;
			}
			else {
				found = false;
			}
			break;
		}
	}
	file.close();
	return found;
}

bool patchChecker::undubCheck(std::string path) {
	initialise();
	maxByte = 56741;
	file.open(path, std::ios::in | std::ios::out | std::ios::binary);
	while (!file.bad()) {
		file.read(reinterpret_cast<char*>(&buffer), sizeof(buffer));
		byte += 1;
		if (byte == maxByte) {
			int val = (int)buffer;
			if (val == 207) {
				found = true;
			}
			else {
				found = false;
			}
			break;
		}
	}
	file.close();
	return found;
}
#pragma once

class Info {
public:
	Info() : Info(1, 'a') {}
	Info(int i) : Info(i, 'a') {}
	Info(char e) : Info(1, e) {}

	/**
	 * Info() : Info(1) {}
	 * Info(int i) : Info(i, 'a') {}
	 * Info(char e) : Info(1, e) {}
	 */

private:
	Info(int i, char e) :type_(i), name_(e) {}
	int type_;
	char name_;
};
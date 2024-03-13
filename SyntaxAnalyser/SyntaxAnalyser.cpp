#include "pch.h"
#include "framework.h"
#include <string>

std::string program = "3 -- 4";

int i = 0; //string pos

bool type() {
	//
}

bool param() {
	if (i >= program.size()) {
		return true;
	}
	if (!type()) {
		return false;
	}
	//id
	if (!paramList()) {
		return false;
	}
	return true;
}

bool paramList() {
	if (i >= program.size()) {
		return true;
	}
	if (!type) {		
		return false;
	}
	//id
	if (!paramList()) {
		return false;
	}
	return true;
}

bool stmtList() {
	//
}

bool initVar() {
	if (i >= program.size()) {
		return true;
	}
	if (program[i] = '=') {
		//num or char
		return true;
	}
	return false;
}

bool declareVarList() {
	if (i >= program.size()) {
		return true;
	}
	if (program[i] == ',') {
		// id 
		if (!initVar()) {
			return false;
		}
		if (!declareVarList()) {
			return false;
		}
		return true;
	}	
}

bool declareStmtList() {
	if (program[i] == '(') {
		i += 1;
		if (!param()) {
			return false;
			
		}
		if (program[i] == ')') {
			i += 1;
		}

		if (program[i] == '{') {
			if (!stmtList()) {
				return false;
			}
			if (program[i] == '}') {
				return true;
			}
		}
	}
	else if (program[i] == '=') {
		//num
		if (!declareVarList()) {
			return true;
		}
	}
	else {
		if (!declareVarList()) { // !!!
			return true;
		}
	}
	return false;
}



bool declareStmt() {
	if (!type) {
		return false;
	}
	// id
	if (!declareStmtList()) {
		return false;
	}

}
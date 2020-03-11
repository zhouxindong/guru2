#pragma once

/**
 * 
 .rdbuf() -> 流所使用的streambuf
 << streambuf


 (argc > 2
	? ofstream(argv[2], ios::out | ios::binary)
	: cout
<<
 (argc > 1
	? ifstream(argv[1], ios::in | ios::binary)
	: cin)
	.rdbuf();
 */
/*
    This file is a part of KMC software distributed under GNU GPL 3 licence.
    The homepage of the KMC project is http://sun.aei.polsl.pl/kmc

    Authors: Sebastian Deorowicz, Agnieszka Debudaj-Grabysz, Marek Kokot

    Version: 2.2.0
    Date   : 2015-04-15
*/

#ifndef _MEM_DISK_FILE_H
#define _MEM_DISK_FILE_H

#include "../kmc/definitions.h"
#include <string>
#include <cstdio>
#include <vector>


//************************************************************************************************************
// CMemDiskFile - wrapper for FILE* or memory equivalent
//************************************************************************************************************
class CMemDiskFile {
	bool memory_mode;
	FILE* file;
	typedef std::pair<uchar*, uint64> elem_t;//buf,size
	typedef std::vector<elem_t> container_t;

	container_t container;
	std::string name;
  public:
	CMemDiskFile(bool _memory_mode);
	void Open(const std::string& f_name);
	void Rewind();
	int Close();
	size_t Read(uchar * ptr, size_t size, size_t count);
	size_t Write(const uchar * ptr, size_t size, size_t count);
	void Remove();
};

#endif


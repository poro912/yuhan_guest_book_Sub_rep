#include"GB_File_io.h"

bool file_save(vector <PINFO> &info_vector, const wchar_t *name)
{
	fstream fs;
	fs.open(name, ios::out | ios::trunc);
	if (fs.fail())	// 파일 열기에 실패한 경우
		return false;
	for (const auto& i : info_vector)
	{
		fs << i.lparm << " ";
		fs << i.cWidth << " ";
		fs << i.color << " ";
		fs << i.ctime << " ";
		fs << i.state << endl;
	}
	fs.close();
	return true;
}


bool file_load(vector <PINFO> & info_vector, const wchar_t *name)
{
	fstream fs;
	fs.open(name, ios::in);
	if (fs.fail())	// 파일열기에 실패한 경우
		return false;
	while (!fs.eof())
	{
		PINFO temp;
		fs >> temp.lparm;
		fs >> temp.cWidth;
		fs >> temp.color;
		fs >> temp.ctime;
		fs >> temp.state;
		info_vector.push_back(temp);
	}
	return true;
}

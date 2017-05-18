/**
 * This program will do a word, byte, and char count of STDIN or a file
 * @authors Stone Daniel & Jean Bae
 */
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cerrno>
#include <unistd.h>
#include <fcntl.h>
#include <cctype>
#include <wchar.h>
#include <string>
#include <sys/types.h>
#include <sys/stat.h>
using std::cout;
using std:: endl;
using std::isspace;
using std::string;

int main(const int argc, const char * argv []){

	int n{0};
	const int BUFF_SIZE{1};
	char buffer[BUFF_SIZE];
	wchar_t wc;
	mbstate_t ss;
	int fd;
	int charCount = 0;
	int wordCount = 0;
	int newLine=0;
	int bytes = 0;
	int fileCount = 0;
	int totalNewLine =0;
	int totalBytes = 0;
	int totalChars = 0;
	int totalWordCount = 0;
	string s = "";
	bool c=false,l=false,m=false,w=false, stdInput=false;
	struct stat st;

	//if argv[1] is NULL then read from STDIN
	if(argv[1] == NULL){
		newLine = 0;
		wordCount = 0;
		bytes = 0;
		charCount = 0;
		(fstat(fd,&st));
		while((n = read(STDIN_FILENO,buffer,BUFF_SIZE)) > 0)
		{
			mbrlen ( NULL, 0, &ss );
			s.append(buffer,1);
			if(*buffer == '\n')
				newLine++;
			totalNewLine+=newLine;
			//cout << st.st_size << endl;
			bytes+= mbrtowc(&wc,buffer,1,&ss);

			charCount++;

		}
		totalBytes += bytes;
		totalChars+= charCount;
		for(int i = 0;i<bytes-1;i++)
		{
			if(!(isspace(s.at(i))) && isspace(s.at(i+1)))
				wordCount++;

		}
		totalWordCount += wordCount;
		cout << "new lines: "<< newLine << " word count: " << wordCount << " bytes: " << bytes << endl;

	}
	else
	{
		//if it's not NULL, check options
		for(int i = 1;i<argc;i++)
		{
			string temp = argv[i];
			if(temp == "-c")
			{
				c = true;
			}
			else if(temp == "-l")
			{
				l = true;
			}
			else if(temp == "-m")
			{
				m = true;
			}
			else if(temp == "-w")
			{
				w = true;
			}
			else if(temp == "-cm" || temp == "-mc")
			{
				c = true;
				m = true;
			}
			else if(temp == "-lw" || temp == "-wl")
			{
				l = true;
				w = true;
			}
			else if(temp == "-")
			{
				stdInput = true;
			}
			else 
			{
				newLine = 0;
				bytes = 0;
				charCount = 0;
				wordCount = 0;
				fd = open(argv[i],O_RDONLY);
				int read1;
				fstat(fd,&st);
				bytes = st.st_size;
				totalBytes+=bytes;
				mbrlen ( NULL, 0, &ss );
				s.clear();

				while((read1 = read(fd,buffer,1)) > 0)
				{
					s.append(buffer,1);
					if(*buffer == '\n')
						newLine++;
					//bytes+= mbrtowc(&wc,buffer,1,&ss);
					charCount++;
				}
				totalNewLine+=newLine;
				totalChars+=charCount;
				
				char prevChar = '\0';
				for(int i = 0;i<charCount;i++)
				{	
					if (!isspace(prevChar) && isspace(s.at(i)))
						wordCount++;
					prevChar = s.at(i);
					// if (i == 0 && !isspace(s.at(0)))
					// 	wordCount++;
					// else if(isspace(s.at(i)) && !isspace(s.at(i+1)))
					//	wordCount++;

				}
				prevChar = '\0';
				cout << "new lines: "<< newLine << " word count: " << wordCount << " bytes: " << bytes << endl;

				totalWordCount+=wordCount;

				fileCount++;



			}

		}
		if(fd == 0 || stdInput == true)
		{
			newLine = 0;
			bytes = 0;
			charCount = 0;
			wordCount = 0;

			mbrlen ( NULL, 0, &ss );
			while((n = read(STDIN_FILENO,buffer,BUFF_SIZE)) > 0)
			{
				s.append(buffer,1);
				if(*buffer == '\n')
					newLine++;

				bytes+= mbrtowc(&wc,buffer,1,&ss);

				charCount++;
			}
			totalBytes += bytes;
			totalNewLine+=newLine;
			totalChars+=charCount;

			for(int i = 0;i<bytes-1;i++)
			{
				if(!(isspace(s.at(i))) && isspace(s.at(i+1)))
					wordCount++;
			}
			totalWordCount+=wordCount;
			fileCount++;
			cout << "new lines: "<< newLine << " word count: " << wordCount << " bytes: " << bytes << endl;

		}
	}

	//cout << s<< endl;
	if(c)
		cout << "Bytes:" << bytes << endl;
	if(l)
		cout << "Lines:" << newLine << endl;
	if(m)
		cout << "Chars:" <<  bytes << endl;//Charcount
	if(w)
		cout << "Word Count:" << wordCount << endl;
	//if(!c && !m && !l && !w)
	//	  cout << "new lines: "<< newLine << " word count: " << wordCount << " bytes: " << bytes << endl;
	if(fileCount > 1)
		cout << "total new lines: " << totalNewLine << " total word count: " << totalWordCount << " total bytes: " << totalBytes << endl;
	return EXIT_SUCCESS;

}  

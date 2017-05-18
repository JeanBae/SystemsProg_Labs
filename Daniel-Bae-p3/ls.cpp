/**
 * This program does a list of files, if -a is specified, it includes files with a dot
 * @authors Stone Daniel & Jean Bae
 *
 * Sorting code from Coterrell's code in class.*/
#include <cstdlib>
#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <cstring>
#include <string>
#include <string.h>
#include <list>
#include <fcntl.h>
#include <grp.h>
#include <pwd.h>
using namespace std;
bool direnticmp(struct dirent * a, struct dirent * b)
{
  return strcasecmp(a->d_name, b->d_name) < 0;
}
int listContents(char * c,bool all,bool lon)
{
  DIR *dir;
  struct dirent *entry;
  dir = opendir(c);//Check opendir for errors for a bad file/path name 
  //char buf[512];
  bool a = all;
  list<struct dirent *> entries;
  int blocks = 0;
  //vector<string> vector1;
  while((entry = readdir(dir)) != nullptr)
    {
      entries.push_back(entry);
      //vector1.push_back((string)entry->d_name);
    }
  entries.sort(direnticmp);
  if(!lon)
    {
      for(auto x : entries)
	{
	  string temp = x->d_name;//entry->d_name;
	  if(temp[0] != '.' || a == true)
	    cout << x->d_name << "  ";
	}
      cout << endl;
    }
  else
    {
      for(auto y : entries)
	{
	  struct stat blocks1;//
	  string tem1 = c;
	  tem1.append("/");
	  tem1.append(y->d_name);
	  if(y->d_name[0] != '.' || a) 
	    {
	      if(stat(tem1.c_str(),&blocks1) == -1)
		{	     
		 perror("Stat Error");
		 exit(EXIT_FAILURE);
		}
	      blocks+= blocks1.st_blocks;
	    }
	}
      blocks/=2;
      cout << "Total:" << blocks << endl;
      for(auto x : entries)
	{
	  struct stat results;
	  struct passwd * pw;
	  struct group *grp;
	  //cout << x->d_name << endl;
	  //cout << strlen(x->d_name) << endl;
	  //int fd = open(x->d_name,&results);
	  string tem = c;
	  tem.append("/");
	  tem.append(x->d_name);
	  if(x->d_name[0] != '.' || a) 
	    {
	      if(stat(tem.c_str(),&results) == -1)
		{	     
		  perror("Stat Error");
		  exit(EXIT_FAILURE);
		}	   
	      pw = getpwuid(results.st_uid);
	      grp = getgrgid(results.st_gid);
	      printf("%s",(S_ISDIR(results.st_mode)) ? "d" : "-");
	      printf("%s",(results.st_mode & S_IRUSR) != 0 ? "r" : "-");//1
	      printf("%s",(results.st_mode & S_IWUSR) != 0 ? "w" : "-");
	      if((results.st_mode & S_ISUID) != 0)
		printf("s");
	      else if((results.st_mode & S_ISUID) != 0 && (results.st_mode & S_IXUSR) != 0)
		printf("S");
	      else 
	       printf("%s",(results.st_mode & S_IXUSR) != 0 ? "x" : "-");
	      //printf("%s",results.st_mode & S_ISUID != 0 ? "S" : "-");//3
	     
	      printf("%s",(results.st_mode & S_IRGRP) != 0 ? "r" : "-");//4
	      printf("%s",(results.st_mode & S_IWGRP) != 0 ? "w" : "-");
	      if((results.st_mode & S_ISGID) != 0)
		printf("s");
	      else if((results.st_mode & S_ISGID) != 0 && (results.st_mode & S_IXGRP) != 0)
		printf("S");
	      else
		printf("%s",(results.st_mode & S_IXGRP) != 0 ? "x" : "-");
	      
	      printf("%s",(results.st_mode & S_IROTH) != 0 ? "r" : "-");//7
	      printf("%s",(results.st_mode & S_IWOTH) != 0 ? "w" : "-");
	      if((results.st_mode & S_ISVTX) != 0)
		printf("t");
	      else if((results.st_mode & S_ISVTX)!= 0 && (results.st_mode & S_IXOTH) != 0)
		printf("T");
	      else
		printf("%s",(results.st_mode & S_IXOTH) != 0 ? "x" : "-");
	      //printf(") ");	      
	      cout << "\t" << results.st_nlink;
	      cout << "\t" <<  pw->pw_name;
	      cout << "\t" << grp->gr_name;
	      cout << "\t" << results.st_size;
	      string s = ctime(&results.st_atime);
	      s.erase(s.size()-5,5);
	      s.erase(0,3);
	      cout << s;
	      //printf("%s ",ctime(&results.st_atime));
	      cout << "\t" << x->d_name << endl;
	      //cout  << sb.st_size << endl;
	    }
	}
      closedir(dir);
    }
  return 0;
}

int main(int argc, char * argv[])
{
  bool a = false,l=false;
  char pwd[1024];
  if(getcwd(pwd,sizeof(pwd)) == 0)
    perror("How did you mess this up?");  
  char temp[1024];
  bool used = false;
  
  if(argc==1)
    {
      strcpy(temp,pwd);
      listContents(pwd,false,false);
      used = true;
    }
  else
    {
      for(int i = 1;i<argc;i++)
	{
	  if((string)argv[i] == "-a")
	    {
	      a = true;
	    }
	  else if((string)argv[i] == "-l")
	    {
	      l = true;
	    }
	  else if((string)argv[i] == "-la" || (string)argv[i] == "-al")
	    {
	      a = true;
	      l = true;
	    }
	  else
	    {
	      //strcpy(temp,argv[i]);
	      used = true;
	      listContents(argv[i],a,l);
	    }
	  
	}//For
      if(!used)
	{
	  strcpy(temp,pwd);
	  listContents(pwd,a,l);
	}
    }
  return 0;
}

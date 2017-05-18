#include <cstdlib>
#include <cerrno>
#include <unistd.h>
#include <iostream>
#include <ctime>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <pwd.h>
#include <grp.h>

using std::cout;
using std::endl;
using std::hex;
using std::dec;
using std::string;

string s;
struct stat sb;
struct passwd *pwd;
struct group * grp;
bool bc = false;

int main(int argc, char *argv[])
{

  int i = 0;
  if(argc > 1){
    i = 1;
    while(argv[i]!=NULL){

      if((*argv[i]) == '-'){
      fstat(0, &sb);
    }
      
      else if(stat(argv[i], &sb) > -1){
	lstat(argv[i], &sb);
      }

      cout << "  File: `" << argv[i] << "'";
      cout<< "\n";
      printf("  Size: %lld\t\t", (long long) sb.st_size);
      printf("Blocks:%lld\t   ", (long long) sb.st_blocks);
      printf("I/O Block: %ld   ", (long) sb.st_blksize);
      
      switch (sb.st_mode & S_IFMT) {
      case S_IFBLK:  
	printf("block device\n");            
	s = "b";
	bc = true;
	break;
      case S_IFCHR:  
	printf("character device\n");        
	s = "c";
	bc = true;
	break;
      case S_IFDIR:  
	printf("directory\n");               
	s = "d";
	break;
      case S_IFIFO:  
	printf("FIFO/pipe\n");               
	s = "p";
	break;
      case S_IFLNK:  
	printf("symbolic link\n");                 
	s = "l";
	break;
      case S_IFREG:  
	printf("regular file\n");            
	s = "-";
	break;
      case S_IFSOCK: 
	printf("socket\n");                  
	s = "s";
	break;
      default:       
	printf("unknown?\n");                
	break;
      }//end switch
      
      cout << "Device: " << hex << (long) sb.st_dev 
	   << "h/" << dec << (long) sb.st_dev<< "d\t";
      
      printf("Inode: %ld   ", (long) sb.st_ino);
      printf("Links: %ld\t", (long) sb.st_nlink);

      if(bc == true){
	cout << "Device type: " << hex << major (sb.st_rdev) 
	     << "," << hex << minor(sb.st_rdev);

      }
      
      int num = sb.st_mode;
      int octal = 0;
      int rem = 0;
      int j = 1;
      while(num!=0){
	rem = num % 8;
	num /= 8;
	octal += rem * j;
	j *= 10;
      }//end while(num!=0)
      
      octal = octal%10000;
      if(octal >= 7777){
	printf("\nAccess: (%ld/", (long) octal);
      }
      
      else{
        printf("\nAccess: (0%ld/", (long) octal);
      }
      
      cout<< s ;
      (sb.st_mode & S_IRUSR) ? printf("r") : printf("-");
      (sb.st_mode & S_IWUSR) ? printf("w") : printf("-");    
      if(sb.st_mode & S_IXUSR && sb.st_mode & S_ISUID){ 
	printf("s");
      }
      else if(sb.st_mode & S_ISUID){
	printf("S");
      }
      else if(sb.st_mode & S_IXUSR){
	printf("x");
      }
      else{
	printf("-");
      }
      
      (sb.st_mode & S_IRGRP) ? printf("r") : printf("-");
      (sb.st_mode & S_IWGRP) ? printf("w") : printf("-");
      if(sb.st_mode & S_IXGRP && sb.st_mode & S_ISGID){ 
	printf("s");
      }
      else if(sb.st_mode & S_ISGID){
	printf("S");
      }
      else if(sb.st_mode & S_IXGRP){
	printf("x");
      } 
      else{
	printf("-");
      }
      (sb.st_mode & S_IROTH) ? printf("r") : printf("-");
      (sb.st_mode & S_IWOTH) ? printf("w") : printf("-"); 
      if(sb.st_mode & S_IXOTH && sb.st_mode & S_ISVTX){ 
	printf("t");
      }
      else if(sb.st_mode & S_ISVTX){
	printf("T");
      }
      else if(sb.st_mode & S_IXOTH){
	printf("x");
      }
      else{
	printf("-");
      }
      printf(")");
      
      if((pwd = getpwuid(sb.st_uid)) != NULL){
	printf("  Uid: (%ld/    ",(long) sb.st_uid);
	cout << pwd->pw_name <<")   ";
      }
      
      if((grp = getgrgid(sb.st_gid)) != NULL){
	printf("Gid: (%ld/    ",(long) sb.st_gid);
	cout << grp->gr_name<< ")";
      }
      
      printf("\nAccess: %s", ctime(&sb.st_atime));
      printf("Modify: %s", ctime(&sb.st_mtime));
      printf("Change: %s", ctime(&sb.st_ctim.tv_sec));
      
      i++;      
    }//end while argv[i]!=NULL
  }//end if argc==1


  if(argc == 1){
   if(argv[1] == NULL){
      fstat(0, &sb);
            cout << "  File: `" << argv[1] << "'";
      cout<< "\n";
      printf("  Size: %lld\t\t", (long long) sb.st_size);
      printf("Blocks:%lld\t   ", (long long) sb.st_blocks);
      printf("I/O Block: %ld   ", (long) sb.st_blksize);
      
      switch (sb.st_mode & S_IFMT) {
      case S_IFBLK:  
	printf("block device\n");            
	s = "b";
	break;
      case S_IFCHR:  
	printf("character device\n");        
	s = "c";
	break;
      case S_IFDIR:  
	printf("directory\n");               
	s = "d";
	break;
      case S_IFIFO:  
	printf("FIFO/pipe\n");               
	s = "p";
	break;
      case S_IFLNK:  
	printf("symbolic link\n");                 
	s = "l";
	break;
      case S_IFREG:  
	printf("regular file\n");            
	s = "-";
	break;
      case S_IFSOCK: 
	printf("socket\n");                  
	s = "s";
	break;
      default:       
	printf("unknown?\n");                
	break;
      }//end switch
      
      cout << "Device: " << hex << (long) sb.st_dev 
	   << "h/" << dec << (long) sb.st_dev<< "d\t";
      
      printf("Inode: %ld   ", (long) sb.st_ino);
      printf("Links: %ld\n", (long) sb.st_nlink);
      
      int num = sb.st_mode;
      int octal = 0;
      int rem = 0;
      int j = 1;
      while(num!=0){
	rem = num % 8;
	num /= 8;
	octal += rem * j;
	j *= 10;
      }//end while(num!=0)
      
      octal = octal%10000;
      if(octal >= 7777){
	printf("Access: (%ld/", (long) octal);
      }
      
      else{
        printf("Access: (0%ld/", (long) octal);
      }
      
      cout<< s ;
      (sb.st_mode & S_IRUSR) ? printf("r") : printf("-");
      (sb.st_mode & S_IWUSR) ? printf("w") : printf("-");    
      if(sb.st_mode & S_IXUSR && sb.st_mode & S_ISUID){ 
	printf("s");
      }
      else if(sb.st_mode & S_ISUID){
	printf("S");
      }
      else if(sb.st_mode & S_IXUSR){
	printf("x");
      }
      else{
	printf("-");
      }
      
      (sb.st_mode & S_IRGRP) ? printf("r") : printf("-");
      (sb.st_mode & S_IWGRP) ? printf("w") : printf("-");
      if(sb.st_mode & S_IXGRP && sb.st_mode & S_ISGID){ 
	printf("s");
      }
      else if(sb.st_mode & S_ISGID){
	printf("S");
      }
      else if(sb.st_mode & S_IXGRP){
	printf("x");
      } 
      else{
	printf("-");
      }
      (sb.st_mode & S_IROTH) ? printf("r") : printf("-");
      (sb.st_mode & S_IWOTH) ? printf("w") : printf("-"); 
      if(sb.st_mode & S_IXOTH && sb.st_mode & S_ISVTX){ 
	printf("t");
      }
      else if(sb.st_mode & S_ISVTX){
	printf("T");
      }
      else if(sb.st_mode & S_IXOTH){
	printf("x");
      }
      else{
	printf("-");
      }
      printf(")");
      
      if((pwd = getpwuid(sb.st_uid)) != NULL){
	printf("  Uid: (%ld/    ",(long) sb.st_uid);
	cout << pwd->pw_name <<")   ";
      }
      
      if((grp = getgrgid(sb.st_gid)) != NULL){
	printf("Gid: (%ld/    ",(long) sb.st_gid);
	cout << grp->gr_name<< ")";
      }
      
      printf("\nAccess: %s", ctime(&sb.st_atime));
      printf("Modify: %s", ctime(&sb.st_mtime));
      printf("Change: %s", ctime(&sb.st_ctim.tv_sec));

   }//inner if
   

  }//if argc==1




}//end main

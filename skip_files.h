#include <dirent.h>
#include <fstream>

void skip_files()
{
  std::string src_dir("/home/alexaway/Desktop/data/");
  std::string des_dir("/home/alexaway/Desktop/dest/");
  int skip = 10;

  DIR *dpdf;
  struct dirent *epdf;
  int i = 0;
  dpdf = opendir(src_dir.c_str());
  if (dpdf != NULL){
    while (epdf = readdir(dpdf)){
      if(i++==0)continue;
      if(i %10 == 0){
        std::string in = src_dir + epdf->d_name;
        std::string out = des_dir + epdf->d_name;
        std::ifstream src(in);
        std::ofstream dest(out);
        dest << src.rdbuf();
      }
    }
  }
}
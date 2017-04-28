#include <dirent.h>
#include <fstream>
#include <iostream>
#include <experimental/filesystem>
namespace fs = std::experimental::filesystem;
using namespace std;
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

void copy(string from, string to)
{
  fs::path f(from);
  fs::path t(to);
  int count =0;
  for(auto &p : fs::directory_iterator(f)){
    if(count++ % 10 == 0){
      fs::copy_file(p, t / p.path().filename());
    }
  }
}
void copy_recursively_to_one_directory(string from,string to)
{
  fs::path f(from);
  fs::path t(to);
  for(auto &p : fs::recursive_directory_iterator(f)){
    if(fs::is_directory(p))continue;
    fs::copy_file(p, t / p.path().filename());
  }
}

void copy_recursively(string from, string to)
{
  fs::path f(from);
  fs::path t(to);
  fs::copy(f,t,fs::copy_options::recursive);
}

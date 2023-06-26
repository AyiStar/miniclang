#include <iostream>

int main(int argc, char **argv) {
  if (argc != 2) {
    std::cerr << argv[0] << ": invalid number of arguments" << std::endl;
    return 1;
  }
  
  std::cout << "define i32 @main(i32 %argc, i8** %argv) {" << std::endl;
  std::cout << "ret i32 " << std::stoi(argv[1]);
  std::cout << "}" << std::endl;

  return 0;
}
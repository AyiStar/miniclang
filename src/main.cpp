#include <sstream>
#include <iomanip>
#include <iostream>
#include <charconv>
#include <string_view>

int main(int argc, char **argv) {
  if (argc != 2) {
    std::cerr << argv[0] << ": invalid number of arguments" << std::endl;
    return 1;
  }

  std::string_view program(argv[1]);
  std::string_view valid_ops("+-");
  char last_op = '+';
  int operand;

  std::ostringstream code;
  size_t counter = 1;  // used for register 

  code << "define i32 @main(i32 %argc, i8** %argv) {\n";
  code << "%" << counter << " = xor i32 0, 0\n";
  while (!program.empty()) {
    // parse an integer
    auto [ptr, ec] = std::from_chars(program.begin(), program.end(), operand);
    if (ec == std::errc::invalid_argument) {
      std::cerr << "Syntax error: invalid number at " << program.at(0) << std::endl;
      return 1;
    }
    else if (ec == std::errc::result_out_of_range) {
      std::cerr << "Parse error: number is larger than an int";
    }
    // operator on integer
    switch (last_op) {
      case '+':
        code << "%" << (counter + 1) << " = add i32 %" << counter << ", " << operand << "\n";
        counter++;
        break;
      case '-':
        code << "%" << (counter + 1) << " = sub i32 %" << counter << ", " << operand << "\n";
        counter++;
        break;
    }
    // consume the next operator
    if (ptr != program.end()) {
      last_op = *ptr;
      if (valid_ops.find(last_op) == std::string_view::npos) {
        std::cerr << "Syntax error: invalid operator " << last_op << std::endl;
        return 1;
      }
      ptr++;
    }
    // proceed
    program = program.substr(std::distance(program.begin(), ptr));
  }
  code << "ret i32 %" << counter << "\n";
  code << "}\n";
  std::cout << code.str();

  return 0;
}
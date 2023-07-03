#ifndef MINICLANG_LEXER_H
#define MINICLANG_LEXER_H

#include <string_view>

#include "fmt/core.h"
#include "source_location.h"
#include "token.h"

namespace lex {

class InvalidTokenException {
public:
  InvalidTokenException(SourceLocation loc): loc_{loc} {}
  std::string_view what() {
    return fmt::format("", )
  }

private:
  SourceLocation loc_;
};

class Lexer {
public:
  Lexer(const char* buffer): buffer_{buffer}, cursor_{buffer}, curr_loc_{buffer_} {}
  Lexer(const Lexer&) = delete;
  Lexer& operator=(const Lexer&) = delete;

  const char* getBuffer() const;
  SourceLocation getSourceLocation() const;
  const char* getBufferLocation() const;

  /// Lex - Return the next token in the file by `result`.
  /// If this is the end of file, it returns false,
  /// and the kind of `result` will be kEOF.
  /// Will throw InvalidTokenException if parsing invalid token
  bool lex(Token& result) throw();


private:
  const char* const buffer_;
  const char* cursor_;
  SourceLocation curr_loc_;
};

}  // namespace lex

#endif // MINICLANG_LEXER_H

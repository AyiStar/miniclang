#include <cctype>
#include <cstdlib>

#include "lexer.h"

const char* Lexer::getBuffer() const { return buffer_; }

SourceLocation Lexer::getSourceLocation() const { return curr_loc_; }

const char* Lexer::getBufferLocation() const { return cursor_; }

bool Lexer::lex(Token& result) {
  const char* p =cursor_;
  while (*p) {
    // Skip whitespace
    if (std::isspace(*p)) {
      p++;
      continue;
    }

    // Numeric literals
    if (std::isdigit(*p)) {
      char* q = const_cast<char*>(p);  // this is a flaw in C's strtol
      int val = std::strtol(q, &q, 10);
      result = Token(TokenKind::kNum, p, q - p);
      cursor_ = q;
      return true;
    }

    // Punctuators
    if (*p == '+' || *p == '-') {
      result = Token(TokenKind::kPunct, p, 1);
      p++;
      cursor_ = p;
      return true;
    }

    return false;
  }

  cursor_ = p;
  result = Token(TokenKind::kEOF, p, 0);
  return false;
}
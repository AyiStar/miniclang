#ifndef MINICLANG_TOKEN_H
#define MINICLANT_TOKEN_H

#include "source_location.h"

enum class TokenKind {
  kPunct,  // Punctuators
  kNum,    // Numeric literals
  kEOF,    // EOF
};

class Token {
public:
  Token(TokenKind kind, SourceLocation start_loc, int length);

  SourceLocation getStart() const;
  SourceLocation getEnd() const;
  int getLength() const;
  TokenKind getKind() const;
  int getValue() const;
  void setValue(int val);
  
private:
  TokenKind kind_;
  SourceLocation start_;
  SourceLocation end_;
  int length_;  // token length

  int value_;  // hold the value if token kind is kNum
};

#endif // MINICLANG_TOKEN_H

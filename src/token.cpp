#include "token.h"

Token::Token(TokenKind kind, SourceLocation start_loc, int length):
  kind_{kind}, start_{start_loc}, length_{length}, end_{start_loc.getLocPtr() + length} {}

SourceLocation Token::getStart() const { return start_; }

SourceLocation Token::getEnd() const { return end_; }

int Token::getLength() const { return length_; }

TokenKind Token::getKind() const {
  return kind_;
}

int Token::getValue() const {
  return value_;
}

void Token::setValue(int val) {
  value_ = val;
}

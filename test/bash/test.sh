#!/bin/bash
assert() {
  expected="$1"
  input="$2"

  ../../miniclang "$input" > tmp.ll || exit
  llc -filetype=obj tmp.ll -o tmp.o
  clang tmp.o -o tmp.out
  ./tmp.out
  actual="$?"

  if [ "$actual" = "$expected" ]; then
    echo "$input => $actual"
  else
    echo "$input => $expected expected, but got $actual"
    exit 1
  fi
}

assert 0 0
assert 42 42

echo OK

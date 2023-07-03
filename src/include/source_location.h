#ifndef MINICLANG_SOURCE_LOCATION_H
#define MINICLANG_SOURCE_LOCATION_H

class SourceLocation {
public:
  SourceLocation(const char* loc): loc_(loc) {}
  SourceLocation(unsigned file_id, const char* loc): file_id_{file_id}, loc_{loc} {}
  const char* getLocPtr() { return loc_; };
private:
  unsigned file_id_{0};
  const char* loc_;
};

#endif // MINICLANG_SOURCE_LOCATION_H

export module source_location;

export class SourceLocation {
public:
  SourceLocation(const char *loc) : loc_(loc) {}
  SourceLocation(unsigned file_id, const char *loc)
      : file_id_{file_id}, loc_{loc} {}
  unsigned getFileId() { return file_id_; }
  const char *getLoc() { return loc_; };

private:
  unsigned file_id_{0};
  const char *loc_;
};

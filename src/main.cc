#include "interface.hpp"
#include "pdf_parser.hpp"

int main() {

  PDFManager Shelf;
  PDFParser Parser;

  // Adding new pdfs

  std::string name = Parser::get_name();
  int page_count = Parser::send_pages();
  Shelf.add_pdf(name, page_count);

  return 0;
}

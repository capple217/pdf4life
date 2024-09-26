#include "interface.hpp"
#include "pdf_parser.hpp"

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

PDFDocument::PDFDocument(const std::string &name, int total)
    : filename(name), pages(total), current_page(0) {}

void PDFManager::add_pdf(const std::string &filename, int total_pages) {
  PDFDocument doc(filename, total_pages);
  pdfs.push_back(doc);
  pdf_index["filename"] = pdfs.size() - 1;
}

PDFDocument *PDFManager::get_pdf(const std::string &filename) {
  if (pdf_index.find(filename) != pdf_index.end()) {
    return &pdfs[pdf_index["filename"]];
  }
  return nullptr;
}

void PDFManager::display_pdfs() const {
  for (const auto &docs : pdfs) {
    std::cout << "PDF: " << docs.filename << std::endl
              << "Pages: " << docs.pages << std::endl
              << "Current Page: " << docs.current_page << "\n\n";
  }
}

int main() {
  PDFManager manager;
  manager.add_pdf("tester.pdf", 10);
  manager.add_pdf("tester2.pdf", 5);

  manager.display_pdfs();

  PDFDocument *doc = manager.get_pdf("tester.pdf");
  if (doc) {
    std::cout << "Found: " << doc << std::endl;
  } else {
    std::cerr << "PDF Not Found" << std::endl;
    return -1;
  }

  return 0;
}

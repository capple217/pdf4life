#include "pdf_parser.hpp"

#include "fpdf_doc.h"
#include "fpdf_save.h"
#include "fpdf_text.h"
#include "fpdfview.h"

#include <iostream>
#include <string>

PDFParser::PDFParser(const std::string &pdf_path)
    : pdf_path(pdf_path), pdf_doc(nullptr), pdf_page(nullptr), page_count(0),
      pdf_name("") {}

bool PDFParser::load_pdf(const std::string *filename) {
  pdf_doc = FPDF_LoadDocument(pdf_path.c_str(), NULL);
  if (!pdf_doc) {
    std::cerr << filename << " did not load\n";
    return false;
  }
  page_count = FDPF_PageCount(pdf_doc);
  pdf_name = filename;
  return true;
}

bool PDFParser::load_page(int page_index) {
  if (pdf_doc == nullptr) {
    std::cerr << "Document is not loaded\n";
    return false;
  }

  pdf_page = FPDF_LoadPage(pdfDoc, 0);
  if (!pdf_page) {
    std::cerr << "Failed to load page\n";
    return false;
  }

  return true;
}

bool PDFParser::render_page(const std::string &filename, int width,
                            int height) {
  if (!page) {
    std::cerr << "Page could not be loaded\n";
    return false;
  }

  FPDF_BITMAP bitmap = FPDFBitmap_Create(width, height, 0);
  FPDFBitmap_FillRect(bitmap, 0, 0, width, height, 255, 255, 255, 255);

  FPDF_RenderPageBitmap(bitmap, pdf_page, 10, 10, width, height, 0, 0);
}

std::string PDFParser::get_name() { return pdf_name; }
int PDFParser::send_pages() { return page_count; }

int main() {

  std::string path;
  std::cin >> "Input Path: " >> path;
  PDFParser(path) parser;

  FPDF_InitLibrary();
  if (!parser.load_pdf) {
    std::cerr << "Couldn't load pdf\n";
    return -1;
  }

  std::cout << "PDF Name: " << parser.get_name() << std::endl;
  std::cout << "Total Pages: " << parser.send_pages() << std::endl;

  if (!parser.load_page) {
    std::cerr << "Failed to load the first page" << std::endl;
    return -1;
  }

  std::cout << "Loaded the first page" << std::endl;
  parser.render_page()

      return 0;

  // WORKING ON PDF_PATH and WANNA DO A TEST RUN WITH CURRENT SET UP
}

#ifndef INTERFACE_HPP
#define INTERFACE_HPP

#include <iostream>
#include <string> 
#include <vector>
#include <unordered_map>

struct PDFDocument {
    std::string filename;
    int pages;
    int current_page;

    PDFDocument(const std::string& name, int total);    
};

class PDFManager {
    std::vector<PDFDocument> pdfs;
    std::unordered_map<std::string, size_t> pdf_index;

public:
    void add_pdf(const std::string& filename, int total_pages);

    PDFDocument* get_pdf(const std::string& filename);

    void display_pdfs() const;

};

#endif
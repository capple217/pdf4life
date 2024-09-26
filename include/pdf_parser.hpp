#ifndef PDF_PARSER_HPP
#define PDF_PARSER_HPP

#include "fpdfview.h"
#include "fpdf_doc.h"
#include "fpdf_text.h"
#include "fpdf_save.h"
#include <iostream>

class PDFParser {

    std::string pdf_path;
    FPDF_DOCUMENT pdf_doc;
    FPDF_PAGE pdf_page;
    int page_count;
    std::string pdf_name;

public:

    PDFParser(const std::string& pdf_path);

    bool load_pdf(const std::string& filename);

    bool load_page(int page_index);

    bool render_page(const std::string& filename, int width, int height);

    void close_all();

    std::string get_name() { return pdf_name; }
    int send_pages() { return page_count; }


};



#endif
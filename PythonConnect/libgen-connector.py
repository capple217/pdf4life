from libgen_api import LibgenSearch

s = LibgenSearch()
results = s.search_title("Harry Potter")

def format_output(result):
    formatted = (
        f"Title: {result['Title']}\n"
        f"Author: {result['Author']}\n"
        f"Publisher: {result.get('Publisher', 'N/A')}\n"
        f"Year: {result.get('Year', 'N/A')}\n"
        f"Pages: {result.get('Pages', 'N/A')}\n"
        f"Language: {result.get('Language', 'N/A')}\n"
        f"Size: {result.get('Size', 'N/A')}\n"
        f"File Extension: {result.get('Extension', 'N/A')}\n"
        f"Download Links:\n"
        f"  Mirror 1: {result.get('Mirror_1', 'N/A')}\n"
        f"  Mirror 2: {result.get('Mirror_2', 'N/A')}\n"
        f"  Mirror 3: {result.get('Mirror_3', 'N/A')}\n"
        "----------------------------------------"
    )
    return formatted

for res in results:
    print(format_output(res))

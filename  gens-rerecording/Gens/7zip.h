#ifndef _7ZIP_DEC_HEADER
#define _7ZIP_DEC_HEADER

void InitDecoder();
void CleanupDecoder();
const char* GetSupportedFormatsFilter();

// simplest way of extracting a file after calling InitDecoder():
// int size = ArchiveFile(filename).ExtractItem(0, buf, sizeof(buf));

struct ArchiveFile
{
	ArchiveFile(const char* filename);
	virtual ~ArchiveFile();

	int GetNumItems();
	int GetItemSize(int item);
	const char* GetItemName(int item);
	int ExtractItem(int item, unsigned char* outBuffer, int bufSize) const; // returns size, or 0 if failed
	int ExtractItem(int item, const char* outFilename) const;

	bool IsCompressed();
	const char* GetArchiveTypeName();

protected:
	struct ArchiveItem
	{
		int size;
		char* name;
	};
	ArchiveItem* m_items;
	int m_numItems;
	int m_typeIndex;
	int m_offset;
	char* m_filename;
};

#endif

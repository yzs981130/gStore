/*===========================================================================
 * Filename: Trie.h
 * Author: Zongyue Qin
 * Mail: qinzongyue@pku.edu.cn
 * Last modified	2018-01-15
 * Description:
 * This data structure is used to extract common prefixes from a given dataset,
 * and compress/uncompress the dataset according to those prefixes.
 ==============================================================================*/
#include "TrieNode.h"
#include "../Util/Triple.h"
#include "../Util/Util.h"
#include "../Parser/RDFParser.h"
#include <vector>

using namespace std;

class Trie
{
	static const int SAMPLE_UPBOUND = 300000;
	static const int LOWBOUND = 30;//this param should change with data sets
	string store_path;
	int curID;
	TrieNode *root;
	vector <string> dictionary;

	void addString(string _str, int _ID);
	void WriteDownNode(TrieNode *_node, ofstream &_fout, string _str);
	void Release(TrieNode *node);
public:
	static const int BUILDMODE = 0;
	static const int QUERYMODE = 1;

	Trie();
	Trie(const string _rdf_file, string _store_path);
	~Trie();
	bool isInitialized();
	bool WriteDown();
	void Release();
	TripleWithObjType Compress(const TripleWithObjType &_in_triple, int MODE);
	string Compress(string _str);
	bool LoadDictionary();
	string Uncompress(const char *_str, const int len);
	string Uncompress(const string &_str, const int len);
	bool LoadTrie(string dictionary_path);
};

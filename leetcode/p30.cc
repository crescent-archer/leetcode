#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> findSubstring1(string s, vector<string>& words) 
{
    // 特殊情况直接排除
    if(s.empty() || words.empty()) return {};
    
    // 存放结果的数组
    vector<int> result;
    
    // 单词数组中的单词的大小，个数，以及总长度
    size_t one_word = words[0].size();
    size_t word_num = words.size();
    // int all_len=one_word*word_num;
    
    // 建立单词->单词个数的映射
    unordered_map<string,int> m1;
    for(const auto& w:words) m1[w]++;
    
    for(size_t i = 0; i < one_word; ++i)
    {
        // left和rigth表示窗口的左右边界，count用来统计匹配的单词个数
        size_t left = i,right = i,count = 0;
        
        unordered_map<string,int> m2;
        
        // 开始滑动窗口
        while(right + one_word <= s.size())
        {
            // 从s中提取一个单词拷贝到w
            string w = s.substr(right, one_word);
            right += one_word; // 窗口右边界右移一个单词的长度
            
            if(m1.count(w) == 0) // 此单词不在words中，表示匹配不成功,然后重置单词个数、窗口边界、以及m2
            {
                count = 0;
                left = right;
                m2.clear();
            }
            else // 该单词匹配成功，添加到m2中
            {
                m2[w]++;
                count++;    
                while(m2.at(w) > m1.at(w)) // 一个单词匹配多次，需要缩小窗口，也就是left右移
                {
                    string t_w = s.substr(left,one_word);
                    count--;
                    m2[t_w]--;
                    left += one_word;
                }
                if(count == word_num) result.push_back(left);
            }
        }
    }
    return result;
}

vector<int> findSubstring(string s, vector<string>& words) 
{
    if(s.empty() || words.empty()) return {};

    unordered_map<string, int> umap;
    for(auto w: words) ++umap[w]; 
    size_t words_num = words.size();
    size_t word_len = words[0].size();
    vector<int> result;

    for(size_t i = 0; i < word_len; ++i)
    {
        size_t left = i, right = i;
        unordered_map<string, int> tmp;
        size_t count = 0;

        while(right + word_len <= s.size())
        {
            string word = s.substr(right, word_len);

            right += word_len; 
            if(umap.count(word) < 1)
            {
                tmp.clear();
                count = 0;
                left = right;
            }
            else
            {
                ++tmp[word];
                ++count;
                while(tmp[word] > umap[word])
                {
                    string first_word = s.substr(left, word_len);
                    --tmp[first_word];
                    left += word_len;
                    --count;
                }
                if(count == words_num) result.push_back(left);
                
            }
        }
    }
    return result;
}

int main()
{
    string s = "wordgoodgoodgoodbestword";
    vector<string> vec{"word","good","best","word"};
    auto vi = findSubstring(s, vec);
    for(auto i: vi)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    return 0;
}


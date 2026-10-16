#include <string_view>
#include <unordered_map>

class Solution {
public:
    vector<vector<string>> findDuplicate(const vector<string>& paths)
    {
        vector<vector<string>> duplicates;
        duplicates.reserve( paths.size() );

        unordered_map<string_view, vector<string>> contentFilenames;
        contentFilenames.reserve( 8 );

        for( auto& s : paths )
        {
            // parse directory
            size_t i = s.find_first_of( ' ' );
            auto directory = string_view( s.c_str(), i );
            ++i; // skip space

            while( i < s.size() )
            {
                // parse filename
                const auto filenameStart = i;
                while( s[i] != '(' )
                    ++i;

                auto filename = string_view( s.c_str() + filenameStart, i - filenameStart );
                ++i; // skip (

                // parse content
                const auto contentStart = i;
                while( s[i] != ')' )
                    ++i;

                auto content = string_view( s.c_str() + contentStart, i - contentStart );
                i += 2; // skip ) and space

                // concatenate directory and filename
                string fullPath;
                fullPath.reserve( directory.size() + filename.size() + 1 );
                ( ( fullPath += directory ) += '/' ) += filename;

                // record filename under content key
                auto it = contentFilenames.find( content );
                if ( it == contentFilenames.end() )
                {
                    vector<string> filenames;
                    filenames.reserve( 8 );

                    bool inserted;
                    std::tie( it, inserted ) = contentFilenames.emplace( content, std::move(filenames) );
                }
                it->second.push_back( std::move( fullPath ) );
            }
        }

        for( auto&&[ content, filenames ] : contentFilenames )
        {
            if ( filenames.size() > 1 )
                duplicates.push_back( std::move( filenames ) );
        }

        return duplicates;
    }
};
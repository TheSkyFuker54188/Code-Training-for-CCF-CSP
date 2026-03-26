// 2017年03月 第C题 Markdown
// 考点：字符串处理、模拟、分块解析

#include <iostream>
#include <string>
#include <vector>

using namespace std;

static bool isHeading(const string &line)
{
    return !line.empty() && line[0] == '#';
}

static bool isListItem(const string &line)
{
    return !line.empty() && line[0] == '*';
}

static string parseInline(const string &s, int left, int right)
{
    string result;
    int i = left;
    while (i < right)
    {
        if (s[i] == '_')
        {
            int j = i + 1;
            while (j < right && s[j] != '_')
                j++;
            result += "<em>";
            result += parseInline(s, i + 1, j);
            result += "</em>";
            i = j + 1;
        }
        else if (s[i] == '[')
        {
            int textR = i + 1;
            while (textR < right && s[textR] != ']')
                textR++;

            int linkL = textR + 1;
            int linkR = linkL + 1;
            while (linkR < right && s[linkR] != ')')
                linkR++;

            string text = parseInline(s, i + 1, textR);
            string link = s.substr(linkL + 1, linkR - linkL - 1);
            result += "<a href=\"" + link + "\">" + text + "</a>";
            i = linkR + 1;
        }
        else
        {
            result.push_back(s[i]);
            i++;
        }
    }
    return result;
}

static string parseInline(const string &s)
{
    return parseInline(s, 0, static_cast<int>(s.size()));
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<string> lines;
    string line;
    while (getline(cin, line))
    {
        lines.push_back(line);
    }

    vector<string> output;
    int n = static_cast<int>(lines.size());
    int i = 0;
    while (i < n)
    {
        if (lines[i].empty())
        {
            i++;
            continue;
        }

        if (isHeading(lines[i]))
        {
            int level = 0;
            while (level < static_cast<int>(lines[i].size()) && lines[i][level] == '#')
                level++;

            int pos = level;
            while (pos < static_cast<int>(lines[i].size()) && lines[i][pos] == ' ')
                pos++;

            string content = lines[i].substr(pos);
            content = parseInline(content);
            output.push_back("<h" + to_string(level) + ">" + content + "</h" + to_string(level) + ">");
            i++;
            continue;
        }

        if (isListItem(lines[i]))
        {
            output.push_back("<ul>");
            while (i < n && isListItem(lines[i]))
            {
                int pos = 1;
                while (pos < static_cast<int>(lines[i].size()) && lines[i][pos] == ' ')
                    pos++;
                string content = lines[i].substr(pos);
                content = parseInline(content);
                output.push_back("<li>" + content + "</li>");
                i++;
            }
            output.push_back("</ul>");
            continue;
        }

        vector<string> paragraph;
        while (i < n && !lines[i].empty() && !isHeading(lines[i]) && !isListItem(lines[i]))
        {
            paragraph.push_back(parseInline(lines[i]));
            i++;
        }

        if (paragraph.size() == 1)
        {
            output.push_back("<p>" + paragraph[0] + "</p>");
        }
        else
        {
            paragraph[0] = "<p>" + paragraph[0];
            paragraph.back() += "</p>";
            for (const string &row : paragraph)
                output.push_back(row);
        }
    }

    for (const string &row : output)
        cout << row << '\n';

    return 0;
}

# C/C++����Լ�Git������ϰ(ʹ��VSCode)
## Ч��Ԥ��
![Ч��Ԥ��](https://raw.githubusercontent.com/David-AJ/C_CPP_PROJECTS/master/img/20170717120306.png)
## 1. VSCode����`C/C++`����
* `.vscode\c_cpp_properties.json`����`includePath`
* `.vscode\tasks.json`����`gcc/g++`����ָ��
* `.vscode\launch.json`����Debug����ָ��(DebugЧ��)    

![Ԥ��](https://raw.githubusercontent.com/David-AJ/C_CPP_PROJECTS/master/img/20170807223226.jpg)
* `.vscode\settings.json`�����ļ������������
## 2. VSCode��`Git`����ʹ��
* ʹ��`VSCode`��ʼ����������`Git`��    

![GitԤ��](https://raw.githubusercontent.com/David-AJ/C_CPP_PROJECTS/master/img/20170808092916.JPG)
* `Github`����Զ�̿�
* �ڱ���`Git`��������ָ��(����`xxxx`Ϊ`Github`��ӦԶ�̿��ַ)
```PowerShell
git remote add origin https://github.com/xxxx.git
git push -u origin master
```
* ʹ��`git log`ָ��鿴`Git`��ʷ

![git logԤ��](https://raw.githubusercontent.com/David-AJ/C_CPP_PROJECTS/master/img/20170807223028.jpg)
## 3. LeetCode��Ŀ(`git log`)
### 8098f56 David-AJ: [LeetCode 551](https://leetcode.com/problems/student-attendance-record-i/description/) Tag-String
Whether a string contains **no more than one 'A'** or **two continuous 'L'**.

Example 1:

    Input: "PPALLP"
    Output: True

Example 2:

    Input: "PPALLL"
    Output: False
### d22c26a David-AJ: [LeetCode 345](https://leetcode.com/problems/reverse-vowels-of-a-string/description/) Tag-String 
Write a function that takes a string as input and reverse only the vowels of a string.

Example 1:    
Given s = "hello", return "holle".

Example 2:    
Given s = "leetcode", return "leotcede".

Note:    
The vowels does not include the letter "y". 
### 14ddf97 David-AJ: [LeetCode 206](https://leetcode.com/problems/reverse-linked-list/description/) Tag-Linked List 
Reverse a singly linked list.
### d828033 David-AJ: [LeetCode 541](https://leetcode.com/problems/reverse-string-ii/description/) Tag-String 
Given a string and an integer k, you need to reverse the first k characters for every 2k characters counting from the start of the string. If there are less than k characters left, reverse all of them. If there are less than 2k but greater than or equal to k characters, then reverse the first k characters and left the other as original.

Example:

    Input: s = "abcdefg", k = 2
    Output: "bacdfeg"
Restrictions:

    The string consists of lower English letters only.
    Length of the given string and k will in the range [1, 10000]
### 4d1e43e David-AJ: [LeetCode 383](https://leetcode.com/problems/ransom-note/description/) Tag-String 
Given an arbitrary ransom note string and another string containing letters from all the magazines, write a function that will return true if the ransom note can be constructed from the magazines ; otherwise, it will return false.

Each letter in the magazine string can only be used once in your ransom note.

**Note:**    
You may assume that both strings contain only lowercase letters.

    canConstruct("a", "b") -> false
    canConstruct("aa", "ab") -> false
    canConstruct("aa", "aab") -> true

### ccfc31c David-AJ: [LeetCode 125](https://leetcode.com/problems/valid-palindrome/description/) Tag-String 
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

For example,    
`"A man, a plan, a canal: Panama"` is a palindrome.    
`"race a car"` is not a palindrome.

Note:      
Have you consider that the string might be empty? This is a good question to ask during an interview.

For the purpose of this problem, we define empty string as valid palindrome. 
### c80c4f3 David-AJ: [LeetCode 108](https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description/) Tag-Tree 
Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
### b08d895 David-AJ: [LeetCode 606](https://leetcode.com/problems/construct-string-from-binary-tree/description/) Tag-String 
You need to construct a string consists of parenthesis and integers from a binary tree with the preorder traversing way.

The null node needs to be represented by empty parenthesis pair "()". And you need to omit all the empty parenthesis pairs that don't affect the one-to-one mapping relationship between the string and the original binary tree.

Example 1:

    Input: Binary tree: [1,2,3,4]
           1
         /   \
        2     3
       /    
      4     

    Output: "1(2(4))(3)"

    Explanation: Originallay it needs to be "1(2(4)())(3()())", but you need to omit all the unnecessary empty parenthesis pairs. And it will be "1(2(4))(3)".

Example 2:

    Input: Binary tree: [1,2,3,null,4]
          1
         /   \
        2     3
         \  
          4 

    Output: "1(2()(4))(3)"

    Explanation: Almost the same as the first example, except we can't omit the first parenthesis pair to break the one-to-one mapping relationship between the input and the output.
### a6d3407 David-AJ: [LeetCode 520](https://leetcode.com/problems/detect-capital/description/) Tag-String 
Given a word, you need to judge whether the usage of capitals in it is right or not.

We define the usage of capitals in a word to be right when one of the following cases holds:

1. All letters in this word are capitals, like "USA".
2. All letters in this word are not capitals, like "leetcode".
3. Only the first letter in this word is capital if it has more than one letter, like "Google".

Otherwise, we define that this word doesn't use capitals in a right way.

Example 1:

    Input: "USA"
    Output: True

Example 2:

    Input: "FlaG"
    Output: False

Note: The input will be a non-empty word consisting of uppercase and lowercase latin letters. 
### d2a25cc David-AJ: [LeetCode 557](https://leetcode.com/problems/reverse-words-in-a-string-iii/description/) Tag-String 
Given a string, you need to reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

Example 1:

    Input: "Let's take LeetCode contest"
    Output: "s'teL ekat edoCteeL tsetnoc"

**Note:** In the string, each word is separated by single space and there will not be any extra space in the string. 
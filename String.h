/*
* 说明：这是以字符串处理算法为主的库
* 编号：002
* 备注：字符串处理
*/

#include "Header.h"

namespace STRING
{
	/*
	* 编号：002_1
	* 函数名称：_Uppcase_Str
	* 描述：返回输入字符串的大写模式
	*/
	string _Uppcase_Str(string _Dest_Str)
	{
		_FOR_(i, _Dest_Str.length())
		{
			if (_Dest_Str[i] >= 'a'&&_Dest_Str[i] <= 'z')
			{
				_Dest_Str[i] = (char)('A' + _Dest_Str[i] - 'a');
			}
		}
		return _Dest_Str;
	}

	/*
	* 编号：002_2
	* 函数名称：_Lowcase_Str
	* 描述：返回输入字符串的小写模式
	*/
	string _Lowcase_Str(string _Dest_Str)
	{
		_FOR_(i, _Dest_Str.length())
		{
			if (_Dest_Str[i] >= 'A'&&_Dest_Str[i] <= 'Z')
			{
				_Dest_Str[i] = (char)('a' + _Dest_Str[i] - 'A');
			}
		}
		return _Dest_Str;
	}

	/*
	* 编号：002_3
	* 函数名称：_Count_of_Letter
	* 描述:返回总共出现了多少个不同的字符
	*/
	int _Count_of_Letter(string _Dest_Str)
	{
		list<char> _List_Str;
		_FOR_(i, _Dest_Str.length())
		{
			_List_Str.push_back(_Dest_Str[i]);
		}
		_List_Str.sort();
		_List_Str.unique();
		return _List_Str.size();
	}

	/*
	* 编号：002_4
	* 函数名称：_Count_of_Letter_if
	* 描述:返回指定字符在字符串中出现的次数
	*/
	int _Count_of_Letter_if(string _Dest_Str, char _Dest_Ch)
	{
		int _Res_Num = 0;
		_FOR_(i, _Dest_Str.length())
		{
			if (_Dest_Str[i] == _Dest_Ch)
			{
				_Res_Num++;
			}
		}
		return _Res_Num;
	}

	/*
	* 编号：002_5
	* 函数名称：_Fist_Idex_Ch
	* 描述:返回指定字符在字符串中首次出现的位置
	* 备注：返回-1表示没有这样的字符在字符串中出现
	*/
	int _Fist_Idex_Ch(string _Dest_Str, char _Dest_Ch)
	{
		int _Res_Idex = -1;
		_FOR_(i, _Dest_Str.length())
		{
			if (_Dest_Str[i] == _Dest_Ch)
			{
				_Res_Idex = i;
				break;
			}
		}
		return _Res_Idex;
	}

	/*
	* 编号：002_5
	* 函数名称：_Last_Idex_Ch
	* 描述:返回指定字符在字符串中最后出现出现的位置
	* 备注：返回-1表示没有这样的字符在字符串中出现
	*/
	int _Last_Idex_Ch(string _Dest_Str, char _Dest_Ch)
	{
		int _Res_Idex = -1;
		_Re_For(i, _Dest_Str.length() - 1)
		{
			if (_Dest_Str[i] == _Dest_Ch)
			{
				_Res_Idex = i;
				break;
			}
		}
		return _Res_Idex;
	}

	/*
	* 编号：002_6
	* 函数名称：_Next_Permutation
	* 描述:返回输入字符串按照字典序的全排列
	* 备注：返回当前字符串开始的全排列
	* 如果想要输出所有排列，去掉注释
	*/
	vector<string> _Next_Permutation(string _Souce_Str)
	{
		vector<string> _Res_Set_Str;
		//sort(_Souce_Str.begin(), _Souce_Str.end());
		//_Res_Set_Str.push_back(_Souce_Str);
		while (next_permutation(_Souce_Str.begin(), _Souce_Str.end()))
		{
			_Res_Set_Str.push_back(_Souce_Str);
		}
		return _Res_Set_Str;
	}

	/*
	* 编号：002_7
	* 函数名称：_Get_Next_Array
	* 描述:返回输入字符串的next数组
	* 备注：此函数可以单独使用
	*/
	int* _Get_Next_Array(string _Pattern_Str)
	{
		int* _Next_Array;
		_Next_Array = new int[_Pattern_Str.length()];
		_Next_Array[0] = -1;
		int i = 0, j = -1;
		while (i != _Pattern_Str.length())
		{
			if (j == -1 || _Pattern_Str[i] == _Pattern_Str[j])
			{
				i++, j++;
				_Next_Array[i] = j;
			}
			else{
				j = _Next_Array[j];
			}
		}
		return _Next_Array;
	}

	/*
	* 编号：002_8
	* 函数名称：_Brute_Force
	* 描述:判断模式串是否在主串中出现
	* 备注：如果匹配成功则返回第一次匹配成功的开始下标，否则返回-1
	*/
	int _Brute_Force(string _Main_Str, string _Pattern_Str)
	{
		int _Res_Idex = 0;
		while (_Res_Idex != _Main_Str.length())
		{
			int _Idex_of_Main_Str;
			int _Length_of_Pattern;
			for (_Idex_of_Main_Str = _Res_Idex, _Length_of_Pattern = 0;
				_Idex_of_Main_Str != _Main_Str.length() &&
				_Length_of_Pattern != _Pattern_Str.length() &&
				_Main_Str[_Idex_of_Main_Str] == _Pattern_Str[_Length_of_Pattern];
			_Idex_of_Main_Str++, _Length_of_Pattern++);
			if (_Length_of_Pattern == _Pattern_Str.length())
			{
				return _Res_Idex;
			}
			_Res_Idex++;
		}
		return -1;
	}

	/*
	* 编号：002_9
	* 函数名称：_Kmp
	* 描述:判断模式串是否在主串中出现
	* 备注：如果匹配成功则返回第一次匹配成功的开始下标，否则返回-1
	*/
	int _Kmp(string _Main_Str, string _Pattern_Str)
	{
		int *_Next_array = _Get_Next_Array(_Pattern_Str);
		int _Idex_of_Main_str = 0;
		int _Idex_of_Pattern_str = 0;
		int _Res_Idex = -1;
		while (_Idex_of_Main_str != _Main_Str.length() &&
			_Idex_of_Pattern_str != _Pattern_Str.length())
		{
			if (_Idex_of_Pattern_str == -1 ||
				_Main_Str[_Idex_of_Main_str] == _Pattern_Str[_Idex_of_Pattern_str])
			{
				_Idex_of_Main_str++;
				_Idex_of_Pattern_str++;
			}
			else{
				_Idex_of_Pattern_str = _Next_array[_Idex_of_Pattern_str];
			}
		}
		if (_Idex_of_Pattern_str >= _Pattern_Str.length())
		{
			_Res_Idex = _Idex_of_Main_str - _Pattern_Str.length();
		}
		return _Res_Idex;
	}

	/*
	* 编号：002_10
	* 函数名称：_Order_Str
	* 描述:判断给定字符串是不是有序
	* 备注：该函数将忽略大小写
	* 返回0代表无序，返回1代表从小到大有序
	* 返回2代表从大到小有序,3代表只有一个字符
	*/
	int _Order_Str(string _Dest_Str)
	{
		_Dest_Str = _Uppcase_Str(_Dest_Str);
		string _Temp_Sorted_Str = _Dest_Str;
		sort(_Temp_Sorted_Str.begin(), _Temp_Sorted_Str.end());
		string _Reverse_Str = _Temp_Sorted_Str;
		reverse(_Reverse_Str.begin(), _Reverse_Str.end());
		if (_Reverse_Str == _Temp_Sorted_Str)
		{
			return 2;
		}
		else if (_Dest_Str == _Temp_Sorted_Str)
		{
			return 1;
		}
		else if (_Dest_Str == _Reverse_Str)
		{
			return 2;
		}
		else{
			return 0;
		}
	}

	/*
	* 编号：002_11
	* 函数名称：_Delete_If_Ch
	* 描述:将给定的字符从字符串中删除
	* 备注：该函数将不处理输入错误的情况
	*/
	string _Delete_If_Ch(string _Dest_Str, char _Delete_Ch)
	{
		string _Res_Str = "";
		_FOR_(i, _Dest_Str.length())
		{
			if (_Dest_Str[i] != _Delete_Ch)
			{
				_Res_Str += _Dest_Str[i];
			}
		}
		return _Res_Str;
	}

	/*
	* 编号：002_12
	* 函数名称：_Delete_If_String
	* 描述:将给定的子字符串从字符串中删除
	* 备注：该函数将不处理输入错误的情况
	*/
	string _Delete_If_String(string _Dest_Str, string _Delete_Str)
	{
		//使用Kmp算法求出字串的位置，然后删除
	Loop:
		int _Start_Idex = _Kmp(_Dest_Str, _Delete_Str);
		if (_Start_Idex != -1)
		{
			_Dest_Str = _Dest_Str.substr(0, _Start_Idex) +
				_Dest_Str.substr(_Start_Idex + _Delete_Str.length());
			goto Loop;
		}
		else{
			return _Dest_Str;
		}
	}

	/*
	* 编号：002_13
	* 函数名称：_Count_If_String
	* 描述:该函数将返回给定字符串在源字符串中出现的次数
	*/
	int _Count_If_String(string _Dest_Str, string _Count_Str)
	{
		int _Res_Num = 0;
	_Loop:
		int _Start_Idex = _Kmp(_Dest_Str, _Count_Str);
		if (_Start_Idex != -1)
		{
			_Res_Num++;
			_Dest_Str = _Dest_Str.substr(_Start_Idex + 1);
			goto _Loop;
		}
		else{
			return _Res_Num;
		}
	}

	/*
	* 编号：002_14
	* 函数名称：_First_Idex_Str
	* 描述:该函数将返回给定字符串在源字符串中首次出现的位置
	* 备注：返回-1代表没有这样的字串存在于源字符串中
	*/
	int _First_Idex_Str(string _Dest_Str, string _Find_Str)
	{
		return _Kmp(_Dest_Str, _Find_Str);
	}

	/*
	* 编号：002_15
	* 函数名称：_Last_Idex_Str
	* 描述:该函数将返回给定字符串在源字符串中最后出现的位置
	* 备注：返回-1代表没有这样的字串存在于源字符串中
	*/
	int _Last_Idex_Str(string _Dest_Str, string _Find_Str)
	{
		int _Res_Idex;
		reverse(_Dest_Str.begin(), _Dest_Str.end());
		reverse(_Find_Str.begin(), _Find_Str.end());
		_Res_Idex = _Kmp(_Dest_Str, _Find_Str);
		_Res_Idex += (_Find_Str.length());
		return (_Dest_Str.length() - _Res_Idex);
	}

	/*
	* 编号：002_16
	* 函数名称：_Longest_Sub_Str
	* 描述:该函数将求出给定的两个字符串的最大公共子序列的长度
	* 备注：所谓子序列不要求连续，只要在两个串中都存在即可
	*/
	int _Longest_Sub_Str(string _Dest_Str_1, string _Dest_Str_2)
	{
		//动态申请内存
		int** _Longest_Length;
		_Longest_Length = new int*[_Dest_Str_1.length() + 1];
		_FOR_(i, _Dest_Str_1.length() + 1)
		{
			_Longest_Length[i] = new int[_Dest_Str_2.length() + 1];
		}
		_FOR_(i, _Dest_Str_1.length() + 1)
			_FOR_(j, _Dest_Str_2.length() + 1){
				_Longest_Length[i][j] = 0;
			}
		_FFOR_(i, _Dest_Str_1.length())
			_FFOR_(j, _Dest_Str_2.length()){
				if (_Dest_Str_1[i - 1] == _Dest_Str_2[j - 1])
				{
					_Longest_Length[i][j] = _Longest_Length[i - 1][j - 1] + 1;
				}
				else{
					_Longest_Length[i][j] = max(_Longest_Length[i - 1][j],
						_Longest_Length[i][j - 1]);
				}
			}
		int Res_Num = _Longest_Length[_Dest_Str_1.length()][_Dest_Str_2.length()];
		_FOR_(i, _Dest_Str_1.length() + 1)
		{
			delete[] _Longest_Length[i];
		}
		delete[]_Longest_Length;
		return Res_Num;
	}

	/*
	* 编号：002_17
	* 函数名称：Is_Palindrome
	* 描述:该函数判断给定的一个字符串是否构成回文
	*/
	bool Is_Palindrome(string _Dest_Str)
	{
		string _Temp_Str = _Dest_Str;
		reverse(_Temp_Str.begin(), _Temp_Str.end());
		return (_Dest_Str == _Temp_Str);
	}

	/*
	* 编号：002_18
	* 函数名称：Min_Change_Time_To_Palindrome
	* 描述:该函数将给出最少加入几个字符可以使得其变为回文
	*/
	int Min_Change_Time_To_Palindrome(string _Dest_Str)
	{
		string _Reverse_Str = _Dest_Str;
		reverse(_Reverse_Str.begin(), _Reverse_Str.end());
		return (_Dest_Str.length() -
			_Longest_Sub_Str(_Dest_Str, _Reverse_Str));
	}
}/*end of namespace STRING*/


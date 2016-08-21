/*
* ˵�����������ַ��������㷨Ϊ���Ŀ�
* ��ţ�002
* ��ע���ַ�������
*/

#include "Header.h"

namespace STRING
{
	/*
	* ��ţ�002_1
	* �������ƣ�_Uppcase_Str
	* ���������������ַ����Ĵ�дģʽ
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
	* ��ţ�002_2
	* �������ƣ�_Lowcase_Str
	* ���������������ַ�����Сдģʽ
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
	* ��ţ�002_3
	* �������ƣ�_Count_of_Letter
	* ����:�����ܹ������˶��ٸ���ͬ���ַ�
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
	* ��ţ�002_4
	* �������ƣ�_Count_of_Letter_if
	* ����:����ָ���ַ����ַ����г��ֵĴ���
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
	* ��ţ�002_5
	* �������ƣ�_Fist_Idex_Ch
	* ����:����ָ���ַ����ַ������״γ��ֵ�λ��
	* ��ע������-1��ʾû���������ַ����ַ����г���
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
	* ��ţ�002_5
	* �������ƣ�_Last_Idex_Ch
	* ����:����ָ���ַ����ַ����������ֳ��ֵ�λ��
	* ��ע������-1��ʾû���������ַ����ַ����г���
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
	* ��ţ�002_6
	* �������ƣ�_Next_Permutation
	* ����:���������ַ��������ֵ����ȫ����
	* ��ע�����ص�ǰ�ַ�����ʼ��ȫ����
	* �����Ҫ����������У�ȥ��ע��
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
	* ��ţ�002_7
	* �������ƣ�_Get_Next_Array
	* ����:���������ַ�����next����
	* ��ע���˺������Ե���ʹ��
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
	* ��ţ�002_8
	* �������ƣ�_Brute_Force
	* ����:�ж�ģʽ���Ƿ��������г���
	* ��ע�����ƥ��ɹ��򷵻ص�һ��ƥ��ɹ��Ŀ�ʼ�±꣬���򷵻�-1
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
	* ��ţ�002_9
	* �������ƣ�_Kmp
	* ����:�ж�ģʽ���Ƿ��������г���
	* ��ע�����ƥ��ɹ��򷵻ص�һ��ƥ��ɹ��Ŀ�ʼ�±꣬���򷵻�-1
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
	* ��ţ�002_10
	* �������ƣ�_Order_Str
	* ����:�жϸ����ַ����ǲ�������
	* ��ע���ú��������Դ�Сд
	* ����0�������򣬷���1�����С��������
	* ����2����Ӵ�С����,3����ֻ��һ���ַ�
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
	* ��ţ�002_11
	* �������ƣ�_Delete_If_Ch
	* ����:���������ַ����ַ�����ɾ��
	* ��ע���ú����������������������
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
	* ��ţ�002_12
	* �������ƣ�_Delete_If_String
	* ����:�����������ַ������ַ�����ɾ��
	* ��ע���ú����������������������
	*/
	string _Delete_If_String(string _Dest_Str, string _Delete_Str)
	{
		//ʹ��Kmp�㷨����ִ���λ�ã�Ȼ��ɾ��
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
	* ��ţ�002_13
	* �������ƣ�_Count_If_String
	* ����:�ú��������ظ����ַ�����Դ�ַ����г��ֵĴ���
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
	* ��ţ�002_14
	* �������ƣ�_First_Idex_Str
	* ����:�ú��������ظ����ַ�����Դ�ַ������״γ��ֵ�λ��
	* ��ע������-1����û���������ִ�������Դ�ַ�����
	*/
	int _First_Idex_Str(string _Dest_Str, string _Find_Str)
	{
		return _Kmp(_Dest_Str, _Find_Str);
	}

	/*
	* ��ţ�002_15
	* �������ƣ�_Last_Idex_Str
	* ����:�ú��������ظ����ַ�����Դ�ַ����������ֵ�λ��
	* ��ע������-1����û���������ִ�������Դ�ַ�����
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
	* ��ţ�002_16
	* �������ƣ�_Longest_Sub_Str
	* ����:�ú�������������������ַ�������󹫹������еĳ���
	* ��ע����ν�����в�Ҫ��������ֻҪ���������ж����ڼ���
	*/
	int _Longest_Sub_Str(string _Dest_Str_1, string _Dest_Str_2)
	{
		//��̬�����ڴ�
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
	* ��ţ�002_17
	* �������ƣ�Is_Palindrome
	* ����:�ú����жϸ�����һ���ַ����Ƿ񹹳ɻ���
	*/
	bool Is_Palindrome(string _Dest_Str)
	{
		string _Temp_Str = _Dest_Str;
		reverse(_Temp_Str.begin(), _Temp_Str.end());
		return (_Dest_Str == _Temp_Str);
	}

	/*
	* ��ţ�002_18
	* �������ƣ�Min_Change_Time_To_Palindrome
	* ����:�ú������������ټ��뼸���ַ�����ʹ�����Ϊ����
	*/
	int Min_Change_Time_To_Palindrome(string _Dest_Str)
	{
		string _Reverse_Str = _Dest_Str;
		reverse(_Reverse_Str.begin(), _Reverse_Str.end());
		return (_Dest_Str.length() -
			_Longest_Sub_Str(_Dest_Str, _Reverse_Str));
	}
}/*end of namespace STRING*/


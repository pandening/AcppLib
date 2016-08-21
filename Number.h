#include "Header.h"

namespace NUMBER
{
	/*这个函数可以将一位整数换位字符*/
	inline char _INT_TO_Char(int n)
	{
		return (char)('0' + n);
	}

	/*这个函数可以将多位整数变为字符串*/
	inline string _INT_TO_String(int n)
	{
		string _Res_String = "";
		while (n != 0)
		{
			_Res_String = _INT_TO_Char(n % 10) + _Res_String;
			n /= 10;
		}
		if (_Res_String.length() == 0){
			_Res_String = "0";
		}
		return _Res_String;
	}

	/*这个函数可以将一个字符变为数字*/
	inline int _Char_To_Int(char _Dest_ch)
	{
		return (int)(_Dest_ch - '0');
	}

	/*这个函数可以将一个字符串变为整数*/
	inline int _String_To_Int(string _Dest_str)
	{
		int _Res_Interger = 0;
		int _I = 0;
		_Re_For(i, _Dest_str.length() - 1)
		{
			_Res_Interger += _Char_To_Int(_Dest_str[i])*pow(10.0, _I++);
		}
		return _Res_Interger;
	}

	/*
	* 分组代号：001_1
	* 函数名称：_Big_Interger_Operator
	* 描述：该函数可以实现超大整数的加法
	*/
	string _Big_Interger_Operator(string Num_1, string Num_2)
	{
		string _Res_Num = "";
		int Dis_Length = abs((int)(Num_1.length() - Num_2.length()));
		string Zero_Push(Dis_Length, '0');
		if (Num_1.length() < Num_2.length())
		{
			Num_1 = Zero_Push + Num_1;
		}
		else{
			Num_2 = Zero_Push + Num_2;
		}
		int _Sum = 0, _Carry = 0;
		_Re_For(i, Num_1.length() - 1)
		{
			_Sum = _Char_To_Int(Num_1[i]) + _Char_To_Int(Num_2[i]) + _Carry;
			_Res_Num = _INT_TO_Char(_Sum % 10) + _Res_Num;
			_Carry = _Sum / 10;
		}
		if (_Carry != 0)
		{
			_Res_Num = _INT_TO_Char(_Carry) + _Res_Num;
		}
		return _Res_Num;
	}
	/*
	* 分组代号：001_2
	* 函数名字：_Big_Interger_Multiplication_One
	* 描述：用于实现一个整数和一个大整数之间的乘法
	*/
	string _Big_Interger_Multiplication_One(string _Dest_Str, char _k_)
	{
		string _Res_Str = "";
		int _Sum_ = 0, _Carry_ = 0;
		_Re_For(i, _Dest_Str.length() - 1)
		{
			_Sum_ = _Carry_ + _Char_To_Int(_Dest_Str[i])*_Char_To_Int(_k_);
			_Res_Str = _INT_TO_Char(_Sum_ % 10) + _Res_Str;
			_Carry_ = _Sum_ / 10;
		}
		if (_Carry_ != 0)
		{
			_Res_Str = _INT_TO_Char(_Carry_) + _Res_Str;
		}
		_Res_Str = _INT_TO_String(_String_To_Int(_Res_Str));
		return _Res_Str;
	}

	/*
	* 分组代号：001_3
	* 函数名字：_Big_Interger_Multiplication
	* 描述：用于实现两个大整数的乘法
	*/
	string _Big_Interger_Multiplication(string _Dest_Str1, string _Dest_Str2)
	{
		string _Res_Str = "0";
		if (_Dest_Str1.length() == 1)
		{
			return _Big_Interger_Multiplication_One(_Dest_Str2, _Dest_Str1[0]);
		}
		else if (_Dest_Str2.length() == 1)
		{
			return _Big_Interger_Multiplication_One(_Dest_Str1, _Dest_Str2[0]);
		}
		//用那个较短的作为乘数，可以减少运算次数
		if (_Dest_Str1.length() > _Dest_Str2.length())
		{
			string _Temp_str = _Dest_Str1;
			_Dest_Str1 = _Dest_Str2; _Dest_Str2 = _Temp_str;
		}
		string _Temp_Sum_Str = "0";
		int _Zero_ = 0;
		_Re_For(i, _Dest_Str1.length() - 1)
		{
			_Temp_Sum_Str = _Big_Interger_Multiplication_One(_Dest_Str2, _Dest_Str1[i]);
			string _Zero(_Zero_++, '0');
			_Temp_Sum_Str += _Zero;
			_Res_Str = _Big_Interger_Operator(_Temp_Sum_Str, _Res_Str);
		}
		return _Res_Str;
	}

	/*
	* 分组代号：001_4
	* 函数名称：_Big_Interger_Operator
	* 描述：该函数可以实现超大整数的加法
	* 备注：这是一个重载函数
	* 用法：如果你不提供第三个参数，那么默认为大数加法
	* 但是如果你提供了（'+','-','*'）中的一个运算符，那么
	* 函数将按照您的要求进行运算，如果输入错误，将按照
	* 默认的加法进行运算。
	*/
	string _Big_Interger_Operator(string Num_1, string Num_2, char _Your_operator)
	{
		if (_Your_operator != '+'&&_Your_operator != '-')
		{
			//您的输入有误，但是不提示，做加法运算
			return _Big_Interger_Operator(Num_1, Num_2);
		}
		if (_Your_operator == '+')
		{
			//做加法运算
			return _Big_Interger_Operator(Num_1, Num_2);
		}
		else if (_Your_operator == '-')
		{
			//如果您输入的是两个数都是单位数字，那么直接输出
			if (Num_1.length() == 1 && Num_2.length() == 1)
			{
				int _Ans_ = _Char_To_Int(Num_1[0]) - _Char_To_Int(Num_2[0]);
				if (_Ans_ < 0)
				{
					return '-' + _INT_TO_String(abs((int)_Ans_));
				}
				else{
					return _INT_TO_String(_Ans_);
				}
			}
			bool _Negative = false;
			string _Res_Num = "";
			int Dis_Length = abs((int)(Num_1.length() - Num_2.length()));
			string Zero_Push(Dis_Length, '0');
			if (Num_1.length() < Num_2.length())
			{
				Num_1 = Zero_Push + Num_1;
			}
			else{
				Num_2 = Zero_Push + Num_2;
			}
			if (Num_1[0] < Num_2[0])
			{
				//请保证您输入的数据不以‘0’开头
				_Negative = true;
				string _Temp_str;
				_Temp_str = Num_1;
				Num_1 = Num_2;
				Num_2 = _Temp_str;
			}
			int _Sum = 0, _Carry = 0;
			_Re_For(i, Num_1.length() - 1)
			{
				//如果当前被减数的大小等于0或者小于减数，那么借位设为0
				//同时，被减数加10，被减数前一位减1，如果当前为第一位
				//前面已经没有数字，那么反过来，减数减去被减数,_Negative=1
				if (i == 0)
				{
					//当前已经是0位置，那么不能再往前借了
					int _Ans_ = _Char_To_Int(Num_1[0]) - _Char_To_Int(Num_2[0]) - _Carry;
					_Carry = 0;
					if (_Ans_ >= 0)
					{
						_Res_Num = _INT_TO_Char(_Ans_) + _Res_Num;
					}
					else{
						_Negative = true;
					}
					goto _End_;
				}
				else
				{
					//不是第一位，那么就可以借
					if (_Char_To_Int(Num_1[i]) - _Carry < _Char_To_Int(Num_2[i]))
					{
						_Res_Num = _INT_TO_Char(_Char_To_Int(Num_1[i]) + 10 - _Char_To_Int(Num_2[i]) - _Carry) + _Res_Num;
						_Carry = 1;
					}
					else
					{
						_Res_Num = _INT_TO_Char(_Char_To_Int(Num_1[i]) - _Char_To_Int(Num_2[i]) - _Carry) + _Res_Num;
						_Carry = 0;
					}
				}
			}
		_End_:
			_Res_Num = _INT_TO_String(_String_To_Int(_Res_Num));
			if (_Negative)
			{
				_Res_Num = '-' + _Res_Num;
			}
			return _Res_Num;
		}
		else if (_Your_operator == '*' || _Your_operator == 'x')
		{
			//做乘法
			return _Big_Interger_Multiplication(Num_1, Num_2);
		}
	}

	/*
	* 分组号：001_5
	* 函数名字：HEX_Decimal_To_Binary
	* 描述：该函数可以将十进制转换为二进制
	*/
	string HEX_Decimal_To_Binary(int _Num_)
	{
		string _Binary_Code = "";
		while (_Num_ != 0)
		{
			_Binary_Code = _INT_TO_Char(_Num_ % 2) + _Binary_Code;
			_Num_ /= 2;
		}
		return _Binary_Code;
	}

	/*
	* 分组号：001_6
	* 函数名字：HEX_Binary_To_Decimal
	* 描述：该函数可以将二进制转换为十进制
	*/
	int HEX_Binary_To_Decimal(string _Binary_Code)
	{
		int Decimal_Num = 0;
		int _Pow_idex = 0;
		_Re_For(i, _Binary_Code.length() - 1)
		{
			Decimal_Num += _Char_To_Int(_Binary_Code[i])*pow(2.0, _Pow_idex++);
		}
		return Decimal_Num;
	}

	/*
	* 分组号：001_7
	* 函数名字：HEX_Decimal_To_Octal
	* 描述：该函数可以将十进制转换为八进制
	*/
	string HEX_Decimal_To_Octal(int _Num_)
	{
		string _Octal_Str = "";
		while (_Num_ != 0)
		{
			_Octal_Str = _INT_TO_Char(_Num_ % 8) + _Octal_Str;
			_Num_ /= 8;
		}
		return _Octal_Str;
	}

	/*
	* 分组号：001_8
	* 函数名字：HEX_Octal_To_Decimal
	* 描述：该函数可以将八进制转换为十进制
	*/
	int HEX_Octal_To_Decimal(string _Oct_Str)
	{
		int _Decimal_Num = 0;
		int _Pos_idex = 0;
		_Re_For(i, _Oct_Str.length() - 1)
		{
			_Decimal_Num += _Char_To_Int(_Oct_Str[i])*pow(8.0, _Pos_idex++);
		}
		return _Decimal_Num;
	}

	/*
	* 分组号：001_9
	* 函数名字：HEX_Decimal_To_Hexadecimal
	* 描述：该函数可以将十进制转换为十六进制
	*/
	string HEX_Decimal_To_Hexadecimal(int _Num_)
	{
		string _Table_Str = "0123456789ABCDF";
		string _Hexadecimal_Code = "";
		while (_Num_ != 0)
		{
			int _Temp_Num = _Num_ % 16;
			_Hexadecimal_Code = _Table_Str[_Temp_Num] + _Hexadecimal_Code;
			_Num_ /= 16;
		}
		return _Hexadecimal_Code;
	}

	/*
	* 分组号：001_10
	* 函数名字：HEX_Hexadecimal_To_Decimal
	* 描述：该函数可以将十六进制转换为十进制
	*/
	int HEX_Hexadecimal_To_Decimal(string _Hexadecimal_Str)
	{
		int _Decimal_Num = 0;
		int _Pos_idex = 0;
		//有可能传进来的参数中是小写字母
		//还有可能是大写字母，所以都要考虑
		_Re_For(i, _Hexadecimal_Str.length() - 1)
		{
			if (_Hexadecimal_Str[i] >= '0'&&_Hexadecimal_Str[i] <= '9')
			{
				_Decimal_Num += _Char_To_Int(_Hexadecimal_Str[i])*pow(16.0, _Pos_idex++);
			}
			else if (_Hexadecimal_Str[i] >= 'a'&&_Hexadecimal_Str[i] <= 'z')
			{
				_Decimal_Num += (int)(_Hexadecimal_Str[i] - 'a' + 10)*pow(16.0, _Pos_idex++);
			}
			else if (_Hexadecimal_Str[i] >= 'A'&&_Hexadecimal_Str[i] <= 'Z')
			{
				_Decimal_Num += (int)(_Hexadecimal_Str[i] - 'A' + 10)*pow(16.0, _Pos_idex++);
			}
		}
		return _Decimal_Num;
	}


	/*
	* 分组号：001_11
	* 函数名字：Original_Code
	* 描述：求一个数字的原码
	* 备注：需要指定所有的长度
	*/
	string Original_Code(int _Num_, int _Code_Length)
	{
		bool _Negative = false;
		if (_Num_ < 0) _Negative = true;
		_Num_ = abs(_Num_);
		string _Original_code = HEX_Decimal_To_Binary(_Num_);
		if (_Code_Length < _Original_code.length() + 1)
		{
			cerr << "Error!" << endl;
			return "";
		}
		else{
			int _Zero_Length = _Code_Length - _Original_code.length() - 1;
			string _Zero_Code(_Zero_Length, '0');
			_Original_code = _Zero_Code + _Original_code;
		}
		if (_Negative == true)
		{
			_Original_code = '1' + _Original_code;
		}
		else{
			_Original_code = '0' + _Original_code;
		}
		return _Original_code;
	}

	/*
	* 分组号：001_12
	* 函数名字：Oppostion_Code
	* 描述：求一个数字的反码
	* 备注：需要指定所有的长度
	*/
	string Oppostion_Code(int _Num_, int _Code_Length)
	{
		string _Oppostion_code = Original_Code(_Num_, _Code_Length);
		if (_Num_ < 0){
			for (int i = 1; i < _Oppostion_code.length(); i++)
			{
				if (_Oppostion_code[i] == '0')
				{
					_Oppostion_code[i] = '1';
				}
				else{
					_Oppostion_code[i] = '0';
				}
			}
		}
		return _Oppostion_code;
	}

	/*
	* 分组号：001_13
	* 函数名字：Complement_Code
	* 描述：求一个数字的补码
	* 备注：需要指定所有的长度
	*/
	string Complement_Code(int _Num_, int _Code_Length)
	{
		string _complement_code = Original_Code(_Num_, _Code_Length);
		if (_Num_ < 0)
		{
			bool _Start_opp = false;
			int _Start_idex = -1;
			for (_Start_idex = _complement_code.length() - 1;
				_complement_code[_Start_idex] != '1'; _Start_idex--);
				_Start_idex--;
			for (int i = _Start_idex; i >= 1; i--)
			{
				if (_complement_code[i] == '0')
				{
					_complement_code[i] = '1';
				}
				else{
					_complement_code[i] = '0';
				}
			}
		}
		return _complement_code;
	}
}/*end of namespace NUMBER*/
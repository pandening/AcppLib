#include "Header.h"

namespace MATH
{
	/*
	 * 编号：003_1
	 * 函数名：_Random_Number
	 * 功能：生成指定大小和数量的随机数
	 * 备注：要想得到不同边界的随机数，请去掉注释
	 */
	vector<int> _Random_Number(int _Left_, int _Right_, int _Num_)
	{
		vector<int> _Res_Num;
		srand((unsigned)time(NULL));
		_FOR_(i, _Num_)
		{
			_Res_Num.push_back(rand() % (_Right_ - _Left_ + 1) + _Left_);/* [_Left_,_Right_] */
			//_Res_Num.push_back(rand() % (_Right_ - _Left_) + _Left_);  /* [_Left_,_Right_) */
			//_Res_Num.push_back(rand() % (_Right_ - _Left_) + _Left_+1);/* (_Left_,_Right_]*/ 
		}
		return _Res_Num;
	}

	/*
	* 编号：003_2
	* 函数名：Average
	* 功能：对于给定的数据，求出数据集合的平均数
	* 备注：如果将flag标记设为true的话，将去掉一个最大值和一个最小值
	*/
	template<class _Type_>double Average(_Type_* _Dest_Set, int _Size, bool _Flag)
	{
		_Type_ _Sum = 0;
		_FOR_(i, _Size)
		{
			_Sum += _Dest_Set[i];
		}
		if (_Flag == true)
		{
			if (_Size <= 2)
			{
				cout << "Error!" << endl;
				return 0x7fffffff;
			}
			int _Min_ = 0x7fffffff, _Max_ = -0x7fffffff;
			_FOR_(i, _Size)
			{
				if (_Dest_Set[i] > _Max_)
				{
					_Max_ = _Dest_Set[i];
				}
				if (_Dest_Set[i] < _Min_)
				{
					_Min_ = _Dest_Set[i];
				}
			}
			_Sum -= (_Max_ + _Min_);
			return (double)(_Sum / (_Size - 2));
		}
		return (double)(_Sum / _Size);
	}

	/*
	* 编号：003_3
	* 函数名：Median
	* 功能：对于给定的数据，求出其中位数
	*/
	template<class _Type_> double Median(_Type_* _Dest_Set, int _Size)
	{
		if (_Size % 2 != 0)
		{
			return _Dest_Set[_Size / 2];
		}
		else{
			return double(_Dest_Set[_Size / 2 - 1] + _Dest_Set[_Size / 2]) / 2;
		}
	}

	/*
	* 编号：003_4
	* 函数名：_Min_One
	* 功能：对于给定的数据，求出其最小数
	*/
	template<class _Type_> _Type_ _Min_One(_Type_* _Dest_Set, int _Size)
	{
		sort(_Dest_Set, _Dest_Set + _Size);
		return _Dest_Set[0];
	}

	/*
	* 编号：003_4
	* 函数名：_Max_One
	* 功能：对于给定的数据，求出其最大数
	*/
	template<class _Type_> _Type_ _Max_One(_Type_* _Dest_Set, int _Size)
	{
		sort(_Dest_Set, _Dest_Set + _Size);
		return _Dest_Set[_Size - 1];
	}

	/*
	* 编号：003_5
	* 函数名：Split_Integer
	* 功能：将一个数字拆分为各位
	* 备注：为了获得结果，请从下标0开始访问
	*/
	vector<int> Split_Integer(int _Dest_Num)
	{
		vector<int> _Res_Vec;
		while (_Dest_Num != 0)
		{
			_Res_Vec.push_back(_Dest_Num % 10);
			_Dest_Num /= 10;
		}
		reverse(_Res_Vec.begin(), _Res_Vec.end());
		return _Res_Vec;
	}

	/*
	* 编号：003_6
	* 函数名：Is_Prime
	* 功能:判断一个数字是不是素数
	*/
	bool Is_Prime(int _Dest_Num)
	{
		if (_Dest_Num == 1) return false;
		if (_Dest_Num == 2) return true;
		for (int i = 2; i*i <= _Dest_Num; i++)
		{
			if (_Dest_Num%i == 0)
			{
				return false;
			}
		}
		return true;
	}

	/*
	* 编号：003_7
	* 函数名：Prime
	* 功能:将获得一个指定范围内的素数表
	*/
	vector<int> Prime(int _Left_, int _Right_)
	{
		vector<int> _Res_Num;
		bool* _Sieve;
		_Sieve = new bool[_Right_ + 1];
		memset(_Sieve, false, sizeof(_Sieve));
		_Sieve[0] = true;
		_Sieve[1] = true;
		int _Idex = 0;
		for (int i = 0; i <= _Right_; i++)
		{
			if (_Sieve[i] == true)
			{
				continue;
			}
			else{
				if (i >= _Left_&&i <= _Right_)
					_Res_Num.push_back(i);
				for (int j = i*i; j <= _Right_; j += i)
				{
					_Sieve[j] = true;
				}
			}
		}
		return _Res_Num;
	}

	/*
	* 编号：003_8
	* 函数名：_GCD
	* 功能:求出两个数字的最大公约数
	*/
	int _GCD(int _Num_1, int _Num_2)
	{
		if (_Num_1 < _Num_2) swap(_Num_1, _Num_2);
		if (_Num_2 == 0) return _Num_1;
		return _GCD(_Num_2, _Num_1%_Num_2);
	}

	/*
	* 编号：003_9
	* 函数名：_LCM
	* 功能:求出两个数字的最小公倍数
	*/
	int _LCM(int _Num_1, int _Num_2)
	{
		return (_Num_1*_Num_2) / _GCD(_Num_1, _Num_2);
	}

	/*
	* 编号：003_10
	* 函数名：_Simplest_fraction
	* 功能:将给定的一个分数化为最简
	* 备注：_Molecular为分子，_Denominator为分母
	*/
	pair<int, int> _Simplest_fraction(int _Molecular, int _Denominator)
	{
		int _gcd = _GCD(_Molecular, _Denominator);
		_Molecular /= _gcd;
		_Denominator /= _gcd;
		pair<int, int> _Res_pair(_Molecular, _Denominator);
		return _Res_pair;
	}

	/*
	* 编号：003_11
	* 函数名：_Decimal_To_fraction
	* 功能:给定一个小数，将它化为最简分数
	* 备注：为了快速计算，请输入小数点后面的有效位长度
	*/
	pair<int, int> _Decimal_To_fraction(double _Dest_Decimal, int _Decimal_Length)
	{
		int _Mole, _Deno;
		_Mole = pow(10.0, _Decimal_Length)*_Dest_Decimal;
		_Deno = pow(10.0, _Decimal_Length);
		pair<int, int> _Res_pair;
		_Res_pair = _Simplest_fraction(_Mole, _Deno);
		return _Res_pair;
	}


	/*
	* 编号：003_12
	* 函数名：_Quick_Pow
	* 功能:快速冥运算
	* 备注：为了计算安全，请提供取模数_Mod_Num，默认请使用_Mod_Num=0x7fffffff
	*/
	L_L _Quick_Pow(L_L _Base_Num, L_L _Pow_Num, L_L _Mod_Num)
	{
		L_L _Res_Num = 1;
		while (_Pow_Num != 0)
		{
			if (_Pow_Num & 1)
			{
				_Res_Num = (_Res_Num*_Base_Num + _Mod_Num) % _Mod_Num;
			}
			_Base_Num = (_Base_Num*_Base_Num + _Mod_Num) % _Mod_Num;
			_Pow_Num >>= 1;
		}
		return _Res_Num;
	}

	/*
	* 编号：003_13
	* 函数名：_Matrix_Add
	* 功能:给定两个矩阵，计算和
	* 备注：请提供矩阵的行和列数
	*/
	template<class _Type_>
	_Type_**  _Matrix_Add(_Type_** _Matrix_A, _Type_** _Matrix_B,
		int _Rows, int _Columns)
	{
		_Type_** _Res_Mat;
		_Res_Mat = new _Type_*[_Rows];
		_FOR_(i, _Rows)
			_Res_Mat[i] = new _Type_[_Columns];
		_FOR_(i, _Rows)_FOR_(j, _Columns)
			_Res_Mat[i][j] = _Matrix_A[i][j] + _Matrix_B[i][j];
		return _Res_Mat;
	}

	/*
	* 编号：003_14
	* 函数名：_Matrix_Mul
	* 功能:给定两个矩阵，计算乘积
	* 备注：请提供矩阵的行和列数
	*/
	template<class _Type_>
	_Type_**  _Matrix_Mul(_Type_** _Matrix_A, _Type_** _Matrix_B,
		int _Rows_Matrix_A, int _Columns_Matrix_A,
		int _Rows_Matrix_B, int _Columns_Matrix_B)
	{
		if (_Columns_Matrix_A != _Rows_Matrix_A)
		{
			cout << "Error!!" << endl;
			exit(0);
		}
		_Type_** _Res_Mat;
		_Res_Mat = new _Type_*[_Rows_Matrix_A];
		_FOR_(i, _Rows_Matrix_A)
			_Res_Mat[i] = new _Type_[_Columns_Matrix_B];
		_FOR_(i, _Rows_Matrix_A)
			_FOR_(j, _Columns_Matrix_B)
			_Res_Mat[i][j] = 0;
		_FOR_(i, _Rows_Matrix_A)
			_FOR_(k, _Columns_Matrix_A)
			_FOR_(j, _Columns_Matrix_B)
			_Res_Mat[i][j] += (_Matrix_A[i][k] * _Matrix_B[k][j]);
		return _Res_Mat;
	}

	/*
	* 编号：003_15
	* 函数名：_Matrix_Pow
	* 功能:求矩阵的冥
	* 备注：请提供矩阵的行和列数
	*/
	template<class _Type_>
	_Type_**  _Matrix_Pow(_Type_** _Matrix_Base, int _Pow,
		int _Rows, int _Columns)
	{
		_Type_ **_Pow_Base_matrix;
		_Pow_Base_matrix = new _Type_*[_Rows];
		_FOR_(i, _Rows)
			_Pow_Base_matrix[i] = new _Type_[_Columns];

		_FOR_(i, _Rows)
			_FOR_(j, _Columns)
		if (i == j){
			_Pow_Base_matrix[i][j] = 1;
		}
		else{
			_Pow_Base_matrix[i][j] = 0;
		}
		while (_Pow != 0)
		{
			if (_Pow & 1){
				_Pow_Base_matrix = _Matrix_Mul(_Pow_Base_matrix, _Matrix_Base
					, _Rows, _Columns, _Rows, _Columns);
			}
			_Matrix_Base = _Matrix_Mul(_Matrix_Base, _Matrix_Base, _Rows, _Columns
				, _Rows, _Columns);
			_Pow >>= 1;
		}
		return _Pow_Base_matrix;
	}

	/*
	* 编号：003_16
	* 函数名：Gauss_Elimination
	* 功能:用高斯消元求解方程组，输入增广矩阵
	*/
	template<class _Type_>
	_Type_**  Gauss_Elimination(_Type_** _Matrix, int _N_)
	{
		for (int k = 1; k < _N_; k++)
		{
			for (int i = k; i < _N_; i++)
			{
				double _Temp_action = -_Matrix[i][k - 1] / _Matrix[k - 1][k - 1];
				for (int j = k - 1; j <= _N_; j++)
				{
					_Matrix[i][j] += (_Matrix[k - 1][j] * _Temp_action);
				}
			}
		}
		double* _Res_Num;
		_Res_Num = new double[_N_];
		_Res_Num[_Rows - 1] = _Matrix[_N_ - 1][_N_] / _Matrix[_N_ - 1][_N_ - 1];
		for (int i = _N_ - 2; i >= 0; i--)
		{
			for (int p = _N_ - 1; p > i; p--)
			{
				_Matrix[i][_N_] -= _Res_Num[p] * _Matrix[i][p];
			}
			_Res_Num[i] = _Matrix[i][_N_] / _Matrix[i][i];
		}
		return _Res_Num;
	}

	/*
	* 编号：003_17
	* 函数名：_De_Number
	* 功能:将一个合数分解为多个素数之积
	*/
	vector<int> _De_Number(int _Dest_Num)
	{
		vector<int> _Res_Num;
		if (Is_Prime(_Dest_Num))
		{
			_Res_Num.push_back(_Dest_Num);
			return _Res_Num;
		}
		int _split_I = 2;
		while (true)
		{
			if (_Dest_Num%_split_I == 0)
			{
				_Res_Num.push_back(_split_I);
				if (Is_Prime(_Dest_Num /= _split_I))
				{
					_Res_Num.push_back(_Dest_Num);
					break;
				}
			}
			else{
				_split_I++;
			}
		}
		return _Res_Num;
	}
}/*end of math*/
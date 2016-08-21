#include "Header.h"

namespace MATH
{
	/*
	 * ��ţ�003_1
	 * ��������_Random_Number
	 * ���ܣ�����ָ����С�������������
	 * ��ע��Ҫ��õ���ͬ�߽�����������ȥ��ע��
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
	* ��ţ�003_2
	* ��������Average
	* ���ܣ����ڸ��������ݣ�������ݼ��ϵ�ƽ����
	* ��ע�������flag�����Ϊtrue�Ļ�����ȥ��һ�����ֵ��һ����Сֵ
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
	* ��ţ�003_3
	* ��������Median
	* ���ܣ����ڸ��������ݣ��������λ��
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
	* ��ţ�003_4
	* ��������_Min_One
	* ���ܣ����ڸ��������ݣ��������С��
	*/
	template<class _Type_> _Type_ _Min_One(_Type_* _Dest_Set, int _Size)
	{
		sort(_Dest_Set, _Dest_Set + _Size);
		return _Dest_Set[0];
	}

	/*
	* ��ţ�003_4
	* ��������_Max_One
	* ���ܣ����ڸ��������ݣ�����������
	*/
	template<class _Type_> _Type_ _Max_One(_Type_* _Dest_Set, int _Size)
	{
		sort(_Dest_Set, _Dest_Set + _Size);
		return _Dest_Set[_Size - 1];
	}

	/*
	* ��ţ�003_5
	* ��������Split_Integer
	* ���ܣ���һ�����ֲ��Ϊ��λ
	* ��ע��Ϊ�˻�ý��������±�0��ʼ����
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
	* ��ţ�003_6
	* ��������Is_Prime
	* ����:�ж�һ�������ǲ�������
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
	* ��ţ�003_7
	* ��������Prime
	* ����:�����һ��ָ����Χ�ڵ�������
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
	* ��ţ�003_8
	* ��������_GCD
	* ����:����������ֵ����Լ��
	*/
	int _GCD(int _Num_1, int _Num_2)
	{
		if (_Num_1 < _Num_2) swap(_Num_1, _Num_2);
		if (_Num_2 == 0) return _Num_1;
		return _GCD(_Num_2, _Num_1%_Num_2);
	}

	/*
	* ��ţ�003_9
	* ��������_LCM
	* ����:����������ֵ���С������
	*/
	int _LCM(int _Num_1, int _Num_2)
	{
		return (_Num_1*_Num_2) / _GCD(_Num_1, _Num_2);
	}

	/*
	* ��ţ�003_10
	* ��������_Simplest_fraction
	* ����:��������һ��������Ϊ���
	* ��ע��_MolecularΪ���ӣ�_DenominatorΪ��ĸ
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
	* ��ţ�003_11
	* ��������_Decimal_To_fraction
	* ����:����һ��С����������Ϊ������
	* ��ע��Ϊ�˿��ټ��㣬������С����������Чλ����
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
	* ��ţ�003_12
	* ��������_Quick_Pow
	* ����:����ڤ����
	* ��ע��Ϊ�˼��㰲ȫ�����ṩȡģ��_Mod_Num��Ĭ����ʹ��_Mod_Num=0x7fffffff
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
	* ��ţ�003_13
	* ��������_Matrix_Add
	* ����:�����������󣬼����
	* ��ע�����ṩ������к�����
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
	* ��ţ�003_14
	* ��������_Matrix_Mul
	* ����:�����������󣬼���˻�
	* ��ע�����ṩ������к�����
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
	* ��ţ�003_15
	* ��������_Matrix_Pow
	* ����:������ڤ
	* ��ע�����ṩ������к�����
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
	* ��ţ�003_16
	* ��������Gauss_Elimination
	* ����:�ø�˹��Ԫ��ⷽ���飬�����������
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
	* ��ţ�003_17
	* ��������_De_Number
	* ����:��һ�������ֽ�Ϊ�������֮��
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
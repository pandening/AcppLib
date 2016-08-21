#include "Header.h"

/*数据结构库*/
namespace DATA
{
/*
   编号：004_1
   名字：Sq_List
   描述：该类属于线性表类
*/
template<class _Type,int _Max_Size>class Sq_List
{
public:
	_Type _Data[_Max_Size];
	int _Sq_Length;
	Sq_List()
	{
		_Sq_Length = 0;
	}


	//在尾部加上元素
	void _Append_Element(_Type _Element)
	{
		_Data[_Sq_Length++] = _Element;
	}

	//返回指定位置上的值
	_Type _Get_Element(int _Dest_Idex)
	{
		if (_Dest_Idex<0 || _Dest_Idex>_Sq_Length)
		{
			cout << "Error!!" << endl;
			return -0x7fffffff;
		}
		return _Data[_Dest_Idex];
	}

	//返回第一个等于给定值的位置，如果返回0，则不存在
	int _Locate_Element(_Type _Dest_Element)
	{
		int _Res_Idex =0;
		while (_Res_Idex < _Sq_Length&&_Data[_Res_Idex] != _Dest_Element){
			_Res_Idex++;
		}
		if (_Res_Idex>_Sq_Length)
		{
			return -1;
		}
		return _Res_Idex;
	}

	//在指定位置插入值
	bool _Insert_Element(int _Dest_Idex, _Type _Dest_Element)
	{
		if (_Dest_Idex<0 || _Dest_Idex>_Sq_Length)
		{
			return false;
		}
		for (int i = _Sq_Length; i >=_Dest_Idex; i--)
		{
			_Data[i] = _Data[i - 1];
		}
		_Data[_Dest_Idex] = _Dest_Element;
		return true;
	}

	//删除指定位置上的值
	bool _Delete_Element(int _Dest_Idex)
	{
		if (_Dest_Idex<0 || _Dest_Idex>_Sq_Length)
		{
			return false;
		}
		for (int i = _Dest_Idex; i < _Sq_Length; i++)
		{
			_Data[i] = _Data[i + 1];
		}
		_Sq_Length--;
		return true;
	}

	//判断是不是存在某个值
	bool _Exist_Element(_Type _Dest_Element)
	{
		for (int i = 0; i <_Sq_Length; i++)
		{
			if (_Data[i] == _Dest_Element)
			{
				return true;
			}
		}
		return false;
	}

	//删除某个指定值
	bool _Delete_Element_By_Element(_Type _Dest_Element)
	{
		if (!_Exist_Element(_Dest_Element))
		{
			return false;
		}
		while (_Exist_Element(_Dest_Element) == true)
		{
			int _Idex = _Locate_Element(_Dest_Element);
			_Delete_Element(_Idex);
		}
		return true;
	}

	//有序表的归并，将两张有序的表归并成一张有序表
	//将结果返回为一个新的顺序表
	Sq_List _Merge_Sq(Sq_List _Dest_Sq)
	{
		Sq_List _Res_Sq;
		int _Idex_Souce = 0;
		int _Idex_Dest = 0;
		while (_Idex_Dest < _Dest_Sq._Sq_Length&&_Idex_Souce < _Sq_Length)
		{
			if (_Data[_Idex_Souce] < _Dest_Sq._Data[_Idex_Dest])
			{
				_Res_Sq._Data[_Res_Sq._Sq_Length++] = _Data[_Idex_Souce++];
			}
			else if (_Dest_Sq._Data[_Idex_Dest] < _Data[_Idex_Souce])
			{
				_Res_Sq._Data[_Res_Sq._Sq_Length++] = _Dest_Sq._Data[_Idex_Dest++];
			}
			else if(_Dest_Sq._Data[_Idex_Dest]==_Data[_Idex_Souce]){
				_Res_Sq._Data[_Res_Sq._Sq_Length++] = _Dest_Sq._Data[_Idex_Dest++];
			}
		}
		while (_Idex_Dest < _Dest_Sq._Sq_Length)
		{
			_Res_Sq._Data[_Res_Sq._Sq_Length++] = _Dest_Sq._Data[_Idex_Dest++];
		}
		while (_Idex_Souce < _Sq_Length)
		{
			_Res_Sq._Data[_Res_Sq._Sq_Length++] = _Data[_Idex_Souce++];
		}
		return _Res_Sq;
	}

	//将顺序表的元素逆转
	void _Reverse_Sq()
	{
		int _Idex;
		_Type _Element;
		for (int i = 0; i < _Sq_Length / 2; i++)
		{
			_Element = _Data[i];
			_Data[i] = _Data[_Sq_Length - 1 - i];
			_Data[_Sq_Length - 1 - i] = _Element;
		}
	}

	//求两个顺序表的交集
	Sq_List _Intersection_sq(Sq_List _Dest_sq)
	{
		Sq_List _Res_Sq;
		_Res_Sq._Sq_Length = 0;
		int _idex_souce;
		int _idex_dest;
		for (_idex_souce = 0; _idex_souce < _Sq_Length; _idex_souce++)
		{
			_idex_dest = 0;
			while (_idex_dest < _Dest_sq._Sq_Length&&_Data[_idex_souce] !=
				_Dest_sq._Data[_idex_dest])
			{
				_idex_dest++;
			}
			if (_idex_dest < _Dest_sq._Sq_Length)
			{
				_Res_Sq._Data[_Res_Sq._Sq_Length++] = _Data[_idex_souce];
			}
		}
		return _Res_Sq;
	}

	//求两个顺序表的并集
	Sq_List _Union_Sq(Sq_List _Dest_Sq)
	{
		Sq_List _Res_Sq;
		int _idex_souce;
		int _idex_dest;
		for (_idex_souce = 0; _idex_souce < _Sq_Length; _idex_souce++)
		{
			_Res_Sq._Data[_Res_Sq._Sq_Length++] = _Data[_idex_souce];
		}
		//对于_Dest_Sq，如果其中的元素已经存在于_Res_Sq中
		//那么久没必要再复制过去了，所以，只要判断是否存在就可以了
		for (_idex_dest = 0; _idex_dest < _Dest_Sq._Sq_Length; _idex_dest++)
		{
			bool _Ans_Idex = _Res_Sq._Exist_Element(_Dest_Sq._Data[_idex_dest]);
			if (_Ans_Idex==false)
			{
				//说明还不存在，那么就复制过来
				_Res_Sq._Data[_Res_Sq._Sq_Length++] = _Dest_Sq._Data[_idex_dest];
			}
		}
		return _Res_Sq;
	}

	//求两个顺序表的差集
	void _Diffence_Sq(Sq_List _Dest_sq)
	{
		int _idex_souce;
		int _idex_dest;
			for (_idex_dest = 0; _idex_dest < _Dest_sq._Sq_Length; _idex_dest++)
			{
				bool _idex_ = _Exist_Element(_Dest_sq._Data[_idex_dest]);
				if (_idex_==true)
				{
					_Delete_Element_By_Element(_Dest_sq._Data[_idex_dest]);
				}
			}
	}
	//将元素打印出来
	void _Print_Element()
	{
		_FOR_(i, _Sq_Length)
		{
			cout << _Data[i] << " ";
		}
		cout << endl;
	}
};

/*
  编号：004_2
  名字：Link_List
  描述：该类为单链表类
*/
template<class _Type> class Link_List
{
public:
	_Type _Element_Data;
	Link_List* _Next_pointer;
	int _Element_Length;
	Link_List* Head_pointer;

	Link_List()
	{
		Head_pointer = NULL;
		_Element_Length = 0;
	}
	
	//返回链表的大小
	int _Size_()
	{
		return _Element_Length;
	}
	//创建新链表，新节点接在头结点，返回头结点
	Link_List* Create_List_front(_Type* _Add_Element,int _Size)
	{
		Link_List* _Head_Pointer = new Link_List;
		_Head_Pointer->_Next_pointer =NULL;
		_Head_Pointer->_Element_Data = _Add_Element[0];
		_Element_Length+=_Size;
		for (int i = 1; i < _Size; i++)
		{
			Link_List* _Temp_pointer = new Link_List;
			_Temp_pointer->_Next_pointer = _Head_Pointer;
			_Temp_pointer->_Element_Data = _Add_Element[i];
			_Head_Pointer = _Temp_pointer;
		}
		return _Head_Pointer;
	}

	//创建一个新链表，新节点接在尾节点，返回头结点
	Link_List* Creat_List_Back(_Type* _Add_Element, int _Size)
	{
		Link_List* _Head_Pointer, *_Tail_Pointer;
		_Head_Pointer = new Link_List;
		_Tail_Pointer = new Link_List;
		_Element_Length += _Size;
		_Head_Pointer->_Element_Data = _Add_Element[0];
		//this is very important!!
		_Tail_Pointer = _Head_Pointer;
		_Tail_Pointer->_Next_pointer = NULL; 
		for (int i = 1; i < _Size; i++)
		{
			Link_List* _Temp_pointer=new Link_List;
			_Temp_pointer->_Element_Data = _Add_Element[i];
			_Temp_pointer->_Next_pointer = NULL;
			_Tail_Pointer->_Next_pointer = _Temp_pointer;
			_Tail_Pointer = _Temp_pointer;
		}
		return _Head_Pointer;
	}

	//判断这个链表中是否存在值为指定值的结点，如果有，返回节点位置，如果没有，返回-1
	//仅返回第一个等于指定值的节点的下标，如果有多个需要特别处理
	int _Exist_And_Idex(_Type _Dest_Data)
	{
		Link_List* _Find_Pointer = new Link_List;
		_Find_Pointer = Head_pointer;
		int _Res_Idex = 0;
		while (_Find_Pointer != NULL&&_Find_Pointer->_Element_Data != _Dest_Data)
		{
			_Find_Pointer = _Find_Pointer->_Next_pointer;
			_Res_Idex++;
		}
		if (_Res_Idex==_Element_Length)
		{
			return -1;
		}
		else{
			return _Res_Idex;
		}
	}

	//在指定的位置上插入一个节点,返回头结点
	//备注：这个新插入的节点将始终放在目标位置之前
	//对于将新的节点插入在目标位置之后，可以模仿此函数，不再赘述
	Link_List* _Insert_Node(int _Dest_Idex, _Type _Dest_Data)
	{
		if (_Dest_Idex>=_Element_Length)
		{
			cout << "Error!!" << endl;
			return Head_pointer;
		}
		//if the head pointer is null,then create it first
		if (Head_pointer == NULL)
		{
			Head_pointer->_Element_Data = _Dest_Data;
			Head_pointer->_Next_pointer = NULL;
			_Element_Length++;
		}
		if (_Dest_Idex == 0)
		{
			//this new pointer will be the new header pointer
			Link_List* _New_Header_pointer = new Link_List;
			_New_Header_pointer->_Element_Data = _Dest_Data;
			_New_Header_pointer->_Next_pointer = Head_pointer;
			Head_pointer = _New_Header_pointer;
			_Element_Length++;
			return Head_pointer;
		}

		//then ,the head pointer is existed
		Link_List *_Pre_pointer, *_Cur_pointer;
		_Pre_pointer = new Link_List;
		_Cur_pointer = new Link_List;
		_Cur_pointer = Head_pointer;
		_Pre_pointer = NULL;
		int _Counter = 0;
		while (_Counter != _Dest_Idex)
		{
			_Counter++;
			_Pre_pointer = _Cur_pointer;
			_Cur_pointer = _Cur_pointer->_Next_pointer;
		}
		Link_List* _Insert_pointer = new Link_List;
		_Insert_pointer->_Element_Data = _Dest_Data;
		_Insert_pointer->_Next_pointer = NULL;
		_Insert_pointer->_Next_pointer = _Cur_pointer;
		_Pre_pointer->_Next_pointer = _Insert_pointer;
		_Element_Length++;
		return Head_pointer;
	}

	//删除指定位置上的节点,返回头结点
	Link_List* _Delete_Node(int _Dest_Idex)
	{
		if (_Dest_Idex >= _Element_Length)
		{
			cout << "Error!!" << endl;
			return Head_pointer;
		}
		//如果要删除头结点，那么就要重新找到一个头结点
		if (_Dest_Idex == 0)
		{
			Link_List* _Delete_pointer = new Link_List;
			_Delete_pointer = Head_pointer;
			Head_pointer = _Delete_pointer->_Next_pointer;
			_Element_Length--;
			delete _Delete_pointer;
			return Head_pointer;
		}
		Link_List *_Pre_pointer, *_Cur_pointer;
		_Pre_pointer = new Link_List;
		_Cur_pointer = new Link_List;
		_Pre_pointer = NULL;
		_Cur_pointer = Head_pointer;
		int _Delete_Idex = 0;
		while (_Delete_Idex != _Dest_Idex)
		{
			_Delete_Idex++;
			_Pre_pointer = _Cur_pointer;
			_Cur_pointer = _Cur_pointer->_Next_pointer;
		}
		_Pre_pointer->_Next_pointer = _Cur_pointer->_Next_pointer;
		_Element_Length--;
		delete _Cur_pointer;
		return Head_pointer;
	}
	//统计链表中指定值的数量
	int _Count_Element(_Type _Dest_Data)
	{
		int _Res_Num = 0;
		if (_Exist_And_Idex(_Dest_Data) == -1)
		{
			return 0;
		}
		Link_List *_Counter_pointer = new Link_List;
		_Counter_pointer = Head_pointer;
		while (_Counter_pointer!= NULL)
		{
			if (_Counter_pointer->_Element_Data == _Dest_Data){
				_Res_Num++;
			}
			_Counter_pointer = _Counter_pointer->_Next_pointer;
		}
		return _Res_Num;
	}
	//一个将数组反转过来的函数
	_Type* _Reverse_Array(_Type* _Dest_Array,int _Array_size)
	{
		for (int i = 0; i < _Array_size / 2; i++)
		{
			_Type _Temp_Data = _Dest_Array[i];
			_Dest_Array[i] = _Dest_Array[_Array_size - 1 - i];
			_Dest_Array[_Array_size - 1 - i] = _Temp_Data;
		}
		return _Dest_Array;
	}
	//给链表排序，如果想要从大到小排序，请将_Flag_参数置0，否则置1
	//函数运行结束将返回头结点，内存爆炸等后果自负（保证输入规模适合即可）
	Link_List* _Sort_Link_list(bool _Flag_)
	{
		_Type *_Temp_Array;
		_Temp_Array = new _Type[_Element_Length];
		Link_List* _Move_pointer = new Link_List;
		int _Move_Idex = 0;
		_Move_pointer = Head_pointer;
		while (_Move_pointer != NULL)
		{
			_Temp_Array[_Move_Idex++] = _Move_pointer->_Element_Data;
			_Move_pointer = _Move_pointer->_Next_pointer;
		}
		sort(_Temp_Array, _Temp_Array + _Element_Length);
		if (_Flag_ == false) _Temp_Array = _Reverse_Array(_Temp_Array, _Element_Length);
		Head_pointer = Creat_List_Back(_Temp_Array,_Move_Idex);
		delete[] _Temp_Array;
		return Head_pointer;
	}
	//返回在指定大小区间内的节点数量[_Left_Data,_Right_Data]
	//为了返回正确的值，请保证输入区间合法,返回-1表示出错
	int _Section_Size(_Type _Left_Data, _Type _Right_Data)
	{
		if (_Left_Data > _Right_Data)
		{
			return -1;
		}
		int _Res_Num = 0;
		Head_pointer = _Sort_Link_list(true);
		Link_List* _Counter_pointer = new Link_List;
		_Counter_pointer = Head_pointer;
		while (_Counter_pointer != NULL)
		{
			if (_Counter_pointer->_Element_Data >= _Left_Data&&
				_Counter_pointer->_Element_Data <= _Right_Data)
			{
				_Res_Num++;
			}
			if (_Counter_pointer->_Element_Data > _Right_Data)
			{
				break;
			}
			_Counter_pointer = _Counter_pointer->_Next_pointer;
		}
		return _Res_Num;
	}
	//反转链表,返回头结点
	Link_List* _Reverse_Link_list()
	{
		_Type* _Temp_Array;
		_Temp_Array = new _Type[_Element_Length];
		Link_List* _Temp_pointer = new Link_List;
		_Temp_pointer = Head_pointer;
		int _Temp_Idex = 0;
		while (_Temp_pointer != NULL)
		{
			_Temp_Array[_Temp_Idex++] = _Temp_pointer->_Element_Data;
			_Temp_pointer = _Temp_pointer->_Next_pointer;
		}
		//way 1: boring
		//_Temp_Array = _Reverse_Array(_Temp_Array, _Element_Length);
		//Head_pointer = Creat_List_Back(_Temp_Array, _Temp_Idex);

		// way 2: you can choose it
		Head_pointer = Create_List_front(_Temp_Array, _Temp_Idex);
		delete[] _Temp_Array;
		return  Head_pointer;
	}
	//获取链表元素表，返回所有节点的元素值
	vector<_Type> _Get_All_Elements()
	{
		vector<_Type> _Res_Vec;
		Link_List *_Temp_pointer = new Link_List;
		_Temp_pointer = Head_pointer;
		while (_Temp_pointer != NULL)
		{
			_Res_Vec.push_back(_Temp_pointer->_Element_Data);
			_Temp_pointer = _Temp_pointer->_Next_pointer;
		}
		return _Res_Vec;
	}
	//返回最小值节点的值
	_Type _Min_Data()
	{
		if (Head_pointer == NULL)
		{
			return -0x7fffffff;
		}
		vector<_Type> _Data_Set = _Get_All_Elements();
		sort(_Data_Set.begin(), _Data_Set.end());
		return _Data_Set.front();
	}
	//返回最大值节点
	_Type _Max_Data()
	{
		if (Head_pointer == NULL)
		{
			return 0x7fffffff;
		}
		Head_pointer = _Sort_Link_list(false);
		return Head_pointer->_Element_Data;
	}
	//打印这个链表
	void _Print_Link_list()
	{
		Link_List* _Print_Pointr = new Link_List;
		_Print_Pointr = Head_pointer;
		while (_Print_Pointr != NULL)
		{
			cout << _Print_Pointr->_Element_Data << " ";
			_Print_Pointr = _Print_Pointr->_Next_pointer;
		}
		cout << endl;
	}
};

/*
  编号：004_3
  名字：Double_Link_List
  描述：双向链表类
*/
template<class _Type> class Double_Link_List
{
public:
	_Type _Element_Data;
	Double_Link_List* _Next_Pointer;
	Double_Link_List* _Pre_Pointer;
	int _Element_Size;
	//if you need a Tail pointer,you can append a Tail node by yourself
	Double_Link_List* _Header_Pointer;
	Double_Link_List()
	{
		//this is very important ,remember this point forever
		_Element_Size = 0;
		_Header_Pointer = NULL;
	}
	//返回链表的大小
	int _Size_()
	{
		return _Element_Size;
	}
	
	//新建一个链表，新的节点将追加在原链表的尾部,返回头结点
	Double_Link_List* _Create_Double_Link_List(_Type* _Element_Set,int _Size_Of_Set)
	{
		_Element_Size += _Size_Of_Set;
		Double_Link_List* _Tail_pointer = new Double_Link_List;
		Double_Link_List* _Head_pointer = new Double_Link_List;
		_Head_pointer->_Element_Data = _Element_Set[0];
		//this is important
		_Tail_pointer = _Head_pointer;
		_Tail_pointer->_Next_Pointer = NULL;
		for (int i = 1; i < _Size_Of_Set;i++)
		{
			Double_Link_List* _Append_Node = new Double_Link_List;
			_Append_Node->_Element_Data =_Element_Set[i];
			_Tail_pointer->_Next_Pointer = _Append_Node;
			_Append_Node->_Pre_Pointer = _Tail_pointer;
			_Tail_pointer = _Append_Node;
			_Tail_pointer->_Next_Pointer = NULL;
		}
		return _Head_pointer;
	}

	//判断某个值的节点是否存在
	//如果不存在，返回-1，否则返回第一次匹配成功的下标
	int _Exist_And_Idex(_Type _Find_Data)
	{
		if (_Header_Pointer == NULL)
		{
			return -1;
		}
		int _Res_Idex = 0;
		Double_Link_List* _Find_pointer = new Double_Link_List;
		_Find_pointer = _Header_Pointer;
		while (_Find_pointer != NULL&&_Find_pointer->_Element_Data != _Find_Data){
			_Res_Idex++;
			_Find_pointer = _Find_pointer->_Next_Pointer;
		}
		if (_Res_Idex == _Element_Size){
			return -1;
		}
		return _Res_Idex;
	}

	//在指定位置插入一个节点,返回头结点
	//这是链表类的通用插入算法，可以使用双链表的特性进行优化
	Double_Link_List* _Insert_Node_Before(_Type _Dest_Data, int _Dest_Idex)
	{
		if (_Dest_Idex >_Element_Size)
		{
			return _Header_Pointer;
		}
		if (_Dest_Idex == _Element_Size)
		{
			//this insert node will be the tail node of this list
			Double_Link_List* insert_pointer = new Double_Link_List;
			insert_pointer->_Element_Data = _Dest_Data;
			insert_pointer->_Next_Pointer = NULL;
			Double_Link_List* _Tail_pointer = new Double_Link_List;
			_Tail_pointer = _Header_Pointer;

			int _Counter_hehe = 0;
			while (_Counter_hehe<_Element_Size - 1)
			{
				_Counter_hehe++;
				_Tail_pointer = _Tail_pointer->_Next_Pointer;
			}
			insert_pointer->_Pre_Pointer = _Tail_pointer;
			_Tail_pointer->_Next_Pointer = insert_pointer;
			_Element_Size++;
			return _Header_Pointer;
		}
		if (_Dest_Idex == 0)
		{
			//you want to append a node front header pointer
			//then,you need to rebuild the header pointer
			Double_Link_List* _New_header_pointer = new Double_Link_List;
			_New_header_pointer->_Element_Data = _Dest_Data;
			_New_header_pointer->_Next_Pointer = _Header_Pointer;
			_New_header_pointer->_Pre_Pointer = NULL;
			_Header_Pointer = _New_header_pointer;
			_Element_Size++;
			return _Header_Pointer;
		}
		if (_Header_Pointer == NULL)
		{
			//if you find the header pointer is null,then create the header pointer
			_Header_Pointer->_Element_Data = _Dest_Data;
			_Header_Pointer->_Next_Pointer = NULL;
			_Header_Pointer->_Pre_Pointer = NULL;
			_Element_Size++;
			return _Header_Pointer;
		}
		Double_Link_List* _P_pointer = new Double_Link_List;
		Double_Link_List* _C_pointer = new Double_Link_List;
		_P_pointer = NULL;
		_C_pointer = _Header_Pointer;
		int _Counter = 0;
		while (_Counter != _Dest_Idex)
		{
			_Counter++;
			_P_pointer = _C_pointer;
			_C_pointer = _C_pointer->_Next_Pointer;
		}
		//append this node to the idex 
		Double_Link_List* _Insert_pointer = new Double_Link_List;
		_Insert_pointer->_Element_Data = _Dest_Data;
		_Insert_pointer->_Pre_Pointer = _P_pointer;
		_Insert_pointer->_Next_Pointer = _C_pointer;
		_P_pointer->_Next_Pointer = _Insert_pointer;
		_C_pointer->_Pre_Pointer = _Insert_pointer;
		_Element_Size++;
		return _Header_Pointer;
	}

	//在指定节点之后插入一个节点,返回头结点
	//本算法将使用双链表的特性而不是通用算法
	Double_Link_List* _Insert_Node_After(int _Dest_Idex, _Type _Dest_Data)
	{
		if (_Dest_Idex > _Element_Size)
		{
			return _Header_Pointer;
		}
		if (_Header_Pointer == NULL)
		{
			//if the header pointer is null. then create it first
			_Header_Pointer->_Element_Data = _Dest_Data;
			_Header_Pointer->_Next_Pointer = NULL;
			_Header_Pointer->_Pre_Pointer = NULL;
			_Element_Size++;
			return _Header_Pointer;
		}
		Double_Link_List* _Traversal_pointer = new Double_Link_List;
		_Traversal_pointer = _Header_Pointer;
		int _Traversal_Idex = 0;
		while (_Traversal_Idex < _Dest_Idex)
		{
			_Traversal_Idex++;
			_Traversal_pointer = _Traversal_pointer->_Next_Pointer;
		}
		Double_Link_List* _Insert_pointer = new Double_Link_List;
		_Insert_pointer->_Element_Data = _Dest_Data;
		_Insert_pointer->_Next_Pointer = _Traversal_pointer->_Next_Pointer;
		_Traversal_pointer->_Next_Pointer = _Insert_pointer;
		_Insert_pointer->_Pre_Pointer = _Traversal_pointer;
		_Element_Size++;
		return _Header_Pointer;
	}
	//删除一个节点，指定位置，返回头结点
	//这是链表通用删除算法，可以使用双链表的特性进行优化
	//使用算链表特性的算法更为简洁方便，但在此不再赘述，如果需要自行参考_Insert_Node_After
	Double_Link_List* _Delete_Node(int _Dest_Idex)
	{
		if (_Dest_Idex >= _Element_Size)
		{
			return _Header_Pointer;
		}
		if (_Dest_Idex == 0)
		{
			//you want to delete the header node, so ,you need to 
			//rebuild the header pointer 
			Double_Link_List* _New_header_pointer = new Double_Link_List;
			_New_header_pointer = _Header_Pointer;
			_Header_Pointer = _New_header_pointer->_Next_Pointer;
			delete _New_header_pointer;
			_Element_Size--;
			return _Header_Pointer;
		}
		Double_Link_List* _P_pointer = new Double_Link_List;
		Double_Link_List* _C_pointer = new Double_Link_List;
		_P_pointer = NULL;
		_C_pointer = _Header_Pointer;
		int _Counter = 0;
		while (_Counter != _Dest_Idex)
		{
			_Counter++;
			_P_pointer = _C_pointer;
			_C_pointer = _C_pointer->_Next_Pointer;
		}
		_P_pointer->_Next_Pointer = _C_pointer->_Next_Pointer;
		delete _C_pointer;
		_Element_Size--;
		return _Header_Pointer;
	}

	//获取整个链表节点值,返回一个数组
	_Type* _Get_All_Elements()
	{
		_Type* _Res_Array;
		_Res_Array = new _Type[_Element_Size];
		Double_Link_List* _Traversal_pointer = new Double_Link_List;
		_Traversal_pointer = _Header_Pointer;
		int _Temp_Idex = 0;
		while (_Traversal_pointer != NULL)
		{
			_Res_Array[_Temp_Idex++] = _Traversal_pointer->_Element_Data;
			_Traversal_pointer = _Traversal_pointer->_Next_Pointer;
		}
		return _Res_Array;
	}

	//反转一个数组
	_Type* _Reverse_Array(_Type* _Dest_Array, int _Array_size)
	{
		for (int i = 0; i < _Array_size / 2; i++)
		{
			_Type _Temp_Data = _Dest_Array[i];
			_Dest_Array[i] = _Dest_Array[_Array_size - 1 - i];
			_Dest_Array[_Array_size - 1 - i] = _Temp_Data;
		}
		return _Dest_Array;
	}

	//排序，如果想要从大到小排序的话，请将_Flag参数置位true，否则置位false
	//函数运行结束时将返回链表头指针
	Double_Link_List* Sort(bool _Flag)
	{
		_Type* _Elements_Array = _Get_All_Elements();
		sort(_Elements_Array, _Elements_Array + _Element_Size);
		if (_Flag == true) {
			_Elements_Array = _Reverse_Array(_Elements_Array, _Element_Size);
		}
		_Header_Pointer = _Create_Double_Link_List(_Elements_Array, _Element_Size);
		delete[] _Elements_Array;
		return _Header_Pointer;
	}

	//返回最大值
	_Type _Max_Data()
	{
		_Type* _Element_Array;
		_Element_Array = new _Type[_Element_Size];
		_Element_Array = _Get_All_Elements();
		sort(_Element_Array, _Element_Array + _Element_Size);
		return _Element_Array[0];
	}
	//返回最小值
	_Type _Min_Data()
	{
		_Type* _Element_Array;
		_Element_Array = new _Type[_Element_Size];
		_Element_Array = _Get_All_Elements();
		sort(_Element_Array, _Element_Array + _Element_Size);
		_Reverse_Array(_Element_Array, _Element_Size);
		return _Element_Array[0];
	}
	//返回所有等于给定值的节点的下标
	//如果返回的只有-1，那么就表示这样的元素节点不存在
	vector<int>_Get_Idex_Equal_Value(_Type _Dest_Data)
	{
		vector<int> _Res_Vec;
		if (_Header_Pointer == NULL)
		{
			_Res_Vec.push_back(-1);
			return _Res_Vec;
		}
		Double_Link_List* _Teaversal_pointer = new Double_Link_List;
		_Teaversal_pointer = _Header_Pointer;
		int _Aim_Idex = 0;
		while (_Teaversal_pointer != NULL)
		{
			if (_Teaversal_pointer->_Element_Data == _Dest_Data)
			{
				_Res_Vec.push_back(_Aim_Idex);
			}
			_Aim_Idex++;
			_Teaversal_pointer = _Teaversal_pointer->_Next_Pointer;
		}
		if (_Res_Vec.size() == 0)
		{
			_Res_Vec.push_back(-1);
		}
		return _Res_Vec;
	}
	//返回给定值的节点的数量
	int _Get_Num_Equal_Element(_Type _Dest_Element)
	{
		vector<int> _Aim_idex = _Get_Idex_Equal_Value();
		if (_Aim_idex.size() == 1 && _Aim_idex.front() == -1)
		{
			return 0;
		}
		else{
			return _Aim_idex.size();
		}
	}
	//删除所有等于所给值的节点
	//返回头结点
	Double_Link_List* _Remove_All_Equal_Element(_Type _Dest_Data)
	{
		vector<int> _Aim_Idex_Vec;
		_Aim_Idex_Vec = _Get_Idex_Equal_Value(_Dest_Data);
		if (_Aim_Idex_Vec.size() == 1 && _Aim_Idex_Vec.front() == -1)
		{
			//not find this pointer in this list
			return _Header_Pointer;
		}
		else{
			vector<int>::iterator _Delete_Vit = _Aim_Idex_Vec.begin();
			int _H_ = 0;
			for (_Delete_Vit; _Delete_Vit != _Aim_Idex_Vec.end(); _Delete_Vit++)
			{
				 int _Idex=*_Delete_Vit;
				 _Header_Pointer = _Delete_Node(_Idex-_H_++);
			}
			return _Header_Pointer;
		}
	}

	//返回最末尾的节点值
	//这样看来应该定一个尾节点什么的，自行解决
	_Type _Back()
	{
		_Type* _Elements_Set;
		_Elements_Set = new _Type[_Element_Size];
		_Elements_Set = _Get_All_Elements();
		_Type _Res_Data = _Elements_Set[_Element_Size - 1];
		delete[]_Elements_Set;
		return _Res_Data;
	}
	//返回首节点
	_Type _Front()
	{
		return _Header_Pointer->_Element_Data;
	}
	//去掉相邻的重复的节点，返回首节点
	Double_Link_List* _Unique()
	{
		Double_Link_List* _Traversal_pointer = new Double_Link_List;
		_Traversal_pointer = _Header_Pointer;
		_Type _Unique_Val = _Header_Pointer->_Element_Data;
		_Traversal_pointer = _Traversal_pointer->_Next_Pointer;
		int _Delete_Idex = 1;
		vector<int> _Remove_Idex_Set;
		while (_Traversal_pointer != NULL)
		{
			if (_Traversal_pointer->_Element_Data == _Unique_Val)
			{
				//delete
				_Remove_Idex_Set.push_back(_Delete_Idex);
			}
			else{
				_Unique_Val = _Traversal_pointer->_Element_Data;
			}
			_Delete_Idex++;
			_Traversal_pointer = _Traversal_pointer->_Next_Pointer;
		}
		vector<int>::iterator _Delete_Vit = _Remove_Idex_Set.begin();
		int _H_ = 0;
		for (_Delete_Vit;_Delete_Vit != _Remove_Idex_Set.end(); _Delete_Vit++)
		{
			int _Delete_Idex_ = *_Delete_Vit;
			_Header_Pointer = _Delete_Node(_Delete_Idex_-_H_++);
		}
		return _Header_Pointer;
	}
		
	//用一个元素取代给定位置上的节点元素返回头结点
	//将对给定位置的那个元素进行操作
	Double_Link_List* _Emplace(int _Dest_Idex, _Type _Dest_Data)
	{
		if (_Dest_Idex >= _Element_Size)
		{
			return _Header_Pointer;
		}
		if (_Header_Pointer == NULL)
		{
			//if the header pointer is null,then create it
			_Header_Pointer->_Element_Data = _Dest_Data;
			_Header_Pointer->_Next_Pointer = NULL;
			_Header_Pointer->_Pre_Pointer = NULL;
			_Element_Size++;
			return _Header_Pointer;
		}
		if (_Dest_Idex == _Element_Size - 1)
		{
			return _Header_Pointer;
		}
		Double_Link_List* _Traversal_pointer = new Double_Link_List;
		_Traversal_pointer = _Header_Pointer;
		int _Counter = 0;
		while (_Counter < _Dest_Idex)
		{
			_Counter++;
			_Traversal_pointer = _Traversal_pointer->_Next_Pointer;
		}
		_Traversal_pointer->_Element_Data = _Dest_Data;
		return _Header_Pointer;
	}


	//用一个元素取代给定位置上的节点元素返回头结点
	//将对给定位置后面的那个元素进行操作
	Double_Link_List* _Emplace_After(int _Dest_Idex, _Type _Dest_Data)
	{
		if (_Dest_Idex >=_Element_Size)
		{
			return _Header_Pointer;
		}
		if (_Header_Pointer == NULL)
		{
			//if the header pointer is null,then create it
			_Header_Pointer->_Element_Data = _Dest_Data;
			_Header_Pointer->_Next_Pointer = NULL;
			_Header_Pointer->_Pre_Pointer = NULL;
			_Element_Size++;
			return _Header_Pointer;
		}
		if (_Dest_Idex == _Element_Size - 1)
		{
			return _Header_Pointer;
		}
		Double_Link_List* _Traversal_pointer = new Double_Link_List;
		_Traversal_pointer = _Header_Pointer;
		int _Counter = 0;
		while (_Counter < _Dest_Idex)
		{
			_Counter++;
			_Traversal_pointer = _Traversal_pointer->_Next_Pointer;
		}
		_Traversal_pointer->_Next_Pointer->_Element_Data = _Dest_Data;
		return _Header_Pointer;
	}

	//用一个元素取代给定位置上的节点元素返回头结点
	//将对给定位置前面的那个元素进行操作
	Double_Link_List* _Emplace_Before(int _Dest_Idex, _Type _Dest_Data)
	{
		if (_Dest_Idex >= _Element_Size)
		{
			return _Header_Pointer;
		}
		if (_Header_Pointer == NULL)
		{
			//if the header pointer is null,then create it
			_Header_Pointer->_Element_Data = _Dest_Data;
			_Header_Pointer->_Next_Pointer = NULL;
			_Header_Pointer->_Pre_Pointer = NULL;
			_Element_Size++;
			return _Header_Pointer;
		}
		if (_Dest_Idex == 0)
		{
			return _Header_Pointer;
		}
		Double_Link_List* _Traversal_pointer = new Double_Link_List;
		_Traversal_pointer = _Header_Pointer;
		int _Counter = 0;
		while (_Counter < _Dest_Idex)
		{
			_Counter++;
			_Traversal_pointer = _Traversal_pointer->_Next_Pointer;
		}
		_Traversal_pointer->_Pre_Pointer->_Element_Data = _Dest_Data;
		return _Header_Pointer;
	}
	//清空整个链表,返回一个空链表头
	Double_Link_List* _Clear()
	{
		if (_Header_Pointer == NULL)
		{
			return _Header_Pointer;
		}
		_Element_Size = 0;
		Double_Link_List* _Clear_pointer = new Double_Link_List;
		Double_Link_List* _Temp_pointer = new Double_Link_List;
		_Clear_pointer = _Header_Pointer;
		while (_Clear_pointer != NULL)
		{
			_Temp_pointer = _Clear_pointer;
			delete _Temp_pointer;
			_Clear_pointer = _Clear_pointer->_Next_Pointer;
		}
		_Header_Pointer = NULL;
		return _Header_Pointer;
	}
	//判断链表是否为空
	bool _Empty()
	{
		return _Header_Pointer == NULL;
	}
	//在尾部插入一个节点,返回头结点
	Double_Link_List* _Push_Back(_Type _Dest_Data)
	{
		_Header_Pointer=_Insert_Node_After(_Element_Size - 1, _Dest_Data);
		return _Header_Pointer;
	}
	//在头部插入一个新节点,返回头结点
	Double_Link_List* _Push_Front(_Type _Dest_Data)
	{
		_Header_Pointer=_Insert_Node_Before(_Dest_Data, 0);
		return _Header_Pointer;
	}
	//归并两个有序链表，返回新链表的头结点
	//为了使该算法有意义，并且你希望得到正确结果，请保证输入链表已经有序
	//输入参数表示的是目标链表的头结点，请不要乱入，后果自负
	Double_Link_List* _Merge_Double_Link_List(Double_Link_List* _Dest_list_header_pointer)
	{
		//再次确认您输入的两个链表有序，否则不可能得到正确结果（很大概率）
		Double_Link_List* _Merge_List_header_pointer = new Double_Link_List;
		Double_Link_List* _This_header_pointer =       new Double_Link_List;
		Double_Link_List* _Dest_header_pointer =       new Double_Link_List;
		_This_header_pointer = _Header_Pointer;
		_Dest_header_pointer = _Dest_list_header_pointer;
		_Type* _Append_Elements;
		_Append_Elements = new _Type[_Element_Size + _Dest_list_header_pointer->_Element_Size];
		int _Append_Idex = 0;
		while (_This_header_pointer != NULL&&_Dest_header_pointer != NULL)
		{
			if (_This_header_pointer->_Element_Data< _Dest_header_pointer->_Element_Data)
			{
				_Append_Elements[_Append_Idex++] = _This_header_pointer->_Element_Data;
				_This_header_pointer = _This_header_pointer->_Next_Pointer;
			}
			else if(_This_header_pointer->_Element_Data>=_Dest_header_pointer->_Element_Data){
				_Append_Elements[_Append_Idex++] = _Dest_header_pointer->_Element_Data;
				_Dest_header_pointer = _Dest_header_pointer->_Next_Pointer;
			}
		}
		while (_This_header_pointer != NULL)
		{
			_Append_Elements[_Append_Idex++] = _This_header_pointer->_Element_Data;
			_This_header_pointer = _This_header_pointer->_Next_Pointer;
		}
		while (_Dest_header_pointer != NULL)
		{
			_Append_Elements[_Append_Idex++] = _Dest_header_pointer->_Element_Data;
			_Dest_header_pointer = _Dest_header_pointer->_Next_Pointer;
		}
		_Merge_List_header_pointer = _Create_Double_Link_List(_Append_Elements, _Append_Idex);
		_Merge_List_header_pointer->_Element_Size = _Append_Idex;
		return _Merge_List_header_pointer;
	}
	//交换两个节点
	void _Swap_Node(int _Idex_1, int _Idex_2)
	{
		if (_Idex_1 >= _Element_Size || _Idex_2 >= _Element_Size){
			return;
		}
		Double_Link_List* _Traversal_pointer_1 = new Double_Link_List;
		Double_Link_List* _Traversal_pointer_2 = new Double_Link_List;
		_Traversal_pointer_1 = _Header_Pointer;
		_Traversal_pointer_2 = _Header_Pointer;
		int _Counter = 0;
		while (_Counter<_Idex_1)
		{
			_Traversal_pointer_1 = _Traversal_pointer_1->_Next_Pointer;
			_Counter++;
		}
		_Counter = 0;
		while (_Counter < _Idex_2)
		{
			_Traversal_pointer_2 = _Traversal_pointer_2->_Next_Pointer;
			_Counter++;
		}
		//then swap node
		_Type _Swap_Data = _Traversal_pointer_1->_Element_Data;
		_Traversal_pointer_1->_Element_Data = _Traversal_pointer_2->_Element_Data;
		_Traversal_pointer_2->_Element_Data = _Swap_Data;
	}

	//返回指定位置上的节点值
	_Type _At(int _Dest_Idex)
	{
		if (_Dest_Idex >= _Element_Size)
		{
			//Error!!
			return 0x7fffffff;
		}
		Double_Link_List* _Traversal_pointer=new Double_Link_List;
		_Traversal_pointer = _Header_Pointer;
		int _Counter = 0;
		while (_Counter < _Dest_Idex)
		{
			_Traversal_pointer = _Traversal_pointer->_Next_Pointer;
			_Counter++;
		}
		return _Traversal_pointer->_Element_Data;
	}

	//打印链表
	void _Print_List()
	{
		Double_Link_List* _Print_pointer = new Double_Link_List;
		_Print_pointer = _Header_Pointer;
		while (_Print_pointer!=NULL)
		{
			cout << _Print_pointer->_Element_Data << " ";
			_Print_pointer = _Print_pointer->_Next_Pointer;
		}
		cout << endl;
	}
};

/*
编号：004_4
名字：Circle_Double_Link_List
描述：循环双链表类
*/
template<class _Type> class Circle_Double_Link_List
{
public:
	_Type _Element_Data;
	int _Element_Size;
	Circle_Double_Link_List* _Pre_Pointer;
	Circle_Double_Link_List* _Next_Pointer;
	Circle_Double_Link_List* _Header_Pointer;
	Circle_Double_Link_List* _Tail_Pointer;
	Circle_Double_Link_List()
	{
		_Element_Size = 0;
		_Header_Pointer = NULL;
		_Tail_Pointer = NULL;
	}
	
	//新建一个链表,返回链表头
	//新节点将追加在原链表的尾部
	Circle_Double_Link_List* _Create_Circle_Double_List(_Type* _Dest_Set, int _Dest_Size)
	{
		_Element_Size += _Dest_Size;
		Circle_Double_Link_List* _Tail_pointer = new Circle_Double_Link_List;
		Circle_Double_Link_List* _Head_pointer = new Circle_Double_Link_List;
		_Head_pointer->_Element_Data = _Dest_Set[0];
		//this is important
		_Tail_pointer = _Head_pointer;
		_Tail_pointer->_Next_Pointer = NULL;
		for (int i = 1; i < _Dest_Size; i++)
		{
			Circle_Double_Link_List* _Append_Node = new Circle_Double_Link_List;
			_Append_Node->_Element_Data = _Dest_Set[i];
			_Tail_pointer->_Next_Pointer = _Append_Node;
			_Append_Node->_Pre_Pointer = _Tail_pointer;
			_Tail_pointer = _Append_Node;
			_Tail_pointer->_Next_Pointer = NULL;
		}
		_Head_pointer->_Pre_Pointer = _Tail_pointer;
		_Tail_pointer->_Next_Pointer= _Head_pointer;
		//this is important
		_Tail_Pointer = _Tail_pointer;
		return _Head_pointer;
	}
;
	//返回是否为空
	bool _Empty()
	{
		return _Header_Pointer == NULL;
	}
	//返回链表的大小
	int _Size()
	{
		return _Element_Size;
	}

	//返回某个位置上的值，超过链表长度将循环
	_Type _At(int _Dest_Idex)
	{
		Circle_Double_Link_List* _Traversal_pointer = new Circle_Double_Link_List;
		_Traversal_pointer = _Header_Pointer;
		int _Counter = 0;
		while (_Counter < _Dest_Idex)
		{
			_Traversal_pointer = _Traversal_pointer->_Next_Pointer;
			_Counter++;
		}
		return _Traversal_pointer->_Element_Data;
	}

	//查找某个固定值的节点，返回一个下标集合
	//如果返回集合只有-1则表示不存在这样的节点
	vector<int> _Get_All_Equal_Elements(_Type _Dest_Data)
	{
		vector<int> _Res_Vec;
		if (_Header_Pointer == NULL)
		{
			_Res_Vec.push_back(-1);
			return _Res_Vec;
		}
		Circle_Double_Link_List* Traversal_pointer = new Circle_Double_Link_List;
		Traversal_pointer = _Header_Pointer;
		int _Counter = 0;
		while (_Counter < _Element_Size)
		{
			if (Traversal_pointer->_Element_Data == _Dest_Data)
			{
				_Res_Vec.push_back(_Counter);
			}
			_Counter++;
			Traversal_pointer = Traversal_pointer->_Next_Pointer;
		}
		if (_Res_Vec.size() == 0)
		{
			_Res_Vec.push_back(-1);
		}
		return _Res_Vec;
	}

	//在尾部追加一个节点，返回头结点
	Circle_Double_Link_List* _Push_back(_Type _Dest_Data)
	{
		Circle_Double_Link_List* _Append_pointer = new Circle_Double_Link_List;
		_Append_pointer->_Element_Data = _Dest_Data;
		_Append_pointer->_Pre_Pointer = _Tail_Pointer;
		_Append_pointer->_Next_Pointer = _Header_Pointer;
		_Tail_Pointer->_Next_Pointer = _Append_pointer;
		_Header_Pointer->_Pre_Pointer = _Append_pointer;
		_Tail_Pointer = _Append_pointer;
		_Element_Size++;
		return _Header_Pointer;
	}

	//在头结点之前追加一个新节点,返回头结点
	Circle_Double_Link_List* _Push_front(_Type _Dest_Data)
	{
		Circle_Double_Link_List* _Append_pointer = new Circle_Double_Link_List;
		_Append_pointer->_Element_Data = _Dest_Data;
		_Append_pointer->_Next_Pointer = _Header_Pointer;
		_Append_pointer->_Pre_Pointer = _Tail_Pointer;
		_Header_Pointer = _Append_pointer;
		_Element_Size++;
		return _Header_Pointer;
	}

	//删除头结点,返回新的头结点
	Circle_Double_Link_List* _Pop_front()
	{
		if (_Header_Pointer == NULL){
			return NULL;
		}
		_Header_Pointer = _Header_Pointer->_Next_Pointer;
		_Element_Size--;
		return _Header_Pointer;
	}

	//删除尾节点，返回头结点
	Circle_Double_Link_List* _Pop_back()
	{
		if (_Tail_Pointer == NULL){
			return NULL;
		}
		_Header_Pointer = _Delete_Node(_Element_Size - 1);
		return _Header_Pointer;
	}


	//在给定位置上插入一个节点，返回头结点
	//对于插入在给定位置之前后之后的算法再次不再赘述
	//如果数字超过了链表的大小，函数将循环计数，对于出乎意料的结果，请保持淡定，都是因为您的输入问题
	Circle_Double_Link_List* _Insert_Node(int _Dest_Idex, _Type _Dest_Data)
	{
		if (_Element_Size!=0&&_Dest_Idex%_Element_Size== 0)
		{
			//the new header pointer
			_Header_Pointer =_Push_front(_Dest_Data);
			return _Header_Pointer;
		}
		if (_Header_Pointer == NULL)
		{
			//then create the header node 

			Circle_Double_Link_List* _New_header_pointer = new Circle_Double_Link_List;
			Circle_Double_Link_List* _New_Tail_pointer = new Circle_Double_Link_List;
			_New_header_pointer->_Element_Data = _Dest_Data;
			_New_Tail_pointer = _New_header_pointer;
			_New_Tail_pointer->_Next_Pointer = NULL;
			_New_header_pointer->_Pre_Pointer = _New_Tail_pointer;
			_New_header_pointer->_Next_Pointer = _New_Tail_pointer;
			_New_Tail_pointer->_Next_Pointer = _New_header_pointer;
			_New_Tail_pointer->_Pre_Pointer = _New_header_pointer;
			_Tail_Pointer = _New_Tail_pointer;
			_Element_Size++;
			return _New_header_pointer;
		}
		Circle_Double_Link_List* _Insert_pointer = new Circle_Double_Link_List;

		Circle_Double_Link_List* _Traversal_pointer = new Circle_Double_Link_List;
		_Traversal_pointer = _Header_Pointer;
		int _Counter = 0;
		while (_Counter < _Dest_Idex-1)
		{
			_Traversal_pointer = _Traversal_pointer->_Next_Pointer;
			_Counter++;
		}
		_Insert_pointer->_Element_Data = _Dest_Data;
		_Insert_pointer->_Pre_Pointer = _Traversal_pointer;
		_Insert_pointer->_Next_Pointer = _Traversal_pointer->_Next_Pointer;
		_Traversal_pointer->_Next_Pointer = _Insert_pointer;
		_Element_Size++;
		return _Header_Pointer;
	}

	//删除给定位置的节点，返回头结点
	//因为是循环链表，所以如果您输入的下标超出了链表长度，那么将循回计数
	Circle_Double_Link_List* _Delete_Node(int _Dest_Idex)
	{
		if (_Header_Pointer == NULL)
		{
			return NULL;
		}
		if (_Dest_Idex%_Element_Size == 0)
		{
			//you want to delete the header node,so you need to rebuild the header node
			Circle_Double_Link_List* _New_header_pointer = new Circle_Double_Link_List;
			_New_header_pointer = _Header_Pointer;
			_Header_Pointer = _New_header_pointer->_Next_Pointer;
			delete _New_header_pointer;
			_Element_Size--;
			return _Header_Pointer;
		}
		
		int _Counter = 0;
		Circle_Double_Link_List* _Traversal_pointer = new Circle_Double_Link_List;
		_Traversal_pointer = _Header_Pointer;
		while (_Counter <_Dest_Idex)
		{
			_Counter++;
			_Traversal_pointer = _Traversal_pointer->_Next_Pointer;
		}
		_Traversal_pointer->_Pre_Pointer->_Next_Pointer = _Traversal_pointer->_Next_Pointer;
		_Traversal_pointer->_Next_Pointer->_Pre_Pointer = _Traversal_pointer->_Pre_Pointer;
		//delete _Traversal_pointer;
		_Element_Size--;
		return _Header_Pointer;
	}



	//统计出链表中等于给定值的节点数量
	int _Count_element_Num(_Type _Dest_Data)
	{
		int _Res_Num = 0;
		Circle_Double_Link_List* _Traversal_pointer = new Circle_Double_Link_List;
		_Traversal_pointer = _Header_Pointer;
		if (_Traversal_pointer == NULL)
		{
			return 0;
		}
		int _Counter = 0;
		while (_Counter < _Element_Size)
		{
			if (_Traversal_pointer->_Element_Data == _Dest_Data)
			{
				_Res_Num++;
			}
			_Traversal_pointer = _Traversal_pointer->_Next_Pointer;
		}
		return _Res_Num;
	}

	//取到链表所有节点的值
	_Type* _Get_All_Elements()
	{
		_Type* _Res_Array;
		_Res_Array = new _Type[_Element_Size];
		int _Counter = 0,_Idex=0;
		Circle_Double_Link_List* _Traversal_pointer = new Circle_Double_Link_List;
		_Traversal_pointer = _Header_Pointer;
		while (_Counter < _Element_Size)
		{
			_Res_Array[_Idex++] = _Traversal_pointer->_Element_Data;
			_Traversal_pointer = _Traversal_pointer->_Next_Pointer;
			_Counter++;
		}
		return _Res_Array;
	}

	//反转一个数组
	_Type* _Reverse_Array(_Type* _Dest_Array, int _Array_size)
	{
		for (int i = 0; i < _Array_size / 2; i++)
		{
			_Type _Temp_Data = _Dest_Array[i];
			_Dest_Array[i] = _Dest_Array[_Array_size - 1 - i];
			_Dest_Array[_Array_size - 1 - i] = _Temp_Data;
		}
		return _Dest_Array;
	}


	//对链表排序，如果想要得到从大到小的链表，请将_flag_值为1，否则值为0
	//函数运行结束将返回链表头结点
	Circle_Double_Link_List* _Sort(bool _flag_)
	{
		_Type* _Elements_Array=_Get_All_Elements();
		sort(_Elements_Array, _Elements_Array + _Element_Size);
		if (_flag_ == true) _Elements_Array = _Reverse_Array(_Elements_Array, _Element_Size);
		_Header_Pointer = _Create_Circle_Double_List(_Elements_Array, _Element_Size);
		_Element_Size /= 2;
		delete[] _Elements_Array;
		return _Header_Pointer;
	}

	//返回头结点的值
	_Type _Front()
	{
		if (_Header_Pointer != NULL)
			return _Header_Pointer->_Element_Data;
		else
			return 0x7fffffff;
	}
	//返回尾节点
	_Type _Back()
	{
		if (_Header_Pointer == NULL)
		{
			return 0x7fffffff;
		}
		else{
			return _Tail_Pointer->_Element_Data;
		}
	}

	//返回之最小的节点
	_Type _Min()
	{
		if (_Header_Pointer == NULL){
			return -0x7fffffff;
		}
		_Type _Res_Data =_Header_Pointer->_Element_Data;
		Circle_Double_Link_List* _Traversal_pointer = new Circle_Double_Link_List;
		_Traversal_pointer = _Header_Pointer->_Next_Pointer;
		int _counter = 1;
		while (_counter < _Element_Size)
		{
			if (_Res_Data < _Traversal_pointer->_Element_Data)
			{
				_Res_Data=_Traversal_pointer->_Element_Data;
			}
			_counter++;
			_Traversal_pointer = _Traversal_pointer->_Next_Pointer;
		}
		return _Res_Data;
	}

	//返回之最大的节点
	_Type _Max()
	{
		if (_Header_Pointer == NULL){
			return 0x7fffffff;
		}
		_Type _Res_Data =_Header_Pointer->_Element_Data;
		Circle_Double_Link_List* _Traversal_pointer = new Circle_Double_Link_List;
		_Traversal_pointer = _Header_Pointer->_Next_Pointer;
		int _counter = 1;
		while (_counter < _Element_Size)
		{
			if (_Res_Data>_Traversal_pointer->_Element_Data)
			{
				_Res_Data = _Traversal_pointer->_Element_Data;
			}
			_counter++;
			_Traversal_pointer = _Traversal_pointer->_Next_Pointer;
		}
		return _Res_Data;
	}

	//去掉重复的节点，返回头结点
	Circle_Double_Link_List* _Unique()
	{
		Circle_Double_Link_List* _Traversal_pointer = new Circle_Double_Link_List;
		_Traversal_pointer = _Header_Pointer;
		if (_Traversal_pointer == NULL){
			return NULL;
		}
		_Type _Now_Data = _Traversal_pointer->_Element_Data;
		_Traversal_pointer = _Traversal_pointer->_Next_Pointer;
		int _counter = 1;
		int _Delete_Num= 0;
		while (_counter <_Element_Size-_Delete_Num)
		{
			if (_Traversal_pointer->_Element_Data == _Now_Data)
			{
				//delete
				_Header_Pointer = _Delete_Node(_counter-_Delete_Num);
				_Delete_Num++;
			}
			else{
				_Now_Data = _Traversal_pointer->_Element_Data;
			}
			_counter++;
			_Traversal_pointer = _Traversal_pointer->_Next_Pointer;
		}
		return _Header_Pointer;
	}

	//返回给定位置的指针，以便访问
	//如果您输入的下标超过了链表的长度，那么函数将会循环计数
	Circle_Double_Link_List* _Pointer_At(int _Dest_Idex)
	{
		if (_Header_Pointer == NULL) return NULL;
		Circle_Double_Link_List* _Res_pointer = new Circle_Double_Link_List;
		_Res_pointer = _Header_Pointer;
		int _Counter = 0;
		while (_Counter < _Dest_Idex)
		{
			_Counter++;
			_Res_pointer = _Res_pointer->_Next_Pointer;
		}
		return _Res_pointer;
	}


	//清空链表，返回空指针
	Circle_Double_Link_List* _Clear()
	{
		_Element_Size = 0;
		_Header_Pointer = NULL;
		_Tail_Pointer = NULL;
		return NULL;
	}

	//将指定位置节点上的值换位给定值，返回头结点
	//如果您输入的下标超过链表长度，函数将循环计数
	Circle_Double_Link_List* _Emplace_At(int _Dest_Idex, _Type _Dest_Data)
	{
		if (_Header_Pointer == NULL) return NULL;
		Circle_Double_Link_List* _Traversal_pointer = new Circle_Double_Link_List;
		_Traversal_pointer = _Header_Pointer;
		int _Counter = 0;
		while (_Counter < _Dest_Idex)
		{
			_Counter++;
			_Traversal_pointer = _Traversal_pointer->_Next_Pointer;
		}
		_Traversal_pointer->_Element_Data = _Dest_Data;
		return _Header_Pointer;
	}

	//将所有等于给定值的节点的值变为另外的给定的值
	//将节点值等于_If_Data的节点的值变为_To_Data
	//函数将返回头结点
	Circle_Double_Link_List* _Emplace_If_All(_Type _If_Data, _Type _To_Data)
	{
		if (_Header_Pointer == NULL) return NULL;
		Circle_Double_Link_List* _Traversal_pointer = new Circle_Double_Link_List;
		_Traversal_pointer = _Header_Pointer;
		int counter = 0;
		while (counter < _Element_Size)
		{
			if (_Traversal_pointer->_Element_Data == _If_Data)
			{
				_Traversal_pointer->_Element_Data = _To_Data;
			}
			counter++;
			_Traversal_pointer = _Traversal_pointer->_Next_Pointer;
		}
		return _Header_Pointer;
	}

	//归并两个有序的链表，返回新的头结点
	//为了得到正确答案，请保证输入的两个链表已经有序
	//输入参数为第二个链表的表头,及此链表的长度
	//该函数有bug，不推荐使用如此愚蠢的算法
	Circle_Double_Link_List _Merge(Circle_Double_Link_List* _Dest_List_header_pointer,int _Size_Dest_list)
	{
		Circle_Double_Link_List* _Traversal_pointer_This_list = new Circle_Double_Link_List;
		Circle_Double_Link_List* _Traversal_pointer_Dest_list = new Circle_Double_Link_List;
		_Type* _Elements_Array;
		_Elements_Array = new _Type[_Element_Size + _Size_Dest_list];
		int _Elements_Array_Idex = 0;
		int _counter_This_list = 0;
		int _counter_Dest_list = 0;
		_Traversal_pointer_Dest_list = _Dest_List_header_pointer;
		_Traversal_pointer_This_list = _Header_Pointer;
		while (_counter_This_list < _Element_Size&&
			_counter_Dest_list <_Size_Dest_list)
		{
			if (_Traversal_pointer_This_list->_Element_Data < _Traversal_pointer_Dest_list->_Element_Data)
			{
				_Elements_Array[_Elements_Array_Idex++] = _Traversal_pointer_This_list->_Element_Data;
				_Traversal_pointer_This_list = _Traversal_pointer_This_list->_Next_Pointer;
				_counter_This_list++;
			}
			else{
				_Elements_Array[_Elements_Array_Idex++] = _Traversal_pointer_Dest_list->_Element_Data;
				_Traversal_pointer_Dest_list = _Traversal_pointer_Dest_list->_Next_Pointer;
				_counter_Dest_list++;
			}
		}
		while (_counter_This_list < _Element_Size)
		{
			_Elements_Array[_Elements_Array_Idex++] = _Traversal_pointer_This_list->_Element_Data;
			_Traversal_pointer_This_list = _Traversal_pointer_This_list->_Next_Pointer;
			_counter_This_list++;
		}
		while (_counter_Dest_list < _Size_Dest_list)
		{
			_Elements_Array[_Elements_Array_Idex++] = _Traversal_pointer_Dest_list->_Element_Data;
			_Traversal_pointer_Dest_list = _Traversal_pointer_Dest_list->_Next_Pointer;
			_counter_Dest_list++;
		}
		Circle_Double_Link_List _Res_List;
		_Res_List._Header_Pointer= _Create_Circle_Double_List(_Elements_Array, _Elements_Array_Idex);
		_Res_List._Element_Size = _Elements_Array_Idex;
		return _Res_List;
	}
	//遍历链表
	void _Print_List()
	{
		Circle_Double_Link_List* Traversal_pointer = new Circle_Double_Link_List;
		Traversal_pointer = _Header_Pointer;
		int _Counter = 0;
		while (_Counter!=_Element_Size)
		{
			_Counter++;
			cout << Traversal_pointer->_Element_Data << " ";
			Traversal_pointer = Traversal_pointer->_Next_Pointer;
		}
		cout << endl;
	}
};

/*
编号：004_5
名字：Stack
描述：栈类
备注：特别说明，使用此栈请不要负载过大的内存，默认最大为10000如有需要可修改
*/
template<class _Type> class Stack
{
public:
	//栈默认最大容量，可根据内存大小和需求修改
	_Type _Stack_Data[10000];
	int _Stack_Idex;
	Stack()
	{
		//将栈归为0
		_Stack_Idex =0;
	}
	//返回栈此时的大小
	int _Size()
	{
		return _Stack_Idex;
	}
	//判断栈是否为空
	bool _Empty()
	{
		return _Stack_Idex == 0;
	}
	//返回栈顶元素
	_Type _Top()
	{
		return _Stack_Data[_Stack_Idex-1];
	}
	//压入一个元素到栈顶
	void _Push(_Type _Data)
	{
		_Stack_Data[_Stack_Idex++] = _Data;
	}
	//弹出栈顶元素
	void _Pop()
	{
		_Stack_Idex--;
	}
	//将整个栈遍历
	void _Traversal_Stack()
	{
		while (!_Empty())
		{
			cout <<_Top()<< " ";
			_Pop();
		}
		cout << endl;
	}
};

/*
编号：004_6
名字：Dequeue
描述：双端队列类(使用单向链表)
*/
template<class _Type> class Dequeue
{
public:
	_Type _Element_Data;
	int _Element_Size;
	Dequeue* _Next_Pointer;
	Dequeue* _Header_Pointer;
	Dequeue* _Tail_Pointer;
	Dequeue()
	{
		_Element_Size = 0;
		_Header_Pointer = NULL;
		_Tail_Pointer = NULL;
	}

	//返回队列的大小
	int _Size()
	{
		return _Element_Size;
	}
	//判断队列是不是为空
	bool _Empty()
	{
		return _Header_Pointer == NULL;
	}

	//return the front
	_Type _Front()
	{
		if (_Header_Pointer == NULL) return NULL;
		return _Header_Pointer->_Element_Data;
	}

	//return the back
	_Type _Back()
	{
		if (_Header_Pointer == NULL) return NULL;
		return _Tail_Pointer->_Element_Data;
	}

	//在指定位置处插入一个新的节点
	//返回新队列的链头
	Dequeue* _Insert_Node(int _Dest_Idex, _Type _Dest_Data)
	{
		if (_Dest_Idex >_Element_Size){
			return _Header_Pointer;
		}
		if (_Header_Pointer == NULL)
		{
			//if the header pointer is null,then create the header pointer 
			Dequeue* _New_Header_pointer = new Dequeue;
			_New_Header_pointer->_Element_Data = _Dest_Data;
			_New_Header_pointer->_Next_Pointer =_Tail_Pointer;
			_Header_Pointer = _New_Header_pointer;
			_Tail_Pointer = _Header_Pointer;
			_Tail_Pointer->_Next_Pointer = NULL;
			_Element_Size++;
			return _Header_Pointer;
		}
		if (_Dest_Idex == 0)
		{
			//you want to insert a node to emplace the header pointer
			//then you need to rebuild a new pointer as the new header pointer
			Dequeue* _New_header_pointer = new Dequeue;
			_New_header_pointer->_Element_Data = _Dest_Data;
			_New_header_pointer->_Next_Pointer = _Header_Pointer;
			_Header_Pointer = _New_header_pointer;
			_Element_Size++;
			return _Header_Pointer;
		}
		//else find the idex you want to insert ,then insert and done
		int _Counter = 0;
		Dequeue* _Traversal_pointer = new Dequeue;
		Dequeue* _Pre_pointer = new Dequeue;
		_Pre_pointer = NULL;
		_Traversal_pointer = _Header_Pointer;
		while (_Counter < _Dest_Idex)
		{
			_Counter++;
			_Pre_pointer = _Traversal_pointer;
			_Traversal_pointer = _Traversal_pointer->_Next_Pointer;
		}
		Dequeue* _Insert_pointer = new Dequeue;
		_Insert_pointer->_Element_Data = _Dest_Data;
		_Insert_pointer->_Next_Pointer = _Traversal_pointer;
		_Pre_pointer->_Next_Pointer = _Insert_pointer;
		_Element_Size++;
		return _Header_Pointer;
	}

	//在尾部追加一个新节点，返回新队列的头结点
	Dequeue* _Push_back(_Type _Dest_Data)
	{
		if (_Header_Pointer == NULL)
		{
			//the new header pointer
			_Header_Pointer = new Dequeue;
			_Header_Pointer->_Element_Data = _Dest_Data;
			_Header_Pointer->_Next_Pointer = NULL;
			_Tail_Pointer = new Dequeue;
			_Tail_Pointer = _Header_Pointer;
			_Tail_Pointer->_Next_Pointer = NULL;
			_Element_Size = 1;
			return _Header_Pointer;
		}
		Dequeue* _Append_pointer = new Dequeue;
		_Append_pointer->_Element_Data = _Dest_Data;
		_Append_pointer->_Next_Pointer = NULL;
		_Tail_Pointer->_Next_Pointer = _Append_pointer;
		_Tail_Pointer = _Append_pointer;
		_Element_Size++;
		return _Header_Pointer;
	}

	//在队列头添加一个新的节点，返回新队列的头结点
	Dequeue* _Push_front(_Type _Dest_Data)
	{
		if (_Header_Pointer == NULL)
		{
			//the new header pointer
			_Header_Pointer = new Dequeue;
			_Header_Pointer->_Element_Data = _Dest_Data;
			_Header_Pointer->_Next_Pointer = NULL;
			_Tail_Pointer = new Dequeue;
			_Tail_Pointer = _Header_Pointer;
			_Tail_Pointer->_Next_Pointer = NULL;
			_Element_Size = 1;
			return _Header_Pointer;
		}
		Dequeue* _Append_pointer = new Dequeue;
		_Append_pointer->_Element_Data = _Dest_Data;
		_Append_pointer->_Next_Pointer = _Header_Pointer;
		_Header_Pointer = _Append_pointer;
		_Element_Size++;
		return _Header_Pointer;
	}

	//删除某个指定位置的节点，返回头结点
	Dequeue* _Delete_Node(int _Dest_idex)
	{
		if (_Header_Pointer == NULL){
			return NULL;
		}
		if (_Dest_idex > _Element_Size)
		{
			return _Header_Pointer;
		}
		if (_Dest_idex == 0)
		{
			//you want to delete the header pointer,so you need to rebuild a new header pointer
			_Header_Pointer = _Header_Pointer->_Next_Pointer;
			_Element_Size--;
			return _Header_Pointer;
		}
		Dequeue* _Traversal_pointer = new Dequeue;
		Dequeue* _pre_pointer = new Dequeue;
		_Traversal_pointer = _Header_Pointer;
		_pre_pointer = NULL;
		int _counter = 0;
		while (_counter < _Dest_idex)
		{
			_counter++;
			_pre_pointer = _Traversal_pointer;
			_Traversal_pointer = _Traversal_pointer->_Next_Pointer;
		}
		_pre_pointer->_Next_Pointer = _Traversal_pointer->_Next_Pointer;
		delete _Traversal_pointer;
		_Element_Size--;
		return _Header_Pointer;
	}

	//删除尾节点，返回头结点
	Dequeue* _Pop_back()
	{
		if (_Header_Pointer == NULL){
			return NULL;
		}
		_Header_Pointer = _Delete_Node(_Element_Size-2);
		return _Header_Pointer;
	}

	//删除头结点,返回新的头结点
	Dequeue* _Pop_front()
	{
		if (_Header_Pointer == NULL){
			return NULL;
		}
		_Header_Pointer = _Delete_Node(0);
		return _Header_Pointer;
	}

	//判断给定的元素节点是否存在
	//如果存在则返回第一次出现的下标，否则返回-1
	int _Exist_And_Idex(_Type _Dest_Data)
	{
		Dequeue* _Traversal_pointer = new Dequeue;
		_Traversal_pointer = _Header_Pointer;
		int _Res_Idex = 0;
		while (_Traversal_pointer != NULL)
		{
			if (_Traversal_pointer->_Element_Data == _Dest_Data)
			{
				return _Res_Idex;
			}
			_Res_Idex++;
			_Traversal_pointer = _Traversal_pointer->_Next_Pointer;
		}
		return -1;
	}

	//交换指定位置上的节点信息，返回头指针
	Dequeue* _Swap_Info(int _idex_1, int _idex_2)
	{
		if (_idex_1<0 || _idex_1>_Element_Size || _idex_2<0 || _idex_2>_Element_Size)
		{
			return _Header_Pointer;
		}
		if (_Header_Pointer == NULL){
			return NULL;
		}
		int _counter_1 = 0;
		int _counter_2 = 0;
		Dequeue* _Traversal_1 = new Dequeue;
		Dequeue* _Traversal_2 = new Dequeue;
		_Traversal_1 = _Header_Pointer;
		_Traversal_2 = _Header_Pointer;
		while (_counter_1 < _idex_1){
			_counter_1++;
			_Traversal_1 = _Traversal_1->_Next_Pointer;
		}
		while (_counter_2 < _idex_2){
			_counter_2++;
			_Traversal_2 = _Traversal_2->_Next_Pointer;
		}
		_Type _Temp_data = _Traversal_1->_Element_Data;
		_Traversal_1->_Element_Data = _Traversal_2->_Element_Data;
		_Traversal_2->_Element_Data = _Temp_data;
		return _Header_Pointer;
	}

	//获取队列中的元素为一个数组
	_Type* _Get_All_Elements()
	{
		_Type* _Res_Array;
		_Res_Array = new _Type[_Element_Size];
		Dequeue* _Traversal_pointer = new Dequeue;
		_Traversal_pointer = _Header_Pointer;
		int _idex_array = 0;
		while (_Traversal_pointer != NULL)
		{
			_Res_Array[_idex_array++]=(_Traversal_pointer->_Element_Data);
			_Traversal_pointer = _Traversal_pointer->_Next_Pointer;
		}
		return _Res_Array;
	}

	//给定一个队列，直接创建出这个队列，返回对头
	Dequeue* _Creat_dequeue(_Type* _Element_Set, int _Set_size)
	{
		//first,you should build the header pointer
		Dequeue* _de_header_pointer = new Dequeue;
		Dequeue* _de_tail_pointer = new Dequeue;
		_de_header_pointer->_Element_Data = _Element_Set[0];
		_de_header_pointer->_Next_Pointer = NULL;
		_de_tail_pointer = _de_header_pointer;
		_de_tail_pointer->_Next_Pointer = NULL;
		_Element_Size++;
		for (int i = 1; i < _Set_size; i++)
		{
			Dequeue* _new_pointer = new Dequeue;
			_new_pointer->_Element_Data = _Element_Set[i];
			_new_pointer->_Next_Pointer = NULL;
			_de_tail_pointer->_Next_Pointer = _new_pointer;
			_de_tail_pointer = _new_pointer;
			_Element_Size++;
		}
		_Tail_Pointer = _de_tail_pointer;
		return _de_header_pointer;
	}

	//反转一个数组
	_Type* _Reverse_Array(_Type* _Dest_Array, int _Array_size)
	{
		for (int i = 0; i < _Array_size / 2; i++)
		{
			_Type _Temp_Data = _Dest_Array[i];
			_Dest_Array[i] = _Dest_Array[_Array_size - 1 - i];
			_Dest_Array[_Array_size - 1 - i] = _Temp_Data;
		}
		return _Dest_Array;
	}
	//排序，如果希望按从大到小排序，请将_Flag_参数置位true，否则置位false
	//函数运行后将返回排序后的头结点
	Dequeue* _Sort(bool _Flag_)
	{
		_Type* _Res_Array = _Get_All_Elements();
		sort(_Res_Array, _Res_Array + _Element_Size);
		if (_Flag_ == true)
			_Res_Array = _Reverse_Array(_Res_Array, _Element_Size);
		Dequeue* _sort_header_pointer = new Dequeue;
		_sort_header_pointer = _Creat_dequeue(_Res_Array, _Element_Size);
		return _sort_header_pointer;
	}

	//反转链表，返回新的头结
	Dequeue* _Reverse()
	{
		_Type* _Element_array = _Get_All_Elements();
		_Element_array = _Reverse_Array(_Element_array, _Element_Size);
		Dequeue* _This_header_pointer = new Dequeue;
		_This_header_pointer = _Creat_dequeue(_Element_array, _Element_Size);
		return _This_header_pointer;
	}

	//归并两个有序的链表，请输入数据保证从小到大有序，否则后果自负
	//函数运行结束将返回归并后的队列链表的头结点以便访问
	Dequeue _Merge(Dequeue* _Dest_header_pointer)
	{
		Dequeue _Res_Deque;
		Dequeue* _Traversal_dest_pointer = new Dequeue;
		Dequeue* _Traversal_this_pointer = new Dequeue;
		Dequeue* _Merge_header_pointer = new Dequeue;
		_Type* _Element_sorted;
		_Element_sorted = new _Type[_Element_Size + _Dest_header_pointer->_Element_Size];
		_Traversal_dest_pointer = _Dest_header_pointer;
		_Traversal_this_pointer = _Header_Pointer;
		int _counter_idex = 0;
		while (_Traversal_dest_pointer != NULL&&_Traversal_this_pointer != NULL)
		{
			if (_Traversal_dest_pointer->_Element_Data < _Traversal_this_pointer->_Element_Data)
			{
				_Element_sorted[_counter_idex++] = _Traversal_dest_pointer->_Element_Data;
				_Traversal_dest_pointer = _Traversal_dest_pointer->_Next_Pointer;
			}
			else{
				_Element_sorted[_counter_idex++] = _Traversal_this_pointer->_Element_Data;
				_Traversal_this_pointer = _Traversal_this_pointer->_Next_Pointer;
			}
		}
		while (_Traversal_dest_pointer != NULL)
		{
			_Element_sorted[_counter_idex++] = _Traversal_dest_pointer->_Element_Data;
			_Traversal_dest_pointer = _Traversal_dest_pointer->_Next_Pointer;
		}
		while (_Traversal_this_pointer != NULL)
		{
			_Element_sorted[_counter_idex++] = _Traversal_this_pointer->_Element_Data;
			_Traversal_this_pointer = _Traversal_this_pointer->_Next_Pointer;
		}
		_Merge_header_pointer = _Creat_dequeue(_Element_sorted, _counter_idex);
		_Res_Deque._Header_Pointer = _Merge_header_pointer;
		_Res_Deque._Element_Size = _counter_idex;
		//get the tail pointer
		_Res_Deque._Tail_Pointer =NULL;
		Dequeue* _F_pointer = _Merge_header_pointer;
		while (_F_pointer != NULL)
		{
			_Res_Deque._Tail_Pointer = _F_pointer;
			_F_pointer = _F_pointer->_Next_Pointer;
		}
		return _Res_Deque;
	}
	//清空队列,返回空指针
	Dequeue* _Clear()
	{
		_Header_Pointer = NULL;
		_Tail_Pointer = NULL;
		_Element_Size = 0;
		return _Header_Pointer;
	}

	//遍历整个队列
	void _Print_Deque()
	{
		Dequeue* _Traversal_pointer = new Dequeue;
		_Traversal_pointer = _Header_Pointer;
		while (_Traversal_pointer != NULL)
		{
			cout << _Traversal_pointer->_Element_Data << " ";
			_Traversal_pointer = _Traversal_pointer->_Next_Pointer;
		}
		cout << endl;
	}
};


/*
编号：004_7
名字：Vector
描述：矢量容器类
*/
template<class _Type> class Vector
{
public:
	_Type _ELEMENT_DATA;
	Vector* _NEXT_POINTER;
	Vector* _HEADER_POINTER;
	Vector* _TAIL_POINTER;
	int _SIZE_ELEMENTS;
	Vector()
	{
		_HEADER_POINTER = NULL;
		_TAIL_POINTER = NULL;
		_SIZE_ELEMENTS = 0;
	}
	//初始化一个向量表,返回这个向量
	Vector _create_vector(_Type* _Dest_Elements_array, int _Size_Elements)
	{
		Vector _Res_vector;
		if (_Size_Elements == 0) return _Res_vector;
		//first you need to create the header pointer of this vector
		Vector* _header_pointer = new Vector;
		Vector* _tail_pointer = new Vector;
		_header_pointer->_ELEMENT_DATA = _Dest_Elements_array[0];
		_header_pointer->_NEXT_POINTER = NULL;
		_tail_pointer = _header_pointer;
		_tail_pointer->_NEXT_POINTER = NULL;
		//then,you can continue your work 
		for (int idex = 1; idex < _Size_Elements; idex++)
		{
			Vector* _append_pointer = new Vector;
			_append_pointer->_ELEMENT_DATA = _Dest_Elements_array[idex];
			_append_pointer->_NEXT_POINTER = NULL;
			_tail_pointer->_NEXT_POINTER = _append_pointer;
			_tail_pointer = _append_pointer;
			_tail_pointer->_NEXT_POINTER = NULL;
		}
		_Res_vector._HEADER_POINTER = _header_pointer;
		_Res_vector._TAIL_POINTER = _tail_pointer;
		_Res_vector._SIZE_ELEMENTS = _Size_Elements;
		return _Res_vector;
	}

	//return the size of this vector
	int _Size()
	{
		return _SIZE_ELEMENTS;
	}

	//judge if this vector is empty
	bool _Empty()
	{
		return _HEADER_POINTER == NULL;
	}

	//append a node to this vector,return the header pointer
	Vector* _Push_back(_Type _Dest_data)
	{
		if (_HEADER_POINTER == NULL)
		{
			//if this vector not exist ,you need to create it 
			_HEADER_POINTER = new Vector;/* if you find error,this is important */
			_HEADER_POINTER->_ELEMENT_DATA = _Dest_data;
			_HEADER_POINTER->_NEXT_POINTER = NULL;
			_TAIL_POINTER = _HEADER_POINTER;
			_TAIL_POINTER->_NEXT_POINTER = NULL;
			_SIZE_ELEMENTS = 1;
			return _HEADER_POINTER;  
		}
		//else the header pointer has existed,append the new node
		Vector* _append_pointer = new Vector;
		_append_pointer->_ELEMENT_DATA = _Dest_data;
		_append_pointer->_NEXT_POINTER = NULL;
		_TAIL_POINTER->_NEXT_POINTER = _append_pointer;
		_TAIL_POINTER = _append_pointer;
		_TAIL_POINTER->_NEXT_POINTER = NULL;
		_SIZE_ELEMENTS++;
		return _HEADER_POINTER;
	}

	//append a node in front ,then return the new header pointer
	Vector* _Push_front(_Type _Dest_Data)
	{
		if (_HEADER_POINTER == NULL)
		{
			//the header pointer is null,then create the header pointer 
			_HEADER_POINTER->_ELEMENT_DATA = _Dest_Data;
			_HEADER_POINTER->_NEXT_POINTER = NULL;
			_TAIL_POINTER = _HEADER_POINTER;
			_TAIL_POINTER->_NEXT_POINTER = NULL;
			_SIZE_ELEMENTS = 1;
			return _HEADER_POINTER;
		}
		//else , you can append the new node to the very beginning of this vector
		Vector* _append_pointer = new Vector;
		_append_pointer->_ELEMENT_DATA = _Dest_Data;
		_append_pointer->_NEXT_POINTER = _HEADER_POINTER;
		_HEADER_POINTER = _append_pointer;
		_SIZE_ELEMENTS++;
		return _HEADER_POINTER;
		//end ..
	}

	//delete a node from the tail of this vector
	//return the header pointer of this vector
	Vector* _Pop_back()
	{
		if (_HEADER_POINTER == NULL) return NULL;
		if (_SIZE_ELEMENTS == 1)
		{
			_SIZE_ELEMENTS = 0;
			_HEADER_POINTER = NULL;
			_TAIL_POINTER = NULL;
			return _HEADER_POINTER;
		}
		//find the pre_tail_pointer of this vector
		Vector* _pre_tail_pointer = new Vector;
		_pre_tail_pointer = _HEADER_POINTER;
		while (_pre_tail_pointer->_NEXT_POINTER->_NEXT_POINTER != NULL)
		{
			_pre_tail_pointer = _pre_tail_pointer->_NEXT_POINTER;
		}
		_TAIL_POINTER = _pre_tail_pointer;
		_TAIL_POINTER->_NEXT_POINTER = NULL;
		_SIZE_ELEMENTS--;
		return _HEADER_POINTER;
	}

	//delete a node from the header of this vector
	//return the header pointer node of this vector
	Vector* _Pop_front()
	{
		if (_HEADER_POINTER == NULL) return NULL;
		if (_SIZE_ELEMENTS == 1)
		{
			_SIZE_ELEMENTS = 0;
			_HEADER_POINTER = NULL;
			_TAIL_POINTER = NULL;
			return _HEADER_POINTER;
		}
		//else delete the header pointer and return the new header pointer
		_HEADER_POINTER = _HEADER_POINTER->_NEXT_POINTER;
		_SIZE_ELEMENTS--;
		return _HEADER_POINTER;
	}

	//insert a node in the idex you offer
	//and return the new header pointer of this vector
	Vector* _Insert(_Type _Dest_Data, int _Idex_insert)
	{
		if (_Idex_insert >_SIZE_ELEMENTS)
		{
		    return _HEADER_POINTER;
		}
		if (_Idex_insert == _SIZE_ELEMENTS)
		{
			//you want to append a node in the back of this vector
			_HEADER_POINTER = _Push_back(_Dest_Data);
			return _HEADER_POINTER;
		}
		if (_Idex_insert == 0)
		{
			//you want to rebuild the hedaer pointer
			_HEADER_POINTER = _Push_front(_Dest_Data);
			return _HEADER_POINTER;
		}
		/* just for fun */
		if (_HEADER_POINTER == NULL)
		{
			//this vector is empty ,so you want to insert a node in this vector's header
			_HEADER_POINTER->_ELEMENT_DATA = _Dest_Data;
			_HEADER_POINTER->_NEXT_POINTER = NULL;
			_TAIL_POINTER = _HEADER_POINTER;
			_TAIL_POINTER->_NEXT_POINTER = NULL;
			_SIZE_ELEMENTS = 1;
			return _HEADER_POINTER;
		}
		//else you need to find the currect idex and insert the new node
		int counter= 0;
		Vector* _Traversal_pointer = new Vector;
		Vector* _Pre_Traversal_pointer = new Vector;
		_Traversal_pointer = _HEADER_POINTER;
		_Pre_Traversal_pointer = NULL;
		while (counter != _Idex_insert)
		{
			counter++;
			_Pre_Traversal_pointer = _Traversal_pointer;
			_Traversal_pointer = _Traversal_pointer->_NEXT_POINTER;
		}
		Vector* _insert_pointer = new Vector;
		_insert_pointer->_ELEMENT_DATA = _Dest_Data;
		_insert_pointer->_NEXT_POINTER = _Traversal_pointer;
		_Pre_Traversal_pointer->_NEXT_POINTER = _insert_pointer;
		_SIZE_ELEMENTS++;
		return _HEADER_POINTER;
	}

	//delete the node in the position of your input idex
	//the return the header pointer of this vector
	Vector* _Delete(int _Dest_idex)
	{
		if (_HEADER_POINTER == NULL)
		{
			//this vector is null,so return null
			return _HEADER_POINTER;
		}
		if (_Dest_idex >= _SIZE_ELEMENTS)
		{
			//your idex overfllow
			return _HEADER_POINTER;
		}
		if (_Dest_idex == 0)
		{
			//you want to delete the header pointer of this vector
			//so ,you need to create a new header pointer 
			_HEADER_POINTER = _Pop_front();
			return _HEADER_POINTER;
		}
		//then ,find the current idex ,and delete the node
		//delete the current idex's value
		Vector* _delete_pointer = new Vector;
		Vector* _pre_delete_pointer = new Vector;
		_delete_pointer = _HEADER_POINTER;
		_pre_delete_pointer = NULL;
		int counter = 0;
		while (counter != _Dest_idex)
		{
			counter++;
			_pre_delete_pointer = _delete_pointer;
			_delete_pointer = _delete_pointer->_NEXT_POINTER;
		}
		_pre_delete_pointer->_NEXT_POINTER = _delete_pointer->_NEXT_POINTER;
		_SIZE_ELEMENTS--;
		return _HEADER_POINTER;
	}

	//return the value of the idex you offer
	_Type _At(int _Dest_idex)
	{
		_Type p;
		if (_Dest_idex < 0 || _Dest_idex >= _SIZE_ELEMENTS)
		{
			//overfllow
			return p;
		}
		Vector* _Traversal_pointer = new Vector;
		_Traversal_pointer = _HEADER_POINTER;
		int counter = 0;
		while (counter != _Dest_idex)
		{
			counter++;
			_Traversal_pointer = _Traversal_pointer->_NEXT_POINTER;
		}
		return _Traversal_pointer->_ELEMENT_DATA;
	}

	//judge exist or not
	//if the value you offer is exist in this vector,return the current idex 
	//the current idex is the fist meet idex of this vector
	//else return -1 to mean find error or false
	int _Exist(_Type _Dest_Data)
	{
		if (_HEADER_POINTER == NULL)
		{
			return -1;
		}
		Vector* _Traversal_pointer = new Vector;
		_Traversal_pointer = _HEADER_POINTER;
		int current_idex = 0;
		while (_Traversal_pointer != NULL)
		{
			if (_Traversal_pointer->_ELEMENT_DATA == _Dest_Data)
			{
				return current_idex;
			}
			_Traversal_pointer = _Traversal_pointer->_NEXT_POINTER;
			current_idex++;
		}
		//if not find,return -1
		return -1;
	}

	//count the value you offer in this vector
	int _Count(_Type Dest_data)
	{
		Vector* _Traversal_pointer = new Vector;
		int _Res_Num = 0;
		_Traversal_pointer = _HEADER_POINTER;
		while (_Traversal_pointer != NULL)
		{
			if (_Traversal_pointer->_ELEMENT_DATA == Dest_data)
			{
				_Res_Num++;
			}
			_Traversal_pointer = _Traversal_pointer->_NEXT_POINTER;
		}
		return _Res_Num;
	}

	//get all element value of this vector
	//return the elements array
	_Type* _Get_All_Elements()
	{
		_Type* _Element_array;
		_Element_array = new _Type[_SIZE_ELEMENTS];
		Vector* _Traversal_pointer = new Vector;
		_Traversal_pointer = _HEADER_POINTER;
		int counter_idex = 0;
		while (_Traversal_pointer != NULL)
		{
			_Element_array[counter_idex++] = _Traversal_pointer->_ELEMENT_DATA;
			_Traversal_pointer = _Traversal_pointer->_NEXT_POINTER;
		}
		return _Element_array;
	}

	//reverse a array
	//return the new array
	_Type* _Reverse_Array(_Type* _Dest_Array, int _Array_size)
	{
		for (int i = 0; i < _Array_size / 2; i++)
		{
			_Type _Temp_Data = _Dest_Array[i];
			_Dest_Array[i] = _Dest_Array[_Array_size - 1 - i];
			_Dest_Array[_Array_size - 1 - i] = _Temp_Data;
		}
		return _Dest_Array;
	}

	//sort this vector
	//if you want to sort this vector from big to small,please offer the flag as true,or let the flag=false
	//return this vector
	Vector _Sort(bool flag)
	{
		Vector _Res_vector;
		_Res_vector._HEADER_POINTER = NULL;
		_Res_vector._TAIL_POINTER = NULL;
		_Res_vector._SIZE_ELEMENTS = 0;
		if (_HEADER_POINTER == NULL) return _Res_vector;
		_Type* _Element_array = _Get_All_Elements();
		sort(_Element_array, _Element_array + _SIZE_ELEMENTS);
		Vector* _New_header_pointer = new Vector;
		if (flag == true) _Element_array = _Reverse_Array(_Element_array, _SIZE_ELEMENTS);
		_Res_vector= _create_vector(_Element_array, _SIZE_ELEMENTS);		
		_Res_vector._SIZE_ELEMENTS = _SIZE_ELEMENTS;
		delete[]_Element_array;
		return _Res_vector;
	}

	//emplace a node's value if this node's value equals the data you offer
	//return the vector's header pointer
	Vector* _Emplace_If(_Type _Find_data,_Type _Emplace_to_data)
	{
		if (_HEADER_POINTER == NULL) reurn _HEADER_POINTER;
		Vector* _Traversal_pointer = new Vector;
		_Traversal_pointer = _HEADER_POINTER;
		while (_Traversal_pointer != NULL)
		{
			if (_Traversal_pointer->_ELEMENT_DATA == _Find_data)
			{
				_Traversal_pointer->_ELEMENT_DATA = _Emplace_to_data;
			}
			_Traversal_pointer = _Traversal_pointer->_NEXT_POINTER;
		}
		return _HEADER_POINTER;
	}

	//swap two node's value in this vector,please offer two idex 
	//return the header pointer of this vector
	Vector* _Swap(int _idex_1, int _idex_2)
	{
		if (_idex_1 < 0 || _idex_1 >= _SIZE_ELEMENTS || _idex_2 < 0 || _idex_2 >= _SIZE_ELEMENTS)
		{
			return _HEADER_POINTER;
		}
		if (_idex_1 == _idex_2) return _HEADER_POINTER;
		Vector* _Traversal_pointer_1 = new Vector;
		Vector* _Traversal_pointer_2 = new Vector;
		int _counter_1 = 0;
		int _counter_2 = 0;
		_Traversal_pointer_1 = _HEADER_POINTER;
		_Traversal_pointer_2 = _HEADER_POINTER;
		while (_counter_1 != _idex_1)
		{
			_counter_1++;
			_Traversal_pointer_1 = _Traversal_pointer_1->_NEXT_POINTER;
		}
		while (_counter_2 != _idex_2)
		{
			_counter_2++;
			_Traversal_pointer_2 = _Traversal_pointer_2->_NEXT_POINTER;
		}
		_Type _Temp_data;
		_Temp_data = _Traversal_pointer_1->_ELEMENT_DATA;
		_Traversal_pointer_1->_ELEMENT_DATA = _Traversal_pointer_2->_ELEMENT_DATA;
		_Traversal_pointer_2->_ELEMENT_DATA = _Temp_data;
		return _HEADER_POINTER;
	}
	
	//return the header node's value of this vector
	_Type _Front()
	{
		return _HEADER_POINTER->_ELEMENT_DATA;
	}

	//return the tail node's value of this vector
	_Type _Back()
	{
		return _TAIL_POINTER->_ELEMENT_DATA;
	}

	//merge two vector,please offer two sorted vector,or the result vector is not meaning
	//return the merge_vector of this two vector
	Vector _Merge(Vector _Dest_vector)
	{
		Vector _Res_vector;
		_Type* _All_Elements;
		_All_Elements = new _Type[_SIZE_ELEMENTS + _Dest_vector._SIZE_ELEMENTS];
		int counter_idex = 0;
		Vector* _Traversal_pointer_this = new Vector;
		Vector* _Traversal_pointer_dest = new Vector;
		_Traversal_pointer_this = _HEADER_POINTER;
		_Traversal_pointer_dest = _Dest_vector._HEADER_POINTER;
		while (_Traversal_pointer_dest != NULL&&_Traversal_pointer_this != NULL)
		{
			if (_Traversal_pointer_dest->_ELEMENT_DATA < _Traversal_pointer_this->_ELEMENT_DATA)
			{
				_All_Elements[counter_idex++] = _Traversal_pointer_dest->_ELEMENT_DATA;
				_Traversal_pointer_dest = _Traversal_pointer_dest->_NEXT_POINTER;
			}
			else{
				_All_Elements[counter_idex++] = _Traversal_pointer_this->_ELEMENT_DATA;
				_Traversal_pointer_this = _Traversal_pointer_this->_NEXT_POINTER;
			}
		}
		while (_Traversal_pointer_this != NULL)
		{
			_All_Elements[counter_idex++] = _Traversal_pointer_this->_ELEMENT_DATA;
			_Traversal_pointer_this = _Traversal_pointer_this->_NEXT_POINTER;
		}
		while (_Traversal_pointer_dest != NULL)
		{
			_All_Elements[counter_idex++] = _Traversal_pointer_dest->_ELEMENT_DATA;
			_Traversal_pointer_dest = _Traversal_pointer_dest->_NEXT_POINTER;
		}
		_Res_vector = _create_vector(_All_Elements, counter_idex);
		delete[] _All_Elements;
		return _Res_vector;
	}
	//clear this vector
	//return null 
	Vector* _Clear()
	{
		_HEADER_POINTER = NULL;
		_TAIL_POINTER = NULL;
		_SIZE_ELEMENTS = 0;
		return _HEADER_POINTER;
	}

	//print the vector out 
	void _print_vector()
	{
		Vector* _Traversal_pointer = new Vector;
		_Traversal_pointer = _HEADER_POINTER;
		while (_Traversal_pointer != NULL)
		{
			cout << _Traversal_pointer->_ELEMENT_DATA << " ";
			_Traversal_pointer = _Traversal_pointer->_NEXT_POINTER;
		}
		cout << endl;
	}

};

/*
编号：004_8
名字：_Binary_Tree
描述：二叉树类
备注：关于多叉树，在此不作叙述
*/
template<class _Type> class _Binary_Tree
{
public:
	_Type _Node_Data;
	_Binary_Tree *_Left_Child;
	_Binary_Tree *_Right_Child;
	_Binary_Tree *_Root_Pointer;
	int _Node_Size;
	_Binary_Tree()
	{
		_Root_Pointer = NULL;
		_Left_Child = NULL;
		_Right_Child = NULL;
		_Node_Size = 0;
	}
	//以前序形式输入节点，创建这棵树,以‘#’代表空节点
	//返回树的根节点，输入请合法
	_Binary_Tree* _Create_Tree_By_Preorder()
	{
		_Binary_Tree* Tree_Root_pointer = new _Binary_Tree;
		_Type _Append_node_data;
		while (cin >> _Append_node_data)
		{
			if (_Append_node_data == '#')
			{
				//this is a empty node
				Tree_Root_pointer = NULL;
			}
			else{
				Tree_Root_pointer = new _Binary_Tree;
				Tree_Root_pointer->_Node_Data = _Append_node_data;
				Tree_Root_pointer->_Left_Child = _Create_Tree_By_Preorder();
				Tree_Root_pointer->_Right_Child = _Create_Tree_By_Preorder();
			}
			return Tree_Root_pointer;
		}
	}

	//以中序形式输入节点，创建这棵树,以‘#’代表空节点
	//返回树的根节点，输入请合法
	_Binary_Tree* _Create_Tree_By_Inorder()
	{
		_Root_Pointer = new _Binary_Tree;
		_Type _Append_node_data;
		while (cin >> _Append_node_data)
		{
			if (_Append_node_data == '#')
			{
				//this is a empty node
				_Root_Pointer = NULL;
			}
			else{
				_Root_Pointer = new _Binary_Tree;
				_Root_Pointer->_Left_Child = _Create_Tree_By_Preorder();
				_Root_Pointer->_Node_Data = _Append_node_data;
				_Root_Pointer->_Right_Child = _Create_Tree_By_Preorder();
			}
			return _Root_Pointer;
		}	
	}

	//以后序形式输入节点，创建这棵树,以‘#’代表空节点
	//返回树的根节点，输入请合法
	_Binary_Tree* _Create_Tree_By_Postorder()
	{
		_Root_Pointer = new _Binary_Tree;
		_Type _Append_node_data;
		while (cin >> _Append_node_data)
		{
			if (_Append_node_data == '#')
			{
				//this is a empty node
				_Root_Pointer = NULL;
			}
			else{
				_Root_Pointer = new _Binary_Tree;
				_Root_Pointer->_Left_Child = _Create_Tree_By_Preorder();
				_Root_Pointer->_Right_Child = _Create_Tree_By_Preorder();
				_Root_Pointer->_Node_Data = _Append_node_data;
			}
			return _Root_Pointer;
		}
	}

	//先序遍历树,递归版本
	void _Preorder_Traversal_Recursive(_Binary_Tree* _Traversal_Root)
	{
		if (_Traversal_Root != NULL)
		{
			if (_Traversal_Root->_Node_Data!=NULL)
			cout << _Traversal_Root->_Node_Data << " ";
			_Preorder_Traversal_Recursive(_Traversal_Root->_Left_Child);
			_Preorder_Traversal_Recursive(_Traversal_Root->_Right_Child);
		}
	}

	//先序遍历，迭代版本
	void _Preorder_Traversal_Iterative(_Binary_Tree* _Traversal_Root)
	{
		if (_Traversal_Root == NULL) return;
		//需要使用栈来实现
		Stack<_Binary_Tree*> _Pre_Traversal_Stack;
		_Pre_Traversal_Stack._Push(_Traversal_Root);
		while (!_Pre_Traversal_Stack._Empty())
		{
			//因为先序遍历的思想是先根，后左子树，最后右子树
			//所以当栈不空时，先访问根，而后当右子树不空，进栈
			//最后判断左子树，不空则进栈
			_Binary_Tree* _Temp_pointer = new _Binary_Tree;
			_Temp_pointer = _Pre_Traversal_Stack._Top();
			_Pre_Traversal_Stack._Pop();
			cout << _Temp_pointer->_Node_Data << " ";
			if (_Temp_pointer->_Right_Child != NULL)
			{
				_Pre_Traversal_Stack._Push(_Temp_pointer->_Right_Child);
			}
			if (_Temp_pointer->_Left_Child != NULL)
			{
				_Pre_Traversal_Stack._Push(_Temp_pointer->_Left_Child);
			}
		}
	}

	//中序遍历，递归版本
	void _Inorder_Traversal_Recursive(_Binary_Tree* _Traversal_Root)
	{
		if (_Traversal_Root != NULL)
		{
			_Inorder_Traversal_Recursive(_Traversal_Root->_Left_Child);
			if (_Traversal_Root->_Node_Data != NULL)
			cout << _Traversal_Root->_Node_Data<<" ";
			_Inorder_Traversal_Recursive(_Traversal_Root->_Right_Child);
		}
	}

	//中序遍历，迭代版本
	void _Inorder_Traversal_Iterative(_Binary_Tree* _Traversal_pointer)
	{
		if (_Traversal_pointer == NULL) return;
		Stack<_Binary_Tree*> _In_Traversal_Stack;
		//根据中序遍历的思想，先访问左子树，然后反问根节点，最后访问右子树
		//所以用一个栈先将左子树都入栈，然后一一出栈访问，而后右子树进栈
		//如此反复知道栈为空
		_Binary_Tree* _Temp_pointer= new _Binary_Tree;
		_Temp_pointer = _Traversal_pointer;
		while (!_In_Traversal_Stack._Empty() || _Temp_pointer != NULL)
		{
			//左子树入栈
			while (_Temp_pointer != NULL)
			{
				_In_Traversal_Stack._Push(_Temp_pointer);
				_Temp_pointer = _Temp_pointer->_Left_Child;
			}
			//访问...
			if (!_In_Traversal_Stack._Empty())
			{
				_Temp_pointer = _In_Traversal_Stack._Top();
				_In_Traversal_Stack._Pop();
				cout << _Temp_pointer->_Node_Data<<" ";
				_Temp_pointer = _Temp_pointer->_Right_Child;
			}
		}
	}

	//后序遍历，递归版本
	void _Postorder_Traversal_Recursive(_Binary_Tree* _Traversal_Root)
	{
		if (_Traversal_Root != NULL)
		{
			_Postorder_Traversal_Recursive(_Traversal_Root->_Left_Child);
			_Postorder_Traversal_Recursive(_Traversal_Root->_Right_Child);
			if (_Traversal_Root->_Node_Data != NULL)
			cout << _Traversal_Root->_Node_Data << " ";
		}
	}

	//后序遍历，迭代版本
	void _Postorder_Traversal_Iterative(_Binary_Tree* _Traversal_Root)
	{
		if (_Traversal_Root == NULL) return;
		//根据后序遍历的思想，先遍历左子树，然后是右子树，最后才是根节点
		//那么现在的问题是什么时候可以访问根节点呢，因为在后续遍历中根节
		//点是右子树遍历完后才能访问的，所以用一个指针标记当前访问的节点
		//如果当前访问节点等于根节点的右子树，那么就可以访问根节点了

		Stack<_Binary_Tree*> _Post_Traversal_Stack;
		_Binary_Tree* _Pre_Visited = new _Binary_Tree;
		_Binary_Tree* _Cur_Visit = new _Binary_Tree;
		_Cur_Visit = _Traversal_Root;
		_Post_Traversal_Stack._Push(_Cur_Visit);
		_Cur_Visit = _Cur_Visit->_Left_Child;
		while (!_Post_Traversal_Stack._Empty())
		{
			//左子树入栈
			while (_Cur_Visit != NULL)
			{
				_Post_Traversal_Stack._Push(_Cur_Visit);
				_Cur_Visit = _Cur_Visit->_Left_Child;
			}
			_Pre_Visited = NULL;
			bool visited = true;
			while (visited==true&&!_Post_Traversal_Stack._Empty())
			{
				_Cur_Visit = _Post_Traversal_Stack._Top();
				if (_Cur_Visit->_Right_Child == _Pre_Visited)
				{
					cout << _Cur_Visit->_Node_Data << " ";
					_Post_Traversal_Stack._Pop();
					_Pre_Visited = _Cur_Visit;
				}
				else{
					_Cur_Visit = _Cur_Visit->_Right_Child;
					visited = false;
				}
			}
		}
	}

	//层序遍历，使用队列实现
	void _Sequenceorder_Traversal(_Binary_Tree* _Traversal_Root)
	{
		if (_Traversal_Root == NULL) return;
		deque<_Binary_Tree*> _Node_Elements;
		_Node_Elements.push_front(_Traversal_Root);
		while (!_Node_Elements.empty())
		{
			_Binary_Tree* _Temp_pointer = _Node_Elements.front();
			_Node_Elements.pop_front();
			cout << _Temp_pointer->_Node_Data << " ";
			if (_Temp_pointer->_Left_Child!=NULL)
			_Node_Elements.push_back(_Temp_pointer->_Left_Child);
			if (_Temp_pointer->_Right_Child!=NULL)
			_Node_Elements.push_back(_Temp_pointer->_Right_Child);
		}
	}

	//查找只等于给定值的第一个节点，返回节点指针
	_Binary_Tree* _Find_Node(_Binary_Tree* _Tree_Root_pointer,_Type _Dest_data)
	{
		//下面是递归出口
		if (_Tree_Root_pointer == NULL) return NULL;
		_Binary_Tree* _Res_pointer = new _Binary_Tree;
		_Res_pointer = _Tree_Root_pointer;
		if (_Res_pointer->_Node_Data == _Dest_data){
			return _Res_pointer;
		}
		//现看左子树，再看右子树
		return _Res_pointer = _Find_Node(_Res_pointer->_Left_Child, _Dest_data);
		return _Res_pointer = _Find_Node(_Res_pointer->_Right_Child, _Dest_data);
	}

	//统计给定值的节点数量
	int _Count_If(_Binary_Tree* _Tree_Root_pointer,_Type _Dest_Data)
	{
		if (_Tree_Root_pointer == NULL) return 0;
		if (_Tree_Root_pointer->_Node_Data == _Dest_Data)
		{
			return 1;
		}
		else{
			return _Count_If(_Tree_Root_pointer->_Left_Child, _Dest_Data) +
				   _Count_If(_Tree_Root_pointer->_Right_Child,_Dest_Data);
		}
	}

	//求树高度的算法
	int _Height(_Binary_Tree* _Tree_Root_pointer)
	{
		if (_Tree_Root_pointer == NULL) return 0;
		else
		{
			return max(_Height(_Tree_Root_pointer->_Left_Child),
				_Height(_Tree_Root_pointer->_Right_Child)) + 1;
		}
	}

	//叶子数量
	int _Leaf_Num(_Binary_Tree* _Tree_Root_pointer)
	{
		if (_Tree_Root_pointer == NULL) return 0;
		else
		{
			if (_Tree_Root_pointer->_Left_Child == NULL&&
				_Tree_Root_pointer->_Right_Child == NULL){
				return 1;
			}
			else{
				return (_Leaf_Num(_Tree_Root_pointer->_Leaf_Num) +
					_Leaf_Num(_Tree_Root_pointer->_Right_Child));
			}
		}
	}

	//求度为2的节点数量
	int _TwoDegree_Node_Num(_Binary_Tree* _Tree_Root_pointer)
	{
		if (_Tree_Root_pointer == NULL) return 0;
		if (_Tree_Root_pointer->_Left_Child != NULL&&
			_Tree_Root_pointer->_Right_Child != NULL)
		{
			return 1;
		}
		else{
			return _TwoDegree_Node_Num(_Tree_Root_pointer->_Left_Child)
				+ _TwoDegree_Node_Num(_Tree_Root_pointer->_Right_Child);
		}
	}

	//求一个节点的度
	int _Degree(_Binary_Tree* _This_pointer)
	{
		if (_This_pointer == NULL) return 0;
		if (_This_pointer->_Left_Child == NULL
			&&_This_pointer->_Right_Child == NULL)
		{
			return 0;
		}
		if (_This_pointer->_Left_Child != NULL&&
			_This_pointer->_Right_Child != NULL)
		{
			return 2;
		}
		if (_This_pointer->_Left_Child == NULL&&
			_This_pointer->_Right_Child != NULL)
		{
			return 1;
		}
		if (_This_pointer->_Left_Child != NULL&&
			_This_pointer->_Right_Child == NULL)
		{
			return 1;
		}
	}

	//求整棵树的节点度数之和
	int _Degree_Sum(_Binary_Tree* _Tree_Root_pointer)
	{
		if (_Tree_Root_pointer == NULL) return 0;
		int _Res_Num = 0;
		deque<_Binary_Tree*> _Node_Elements;
		_Node_Elements.push_front(_Tree_Root_pointer);
		while (!_Node_Elements.empty())
		{
			_Binary_Tree* _Temp_pointer = _Node_Elements.front();
			_Node_Elements.pop_front();
			_Res_Num += _Degree(_Temp_pointer);
			if (_Temp_pointer->_Left_Child != NULL)
				_Node_Elements.push_back(_Temp_pointer->_Left_Child);
			if (_Temp_pointer->_Right_Child != NULL)
				_Node_Elements.push_back(_Temp_pointer->_Right_Child);
		}
		return _Res_Num;
	}

	//判断一棵树是不是满树
	int _Full(_Binary_Tree* _Tree_Root_pointer)
	{
		//如果不存在度为1的节点，那么就是满树啦
		deque<_Binary_Tree*> _Node_Elements;
		_Node_Elements.push_front(_Tree_Root_pointer);
		while (!_Node_Elements.empty())
		{
			_Binary_Tree* _Temp_pointer = _Node_Elements.front();
			_Node_Elements.pop_front();
			if (_Degree(_Temp_pointer) == 1)
			{
				return false;
			}
			if (_Temp_pointer->_Left_Child != NULL)
				_Node_Elements.push_back(_Temp_pointer->_Left_Child);
			if (_Temp_pointer->_Right_Child != NULL)
				_Node_Elements.push_back(_Temp_pointer->_Right_Child);
		}
		return true;
	}

	//求一个节点的所有子孙节点值，将返回一个包含这些子孙节点值的vector容器
	//这个‘子孙’将包不含父亲节点本身，如果需要父亲节点，请将后面的语句加上注释
	Vector<_Type> _Descendants(_Binary_Tree* _Father_pointer)
	{
		Vector<_Type> _Res_vector;
		deque<_Binary_Tree*> _Node_Elements;
		_Node_Elements.push_front(_Father_pointer);
		while (!_Node_Elements.empty())
		{
			_Binary_Tree* _Temp_pointer = _Node_Elements.front();
			_Node_Elements.pop_front();
			_Res_vector._Push_back(_Temp_pointer->_Node_Data);
			if (_Temp_pointer->_Left_Child != NULL)
				_Node_Elements.push_back(_Temp_pointer->_Left_Child);
			if (_Temp_pointer->_Right_Child != NULL)
				_Node_Elements.push_back(_Temp_pointer->_Right_Child);
		}
		//including the parent node itself,if you  need this node's value,append this word
		_Res_vector._Pop_front();
		return _Res_vector;
	}
};
 
/*
编号：004_9
名字：_Sort
描述：排序算法类
*/
template<class _Type> class _sort
{
public:
	//bubble sort,return the array,if you want to sort the array from big to small
	//flag=true,or flag=false from small to big
	_Type* _Bubble_Sort(_Type* _Sort_array, int _size, bool flag)
	{
		for (int i = 0; i < _size - 1; i++){
			for (int j = i + 1; j < _size; j++){
				if (flag == true)
				{
					if (_Sort_array[i] < _Sort_array[j])
					{
						_Type _Temp_ = _Sort_array[i];
						_Sort_array[i] = _Sort_array[j];
						_Sort_array[j] = _Temp_;
					}
				}
				else{
					if (_Sort_array[i]>_Sort_array[j])
					{
						_Type _Temp_ = _Sort_array[i];
						_Sort_array[i] = _Sort_array[j];
						_Sort_array[j] = _Temp_;
					}
				}
			}
		}
		return _Sort_array;
	}

	//reverse an array
	_Type* _Reverse_Array(_Type* _Dest_Array, int _Array_size)
	{
		for (int i = 0; i < _Array_size / 2; i++)
		{
			_Type _Temp_Data = _Dest_Array[i];
			_Dest_Array[i] = _Dest_Array[_Array_size - 1 - i];
			_Dest_Array[_Array_size - 1 - i] = _Temp_Data;
		}
		return _Dest_Array;
	}

	//insert sort,return the array.sort the array from small to big
	//if you want to sort an array from big to small,reverse it by yourself
	_Type* _Insert_Sort(_Type* _Sort_array, int _size)
	{
		for (int i = 1; i < _size; i++)
		{
			_Type _Insert_data = _Sort_array[i];
			int idex = i - 1;
			while (idex >= 0 && _Sort_array[idex]>_Insert_data){
				_Sort_array[idex + 1] = _Sort_array[idex];
				idex--;
			}
			_Sort_array[idex + 1] = _Insert_data;
		}
		return _Sort_array;
	}

	//quick sort,return void.
	//using this algorithm as:_Quick_Sort(Sort_array,0,_Size-1).
	void _Quick_Sort(_Type* Sort_array, int _Left_idex, int _Right_idex)
	{
		if (_Left_idex > _Right_idex) return;
		_Type _Partition_data = Sort_array[_Left_idex];
		int _idex_left = _Left_idex;
		int _idex_right = _Right_idex;
		while (_idex_left != _idex_right)
		{
			//the right pointer first move,this is very important
			while (Sort_array[_idex_right] >= _Partition_data&&_idex_left < _idex_right){
				_idex_right--;
			}
			while (Sort_array[_idex_left] <= _Partition_data&&_idex_left < _idex_right){
				_idex_left++;
			}
			//change the two idex's value,and continue move two pointer
			if (_idex_left < _idex_right)
			{
				_Type _Temp_ = Sort_array[_idex_left];
				Sort_array[_idex_left] = Sort_array[_idex_right];
				Sort_array[_idex_right] = _Temp_;
			}
		}
		Sort_array[_Left_idex] = Sort_array[_idex_left];
		Sort_array[_idex_left] = _Partition_data;
		//dc
		_Quick_Sort(Sort_array, _Left_idex, _idex_left - 1);
		_Quick_Sort(Sort_array, _Left_idex + 1, _Right_idex);
	}

	//shell sort
	void _Shell_Sort(_Type* _Sort_array, int _size)
	{
		for (int _step_length = _size / 2; _step_length > 0; _step_length /= 2)
		{
			for (int i = 0; i < _step_length; i++)
			{
				for (int j = i + _step_length; j < _size; j += _step_length)
				{
					int _Insert_data = _Sort_array[j];
					int idex = j - _step_length;
					while (idex >= 0 && _Sort_array[idex]>_Insert_data){
						_Sort_array[idex + _step_length] = _Sort_array[idex];
						idex -= _step_length;
					}
					_Sort_array[idex + _step_length] = _Insert_data;
				}
			}
		}
	}

	//adjust a heap
	void _Adjust_Heap(_Type* _Adjust_array, int _root, int size)
	{
		//root .....child 
		int _left_child_idex = 2 * _root;
		int _right_child_idex = 2 * _root + 1;
		int _This_root = _root;
		if (_root <= size / 2)
		{
			if (_left_child_idex <= size&&
				_Adjust_array[_left_child_idex] > _Adjust_array[_This_root])
			{
				_This_root = _left_child_idex;
			}
			if (_right_child_idex <= size&&
				_Adjust_array[_right_child_idex] > _Adjust_array[_This_root])
			{
				_This_root = _right_child_idex;
			}
			if (_This_root != _root)
			{
				_Type _Temp_ = _Adjust_array[_This_root];
				_Adjust_array[_This_root] = _Adjust_array[_root];
				_Adjust_array[_root] = _Temp_;
				_Adjust_Heap(_Adjust_array, _This_root, size);
			}
		}
		//end
	}
	//heap sort
	void _Heap_Sort(_Type* _Sort_Array, int size)
	{
		//build the heap
		for (int i = size / 2; i >= 0; i--)
		{
			_Adjust_Heap(_Sort_Array, i, size - 1);
		}
		//start to heap sort
		for (int i = size - 1; i >0; i--)
		{
			//swap 0 and i
			_Type _Temp_ = _Sort_Array[0];
			_Sort_Array[0] = _Sort_Array[i];
			_Sort_Array[i] = _Temp_;
			//re-adjust this array to heap
			_Adjust_Heap(_Sort_Array, 0, i - 1);
		}
	}

	//merge two array
	void _Merge(_Type* _Merge_Array, int left_idex, int mid_idex, int right_idex)
	{
		int idex_1 = mid_idex - left_idex + 1;
		int idex_2 = right_idex - mid_idex;
		_Type* Left_Array = new _Type[idex_1 + 1];
		_Type* Right_Array = new _Type[idex_2 + 1];
		for (int i = 0; i < idex_1; i++)
		{
			Left_Array[i] = _Merge_Array[left_idex + i];
		}
		for (int j = 0; j < idex_2; j++)
		{
			Right_Array[j] = _Merge_Array[mid_idex + 1 + j];
		}
		int idex1 = 0;
		int idex2 = 0;
		int idex_start = left_idex;
		//merge
		while (idex1 < idex_1&&idex2 < idex_2)
		{
			if (Left_Array[idex1] < Right_Array[idex2])
			{
				_Merge_Array[idex_start++] = Left_Array[idex1++];
			}
			else{
				_Merge_Array[idex_start++] = Right_Array[idex2++];
			}
		}
		while (idex1 < idex_1)
		{
			_Merge_Array[idex_start++] = Left_Array[idex1++];
		}
		while (idex2 < idex_2)
		{
			_Merge_Array[idex_start++] = Right_Array[idex2++];
		}
		delete[] Left_Array;
		delete[] Right_Array;
		return;
		//end
	}
	//mergesort
	void _Merge_Sort(_Type* _Sort_Array, int _Left_idex, int _Right_idex)
	{
		int _Mid_idex;
		if (_Left_idex < _Right_idex)
		{
			_Mid_idex = (_Left_idex + _Right_idex) / 2;
			_Merge_Sort(_Sort_Array, _Left_idex, _Mid_idex);
			_Merge_Sort(_Sort_Array, _Mid_idex + 1, _Right_idex);
			_Merge(_Sort_Array, _Left_idex, _Mid_idex, _Right_idex);
		}
		return;
		//end
	}
};

/*
编号：004_10
名字：_Stack_List
描述：链栈类，前面写到的是数组实现，内存提前分配
*/
template<class _Type> class _Stack_List
{
public:
	_Type _Element_Data;
	_Stack_List* _Next_Pointer;
	_Stack_List* _Header_Pointer;
	_Stack_List* _Tail_Pointer;
	int _Element_Size;
	_Stack_List()
	{
		_Element_Size = 0;
		_Header_Pointer = NULL;
		_Tail_Pointer = NULL;
		_Tail_Pointer = _Header_Pointer;
	}

	//return the size of this stack
	int _Size()
	{
		return _Element_Size;
	}
	
	//judge if this stack is empty
	bool _Empty()
	{
		return _Header_Pointer == NULL;
	}

	//create a stack according to your offer element array
	//return this stack
	_Stack_List _Create_Stack(_Type* _Dest_Elements_array, int _size)
	{
		_Stack_List _Res_stack;
		_Res_stack._Header_Pointer = new _Stack_List;
		_Res_stack._Tail_Pointer = new _Stack_List;
		_Res_stack._Element_Size = 0;
		if (_size == 0) return _Res_stack;
		//first you need to create the header pointer of this vector
		_Stack_List* _header_pointer = new _Stack_List;
		_Stack_List* _tail_pointer = new _Stack_List;
		_header_pointer->_Element_Data= _Dest_Elements_array[0];
		_header_pointer->_Next_Pointer = NULL;
		_tail_pointer = _header_pointer;
		_tail_pointer->_Next_Pointer = NULL;
		//then,you can continue your work  
		for (int idex = 1; idex < _size; idex++)
		{
			_Stack_List* _append_pointer = new _Stack_List;
			_append_pointer->_Element_Data= _Dest_Elements_array[idex];
			_append_pointer->_Next_Pointer= NULL;
			_tail_pointer->_Next_Pointer= _append_pointer;
			_tail_pointer = _append_pointer;
			_tail_pointer->_Next_Pointer= NULL;
		}
		_Res_stack._Header_Pointer = _header_pointer;
		_Res_stack._Tail_Pointer= _tail_pointer;
		_Res_stack._Element_Size= _size;
		return _Res_stack;
	}

	//get the top node of this stack
	_Type _Top()
	{
		if (_Header_Pointer == NULL)
		{
			//this stack is null
			return 0x7fffffff;
		}
		return _Tail_Pointer->_Element_Data;
	}

	//pop a node 
	void _Pop()
	{
		if (_Header_Pointer == NULL) return;
		//get the pre-tail pointer
		_Stack_List* _Pre_tail_pointer = new _Stack_List;
		_Pre_tail_pointer = _Header_Pointer;
		while (_Pre_tail_pointer->_Next_Pointer->_Next_Pointer != NULL)
		{
			_Pre_tail_pointer = _Pre_tail_pointer->_Next_Pointer;
		}
		_Tail_Pointer = _Pre_tail_pointer;
		_Element_Size--;
		_Tail_Pointer->_Next_Pointer = NULL;
	}

	//push a node
	void _Push(_Type _Dest_Data)
	{
		if (_Header_Pointer == NULL)
		{
			//this header pointer is null,so create it
			_Header_Pointer = new _Stack_List;
			_Tail_Pointer = new _Stack_List;
			_Header_Pointer->_Element_Data = _Dest_Data;
			_Header_Pointer->_Next_Pointer = NULL;
			_Tail_Pointer = _Header_Pointer;
			_Tail_Pointer->_Next_Pointer = NULL;
			_Element_Size = 1;
			return;
		}
		_Stack_List* _Append_pointer = new _Stack_List;
		_Append_pointer->_Element_Data = _Dest_Data;
		_Append_pointer->_Next_Pointer = NULL;
		_Tail_Pointer->_Next_Pointer = _Append_pointer;
		_Tail_Pointer = _Append_pointer;
		_Tail_Pointer->_Next_Pointer = NULL;
		_Element_Size++;
		return;
	}

	//get all elements as a array
	//return this array
	_Type* _Get_All_Elements()
	{
		if (_Header_Pointer == NULL) return NULL;
		_Type* _Elements_Array = new _Type[_Element_Size];
		int idex = 0;
		_Stack_List* _Traversal_pointer = new _Stack_List;
		_Traversal_pointer = _Header_Pointer;
		while (_Traversal_pointer != NULL)
		{
			_Elements_Array[idex++] = _Traversal_pointer->_Element_Data;
			_Traversal_pointer = _Traversal_pointer->_Next_Pointer;
		}
		return _Elements_Array;
	}

	//swap two pointer
	//return the header pointer
	_Stack_List* _Swap(int idex_1, int idex_2)
	{
		if (idex_1 < 0 || idex_1 >= _Element_Size || idex_2 < 0 || idex_2 >= _Element_Size)
		{
			return _Header_Pointer;
		}
		if (idex_1 == idex_2) return _Header_Pointer;
		_Stack_List* _Traversal_pointer_1 = new _Stack_List;
		_Stack_List* _Traversal_pointer_2 = new _Stack_List;
		_Traversal_pointer_1 = _Header_Pointer;
		_Traversal_pointer_2 = _Header_Pointer;
		int counter_1 = 0;
		int counter_2 = 0;
		while (counter_1 < idex_1)
		{
			counter_1++;
			_Traversal_pointer_1 = _Traversal_pointer_1->_Next_Pointer;
		}
		while (counter_2 < idex_2)
		{
			counter_2++;
			_Traversal_pointer_2 = _Traversal_pointer_2->_Next_Pointer;
		}
		//swap
		_Type _Temp_ = _Traversal_pointer_1->_Element_Data;
		_Traversal_pointer_1->_Element_Data = _Traversal_pointer_2->_Element_Data;
		_Traversal_pointer_2->_Element_Data = _Temp_;
		return _Header_Pointer;
	}

	//emplace a node if equal 
	//return the header pointer of this stack
	_Stack_List* _Emplace_If(_Type _Find_data,_Type _Change_To_Data)
	{
		if (_Header_Pointer == NULL) return _Header_Pointer;
		_Stack_List* _Traversal_pointer = new _Stack_List;
		_Traversal_pointer = _Header_Pointer;
		while (_Traversal_pointer != NULL)
		{
			if (_Traversal_pointer->_Element_Data == _Find_data)
			{
				//change this node's value
				_Traversal_pointer->_Element_Data = _Change_To_Data;
			}
			_Traversal_pointer = _Traversal_pointer->_Next_Pointer;
		}
		return _Traversal_pointer;
	}
	//judge if exist a value node
	//if exist,return the idex,or return -1
	int _Exist(_Type _Dest_Data)
	{
		if (_Header_Pointer == NULL) return -1;
		int idex = 0;
		_Stack_List* _Traversal_pointer = new _Stack_List;
		_Traversal_pointer = _Header_Pointer;
		while (_Traversal_pointer != NULL)
		{
			if (_Traversal_pointer->_Element_Data == _Dest_Data)
			{
				return idex;
			}
			idex++;
			_Traversal_pointer = _Traversal_pointer->_Next_Pointer;
		}
		//error or not find 
		return -1;
	}

	//counter if equal
	int _Count_If(_Type _Dest_data)
	{
		if (_Header_Pointer == NULL) return 0;
		int _Res_Num = 0;
		_Stack_List* _Trsversal_pointer = new _Stack_List;
		_Trsversal_pointer = _Header_Pointer;
		while (_Trsversal_pointer != NULL)
		{
			if (_Trsversal_pointer->_Element_Data == _Dest_data)
			{
				_Res_Num++;
			}
			_Trsversal_pointer = _Trsversal_pointer->_Next_Pointer;
		}
		return _Res_Num;
	}

	//print this stack
	void _Print()
	{

		_Stack_List* _Traversal_pointer = new _Stack_List;
		_Traversal_pointer = _Header_Pointer;


		while (_Traversal_pointer!=NULL)
		{
			cout << _Traversal_pointer->_Element_Data << " ";
			_Traversal_pointer = _Traversal_pointer->_Next_Pointer;
		}
		cout << endl;
	}
};

/*
编号：004_11
名字：_Array_List
描述：链数组类
备注：动态分配内存，以数组方式访问,将动态申请_Initialization_Size个空间
*/
template<class _Type, int _Initialization_Size> class _Array_List
{
public:
	_Type _Element_Data;
	_Array_List* _Header_Pointer;
	_Array_List* _Tail_Pointer;
	_Array_List* _Next_Pointer;
	int _Element_Size;
	_Array_List()
	{
		_Header_Pointer = NULL;
		_Tail_Pointer = NULL;
		_Element_Size = 0;
	}

	//apply memory ,return the list array
	//_Initialization the array's value as 0
	_Array_List _Apply_Memory()
	{
		_Array_List _Res_Array;
		_Res_Array._Element_Size = 0;
		_Res_Array._Header_Pointer = NULL;
		_Res_Array._Tail_Pointer = NULL;
		if (_Initialization_Size <= 0) return _Res_Array;
		//create the header pointer 
		_Array_List* _Array_header_pointer = new _Array_List;
		_Array_List* _Array_tail_pointer = new _Array_List;
		_Array_header_pointer->_Element_Data = 0;
		_Array_header_pointer->_Next_Pointer = NULL;
		_Array_tail_pointer = _Array_header_pointer;
		_Array_tail_pointer->_Next_Pointer = NULL;
		for (int idex = 1; idex != _Initialization_Size; idex++)
		{
			_Array_List* _Append_pointer = new _Array_List;
			_Append_pointer->_Element_Data = 0;
			_Append_pointer->_Next_Pointer = NULL;
			_Array_tail_pointer->_Next_Pointer = _Append_pointer;
			_Array_tail_pointer = _Append_pointer;
			_Array_tail_pointer->_Next_Pointer = NULL;
		}
		_Res_Array._Header_Pointer = _Array_header_pointer;
		_Res_Array._Tail_Pointer = _Array_tail_pointer;
		_Res_Array._Element_Size = _Initialization_Size;
		return _Res_Array;
	}
	//operator []
	//return this idex's value
	_Type operator[](int idex)
	{
		if (idex < 0 || idex >=_Element_Size) return NULL;
		//find the idex
		int counter = 0;
		_Array_List* _Traversal_pointer = new _Array_List;
		_Traversal_pointer = _Header_Pointer;
		while (counter != idex)
		{
			counter++;
			_Traversal_pointer = _Traversal_pointer->_Next_Pointer;
		}
		return _Traversal_pointer->_Element_Data;
	}
	//assign a value
	void _Assign_At(int idex, _Type _Dest_Data)
	{
		if (idex < 0||idex>_Element_Size) return;
		if (idex == 0)
		{
			if (_Header_Pointer == NULL) _Element_Size++;
			//you want to build heap root 
			_Array_List* _Append_pointer = new _Array_List;
			_Append_pointer->_Element_Data = _Dest_Data;
			_Append_pointer->_Next_Pointer = _Header_Pointer;
			_Header_Pointer = _Append_pointer;
			return;
		}

		if (idex == _Element_Size)
		{
			//you need to create a new pointer append to tail pointer
			_Array_List* _Append_pointer = new _Array_List;
			_Append_pointer->_Element_Data = _Dest_Data;
			_Append_pointer->_Next_Pointer = NULL;
			_Tail_Pointer->_Next_Pointer = _Append_pointer;
			_Tail_Pointer = _Append_pointer;
			_Tail_Pointer->_Next_Pointer = NULL;
			_Element_Size++;
			return;
		}
		int counter = 0;
		_Array_List* _Traversal_pointer = new _Array_List;
		_Traversal_pointer = _Header_Pointer;
		while (counter < idex)
		{
			counter++;
			_Traversal_pointer = _Traversal_pointer->_Next_Pointer;
		}
		_Traversal_pointer->_Element_Data = _Dest_Data;
		return;
		//end
	}
	//print this array 
	void _print()
	{
		_Array_List* _Traversal_pointer = new _Array_List;
		_Traversal_pointer = _Header_Pointer;
		int counter_idex = 0;
		while (_Traversal_pointer!=NULL)
		{
			cout << _Traversal_pointer->_Element_Data << " ";
			counter_idex++;
			_Traversal_pointer = _Traversal_pointer->_Next_Pointer;
		}
		cout << endl;
	}
};

/*
编号：004_12
名字：_Priority_queue
描述：优先队列类
备注：如果你想要从大到小取出元素，请将_Flag_置位true，否则置位false
*/
template<int _heap_size, class _Type, bool _Flag_> class _Priority_queue
{
public:
	_Array_List<_Type, _heap_size> _Heap_array;

	_Priority_queue()
	{
		_Heap_array._Element_Size = _heap_size;
		_Heap_array = _Heap_array._Apply_Memory();
	}
	//give this array value
	void _Assign_This_Array(_Type* _Elements_Array, int size)
	{
		for (int i = 0; i < size; i++)
		{
			_Heap_array._Assign_At(i, _Elements_Array[i]);
		}
		_Heap(size);
	}
	//adjust a heap 
	void _Adjust_Heap(int _Root_idex, int size)
	{
		int _Left_Child_idex = 2 * _Root_idex;
		int _Right_Child_idex = _Left_Child_idex + 1;
		int _This_Root_idex = _Root_idex;
		if (_Root_idex <= size / 2)
		{
			if (_Flag_== true){
				if (_Left_Child_idex <= size&&
					_Heap_array[_Left_Child_idex] > _Heap_array[_Root_idex]){
					_This_Root_idex = _Left_Child_idex;
				}
				if (_Right_Child_idex <= size&&
					_Heap_array[_Right_Child_idex] > _Heap_array[_Root_idex]){
					_This_Root_idex = _Right_Child_idex;
				}
				if (_Root_idex != _This_Root_idex)
				{
					_Type _Temp_ = _Heap_array[_Root_idex];
					_Heap_array._Assign_At(_Root_idex, _Heap_array[_This_Root_idex]);
					_Heap_array._Assign_At(_This_Root_idex, _Temp_);
					_Adjust_Heap(_This_Root_idex, size);
				}
			}
			else{
				if(_Left_Child_idex <= size&&
					_Heap_array[_Left_Child_idex] < _Heap_array[_Root_idex]){
					_This_Root_idex = _Left_Child_idex;
				}
				if (_Right_Child_idex <= size&&
					_Heap_array[_Right_Child_idex] < _Heap_array[_Root_idex]){
					_This_Root_idex = _Right_Child_idex;
				}
				if (_Root_idex != _This_Root_idex)
				{
					_Type _Temp_ = _Heap_array[_Root_idex];
					_Heap_array._Assign_At(_Root_idex, _Heap_array[_This_Root_idex]);
					_Heap_array._Assign_At(_This_Root_idex, _Temp_);
					_Adjust_Heap(_This_Root_idex, size);
				}
			}
		}
	}

	//build this heap
	void _Heap(int size)
	{
		for (int i = size / 2; i >= 0; i--)
		{
			_Adjust_Heap(i, size - 1);
		}

		for (int i = size - 1; i > 0; i--)
		{
			_Type _Temp_ = _Heap_array[0];
			_Heap_array._Assign_At(0, _Heap_array[i - 1]);
			_Heap_array._Assign_At(i - 1, _Temp_);
			_Adjust_Heap(0, i - 1);
		}
	}

	//get the top value
	_Type _Top()
	{
		return _Heap_array[_Heap_array._Element_Size-1];
	}

	//push a node
	void _Push(_Type _Dest_Data)
	{
		_Heap_array._Assign_At(_Heap_array._Element_Size, _Dest_Data);	
		//adjust heap
		_Heap_array._Element_Size++;
		_Heap(_Heap_array._Element_Size);
	}
	//pop the top pointer
	void _Pop()
	{
		_Heap_array._Element_Size--;
	}

	//judge if empty
	bool _Empty()
	{
		return _Heap_array._Element_Size == 0;
	}

	//return heap size
	int _Size()
	{
		return _Heap_array._Element_Size;
	}
	//emplace if equal
	void _Emplace(_Type _Find_Data, _Type _Change_To_Data)
	{
		for (int i = 0; i < _Heap_array._Element_Size; i++)
		{
			if (_Heap_array[i] == _Find_Data)
			{
				_Heap_array._Assign_At(i, _Change_To_Data);
			}
		}
		return;
	}
	//swap two idex's value
	void _Swap(int _idex_1, int _idex_2)
	{
		if (_idex_1 < 0 || _idex_1 >= _Heap_array._Element_Size ||
			_idex_2 < 0 || _idex_2 >= _Heap_array._Element_Size||
			_idex_1==_idex_2){
			return;
		}
		_Type _Temp_ = _Heap_array[_idex_1];
		_Heap_array._Assign_At(_idex_1, _Heap_array[_idex_2]);
		_Heap_array._Assign_At(_idex_2, _Temp_);
		return;
	}
	//print this heap
	void _print()
	{
		_Heap_array._print();
	}
};

/*
编号：004_13
名字：_Huffman_Tree
描述：Huffman树与应用类
备注：本类仅对小写英文字符实现，对于不同需求，请自行修改代码
*/
class _Huffman_Tree
{
public:
	//the character and num
	//_Character_Num[character-'a'].
	int _Character_Num[26];
	int _All_Character_Num;
	char _Element_Data;
	int _Cost_character;
	_Huffman_Tree* _Root_Pointer;
	_Huffman_Tree* _Left_child_pointer;
	_Huffman_Tree* _Right_child_pointer;

	struct _character_code
	{
		char value;
		string code;
	};
	Vector<_character_code> _Huffman_code;

	_Huffman_Tree()
	{
		memset(_Character_Num, 0, sizeof(_Character_Num));
		_All_Character_Num = 0;
		_Root_Pointer = NULL;
	}

	_Huffman_Tree(char _Value, int _Weight, _Huffman_Tree* left_child, _Huffman_Tree* right_child)
	{
		_Element_Data = _Value;
		_Cost_character = _Weight;
		_Left_child_pointer = left_child;
		_Right_child_pointer = right_child;
	}

	//judge if this node is leaf node
	bool leaf()
	{
		return _Left_child_pointer == NULL&&_Right_child_pointer == NULL;
	}

	//you need to offer a file that stored the txt
	//count num
	void _Count_character_nums(string filename)
	{
		//open file
		ifstream _Open;
		_Open.open(filename);
		string _Line;
		while (getline(_Open, _Line))
		{
			for (int i = 0; i < _Line.length(); i++)
			{
				if (_Character_Num[(size_t)(_Line[i] - 'a')] == 0){
					_All_Character_Num++;
				}
				_Character_Num[(size_t)(_Line[i] - 'a')]++;
			}
		}
		_Open.close();
	}

	//function pointer
	class _small_big
	{
	public:
		bool operator()(_Huffman_Tree* pointer1, _Huffman_Tree* pointer2)
		{
			return pointer1->_Cost_character > pointer2->_Cost_character;
		}
	};

	//build huffman tree
	//return the root pointer of this huffman tree
	_Huffman_Tree* _Create_Huffman_Tree()
	{
		priority_queue<_Huffman_Tree*, vector<_Huffman_Tree*>,_small_big > _My_queue;
		//first push these leaf node into queue
		for (int i = 0; i <26; i++){
			if (_Character_Num[i] != 0)
			{
				_Huffman_Tree* _append_pointer = new _Huffman_Tree((char)('a' + i),
					_Character_Num[i], NULL, NULL);
				_My_queue.push(_append_pointer);
			}
		}
		//create this huffman tree
		while (_My_queue.size()>1)
		{
			_Huffman_Tree* _min_pointer_1 = new _Huffman_Tree;
			_Huffman_Tree* _min_pointer_2 = new _Huffman_Tree;
			_min_pointer_1 = _My_queue.top();
			_My_queue.pop();
			_min_pointer_2 = _My_queue.top();
			_My_queue.pop();
			_Huffman_Tree* _Append_pointer = new _Huffman_Tree(NULL,
				_min_pointer_1->_Cost_character +
				_min_pointer_2->_Cost_character,
				_min_pointer_1, _min_pointer_2);
			_My_queue.push(_Append_pointer);
		}
		return _My_queue.top();
	}

	//Encode huffman code
	//return void
	void _Encode_huffman(_Huffman_Tree* _root_pointer,string _huffman_code)
	{
		if (_root_pointer->leaf())
		{
			//this pointer is leaf node,so create it
			_character_code _append_code;
			_append_code.value = _root_pointer->_Element_Data;
			_append_code.code = _huffman_code;
			_Huffman_code._Push_back(_append_code);
			return;
		}
		string _left_code = _huffman_code;
		string _right_code = _huffman_code;
		_left_code += '1';
		_right_code += '0';
		_Encode_huffman(_root_pointer->_Left_child_pointer, _left_code);
		_Encode_huffman(_root_pointer->_Right_child_pointer, _right_code);
	}

	//Decode,so you need to offer a filename
	//this file need including some huffman code
	//the fuction will decode these huffman code 
	void _Decode_huffman(_Huffman_Tree* _root_pointer,string filename)
	{
		ifstream _read_file_stream;
		_read_file_stream.open(filename);
		string _read_one_line;
		while (getline(_read_file_stream, _read_one_line))
		{
			_Huffman_Tree* _decode_pointer = new _Huffman_Tree;
			_decode_pointer = _root_pointer;
			for (int i = 0; i < _read_one_line.length(); i++)
			{
				if (_decode_pointer->leaf())
				{
					//this node is leaf node,so decode it
					cout << _decode_pointer->_Element_Data << " ";
					//return this decode pointer back root pointer
					_decode_pointer = _root_pointer;
				}
				if (_read_one_line[i] == '1')
				{
					_decode_pointer = _decode_pointer->_Left_child_pointer;
				}
				if (_read_one_line[i] == '0')
				{
					_decode_pointer = _decode_pointer->_Right_child_pointer;
				}
			}
		}
		_read_file_stream.close();
	}
};

/*
编号：004_14
名字：_Binary_Sort_Tree
描述：二叉排序树
*/
template<class _Type> class _Binary_Sort_Tree
{
public:
	_Type _Element_Value;
	_Binary_Sort_Tree* _Root_Pointer;
	_Binary_Sort_Tree* _Left_Child_Pointer;
	_Binary_Sort_Tree* _Right_Child_Pointer;
	int _Elements_size;
	_Binary_Sort_Tree()
	{
		_Elements_size = 0;
		_Root_Pointer = NULL;
	}

	//judge leaf
	bool _Leaf()
	{
		return _Left_Child_Pointer == NULL&&_Right_Child_Pointer == NULL;
	}

	//insert a node,return the root pointer
	_Binary_Sort_Tree* _Insert_(_Binary_Sort_Tree* _root_pointer,_Type _Dest_Data)
	{
		//if this root is null,you should create the pointer
		if (_root_pointer == NULL)
		{
			_Binary_Sort_Tree* _New_root_pointer = new _Binary_Sort_Tree;
			_New_root_pointer->_Element_Value = _Dest_Data;
			_New_root_pointer->_Left_Child_Pointer = NULL;
			_New_root_pointer->_Right_Child_Pointer = NULL;
			_Elements_size++;
			return _New_root_pointer;
		}
		else if (_root_pointer->_Element_Value == _Dest_Data)
		{
			//there is a same value node has exised
			return _root_pointer;
		}
		else{
			if (_Dest_Data < _root_pointer->_Element_Value)
			{
				//left tree
				_root_pointer->_Left_Child_Pointer = _Insert_(_root_pointer->_Left_Child_Pointer, _Dest_Data);
			}
			else{
				//right tree
				_root_pointer->_Right_Child_Pointer = _Insert_(_root_pointer->_Right_Child_Pointer, _Dest_Data);
			}
			return _root_pointer;
		}
	}

	//find a node
	bool _find(_Binary_Sort_Tree* _root_pointer, _Type _Dest_Data)
	{
		if (_root_pointer == NULL) return false;
		if (_root_pointer->_Element_Value == _Dest_Data) return true;
		if (_Dest_Data < _root_pointer->_Element_Value)
		{
			//left tree
			return _find(_root_pointer->_Left_Child_Pointer, _Dest_Data);
		}
		else{
			//right tree
			return _find(_root_pointer->_Right_Child_Pointer, _Dest_Data);
		}
	}

	//sort,so you need give an elements array for create the binary balance tree
	//this function will return the root pointer of this binary balance tree
	_Binary_Sort_Tree* _Create_Binary_Balance_Tree(_Type* _Elements_Array, int size)
	{
		_Binary_Sort_Tree* _root_pointer = new _Binary_Sort_Tree;
		for (int i = 0; i < size; i++)
		{
			_root_pointer = _Insert_(_root_pointer, _Elements_Array[i]);
		}
		return _root_pointer;
	}



	//delete a node in this bst
	_Binary_Sort_Tree* _Delete(_Binary_Sort_Tree* _root_pointer, _Type _Dest_Data)
	{
		/*
		    * delete a node,there are three cases:
			*1.the node we want to delete's left child is null,then just let the right node replace the node we delete
			*2.the node we want to delete's left 's right node is null,then just let the left node replace the node we delete
			*3.if not case 1 or case 2,then just find the most biggest node in the tree that we want to delete's left child tree
		    *  then let the node replac the node we want to delete
		*/
		if (_root_pointer == NULL) return NULL;
		else if (_Dest_Data < _root_pointer->_Element_Value)
		{
			//left child tree
			_root_pointer->_Left_Child_Pointer = _Delete(_root_pointer->_Left_Child_Pointer, _Dest_Data);
		}
		else if (_Dest_Data>_root_pointer->_Element_Value) 
		{
			//right child tree
			_root_pointer->_Right_Child_Pointer = _Delete(_root_pointer->_Right_Child_Pointer, _Dest_Data);
		}
		//case 1
		else if (_root_pointer->_Left_Child_Pointer == NULL)
		{
			_Binary_Sort_Tree*_Append_pointer = new _Binary_Sort_Tree;
			_Append_pointer = _root_pointer->_Right_Child_Pointer;
			//delete the node
			delete _root_pointer;
			//let this append pointer replace the node we delete
			return _Append_pointer;
		}
		//case 2
		else if (_root_pointer->_Left_Child_Pointer->_Right_Child_Pointer == NULL)
		{
			_Binary_Sort_Tree* _Append_pointer = new _Binary_Sort_Tree;
			_Append_pointer = _root_pointer->_Left_Child_Pointer;
			_Append_pointer->_Right_Child_Pointer = _root_pointer->_Right_Child_Pointer;
			//delete the node
			delete _root_pointer;
			//let the append pointer replace the node we delete
			return _Append_pointer;
		}
		//case 3
		else
		{
			//this is very complex,slow.....
			_Binary_Sort_Tree* _Append_pointer = new _Binary_Sort_Tree;
			//find the delete node's left child tree's most biggest node
			_Append_pointer = _root_pointer->_Left_Child_Pointer;
			while (_Append_pointer->_Right_Child_Pointer->_Right_Child_Pointer != NULL)
			{
				_Append_pointer = _Append_pointer->_Right_Child_Pointer;
			}
			//in this position,please use your pen to judge .....
			_Binary_Sort_Tree* _The_pointer = new _Binary_Sort_Tree;
			_The_pointer = _Append_pointer->_Right_Child_Pointer;
			_Append_pointer->_Right_Child_Pointer = _The_pointer->_Left_Child_Pointer;
			_The_pointer->_Left_Child_Pointer = _root_pointer->_Left_Child_Pointer;
			_The_pointer->_Right_Child_Pointer = _root_pointer->_Right_Child_Pointer;
			//delete the node we want to delete
			delete _root_pointer;
			//let the node we find replace the node we deleted
			return _The_pointer;
		}
		//the end..
		return _root_pointer;
	}


	//get the size of this tree's node
	int _Size(_Binary_Sort_Tree* _root_pointer)
	{
		return _Elements_size;
	}

	//get all element data in this binary balance tree
	//return this elements array
	_Type* _Get_All_Elements(_Binary_Sort_Tree* _Traversal_pointer)
	{
		_Type* _Elements_Array;
		_Elements_Array = new _Type[_Elements_size];
		if (_Traversal_pointer == NULL) return _Elements_Array;
		Stack<_Binary_Sort_Tree*> _In_Traversal_Stack;
		//根据中序遍历的思想，先访问左子树，然后反问根节点，最后访问右子树
		//所以用一个栈先将左子树都入栈，然后一一出栈访问，而后右子树进栈
		//如此反复知道栈为空
		_Binary_Sort_Tree* _Temp_pointer = new _Binary_Sort_Tree;
		_Temp_pointer = _Traversal_pointer;
		int counter_idex = 0;
		while (!_In_Traversal_Stack._Empty() || _Temp_pointer != NULL)
		{
			//左子树入栈
			while (_Temp_pointer != NULL)
			{
				_In_Traversal_Stack._Push(_Temp_pointer);
				_Temp_pointer = _Temp_pointer->_Left_Child_Pointer;
			}
			//访问...
			if (!_In_Traversal_Stack._Empty())
			{
				_Temp_pointer = _In_Traversal_Stack._Top();
				_In_Traversal_Stack._Pop();
				if(_Temp_pointer->_Element_Value!=NULL)
				_Elements_Array[counter_idex++] = _Temp_pointer->_Element_Value;
				_Temp_pointer = _Temp_pointer->_Right_Child_Pointer;
			}
		}
		return _Elements_Array;
	}

	//reverse an array
	_Type* _Reverse_Array(_Type* _Dest_Array, int _Array_size)
	{
		for (int i = 0; i < _Array_size / 2; i++)
		{
			_Type _Temp_Data = _Dest_Array[i];
			_Dest_Array[i] = _Dest_Array[_Array_size - 1 - i];
			_Dest_Array[_Array_size - 1 - i] = _Temp_Data;
		}
		return _Dest_Array;
	}

	//sort ,if you want to sort this arrray from big to small,please let flag=true
	//else please let flag=false,this function will return a sorted array
	_Type* _Sort(bool flag,_Binary_Sort_Tree* _root_pointer)
	{
		_Type* _Elements_Array = new _Type[_Elements_size];
		_Elements_Array = _Get_All_Elements(_root_pointer);
		if (flag == true)
		{
			_Elements_Array = _Reverse_Array(_Elements_Array, _Elements_size);
		}
		return _Elements_Array;
	}

	//preorder traversal
	void _Inorder_Traversal(_Binary_Sort_Tree* _root_pointer)
	{
		if (_root_pointer != NULL)
		{
			_Inorder_Traversal(_root_pointer->_Left_Child_Pointer);
			if (_root_pointer->_Element_Value != NULL)
			{
				cout << _root_pointer->_Element_Value << " ";
			}
			_Inorder_Traversal(_root_pointer->_Right_Child_Pointer);
		}
	}

};


/*
编号：004_15
名字：_Key_Tree
描述：字典树类
  *just for char type.
  *if this class's function runtime error please check the detals 
  *in this class,I have give many detals for users.thanks!
*/
class _Key_Tree
{
public:
	//the node's value world
	string _Node_Word;
	//the flag of world
	bool _Exist_Word;
	//next pointers,please just insert the lower case character
	//or,this class's function will return wrong reslut or error 
	_Key_Tree* _Next_Pointers[26];
	//the root of this tree
	_Key_Tree* _Root_Pointer;
	//the nums of world
	int _Word_Num;

	_Key_Tree()
	{
		_Node_Word = "";
		_Exist_Word = false;
		_FOR_(i, 26) _Next_Pointers[i] = NULL;
		_Root_Pointer = NULL;
		_Word_Num = 0;
	}

	//insert a word into this key tree
	//please input the root of the key tree
	//and this function will return the root pointer of this tree
	_Key_Tree* _Insert_(_Key_Tree* _root_pointer, string _Dest_Word)
	{
		int _idex_ = 0;
		_Key_Tree* _Append_pointer = new _Key_Tree;
		_Append_pointer = _root_pointer;
		//insert
		for (_idex_; _idex_ < _Dest_Word.length(); _idex_++)
		{
			if (_Append_pointer->_Next_Pointers[_Dest_Word[_idex_] - 'a'] == NULL)
			{
				//this node is null,so you need to create the node 
				//append a node and init this node
				_Key_Tree* _New_Node_pointer = new _Key_Tree;
				_New_Node_pointer->_Node_Word =
					_Append_pointer->_Node_Word + _Dest_Word[_idex_];
				//append this new node
				_Append_pointer->_Next_Pointers[_Dest_Word[_idex_] - 'a']
					= _New_Node_pointer;
			}
			//the append pointer forword 
			_Append_pointer = _Append_pointer->_Next_Pointers[_Dest_Word[_idex_] - 'a'];
		}
		//insert a node sucessfully
		//so,this node has a word and the sum of word add 1
		_Append_pointer->_Exist_Word = true;
		//if error.please check the root pointer
		//before using a new pointer,you must assign memory for this new pointer
		//so,if something wrong,check if you are using pointer whitout new it
		_root_pointer->_Word_Num++;
		return _root_pointer;
	}

	//search a world,return true or false
	//please offer your key tree's root pointer
	bool _find_(_Key_Tree* _root_pointer, string _Dest_Word)
	{
		int idex = 0;
		_Key_Tree* _Traversal_pointer = new _Key_Tree;
		_Traversal_pointer = _root_pointer;
		while (_Traversal_pointer!=NULL&&idex!=_Dest_Word.length())
		{
			_Traversal_pointer = _Traversal_pointer->
				_Next_Pointers[_Dest_Word[idex++] - 'a'];
		}
		if (idex == _Dest_Word.length())
		{
			//find the word
			return true;
		}
		else{
			return false;
		}
	}

	//if you offer a words file,using this function to build your key tree
	//this function will read word from file and return the root pointer of this
	//key tree,please offer your key tree's root pointer
	_Key_Tree* _Create_key_tree_from_file(_Key_Tree* _root_pointer,string filename)
	{
		ifstream _read_file_stream;
		_read_file_stream.open(filename);
		string _read_one_line;
		while (getline(_read_file_stream, _read_one_line))
		{
			string _a_word = "";
			_FOR_(idex, _read_one_line.size())
			{
				if (_read_one_line[idex] >= 'a'&&
					_read_one_line[idex] <= 'z')
				{
					_a_word += _read_one_line[idex];
				}
				else{
					//this is a word ,insert the word into the key tree
					_root_pointer = _Insert_(_root_pointer, _a_word);
					_a_word = "";
				}
			}
		}
		_read_file_stream.close();
		//....the end......
		return _root_pointer;
	}

	//the size of this key tree's word
	int _size()
	{
		return _Root_Pointer->_Word_Num;
	}

	//give the prefix word,return all word have the same prefix word
	//you need to offer the root pointer of your key tree
	//this function will return a Vector Type varable
	Vector<string> _sufffix_words(_Key_Tree* _root_pointer, string prefix)
	{
		//this Vector is my Vector 
		//not the vector of stl
		Vector<string> _Res_Vec;
		_Res_Vec._Clear();
		if (_root_pointer == NULL || !_find_(_Root_Pointer, prefix))
		{
			//find the prefix fail,return empty vector
			return _Res_Vec;
		}
		//first you need to find the node 
		_Key_Tree* _prefix_pointer = new _Key_Tree;
		_prefix_pointer = _root_pointer;
		int idex = 0;
		for (idex; idex < prefix.length(); idex++)
		{
			_prefix_pointer = _prefix_pointer->_Next_Pointers[prefix[idex] - 'a'];
		}
		//suffix_pointer
		_Key_Tree* _suffix_pointer = new _Key_Tree;
		_suffix_pointer = _prefix_pointer;
		//bsf to find the word
		queue<_Key_Tree*> my_queue;
		my_queue.push(_suffix_pointer);
		while (!my_queue.empty())
		{
			_Key_Tree* _check_pointer = new _Key_Tree;
			_check_pointer = my_queue.front();
			my_queue.pop();
			if (_check_pointer->_Exist_Word)
			{
				_Res_Vec._Push_back(_check_pointer->_Node_Word);
			}
			_FOR_(i, 26)
			{
				if (_check_pointer->_Next_Pointers[i] != NULL)
				{
					my_queue.push(_check_pointer->_Next_Pointers[i]);
				}
			}
		}//..end while....
		return _Res_Vec;
	}

	//find the common prefix word
	//if find the world,return the common prefix,else return null
	string _common_prefix_word(Vector<string> _word_vec)
	{
		string _res_str = "";
		if (_word_vec._Size()== 0)
		{
			return _res_str;
		}
		int _prefix_word_length = 0;
		int _limited_length = 0x7fffffff;
		//first you need to find the limited length
		//the limited length is the min length of this vector
		string _limited_str;
		_FOR_(i, _word_vec._Size())
		{
			_limited_length = min(_limited_length, _word_vec._At(i).length());
			if (_limited_length > _word_vec._At(i).length())
			{
				_limited_str = _word_vec._At(i);
			}
		}
		while (_prefix_word_length!=_limited_length)
		{
			_res_str += _word_vec._At(0)[_prefix_word_length++];
			bool _common_prefix = true;
			for (int idex = 0; idex != _word_vec._Size(); idex++)
			{
				if (_res_str != _word_vec._At(idex).substr(0, _prefix_word_length))
				{
					_common_prefix = false;
					break;
				}
			}
			if (!_common_prefix)
			{
				if (_prefix_word_length == 1)
				{
					return "";
				}
				else{
					return _res_str.substr(0, _prefix_word_length - 1);
				}
			}
		}
		return _limited_str;
	}


};


/*
编号：004_16
名字：_Map
描述：关联容器类
  *关于关联容器的用法，请自行参考STL中的map容器
*/
template<class _Type_1, class _Type_2> class _Map
{
public:
	_Type_1 _First_data;
	_Type_2 _Second_data;
	_Map* _Header_Pointer;
	_Map* _Tail_Pointer;
	_Map* _Next_Pointer;
	int _Element_size;
	struct _Type{ _Type_1 k; _Type_2 v; };
	_Map()
	{
		_Header_Pointer = NULL;
		_Tail_Pointer = NULL;
		_Element_size = 0;
	}
	//judge 
	bool _Empty()
	{
		return _Header_Pointer == NULL;
	}
	//the size
	int _size()
	{
		return _Element_size;
	}
	//according to the array you offer,create this map
	//return the  map created,if you can't understand,please don's use this function
	_Map _create_according_array(_Type* _element_array, int size)
	{
		_Map _res_map;
		_Map* _header_pointer = new _Map;
		_Map* _tail_pointer = new _Map;
		if (size == 0) return res_map;
		//first create the header pointer of this empty map
		_header_pointer->_First_data = _element_array[0]._key_;
		_header_pointer->_Second_data = _element_array[0]._key_value_;
		_header_pointer->_Next_Pointer = NULL;
		_tail_pointer = _header_pointer;
		_tail_pointer->_Next_Pointer = NULL;
		//the header pointer is exist ,append the nodes
		for (int idex = 1; idex < size; idex++)
		{
			_Map* _append_pointer = new _Map;
			_append_pointer->_First_data = _element_array[idex]._key_;
			_append_pointer->_Second_data = _element_array[idex]._key_value_;
			_tail_pointer->_Next_Pointer = _append_pointer;
			_tail_pointer = _append_pointer;
			_tail_pointer->_Next_Pointer = NULL;
		}
		_res_map._Header_Pointer = _header_pointer;
		_res_map._Tail_Pointer = _tail_pointer;
		_res_map._Element_size = size;
		return _res_map;
	}

	//the operator []
	//give me the idex ,I give you the value of the idex
	//so,we need to know that,the map's idex is increase 0...big 
	_Type_2 operator[](_Type_1 _key)
	{
		_Map* _Traversal_pointer = new _Map;
		_Traversal_pointer = _Header_Pointer;
		while (_Traversal_pointer != NULL)
		{
			if (_Traversal_pointer->_First_data == _key)
			{
				return _Traversal_pointer->_Second_data;
			}
			_Traversal_pointer = _Traversal_pointer->_Next_Pointer;
		}
		//return null
		return NULL;
	}

	//judge the idex=key exist
	//if return -1,means not exist,else return the idex of idex=key
	int idex(_Type_1 _key)
	{
		_Map* _Traversal_pointer = new _Map;
		_Traversal_pointer = _Header_Pointer;
		int idex= 0;
		while (_Traversal_pointer != NULL)
		{
			if (_Traversal_pointer->_First_data == _key)
			{
				return idex;
			}
			idex++;
			_Traversal_pointer = _Traversal_pointer->_Next_Pointer;
		}
		//not find
		return -1;
	}


	//append a node in the tail of this map
	//return the header pointer of this map
	_Map* _Push(_Type_1 _key, _Type_2 _key_value)
	{
		if (_Header_Pointer == NULL)
		{
			//this map is null 
			//so you need to create the header pointer for this new map
			_Header_Pointer = new _Map;
			_Tail_Pointer = new _Map;
			_Header_Pointer->_First_data = _key;
			_Header_Pointer->_Second_data = _key_value;
			_Header_Pointer->_Next_Pointer = NULL;
			_Tail_Pointer = _Header_Pointer;
			_Tail_Pointer->_Next_Pointer = NULL;
			_Element_size++;
			return _Header_Pointer;
		}
		//judge if the key is exist,if not ,create it,or replace it
		int _idex = idex(_key);
		if (_idex == -1)
		{
			//this key is first time,so create the idex=key
			_Map* _append_pointer = new _Map;
			_append_pointer->_First_data = _key;
			_append_pointer->_Second_data = _key_value;
			_append_pointer->_Next_Pointer = NULL;
			_Tail_Pointer->_Next_Pointer = _append_pointer;
			_Tail_Pointer = _append_pointer;
			_Tail_Pointer->_Next_Pointer = NULL;
			_Element_size++;
			return _Header_Pointer;
		}
		else{
			//this idex is exist ,then find the idex and replace it
			int counter = 0;
			_Map* _Traversal_pointer = new _Map;
			_Traversal_pointer = _Header_Pointer;
			//find the pointer
			while (counter != _idex)
			{
				counter++;
				_Traversal_pointer = _Traversal_pointer->_Next_Pointer;
			}
			//change the value 
			_Traversal_pointer->_Second_data = _key_value;
			return _Header_Pointer;
		}
		//......end.....
	}

	//get the value 
	_Type_2 _at(int idex)
	{
		if (idex < 0 || idex >= _Element_size)
		{
			return NULL;
		}
		_Map* _Traversal_pointer = new _Map;
		_Traversal_pointer = _Header_Pointer;
		int counter = 0;
		while (counter != idex)
		{
			counter++;
			_Traversal_pointer = _Traversal_pointer->_Next_Pointer;
		}
		return _Traversal_pointer->_Second_data;
	}

	//count
	int _count(_Type_2 _dest_data)
	{
		if (_Header_Pointer == NULL) return 0;
		int _res_num = 0;
		_Map* _Traversal_pointer = new _Map;
		_Traversal_pointer = _Header_Pointer;
		while (_Traversal_pointer != NULL)
		{
			if (_Traversal_pointer->_Second_data == _dest_data)
			{
				_res_num++;
			}
			_Traversal_pointer = _Traversal_pointer->_Next_Pointer;
		}
		return _res_num;
	}

	//return the max value
	_Type_2 _max_()
	{
		if (_Header_Pointer == NULL) return NULL;
		_Map* _Traversal_pointer = new _Map;
		_Traversal_pointer = _Header_Pointer;
		_Type_2 _max_value = NULL;
		while (_Traversal_pointer != NULL)
		{
			if (_Traversal_pointer->_Second_data > _max_value)
			{
				_max_value = _Traversal_pointer->_Second_data;
			}
			_Traversal_pointer = _Traversal_pointer->_Next_Pointer;
		}
		return _max_value;
	}

	//return the min value
	_Type_2 _min_()
	{
		if (_Header_Pointer == NULL) return NULL;
		_Map* _Traversal_pointer = new _Map;
		_Traversal_pointer = _Header_Pointer;
		_Type_2 _min_value = NULL;
		while (_Traversal_pointer != NULL)
		{
			if (_Traversal_pointer->_Second_data< _max_value)
			{
				_min_value = _Traversal_pointer->_Second_data;
			}
			_Traversal_pointer = _Traversal_pointer->_Next_Pointer;
		}
		return _min_value;
	}

	//insert a node in this map
	//return the header pointer of this map
	_Map* _Insert_(int _idex, _Type_1 _key, _Type_2 _key_value)
	{
		if (_idex<0 || _idex>_Element_size) return _Header_Pointer;
		if (_idex == 0)
		{
			//you want to rebuild the header pointer of this map
			_Map* _append_pointer = new _Map;
			_append_pointer->_First_data = _key;
			_append_pointer->_Second_data = _key_value;
			_append_pointer->_Next_Pointer = _Header_Pointer;
			_Header_Pointer = _append_pointer;
			_Element_size++;
			return _Header_Pointer;
		}
		if (_idex == _Element_size)
		{
			//you want to insert a node in the tail of this map
			_Map* _append_pointer = new _Map;
			_append_pointer->_First_data = _key;
			_append_pointer->_Second_data = _key_value;
			_append_pointer->_Next_Pointer = NULL;
			_Tail_Pointer->_Next_Pointer = _append_pointer;
			_Tail_Pointer = _append_pointer;
			_Tail_Pointer->_Next_Pointer = NULL;
			_Element_size++;
			return _Header_Pointer;
		}
		else{
			//you want to inset a node in it
			_Map* _append_pointer = new _Map;
			_append_pointer->_First_data = _key;
			_append_pointer->_Second_data = _key_value;
			_append_pointer->_Next_Pointer = NULL;
			//now you need to find position
			_Map* _Traversal_pointer = new _Map;
			_Traversal_pointer = _Header_Pointer;
			int counter = 0;
			while (counter != _idex)
			{
				counter++;
				_Traversal_pointer = _Traversal_pointer->_Next_Pointer;
			}
			//insert node
			_append_pointer->_Next_Pointer = _Traversal_pointer->_Next_Pointer;
			_Traversal_pointer->_Next_Pointer = _append_pointer;
			_Element_size++;
			return _Header_Pointer;
		}
	}


	//delete a node 
	//accord your idex
	//return the header pointer of this map
	_Map* _delete_idex(int _idex_)
	{
		if (_idex_ < 0 || _idex_ >= _Element_size) return _Header_Pointer;
		if (_idex_ == 0)
		{
			//you want to delete the header pointer
			//so please rebuild the header pointer
			_Header_Pointer = _Header_Pointer->_Next_Pointer;
			_Element_size--;
			return _Header_Pointer;
		}
		_Map* _Traversal_pointer = new _Map;
		_Map* _Pre_Traversal_pointer = new _Map;
		_Pre_Traversal_pointer = NULL;
		_Traversal_pointer = _Header_Pointer;
		int counter = 0;
		while (counter != _idex_)
		{
			counter++;
			_Pre_Traversal_pointer = _Traversal_pointer;
			_Traversal_pointer = _Traversal_pointer->_Next_Pointer;
		}
		//delete the node
		_Pre_Traversal_pointer->_Next_Pointer = _Traversal_pointer->_Next_Pointer;
		delete _Traversal_pointer;
		_Element_size--;
		return _Header_Pointer;
	}


	//delete a node from this map
	//return the header pointer of this map
	//according to the value you offer
	_Map* _Delete_If_Equal(_Type_2 _dest_data)
	{
		if (_Header_Pointer == NULL) return NULL;
		_Map* _Traversal_pointer = new _Map;
		_Map* _Pre_Traversal_pointer = new _Map;
		_Pre_Traversal_pointer = NULL;
		_Traversal_pointer = _Header_Pointer;
		int _idex_delete_ = 0;
		while (_Traversal_pointer != NULL)
		{
			if (_Traversal_pointer->_Second_data == _dest_data)
			{
				//if the idex we want to delete is the header pointer
				if (_idex_delete_ == 0)
				{
					//you need to rebuild the header pointer
					_Header_Pointer = _Header_Pointer->_Next_Pointer;
				} 
				else{
					//just delete
					_Pre_Traversal_pointer->_Next_Pointer = _Traversal_pointer->_Next_Pointer;
				}
				_Element_size--;
			}
			_idex_delete_++;
			_Pre_Traversal_pointer = _Traversal_pointer;
			_Traversal_pointer = _Traversal_pointer->_Next_Pointer;
		}
		//.......end............
		return _Header_Pointer;
	}

	//emplace
	//you need offer an idex and a value
	//the function will chnage the idex's value as the value you offer
	//the function will return the header pointer of this map
	_Map* _Emplace_If(int _idex_, _Type_2 _dest_data)
	{
		if (_idex_ < 0 || _idex_ >= _Element_size) return _Header_Pointer;
		_Map* _Traversal_pointer = new _Map;
		_Traversal_pointer = _Header_Pointer;
		int counter = 0;
		while (counter != _idex_)
		{
			counter++;
			_Traversal_pointer = _Traversal_pointer->_Next_Pointer;
		}
		//change the value
		_Traversal_pointer->_Second_data = _dest_data;
		return _Header_Pointer;
	}

	//emplace two value
	//you need to offer two idexs 
	//this function will return the hedaer pointer of this map
	_Map* _Emplace_(int idex_1, int idex_2)
	{
		if (idex_1 < 0 || idex_1 >= _Element_size || idex_2 < 0 || idex_2 >= _Element_size) return _Header_Pointer;
		_Map* _Traversal_pointer_1 = new _Map;
		_Map* _Traversal_pointer_2 = new _Map;
		_Traversal_pointer_1 = _Header_Pointer;
		_Traversal_pointer_2 = _Header_Pointer;
		int counter_1 = 0;
		int counter_2 = 0;
		while (counter_1 != idex_1)
		{
			counter_1++;
			_Traversal_pointer_1 = _Traversal_pointer_1->_Next_Pointer;
		}
		while (counter_2 != idex_2)
		{
			counter_2++;
			_Traversal_pointer_2 = _Traversal_pointer_2->_Next_Pointer;
		}
		_Type_2 _Temp_ = _Traversal_pointer_1->_Second_data;
		_Traversal_pointer_1->_Second_data = _Traversal_pointer_2->_Second_data;
		_Traversal_pointer_2->_Second_data = _Temp_;
		return _Header_Pointer;
	}

	//clear this map
	//return the header pointer of this map(null)
	_Map* _clear()
	{
		_Element_size = 0;
		_Header_Pointer = NULL;
		_Tail_Pointer = NULL;
		return _Header_Pointer;
	}

	//traversal this map
	void _Traverasal_map()
	{
		_Map* _Traversal_pointer = new _Map;
		_Traversal_pointer = _Header_Pointer;
		while (_Traversal_pointer != NULL)
		{
			cout <<"["<< _Traversal_pointer->_First_data << "," << _Traversal_pointer->_Second_data<<"] ";
			_Traversal_pointer = _Traversal_pointer->_Next_Pointer;
		}
		cout << endl;
	}

};


/*
编号：004_17
名字：_Binary_Balance_Tree(AVL)
描述：AVL树的初步研究
*/
template<class _Type> class _Binary_Balance_Tree
{
public:
	/*   AVL树的定义：
	     一棵树为AVL树，要么是一棵空的二叉树，要么每个节点左右子树
		 都是一棵AVL树。用hl和hr表示一个节点左右子树的高度，bf=hl-hr
		 如果bf的绝对值大于2的话就不符合AVL树的规定了，也就是说对于
		 AVL树来说，每个节点的左右子树的高度差的绝对值不会超高1，如
		 果超过了就要进行旋转来达到新的平衡。
	*/

	_Type _Element_Data;
	_Binary_Balance_Tree* _Root_Pointer;
	_Binary_Balance_Tree* _Left_child_Pointer;
	_Binary_Balance_Tree* _Right_child_Pointer;
	int _AVL_Tree_Height;

	_Binary_Balance_Tree()
	{
		_Root_Pointer = NULL;
		_Left_child_Pointer = NULL;
		_Right_child_Pointer = NULL;
		_AVL_Tree_Height = 0;
	}

	//return the height of one's node
	//you should offer a pointer
	int _Height(_Binary_Balance_Tree* _root_pointer)
	{
		if (_root_pointer == NULL) return -1;
		return _root_pointer->_AVL_Tree_Height;
	}

	//return the size
	int _size()
	{
		int counter = 0;
		if (_Root_Pointer == NULL) return 0;
		deque<_Binary_Balance_Tree*> _Node_Elements;
		_Node_Elements.push_front(_Root_Pointer);
		while (!_Node_Elements.empty())
		{
			_Binary_Balance_Tree* _Temp_pointer = _Node_Elements.front();
			_Node_Elements.pop_front();
			if (_Temp_pointer->_Element_Data != NULL)
			{
				counter++;
			}
			if (_Temp_pointer->_Left_child_Pointer!= NULL)
				_Node_Elements.push_back(_Temp_pointer->_Left_child_Pointer);
			if (_Temp_pointer->_Right_child_Pointer!= NULL)
				_Node_Elements.push_back(_Temp_pointer->_Right_child_Pointer);
		}
		return counter;
	}

	//get all allelements of this avl tree
	//return an array 
	_Type* _Get_Elements_()
	{
		_Type* _Element_Array;
		_Element_Array = new _Type[_size()];
		if (_Root_Pointer == NULL) return _Element_Array;
		int counter = 0;
		deque<_Binary_Balance_Tree*> _Node_Elements;
		_Node_Elements.push_front(_Root_Pointer);
		while (!_Node_Elements.empty())
		{
			_Binary_Balance_Tree* _Temp_pointer = _Node_Elements.front();
			_Node_Elements.pop_front();
			if (_Temp_pointer->_Element_Data != NULL)
			{
				_Element_Array[counter++] = _Temp_pointer->_Element_Data;
			}
			if (_Temp_pointer->_Left_child_Pointer != NULL)
				_Node_Elements.push_back(_Temp_pointer->_Left_child_Pointer);
			if (_Temp_pointer->_Right_child_Pointer != NULL)
				_Node_Elemen
		}
		return _Element_Array;
	}

	//judge is this avl tree is empty
	bool _empty()
	{
		return _Root_Pointer == NULL;
	}

	//rotate
	//left-left
	//return the root pointer of this avl tree
	_Binary_Balance_Tree* _Left_Rotate(_Binary_Balance_Tree* _root_pointer)
	{
		//start to rotate
		_Binary_Balance_Tree* _rotate_pointer = new _Binary_Balance_Tree;
		_rotate_pointer = _root_pointer->_Left_child_Pointer;
		_root_pointer->_Left_child_Pointer = _rotate_pointer->_Right_child_Pointer;
		_rotate_pointer->_Right_child_Pointer = _root_pointer;
		//update the height
		_root_pointer->_AVL_Tree_Height = max(_Height(_root_pointer->_Left_child_Pointer),
			_Height(_root_pointer->_Right_child_Pointer)) + 1;
		_rotate_pointer->_AVL_Tree_Height = max(_Height(_rotate_pointer->_Left_child_Pointer),
			_Height(_rotate_pointer->_Right_child_Pointer)) + 1;
		return _rotate_pointer;
		//.........end..........
	}

	//rotate
	//right-right
	//return the root of this avl tree
	_Binary_Balance_Tree* _Right_Rotate(_Binary_Balance_Tree* _root_pointer)
	{
		//start to rotate
		_Binary_Balance_Tree* _rotate_pointer = new _Binary_Balance_Tree;
		_rotate_pointer = _root_pointer->_Right_child_Pointer;
		_root_pointer->_Right_child_Pointer = _rotate_pointer->_Left_child_Pointer;
		_rotate_pointer->_Left_child_Pointer = _root_pointer;
		//update the tree's height
		_root_pointer->_AVL_Tree_Height = max(_Height(_root_pointer->_Left_child_Pointer),
			_Height(_root_pointer->_Right_child_Pointer)) + 1;
		_rotate_pointer->_AVL_Tree_Height = max(_Height(_rotate_pointer->_Left_child_Pointer),
			_Height(_rotate_pointer->_Right_child_Pointer)) + 1;
		return _rotate_pointer;
		//.......end........
	}

	//rotate
	//right-left
	//return the root pointer of this tree
	_Binary_Balance_Tree* _Right_Left_Rotate(_Binary_Balance_Tree* _root_pointer)
	{
		//start to rotate
		_root_pointer->_Right_child_Pointer = _Left_Rotate(_root_pointer->_Right_child_Pointer);
		 return _Right_Rotate(_root_pointer);
		//........end.......
	}

	//rotate
	//left-right
	//return the root pointer of this tree
	_Binary_Balance_Tree* _Left_Right_Rotate(_Binary_Balance_Tree* _root_pointer)
	{
		//start to rotate
		_root_pointer->_Left_child_Pointer = _Right_Rotate(_root_pointer->_Left_child_Pointer);
		return _Left_Rotate(_root_pointer);
		//.........end.......
	}

	//find a node in this avl tree
	//return the node pointer
	_Binary_Balance_Tree* _Find_(_Type _dest_data, _Binary_Balance_Tree* _root_pointer)
	{
		//just like the binarytree sort tree's find a node
		if (_root_pointer->_Element_Data == _dest_data)
		{
			//find it 
			return _root_pointer;
		}
		else if (_root_pointer == NULL)
		{
			//find error or fail
			return NULL;
		}
		else
		{
			//in the left tree
			if (_dest_data < _root_pointer->_Element_Data)
			{
				return _Find_(_dest_data, _root_pointer->_Left_child_Pointer);
			}
			//in the right tree
			else{
				return _Find_(_dest_data, _root_pointer->_Right_child_Pointer);
			}
		}
	}


	/*
	   * Insert a node in this AVL tree*
	   * 1.find the position 
	   * 2.insert the node
	   * 3.judge the AVL tree 
	   * 4.if need to rotate to keep balance,then rotate
	*/
	
	//insert a node in this avl tree
	//if this function don't work,move this function out of class
	//set a function alone and retry
	//return the root pointer of this avl tree
	_Binary_Balance_Tree* _Insert_(_Binary_Balance_Tree* _root_pointer, _Type _dest_data)
	{
		//if this avl tree is null,then create the root pointer
		if (_root_pointer == NULL)
		{
			_root_pointer = new _Binary_Balance_Tree;
			_root_pointer->_Left_child_Pointer = NULL;
			_root_pointer->_Right_child_Pointer = NULL;
			_root_pointer->_Element_Data = _dest_data;
			_root_pointer->_AVL_Tree_Height = 0;
		}
		else{
			//just insert
			if (_dest_data < _root_pointer->_Element_Data)
			{
				//insert the left tree
				_root_pointer->_Left_child_Pointer = _Insert_(_root_pointer->_Left_child_Pointer,
					_dest_data);
				//judge avl tree
				int _balance_factor;
				_balance_factor = _Height(_root_pointer->_Left_child_Pointer) -
					_Height(_root_pointer->_Right_child_Pointer);
				//the _balance_faltor must positive
				//because we insert the node in the left tree
				if (_balance_factor == 2)
				{
					if (_dest_data< _root_pointer->_Left_child_Pointer->_Element_Data)
					{
						_root_pointer = _Left_Rotate(_root_pointer);
					}
					else{
						_root_pointer = _Left_Right_Rotate(_root_pointer);
					}
				}
			}//if end
				else if (_dest_data>_root_pointer->_Element_Data)
				{
					//insert the node in the right tree
					_root_pointer->_Right_child_Pointer = _Insert_(_root_pointer->_Right_child_Pointer,
						_dest_data);
					int _balance_factor = _Height(_root_pointer->_Left_child_Pointer) -
						_Height(_root_pointer->_Right_child_Pointer);
					if (_balance_factor == -2)
					{
						//need to ratate
						if (_dest_data > _root_pointer->_Right_child_Pointer->_Element_Data)
						{
							_root_pointer = _Right_Rotate(_root_pointer);
						}
						else{
							_root_pointer = _Right_Left_Rotate(_root_pointer);
						}
					}
				}//else if end
		}//else end
		//update the height of this tree
		_root_pointer->_AVL_Tree_Height = max(_Height(_root_pointer->_Left_child_Pointer),
			_Height(_root_pointer->_Right_child_Pointer)) + 1;
		return _root_pointer;
	}//end function

	/*
	  rotate the tree to an avl tree
	*/
	//this function will return the root pointer of this avl tree
	//rotate a node of this avl tree,let the node's tree to be avl tree
	_Binary_Balance_Tree* _Rotate_Node_To_Be_AVL(_Binary_Balance_Tree* _This_node_pointer)
	{
		int _balance_factor;
		_balance_factor = _Height(_This_node_pointer->_Left_child_Pointer) -
			_Height(_This_node_pointer->_Right_child_Pointer);
		//the left tree need to adjust
		if (_balance_factor ==2)
		{
			//judge the case and rotate
			if (_Height(_This_node_pointer->_Left_child_Pointer->_Left_child_Pointer) >=
				_Height(_This_node_pointer->_Left_child_Pointer->_Right_child_Pointer))
			{
				_This_node_pointer = _Left_Rotate(_This_node_pointer);
			}
			else{
				_This_node_pointer = _Left_Right_Rotate(_This_node_pointer);
			}
		}
		//the right tree need to adjust
		if (_balance_factor == -2)
		{
			if (_Height(_This_node_pointer->_Right_child_Pointer->_Right_child_Pointer) >=
				_Height(_This_node_pointer->_Right_child_Pointer->_Left_child_Pointer))
			{
				_This_node_pointer = _Right_Rotate(_This_node_pointer);
			}
			else{
				_This_node_pointer = _Right_Left_Rotate(_This_node_pointer);
			}
		}
		//...end...
		return _This_node_pointer;
	}

	/*
	   ********************no.1***************************
	   * Delete a node in this avl tree*
	   *  _delete_pointer is the node we want to delete
	   *  _Parent_pointer_delete is the parent pointer of the node we want to delete
	   *  1. if _delete_pointer is the leaf node,delete and adjust
	   *  2. if the delete_pointer only has the right-tree not left-tree,then
	   *   _Parent_pointer_delete->rightchild=delete_pointer->right_pointer
	   *  3. if the delete_pointer only has the left-tree not right-tree,then 
	   *   _Parent_pointer->leftchild=delete_pointer->left_pointer
	   *  4. else,find the biggest node in the left-tree,then let the node emplace delete_pointer
	   ********************no.2*****************************
	   * The Algorithm of deleting an node in an avl tree*
	   *1.the node we want to delete's left child is null,then just let the right node replace the node we delete
	   *2.the node we want to delete's left 's right node is null,then just let the left node replace the node we delete
	   *3.if not case 1 or case 2,then just find the most biggest node in the tree that we want to delete's left child tree
	   *  then let the node replac the node we want to delete
    */

	//delete a node from this avl tree
	//the algorithm delete a node just like bst's delete a node from a bst tree
	//this function will return root of the avl tree
	_Binary_Balance_Tree* _delete_(_Binary_Balance_Tree* _root_pointer, _Type _dest_data)
	{
		if (_root_pointer == NULL) return NULL;
		else if (_dest_data < _root_pointer->_Element_Data){
			_root_pointer->_Left_child_Pointer = _delete_(_root_pointer->_Left_child_Pointer, _dest_data);
		}
		else if(_dest_data>_root_pointer->_Element_Data){
			_root_pointer->_Right_child_Pointer = _delete_(_root_pointer->_Right_child_Pointer, _dest_data);
		}
		//if the delete's left node is null
		else if (_root_pointer->_Left_child_Pointer == NULL)
		{
			_Binary_Balance_Tree* _append_pointer = new _Binary_Balance_Tree;
			_append_pointer = _root_pointer->_Right_child_Pointer;
			delete _root_pointer;
			return _append_pointer;
		}
		//the delete's leftchild's rightchild is null
		else if (_root_pointer->_Left_child_Pointer->_Right_child_Pointer == NULL)
		{
			_Binary_Balance_Tree* _append_pointer = new _Binary_Balance_Tree;
			_append_pointer = _root_pointer->_Left_child_Pointer;
			_append_pointer->_Right_child_Pointer = _root_pointer->_Right_child_Pointer;
			delete _root_pointer;
			return _append_pointer;
		}
		//find the biggest node in the left tree
		else{
			_Binary_Balance_Tree* _Traversal_pointer = new _Binary_Balance_Tree;
			_Traversal_pointer = _root_pointer->_Left_child_Pointer;
			while (_Traversal_pointer->_Right_child_Pointer->_Right_child_Pointer != NULL)
			{
				_Traversal_pointer = _Traversal_pointer->_Right_child_Pointer;
			}
			_Binary_Balance_Tree* _append_pointer = new _Binary_Balance_Tree;
			_append_pointer = _Traversal_pointer->_Right_child_Pointer;
			_Traversal_pointer->_Right_child_Pointer = _append_pointer->_Left_child_Pointer;
			_append_pointer->_Left_child_Pointer = _root_pointer->_Left_child_Pointer;
			_append_pointer->_Right_child_Pointer = _root_pointer->_Right_child_Pointer;
			delete _root_pointer;
			return _append_pointer;
		}
		//adjust the new tree to avl tree
		if (_root_pointer->_Left_child_Pointer != NULL)
		{
			_root_pointer->_Left_child_Pointer = _Rotate_Node_To_Be_AVL(_root_pointer->_Left_child_Pointer);
		}
		if (_root_pointer->_Right_child_Pointer != NULL)
		{
			_root_pointer->_Right_child_Pointer = _Rotate_Node_To_Be_AVL(_root_pointer->_Right_child_Pointer);
		}
		if (_root_pointer != NULL)
		{
			_root_pointer = _Rotate_Node_To_Be_AVL(_root_pointer);
		}
		_root_pointer->_AVL_Tree_Height = max(_Height(_root_pointer->_Left_child_Pointer),
			_Height(_root_pointer->_Right_child_Pointer)) + 1;
		return _root_pointer;
	}

	//traveral this avl tree by squence
	void _Traversal_Avl_Tree(_Binary_Balance_Tree* _root_pointer)
	{
		if (_root_pointer == NULL) return;
		Dequeue<_Binary_Balance_Tree*> _Avl_node_deque;
		_Avl_node_deque._Push_front(_root_pointer);
		while (!_Avl_node_deque._Empty())
		{
			_Binary_Balance_Tree* _Traversal_pointer = new _Binary_Balance_Tree;
			_Traversal_pointer = _Avl_node_deque._Front();
			_Avl_node_deque._Pop_front();
			if (_Traversal_pointer->_Element_Data!=NULL)
			      cout << _Traversal_pointer->_Element_Data << " ";
			if (_Traversal_pointer->_Left_child_Pointer != NULL)
			{
				_Avl_node_deque._Push_back(_Traversal_pointer->_Left_child_Pointer);
			}
			if (_Traversal_pointer->_Right_child_Pointer != NULL)
			{
				_Avl_node_deque._Push_back(_Traversal_pointer->_Right_child_Pointer);
			}
		}
		cout << endl;
	}
	//preorder traversal
	void _Inorder_Traversal(_Binary_Balance_Tree* _root_pointer)
	{
		if (_root_pointer != NULL)
		{
			_Inorder_Traversal(_root_pointer->_Left_child_Pointer);
			if (_root_pointer->_Element_Data!= NULL)
			{
				cout << _root_pointer->_Element_Data<< " ";
			}
			_Inorder_Traversal(_root_pointer->_Right_child_Pointer);
		}
	}
};


/*
* 编号：004_18
* 名字：Mystring
* 描述：一个简单的字符串类
*/
class Mystring
{
public:

	Mystring *Header_Pointer;
	Mystring *Tail_Pointer;
	Mystring *Next_Pointer;
	char _Tag_Value;
	int _String_length;
	Mystring()
	{
		Header_Pointer = NULL;
		Tail_Pointer = NULL;
		Next_Pointer = NULL;
		_Tag_Value = '\0';
		_String_length = 0;
	}

	//get the length of this string object
	int length()
	{
		return _String_length;
	}

	//judge if this string object if empty
	bool empty()
	{
		return Header_Pointer == NULL;
	}

	//operator '+'
	//+char
	//return the string object's header pointer
	Mystring* operator +(char _append_character)
	{
		//judge if the obj is null
		if (Header_Pointer == NULL)
		{
			//this obj is null,you need to create the header pointer
			Header_Pointer = new Mystring;
			Header_Pointer->_Tag_Value = _append_character;
			Header_Pointer->Next_Pointer = NULL;
			Tail_Pointer = Header_Pointer;
			_String_length++;
			return Header_Pointer;
		}
		else{
			//this obj is not null,append this char to the tail 
			Mystring* _append_pointer = new Mystring;
			_append_pointer->_Tag_Value = _append_character;
			_append_pointer->Next_Pointer = NULL;
			Tail_Pointer->Next_Pointer = _append_pointer;
			Tail_Pointer = _append_pointer;
			_String_length++;
			return Header_Pointer;
		}
	}


	//insert a char var in the front of the obj
	//return the header pointer
	Mystring* _Append_Front(char _append_character)
	{
		//if the header pointer is null,create the header pointer
		if (Header_Pointer ==NULL)
		{
			Header_Pointer = new Mystring;
			Header_Pointer->_Tag_Value = _append_character;
			Header_Pointer->Next_Pointer = NULL;
			Tail_Pointer = Header_Pointer;
			_String_length++;
			return Header_Pointer;
		}
		else{
			//create the new header pointer
			Mystring* _new_header_pointer = new Mystring;
			_new_header_pointer->_Tag_Value = _append_character;
			_new_header_pointer->Next_Pointer =Header_Pointer;
			Header_Pointer = _new_header_pointer;
			_String_length++;
			return Header_Pointer;
		}
	}

	//insert a char var into the tail of this string object
	//return the header pointer of this objict
	Mystring* _Append_Tail(char _append_character)
	{
		//if this object is null,you need to create the pointer 
		if (Header_Pointer == NULL)
		{
			Header_Pointer = new Mystring;
			Header_Pointer->_Tag_Value = _append_character;
			Header_Pointer->Next_Pointer = NULL;
			Tail_Pointer = Header_Pointer;
			_String_length++;
			return Header_Pointer;
		}
		else{
			//this string object is exist,you just need to append this char var to the 
			//tail of the tail pointer,and let the new append pointer as the tail pointer
			Mystring *_new_tail_pointer = new Mystring;
			_new_tail_pointer->_Tag_Value = _append_character;
			_new_tail_pointer->Next_Pointer = NULL;
			Tail_Pointer->Next_Pointer = _new_tail_pointer;
			Tail_Pointer = _new_tail_pointer;
			Tail_Pointer->Next_Pointer = NULL;
			_String_length++;
			return Header_Pointer;
		}
	}

	//operator '[]'
	char operator[](int _idex_)
	{
		if (_idex_<0 ||_idex_>_String_length){
			//fuck you.
			return NULL;
		}
		int counter = 0;
		Mystring* _Traversal_pointer = new Mystring;
		_Traversal_pointer = Header_Pointer;
		while (counter != _idex_)
		{
			counter++;
			_Traversal_pointer = _Traversal_pointer->Next_Pointer;
		}
		return _Traversal_pointer->_Tag_Value;
	}

	//get the header val
	char front()
	{
		if (Header_Pointer == NULL) return NULL;
		return Header_Pointer->_Tag_Value;
	}

	//get the tail val
	char back()
	{
		if (Tail_Pointer == NULL) return NULL;
		return Tail_Pointer->_Tag_Value;
	}

	//operator ==
	bool operator==(Mystring object_str)
	{
		Mystring* _traversal_this_pointer = new Mystring;
		Mystring* _traversal_obj_pointer = new Mystring;
		_traversal_this_pointer = Header_Pointer;
		_traversal_obj_pointer = object_str.Header_Pointer;
		if (_String_length != object_str.length()) return false;
		while (_traversal_obj_pointer != NULL)
		{
			if (_traversal_obj_pointer->_Tag_Value !=
				_traversal_this_pointer->_Tag_Value){
				return false;
			}
			_traversal_obj_pointer = _traversal_obj_pointer->Next_Pointer;
			_traversal_this_pointer = _traversal_this_pointer->Next_Pointer;
		}
		return true;
	}

	//create the mystring according to your input
	//return the header pointer of this object 
	Mystring* _Init_Mytring(char* _char_array, int length)
	{
		if (length == 0) return NULL;
		//example:  str="hujian"
		Header_Pointer = new Mystring;
		//create the header pointer
		Header_Pointer->_Tag_Value = _char_array[0];
		Header_Pointer->Next_Pointer = NULL;
		Tail_Pointer = Header_Pointer;
		int counter = 1;
		while (counter != length)
		{
			Mystring* _append_pointer = new Mystring;
			_append_pointer->_Tag_Value = _char_array[counter++];
			_append_pointer->Next_Pointer = NULL;
			Tail_Pointer->Next_Pointer = _append_pointer;
			Tail_Pointer = _append_pointer;
			Tail_Pointer->Next_Pointer = NULL;
		}
		_String_length = length;
		return Header_Pointer;
	}

	//operator = 
	//example str="hujian is a hujian"=> str="hujian"!!!!
	//return header pointer of this object
	Mystring* operator=(char* Your_str)
	{
		int length = 0;
		for (; Your_str[length] != ' '; length++);
		if (length == 0) return NULL;
		Header_Pointer = _Init_Mytring(Your_str, length);
		return Header_Pointer;
	}

	//delete a char in the front of this obj
	//return the header pointer 
	Mystring* _delete_front()
	{
		if (Header_Pointer == NULL)
		{
			//this is an empty object
			return NULL;
		}
		Header_Pointer = Header_Pointer->Next_Pointer;
		_String_length--;
		return Header_Pointer;
	}

	//delete a char var in the tail of this obj
	//return the header pointer
	Mystring* _delete_tail()
	{
		if (Header_Pointer == NULL)
		{
			return NULL;
		}
		//find the pointer 
		Mystring* _delete_pointer = new Mystring;
		_delete_pointer = Header_Pointer;
		while (_delete_pointer->Next_Pointer->Next_Pointer!= NULL)
			_delete_pointer = _delete_pointer->Next_Pointer;

		Tail_Pointer = _delete_pointer;
		Tail_Pointer->Next_Pointer = NULL;
		_String_length--;
		return Header_Pointer;
	}

	//change the object to c style
	//return the char* style var
	char* _c_style_str()
	{
		//just this object will work..
		char* _c_str;
		int idex = 0;
		Mystring* _traversal_pointer = new Mystring;
		_traversal_pointer = Header_Pointer;
		while (_traversal_pointer != NULL)
		{
			_c_str[idex++]= _traversal_pointer->_Tag_Value;
			_traversal_pointer = _traversal_pointer->Next_Pointer;
		}
		//the end
		return _c_str;
	}

	//operztor +=
	//+char
	//return the header pointer of this object
	Mystring* operator+=(char append_ch)
	{
		//append a char var in the end of this string
		Header_Pointer = _Append_Tail(append_ch);
		return Header_Pointer;
	}

	//operator +=
	//+string
	//return the header pointer of this object
	Mystring* operator+=(Mystring _object_str)
	{
		Tail_Pointer->Next_Pointer = _object_str.Header_Pointer;
		_String_length += _object_str.length();
		return Header_Pointer;
	}

	//operator +
	//+string
	//return the header pointer
	Mystring* operator+(Mystring _object_str)
	{
		Tail_Pointer->Next_Pointer = _object_str.Header_Pointer;
		_String_length += _object_str.length();
		return Header_Pointer;
	}


	//function at()
	//get the idex's value
	//rturn char type
	char at(int idex)
	{
		if (idex<0 || idex>_String_length) return NULL;
		Mystring* _traversal_pointer = new Mystring;
		_traversal_pointer = Header_Pointer;
		int counter = 0;
		while (counter != idex)
		{
			counter++;
			_traversal_pointer = _traversal_pointer->Next_Pointer;
		}
		//the ned
		return _traversal_pointer->_Tag_Value;
	}


	//substr
	//return the header pointer of the ans object
	Mystring* substr(int start_idex, int length)
	{
		if (start_idex<0 || start_idex>_String_length)
		{
			//fuck you,error
			return Header_Pointer;
		}
		//find the start pointer
		Mystring* _start_pointer = new Mystring;
		_start_pointer = Header_Pointer;
		int counter_start = 0;
		while (counter_start != start_idex)
		{
			counter_start++;
			_start_pointer = _start_pointer->Next_Pointer;
		}
		//now get the start pointer
		Header_Pointer = _start_pointer;
		if (length >=(_String_length - start_idex)) return Header_Pointer;
		int counter_sub = 0;
		//get the tail 
		Mystring* _tail_pointer = new Mystring;
		_tail_pointer = Header_Pointer;
		while (counter_sub != length)
		{
			counter_sub++;
			_tail_pointer = _tail_pointer->Next_Pointer;
		}
		Tail_Pointer = _tail_pointer;
		Tail_Pointer->Next_Pointer = NULL;
		//get the length of this object
		_String_length = length+1;
		return Header_Pointer;
	}

	//explode this string object
	//return an array
	//please use the operator * to print the ans array
	//do not use the function print to output.
	vector<Mystring> explode(char _explode_char)
	{
		vector<Mystring> ans_array;
		ans_array.clear();
		if (Header_Pointer == NULL) return ans_array;
		Mystring* _traversal_pointer = new Mystring;
		_traversal_pointer = Header_Pointer;
		Mystring _explode_str;
		while (_traversal_pointer != NULL)
		{
			_explode_str.Header_Pointer = _traversal_pointer;
			int length = 0;
			while (_traversal_pointer != NULL)
			{
				if (_traversal_pointer->_Tag_Value ==_explode_char)
				{
					_explode_str._String_length = length;
					_explode_str.Next_Pointer = NULL;
					ans_array.push_back(_explode_str);
					break;
				} 
				if (_traversal_pointer->Next_Pointer == NULL)
				{
					_explode_str._String_length = length+1;
					ans_array.push_back(_explode_str);
					return ans_array;
				}
				_explode_str.Next_Pointer = _traversal_pointer->Next_Pointer;
				_traversal_pointer = _traversal_pointer->Next_Pointer;
				length++;
			}
			if (_traversal_pointer == NULL) return ans_array;
			_traversal_pointer = _traversal_pointer->Next_Pointer;
		}
		return ans_array;
	}
	
	//operator *
	//print the explode words
	void operator*(Mystring iter)
	{
		Mystring* _traversal_pointer = new Mystring;
		_traversal_pointer = iter.Header_Pointer;
		int counter = 0;
		while (counter != iter.length())
		{
			cout << _traversal_pointer->_Tag_Value;
			_traversal_pointer = _traversal_pointer->Next_Pointer;
			counter++;
		}
		cout << endl;
	}

	//output this string
	void print()
	{
		Mystring* Traveral_pointer = new Mystring;
		Traveral_pointer = Header_Pointer;
		while (Traveral_pointer != NULL)
		{
			cout << Traveral_pointer->_Tag_Value;
			Traveral_pointer = Traveral_pointer->Next_Pointer;
		}
		cout << endl;
	}

};


/*
 * 编号：004_19
 * 名字：MyDocumentObjectModel
 * 描述：简单xml文件的操作
*/
class MyDocumentObjectModel
{
public:
	//the number of the item
	int _Num_Of_Item;
	//this xml file' name
	string xml_file_name;
	//the item's node
	vector<string> item;
	MyDocumentObjectModel()
	{
		//read the numfile,get the num of the item
		ifstream iread;
		iread.open("config.ini");
		iread >> _Num_Of_Item;
		iread.close();
		xml_file_name = "";
		item.clear();
	}


	//return the size of this xml file's item's number
	int size()
	{
		return _Num_Of_Item;
	}

	//judge if this xml file is empty
	bool empty()
	{
		return _Num_Of_Item == 0;
	}

	//init,start to open the xml file and create the 
	//header ,then you can edit this xml file
	//this function need you offer the xml file 
	//you want to create 's name
	//and this function will return true or false
	//this function just create the xml file...
	bool _start_dom(string xml_file_name)
	{
		//create the the file
		ifstream iread;
		ofstream iwrite;
		//so,please colplete your input parm(filename)
		iread.open(xml_file_name);
		if (iread){
			//this file is exist
			//so,just return true
			//close the xml file
			iread.close();
			return true;
		}
		iread.close();
		//else,this xml file is not exist
		//then create this xml file
		string _header_str = "<?xml version='1.0' encoding='utf-8'?>";
		//create this xml file
		iwrite.open(xml_file_name);
		if (!iwrite)
		{
			//create this xml file error
			return false;
		}
		iwrite << _header_str << endl;
		iwrite << "<rss version='2.0'>" << endl;
		iwrite << "<channel>" << endl;
		//iwrite << "<item>"<< "</item>" << endl;
		iwrite << "</channel>" << endl;
		//ok,close this xml file
		iwrite.close();
		return true;
	}

	//init this the xml file
	//and insert at least one node to this file
	//this function will return true or false
	bool _create_one_item(vector<string> item_name, vector<string> item_value)
	{
		//if the file is not exist
		//just return false
		ifstream iread;
		ofstream iwrite;
		iread.open(xml_file_name);
		if (!iread)
		{
			//this file is not exist
			//return false
			//close this xml file stream
			iread.close();
			return false;
		}

		//iread.close();
		//else ,this xml file is exist
		//so you can insert the item's node to this xml file
		//find the <channel>..idex..</channel>
		iwrite.open("Res"+xml_file_name);
		string line_str;
		while (getline(iread, line_str))
		{
			iwrite << line_str << endl;
			if (line_str == "<channel>")
			{
				//you can insert node here
				//so ,start to insert the node
				vector<string>::iterator name_vit, value_vit;
				name_vit = item_name.begin();
				value_vit = item_value.begin();
				//string _item_node = "<item>";
				iwrite << "<item>";
				for (; name_vit != item_name.end(); name_vit++, value_vit++)
				{
					//ok,start to append the value to the node
					/*_item_node += "<" + *name_vit + ">" + *value_vit + "</" +
						*name_vit + ">";*/
					iwrite << "<" << *name_vit << ">" << *value_vit << "</" <<
						*name_vit << ">";
				}
				iwrite << "</item>" << endl;
				//_item_node += "</item>";
				//ok,done
				/*iwrite << _item_node << endl;	*/
				_Num_Of_Item++;
			}
		}
		//ok,done
		//close this xml file
		iread.close();
		iwrite.close();
		//you need copy the resxmlfile to xmlfile
		iread.open("Res" + xml_file_name);
		iwrite.open(xml_file_name);
		while (getline(iread, line_str))
		{
			iwrite << line_str << endl;
		}
		//done
		iwrite.close();
		iread.close();
		//erease the tem xml file
		iwrite.open("Res" + xml_file_name);
		iwrite << "";
		iwrite.close();
		//update the num of item
		iwrite.open("config.ini");
		iwrite << _Num_Of_Item << endl;
		iwrite.close();
		return true;
	}
	//change this str to lowercase string
	string Nocase(string str)
	{
		for (int i = 0; i != str.length(); i++)
		{
			if (str[i] >= 'a'&&str[i] <= 'z' ||
				str[i] >= 'A'&&str[i] <= 'Z')
			{
				//this is a character
				//change this char to lowercase
				if (str[i] >= 'A'&&str[i] <= 'Z')
				{
					str[i] = 'a' + (int)(str[i] - 'A');
				}
			}
		}
		return str;
	}

	//search a node
	//give me one words
	//this function will read your parm and action
	//please offer the parm include these example
	/*
	   value=xxx where name=xxx
	*/
	//the else case will return false
	bool search(string parm)
	{
		string parm_value="", parm_name="";
		//get the parm_value and parm_name
		int idex = 0;
		for (; parm[idex] != '='; idex++); idex++;
		for (; parm[idex] != ' '; idex++) 
		{
			parm_value += parm[idex];
		}
		for (; parm[idex] != '='; idex++); idex++;
		for (; idex != parm.length(); idex++)
		{
			parm_name += parm[idex];
		}
		//open the file for search
		ifstream iread;
		iread.open(xml_file_name);
		string line_str;
		while (getline(iread, line_str))
		{
			if (line_str.substr(0, 6) == "<item>")
			{
				//ok,start to search the name and the value
				//first,find the node's name
				for (int i = 6; i != line_str.length(); i++)
				{
					string search_name = "";
					if (line_str[i] == '<')
					{
						while ((i+1)!=line_str.length()&&line_str[i+1] != '>')
						{
							search_name += line_str[++i];
						}
					}i++;
					if (search_name==parm_name)
					{
						//find the name,check the value
						string search_value = "";
						while ((i+1)!=line_str.length()&&line_str[i+1] != '<')
						{
							search_value += line_str[++i];
						}
						if (search_value == parm_value)
						{
							//find the node
							return true;
						}
					}
				}
			}
		}
		iread.close();
		return false;
	}
	//delete an item from this fucking xml file
	//....easy ....
  };
}/*end of namespace DATA*/
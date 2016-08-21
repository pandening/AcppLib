#include"Header.h"
/*
*   this library is about graph
*   Before using this library,please read this document
*   if this library'sfunction not work,please check 
*   the souce code,then change the way of your using 
*/
namespace GRAPH
{
#define _Max_Vertex 100
#define _Max_Edge   100
#define _Inf_ 0x7fffffff
	/******************************_Bellman-Ford_*********************************************/
	struct Edge{ int fromVertex, toVertex, cost; };
	Edge _Edges[_Max_Vertex];
	int _dis_[_Max_Vertex];
	int _Vertex, _Edge;
	//Bellman-Ford algorithm
	void Bellman_Ford(int _dest_vertex)
	{
		_FOR_(i, _Vertex + 1) _dis_[i] = _Inf_;
		_dis_[_dest_vertex] = 0;
		while (true)
		{
			bool _update_loop = false;
			_FOR_(i, _Edge)
			{
				Edge _edge_ = _Edges[i];
				if (_dis_[_edge_.fromVertex] != _Inf_&&
					_dis_[_edge_.toVertex] > _dis_[_edge_.fromVertex] + _edge_.cost){
					//update this dis
					_dis_[_edge_.toVertex] = _dis_[_edge_.fromVertex] + _edge_.cost;
					_update_loop = true;
				}
			}
			if (_update_loop == false) break;
		}
		return;
	}


	//using bllman-ford to judge if this graph has negative-loop
	bool _Negative_loop()
	{
		memset(_dis_, 0, sizeof(_dis_));
		_FOR_(i, _Vertex){
			_FOR_(j, _Edge){
				Edge _edge_ = _Edges[j];
				if (_dis_[_edge_.toVertex] > _dis_[_edge_.fromVertex] + _edge_.cost)
				{
					_dis_[_edge_.toVertex] = _dis_[_edge_.fromVertex] + _edge_.cost;
					if (i == _Vertex - 1)
					{
						return true;
					}
				}
			}
		}
		return false;
	}
	/*****************************************************************************************/




	/**********************************_dijkstra_****************************************************/

	int _Cost_Array[_Max_Vertex][_Max_Vertex];
	int _Dis_Array[_Max_Vertex];
	bool _Visit_Array[_Max_Vertex];
	int Vertex;

	//dijkstra algorithm-1
	void _Dijkstra_1(int _dest_vertex)
	{
		_FOR_(i, Vertex) _Dis_Array[i] = _Inf_;
		_FOR_(i, Vertex) _Visit_Array[i] = false;
		_Dis_Array[_dest_vertex] = 0;
		for (;;)
		{
			int _vertex_ = -1;
			for (int V = 0; V < Vertex; V++)
			{
				if (!_Visit_Array[V] && (_vertex_ == -1 || _Dis_Array[V] < _Dis_Array[_vertex_])){
					_vertex_ = V;
				}
			}
			if (_vertex_ == -1) break;
			_Visit_Array[_vertex_] = true;
			_FOR_(i, Vertex)
			{
				_Dis_Array[i] = min(_Dis_Array[i], _Dis_Array[_vertex_] + _Cost_Array[_vertex_][i]);
			}
		}
		return;
	}


	////////////////////////////////////////////////////////////////////////////////////////
	struct _EDGE_{ int toVertex, cost; };
	int __Vertex;
	vector<_EDGE_> Grap[_Max_Vertex];
	int _Dis_array[_Max_Vertex];
	typedef pair<int, int> my_pair;

	//dijkstra-2
	void _Dijkstra_2(int _dest_vertex)
	{
		priority_queue<my_pair, vector<my_pair>, greater<my_pair> > _my_que;
		_FOR_(i, __Vertex) _Dis_Array[i] = _Inf_;
		_Dis_Array[_dest_vertex] = 0;
		_my_que.push(my_pair(0, _dest_vertex));
		while (!_my_que.empty())
		{
			my_pair mp = _my_que.top();
			_my_que.pop();
			if (_Dis_array[mp.second] < mp.first) continue;
			for (int i = 0; i < Grap[mp.second].size(); i++)
			{
				_EDGE_ edge = Grap[mp.second][i];
				if (_Dis_array[mp.second] + edge.cost < _Dis_array[edge.toVertex])
				{
					_Dis_array[edge.toVertex] = _Dis_array[mp.second] + edge.cost;
					_my_que.push(my_pair(edge.toVertex, _Dis_array[edge.toVertex]));
				}
			}
		}
		return;
	}

	/***********************************************************************************************/



	/***************************_Floyd-Warshall_***********************************/
	int _D_Array[_Max_Vertex][_Max_Vertex];
	int _Num_Vertex;

	//floyd-warshall
	void Floyd_Warshall()
	{
		_FOR_(k, _Num_Vertex)
			_FOR_(i, _Num_Vertex)
			_FOR_(j, _Num_Vertex)
			_D_Array[i][j] = min(_D_Array[i][j], _D_Array[i][k] + _D_Array[k][j]);
	}

	/*****************************************************************************/

	//并查集的实现
	///////////////////////////////////////////////////////////////////////
#define _Max_N 1000
	int _Parent_[_Max_N];
	int _Rank_[_Max_N];

	//init 
	void _start_(int _size_)
	{
		_FOR_(i, _size_)
		{
			_Parent_[i] = i;
			_Rank_[i] = 0;
		}
	}

	//find the root of this id
	int _find_(int id)
	{
		if (_Parent_[id] == id) return id;
		else return _Parent_[id] = _find_(id);
	}

	//unite 
	void _unite_(int x, int y)
	{
		x = _find_(x);
		y = _find_(y);
		if (x != y)
		{
			if (_Rank_[x] < _Rank_[y])
			{
				_Parent_[x] = y;
			}
			else if (_Rank_[x] == _Rank_[y]){
				_Parent_[x] = y;
				_Rank_[x]++;
			}
			else{
				_Parent_[y] = x;
			}
		}
	}

	//judge same tree
	bool _same_(int x, int y)
	{
		return _find_(x) == _find_(y);
	}


	////////////////////////////////////////////////////////////////////


	/********************************_Min-Spanning-Tree_*************************************/

	//prim algorithm-1
	int _graph_cost_array[_Max_Vertex][_Max_Vertex];
	int _mincost_set_array[_Max_Vertex];
	bool _used_set_array[_Max_Vertex];
	int _graph_vertex;
	//prim
	int Prim()
	{
		_FOR_(i, _graph_vertex)
		{
			_mincost_set_array[i] = _Inf_;
			_used_set_array[i] = false;
		}
		_mincost_set_array[0] = 0;
		int _Min_Spanning_tree_cost = 0;
		for (;;)
		{
			int _my_vertex = -1;
			for (int itver = 0; itver != _graph_vertex; itver++)
			{
				if (!_used_set_array[itver] &&
					(_my_vertex == -1 || _mincost_set_array[itver] < _mincost_set_array[_my_vertex]))
				{
					_my_vertex = itver;
				}
			}

			if (_my_vertex == -1) break;
			_used_set_array[_my_vertex] = true;
			_Min_Spanning_tree_cost += _mincost_set_array[_my_vertex];
			//update
			for (int itver = 0; itver != _graph_vertex; itver++)
			{
				_mincost_set_array[itver] = min(_mincost_set_array[itver], _Cost_Array[_my_vertex][itver]);
			}
		}
		return _Min_Spanning_tree_cost;
	}


	//kruskal algorithm


	struct _Graph_Edge
	{
		int _from_id, _to_id, _this_cost;
	};

	//the function pointer
	bool cmp_cost(_Graph_Edge e1, _Graph_Edge e2)
	{
		return e1._this_cost < e2._this_cost;
	}

	_Graph_Edge _edge_array[_Max_Edge];
	int _num_vertex, _num_edge;
	int kruskal()
	{
		sort(_edge_array, _edge_array + _num_edge, cmp_cost);
		int _min_spanning_cost = 0;
		_start_(_num_vertex + 1);
		for (int itver = 0; itver != _num_edge; itver++)
		{
			_Graph_Edge _this_edge = _edge_array[itver];
			if (_same_(_this_edge._from_id, _this_edge._to_id) == false)
			{
				_unite_(_this_edge._from_id, _this_edge._to_id);
				_min_spanning_cost += _this_edge._this_cost;
			}
		}
		return _min_spanning_cost;
	}
	/****************************************************************************************/
}/*end of graph*/
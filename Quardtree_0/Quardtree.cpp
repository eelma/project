#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class Object
{

public:
	float m_X;
	float m_Y;
	float m_Width;
	float m_Height;
public:
	Object()
	{
		m_X = 20 + (rand() % 80);
		m_Y = 20 + (rand() % 80);
		m_Width = 10.0f + (rand() % 10);
		m_Height = 10.0f + (rand() % 10);
	}

public:
	void SetPosition(float x, float y, float w, float h)
	{
		m_X = x;
		m_Y = y;
		m_Width = w;
		m_Height = h;
	}


};
class Node
{

public:
	float m_X;
	float m_Y;
	float m_Width;
	float m_Height;
	int m_Depth;
	vector<Object*>List;
	Node* m_Child[4];
	Node* m_Parent;

public:
	Node(Node*parent,float x, float y, float w, float h)
		:m_X(x),m_Y(y),m_Width(w),m_Height(h),m_Depth(0)
	{
		m_Parent=nullptr;
		if (parent != nullptr)
		{
			m_Parent = parent;
			m_Depth = parent->m_Depth + 1;
		}
	}

};


queue<Node*>s_Queue;
class QuardTree
{

public:
	Node* m_Rootnode;

public:
	void AddObject(Object*obj);
	void create(float w,float h);
	Node* createnode(Node*pnode,float x, float y, float w, float h);
	Node* FindNode(Node*fnode,Object*obj);
	void BuildTree(Node*node);

	bool RectToInRect(Node*node,Object*obj);

	int RectToRect(Node* node, Object* obj);
	int RectToRect(Object* fobj, Object* dobj);

	vector<Object*> Collision(Object* obj);
	void GetCollisitionObject(Node*node,Object*obj,vector<Object*>list);

};
void QuardTree::AddObject(Object* obj)
{
	Node* NFindNode = FindNode(m_Rootnode,obj);
	if (NFindNode != nullptr)
	{
		NFindNode->List.push_back(obj);
	}
}
void QuardTree::create(float w, float h)
{
	m_Rootnode = createnode(nullptr, 0, 0, w, h);
	BuildTree(m_Rootnode);

}
Node* QuardTree::createnode(Node* pnode, float x, float y, float w, float h)
{
	Node* newnode = new Node(pnode,x,y,w,h);
	return newnode;

}


void QuardTree::BuildTree(Node * node)
{
	if (node->m_Depth >= 2)return;
	if (node == nullptr)return;

	float x, y, w, h;
	x = node->m_X;
	y = node->m_Y;
	w = node->m_Width/2;
	h = node->m_Height/2;

	node->m_Child[0] = createnode(node,x,y,w,h);
	x = node->m_X+w;
	node->m_Child[1] = createnode(node, x, y, w, h);
	x = node->m_X;
	y = node->m_Y+h;
	node->m_Child[2] = createnode(node,x,y,w,h);
	x = node->m_X + w;
	y = node->m_Y + h;
	node->m_Child[3] = createnode(node,x,y,w,h);

	for (int i = 0; i < 4; i++)
	{
		BuildTree(node->m_Child[i]);
	}

}
bool QuardTree::RectToInRect(Node* node, Object* obj)
{
	if (node->m_X <= obj->m_X)
	{
		if (node->m_X + node->m_Width >= obj->m_X + obj->m_Width)
		{
			if (node->m_Y <= obj->m_Y)
			{
				if (node->m_Y + node->m_Height >= obj->m_Y + obj->m_Height)
				{
					return true;
				}
			}
		}
	}
	return false;
}

Node* QuardTree::FindNode(Node*root,Object*obj)
{
	do
	{
		for (int i = 0; i < 4; i++)
		{
			if (root->m_Child[i] != nullptr)
			{
				bool bin = RectToInRect(root->m_Child[i], obj);
				if (bin > 0)
				{
					s_Queue.push(root->m_Child[i]);
					break;
				}
			}
		}

		if (s_Queue.empty())break;
		root = s_Queue.front();
		s_Queue.pop();
	} while (root);
return root;

}
int QuardTree::RectToRect(Node* node, Object* obj)
{
	float x1 = node->m_X;
	float y1 = node->m_Y;
	float x2 = node->m_X+node->m_Width;
	float y2 = node->m_Y+node->m_Height;

	float z1 = obj->m_X;
	float w1 = obj->m_Y;
	float z2 = obj->m_X+obj->m_Width;
	float w2 = obj->m_X+obj->m_Height;

	float minX = (x1 < z1) ? x1 : z1;
	float minY = (y1 < w1) ? y1 : w1;
	float maxX = (x2 < z2) ? x2 : z2;
	float maxY = (y2 < w2) ? y2 : w2;

	if ((node->m_Width + obj->m_Width) >= (maxX + minX))
	{

		return 1;
	}

	return 0;
}
int QuardTree::RectToRect(Object* fobj, Object* dobj)
{

	float x1 = fobj->m_X;
	float y1 = fobj->m_Y;
	float x2 = fobj->m_X + fobj->m_Width;
	float y2 = fobj->m_Y + fobj->m_Height;

	float z1 = dobj->m_X;
	float w1 = dobj->m_Y;
	float z2 = dobj->m_X + dobj->m_Width;
	float w2 = dobj->m_X + dobj->m_Height;

	float minX = (x1 < z1) ? x1 : z1;
	float minY = (y1 < w1) ? y1 : w1;
	float maxX = (x2 < z2) ? x2 : z2;
	float maxY = (y2 < w2) ? y2 : w2;

	if ((fobj->m_Width + dobj->m_Width) >= (maxX + minX))
	{
		if ((fobj->m_Height + dobj->m_Width) >= (maxY + minY))
		{

			return 1;

		}
		
	}

	return 0;

}



vector<Object*> QuardTree::Collision(Object* obj)
{
	vector<Object*>list;
	GetCollisitionObject(m_Rootnode,obj,list);
	return list;

}
void QuardTree::GetCollisitionObject(Node*node,Object*obj,vector<Object*>list)
{
	if (node == nullptr)return;
	for (int i = 0; i < node->List.size(); i++)
	{
		if (RectToRect(node->List[i], obj))
		{
			list.push_back(node->List[i]);
		}
	}


}
int main(void)
{


	Object player;
	player.SetPosition(10, 10, 30, 30);
	QuardTree quadtree;
	quadtree.create(100.0f, 100.0f);
	for (int iObj = 0; iObj < 100; iObj++)
	{
		Object* pObj = new Object;
		quadtree.AddObject(pObj);
	}
	//Node* pNodePlayer = quadtree.FindNode(quadtree.m_Rootnode, &player);
	vector<Object*> list = quadtree.Collision(&player);
	if (!list.empty())
	{
		for (int iObj = 0; iObj < list.size(); iObj++)
		{
			cout << list[iObj]->m_X <<
				list[iObj]->m_Y <<endl;
		}
	}


}
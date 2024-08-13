#pragma once

template<class T, size_t MAXSIZE> class PoolAllocator
{
public:
	PoolAllocator()
	{
		for (int i = 0; i < MAXSIZE - 1; i++)
		{
			m_data[i].next = &m_data[i + 1];
		}
		m_data[MAXSIZE - 1].next = nullptr;
		m_list = &m_data[0];
	}
	~PoolAllocator()
	{
	}

	T* Alloc()
	{
		if (m_list)
		{
			DATA* current = m_list;
			DATA* next = current->next;
			m_list = next;
			return reinterpret_cast<T*>(current->data);
		}
		return nullptr;
	}

	void Free(T* addr)
	{
		if (addr)
		{
			DATA* ptr = reinterpret_cast<DATA*>(addr);
			ptr->next = m_list;
			m_list = ptr;
		}
	}

private:
	union DATA
	{
		DATA* next;
		char data[sizeof(T)];
	};
	DATA m_data[MAXSIZE];
	DATA* m_list;

};
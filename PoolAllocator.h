#pragma once

template<class T, size_t MAXSIZE> class PoolAllocator
{
public:
	PoolAllocator()
	{
		for (int i = 0; i < MAXSIZE - 1; i++)
		{
			m_block[i].next = &m_block[i + 1];
		}
		m_block[MAXSIZE - 1].next = nullptr;		// 最後のBlockのnextはnullptr
		m_list = &m_block[0];
	}
	~PoolAllocator()
	{
	}

	T* Alloc()
	{
		if (m_list)
		{
			Block* current = m_list;
			Block* next = current->next;
			m_list = next;
			return reinterpret_cast<T*>(current->block);
		}
		return nullptr;
	}

	void Free(T* addr)
	{
		if (addr)
		{
			Block* ptr = reinterpret_cast<Block*>(addr);
			ptr->next = m_list;
			m_list = ptr;
		}
	}

	// 演算子オーバーロード
	T& operator[](int index)
	{
		return *reinterpret_cast<T*>(m_block[index].block);
	}
	const T& operator[](int index) const
	{
		return *reinterpret_cast<const T*>(m_block[index].block);
	}

private:
	union Block
	{
		Block* next;
		char block[sizeof(T)];
	};
	Block m_block[MAXSIZE];
	Block* m_list;
};
#pragma once
#include <iostream>
#include <vector>
struct Message
{
public:
	char m_msg[100];
	char m_name[30];
	double  m_order;
	bool m_is_me = true;

public:
	Message() { m_order = 0; };
	Message(char* name, char* msg, double order)
	{
		strcpy_s(m_name, name);
		strcpy_s(m_msg, msg);
		m_order = order;
	};

};

template<typename T>
class MessageCollection
{
private:
	std::vector<T>			m_data;
	int						m_send_size;
	int						m_recive_size;
	int						m_send_pivot;
	int						m_recive_pivot;
	int						m_recvie_content_size;
	int						m_send_content_size;

public:
	MessageCollection(int size)
	{
		m_send_size = size / 2;
		m_recive_size = size - m_send_size;

		m_data.resize(size);

		m_send_pivot = 0;
		m_recive_pivot = 0;

		m_recvie_content_size = 0;
		m_send_content_size = 0;
	}

	MessageCollection(int size, T val)
	{
		m_send_size = size / 2;
		m_recive_size = size - m_send_size;

		m_data.resize(size, val);

		m_send_pivot = 0;
		m_recive_pivot = 0;

		m_recvie_content_size = 0;
		m_send_content_size = 0;
	}

	~MessageCollection()
	{
		// TODO	
	}

public:

	void SendPush(T& data)
	{
		data.m_is_me = true;
		m_data[m_send_pivot++] = data;
		m_send_content_size++;
		if (m_send_pivot >= m_send_size)
		{
			m_send_content_size--;
			m_send_pivot = m_send_pivot % m_send_size;
		}
	}

	void RecivePush(T& data)
	{
		data.m_is_me = false;
		m_data[m_send_size + m_recive_pivot++] = data;
		m_recvie_content_size++;
		if (m_recive_pivot >= m_recive_size)
		{
			m_recvie_content_size--;
			m_recive_pivot = m_recive_pivot % m_recive_size;
		}
	}

	int	TotalSize()
	{
		return m_recvie_content_size + m_send_content_size;
	};

	void CopyData(std::vector<T>& cdata)
	{
		cdata.clear();
		cdata.assign(m_data.begin(), m_data.end());
	}
};


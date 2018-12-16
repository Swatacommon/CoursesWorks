#pragma once
#define	ID_MAXSIZE		10			// ������������ ���������� �������� � ��������������ID_MAXSIZE
#define	TI_MAXSIZE		4096		// ������������ ���������� ����� � ������� ���������������
#define	TI_INT_DEFAULT	0x00000000	// �������� �� ��������� ��� ���� int
#define	TI_STR_DEFAULT	0x00		// �������� �� ��������� ��� ���� string 
#define	TI_NULLIDX		0xffffffff	// ��� �������� ������� ���������������
#define	TI_STR_MAXSIZE	255
#define TI_


namespace IT
{
	enum IDDATATYPE {
		NDEFD = 0,			//�����������
		INT = 1,			//ingeter
		STR = 2,			//string
		BOOL = 3			//bool
	};			
	enum IDTYPE {
		NDEFT = 0,	//����������� 
		V = 1,		//����������	
		F = 2,		//������� 
		L = 3,		//�������
		P = 4		//��������
	};	

	struct Entry									// ������ ������� ���������������
	{
		int			idxfirstLE;						// ������ ������ ������ � ������� ������
		char		id[30] = "";					//������������� (������������� ��������� �� ID_MAXSIZE)
		IDDATATYPE	iddatatype;						//��� ������
		IDTYPE		idtype;
		char* scope;
		union
		{
			int vint;
			struct
			{
				char len;
				char str[TI_STR_MAXSIZE - 1];
			}	vstr[TI_STR_MAXSIZE];
		}value;
		void reset()
		{
			for(int i = 0; i<30; i++)
			{
				id[i] = 0;
			}
			//memset(id, 0, ID_MAXSIZE);
			idxfirstLE = TI_NULLIDX;
			iddatatype = IT::NDEFD;
			idtype = IT::NDEFT;
		}
	};

	struct  IdTable						// ��������� ������� ���������������
	{
		int maxsize;					// ������� ������� ��������������� < TI_MAXSIZE
		int size;						// ������� ������ ������� ��������������� < maxsize
		Entry* table;					// ������ ����� ������� ���������������
	};


	IdTable Create(						// ������� ������� ���������������	
		int size						// ������� ������� ��������������� < TI_MAXSIZE 
	);
	void Add(							// �������� ������ � ������� ���������������
		IdTable& idtable,				// ��������� ������� ���������������
		Entry entry						// ������ ������� ���������������
	);
	Entry Getentry(IdTable& idtable, int n);

	int IsId(IdTable& idtable, char id[ID_MAXSIZE]);

	void Delete(IdTable& idtable);		// ������� ������� ��������������� ( ���������� ������ );
}
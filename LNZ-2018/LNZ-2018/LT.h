#pragma once
#define LEXEMA_FIXSIZE 1
#define LT_MAXSIZE 4096
#define LT_TI_NULLIDX 0xffffffff
#define LEX_INTEGER 'n'
#define LEX_STRING 's'
#define LEX_BOOL 'k'
#define LEX_ID 'i'			//������� ��� ��������������
#define LEX_LITERAL 'l'
#define LEX_FUNCTION 'f'
#define LEX_DECLARE 'd'
#define LEX_RETURN 'r'
#define LEX_PRINT 'p'
#define LEX_SEMICOLON ';'
#define LEX_COMMA ','
#define LEX_LEFTBRACE '{'
#define LEX_BRACELET '}'
#define LEX_LEFTHESIS '('
#define LEX_RIGHTHESIS ')'
#define LEX_PLUS '+'
#define LEX_MINUS '-'
#define LEX_STAR '*'
#define LEX_DIRSLASH '/'
#define LEX_EQUAL '='
#define LEX_MAIN 'm'
#define LEX_NUMBER 'z'

namespace LT
{
	enum priority { NDEF = 0, BRACE = 1, DS = 3, PM = 2, UM = 4 };
	struct Entry						// ������ ������� ������
	{
		priority pr;
		char lexema;					// �������
		int	 sn;						// ����� ������ � �������� ������
		int	 idxTI;						// ������ � ������� ���������������
	};

	struct LexTable						// ��������� �������� ������
	{
		int maxsize;					// ������� ������� ������ < LT_MAXSIZE
		int size;						// ������� ������ ������� ������ < MAXSIZE
		Entry* table;					// ������ ����� ������� ������
	};

	LexTable Create(		 // ������� ������� ������
		int size // ������� ������� ������ < LT_MAXSIZE
	);
	void Add(					// �������� ������ � ������� ������ 
		LexTable& lextable,	// ��������� ������� ������
		Entry entry			// ������ ������� ������
	);
	Entry Getentry(LexTable& lextable, int n);

	void Delete(LexTable& lextable);	// ������� ������� ������ ( ���������� ������ )
};
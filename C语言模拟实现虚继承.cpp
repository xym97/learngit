//#include<stdio.h>
//#include<stdlib.h>
//
//int main()
//{
//	system("pause");
//	return 0;
//}

#include<stdio.h>
#include<malloc.h>

	enum ShapeType {CIRCLE, SQUARE};  
	  
	//�麯�����������������calculateҲ����˼һ�£�������  
	typedef void (*show)();  
	typedef double (*calculate)(int arg);  
	  
	//�麯����ṹ��  
	typedef struct _VirtualFun  
	{  
	    show      showShape;   
	    calculate calArea;  
	} VirtualFun,*pVirtualFun;  
	  
	//���࣬Shape  
	typedef struct _Shape  
	{  
	    ShapeType type;  
	    VirtualFun *pfun;  
	}Shape,*ShapePointer;  
	  
	//�����࣬Circle  
	typedef struct _Circle  
	{  
	    Shape itsType;  
	    int r;  
	}Circle;  
	  
	//�����࣬Square  
    typedef struct _Square  
	{  
	    Shape itsType;  
	    int d;  
	}Square;  
	  
	//��д���麯��  
	void showCircle()  
	{  
	    printf("I'm circle/n");  
	}  
	  
	//��д���麯��  
	void showSquare()  
	{  
	    printf("I'm square/n");  
	}  
	  
	//circle��ʼ��  
	Circle circle ={  
	    CIRCLE,  
	    (pVirtualFun)malloc(sizeof(VirtualFun)),  
	    0  
	};  
	  
	//square��ʼ��  
	Square square ={  
	    SQUARE,  
	    (pVirtualFun)malloc(sizeof(VirtualFun)),  
	    0  
	};  
	  
	  
	//�����̬��ֻ��Ҫ���ݻ���ָ��ShapePointer��  
	void virtualShow(ShapePointer sp)  
	{  
	    sp->pfun->showShape();  
	}  
	  
	void main()  
	{  
	    //�麯����ʼ��  
	    circle.itsType.pfun->showShape = showCircle;  
	    square.itsType.pfun->showShape = showSquare;  
	      
	    //�û���ָ��ָ��������  
	    ShapePointer spc = (ShapePointer)&circle;  
	    ShapePointer sps = (ShapePointer)&square;  
	      
	    //���ݻ���ָ�룬���ֶ�̬��  
	    virtualShow(spc);  
	    virtualShow(sps);  
	    getchar();  
	} 

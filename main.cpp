#include<bits/stdc++.h>
#include <cstdint>
using namespace std;
uint32_t A1[1024][1024]={0};
uint32_t A2[1024][1024]={0};
uint32_t A3[1024][1024]={0};
uint32_t A4[1024][1024]={0};
uint32_t A5[1024][1024]={0};
uint32_t A6[1024][1024]={0};
uint32_t A7[1024][1024]={0};
uint32_t A8[1024][1024]={0};
uint32_t A9[1024][1024]={0};
uint32_t A10[1024][1024]={0};
uint32_t A11[1024][1024]={0};
uint32_t A12[1024][1024]={0};
uint32_t A13[1024][1024]={0};
uint32_t A14[1024][1024]={0};
uint32_t A15[1024][1024]={0};
uint32_t A16[1024][1024]={0};
uint32_t B[1024][1024]={0};
uint32_t C1[1024][1024]={0};
uint32_t C2[1024][1024]={0};
uint32_t C3[1024][1024]={0};
uint32_t C4[1024][1024]={0};
uint32_t C5[1024][1024]={0};
uint32_t C6[1024][1024]={0};
uint32_t C7[1024][1024]={0};
uint32_t C8[1024][1024]={0};
uint32_t C9[1024][1024]={0};
uint32_t C10[1024][1024]={0};
uint32_t C11[1024][1024]={0};
uint32_t C12[1024][1024]={0};
uint32_t C13[1024][1024]={0};
uint32_t C14[1024][1024]={0};
uint32_t C15[1024][1024]={0};
uint32_t C16[1024][1024]={0};
uint32_t C[1024][1024]={0};
void __attribute__ ((optimize("O3"),__target__("arch=core-avx2"))) find_ans(uint32_t *a,uint32_t*b,uint32_t* c)
{
	__asm__ __volatile__
	(
		"mov 	%[a],	%%rsi\n"//初始
		"mov 	%[b],	%%rdi\n"//被乘数
		"mov 	%[c],	%%rbx\n"//目的
		"mov 	$0,	%%rax\n"  //第一维
		"l1:\n"
		"mov	$0,	%%rcx\n"  //第二维，第一位
		"l2:\n"
		"mov	$0,	%%r15\n"  //第二维

		"l3:\n"
		"push 	%%rax\n"
		"push 	%%rcx\n"
		"mov 	%%rcx,	%%rax\n"
		"mov 	$4096,	%%rcx\n"
		"mul	%%rcx\n"
		"add	%%r15,	%%rax\n"
		"add	%%r15,	%%rax\n"
		"add	%%r15,	%%rax\n"
		"add	%%r15,	%%rax\n"  //rcx*4096+r15*4    b,c
		"vmovdqu	(%%rdi,%%rax),		%%ymm13\n"
		"pop	%%rcx\n"
		"pop 	%%rax\n"


		"push 	%%rax\n"
		"push 	%%r15\n"
		"mov	$4096,	%%r15\n" //rax*4096+rcx*4
		"mul 	%%r15\n"
		"add	%%rcx,	%%rax\n"
		"add	%%rcx,	%%rax\n"
		"add	%%rcx,	%%rax\n"
		"add	%%rcx,	%%rax\n"
		"vpbroadcastd	(%%rsi,%%rax),	%%ymm3\n" //a,b

		"vpmulld	%%ymm3,	%%ymm13,	%%ymm0\n"
		"pop 	%%r15\n"
		"pop	%%rax\n"

		"push 	%%rax\n"
		"push 	%%rcx\n"
		"mov	$4096,	%%rcx\n" //rax*4096+r15*4
		"mul 	%%rcx\n"
		"add	%%r15,	%%rax\n"
		"add	%%r15,	%%rax\n"
		"add	%%r15,	%%rax\n"
		"add	%%r15,	%%rax\n"
		"vmovdqu	(%%rbx,%%rax),	%%ymm1\n" //a,c
		"vpaddd  %%ymm0, %%ymm1, %%ymm2\n"
		"vmovdqu	%%ymm2,		(%%rbx,%%rax)\n"
		"pop 	%%rcx\n"
		"pop	%%rax\n"

		"inc	%%r15\n"
		"inc	%%r15\n"
		"inc	%%r15\n"
		"inc	%%r15\n"
		"inc	%%r15\n"
		"inc	%%r15\n"
		"inc	%%r15\n"
		"inc	%%r15\n"
		"push	%%rcx\n"
		"mov 	$1024,	%%rcx\n"
		"cmp	%%rcx, %%r15\n"
		"pop 	%%rcx\n"
		"jb		l3\n"

		"inc	%%rcx\n"
		"push	%%r15\n"
		"mov	$1024,	%%r15\n"
		"cmp	%%r15,%%rcx\n"
		"pop 	%%r15\n"
		"jb		l2\n"


		"inc 	%%rax\n"
		"push	%%rcx\n"
		"mov 	$1024,	%%rcx\n"
		"cmp	%%rcx,%%rax\n"
		"pop 	%%rcx\n"
		"jb		l1\n"

		:[c]"=m"(c)
		:[a]"m"(a),[b]"m"(b)
		: "%rax", "%rbx", "%rcx","rdx", "%r15", "%rsi", "%rdi", "%rbp","rsp", "memory" , "cc"
	);
	return ;
}
void __attribute__ ((optimize("O3"),__target__("arch=core-avx2"))) sum_ans(uint32_t *a,uint32_t*b,uint32_t *c)
{
	__asm__ __volatile__
	(
		"mov 	%[a],	%%rsi\n"//初始
		"mov 	%[b],	%%rdi\n"//被乘数
		"mov 	%[c],	%%rbx\n"//目的
		"mov 	$0,	%%rax\n"  //第一维
		"l4:\n"
		"mov	$0,	%%rcx\n"  //第二维
		"l5:\n"

		"push 	%%rax\n"
		"push 	%%r15\n"
		"mov	$4096,	%%r15\n" //rax*4096+rcx*4
		"mul 	%%r15\n"
		"add	%%rcx,	%%rax\n"
		"add	%%rcx,	%%rax\n"
		"add	%%rcx,	%%rax\n"
		"add	%%rcx,	%%rax\n"
		"vmovdqu	(%%rsi,%%rax),	%%ymm0\n" //a,c
		"vmovdqu	(%%rdi,%%rax),	%%ymm1\n"
		"vpaddd  %%ymm0, %%ymm1, %%ymm2\n"
		"vmovdqu	%%ymm2,		(%%rbx,%%rax)\n"
		"pop 	%%r15\n"
		"pop	%%rax\n"

		"inc	%%rcx\n"
		"inc	%%rcx\n"
		"inc	%%rcx\n"
		"inc	%%rcx\n"
		"inc	%%rcx\n"
		"inc	%%rcx\n"
		"inc	%%rcx\n"
		"inc	%%rcx\n"
		"push	%%r15\n"
		"mov	$1024,	%%r15\n"
		"cmp	%%r15,%%rcx\n"
		"pop 	%%r15\n"
		"jb		l5\n"


		"inc 	%%rax\n"
		"push	%%rcx\n"
		"mov 	$1024,	%%rcx\n"
		"cmp	%%rcx,%%rax\n"
		"pop 	%%rcx\n"
		"jb		l4\n"

		:[c]"=m"(c)
		:[a]"m"(a),[b]"m"(b)
		: "%rax", "%rbx", "%rcx","rdx", "%r15", "%rsi", "%rdi", "%rbp","rsp", "memory" , "cc"
	);
	return ;
}
int main()
{
	clock_t start, finish; 
	start = clock();
	freopen("A1.txt","r",stdin);
	for(int i=0;i<1024;i++)
	{
		for(int j=0;j<1024;j++)
		{
			cin>>A1[i][j];
		}
	}
	freopen("A2.txt","r",stdin);
	for(int i=0;i<1024;i++)
	{
		for(int j=0;j<1024;j++)
		{
			cin>>A2[i][j];
		}
	}
	freopen("A3.txt","r",stdin);
	for(int i=0;i<1024;i++)
	{
		for(int j=0;j<1024;j++)
		{
			cin>>A3[i][j];
		}
	}
	freopen("A4.txt","r",stdin);
	for(int i=0;i<1024;i++)
	{
		for(int j=0;j<1024;j++)
		{
			cin>>A4[i][j];
		}
	}
	freopen("A5.txt","r",stdin);
	for(int i=0;i<1024;i++)
	{
		for(int j=0;j<1024;j++)
		{
			cin>>A5[i][j];
		}
	}
	freopen("A6.txt","r",stdin);
	for(int i=0;i<1024;i++)
	{
		for(int j=0;j<1024;j++)
		{
			cin>>A6[i][j];
		}
	}
	freopen("A7.txt","r",stdin);
	for(int i=0;i<1024;i++)
	{
		for(int j=0;j<1024;j++)
		{
			cin>>A7[i][j];
		}
	}
	freopen("A8.txt","r",stdin);
	for(int i=0;i<1024;i++)
	{
		for(int j=0;j<1024;j++)
		{
			cin>>A8[i][j];
		}
	}
	freopen("A9.txt","r",stdin);
	for(int i=0;i<1024;i++)
	{
		for(int j=0;j<1024;j++)
		{
			cin>>A9[i][j];
		}
	}
	freopen("A10.txt","r",stdin);
	for(int i=0;i<1024;i++)
	{
		for(int j=0;j<1024;j++)
		{
			cin>>A10[i][j];
		}
	}
	freopen("A11.txt","r",stdin);
	for(int i=0;i<1024;i++)
	{
		for(int j=0;j<1024;j++)
		{
			cin>>A11[i][j];
		}
	}
	freopen("A12.txt","r",stdin);
	for(int i=0;i<1024;i++)
	{
		for(int j=0;j<1024;j++)
		{
			cin>>A12[i][j];
		}
	}
	freopen("A13.txt","r",stdin);
	for(int i=0;i<1024;i++)
	{
		for(int j=0;j<1024;j++)
		{
			cin>>A13[i][j];
		}
	}
	freopen("A14.txt","r",stdin);
	for(int i=0;i<1024;i++)
	{
		for(int j=0;j<1024;j++)
		{
			cin>>A14[i][j];
		}
	}
	freopen("A15.txt","r",stdin);
	for(int i=0;i<1024;i++)
	{
		for(int j=0;j<1024;j++)
		{
			cin>>A15[i][j];
		}
	}
	freopen("A16.txt","r",stdin);
	for(int i=0;i<1024;i++)
	{
		for(int j=0;j<1024;j++)
		{
			cin>>A16[i][j];
		}
	}
	
	freopen("B.txt","r",stdin);
	for(int i=0;i<1024;i++)
	{
		for(int j=0;j<1024;j++)
		{
			cin>>B[i][j];
		}
	}
	find_ans(&A1[0][0],&B[0][0],&C1[0][0]);
	find_ans(&A2[0][0],&B[0][0],&C2[0][0]);
	find_ans(&A3[0][0],&B[0][0],&C3[0][0]);
	find_ans(&A4[0][0],&B[0][0],&C4[0][0]);
	find_ans(&A5[0][0],&B[0][0],&C5[0][0]);
	find_ans(&A6[0][0],&B[0][0],&C6[0][0]);
	find_ans(&A7[0][0],&B[0][0],&C7[0][0]);
	find_ans(&A8[0][0],&B[0][0],&C8[0][0]);
	find_ans(&A9[0][0],&B[0][0],&C9[0][0]);
	find_ans(&A10[0][0],&B[0][0],&C10[0][0]);
	find_ans(&A11[0][0],&B[0][0],&C11[0][0]);
	find_ans(&A12[0][0],&B[0][0],&C12[0][0]);
	find_ans(&A13[0][0],&B[0][0],&C13[0][0]);
	find_ans(&A14[0][0],&B[0][0],&C14[0][0]);
	find_ans(&A15[0][0],&B[0][0],&C15[0][0]);
	find_ans(&A16[0][0],&B[0][0],&C16[0][0]);
	sum_ans(&C[0][0],&C1[0][0],&C[0][0]);
	sum_ans(&C[0][0],&C2[0][0],&C[0][0]);
	sum_ans(&C[0][0],&C3[0][0],&C[0][0]);
	sum_ans(&C[0][0],&C4[0][0],&C[0][0]);
	sum_ans(&C[0][0],&C5[0][0],&C[0][0]);
	sum_ans(&C[0][0],&C6[0][0],&C[0][0]);
	sum_ans(&C[0][0],&C7[0][0],&C[0][0]);
	sum_ans(&C[0][0],&C8[0][0],&C[0][0]);
	sum_ans(&C[0][0],&C9[0][0],&C[0][0]);
	sum_ans(&C[0][0],&C10[0][0],&C[0][0]);
	sum_ans(&C[0][0],&C11[0][0],&C[0][0]);
	sum_ans(&C[0][0],&C12[0][0],&C[0][0]);
	sum_ans(&C[0][0],&C13[0][0],&C[0][0]);
	sum_ans(&C[0][0],&C14[0][0],&C[0][0]);
	sum_ans(&C[0][0],&C15[0][0],&C[0][0]);
	sum_ans(&C[0][0],&C16[0][0],&C[0][0]);
	uint64_t ans=0;
	for(int i=0;i<1024;i++)
	{
		for(int j=0;j<1024;j++)
		{
			ans=ans+C[i][j];
		}
	}
	finish = clock(); 
	cout<<(finish-start)/CLOCKS_PER_SEC<<'\n';
	cout<<ans<<'\n';
 	return 0;
}



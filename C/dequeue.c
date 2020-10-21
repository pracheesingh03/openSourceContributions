
1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
37
38
39
40
41
42
43
44
45
46
47
48
49
50
51
52
53
54
55
56
57
58
59
60
61
62
63
64
65
66
67
68
69
70
71
72
73
74
75
76
77
78
79
80
81
82
83
84
85
86
87
88
89
90
91
92
93
94
95
96
97
98
99
100
101
102
103
104
105
106
107
108
109
110
111
112
113
114
115
116
117
118
119
120
121
122
123
124
125
126
127
128
129
130
131
132
133
134
135
136
137
138
139
140
141
142
143
144
145
146
147
148
149
150
151
152
153
154
155
156
157
158
159
160
161
162
163
164
165
166
167
168
169
170
171
172
173
174
175
176
177
178
179
180
181
182
183
184
185
186
187
188
189
190
191
192
193
194
195
196
197
198
199
200
201
202
#include<stdio.h>
#include<process.h>
#define MAX 30
 
typedef struct dequeue
{
	int data[MAX];
	int rear,front;
}dequeue;
 
void initialize(dequeue *p);
int empty(dequeue *p);
int full(dequeue *p);
void enqueueR(dequeue *p,int x);
void enqueueF(dequeue *p,int x);
int dequeueF(dequeue *p);
int dequeueR(dequeue *p);
void print(dequeue *p);
 
void main()
{
	int i,x,op,n;
	dequeue q;
	
	initialize(&q);
	
	do
	{
		printf("\n1.Create\n2.Insert(rear)\n3.Insert(front)\n4.Delete(rear)\n5.Delete(front)");
		printf("\n6.Print\n7.Exit\n\nEnter your choice:");
		scanf("%d",&op);
		
		switch(op)
		{
			case 1: printf("\nEnter number of elements:");
					scanf("%d",&n);
					initialize(&q);
					printf("\nEnter the data:");
					
					for(i=0;i<n;i++)
					{
						scanf("%d",&x);
						if(full(&q))
						{
							printf("\nQueue is full!!");
							exit(0);
						}
						enqueueR(&q,x);
					}
					break;
					
			case 2: printf("\nEnter element to be inserted:");
					scanf("%d",&x);
							
					if(full(&q))
					{
						printf("\nQueue is full!!");
						exit(0);
					}
					
					enqueueR(&q,x);
					break;
							
			case 3: printf("\nEnter the element to be inserted:");
					scanf("%d",&x);
							
					if(full(&q))
					{
						printf("\nQueue is full!!");
						exit(0);
					}
					
					enqueueF(&q,x);
					break;
							
			case 4: if(empty(&q))
					{
						printf("\nQueue is empty!!");
						exit(0);
					}
							
					x=dequeueR(&q);
					printf("\nElement deleted is %d\n",x);
					break;
					
			case 5: if(empty(&q))
					{
						printf("\nQueue is empty!!");
						exit(0);
					}
							
					x=dequeueF(&q);
					printf("\nElement deleted is %d\n",x);
					break;
							
			case 6: print(&q);
					break;
					
			default: break;
		}
	}while(op!=7);
}
 
void initialize(dequeue *P)
{
	P->rear=-1;
	P->front=-1;
}
 
int empty(dequeue *P)
{
	if(P->rear==-1)
		return(1);
	
	return(0);
}
 
int full(dequeue *P)
{
	if((P->rear+1)%MAX==P->front)
		return(1);
	
	return(0);
}
 
void enqueueR(dequeue *P,int x)
{
	if(empty(P))
	{
		P->rear=0;
		P->front=0;
		P->data[0]=x;
	}
	else
	{
		P->rear=(P->rear+1)%MAX;
		P->data[P->rear]=x;
	}
}
 
void enqueueF(dequeue *P,int x)
{
	if(empty(P))
	{
		P->rear=0;
		P->front=0;
		P->data[0]=x;
	}
	else
	{
		P->front=(P->front-1+MAX)%MAX;
		P->data[P->front]=x;
	}
}
 
int dequeueF(dequeue *P)
{
	int x;
	
	x=P->data[P->front];
	
	if(P->rear==P->front)	//delete the last element
		initialize(P);
	else
		P->front=(P->front+1)%MAX;
	
	return(x);
}
 
int dequeueR(dequeue *P)
{
	int x;
	
	x=P->data[P->rear];
	
	if(P->rear==P->front)
		initialize(P);
	else
		P->rear=(P->rear-1+MAX)%MAX;
		
	return(x);
}
 
void print(dequeue *P)
{
	if(empty(P))
	{
		printf("\nQueue is empty!!");
		exit(0);
	}
	
	int i;
	i=P->front;
	
	while(i!=P->rear)
	{
		printf("\n%d",P->data[i]);
		i=(i+1)%MAX;
	}
	
	printf("\n%d\n",P->data[P->rear]);
}

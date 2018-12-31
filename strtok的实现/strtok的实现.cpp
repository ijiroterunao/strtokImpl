#include<iostream>
#include<assert.h>
char *strtok(char *str, const char *delim)
{
	assert(delim != NULL); //分隔符字符串不能为空
	static char* left = NULL; //局部静态变量：保存剩余的字符串
	if (str == NULL) //如果str为空，则使用剩余的字符串
		str = left;
	if (str == NULL)
		return NULL;

	const char *p;
	bool flag;
	while (*str != 0) //去除起始部分的分隔符
	{
		p = delim;
		flag = false;
		while (*p != 0) //判断当前字符是否属于分隔符
		{
			if (*p++ == *str)
			{
				flag = true;
				break;
			}
		}
		if (!flag)
			break;
		++str;
	}
	char *s = str; //str保留住字符串起始指针
	while (*s != 0) //当遇到第一个分隔符是停止
	{
		p = delim;
		flag = false;
		while (*p != 0) //判断当前字符是否属于分隔符
		{
			if (*p++ == *s)
			{
				flag = true;
				*s = 0;
				break;
			}
		}
		++s;
		if (flag)
		{
			left = s;
			return str;
		}
	}
	left = NULL; //到字符串末尾也没遇到分隔符，没有剩余串了。
	return str;
}
int main()
{

	char str[] = "This,,,a-s,ample string.";
	char * pch;
	printf("%s\n", str);

	pch = strtok(str, " ,.-");
	while (pch != NULL)
	{
		printf("%s\n", pch);
		pch = strtok(NULL, " ,.-");
	}
	//printf("%s\n", str);
	return 0;
}
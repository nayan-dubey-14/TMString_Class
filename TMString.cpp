#include<iostream>
#include<string.h>
using namespace std;
class TMString
{
private:
char *ptr;
int size;
public:
TMString();
TMString(const char *ptr);
~TMString();
TMString & operator=(const TMString &other);
TMString & operator=(const char *ptr);
TMString operator+(const TMString &other);
void operator+=(const TMString &other);
TMString operator*(int count);
int operator<(const TMString &other);
int operator>(const TMString &other);
int operator<=(const TMString &other);
int operator>=(const TMString &other);
int operator==(const TMString &other);
int operator!=(const TMString &other);
friend ostream & operator<<(ostream &out,TMString &other);
};

TMString TMString::operator*(int count)
{
TMString k;
if(this->ptr==NULL || count<=0) return k;
k.size=strlen(this->ptr)*(count);
k.ptr=new char[k.size+1];
int i,e,f;
i=e=f=0;
while(i<count)
{
e=0;
while(this->ptr[e]!='\0')
{
k.ptr[f]=this->ptr[e];
f++;
e++;
}
i++;
}
k.ptr[f]='\0';
return k;
}

TMString::TMString()
{
this->ptr=NULL;
this->size=0;
}
TMString::TMString(const char *ptr)
{
if(ptr==NULL) return;
this->ptr=NULL;
this->size=strlen(ptr);
this->ptr=new char[this->size+1];
strcpy(this->ptr,ptr);
}

TMString::~TMString()
{
if(this->ptr) delete [] this->ptr;
}
TMString & TMString::operator=(const TMString &other)
{
if(this->ptr) delete [] this->ptr;
this->ptr=NULL;
this->size=0;
if(other.ptr==NULL) return *this;
this->size=strlen(other.ptr);
this->ptr=new char[this->size+1];
strcpy(this->ptr,other.ptr);
return *this;
}
TMString & TMString::operator=(const char *ptr)
{
if(this->ptr) delete [] this->ptr;
this->ptr=NULL;
this->size=0;
if(ptr==NULL) return *this;
this->size=strlen(ptr);
this->ptr=new char[this->size+1];
strcpy(this->ptr,ptr);
return *this;
}

TMString TMString::operator+(const TMString &other)
{
TMString k;
if(this->ptr==NULL && other.ptr==NULL) return k;
if(this->ptr==NULL) k=other;
else if(other.ptr==NULL) k=(*this);
else 
{
k=(*this);
k+=(other);
}
return k;
}

void TMString::operator+=(const TMString &other)
{
if(this->ptr==NULL || other.ptr==NULL) return;
if(other.ptr==NULL) return;
if(this->ptr==NULL)
{
(*this)=other;
return;
}
char *tmp;
tmp=new char[this->size+other.size+1];
strcpy(tmp,this->ptr);
strcat(tmp,other.ptr);
delete [] this->ptr;
this->ptr=tmp;
this->size=this->size+other.size;
}

int TMString::operator<(const TMString &other)
{
if(this->ptr==NULL && other.ptr==NULL) return 0;
if(this->ptr==NULL) return 1;
if(other.ptr==NULL) return 0;
return strcmp(this->ptr,other.ptr)<0;
}

int TMString::operator>(const TMString &other)
{
if(this->ptr==NULL && other.ptr==NULL) return 0;
if(this->ptr==NULL) return 0;
if(other.ptr==NULL) return 1;
return strcmp(this->ptr,other.ptr)>0;
}
int TMString::operator<=(const TMString &other)
{
if(this->ptr==NULL && other.ptr==NULL) return 1;
if(this->ptr==NULL) return 1;
if(other.ptr==NULL) return 0;
return strcmp(this->ptr,other.ptr)<=0;
}
int TMString::operator>=(const TMString &other)
{
if(this->ptr==NULL && other.ptr==NULL) return 1;
if(this->ptr==NULL) return 0;
if(other.ptr==NULL) return 1;
return strcmp(this->ptr,other.ptr)>=0;
}
int TMString::operator==(const TMString &other)
{
if(this->ptr==NULL && other.ptr==NULL) return 1;
if(this->ptr==NULL) return 0;
if(other.ptr==NULL) return 0;
return strcmp(this->ptr,other.ptr)==0;
}
int TMString::operator!=(const TMString &other)
{
if(this->ptr==NULL && other.ptr==NULL) return 0;
if(this->ptr==NULL) return 1;
if(other.ptr==NULL) return 1;
return strcmp(this->ptr,other.ptr)!=0;
}

ostream & operator<<(ostream &out,TMString &other)
{
if(other.ptr==NULL) return out;
out<<other.ptr;
return out;
}

int main()
{
TMString t,g,m;
g="Nayan Dubey";
cout<<g<<endl;
return 0;
}

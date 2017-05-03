// Comment : 读写文本文件(用于读取着色器的源代码.vert和.frag文件)
//
///////////////////////////////////////////////////////////////

char *textFileRead(char *fn); //读取文件
int textFileWrite(char *fn, char *s); //写入文件
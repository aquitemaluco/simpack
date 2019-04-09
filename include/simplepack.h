#ifndef SIMPLEPACK_H
#define SIMPLEPACK_H 1

#define LINE_MAX_CHAR 50

// Estrutura de configuracao do programa simple pack
typedef struct s_sinconf SIMCONF;
struct s_sinconf
{
	unsigned char title[LINE_MAX_CHAR];
	unsigned char label[LINE_MAX_CHAR];
	unsigned char version[LINE_MAX_CHAR];
	unsigned char owner[LINE_MAX_CHAR];
};

typedef SIMCONF *PSIMCONF;

void loadconfig(SIMCONF *simconf, char *file);
#endif

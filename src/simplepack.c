#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "simplepack.h"


// Carrega um arquivo de configuracao
void loadconfig(SIMCONF *simconf, char *file)
{
	FILE *h;

	h = fopen(file, "r");
	if (h == NULL) {
		fprintf (stderr, "Erro ao abrir o arquivo de configuracao!\n");
		exit(1);
	}

	int i;
	int ch;
	int equl;
	char param[8];
	while (1)
	{
		equl = 0;

		if ((ch = getc(h)) == -1)
		{
			fclose(h);
			return;
		}

		if (ch == 10) // Ignora linhas vazias
		{
			continue;
		}

		if (ch == '#') // Ignora linhas com comentario
		{
			while ((ch = getc(h)) != 10)
			{
				if (ch == -1)
				{
					fclose(h);
					return;
				}

				continue;
			}
			continue;
		}

		// Le identificador de parametro
		for (i=0; i<8; i++)
		{
			if (ch == 32 || ch == '=')
			{
				param[i] = 0;
				break;
			}

			param[i] = ch;
			ch = getc(h);
			if (ch == -1)
			{
				fclose(h);
				return;
			}
		}

		if (ch == -1)
		{
			fclose(h);
			return;
		}

		if (ch = 32)
		{
			ch = getc(h);
		}

		if (ch == '=')
		{
			equl = 1;
			ch = getc(h);
		}

		if (ch == 32)
		{
			ch = getc(h);
		}

		if (!equl)
		{
			fprintf (stderr, "Erro no arquivo de configuracao! Parametro %s com erro.\n", param);
			exit(1);
		}


		// carrega parametro titulo
		if (strcmp(param, "title") == 0)
		{
			int j = 0;
			while (j < LINE_MAX_CHAR)
			{
				simconf->title[j] = ch;

				j++;
				ch = getc(h);
				if (ch == 10)
				{
					simconf->title[j] = 0;
					break;
				}

				if (ch == -1)
				{
					fprintf (stderr, "Erro no arquivo de configuracao! Parametro %s com erro.\n", param);
					exit(1);
				}

			}
		}

		// carrega parametro label
		if (strcmp(param, "label") == 0)
		{
			int j = 0;
			while (j < LINE_MAX_CHAR)
			{
				simconf->label[j] = ch;

				j++;
				ch = getc(h);
				if (ch == 10)
				{
					simconf->label[j] = 0;
					break;
				}

				if (ch == -1)
				{
					fprintf (stderr, "Erro no arquivo de configuracao! Parametro %s com erro.\n", param);
					exit(1);
				}

			}
		}

		// carrega parametro version
		if (strcmp(param, "version") == 0)
		{
			int j = 0;
			while (j < LINE_MAX_CHAR)
			{
				simconf->version[j] = ch;

				j++;
				ch = getc(h);
				if (ch == 10)
				{
					simconf->version[j] = 0;
					break;
				}

				if (ch == -1)
				{
					fprintf (stderr, "Erro no arquivo de configuracao! Parametro %s com erro.\n", param);
					exit(1);
				}

			}
		}

		// carrega parametro owner
		if (strcmp(param, "owner") == 0)
		{
			int j = 0;
			while (j < LINE_MAX_CHAR)
			{
				simconf->owner[j] = ch;

				j++;
				ch = getc(h);
				if (ch == 10)
				{
					simconf->owner[j] = 0;
					break;
				}

				if (ch == -1)
				{
					fprintf (stderr, "Erro no arquivo de configuracao! Parametro %s com erro.\n", param);
					exit(1);
				}

			}
		}
	}

	fclose(h);
}

int main()
{
	SIMCONF sinconf;
	sinconf.title[0] = 0;
	sinconf.label[0] = 0;
	sinconf.version[0] = 0;
	sinconf.owner[0] = 0;

	loadconfig(&sinconf, "/etc/simplepack/simplepack.conf");

	printf("###########################################################################\n");
	printf("      Simplepack: %s\n", sinconf.title);
	printf("###########################################################################\n");
	printf("   %s\n\n", sinconf.label);
	printf(" Parabens! Voce esta executando o programa simplepack. Este programa tem a\n");
	printf(" finalidade de ajuda-lo a entender o processo de compilacao, instalacao e \n");
	printf(" configuracao de pacotes por meio de arquivos-fonte.\n\n");
	printf(" Por estar vendo esta mensagem, ja sei que voce obteve sucesso na compila-\n");
	printf(" cao. Faca configuracoes alterando o titulo, o rotulo, a versao e tambem o\n");
	printf(" proprietario, assim voce ja tera se tornado um expert na instalacao de \n");
	printf(" pacotes por meio de arquivos-fonte.\n");
	printf("###########################################################################\n");
	printf("   Versao: %s\n", sinconf.version);
	printf("   Propriedade de: %s\n", sinconf.owner);
	printf("###########################################################################\n");

}

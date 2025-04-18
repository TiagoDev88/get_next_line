/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfilipe- <tfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 10:38:06 by tfilipe-          #+#    #+#             */
/*   Updated: 2025/04/18 16:03:48 by tfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// ft_strjoin: Junto duas strings (ex: stash + buffer)

// ft_strchr: vai procurar \n na stash

// ft_strdup: Copia uma string

// ft_substr: Extrai parte da stash

// ft_strlen: Retorna tamanho da string

// Alguma função para limpar e gerir a memória
// (free, malloc, etc.)
// (não esquecer de libertar a stash no final)


char	*get_next_line(int fd)
{
	static char	*buffer;
	char 		buffer_to_read[BUFFER_SIZE + 1];
	ssize_t 	buffersize;
	ssize_t 	read_bytes;

	buffer = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffersize = BUFFER_SIZE;
	read_bytes = 1;
	//     declarar buffer temporário com tamanho BUFFER_SIZE
	//     inicializar variável de controlo de leitura (bytes_lidos)
	while (*buffer_to_read != '\n' && read_bytes != 0)
	{
		read_bytes = read(fd, buffer_to_read, buffersize);
		// if (read_bytes < 0)
		// {
		// 	free(read_bytes);
		// 	return (NULL);
		// }
		buffer_to_read[read_bytes] = '\0';
		write(1, &buffer_to_read, read_bytes);
	}

//     enquanto '\n' não estiver no stash E bytes_lidos != 0
//         bytes_lidos = ler do fd para o buffer
//         se bytes_lidos < 0
//             libertar memória, retornar NULL
//         concatenar buffer ao stash
	if (buffer == 0)
		return (NULL);
//     se stash está vazio
//         retornar NULL

//     encontrar índice do '\n' (ou fim da string se não existir)
//     copiar do início até '\n' para uma nova string chamada "linha"
    
//     atualizar stash com o que sobrou depois do '\n'
    
//     retornar "linha"
}

#include <fcntl.h>
int main()
{
	int fd = open("test.txt", O_RDONLY);
	get_next_line(fd);
	close(fd);
	fd = open("test.txt", O_RDONLY);
	get_next_line(fd);
}
// get_next_line: Lê uma linha de um arquivo (fd) e retorna-a como string
// (incluindo o '\n' se existir).
// A função lê o arquivo até encontrar um '\n' ou o fim do arquivo (EOF).
// Se não houver mais linhas para ler, retorna NULL.

// A função deve ser capaz de lidar com arquivos grandes e ler apenas o necessário
// para retornar a linha. Isso significa que deve usar um buffer temporário para
// ler os dados do arquivo em partes, em vez de ler tudo de uma vez. Isso é
// importante para evitar o uso excessivo de memória, especialmente se o arquivo for
// muito grande. A função deve ser capaz de lidar com arquivos de qualquer tamanho
// e deve ser capaz de ler linhas de qualquer comprimento.
// A função deve retornar uma nova string alocada na memória, que contém a linha
// lida do arquivo. A string deve ser terminada em '\0' e deve incluir o '\n' se
// existir. Se não houver mais linhas para ler, a função deve retornar NULL. A
// função deve garantir que a memória alocada para a string seja liberada corretamente

// após o uso. Isso significa que deve usar funções de alocação de memória como
// malloc e free corretamente. A função deve garantir que a memória alocada para
// a string seja liberada corretamente após o uso. Isso significa que deve usar
// funções de alocação de memória como malloc e free corretamente. A função deve
// garantir que a memória alocada para a string seja liberada corretamente após o uso.


// para evitar desperdício de memória. A função deve ser eficiente e não deve
//causar vazamentos de memória.

// USAR LINKED LISTS, PORQUE A LOGICA DE LINKED LISTS PARA ESTE PROJETO, VAI 
// AUXILIAR NOS PROJETOS FUTUROS.
// VAMOS TENTAR, EM VEZ DE USAR ARRAYS.
#include "monty.h"

var_t var;

/**
 * main - Main function the program enters in
 * @argc: The number of arguments passed to the program
 * @argv: Double pointer of an arry
 * Return - 0 success or 1
 *
 * Return: 0 on success
 */
int main(int argc, char **argv)
{
	var.stack = NULL;
	var.line = NULL;
	var.isStack = 1;

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	openfile(argv[1]);
	process();
	Funfree();
	return (0);
}

/**
 * openfile - Open the file.
 * @name: The name of the file
 * Return - Nothing, Function void
 */
void openfile(char *name)
{
	FILE *file;

	file = fopen(name, "r");
	if (file == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", name);
		exit(EXIT_FAILURE);
	}

	var.file = file;
}

/**
 * process - processes the monty file line by line
 * Return - Nothing, Function void
 */
void process(void)
{
	ssize_t read;
	size_t len = 0;
	char *opcode;

	while ((read = getline(&var.line, &len, var.file)) != -1)
	{
		var.lineNum++;

		opcode = strtok(var.line, " \t\n");
		if (!opcode || opcode[0] == '#')
			continue;

		if (strcmp(opcode, "push") == 0)
			push(strtok(NULL, " \t\n"));
		else
			runopcode(opcode, var.lineNum);
	}
}

/**
 * runopcode - Runs a given opcode, unless it is invalid
 * @opcode: The opcode to run
 * @lineNum: The line number the opcode is on
 *  * Return - Nothing, Function void
 */
void runopcode(char *opcode, unsigned int lineNum)
{
	unsigned int i;

	instruction_t opcodes[] = {
		{"pall", pall},
		{"pint", pint},
		{NULL, NULL}
	};

	for (i = 0; opcodes[i].opcode; ++i)
	{
		if (strcmp(opcodes[i].opcode, opcode) == 0)
		{
			opcodes[i].f(&var.stack, lineNum);
			return;
		}
	}

	dprintf(STDERR_FILENO, "L%u: unknown instruction %s\n", lineNum, opcode);
	Funfree();
	exit(EXIT_FAILURE);
}

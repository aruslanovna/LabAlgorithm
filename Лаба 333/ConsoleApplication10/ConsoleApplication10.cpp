
#include <fstream>

#include <windows.h> // поддерживает индентификатор TEXT
#include <stdio.h>
#include <lm.h>
#include <string>
#include <palsuite.h>

using namespace std;


/*
 * For now, it is assumed that MultiByteToWideChar will only be used in the PAL
 * with CP_ACP, and that dwFlags will be 0.
 */

int __cdecl main(int argc, char *argv[])
{
	char mbStr[128];
	WCHAR wideStr[128];
	int ret;
	int i;

	if (PAL_Initialize(argc, argv))
	{
		return FAIL;
	}

	for (i = 0; i < 128; i++)
	{
		mbStr[i] = 127 - i;
		wideStr[i] = 0;
	}


	ret = MultiByteToWideChar(CP_ACP, 0, mbStr, -1, wideStr, 0);
	if (ret != 128)
	{
		Fail("MultiByteToWideChar did not return correct string length!\n"
			"Got %d, expected %d\n", ret, 128);
	}

	/* Make sure the ASCII set (0-127) gets translated correctly */
	ret = MultiByteToWideChar(CP_ACP, 0, mbStr, -1, wideStr, 128);
	if (ret != 128)
	{
		Fail("MultiByteToWideChar did not return correct string length!\n"
			"Got %d, expected %d\n", ret, 128);
	}

	for (i = 0; i < 128; i++)
	{
		if (wideStr[i] != (WCHAR)(127 - i))
		{
			Fail("MultiByteToWideChar failed to translate correctly!\n"
				"Expected character %d to be %c (%x), got %c (%x)\n",
				i, 127 - i, 127 - i, wideStr[i], wideStr[i]);
		}
	}


	/* try a 0 length string */
	mbStr[0] = 0;
	ret = MultiByteToWideChar(CP_ACP, 0, mbStr, -1, wideStr, 0);
	if (ret != 1)
	{
		Fail("MultiByteToWideChar did not return correct string length!\n"
			"Got %d, expected %d\n", ret, 1);
	}

	PAL_Terminate();

	return PASS;
}

#define LANG_XX			23
#define LANG_CUSTOM		99

#define WM_LANG_PATH		 "/dev_flash/hen/lang"				// language folder

#ifdef ENGLISH_ONLY

static char STR_HOME[8] = "Home";

#define STR_FILES		"Files"
#define STR_GAMES		"Games"
#define STR_SETUP		"Setup"

#define STR_UPDN		"&#8593;/&#8595;" //↑/↓
#define STR_LFRG		"&#8592;/&#8594;" //←/→

#else
static int fh;

static char lang_code[3]			= "";

static char STR_FILES[24];//		= "Files";
static char STR_GAMES[24];//		= "Games";
static char STR_SETUP[24];//		= "Setup";
static char STR_NOTFOUND[40];//		= "Not found!";

static char COVERS_PATH[100];//		= "";

static u32 get_system_language(u8 *lang)
{
	//u32 val_lang = get_xreg_value("/setting/system/language", 1);

	int val_lang = 1;
	xsettings()->GetSystemLanguage(&val_lang);

	switch(val_lang)
	{
		case 0x0:
			*lang = 4;		//ger;
			break;
		//case 0x1:
		//	lang = 0;		//eng-us
		//	break;
		case 0x2:
			*lang = 3;		//spa
			break;
		case 0x3:
			*lang = 1;		//fre
			break;
		case 0x4:
			*lang = 2;		//ita
			break;
		case 0x5:
			*lang = 5;		//dut //Olandese
			break;
		case 0x6:			//por-por
		case 0x11:			//por-bra
			*lang = 6;
			break;
		case 0x7:
			*lang = 7;		//rus
			break;
		case 0x8:
			*lang = 18;		//jap
			break;
		case 0x9:
			*lang = 17;		//kor
			break;
		case 0xA:
		case 0xB:
			*lang = 19;		//chi-tra / chi-sim
			break;
		//case 0xC:
		//	*lang = 0;		//fin /** missing **/
		//	break;
		//case 0xD:
		//	*lang = 0;		//swe /** missing**/
		//	break;
		case 0xE:
			*lang = 20;		//dan
			break;
		//case 0xF:
		//	*lang = 0;		//nor /** missing**/
		//	break;
		case 0x10:
			*lang = 9;		//pol
			break;
		//case 0x12:
		//	*lang = 0;		//eng-uk
		//	break;
		default:
			*lang = 0;
			break;
	}

	return val_lang;
}

#define CHUNK_SIZE 512
#define GET_NEXT_BYTE  {if(p >= CHUNK_SIZE)  {cellFsReadWithOffset(fd, lang_pos, buffer, CHUNK_SIZE, &bytes_read); p = 0;} c = buffer[p++], lang_pos++;}

static u8 lang_roms = 0;

static void close_language(void)
{
	if(fh) cellFsClose(fh); lang_roms = fh = 0;
}

static bool language(const char *key_name, char *label, const char *default_str)
{
	u64 bytes_read = 0;
	static size_t p = 0, lang_pos = 0, size = 0;
	u8 c, i, key_len = strlen(key_name);

	u8 do_retry = 1;
	char buffer[MAX_LINE_LEN];

	if(!lang_roms) close_language();

 retry:
	strcpy(label, default_str);

	if(fh == 0)
	{
		char lang_path[40];

		if(lang_roms)
		{
			sprintf(lang_path, "%s/LANG_EMUS.TXT", WM_LANG_PATH);
			if(not_exists(lang_path))
				sprintf(lang_path, "%s/LANG_ROMS.TXT", WM_LANG_PATH);
		}
		else
		{
			if(webman_config->lang >= LANG_XX && (webman_config->lang != LANG_CUSTOM)) webman_config->lang = 0;

			const char *lang_codes[] = {"EN", "FR", "IT", "ES", "DE", "NL", "PT", "RU", "HU", "PL", "GR", "HR", "BG", "IN", "TR", "AR", "CN", "KR", "JP", "ZH", "DK", "CZ", "SK", "XX"};

			i = webman_config->lang; if(i > LANG_XX) i = LANG_XX;

			sprintf(lang_code, "_%.2s", lang_codes[i]);
			sprintf(lang_path, "%s/LANG%s.TXT", WM_LANG_PATH, lang_code);
		}

		lang_pos = 0;

		struct CellFsStat buf;

		if(cellFsStat(lang_path, &buf)) return true; size = (size_t)buf.st_size;

		if(cellFsOpen(lang_path, CELL_FS_O_RDONLY, &fh, NULL, 0)) return false;

		cellFsLseek(fh, lang_pos, CELL_FS_SEEK_SET, NULL); p = CHUNK_SIZE;
	}

	int fd = fh;

	do {
		for(i = 0; i < key_len;)
		{
			{ GET_NEXT_BYTE }

			if(c != key_name[i]) break; i++;

			if(i == key_len)
			{
				if(buffer[p] > ' ') break;

				size_t str_len = 0; u8 copy = 0;

				cellFsReadWithOffset(fd, lang_pos, buffer, CHUNK_SIZE, NULL); p = 0;

				// set value
				while(lang_pos < size)
				{
					{ GET_NEXT_BYTE }

					if(c == ']' || lang_pos >= size) break;

					if(copy) label[str_len++] = c;

					if(c == '[') copy = 1;
				}

				if(str_len) label[str_len] = '\0';

				if(str_len < do_retry) goto do_retry;

				return true;
			}
		}

	} while(lang_pos < size);

	if(do_retry)
	{
		do_retry:
		cellFsClose(fh); fh = do_retry = 0; goto retry;
	}

	return true;
}

#undef CHUNK_SIZE
#undef GET_NEXT_BYTE

static char TITLE_XX[12];

static void update_language(void)
{
	fh = 0;

	*COVERS_PATH = NULL;

	// initialize variables with default values	

	if(language("STR_FILES", STR_FILES, "Files"))
	{
		language("STR_GAMES", STR_GAMES, "Games");
		language("STR_SETUP", STR_SETUP, "Setup");
		language("STR_HOME", STR_HOME, "Home");
		
		language("STR_NOTFOUND", STR_NOTFOUND, "Not found!");

		language("COVERS_PATH", COVERS_PATH, COVERS_PATH);
		language("IP_ADDRESS", local_ip, local_ip);
		language("SEARCH_URL", search_url, "http://google.com/search?q=");

/*
#ifdef COBRA_ONLY
		language("STR_DISCOBRA", STR_DISCOBRA);
#endif
#ifdef REX_ONLY
		language("STR_RBGMODE", STR_RBGMODE);
		language("STR_RBGNORM", STR_RBGNORM);
		language("STR_RBGMENU", STR_RBGMENU);
#endif
*/
	}

	close_language();

	*html_base_path = NULL;

	// TITLE_XX

	*TITLE_XX = NULL; u8 id = LANG_CUSTOM, lang = webman_config->lang;

	if(lang ==  1) id = 2;  // fr
	if(lang ==  2) id = 5;  // it
	if(lang ==  3) id = 3;  // es
	if(lang ==  4) id = 4;  // de
	if(lang ==  5) id = 6;  // nl
	if(lang ==  6) id = 7;  // pt
	if(lang ==  7) id = 8;  // ru
	if(lang ==  9) id = 16; // pl
	if(lang == 14) id = 19; // tr
	if(lang == 16) id = 11; // zh
	if(lang == 17) id = 9;  // ko
	if(lang == 18) id = 0;  // jp
	if(lang == 19) id = 10; // ch
	if(lang == 20) id = 14; // da
	if(  id == LANG_CUSTOM) return;

	sprintf(TITLE_XX, "TITLE_%02i", id);
}
#endif //#ifndef ENGLISH_ONLY

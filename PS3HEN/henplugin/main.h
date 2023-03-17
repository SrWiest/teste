#ifndef _MAIN_H_
#define _MAIN_H_

#define PLUGINS_TXT_FILE_ENABLED	"/dev_hdd0/boot_plugins.txt"
#define PLUGINS_TXT_FILE_DISABLED	"/dev_hdd0/boot_plugins.txt.bak"

int filecopy(const char *src, const char *dst, const char *chk);

#endif

#include <cstdint>
#include <time.h>

#include <winapi/fileapi.h>
#include <winapi/handleapi.h>
#include <xboxkrnl/xboxkrnl.h>

static struct tm *filetime_to_tm(FILETIME filetime) {
	// Windows tracks time in 100ns since January 1, 1601. Unix tracks time in 1s since January 1, 1970.
	const int64_t ft = *reinterpret_cast<const int64_t *>(&filetime);
	time_t unix_time = static_cast<time_t>((ft - 116444736000000000ll) / 10000000);

	return gmtime(&unix_time);
}

int nxdk_file_access(const char *pathname, int mode) {
	// NXDK does not seem to implement GetSecurityInfo/GetNamedSecurityInfo
	//	-> partly emulate the behavior of access by checking if the file can be opened for reading
	HANDLE hFile = CreateFile(pathname, FILE_GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, 0, NULL);
	if (hFile != INVALID_HANDLE_VALUE) {
		CloseHandle(hFile);
		return 0;
	} else {
		return -1;
	}
}

int nxdk_mkdir(const char *newdir) {
	return CreateDirectoryA(newdir, NULL) ? 0 : -1;
}

bool nxdk_file_last_write_time(const char *filename, struct tm *mod_time) {

	HANDLE hFile = CreateFile(filename, FILE_GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, 0, NULL);
	if (hFile == INVALID_HANDLE_VALUE) {
		return false;
	}

	FILETIME ftWrite;
	bool result = GetFileTime(hFile, NULL, NULL, &ftWrite);
	if (result) {
		auto *tm_time = filetime_to_tm(ftWrite);
		if (tm_time) {
			*mod_time = *tm_time;
		} else {
			mod_time->tm_year = 0;
		}
	}

	CloseHandle(hFile);
	return result;
}

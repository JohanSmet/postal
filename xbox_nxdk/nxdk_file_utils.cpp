#include <cstdint>

#include <winapi/fileapi.h>
#include <winapi/handleapi.h>
#include <xboxkrnl/xboxkrnl.h>

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


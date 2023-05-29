#ifndef NXDK_FILE_UTILS_H
#define NXDK_FILE_UTILS_H

int nxdk_file_access(const char *pathname, int mode);

#define	F_OK	00
#define R_OK	04
#define access	nxdk_file_access

#endif // NXDK_FILE_UTILS_H

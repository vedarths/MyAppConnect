/*!
 * @header ACSecureFile.h
 *
 * @abstract POSIX style AppConnect Secure File IO operations
 *
 * @discussion
 * AppConnect ensures that all file contents written by these functions is encrypted, and file contents read by these
 * functions is decrypted. All file read and write operations must occur through AppConnect secure file functions. Using
 * any other file write functions will corrupt the files irreparably. Using any other file read functions will return
 * encrypted data, making the data appear corrupted.
 *
 * These operations only work on regular files. Named pipes, character specials, directories, block specials, symbolic
 * links and pipes are not supported.
 *
 * If secure services are unavailable, each of these functions will fail, set errno to EACCES, and set
 * ACSecureFileLastError to ACE_NO_KEYS_ERROR. See the -appConnect:secureFileIOPolicyChangedTo: message and the
 * secureServicesAvailability property in AppConnect.h, and see ACSecureFileLastError() in ACError.h
 *
 * If the encryption keys are incorrect or the file has become corrupt, each of these functions will fail, set errno to
 * EIO, and set ACSecureFileLastError to ACE_BAD_KEY_OR_CORRUPT_DATA_ERROR. See ACSecureFileLastError() in ACError.h
 *
 * @copyright Copyright (c) 2013-2018 MobileIron. All rights reserved.
 * <p>YOUR USE AND DISTRIBUTION OF THIS SOFTWARE IS SUBJECT TO THE SOFTWARE DEVELOPMENT KIT (SDK) AGREEMENT BETWEEN
 * YOU AND MOBILE IRON, INC. (“MI”).  USE OR DISTRIBUTION NOT IN STRICT ACCORDANCE WITH THE AGREEMENT IS PROHIBITED.</p>
 */

#ifndef ACSecureFile_h
#define ACSecureFile_h

#include <sys/uio.h>
#include <sys/stat.h>

/*! */
int ACSecureFileOpen(const char *path, int oflag, ...);

/*!
 * ACSharedSecureFileOpen() method opens file at "path", with "oflag". This method assumes that the file opened will be using encrypted/decrypted using key derived from shared key using "sharedGroupID" as Index.
 */
int ACSharedSecureFileOpen(const char *path, const char *sharedGroupId, int oflag, ...);

/*! */
ssize_t ACSecureFileWrite(int fd, const void *buf, size_t nbyte);
/*! */
ssize_t ACSecureFileWritev(int fd, const struct iovec *iov, int iovcnt);
/*! */
ssize_t ACSecureFilePwrite(int fd, const void *buf, size_t nbyte, off_t offset);

/*! */
ssize_t ACSecureFileRead(int fd, const void *buf, size_t nbyte);
/*! */
ssize_t ACSecureFileReadv(int fd, const struct iovec *iov, int iovcnt);
/*! */
ssize_t ACSecureFilePread(int fd, const void *buf, size_t nbyte, off_t offset);

/*! */
int ACSecureFtruncate(int fd, off_t length);
/*! */
int ACSecureTruncate(const char *path, off_t length);

/*! */
off_t ACSecureFileLseek(int fd, off_t offset, int whence);

/*! */
int ACSecureFstat(int fd, struct stat *buf);
/*! */
int ACSecureLstat(const char *__restrict path, struct stat *__restrict buf);

/*! */
int ACSecureFileRename(const char *oldName, const char *newName);

/*! */
int ACSecureFileClose(int fd);

/*!
 * ACSecureFileLastError : this function is not a part of the POSIX API but was added here to provide the library user
 * with a more descriptive error signaling method. Since there is additional policy layered on top the POSIX API, this
 * interface excuses for the shortcomings of using errno alone.
 *
 * The method takes a valid file descriptor and returns the last error seen during a prior secure file function call.
 * The last error is only set for those functions that operate on an open and valid file descriptor.
 */
int ACSecureFileLastError(int fd);

#endif

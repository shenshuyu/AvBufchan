#pragma once

#include <stdint.h>
#include <sys/uio.h>

#ifdef __cplusplus
#define BUFCHAN_API extern "C" __attribute__ ((visibility("default")))
#else
#define BUFCHAN_API __attribute__ ((visibility("default")))
#endif

#define AV_CACHED         (0x1)
#define AV_RDONLY         (0x2)
#define AV_WRONLY         (0x4)
#define AV_OLDEST         (0x8)

BUFCHAN_API int BufChan_MkFifo(char *name, size_t size);
BUFCHAN_API int BufChan_UnLink(char *name);

BUFCHAN_API long BufChan_Open(char *name, int mode);
BUFCHAN_API int BufChan_Close(long handle);

BUFCHAN_API ssize_t BufChan_Write(long handle, void *buf, size_t nbyte);
BUFCHAN_API ssize_t BufChan_Read (long handle, void *buf, size_t nbyte, int milliseconds);

BUFCHAN_API ssize_t BufChan_WriteV(long handle, struct iovec *iov, size_t iovcnt);
BUFCHAN_API ssize_t BufChan_ReadV (long handle, struct iovec *iov, size_t iovcnt, int milliseconds);

BUFCHAN_API ssize_t BufChan_WriteBlock(long handle, size_t maxsize, ssize_t (*write_cb)(struct iovec *iovs, int iovcnt, void *priv_data), void *priv_data);

BUFCHAN_API int BufChan_Left(long handle);
BUFCHAN_API int BufChan_ForEach(long handle, int (*cb)(struct iovec *iovs, int iovcnt, void *priv_data), void *priv_data);

BUFCHAN_API int BufChan_Reset(long handle);


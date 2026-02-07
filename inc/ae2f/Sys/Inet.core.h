#ifndef	ae2fsys_inet_core_h
#define	ae2fsys_inet_core_h

enum AE2FSYS_INET_ {
	/**
	 * @brief Operation succeed
	 * */
	AE2FSYS_INET_GOOD,

	AE2FSYS_INET_UNKNOWN,

	/**
	 * @brief System is not ready.
	 * */
	AE2FSYS_INET_NREADY,

	/**
	 * @brief System does not support this version.
	 * */
	AE2FSYS_INET_NSUPPORT,

	/**
	 * @brief Blocked by Windows Sockets 1.1 operations.
	 * */
	AE2FSYS_INET_BLKED,

	/**
	 * @brief Exceeded Socket task limit.
	 * */
	AE2FSYS_INET_PROCLMT,

	/**
	 * @brief Invalid pointer.	
	 * */
	AE2FSYS_INET_PTRINVAL,

	/** @brief Network is down */
	AE2FSYS_INET_NETDOWN,

	/** @brief startup code has not been called. */
	AE2FSYS_INET_NOINIT
};

#endif

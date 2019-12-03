/*!
 * @header ACSensitiveData.h
 *
 * @abstract Classes for storing sensitive data.
 *
 * @copyright Copyright (c) 2017-2018 MobileIron. All rights reserved.
 * <p>YOUR USE AND DISTRIBUTION OF THIS SOFTWARE IS SUBJECT TO THE SOFTWARE DEVELOPMENT KIT (SDK) AGREEMENT BETWEEN
 * YOU AND MOBILE IRON, INC. (“MI”).  USE OR DISTRIBUTION NOT IN STRICT ACCORDANCE WITH THE AGREEMENT IS PROHIBITED.</p>
 */

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class ACSensitiveMutableData;


/*!
 * @class ACSensitiveData
 * @abstract NSData subclass for holding transient sensitive data.
 *
 * @discussion This class is used to store sensitive information in RAM only for as long as necessary.
 * For example, store encryption keys only as long as necessary to perform a cryptographic operation.
 * The internal buffer is securely cleaned up upon -deallocate before releasing memory back to
 * the operating system.
 *
 * Release instances of this class as soon as possible in order to prevent sensitive information
 * from being stored in plain text in memory for too long. <tt>AC_SENSITIVE_DATA_MAX_LIFETIME</tt> and
 * <tt>AC_SENSITIVE_DATA_MAX_RUN_LOOP_ITERATIONS</tt> environment variables can be used to find
 * ACSensitiveData instances that are held in memory for too long.
 *
 * When <tt>AC_SENSITIVE_DATA_MAX_LIFETIME</tt> is set to a number greater than zero, an exception will be raised if
 * any ACSensitiveData instance is not deallocated before that number of seconds elapses from its allocation time.
 *
 * When <tt>AC_SENSITIVE_DATA_MAX_RUN_LOOP_ITERATIONS</tt> is set to a positive integer value, an exception
 * will be raised if any ACSensitiveData instance is not deallocated before the run loop in which it was allocated
 * completes the specified number of iterations (in any mode).
 *
 * The class has a mutable sublclass @link ACSensitiveMutableData @/link.
 */
@interface ACSensitiveData : NSData

- (ACSensitiveData *)copyWithZone:(nullable NSZone *)zone;
- (ACSensitiveMutableData *)mutableCopyWithZone:(nullable NSZone *)zone;

- (ACSensitiveData *)subdataWithRange:(NSRange)range;

#pragma mark - Unavailable

+ (instancetype)dataWithData:(NSData *)data NS_UNAVAILABLE;
- (instancetype)initWithData:(NSData *)data NS_UNAVAILABLE;

+ (nullable instancetype)dataWithContentsOfFile:(NSString *)path options:(NSDataReadingOptions)readOptionsMask error:(NSError **)errorPtr NS_UNAVAILABLE;
+ (nullable instancetype)dataWithContentsOfURL:(NSURL *)url options:(NSDataReadingOptions)readOptionsMask error:(NSError **)errorPtr NS_UNAVAILABLE;
+ (nullable instancetype)dataWithContentsOfFile:(NSString *)path NS_UNAVAILABLE;
+ (nullable instancetype)dataWithContentsOfURL:(NSURL *)url NS_UNAVAILABLE;

- (nullable instancetype)initWithContentsOfFile:(NSString *)path options:(NSDataReadingOptions)readOptionsMask error:(NSError **)errorPtr NS_UNAVAILABLE;
- (nullable instancetype)initWithContentsOfURL:(NSURL *)url options:(NSDataReadingOptions)readOptionsMask error:(NSError **)errorPtr NS_UNAVAILABLE;
- (nullable instancetype)initWithContentsOfFile:(NSString *)path NS_UNAVAILABLE;
- (nullable instancetype)initWithContentsOfURL:(NSURL *)url NS_UNAVAILABLE;

+ (nullable id)dataWithContentsOfMappedFile:(NSString *)path NS_UNAVAILABLE;
- (nullable id)initWithContentsOfMappedFile:(NSString *)path NS_UNAVAILABLE;

- (BOOL)writeToFile:(NSString *)path atomically:(BOOL)useAuxiliaryFile NS_UNAVAILABLE;
- (BOOL)writeToURL:(NSURL *)url atomically:(BOOL)atomically NS_UNAVAILABLE;
- (BOOL)writeToFile:(NSString *)path options:(NSDataWritingOptions)writeOptionsMask error:(NSError **)errorPtr NS_UNAVAILABLE;
- (BOOL)writeToURL:(NSURL *)url options:(NSDataWritingOptions)writeOptionsMask error:(NSError **)errorPtr NS_UNAVAILABLE;

@end


/*!
 * @class ACSensitiveMutableData
 * @abstract Mutable subclass of ACSensitiveData, offers limited subset of NSMutableData API.
 */
@interface ACSensitiveMutableData : ACSensitiveData

/*! A pointer to an internal buffer contained by the mutable data object. */
@property (nonatomic, readonly) void *mutableBytes NS_RETURNS_INNER_POINTER;
/*! The number of bytes contained in the buffer. */
@property (nonatomic, readwrite) NSUInteger length;

/*!
 * Creates and returns an ACSensitiveMutableData object capable of holding the specified number of bytes.
 * @param capacity The number of bytes the new data object should be capable of holding.
 * @return A new ACSensitiveMutableData object capable of holding capacity bytes.
 */
+ (nullable instancetype)dataWithCapacity:(NSUInteger)capacity;
/*!
 * Creates and returns an ACSensitiveMutableData object with a given length, filled with zero bytes.
 * @param length The number of bytes the new data object should contain.
 * @return A new ACSensitiveMutableData object of length bytes, filled with zeros.
 */
+ (nullable instancetype)dataWithLength:(NSUInteger)length;

/*!
 * Returns an initialized ACSensitiveMutableData object capable of holding the specified number of bytes.
 * @param capacity The number of bytes the new data object should be capable of holding.
 * @return An initialized ACSensitiveMutableData object capable of holding capacity bytes.
 */
- (nullable instancetype)initWithCapacity:(NSUInteger)capacity;
/*!
 * Returns an initialized ACSensitiveMutableData object with a given length, filled with zero bytes.
 * @param length The number of bytes the new data object should contain.
 * @return An initialized ACSensitiveMutableData object of length bytes, filled with zeros.
 */
- (nullable instancetype)initWithLength:(NSUInteger)length;

@end


/*!
 * @class ACSensitiveDataContainer
 * @abstract Provides long term storage for sensitive data
 *
 * @discussion This class should be used when an app needs to store some sensitive data for a period of time
 * longer than necessary to perform operations using the data. For example, use this class
 * to store a master key.
 * ACSensitiveDataContainer is a class cluster that supports either Secure Enclave based storage or local storage,
 * depending on the environment.
 */
@interface ACSensitiveDataContainer : NSObject

/*! A newly retrieved copy of the data passed to -initWithData: */
@property (nonatomic, readonly, copy) ACSensitiveData *data;

/*!
 * Creates and returns an ACSensitiveDataContainer object that holds the provided data.
 * @param data ACSensitiveData object to be stored in the container.
 * @result An initialized ACSensitiveDataContainer containing the given data.
 */

+ (instancetype)containerWithData:(ACSensitiveData *)data;

- (instancetype)init NS_UNAVAILABLE;
/*!
 * Returns an initialized ACSensitiveDataContainer object that holds the provided data.
 * @param data ACSensitiveData object to be stored in the container.
 * @result An initialized ACSensitiveDataContainer containing the given data.
 */
- (instancetype)initWithData:(ACSensitiveData *)data NS_DESIGNATED_INITIALIZER;

@end


NS_ASSUME_NONNULL_END

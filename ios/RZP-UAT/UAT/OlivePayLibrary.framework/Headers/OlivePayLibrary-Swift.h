#if 0
#elif defined(__arm64__) && __arm64__
// Generated by Apple Swift version 5.7.2 (swiftlang-5.7.2.135.5 clang-1400.0.29.51)
#ifndef OLIVEPAYLIBRARY_SWIFT_H
#define OLIVEPAYLIBRARY_SWIFT_H
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wgcc-compat"

#if !defined(__has_include)
# define __has_include(x) 0
#endif
#if !defined(__has_attribute)
# define __has_attribute(x) 0
#endif
#if !defined(__has_feature)
# define __has_feature(x) 0
#endif
#if !defined(__has_warning)
# define __has_warning(x) 0
#endif

#if __has_include(<swift/objc-prologue.h>)
# include <swift/objc-prologue.h>
#endif

#pragma clang diagnostic ignored "-Wduplicate-method-match"
#pragma clang diagnostic ignored "-Wauto-import"
#if defined(__OBJC__)
#include <Foundation/Foundation.h>
#endif
#if defined(__cplusplus)
#include <cstdint>
#include <cstddef>
#include <cstdbool>
#else
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#endif

#if !defined(SWIFT_TYPEDEFS)
# define SWIFT_TYPEDEFS 1
# if __has_include(<uchar.h>)
#  include <uchar.h>
# elif !defined(__cplusplus)
typedef uint_least16_t char16_t;
typedef uint_least32_t char32_t;
# endif
typedef float swift_float2  __attribute__((__ext_vector_type__(2)));
typedef float swift_float3  __attribute__((__ext_vector_type__(3)));
typedef float swift_float4  __attribute__((__ext_vector_type__(4)));
typedef double swift_double2  __attribute__((__ext_vector_type__(2)));
typedef double swift_double3  __attribute__((__ext_vector_type__(3)));
typedef double swift_double4  __attribute__((__ext_vector_type__(4)));
typedef int swift_int2  __attribute__((__ext_vector_type__(2)));
typedef int swift_int3  __attribute__((__ext_vector_type__(3)));
typedef int swift_int4  __attribute__((__ext_vector_type__(4)));
typedef unsigned int swift_uint2  __attribute__((__ext_vector_type__(2)));
typedef unsigned int swift_uint3  __attribute__((__ext_vector_type__(3)));
typedef unsigned int swift_uint4  __attribute__((__ext_vector_type__(4)));
#endif

#if !defined(SWIFT_PASTE)
# define SWIFT_PASTE_HELPER(x, y) x##y
# define SWIFT_PASTE(x, y) SWIFT_PASTE_HELPER(x, y)
#endif
#if !defined(SWIFT_METATYPE)
# define SWIFT_METATYPE(X) Class
#endif
#if !defined(SWIFT_CLASS_PROPERTY)
# if __has_feature(objc_class_property)
#  define SWIFT_CLASS_PROPERTY(...) __VA_ARGS__
# else
#  define SWIFT_CLASS_PROPERTY(...)
# endif
#endif

#if __has_attribute(objc_runtime_name)
# define SWIFT_RUNTIME_NAME(X) __attribute__((objc_runtime_name(X)))
#else
# define SWIFT_RUNTIME_NAME(X)
#endif
#if __has_attribute(swift_name)
# define SWIFT_COMPILE_NAME(X) __attribute__((swift_name(X)))
#else
# define SWIFT_COMPILE_NAME(X)
#endif
#if __has_attribute(objc_method_family)
# define SWIFT_METHOD_FAMILY(X) __attribute__((objc_method_family(X)))
#else
# define SWIFT_METHOD_FAMILY(X)
#endif
#if __has_attribute(noescape)
# define SWIFT_NOESCAPE __attribute__((noescape))
#else
# define SWIFT_NOESCAPE
#endif
#if __has_attribute(ns_consumed)
# define SWIFT_RELEASES_ARGUMENT __attribute__((ns_consumed))
#else
# define SWIFT_RELEASES_ARGUMENT
#endif
#if __has_attribute(warn_unused_result)
# define SWIFT_WARN_UNUSED_RESULT __attribute__((warn_unused_result))
#else
# define SWIFT_WARN_UNUSED_RESULT
#endif
#if __has_attribute(noreturn)
# define SWIFT_NORETURN __attribute__((noreturn))
#else
# define SWIFT_NORETURN
#endif
#if !defined(SWIFT_CLASS_EXTRA)
# define SWIFT_CLASS_EXTRA
#endif
#if !defined(SWIFT_PROTOCOL_EXTRA)
# define SWIFT_PROTOCOL_EXTRA
#endif
#if !defined(SWIFT_ENUM_EXTRA)
# define SWIFT_ENUM_EXTRA
#endif
#if !defined(SWIFT_CLASS)
# if __has_attribute(objc_subclassing_restricted)
#  define SWIFT_CLASS(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) __attribute__((objc_subclassing_restricted)) SWIFT_CLASS_EXTRA
#  define SWIFT_CLASS_NAMED(SWIFT_NAME) __attribute__((objc_subclassing_restricted)) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
# else
#  define SWIFT_CLASS(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
#  define SWIFT_CLASS_NAMED(SWIFT_NAME) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
# endif
#endif
#if !defined(SWIFT_RESILIENT_CLASS)
# if __has_attribute(objc_class_stub)
#  define SWIFT_RESILIENT_CLASS(SWIFT_NAME) SWIFT_CLASS(SWIFT_NAME) __attribute__((objc_class_stub))
#  define SWIFT_RESILIENT_CLASS_NAMED(SWIFT_NAME) __attribute__((objc_class_stub)) SWIFT_CLASS_NAMED(SWIFT_NAME)
# else
#  define SWIFT_RESILIENT_CLASS(SWIFT_NAME) SWIFT_CLASS(SWIFT_NAME)
#  define SWIFT_RESILIENT_CLASS_NAMED(SWIFT_NAME) SWIFT_CLASS_NAMED(SWIFT_NAME)
# endif
#endif

#if !defined(SWIFT_PROTOCOL)
# define SWIFT_PROTOCOL(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) SWIFT_PROTOCOL_EXTRA
# define SWIFT_PROTOCOL_NAMED(SWIFT_NAME) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_PROTOCOL_EXTRA
#endif

#if !defined(SWIFT_EXTENSION)
# define SWIFT_EXTENSION(M) SWIFT_PASTE(M##_Swift_, __LINE__)
#endif

#if !defined(OBJC_DESIGNATED_INITIALIZER)
# if __has_attribute(objc_designated_initializer)
#  define OBJC_DESIGNATED_INITIALIZER __attribute__((objc_designated_initializer))
# else
#  define OBJC_DESIGNATED_INITIALIZER
# endif
#endif
#if !defined(SWIFT_ENUM_ATTR)
# if defined(__has_attribute) && __has_attribute(enum_extensibility)
#  define SWIFT_ENUM_ATTR(_extensibility) __attribute__((enum_extensibility(_extensibility)))
# else
#  define SWIFT_ENUM_ATTR(_extensibility)
# endif
#endif
#if !defined(SWIFT_ENUM)
# define SWIFT_ENUM(_type, _name, _extensibility) enum _name : _type _name; enum SWIFT_ENUM_ATTR(_extensibility) SWIFT_ENUM_EXTRA _name : _type
# if __has_feature(generalized_swift_name)
#  define SWIFT_ENUM_NAMED(_type, _name, SWIFT_NAME, _extensibility) enum _name : _type _name SWIFT_COMPILE_NAME(SWIFT_NAME); enum SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_ENUM_ATTR(_extensibility) SWIFT_ENUM_EXTRA _name : _type
# else
#  define SWIFT_ENUM_NAMED(_type, _name, SWIFT_NAME, _extensibility) SWIFT_ENUM(_type, _name, _extensibility)
# endif
#endif
#if !defined(SWIFT_UNAVAILABLE)
# define SWIFT_UNAVAILABLE __attribute__((unavailable))
#endif
#if !defined(SWIFT_UNAVAILABLE_MSG)
# define SWIFT_UNAVAILABLE_MSG(msg) __attribute__((unavailable(msg)))
#endif
#if !defined(SWIFT_AVAILABILITY)
# define SWIFT_AVAILABILITY(plat, ...) __attribute__((availability(plat, __VA_ARGS__)))
#endif
#if !defined(SWIFT_WEAK_IMPORT)
# define SWIFT_WEAK_IMPORT __attribute__((weak_import))
#endif
#if !defined(SWIFT_DEPRECATED)
# define SWIFT_DEPRECATED __attribute__((deprecated))
#endif
#if !defined(SWIFT_DEPRECATED_MSG)
# define SWIFT_DEPRECATED_MSG(...) __attribute__((deprecated(__VA_ARGS__)))
#endif
#if __has_feature(attribute_diagnose_if_objc)
# define SWIFT_DEPRECATED_OBJC(Msg) __attribute__((diagnose_if(1, Msg, "warning")))
#else
# define SWIFT_DEPRECATED_OBJC(Msg) SWIFT_DEPRECATED_MSG(Msg)
#endif
#if defined(__OBJC__)
#if !defined(IBSegueAction)
# define IBSegueAction
#endif
#endif
#if !defined(SWIFT_EXTERN)
# if defined(__cplusplus)
#  define SWIFT_EXTERN extern "C"
# else
#  define SWIFT_EXTERN extern
# endif
#endif
#if !defined(SWIFT_CALL)
# define SWIFT_CALL __attribute__((swiftcall))
#endif
#if defined(__cplusplus)
#if !defined(SWIFT_NOEXCEPT)
# define SWIFT_NOEXCEPT noexcept
#endif
#else
#if !defined(SWIFT_NOEXCEPT)
# define SWIFT_NOEXCEPT 
#endif
#endif
#if defined(__cplusplus)
#if !defined(SWIFT_CXX_INT_DEFINED)
#define SWIFT_CXX_INT_DEFINED
namespace swift {
using Int = ptrdiff_t;
using UInt = size_t;
}
#endif
#endif
#if defined(__OBJC__)
#if __has_feature(modules)
#if __has_warning("-Watimport-in-framework-header")
#pragma clang diagnostic ignored "-Watimport-in-framework-header"
#endif
@import ObjectiveC;
#endif

#endif
#pragma clang diagnostic ignored "-Wproperty-attribute-mismatch"
#pragma clang diagnostic ignored "-Wduplicate-method-arg"
#if __has_warning("-Wpragma-clang-attribute")
# pragma clang diagnostic ignored "-Wpragma-clang-attribute"
#endif
#pragma clang diagnostic ignored "-Wunknown-pragmas"
#pragma clang diagnostic ignored "-Wnullability"
#pragma clang diagnostic ignored "-Wdollar-in-identifier-extension"

#if __has_attribute(external_source_symbol)
# pragma push_macro("any")
# undef any
# pragma clang attribute push(__attribute__((external_source_symbol(language="Swift", defined_in="OlivePayLibrary",generated_declaration))), apply_to=any(function,enum,objc_interface,objc_category,objc_protocol))
# pragma pop_macro("any")
#endif

#if defined(__OBJC__)

@class NSString;

SWIFT_CLASS("_TtC15OlivePayLibrary12ClearMessage")
@interface ClearMessage : NSObject
/// Creates a clear message from a string, with the specified encoding.
/// \param string String value of the clear message
///
/// \param rawEncoding Encoding to use to generate the clear data
///
///
/// throws:
/// SwiftyRSAError
- (nullable instancetype)initWithString:(NSString * _Nonnull)string using:(NSUInteger)rawEncoding error:(NSError * _Nullable * _Nullable)error;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end


SWIFT_CLASS("_TtC15OlivePayLibrary16EncryptedMessage")
@interface EncryptedMessage : NSObject
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end

@class UIViewController;
@protocol MFMessageComposeViewControllerDelegate;
@class NSError;

SWIFT_CLASS("_TtC15OlivePayLibrary15OliveUpiManager")
@interface OliveUpiManager : NSObject
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
+ (void)initiateSDKWithSdkHandshake:(id _Nullable)sdkHandshake view:(UIViewController * _Nonnull)view delegate:(id <MFMessageComposeViewControllerDelegate> _Nonnull)delegate callback:(void (^ _Nonnull)(id _Nullable, NSError * _Nullable))callback;
+ (void)clearCache;
+ (void)sendMobileBindReqstWithCallback:(void (^ _Nonnull)(id _Nullable, NSError * _Nullable))callback;
+ (void)listKeysWithCallback:(void (^ _Nonnull)(id _Nullable, NSError * _Nullable))callback;
+ (void)fetchListBanksWithCallback:(void (^ _Nonnull)(id _Nullable, NSError * _Nullable))callback;
+ (void)fetchAccountsiinWithIin:(NSString * _Nonnull)iin callback:(void (^ _Nonnull)(id _Nullable, NSError * _Nullable))callback;
+ (void)fetchMyAccountsWithCallback:(void (^ _Nonnull)(id _Nullable, NSError * _Nullable))callback;
+ (void)updateVPAWithVpa:(NSString * _Nonnull)vpa account:(id _Nullable)account callback:(void (^ _Nonnull)(id _Nullable, NSError * _Nullable))callback;
+ (void)checkBalanceWithAccount:(id _Nullable)account viewController:(UIViewController * _Nonnull)viewController callback:(void (^ _Nonnull)(id _Nullable, NSError * _Nullable))callback;
+ (void)changeMpinWithBankid:(NSString * _Nonnull)bankid account:(id _Nullable)account viewController:(UIViewController * _Nonnull)viewController callback:(void (^ _Nonnull)(id _Nullable, NSError * _Nullable))callback;
+ (void)restUPIPinWithBankId:(NSString * _Nonnull)bankId account:(id _Nullable)account type:(NSString * _Nonnull)type cardNo:(NSString * _Nonnull)cardNo exp:(NSString * _Nonnull)exp viewController:(UIViewController * _Nonnull)viewController callback:(void (^ _Nonnull)(id _Nullable, NSError * _Nullable))callback;
+ (void)tranHistoryFromDate:(NSString * _Nonnull)fromDate toDate:(NSString * _Nonnull)toDate callback:(void (^ _Nonnull)(id _Nullable, NSError * _Nullable))callback;
+ (void)raiseQueryWithTxnid:(NSString * _Nonnull)txnid refid:(NSString * _Nonnull)refid amount:(NSString * _Nonnull)amount query:(NSString * _Nonnull)query callback:(void (^ _Nonnull)(id _Nullable, NSError * _Nullable))callback;
+ (void)queryListWithCallback:(void (^ _Nonnull)(id _Nullable, NSError * _Nullable))callback;
+ (void)pendingNotificationsWithCallback:(void (^ _Nonnull)(id _Nullable, NSError * _Nullable))callback;
+ (void)getVpasFromContactWithMobile:(NSString * _Nonnull)mobile callback:(void (^ _Nonnull)(id _Nullable, NSError * _Nullable))callback;
+ (void)initiateCollectWithBeneaccount:(id _Nullable)beneaccount remittervpa:(id _Nullable)remittervpa amount:(NSString * _Nonnull)amount remarks:(NSString * _Nonnull)remarks merchantvpa:(NSString * _Nonnull)merchantvpa merchantid:(NSString * _Nonnull)merchantid submerchantid:(NSString * _Nonnull)submerchantid merchantchannelid:(NSString * _Nonnull)merchantchannelid trantype:(NSString * _Nonnull)trantype expiry:(NSString * _Nonnull)expiry viewController:(UIViewController * _Nonnull)viewController callback:(void (^ _Nonnull)(id _Nullable, NSError * _Nullable))callback;
+ (void)initiatePayWithAccount:(id _Nullable)account benevpa:(id _Nullable)benevpa paymentInput:(id _Nullable)paymentInput viewController:(UIViewController * _Nonnull)viewController callback:(void (^ _Nonnull)(id _Nullable, NSError * _Nullable))callback;
+ (void)collectApproveWithAccount:(id _Nullable)account PendingReq:(id _Nullable)PendingReq viewController:(UIViewController * _Nonnull)viewController callback:(void (^ _Nonnull)(id _Nullable, NSError * _Nullable))callback;
+ (void)parseQRStringWithCode:(NSString * _Nonnull)code callback:(void (^ _Nonnull)(id _Nullable, NSError * _Nullable))callback;
+ (void)accountRemoveWithAccount:(id _Nullable)account callback:(void (^ _Nonnull)(id _Nullable, NSError * _Nullable))callback;
+ (void)removeVpaWithVpa:(NSString * _Nonnull)vpa callback:(void (^ _Nonnull)(id _Nullable, NSError * _Nullable))callback;
+ (void)listvpaWithCallback:(void (^ _Nonnull)(id _Nullable, NSError * _Nullable))callback;
+ (void)saveBeneVpaWithBene:(id _Nullable)bene callback:(void (^ _Nonnull)(id _Nullable, NSError * _Nullable))callback;
+ (void)activateAccountWithIin:(NSString * _Nonnull)iin account:(id _Nullable)account cardNo:(NSString * _Nonnull)cardNo exp:(NSString * _Nonnull)exp viewController:(UIViewController * _Nonnull)viewController callback:(void (^ _Nonnull)(id _Nullable, NSError * _Nullable))callback;
+ (void)checkvpaWithVpa:(NSString * _Nonnull)vpa payerInfo:(id _Nullable)payerInfo callback:(void (^ _Nonnull)(id _Nullable, NSError * _Nullable))callback;
+ (void)collectRejectWithPendingReqVo:(id _Nullable)pendingReqVo callback:(void (^ _Nonnull)(id _Nullable, NSError * _Nullable))callback;
+ (void)collectBlockUnblockWithVpa:(NSString * _Nonnull)vpa block:(NSString * _Nonnull)block reason:(NSString * _Nonnull)reason callback:(void (^ _Nonnull)(id _Nullable, NSError * _Nullable))callback;
+ (void)collectBlocklistWithCallback:(void (^ _Nonnull)(id _Nullable, NSError * _Nullable))callback;
+ (NSString * _Nullable)getRegisteredMobileNumber SWIFT_WARN_UNUSED_RESULT;
+ (void)checkVpaAvailabilityWithVpa:(NSString * _Nonnull)vpa account:(NSString * _Nonnull)account callback:(void (^ _Nonnull)(id _Nullable, NSError * _Nullable))callback;
+ (void)deRegisterWithCallback:(void (^ _Nonnull)(id _Nullable, NSError * _Nullable))callback;
+ (NSString * _Nonnull)getMerchantChecksumWithEmailId:(NSString * _Nullable)emailId merchId:(NSString * _Nullable)merchId merchChanId:(NSString * _Nullable)merchChanId submerchantid:(NSString * _Nullable)submerchantid mcccode:(NSString * _Nullable)mcccode unqCustId:(NSString * _Nullable)unqCustId timestamp:(NSString * _Nullable)timestamp mobilenumber:(NSString * _Nullable)mobilenumber unqTxnId:(NSString * _Nullable)unqTxnId key:(NSString * _Nonnull)key SWIFT_WARN_UNUSED_RESULT;
+ (void)profileVpaWithVpa:(NSString * _Nonnull)vpa callback:(void (^ _Nonnull)(id _Nullable, NSError * _Nullable))callback;
+ (void)createMandateWithAccount:(id _Nullable)account beneVpa:(id _Nullable)beneVpa mandateInput:(id _Nullable)mandateInput viewController:(UIViewController * _Nonnull)viewController completionHandler:(void (^ _Nonnull)(id _Nullable, NSError * _Nullable))completionHandler;
+ (void)modifyMandateWithAccount:(id _Nullable)account beneVpa:(id _Nullable)beneVpa mandateInput:(id _Nullable)mandateInput viewController:(UIViewController * _Nonnull)viewController completionHandler:(void (^ _Nonnull)(id _Nullable, NSError * _Nullable))completionHandler;
+ (void)updateMandateWithAccount:(id _Nullable)account mandateInput:(id _Nullable)mandateInput newState:(NSString * _Nullable)newState viewController:(UIViewController * _Nonnull)viewController completionHandler:(void (^ _Nonnull)(id _Nullable, NSError * _Nullable))completionHandler;
+ (void)executeMandateWithMandateInput:(id _Nullable)mandateInput viewController:(UIViewController * _Nonnull)viewController completionHandler:(void (^ _Nonnull)(id _Nullable, NSError * _Nullable))completionHandler;
+ (void)authorizeMandateWithAccount:(id _Nullable)account beneVpa:(id _Nullable)beneVpa mandateInput:(id _Nullable)mandateInput viewController:(UIViewController * _Nonnull)viewController completionHandler:(void (^ _Nonnull)(id _Nullable, NSError * _Nullable))completionHandler;
+ (void)authorizeRecurranceMandateWithAccount:(id _Nullable)account beneVpa:(id _Nullable)beneVpa mandateInput:(id _Nullable)mandateInput viewController:(UIViewController * _Nonnull)viewController completionHandler:(void (^ _Nonnull)(id _Nullable, NSError * _Nullable))completionHandler;
+ (void)declineMandateWithAccount:(id _Nullable)account mandateInput:(id _Nullable)mandateInput viewController:(UIViewController * _Nonnull)viewController completionHandler:(void (^ _Nonnull)(id _Nullable, NSError * _Nullable))completionHandler;
+ (void)setUrlWithUrl:(NSString * _Nonnull)url;
+ (void)generateSignedQRWithQrString:(NSString * _Nonnull)qrString callback:(void (^ _Nonnull)(id _Nullable, NSError * _Nullable))callback;
+ (void)verifySignedQRWithQrString:(NSString * _Nonnull)qrString callback:(void (^ _Nonnull)(id _Nullable, NSError * _Nullable))callback;
+ (void)getPendingMandatesWithCallback:(void (^ _Nonnull)(id _Nullable, NSError * _Nullable))callback;
+ (void)getRecurranceListWithCallback:(void (^ _Nonnull)(id _Nullable, NSError * _Nullable))callback;
+ (void)getMandateTransactionsWithCallback:(void (^ _Nonnull)(id _Nullable, NSError * _Nullable))callback;
+ (void)defaultAccountWithAccountnumber:(NSString * _Nonnull)accountnumber ifsc:(NSString * _Nonnull)ifsc newvpa:(NSString * _Nonnull)newvpa oldvpa:(NSString * _Nonnull)oldvpa defaultvpa:(NSString * _Nonnull)defaultvpa callback:(void (^ _Nonnull)(id _Nullable, NSError * _Nullable))callback;
+ (void)checkStatusWithCheck:(NSString * _Nonnull)check callback:(void (^ _Nonnull)(id _Nullable, NSError * _Nullable))callback;
+ (void)raiseComplaintWithCheck:(NSString * _Nonnull)check callback:(void (^ _Nonnull)(id _Nullable, NSError * _Nullable))callback;
+ (void)getAddressWithAddress:(NSString * _Nonnull)address callback:(void (^ _Nonnull)(id _Nullable, NSError * _Nullable))callback;
+ (void)regMapperWithMapper:(NSString * _Nonnull)mapper callback:(void (^ _Nonnull)(id _Nullable, NSError * _Nullable))callback;
+ (void)reqInternationalQRActivationWithAccount:(NSString * _Nonnull)account activation:(NSString * _Nonnull)activation viewController:(UIViewController * _Nonnull)viewController callback:(void (^ _Nonnull)(id _Nullable, NSError * _Nullable))callback;
+ (void)valInternationalQRRequestWithAccount:(NSString * _Nonnull)account qrRequest:(NSString * _Nonnull)qrRequest viewController:(UIViewController * _Nonnull)viewController callback:(void (^ _Nonnull)(id _Nullable, NSError * _Nullable))callback;
+ (void)internationalQrStatusWithStatus:(NSString * _Nonnull)status viewController:(UIViewController * _Nonnull)viewController callback:(void (^ _Nonnull)(id _Nullable, NSError * _Nullable))callback;
@end


SWIFT_CLASS("_TtC15OlivePayLibrary10PrivateKey")
@interface PrivateKey : NSObject
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end


SWIFT_CLASS("_TtC15OlivePayLibrary9PublicKey")
@interface PublicKey : NSObject
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end


SWIFT_CLASS("_TtC15OlivePayLibrary9Signature")
@interface Signature : NSObject
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end

typedef SWIFT_ENUM(NSInteger, DigestType, open) {
  DigestTypeSha1 = 0,
  DigestTypeSha224 = 1,
  DigestTypeSha256 = 2,
  DigestTypeSha384 = 3,
  DigestTypeSha512 = 4,
};




SWIFT_CLASS("_TtC15OlivePayLibrary18VerificationResult")
@interface VerificationResult : NSObject
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end

#endif
#if defined(__cplusplus)
#endif
#if __has_attribute(external_source_symbol)
# pragma clang attribute pop
#endif
#pragma clang diagnostic pop
#endif

#else
#error unsupported Swift architecture
#endif


@interface AVCPluginCallResult : NSObject
@property (nonatomic, strong) NSDictionary<NSString *, id>* data;

- (instancetype)initWithData:(NSDictionary<NSString *, id>*)data;
@end

@interface AVCPluginCallError

@property (nonatomic, strong) NSString *message;
@property (nonatomic, strong) NSError *error;
@property (nonatomic, strong) NSDictionary<NSString *, id> *data;

@end

typedef void(^AVCPluginCallSuccessHandler)(AVCPluginCallResult *result);
typedef void(^AVCPluginCallErrorHandler)(AVCPluginCallError *error);

@interface AVCPluginCall : NSObject {
  // AVCPluginCallSuccessHandler successHandler;
  // AVCPluginCallErrorHandler errorHandler;
}

@property (nonatomic, strong) NSDictionary *options;
@property (nonatomic, copy) AVCPluginCallSuccessHandler successHandler;
@property (nonatomic, copy) AVCPluginCallErrorHandler errorHandler;

- (instancetype)initWithOptions:(NSDictionary *)options success:(AVCPluginCallSuccessHandler)success error:(AVCPluginCallErrorHandler)error;
- (AVCPluginCallSuccessHandler)getSuccessHandler;
- (AVCPluginCallErrorHandler)getErrorHandler;

@end


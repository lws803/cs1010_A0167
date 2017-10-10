// Raii wrapper for handle
struct HandleWrapper
{
    HandleWrapper(open_params...);

    bool Open();
    bool Close();
    operator bool();
    HandleNativeType NativeHandle();

    ~HandleWrapper();
};


// Operation type for Write / Read handle views
enum class OperationType { sync, async };

// Object for saving context of async io operations
struct AsyncToken
{
    ResultWithError WaitResult();
    optional<ResultWithError> CheckResult();
};



// Object that can read from handle
template <OperationType>
struct ReadView;

struct ReadView<sync>
{
    HandleWrapper handle_wrapper;
    Result Read(read_params...);
};

struct ReadView<async>
{
    HandleWrapper handle_wrapper;
    AsyncToken Read(read_params...);
};



// Object that can write to handle
template <OperationType>
struct WriteView;

struct WriteView<sync>;
{
    HandleWrapper handle_wrapper;
    Result Write(write_params...);
};

struct WriteView<async>;
{
    HandleWrapper handle_wrapper;
    AsyncToken Write(write_params...);
};




// Object that represent some common file operations
struct OperationView
{
    HandleWrapper handle_wrapper;
    bool Resize(params...);
    bool GetSize(params...);
    bool GetStatus(params...);
};



// Common enumerations for io sys calls
enum class OpenFlags {};
// Error converter (std::error_code)
struct ErrorConverter {};
// Streams helper for read / write views
struct ReadStream { operator>>(); };
struct WriteStream { operator<<(); };
// Continuation helper for AsyncToken
struct AsyncContinuation {};
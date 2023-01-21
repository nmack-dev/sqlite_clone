
class ReplExecutor
{
public:
    ReplExecutor() {};
    ~ReplExecutor() {};

    int Run();

private:
    static void replThread();
};
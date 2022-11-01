#include <iostream>
#include <vector>
#include <memory>

class IFileSystemListener
{
public:
    virtual void OnFileChange() = 0;
};

class FileSystemListener : public IFileSystemListener
{
    void OnFileChange() override
    {
        std::cout << "File has been changed" << std::endl;
    }
};

class FileSystemMonitor
{
public:
    void OnFileAdd()
    {
        std::cout << "OnFileAdd()" << std::endl;
        this->OnFileUpdate();
    }
    void OnFileClose()
    {
        std::cout << "OnFileClose()" << std::endl;
        this->OnFileUpdate();
    }
    void OnFileUpdate()
    {
        for (auto &Listener : Listeners)
        {
            Listener->OnFileChange();
        }
    }
    void AddFileChangeListener(std::shared_ptr<IFileSystemListener> &AddedListener)
    {
        Listeners.push_back(AddedListener);
    }

private:
    std::vector<std::shared_ptr<IFileSystemListener>> Listeners;
};

int main()
{
    std::shared_ptr<IFileSystemListener> Listener1 = std::make_shared<FileSystemListener>();
    std::shared_ptr<IFileSystemListener> Listener2 = std::make_shared<FileSystemListener>();
    FileSystemMonitor monitor;

    monitor.AddFileChangeListener(Listener1);
    monitor.OnFileAdd();
    monitor.AddFileChangeListener(Listener2);

    return 0;
}
#include <iostream>

using namespace std;

class SimpleVector
{
private:
    int *data_;
    int size_;
    int cap_;

public:
    SimpleVector()
    {
        data_ = nullptr;
        size_ = 0;
        cap_ = 0;
    }

    ~SimpleVector()
    {
        delete[] data_;
    }

    void push_back(int value)
    {
        if (size_ == cap_)
        {
            int newCap = (cap_ == 0) ? 2 : cap_ * 2;
            int *newData = new int(newCap);

            for (int i = 0; i < size_; i++)
            {
                newData[i] = data_[i];
            }

            delete[] data_;
            data_ = newData;
            cap_ = newCap;
        }
        data_[size_] = value;
        size_++;
    }

    int get(int index)
    {
        return data_[index];
    }

    int size()
    {
        return size_;
    }
};

int main()
{
    SimpleVector vector;
    vector.push_back(10);
    vector.push_back(20);
    vector.push_back(30);
    vector.push_back(40);

    cout << vector.get(4) << endl;
    cout << vector.size();

    return 0;
}
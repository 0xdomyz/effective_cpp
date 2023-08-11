class Widget
{
public:
    Widget(int size);
    Widget(const Widget &rhs);
    ~Widget();
    Widget &operator=(const Widget &rhs);
    void doThis();
    int showThat() const;
};

class RCWidget
{
public:
    RCWidget(int size) : value(new Widget(size)) {}
    void doThis()
    {
        if (value.getRCObject().isShared())
        {                               // do COW if
            value = new Widget(*value); // Widget is shared
        }
        value->doThis();
    }
    int showThat() const { return value->showThat(); }

private:
    RCIPtr<Widget> value;
};

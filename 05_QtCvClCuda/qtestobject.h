// Copyright(C) 2018 Andrey Yaromenok, ayaromenok@gmail.com
// MIT License - https://github.com/ayaromenok/test/blob/master/LICENSE

#ifndef NQTESTOBJECT_H
#define NQTESTOBJECT_H

class NqTestObject
{

public:
    NqTestObject();
    void testCPU();
    void testCL();
    void testCUDA();
    void getCpuInfo();
    void getClInfo();
    void getCudaInfo();

private:
};

#endif // NQTESTOBJECT_H

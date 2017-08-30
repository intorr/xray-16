#pragma once

#pragma unmanaged
#include "xrCore/xrCore.h"
#pragma managed

namespace XRay
{
namespace ManagedApi
{
namespace Core
{
using namespace System;
using System::Runtime::InteropServices::OutAttribute;
using System::Runtime::InteropServices::StructLayoutAttribute;
using System::Runtime::InteropServices::LayoutKind;
using System::Runtime::InteropServices::FieldOffsetAttribute;

[StructLayout(LayoutKind::Sequential, Size = sizeof(Fcolor))] public value struct ColorF
{
public:
    float r, g, b, a;

    Fcolor ToEngine();
};

[StructLayout(LayoutKind::Sequential, Size = sizeof(Fvector2))] public value struct Vector2F
{
    float x, y;

    Fvector2 ToEngine();
};

[StructLayout(LayoutKind::Sequential, Size = sizeof(Dvector2))] public value struct Vector2D
{
    double x, y;

    Dvector2 ToEngine();
};

[StructLayout(LayoutKind::Sequential, Size = sizeof(Fvector3))] public value struct Vector3F
{
    float x, y, z;

    Fvector3 ToEngine();
};

[StructLayout(LayoutKind::Sequential, Size = sizeof(Dvector3))] public value struct Vector3D
{
    double x, y, z;

    Dvector3 ToEngine();
};

//[FieldOffset(offsetof(Fvector4, x))]
[StructLayout(LayoutKind::Sequential, Size = sizeof(Fvector4))] public value struct Vector4F
{
    float x, y, z, w;

    Fvector4 ToEngine();
};

[StructLayout(LayoutKind::Sequential, Size = sizeof(Dvector4))] public value struct Vector4D
{
    double x, y, z, w;

    Dvector4 ToEngine();
};

[StructLayout(LayoutKind::Sequential, Size = sizeof(Ivector2))] public value struct Vector2I
{
    int x, y;

    Ivector2 ToEngine();
};

[StructLayout(LayoutKind::Sequential, Size = sizeof(Ivector3))] public value struct Vector3I
{
    int x, y, z;

    Ivector3 ToEngine();
};

[StructLayout(LayoutKind::Sequential, Size = sizeof(Ivector4))] public value struct Vector4I
{
    int x, y, z, w;

    Ivector4 ToEngine();
};

// XXX: Review ToEngine() function. m[][] can't be assigned. May be store Fmatrix in MatrixF?
[StructLayout(LayoutKind::Sequential, Size = sizeof(Fmatrix))] public value struct MatrixF
{
    Vector3F i, j, k, c;
    float _14_, _24_, _34_, _44_;

    float _11, _12, _13, _14;
    float _21, _22, _23, _24;
    float _31, _32, _33, _34;
    float _41, _42, _43, _44;

    array<float, 2>^ m;

    Fmatrix ToEngine();
};
[StructLayout(LayoutKind::Sequential, Size = sizeof(Dmatrix))] public value struct MatrixD
{
    Vector3D i, j, k, c;
    double _14_, _24_, _34_, _44_;

    double _11, _12, _13, _14;
    double _21, _22, _23, _24;
    double _31, _32, _33, _34;
    double _41, _42, _43, _44;

    array<double, 2>^ m;

    Dmatrix ToEngine();
};
}
}
}

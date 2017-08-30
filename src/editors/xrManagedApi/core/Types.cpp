#include "Pch.hpp"
#include "Types.hpp"

namespace XRay
{
namespace ManagedApi
{
namespace Core
{
Fcolor ColorF::ToEngine()
{
    Fcolor color;
    color.r = this->r;
    color.g = this->g;
    color.b = this->b;
    color.a = this->a;
    return std::move(color);
}

Fvector2 Vector2F::ToEngine()
{
    Fvector2 vector;
    vector.x = this->x;
    vector.y = this->y;
    return std::move(vector);
}

Dvector2 Vector2D::ToEngine()
{
    Dvector2 vector;
    vector.x = this->x;
    vector.y = this->y;
    return std::move(vector);
}

Fvector3 Vector3F::ToEngine()
{
    Fvector3 vector;
    vector.x = this->x;
    vector.y = this->y;
    vector.z = this->z;
    return std::move(vector);
}

Dvector3 Vector3D::ToEngine()
{
    Dvector3 vector;
    vector.x = this->x;
    vector.y = this->y;
    vector.z = this->z;
    return std::move(vector);
}

Fvector4 Vector4F::ToEngine()
{
    Fvector4 vector;
    vector.x = this->x;
    vector.y = this->y;
    vector.z = this->z;
    vector.w = this->w;
    return std::move(vector);
}

Dvector4 Vector4D::ToEngine()
{
    Dvector4 vector;
    vector.x = this->x;
    vector.y = this->y;
    vector.z = this->z;
    vector.w = this->w;
    return std::move(vector);
}

Ivector2 Vector2I::ToEngine()
{
    Ivector2 vector;
    vector.x = this->x;
    vector.y = this->y;
    return std::move(vector);
}

Ivector3 Vector3I::ToEngine()
{
    Ivector3 vector;
    vector.x = this->x;
    vector.y = this->y;
    vector.z = this->z;
    return std::move(vector);
}

Ivector4 Vector4I::ToEngine()
{
    Ivector4 vector;
    vector.x = this->x;
    vector.y = this->y;
    vector.z = this->z;
    vector.w = this->w;
    return std::move(vector);
}

Fmatrix MatrixF::ToEngine()
{
    Fmatrix matrix;
    matrix.i = this->i.ToEngine();
    matrix.j = this->j.ToEngine();
    matrix.k = this->k.ToEngine();
    matrix.c = this->c.ToEngine();

    matrix._14_ = this->_14_;
    matrix._24_ = this->_24_;
    matrix._34_ = this->_34_;
    matrix._44_ = this->_44_;

    matrix._11 = this->_11;
    matrix._12 = this->_12;
    matrix._13 = this->_13;
    matrix._14 = this->_14;

    matrix._21 = this->_21;
    matrix._22 = this->_22;
    matrix._23 = this->_23;
    matrix._24 = this->_24;

    matrix._31 = this->_31;
    matrix._32 = this->_32;
    matrix._33 = this->_33;
    matrix._34 = this->_34;

    matrix._41 = this->_41;
    matrix._42 = this->_42;
    matrix._43 = this->_43;
    matrix._44 = this->_44;

    return std::move(matrix);
}

Dmatrix MatrixD::ToEngine()
{
    Dmatrix matrix;
    matrix.i = this->i.ToEngine();
    matrix.j = this->j.ToEngine();
    matrix.k = this->k.ToEngine();
    matrix.c = this->c.ToEngine();

    matrix._14_ = this->_14_;
    matrix._24_ = this->_24_;
    matrix._34_ = this->_34_;
    matrix._44_ = this->_44_;

    matrix._11 = this->_11;
    matrix._12 = this->_12;
    matrix._13 = this->_13;
    matrix._14 = this->_14;

    matrix._21 = this->_21;
    matrix._22 = this->_22;
    matrix._23 = this->_23;
    matrix._24 = this->_24;

    matrix._31 = this->_31;
    matrix._32 = this->_32;
    matrix._33 = this->_33;
    matrix._34 = this->_34;

    matrix._41 = this->_41;
    matrix._42 = this->_42;
    matrix._43 = this->_43;
    matrix._44 = this->_44;

    return std::move(matrix);
}

}
}
}
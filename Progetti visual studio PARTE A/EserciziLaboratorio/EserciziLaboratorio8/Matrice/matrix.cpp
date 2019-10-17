#include "stdafx.h"
#include "Matrix.h"

template <class tipo>
Matrix<tipo>::Matrix(tipo a, tipo b, tipo c, tipo d)
{
	m[0][0] = a;
	m[0][1] = b;
	m[1][0] = c;
	m[1][1] = d;
}

template <class tipo>
tipo Matrix<tipo>::get_a() {
	return m[0][0];

}
template <class tipo>
tipo Matrix<tipo>::get_b() {
	return m[0][1];

}
template <class tipo>
tipo Matrix<tipo>::get_c() {
	return m[1][0];

}
template <class tipo>
tipo Matrix<tipo>::get_d() {
	return m[1][1];

}

template <class tipo>
Matrix<tipo> Matrix<tipo>::Add(Matrix<tipo> k) {
	Matrix<tipo> j;
	tipo x, y, z, w;
	x = (m[0][0] + k.get_a());
	y = (m[0][1] + k.get_b());
	z = (m[1][0] + k.get_c());
	w = (m[1][1] + k.get_d());
	j.set(x, y, z, w);
	return j;
}


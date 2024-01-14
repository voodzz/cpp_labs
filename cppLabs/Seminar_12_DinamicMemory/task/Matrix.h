#pragma once
#ifndef DEMOMATRIX_SRC_MATRIX_H_
#define DEMOMATRIX_SRC_MATRIX_H_

template<class T>
class Matrix {
public:
    Matrix();
    ~Matrix();
    Matrix(const size_t& m, const size_t& n);
    Matrix(const size_t& m, const size_t& n, const T& k);
    Matrix(const size_t& n, int number);

    Matrix(const Matrix<T>& other);
    Matrix(Matrix<T>&& other) noexcept;

    Matrix<T>& operator =(const Matrix<T>& other);
    Matrix<T>& operator =(Matrix<T>&& other) noexcept ;

    size_t GetN();
    size_t GetM();
    T **GetA();

    Matrix<T> operator +(const Matrix<T>& other);
    Matrix<T> operator -(const Matrix<T>& other);
    Matrix<T> operator *(const T& scalar);
    Matrix<T> operator /(const T& scalar);

    Matrix<T>& operator +=(const Matrix<T>& other);
    Matrix<T>& operator -=(const Matrix<T>& other);
    Matrix<T>& operator *=(const T& scalar);
    Matrix<T>& operator /=(const T& scalar);

    bool operator ==(const Matrix<T>& other);
    bool operator !=(const Matrix<T>& other);
private:
    T **a_;
    size_t m_;
    size_t n_;

    template<class E>
    friend std::istream& operator >>(std::istream& is, const Matrix<E>& matrix);
    template<class S>
    friend std::ostream& operator <<(std::ostream& os, const Matrix<S>& matrix);
};

template<class T>
Matrix<T>::Matrix(): m_(0), n_(0), a_(nullptr) {}

template<class T>
Matrix<T>::~Matrix() {
    for (size_t i = 0; i < m_; ++i) {
        delete[] a_[i];
    }
    delete[] a_;
}

template<class T>
Matrix<T>::Matrix(const size_t& m, const size_t& n) {
    m_ = m;
    n_ = n;

    a_ = new T* [m_];
    for (size_t i = 0; i < m_; ++i) {
        a_[i] = new T[n_];
    }

    for (size_t i = 0; i < m_; ++i) {
        for (size_t j = 0; j < n_; ++j) {
            a_[i][j] = 0;
        }
    }
}

template<class T>
Matrix<T>::Matrix(const size_t& m, const size_t& n, const T& k) {
    m_ = m;
    n_ = n;

    a_ = new int *[m_];
    for (size_t i = 0; i < m_; ++i) {
        a_[i] = new int[n_];
    }

    for (size_t i = 0; i < m_; ++i) {
        for(size_t j = 0; j != n_; ++j) {
            a_[i][j] = k;
        }
    }
}

template<class T>
Matrix<T>::Matrix(const size_t& n, int number) {
    m_ = n;
    n_ = n;

    a_ = new T*[m_];
    for (size_t i = 0; i != m_; ++i) {
        a_[i] = new T[n_];
    }

    for (size_t i = 0; i < m_; ++i) {
        for (size_t j = 0; j != n_; ++j) {
            if (i != j) {
                a_[i][j] = 0;
            } else {
                a_[i][j] = number;
            }
        }
    }
}

template<class T>
Matrix<T>::Matrix(const Matrix<T>& other) {
    m_ = other.m_;
    n_ = other.n_;

    a_ = new T* [m_];
    for(size_t i = 0; i != m_; ++i) {
        a_[i] = new T[n_];
    }

    for (size_t i = 0; i != m_; ++i) {
        for (size_t j = 0; j != n_; ++j) {
            a_[i][j] = other.a_[i][j];
        }
    }
}

template<class T>
Matrix<T>::Matrix(Matrix<T>&& other) noexcept {
    m_ = other.m_;
    n_ = other.n_;
    a_ = other.a_;

    other.m_ = 0;
    other.n_ = 0;
    other.a_ = nullptr;
}

template<class T>
Matrix<T>& Matrix<T>::operator=(const Matrix<T>& other) {
    if (this == &other) {
        return *this;
    }

    for (size_t i = 0; i < m_; ++i) {
        delete[] a_[i];
    }
    delete[] a_;

    m_ = other.m_;
    n_ = other.n_;

    a_ = new T*[m_];
    for (size_t i = 0; i != m_; ++i) {
        a_[i] = new T[n_];
    }

    for (size_t i = 0; i != m_; ++i) {
        for (size_t j = 0; j != n_; ++j) {
            a_[i][j] = other.a_[i][j];
        }
    }
    return *this;
}

template<class T>
Matrix<T>& Matrix<T>::operator=(Matrix<T>&& other) noexcept {
    if (this == &other) {
        return *this;
    }

    for (size_t i = 0; i < m_; ++i) {
        delete[] a_[i];
    }
    delete[] a_;

    a_ = other.a_;
    m_ = other.m_;
    n_ = other.n_;

    other.a_ = nullptr;
    other.m_ = 0;
    other.n_ = 0;

    return *this;
}

template<class T>
size_t Matrix<T>::GetN() {
    return n_;
}

template<class T>
size_t Matrix<T>::GetM() {
    return m_;
}

template<class T>
T** Matrix<T>::GetA() {
    return a_;
}

template<class T>
Matrix<T> Matrix<T>::operator+(const Matrix<T>& other) {
    if (n_ != other.n_ || m_ != other.m_) {
        throw std::runtime_error("The matrices are of different sizes, therefore we can not sum them up.");
    }
    for (size_t i = 0; i < m_; ++i) {
        for (size_t j = 0; j < n_; ++j) {
            a_[i][j] += other.a_[i][j];
        }
    }
    return *this;
}

template<class T>
Matrix<T> Matrix<T>::operator-(const Matrix<T>& other) {
    if (n_ != other.n_ || m_ != other.m_) {
        throw std::runtime_error("The matrices are of different sizes, therefore we can not find their difference.");
    }
    for (size_t i = 0; i < m_; ++i) {
        for (size_t j = 0; j < n_; ++j) {
            a_[i][j] -= other.a_[i][j];
        }
    }
    return *this;
}

template<class T>
Matrix<T> Matrix<T>::operator*(const T& scalar) {
    for (size_t i = 0; i < m_; ++i) {
        for (size_t j = 0; j < n_; ++j) {
            a_[i][j] *= scalar;
        }
    }
    return *this;
}

template<class T>
Matrix<T> Matrix<T>::operator/(const T& scalar) {
    for (size_t i = 0; i < m_; ++i) {
        for (size_t j = 0; j < n_; ++j) {
            a_[i][j] /= scalar;
        }
    }
    return *this;
}

template<class T>
Matrix<T>& Matrix<T>::operator+=(const Matrix<T>& other) {
    return (*this + other);
}

template<class T>
Matrix<T>& Matrix<T>::operator-=(const Matrix<T>& other) {
    return (*this - other);
}

template<class T>
Matrix<T>& Matrix<T>::operator*=(const T& scalar) {
    return (*this * scalar);
}

template<class T>
Matrix<T>& Matrix<T>::operator/=(const T& scalar) {
    return (*this / scalar);
}

template<class T>
bool Matrix<T>::operator ==(const Matrix<T>& other) {
    if (m_ != other.m_ || n_ != other.n_) {
        return false;
    }
    for (size_t i = 0; i != m_; ++i){
        for (size_t j = 0; j != n_; ++j){
            if (a_[i][j] != other.a_[i][j]) {
                return false;
            }
        }
    }
    return true;
}

template<class T>
bool Matrix<T>::operator !=(const Matrix<T>& other) {
    return !(*this == other);
}

template<class T>
std::istream& operator >>(std::istream& is, const Matrix<T>& matrix) {
    for (size_t i = 0; i != matrix.m_; ++i) {
        for (size_t j = 0; j != matrix.n_; ++j) {
            is >> matrix.a_[i][j];
        }
    }
    return is;
}

template<class T>
std::ostream& operator <<(std::ostream& os, const Matrix<T>& matrix) {
    for (size_t i = 0; i != matrix.m_; ++i) {
        for (size_t j = 0; j != matrix.n_; ++j) {
            os << matrix.a_[i][j] << ' ';
        }
        os << '\n';
    }
    return os;
}

#endif //DEMOMATRIX_SRC_MATRIX_H_
#pragma once

// ����� ����������� ����� ������� � ����������� ��������� ������������ ��������,
// ��� �������
#pragma warning( disable : 4503 )

// ���������� ��������� �������, ������� ���� �������� ��� ���������� � deprecated
// @see http://lists.boost.org/Archives/boost/2006/08/109338.php 
//#pragma warning( disable : 4996 )


// ��� ������ ������������� this � ������������.
#define MSVC_PUSH_DISABLE_WARNING(n) __pragma(warning(push)) \
                                     __pragma(warning(disable:n))
#define MSVC_POP_WARNING() __pragma(warning(pop))
#define ALLOW_THIS_IN_INITIALIZER_LIST(code) MSVC_PUSH_DISABLE_WARNING(4355) \
                                             code \
                                             MSVC_POP_WARNING()


// �������� ����������, �������� ����� ���� �� ��������� Windows
#define WIN32_LEAN_AND_MEAN


// �������� ������� ������ � WinDef.h
#define NOMINMAX

// ���������� �������������� ���������
#define _USE_MATH_DEFINES


#include <assert.h>
#include <math.h>
#include <memory>
#include <stdio.h>
#include <string>

#include <gtest/gtest.h>

////////////////////////////////////////////////////////////////////////////////
//
// Copyright 2016 RWS Inc, All Rights Reserved
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of version 2 of the GNU General Public License as published by
// the Free Software Foundation
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License along
// with this program; if not, write to the Free Software Foundation, Inc.,
// 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
//
#ifndef SMRTDATA_H
#define SMRTDATA_H

//////////////////////////////////////////////////////////////////////////////
// Headers.
//////////////////////////////////////////////////////////////////////////////
#include "bdebug.h"

//////////////////////////////////////////////////////////////////////////////
// Macros.
//////////////////////////////////////////////////////////////////////////////

#ifdef	_DEBUG
//////////////// DEBUG VERSION ///////////////////////////////////////////////
	// This sucks b/c it makes a explicitly an array of n as a constant.
	#define GETSMART(a, T, n)	CSmrtArry<T, n> a;
#else		// ndef _DEBUG
//////////////// RELEASE VERSION /////////////////////////////////////////////
	#define GETSMART(a, T, n)	T a[n];
#endif	// def _DEBUG

//////////////////////////////////////////////////////////////////////////////
// Typedefs.
//////////////////////////////////////////////////////////////////////////////

template <class T, long lSize> class CSmrtArry
	{
	public:	// Construction/Destruction.

//////////////////////////////////////////////////////////////////////////////

	public:	// Methods.
		// Subscript.
		T& operator [](long lIndex)
			{
			ASSERT(lIndex >= 0 && lIndex < lSize);
			return m_t[lIndex];
			}

		// Add with index as second operand.
		T* operator+(long lIndex)
			{
			ASSERT(lIndex >= 0 && lIndex < lSize);
			return m_t + lIndex;
			}

		// Pointer dereference.
		T& operator*(void)
			{
			ASSERT(lSize > 0);
			return *m_t;
			}

		// Cast.
		operator T*(void)
			{	
			return m_t; 
			}

//////////////////////////////////////////////////////////////////////////////

	public:	// Querries.

//////////////////////////////////////////////////////////////////////////////

	protected:	// Internal typedefs.

//////////////////////////////////////////////////////////////////////////////

	protected:	// Internal functions.


//////////////////////////////////////////////////////////////////////////////

	public:	// Member variables.

	protected:	// Member variables.
		T		m_t[lSize];		// This is the actual data.

	};

#endif // SMRTDATA_H
//////////////////////////////////////////////////////////////////////////////
//	EOF
//////////////////////////////////////////////////////////////////////////////

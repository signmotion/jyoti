#pragma once

#include <array>
#include <map>
#include <memory>
#include <vector>
#include <string>


// @see The project "denotat". https://bitbucket.org/signmotion/denotat

// @source Названия > http://vohuman.ru/sanskrit.html?start=5




// Элемент для сборки Джйоти.
// Позволяет создавать составные "понятия".
// @see class Jyoti
template< typename Enum, typename T >
struct ESet {
	typedef std::set< T >  set_t;
	typedef std::map< Enum, set_t >  data_t;

	inline data_t const& get() const { return mData; }

	void add( Enum, const T& );
	inline void operator()( Enum e, const T& v ) { add( e, v ); }

private:
	data_t  mData;
};


template< typename Enum >
struct EnumESet : public ESet< Enum, Enum > {
};


template< typename Enum >
struct StringESet : public ESet< Enum, std::wstring > {
};





template< typename Enum >
class E {
public:
	E();

	virtual ~E();


	EnumESet<   Enum >&  getEnum(   const std::wstring& name );

	typename EnumESet< Enum >::set_t const&
    getEnum( Enum,  const std::wstring& name ) const;


	StringESet< Enum >&  getString( const std::wstring& name );

	typename StringESet< Enum >::set_t const&
    getString( Enum,  const std::wstring& name ) const;


private:
	std::map< std::wstring,  EnumESet<   Enum > >  mEnumESet;
	std::map< std::wstring,  StringESet< Enum > >  mStringESet;
};



/*
// Граха [планета].
class Graha :
	public E
{
public:
	inline Graha( const std::wstring& name ) : E( name ) {}
};




// Раши [созвездие, зодиак].
class Rashi :
	public E
{
public:
	inline Rashi( const std::wstring& name ) : E( name ) {}
};
*/




template< class Graha >
class Jyoti {
public:
	const Graha  graha;


public:
	Jyoti();


	inline virtual ~Jyoti() {}


private:
};




#include "Jyoti.inl"

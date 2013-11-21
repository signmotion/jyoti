template< typename Enum, typename T >
void
ESet< Enum, T >::add( Enum e, const T& v ) {

	auto ftr = mData.find( e );
	if (ftr == mData.end()) {
		ftr = mData.insert( std::make_pair( e, set_t() ) ).first;
	}
	ftr->second.insert( v );
}




template< typename Enum >
inline
E< Enum >::E() {
}




template< typename Enum >
inline
E< Enum >::~E() {
}




template< typename Enum >
EnumESet< Enum >&
E< Enum >::getEnum( const std::wstring& name ) {

	auto ftr = mEnumESet.find( name );
	if (ftr == mEnumESet.end()) {
		ftr = mEnumESet.insert( std::make_pair(
			name,
			EnumESet< Enum >()
	    ) ).first;
	}
	
	return ftr->second;
}




template< typename Enum >
typename EnumESet< Enum >::set_t const&
E< Enum >::getEnum( Enum e,  const std::wstring& name ) const {
	
	const auto ftrName = mEnumESet.find( name );
	static const EnumESet< Enum >::set_t  EMPTY;
	if (ftrName == mEnumESet.end()) { return EMPTY; }
	
	const auto ftrE = ftrName->second.get().find( e );
	return (ftrE == ftrName->second.get().end()) ? EMPTY : ftrE->second;
}




template< typename Enum >
StringESet< Enum >&
E< Enum >::getString( const std::wstring& name ) {

	auto ftr = mStringESet.find( name );
	if (ftr == mStringESet.end()) {
		ftr = mStringESet.insert( std::make_pair(
			name,
			StringESet< Enum >()
	    ) ).first;
	}
	
	return ftr->second;
}




template< typename Enum >
typename StringESet< Enum >::set_t const&
E< Enum >::getString( Enum e,  const std::wstring& name ) const {
	
	const auto ftrName = mStringESet.find( name );
	static const StringESet< Enum >::set_t  EMPTY;
	if (ftrName == mStringESet.end()) { return EMPTY; }
	
	const auto ftrE = ftrName->second.get().find( e );
	return (ftrE == ftrName->second.get().end()) ? EMPTY : ftrE->second;
}








template< class Graha >
inline
Jyoti< Graha >::Jyoti() :
    graha( Graha() )
{
}

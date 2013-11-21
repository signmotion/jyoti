#pragma once

#include <gtest/gtest.h>
#include <Jyoti.h>


namespace {



class JyotiTest : public ::testing::Test {
  protected:
    inline JyotiTest() {
    }


    virtual inline ~JyotiTest() {
    }


    virtual inline void SetUp() {
    }


    virtual void TearDown() {
    }
};




TEST_F( JyotiTest, Create ) {

	using namespace ::testing;
	using namespace jyoti;


	// понятия
	enum Concept {
		UNDEFINED = 0,

		// week day
		Monday = 1000,
		Tusday,
		Wednesday,
		Thursday,
		Friday,
		Saturday,
		Sunday,

		// color
		Gold = 1100,
		White,
		Red,
		Green,
		Orange,
		Rainbow,
		Blue,

		// грахи [планеты]
		// @see http://1-veda.info/_bphs/chapter_03.html
		Sy = 10000, Ch, Ma, Bu, Gu, Sk, Sa,

		// раши [созвездия, зодиаки]
		Aries = 10100,
		Leo,
		Saggitarius,
		Taurus,
		Virgo,
		Capricorn,
		Gemini,
		Libra,
		Aquarius,
		Cancer,
		Scorpio,
		Pisces,

		last,
		count = last - 1  // # including 'last' and 'UNDEFINED'
	};


	// составные понятия
	// Описываются через простые.

#if 0
	struct MyWeekDay {
		enum Code {
			UNDEFINED = 0,
			Monday,
			Tusday,
			Wednesday,
			Thursday,
			Friday,
			Saturday,
			Sunday,
			last,
			count = last - 1  // # including 'last' and 'UNDEFINED'
		};
	};


	struct MyColor {
		enum Code {
			UNDEFINED = 0,
			Gold,
			White,
			Red,
			Green,
			Orange,
			Rainbow,
			Blue,
			last,
			count = last - 1  // # including 'last' and 'UNDEFINED'
		};
	};
#endif


	// грахи [планеты]
#if 0
	class MyGraha {
	public:
		enum Code {
			UNDEFINED = 0,
			// @see http://1-veda.info/_bphs/chapter_03.html
			Sy, Ch, Ma, Bu, Gu, Sk, Sa,
			last,
			count = last - 1  // # including 'last' and 'UNDEFINED'
		};

	public:
		inline MyGraha() {
			mNameSet[ Sy ] = L"Sy";
			mNameSet[ Ch ] = L"Ch";
			mNameSet[ Ma ] = L"Ma";
			mNameSet[ Bu ] = L"Bu";
			mNameSet[ Gu ] = L"Gu";
			mNameSet[ Sk ] = L"Sk";
			mNameSet[ Sa ] = L"Sa";

			mWeekDaySet[ Sy ] = MyWeekDay::Code::Sunday;
			mWeekDaySet[ Ch ] = MyWeekDay::Code::Monday;
			mWeekDaySet[ Ma ] = MyWeekDay::Code::Tusday;
			mWeekDaySet[ Bu ] = MyWeekDay::Code::Wednesday;
			mWeekDaySet[ Gu ] = MyWeekDay::Code::Thursday;
			mWeekDaySet[ Sk ] = MyWeekDay::Code::Friday;
			mWeekDaySet[ Sa ] = MyWeekDay::Code::Saturday;

			mColorSet[ Sy ] = MyColor::Code::Gold;
			mColorSet[ Ch ] = MyColor::Code::White;
			mColorSet[ Ma ] = MyColor::Code::Red;
			mColorSet[ Bu ] = MyColor::Code::Green;
			mColorSet[ Gu ] = MyColor::Code::Orange;
			mColorSet[ Sk ] = MyColor::Code::Rainbow;
			mColorSet[ Sa ] = MyColor::Code::Blue;
		}

	private:
		// # First cell of set is reserved for simplest using.
		typedef std::array< std::wstring, Code::count + 1 >  nameSet_t;
		nameSet_t  mNameSet;

		typedef std::array< MyWeekDay::Code, Code::count + 1 >  weekDaySet_t;
		weekDaySet_t  mWeekDaySet;

		typedef std::array< MyColor::Code, Code::count + 1 >  colorSet_t;
		colorSet_t  mColorSet;
	};
#endif


#if 0
	class MyGraha : public E< MyGraha > {
	public:
		enum Code {
			UNDEFINED = 0,
			// @see http://1-veda.info/_bphs/chapter_03.html
			Sy, Ch, Ma, Bu, Gu, Sk, Sa,
			last,
			count = last - 1  // # including 'last' and 'UNDEFINED'
		};

	public:
		inline MyGraha() {
			{
				auto set = get< std::wstring >( L"name" );
				set->add( Sy, L"Sy" );
				//set->add( Ch, L"Ch" );
			}

			{
				auto set = get< MyWeekDay::Code >( L"weekDay" );
				set->add( Sy, MyWeekDay::Code::Sunday );
				// ...
			}

			{
				auto set = get< MyColor::Code >( L"color" );
				set->add( Sy, MyColor::Code::Gold );
				// ...
			}
		}
	};
#endif


	

#if 1
	class MyGraha : public E< Concept > {
	public:
		inline MyGraha() {
			{
				auto& s = getString( L"name" );
				s( Sy, L"Sy" );
				s( Sy, L"Сурйя" );
				s( Sy, L"Солнце" );
				s( Ch, L"Ch" );
				s( Ch, L"Чандра" );
				s( Ch, L"Луна" );
				s( Ma, L"Ma" );
				s( Ma, L"Мангала" );
				s( Ma, L"Марс" );
				s( Bu, L"Bu" );
				s( Bu, L"Буддха" );
				s( Bu, L"Меркурий" );
				s( Gu, L"Gu" );
				s( Gu, L"Гуру" );
				s( Gu, L"Юпитер" );
				s( Sk, L"Sk" );
				s( Sk, L"Шукра" );
				s( Sk, L"Венера" );
				s( Sa, L"Sa" );
				s( Sa, L"Шани" );
				s( Sa, L"Сатурн" );
			}
			{
				auto& s = getEnum( L"weekDay" );
				s( Sy, Sunday );
				s( Ch, Monday );
				s( Ma, Tusday );
				s( Bu, Wednesday );
				s( Gu, Thursday );
				s( Sk, Friday );
				s( Sa, Saturday );
			}
			{
				auto& s = getEnum( L"color" );
				s( Sy, Gold );
				s( Ch, White );
				s( Ma, Red );
				s( Bu, Green );
				s( Gu, Orange );
				s( Sk, Rainbow );
				s( Sa, Blue );
			}
		}
	};
#endif

	const MyGraha  graha;
	{
		const auto  nameSet = graha.getString( Sy, L"name" );
		EXPECT_EQ( 3, nameSet.size() );
	}
	{
		const auto  nameSet = graha.getString( Sa, L"name" );
		EXPECT_EQ( 3, nameSet.size() );
	}
	{
		const auto  colorSet = graha.getEnum( Ch, L"color" );
		ASSERT_EQ( 1, colorSet.size() );
		const auto  e = *colorSet.cbegin();
		EXPECT_EQ( White, e );
	}


	// раши [созвездия, зодиаки]


	// бхавы [дома]





	typedef Jyoti< MyGraha >  jyoti_t;
	jyoti_t  jyoti;


	//EXPECT_EQ( ...

}



} // namespace

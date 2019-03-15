#pragma once

#include "skse64_common/Relocation.h"  // RelocAddr

#include "RE/Offsets.h"


namespace RE
{
	template <class Ty>
	class CRC32Calculator
	{
	public:
		inline CRC32Calculator()
		{}


		inline CRC32Calculator(const Ty& a_val)
		{
			operator=(a_val);
		}


		inline operator UInt32()
		{
			return _checksum;
		}

	protected:
		template <std::size_t SIZE = sizeof(Ty)>
		inline CRC32Calculator& operator=(const Ty& a_val)
		{
			typedef void(*Fn)(UInt32*, const void*, UInt32);
			RelocAddr<Fn> fn(Offset::CRC32Calculator::SizeOfSize);

			fn(&_checksum, &a_val, SIZE);
			return *this;
		}


		template <>
		inline CRC32Calculator& operator=<4>(const Ty& a_val)
		{
			typedef void(*Fn)(UInt32*, Ty);
			RelocAddr<Fn> fn(Offset::CRC32Calculator::SizeOf32);

			fn(&_checksum, a_val);
			return *this;
		}


		template <>
		inline CRC32Calculator& operator=<8>(const Ty& a_val)
		{
			typedef void(*Fn)(UInt32*, Ty);
			RelocAddr<Fn> fn(Offset::CRC32Calculator::SizeOf64);

			fn(&_checksum, a_val);
			return *this;
		}


		UInt32	_checksum;
	};


	// String hash calculator got inlined
	class CRC32StringCalculator
	{
	public:
		inline CRC32StringCalculator()
		{}


		inline CRC32StringCalculator(const void* a_str)
		{
			operator=(a_str);
		}


		inline operator UInt32()
		{
			return _checksum;
		}

	protected:
		inline CRC32StringCalculator& operator=(const void* a_str)
		{
			CRC32Calculator<std::uint64_t> checksum((std::uint64_t)a_str);
			_checksum = checksum;
			return *this;
		}

		UInt32	_checksum;
	};


	template <class Ty>
	inline UInt32 CalcCRC32(const Ty& a_val)
	{
		CRC32Calculator<Ty> crc(a_val);
		return crc;
	}


	template <class Ty>
	inline UInt32 CalcCRC32String(const Ty& a_val)
	{
		CRC32StringCalculator crc(a_val);
		return crc;
	}
}

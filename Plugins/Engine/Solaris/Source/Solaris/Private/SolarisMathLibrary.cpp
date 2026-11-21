// Copyright Epic Games, Inc. All Rights Reserved.

#include "SolarisMathLibrary.h"

#ifndef FORTSTUB_SKIP_THUNK_PARAMS
#define FORTSTUB_SKIP_THUNK_PARAMS
static void FortStub_SkipThunkParams(FFrame& Stack, UFunction* Function)
{
	if (Function)
	{
		for (TFieldIterator<FProperty> It(Function); It && It->HasAnyPropertyFlags(CPF_Parm); ++It)
		{
			if (It->HasAnyPropertyFlags(CPF_ReturnParm))
			{
				continue;
			}
			void* Temp = FMemory::Malloc(It->GetSize(), It->GetMinAlignment());
			It->InitializeValue(Temp);
			Stack.StepCompiledIn(Temp, It->GetClass());
			It->DestroyValue(Temp);
			FMemory::Free(Temp);
		}
	}
	P_FINISH;
}
#endif

DEFINE_FUNCTION(USolarisMathLibrary_Bool::execQuery)
{
	FortStub_SkipThunkParams(Stack, USolarisMathLibrary_Bool::StaticClass()->FindFunctionByName(TEXT("Query")));
}
void USolarisMathLibrary_Bool::Query()
{
}

double USolarisMathLibrary_Float::Abs(double Value)
{
	return double();
}

double USolarisMathLibrary_Float::Add(double LHS, double RHS)
{
	return double();
}

double USolarisMathLibrary_Float::AddEquals(double& LHS, double RHS)
{
	return double();
}

DEFINE_FUNCTION(USolarisMathLibrary_Float::execCheckConstrainedFloat)
{
	FortStub_SkipThunkParams(Stack, USolarisMathLibrary_Float::StaticClass()->FindFunctionByName(TEXT("CheckConstrainedFloat")));
}
void USolarisMathLibrary_Float::CheckConstrainedFloat(double Min, double Max, double Value)
{
}

double USolarisMathLibrary_Float::Divide(double LHS, double RHS)
{
	return double();
}

double USolarisMathLibrary_Float::DivideEquals(double& LHS, double RHS)
{
	return double();
}

DEFINE_FUNCTION(USolarisMathLibrary_Float::execGreater)
{
	FortStub_SkipThunkParams(Stack, USolarisMathLibrary_Float::StaticClass()->FindFunctionByName(TEXT("Greater")));
}
void USolarisMathLibrary_Float::Greater(double LHS, double RHS)
{
}

DEFINE_FUNCTION(USolarisMathLibrary_Float::execGreaterEqual)
{
	FortStub_SkipThunkParams(Stack, USolarisMathLibrary_Float::StaticClass()->FindFunctionByName(TEXT("GreaterEqual")));
}
void USolarisMathLibrary_Float::GreaterEqual(double LHS, double RHS)
{
}

DEFINE_FUNCTION(USolarisMathLibrary_Float::execLess)
{
	FortStub_SkipThunkParams(Stack, USolarisMathLibrary_Float::StaticClass()->FindFunctionByName(TEXT("Less")));
}
void USolarisMathLibrary_Float::Less(double LHS, double RHS)
{
}

DEFINE_FUNCTION(USolarisMathLibrary_Float::execLessEqual)
{
	FortStub_SkipThunkParams(Stack, USolarisMathLibrary_Float::StaticClass()->FindFunctionByName(TEXT("LessEqual")));
}
void USolarisMathLibrary_Float::LessEqual(double LHS, double RHS)
{
}

double USolarisMathLibrary_Float::Multiply(double LHS, double RHS)
{
	return double();
}

double USolarisMathLibrary_Float::MultiplyEquals(double& LHS, double RHS)
{
	return double();
}

double USolarisMathLibrary_Float::MultiplyFloatInt(double LHS, int64 RHS)
{
	return double();
}

double USolarisMathLibrary_Float::MultiplyIntFloat(int64 LHS, double RHS)
{
	return double();
}

double USolarisMathLibrary_Float::Negate(double Value)
{
	return double();
}

double USolarisMathLibrary_Float::Subtract(double LHS, double RHS)
{
	return double();
}

double USolarisMathLibrary_Float::SubtractEquals(double& LHS, double RHS)
{
	return double();
}

DEFINE_FUNCTION(USolarisMathLibrary_Int::execAbs)
{
	FortStub_SkipThunkParams(Stack, USolarisMathLibrary_Int::StaticClass()->FindFunctionByName(TEXT("Abs")));
}
void USolarisMathLibrary_Int::Abs(int64 Value)
{
}

DEFINE_FUNCTION(USolarisMathLibrary_Int::execAdd)
{
	FortStub_SkipThunkParams(Stack, USolarisMathLibrary_Int::StaticClass()->FindFunctionByName(TEXT("Add")));
}
void USolarisMathLibrary_Int::Add(int64 LHS, int64 RHS)
{
}

DEFINE_FUNCTION(USolarisMathLibrary_Int::execAddEquals)
{
	FortStub_SkipThunkParams(Stack, USolarisMathLibrary_Int::StaticClass()->FindFunctionByName(TEXT("AddEquals")));
}
void USolarisMathLibrary_Int::AddEquals(int64& LHS, int64 RHS)
{
}

DEFINE_FUNCTION(USolarisMathLibrary_Int::execCheckConstrainedInt)
{
	FortStub_SkipThunkParams(Stack, USolarisMathLibrary_Int::StaticClass()->FindFunctionByName(TEXT("CheckConstrainedInt")));
}
void USolarisMathLibrary_Int::CheckConstrainedInt(int64 Min, int64 Max, int64 Value)
{
}

DEFINE_FUNCTION(USolarisMathLibrary_Int::execDivide)
{
	FortStub_SkipThunkParams(Stack, USolarisMathLibrary_Int::StaticClass()->FindFunctionByName(TEXT("Divide")));
}
void USolarisMathLibrary_Int::Divide(int64 LHS, int64 RHS)
{
}

DEFINE_FUNCTION(USolarisMathLibrary_Int::execGreater)
{
	FortStub_SkipThunkParams(Stack, USolarisMathLibrary_Int::StaticClass()->FindFunctionByName(TEXT("Greater")));
}
void USolarisMathLibrary_Int::Greater(int64 LHS, int64 RHS)
{
}

DEFINE_FUNCTION(USolarisMathLibrary_Int::execGreaterEqual)
{
	FortStub_SkipThunkParams(Stack, USolarisMathLibrary_Int::StaticClass()->FindFunctionByName(TEXT("GreaterEqual")));
}
void USolarisMathLibrary_Int::GreaterEqual(int64 LHS, int64 RHS)
{
}

DEFINE_FUNCTION(USolarisMathLibrary_Int::execLess)
{
	FortStub_SkipThunkParams(Stack, USolarisMathLibrary_Int::StaticClass()->FindFunctionByName(TEXT("Less")));
}
void USolarisMathLibrary_Int::Less(int64 LHS, int64 RHS)
{
}

DEFINE_FUNCTION(USolarisMathLibrary_Int::execLessEqual)
{
	FortStub_SkipThunkParams(Stack, USolarisMathLibrary_Int::StaticClass()->FindFunctionByName(TEXT("LessEqual")));
}
void USolarisMathLibrary_Int::LessEqual(int64 LHS, int64 RHS)
{
}

DEFINE_FUNCTION(USolarisMathLibrary_Int::execMultiply)
{
	FortStub_SkipThunkParams(Stack, USolarisMathLibrary_Int::StaticClass()->FindFunctionByName(TEXT("Multiply")));
}
void USolarisMathLibrary_Int::Multiply(int64 LHS, int64 RHS)
{
}

DEFINE_FUNCTION(USolarisMathLibrary_Int::execMultiplyEquals)
{
	FortStub_SkipThunkParams(Stack, USolarisMathLibrary_Int::StaticClass()->FindFunctionByName(TEXT("MultiplyEquals")));
}
void USolarisMathLibrary_Int::MultiplyEquals(int64& LHS, int64 RHS)
{
}

DEFINE_FUNCTION(USolarisMathLibrary_Int::execNegate)
{
	FortStub_SkipThunkParams(Stack, USolarisMathLibrary_Int::StaticClass()->FindFunctionByName(TEXT("Negate")));
}
void USolarisMathLibrary_Int::Negate(int64 Value)
{
}

bool USolarisMathLibrary_Int::PredicateEqual(int64 LHS, int64 RHS)
{
	return false;
}

bool USolarisMathLibrary_Int::PredicateGreater(int64 LHS, int64 RHS)
{
	return false;
}

bool USolarisMathLibrary_Int::PredicateGreaterEqual(int64 LHS, int64 RHS)
{
	return false;
}

bool USolarisMathLibrary_Int::PredicateLess(int64 LHS, int64 RHS)
{
	return false;
}

bool USolarisMathLibrary_Int::PredicateLessEqual(int64 LHS, int64 RHS)
{
	return false;
}

bool USolarisMathLibrary_Int::PredicateNotEqual(int64 LHS, int64 RHS)
{
	return false;
}

DEFINE_FUNCTION(USolarisMathLibrary_Int::execSubtract)
{
	FortStub_SkipThunkParams(Stack, USolarisMathLibrary_Int::StaticClass()->FindFunctionByName(TEXT("Subtract")));
}
void USolarisMathLibrary_Int::Subtract(int64 LHS, int64 RHS)
{
}

DEFINE_FUNCTION(USolarisMathLibrary_Int::execSubtractEquals)
{
	FortStub_SkipThunkParams(Stack, USolarisMathLibrary_Int::StaticClass()->FindFunctionByName(TEXT("SubtractEquals")));
}
void USolarisMathLibrary_Int::SubtractEquals(int64& LHS, int64 RHS)
{
}

int32 USolarisMathLibrary_Int::UncheckedConvertI32I64(int64 RHS)
{
	return int32();
}

DEFINE_FUNCTION(USolarisMathLibrary_Option::execMake)
{
	FortStub_SkipThunkParams(Stack, USolarisMathLibrary_Option::StaticClass()->FindFunctionByName(TEXT("Make")));
}
void USolarisMathLibrary_Option::Make()
{
}

DEFINE_FUNCTION(USolarisMathLibrary_Option::execQuery)
{
	FortStub_SkipThunkParams(Stack, USolarisMathLibrary_Option::StaticClass()->FindFunctionByName(TEXT("Query")));
}
void USolarisMathLibrary_Option::Query()
{
}

DEFINE_FUNCTION(USolarisMathLibrary_Rational::execCeil)
{
	FortStub_SkipThunkParams(Stack, USolarisMathLibrary_Rational::StaticClass()->FindFunctionByName(TEXT("Ceil")));
}
void USolarisMathLibrary_Rational::Ceil(FVerseRational Val)
{
}

DEFINE_FUNCTION(USolarisMathLibrary_Rational::execFloor)
{
	FortStub_SkipThunkParams(Stack, USolarisMathLibrary_Rational::StaticClass()->FindFunctionByName(TEXT("Floor")));
}
void USolarisMathLibrary_Rational::Floor(FVerseRational Val)
{
}

DEFINE_FUNCTION(USolarisMathLibrary_String::execAdd)
{
	FortStub_SkipThunkParams(Stack, USolarisMathLibrary_String::StaticClass()->FindFunctionByName(TEXT("Add")));
}
void USolarisMathLibrary_String::Add(const int32& String, int8 Character)
{
}

DEFINE_FUNCTION(USolarisMathLibrary_String::execCall)
{
	FortStub_SkipThunkParams(Stack, USolarisMathLibrary_String::StaticClass()->FindFunctionByName(TEXT("Call")));
}
void USolarisMathLibrary_String::Call(const int32& String, int64 Index)
{
}

DEFINE_FUNCTION(USolarisMathLibrary_String::execConcat)
{
	FortStub_SkipThunkParams(Stack, USolarisMathLibrary_String::StaticClass()->FindFunctionByName(TEXT("Concat")));
}
int32 USolarisMathLibrary_String::Concat(const int32& Lhs, const int32& Rhs)
{
	return int32();
}

DEFINE_FUNCTION(USolarisMathLibrary_String::execConcatEquals)
{
	FortStub_SkipThunkParams(Stack, USolarisMathLibrary_String::StaticClass()->FindFunctionByName(TEXT("ConcatEquals")));
}
int32 USolarisMathLibrary_String::ConcatEquals(int32& Lhs, const int32& Rhs)
{
	return int32();
}

DEFINE_FUNCTION(USolarisMathLibrary_String::execLength)
{
	FortStub_SkipThunkParams(Stack, USolarisMathLibrary_String::StaticClass()->FindFunctionByName(TEXT("Length")));
}
int64 USolarisMathLibrary_String::Length(const int32& array)
{
	return int64();
}

DEFINE_FUNCTION(USolarisMathLibrary_String::execMake)
{
	FortStub_SkipThunkParams(Stack, USolarisMathLibrary_String::StaticClass()->FindFunctionByName(TEXT("Make")));
}
void USolarisMathLibrary_String::Make()
{
}

DEFINE_FUNCTION(USolarisMathLibrary_String::execMakeLiteral)
{
	FortStub_SkipThunkParams(Stack, USolarisMathLibrary_String::StaticClass()->FindFunctionByName(TEXT("MakeLiteral")));
}
int32 USolarisMathLibrary_String::MakeLiteral()
{
	return int32();
}

DEFINE_FUNCTION(USolarisMathLibrary_String::execMove)
{
	FortStub_SkipThunkParams(Stack, USolarisMathLibrary_String::StaticClass()->FindFunctionByName(TEXT("Move")));
}
void USolarisMathLibrary_String::Move(const int32& Destination, const int32& Source)
{
}

DEFINE_FUNCTION(USolarisMathLibrary_String::execRefCall)
{
	FortStub_SkipThunkParams(Stack, USolarisMathLibrary_String::StaticClass()->FindFunctionByName(TEXT("RefCall")));
}
void USolarisMathLibrary_String::RefCall(const int32& String, int64 Index)
{
}

DEFINE_FUNCTION(USolarisMathLibrary_String::execUncheckedCall)
{
	FortStub_SkipThunkParams(Stack, USolarisMathLibrary_String::StaticClass()->FindFunctionByName(TEXT("UncheckedCall")));
}
void USolarisMathLibrary_String::UncheckedCall(const int32& String, int64 Index)
{
}

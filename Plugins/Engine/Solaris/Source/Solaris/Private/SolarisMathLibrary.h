// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "VerseRational.h"
#include "SolarisMathLibrary.generated.h"

UCLASS()
class USolarisMathLibrary_Bool : public UObject
{
	GENERATED_BODY()

public:
	/*T LHS, T RHS*/
	UFUNCTION(CustomThunk)
	static void Query();
	DECLARE_FUNCTION(execQuery);

};

UCLASS()
class USolarisMathLibrary_Float : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION()
	static double Abs(double Value);

	UFUNCTION()
	static double Add(double LHS, double RHS);

	UFUNCTION()
	static double AddEquals(double& LHS, double RHS);

	/*TOptional<double>*/
	UFUNCTION(CustomThunk)
	static void CheckConstrainedFloat(double Min, double Max, double Value);
	DECLARE_FUNCTION(execCheckConstrainedFloat);

	UFUNCTION()
	static double Divide(double LHS, double RHS);

	UFUNCTION()
	static double DivideEquals(double& LHS, double RHS);

	/*TOptional<double>*/
	UFUNCTION(CustomThunk)
	static void Greater(double LHS, double RHS);
	DECLARE_FUNCTION(execGreater);

	/*TOptional<double>*/
	UFUNCTION(CustomThunk)
	static void GreaterEqual(double LHS, double RHS);
	DECLARE_FUNCTION(execGreaterEqual);

	/*TOptional<double>*/
	UFUNCTION(CustomThunk)
	static void Less(double LHS, double RHS);
	DECLARE_FUNCTION(execLess);

	/*TOptional<double>*/
	UFUNCTION(CustomThunk)
	static void LessEqual(double LHS, double RHS);
	DECLARE_FUNCTION(execLessEqual);

	UFUNCTION()
	static double Multiply(double LHS, double RHS);

	UFUNCTION()
	static double MultiplyEquals(double& LHS, double RHS);

	UFUNCTION()
	static double MultiplyFloatInt(double LHS, int64 RHS);

	UFUNCTION()
	static double MultiplyIntFloat(int64 LHS, double RHS);

	UFUNCTION()
	static double Negate(double Value);

	UFUNCTION()
	static double Subtract(double LHS, double RHS);

	UFUNCTION()
	static double SubtractEquals(double& LHS, double RHS);

};

UCLASS()
class USolarisMathLibrary_Int : public UObject
{
	GENERATED_BODY()

public:
	/*int64*/
	UFUNCTION(CustomThunk)
	static void Abs(int64 Value);
	DECLARE_FUNCTION(execAbs);

	/*int64*/
	UFUNCTION(CustomThunk)
	static void Add(int64 LHS, int64 RHS);
	DECLARE_FUNCTION(execAdd);

	/*int64*/
	UFUNCTION(CustomThunk)
	static void AddEquals(int64& LHS, int64 RHS);
	DECLARE_FUNCTION(execAddEquals);

	/*TOptional<int64>*/
	UFUNCTION(CustomThunk)
	static void CheckConstrainedInt(int64 Min, int64 Max, int64 Value);
	DECLARE_FUNCTION(execCheckConstrainedInt);

	/*TOptional<FVerseRat>*/
	UFUNCTION(CustomThunk)
	static void Divide(int64 LHS, int64 RHS);
	DECLARE_FUNCTION(execDivide);

	/*TOptional<int64>*/
	UFUNCTION(CustomThunk)
	static void Greater(int64 LHS, int64 RHS);
	DECLARE_FUNCTION(execGreater);

	/*TOptional<int64>*/
	UFUNCTION(CustomThunk)
	static void GreaterEqual(int64 LHS, int64 RHS);
	DECLARE_FUNCTION(execGreaterEqual);

	/*TOptional<int64>*/
	UFUNCTION(CustomThunk)
	static void Less(int64 LHS, int64 RHS);
	DECLARE_FUNCTION(execLess);

	/*TOptional<int64>*/
	UFUNCTION(CustomThunk)
	static void LessEqual(int64 LHS, int64 RHS);
	DECLARE_FUNCTION(execLessEqual);

	/*int64*/
	UFUNCTION(CustomThunk)
	static void Multiply(int64 LHS, int64 RHS);
	DECLARE_FUNCTION(execMultiply);

	/*int64*/
	UFUNCTION(CustomThunk)
	static void MultiplyEquals(int64& LHS, int64 RHS);
	DECLARE_FUNCTION(execMultiplyEquals);

	/*int64*/
	UFUNCTION(CustomThunk)
	static void Negate(int64 Value);
	DECLARE_FUNCTION(execNegate);

	UFUNCTION()
	static bool PredicateEqual(int64 LHS, int64 RHS);

	UFUNCTION()
	static bool PredicateGreater(int64 LHS, int64 RHS);

	UFUNCTION()
	static bool PredicateGreaterEqual(int64 LHS, int64 RHS);

	UFUNCTION()
	static bool PredicateLess(int64 LHS, int64 RHS);

	UFUNCTION()
	static bool PredicateLessEqual(int64 LHS, int64 RHS);

	UFUNCTION()
	static bool PredicateNotEqual(int64 LHS, int64 RHS);

	/*int64*/
	UFUNCTION(CustomThunk)
	static void Subtract(int64 LHS, int64 RHS);
	DECLARE_FUNCTION(execSubtract);

	/*int64*/
	UFUNCTION(CustomThunk)
	static void SubtractEquals(int64& LHS, int64 RHS);
	DECLARE_FUNCTION(execSubtractEquals);

	UFUNCTION()
	static int32 UncheckedConvertI32I64(int64 RHS);

};

UCLASS()
class USolarisMathLibrary_Option : public UObject
{
	GENERATED_BODY()

public:
	/*UE::FDynamicallyTypedValue Value*/
	UFUNCTION(CustomThunk)
	static void Make();
	DECLARE_FUNCTION(execMake);

	/*T LHS, T RHS*/
	UFUNCTION(CustomThunk)
	static void Query();
	DECLARE_FUNCTION(execQuery);

};

UCLASS()
class USolarisMathLibrary_Rational : public UObject
{
	GENERATED_BODY()

public:
	/*int64*/
	UFUNCTION(CustomThunk)
	static void Ceil(FVerseRational Val);
	DECLARE_FUNCTION(execCeil);

	/*int64*/
	UFUNCTION(CustomThunk)
	static void Floor(FVerseRational Val);
	DECLARE_FUNCTION(execFloor);

};

UCLASS()
class USolarisMathLibrary_String : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(CustomThunk)
	static void Add(const int32& String, int8 Character);
	DECLARE_FUNCTION(execAdd);

	/*TOptional<FGenericElementType>*/
	UFUNCTION(CustomThunk)
	static void Call(const int32& String, int64 Index);
	DECLARE_FUNCTION(execCall);

	UFUNCTION(CustomThunk)
	static int32 Concat(const int32& Lhs, const int32& Rhs);
	DECLARE_FUNCTION(execConcat);

	UFUNCTION(CustomThunk)
	static int32 ConcatEquals(int32& Lhs, const int32& Rhs);
	DECLARE_FUNCTION(execConcatEquals);

	UFUNCTION(CustomThunk)
	static int64 Length(const int32& array);
	DECLARE_FUNCTION(execLength);

	UFUNCTION(CustomThunk)
	static void Make();
	DECLARE_FUNCTION(execMake);

	UFUNCTION(CustomThunk)
	static int32 MakeLiteral();
	DECLARE_FUNCTION(execMakeLiteral);

	UFUNCTION(CustomThunk)
	static void Move(const int32& Destination, const int32& Source);
	DECLARE_FUNCTION(execMove);

	/*FReferenceProperty*/
	UFUNCTION(CustomThunk)
	static void RefCall(const int32& String, int64 Index);
	DECLARE_FUNCTION(execRefCall);

	/*verse::char8*/
	UFUNCTION(CustomThunk)
	static void UncheckedCall(const int32& String, int64 Index);
	DECLARE_FUNCTION(execUncheckedCall);

};


// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SolarisArrayLibrary.generated.h"

// This type is used as a stand-in for unknown element types in the below CustomThunk signatures.
// The signatures of these generic CustomThunk functions aren't used in the compiled code, and are
// only written here for the benefit of the reader.

USTRUCT()
struct FGenericElementType
{
	GENERATED_BODY()

};

UCLASS()
class USolarisArrayLibrary : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(CustomThunk)
	static int64 Add(const TArray<FGenericElementType>& array, const FGenericElementType& new_item);
	DECLARE_FUNCTION(execAdd);

	/*TOptional<FGenericElementType>*/
	UFUNCTION(CustomThunk)
	static void Call(const TArray<FGenericElementType>& Array, int64 Index);
	DECLARE_FUNCTION(execCall);

	UFUNCTION(CustomThunk)
	static TArray<FGenericElementType> Concat(const TArray<FGenericElementType>& Lhs, const TArray<FGenericElementType>& Rhs);
	DECLARE_FUNCTION(execConcat);

	UFUNCTION(CustomThunk)
	static TArray<FGenericElementType> ConcatEquals(TArray<FGenericElementType>& Lhs, const TArray<FGenericElementType>& Rhs);
	DECLARE_FUNCTION(execConcatEquals);

	UFUNCTION(CustomThunk)
	static void Empty(const TArray<FGenericElementType>& array);
	DECLARE_FUNCTION(execEmpty);

	UFUNCTION(CustomThunk)
	static int64 Length(const TArray<FGenericElementType>& array);
	DECLARE_FUNCTION(execLength);

	UFUNCTION(CustomThunk)
	static void Move(const TArray<FGenericElementType>& Target, const TArray<FGenericElementType>& Source);
	DECLARE_FUNCTION(execMove);

	/*FReferenceProperty*/
	UFUNCTION(CustomThunk)
	static void RefCall(const TArray<FGenericElementType>& Array, int64 Index);
	DECLARE_FUNCTION(execRefCall);

	/*FGenericElementType*/
	UFUNCTION(CustomThunk)
	static void UnsafeCall(const TArray<FGenericElementType>& Array, int64 Index);
	DECLARE_FUNCTION(execUnsafeCall);

};


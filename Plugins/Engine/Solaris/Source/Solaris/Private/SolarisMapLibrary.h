// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SolarisWeakMapLibrary.h"
#include "SolarisMapLibrary.generated.h"

UCLASS()
class USolarisMapLibrary : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(CustomThunk)
	static void Add(const TMap<FGenericKeyType, FGenericValueType>& Map, const FGenericKeyType& Key, const FGenericValueType& Value);
	DECLARE_FUNCTION(execAdd);

	UFUNCTION(CustomThunk)
	static TMap<FGenericKeyType, FGenericValueType> Concat(const TMap<FGenericKeyType, FGenericValueType>& LHS, const TMap<FGenericKeyType, FGenericValueType>& RHS);
	DECLARE_FUNCTION(execConcat);

	UFUNCTION(CustomThunk)
	static FGenericKeyType GetKeyByIndex(const TMap<FGenericKeyType, FGenericValueType>& Map, int64 Index);
	DECLARE_FUNCTION(execGetKeyByIndex);

	UFUNCTION(CustomThunk)
	static int64 GetNextValidIndex(const TMap<FGenericKeyType, FGenericValueType>& Map, int64 InitialIndex);
	DECLARE_FUNCTION(execGetNextValidIndex);

	UFUNCTION(CustomThunk)
	static FGenericValueType GetValueByIndex(const TMap<FGenericKeyType, FGenericValueType>& Map, int64 Index);
	DECLARE_FUNCTION(execGetValueByIndex);

	UFUNCTION(CustomThunk)
	static void InitMap(TMap<FGenericKeyType, FGenericValueType>& Map);
	DECLARE_FUNCTION(execInitMap);

	UFUNCTION(CustomThunk)
	static int64 Length(const TMap<FGenericKeyType, FGenericValueType>& Map);
	DECLARE_FUNCTION(execLength);

	UFUNCTION(CustomThunk)
	static void Move(TMap<FGenericKeyType, FGenericValueType>& Dest, const TMap<FGenericKeyType, FGenericValueType>& Src);
	DECLARE_FUNCTION(execMove);

};


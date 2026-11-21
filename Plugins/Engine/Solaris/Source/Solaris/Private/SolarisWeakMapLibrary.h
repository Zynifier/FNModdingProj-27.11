// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SolarisWeakMapLibrary.generated.h"

class UObject;

// These types are used as stand-ins for unknown key and value types in the below CustomThunk
// signatures. The signatures of these generic CustomThunk functions aren't used in the compiled
// code, and are only written here for the benefit of the reader.

USTRUCT()
struct FGenericKeyType
{
	GENERATED_BODY()


	SOLARIS_API bool operator==(const FGenericKeyType& Other) const;
	friend SOLARIS_API uint32 GetTypeHash(const FGenericKeyType& Value);
};

USTRUCT()
struct FGenericValueType
{
	GENERATED_BODY()

};

UCLASS()
class USolarisWeakMapLibrary : public UObject
{
	GENERATED_BODY()

public:
	/*TOptional<FGenericValueType>*/
	UFUNCTION(CustomThunk)
	static void Call(const TMap<FGenericKeyType, FGenericValueType>& Map, FGenericKeyType Key);
	DECLARE_FUNCTION(execCall);

	/*FReferenceProperty*/
	UFUNCTION(CustomThunk)
	static void CompletelyAssignedPersistentVarRefCall(const FString& Path, const TMap<FGenericKeyType, FGenericValueType>& Map, FGenericKeyType Key);
	DECLARE_FUNCTION(execCompletelyAssignedPersistentVarRefCall);

	/*FReferenceProperty*/
	UFUNCTION(CustomThunk)
	static void CompletelyAssignedRefCall(const TMap<FGenericKeyType, FGenericValueType>& Map, FGenericKeyType Key);
	DECLARE_FUNCTION(execCompletelyAssignedRefCall);

	/*FGenericValueType*/
	UFUNCTION(CustomThunk)
	static void FitsInPlayerMap(FGenericValueType Value);
	DECLARE_FUNCTION(execFitsInPlayerMap);

	/*TOptional<FGenericValueType>*/
	UFUNCTION(CustomThunk)
	static void PersistentVarCall(const TMap<FGenericKeyType, FGenericValueType>& Map, FGenericKeyType Key);
	DECLARE_FUNCTION(execPersistentVarCall);

	/*FReferenceProperty*/
	UFUNCTION(CustomThunk)
	static void PersistentVarRefCall(const FString& Path, const TMap<FGenericKeyType, FGenericValueType>& Map, FGenericKeyType Key);
	DECLARE_FUNCTION(execPersistentVarRefCall);

	/*FReferenceProperty*/
	UFUNCTION(CustomThunk)
	static void RefCall(const TMap<FGenericKeyType, FGenericValueType>& Map, FGenericKeyType Key);
	DECLARE_FUNCTION(execRefCall);

	UFUNCTION(CustomThunk)
	static void Type(UClass* KeyType, UClass* ValueType);
	DECLARE_FUNCTION(execType);

};


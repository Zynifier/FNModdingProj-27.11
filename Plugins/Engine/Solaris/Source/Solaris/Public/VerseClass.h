// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "VerseClassBase.h"
#include "VerseClass.generated.h"

class UClassCookedMetaData;
class UObject;

USTRUCT()
struct SOLARIS_API FVersePersistentVar
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString Path;

	UPROPERTY()
	TFieldPath<FProperty> Property;

};

USTRUCT()
struct SOLARIS_API FVerseSessionVar
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TFieldPath<FProperty> Property;

};

UCLASS()
class SOLARIS_API UVerseClass : public UVerseClassBase
{
	GENERATED_BODY()

public:
	UPROPERTY()
	uint32 SolClassFlags;

	// All coroutine task classes belonging to this class (one for each coroutine in this class)

	UPROPERTY()
	TArray<TSubclassOf<UObject>> TaskClasses;

	UPROPERTY()
	TSet<TSubclassOf<UObject>> InterfaceClasses;

	UPROPERTY()
	TMap<FName, TFieldPath<FProperty>> InterfaceMethodFunctionProperties;

	/** Initialization function */
	UPROPERTY()
	TObjectPtr<UObject> InitInstanceFunction;

	UPROPERTY()
	TArray<FVersePersistentVar> PersistentVars;

	UPROPERTY()
	TArray<FVerseSessionVar> SessionVars;

private:
#if WITH_EDITORONLY_DATA
	UPROPERTY()
	TObjectPtr<UClassCookedMetaData> CachedCookedMetaDataPtr;
#endif

};


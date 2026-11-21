// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Misc/Guid.h"
#include "GameplayEventBindingCache.generated.h"

class UObject;

USTRUCT()
struct FGameplayEventCachedPropertyId
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FName PropertyName;

	UPROPERTY()
	FGuid PropertyGuid;

};

USTRUCT()
struct FGameplayEventCachedBinding
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Event Binding Cache")
	TSoftObjectPtr<UObject> Object;

	UPROPERTY(EditAnywhere, Category="Event Binding Cache")
	FGameplayEventCachedPropertyId PropertyId;

};

USTRUCT()
struct FGameplayEventCachedBindings
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FGameplayEventCachedPropertyId PropertyId;

	UPROPERTY()
	TArray<FGameplayEventCachedBinding> EventBindings;

};

USTRUCT()
struct FGameplayEventCachedPropertyBindings
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<FGameplayEventCachedBindings> PropertyBindings;

};


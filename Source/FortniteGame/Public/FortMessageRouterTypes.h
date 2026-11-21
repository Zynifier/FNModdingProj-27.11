// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "FortMessageRouterTypes.generated.h"

USTRUCT(BlueprintType)
struct FGameplayMessageDualBladeMenuVisible
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	bool bValue;

};

USTRUCT(BlueprintType)
struct FGameplayMessageEnableLobbyInputPreprocessor
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	bool bValue;

};

USTRUCT(BlueprintType)
struct FGameplayMessageStandaloneFrontendDisplayed
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	bool bValue;

};

USTRUCT(BlueprintType)
struct FGameplayMessageUIGameplayTags
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	FGameplayTagContainer UIGameplayTags;

};

USTRUCT(BlueprintType)
struct FGameplayMessageUIGameplayTagsRequest
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	bool bValue;

};


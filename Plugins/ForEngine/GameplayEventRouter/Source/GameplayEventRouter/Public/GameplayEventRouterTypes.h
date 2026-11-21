// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayEventRouterTypes.generated.h"

class UObject;

UENUM(BlueprintType)
enum class EEventBubblingRule : uint8
{
	None = 0,
	Down = 1,
	Up = 2,
};

USTRUCT()
struct FGameplayEventGlobalRouterPendingListenerData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<UObject> EventType;

	UPROPERTY()
	TObjectPtr<UObject> EventContext;

};

USTRUCT()
struct FGameplayEventId
{
	GENERATED_BODY()

};

USTRUCT(BlueprintType)
struct FGameplayEventListenerBackwardCompatibleHandle
{
	GENERATED_BODY()

};

USTRUCT()
struct FGameplayEventListenerData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<UObject> EventType;

	UPROPERTY()
	TObjectPtr<UObject> EventContext;

};

USTRUCT(BlueprintType)
struct FGameplayEventListenerHandle
{
	GENERATED_BODY()

private:
	UPROPERTY()
	int32 Handle;

};

USTRUCT()
struct GAMEPLAYEVENTROUTER_API FGameplayEventListenerList
{
	GENERATED_BODY()

};


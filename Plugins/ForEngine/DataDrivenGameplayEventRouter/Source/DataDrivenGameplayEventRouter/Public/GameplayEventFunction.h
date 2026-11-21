// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/MemberReference.h"
#include "GameplayEventRouterTypes.h"
#include "GameplayEventFunction.generated.h"

class UObject;

USTRUCT()
struct DATADRIVENGAMEPLAYEVENTROUTER_API FGameplayEventHandlerFunction
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Gameplay Event")
	FMemberReference EventHandlerFunction;

	UPROPERTY()
	TMap<FName, FString> EventHandlerFunctionDefaultValues;

};

USTRUCT()
struct DATADRIVENGAMEPLAYEVENTROUTER_API FGameplayEventSubscription
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, SaveGame, Category="Gameplay Event")
	TSoftObjectPtr<UObject> Object;

	UPROPERTY(EditAnywhere, SaveGame, Category="Gameplay Event")
	FMemberReference EventDescriptor;

	UPROPERTY(Transient)
	FGameplayEventListenerHandle EventHandle;

};

USTRUCT(BlueprintType, meta=(DisplayName="Gameplay Function"))
struct DATADRIVENGAMEPLAYEVENTROUTER_API FGameplayEventFunction
{
	GENERATED_BODY()

public:
#if WITH_EDITORONLY_DATA
	UPROPERTY()
	FGameplayEventHandlerFunction OnEventReceived_DEPRECATED;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY()
	FGameplayEventHandlerFunction OnStatefulEventApplied_DEPRECATED;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY()
	FGameplayEventHandlerFunction OnStatefulEventCleared_DEPRECATED;
#endif

	UPROPERTY(EditInstanceOnly, SaveGame, Category="Gameplay Event")
	TArray<FGameplayEventSubscription> EventSubscriptions;

};

USTRUCT()
struct FGameplayEventHandlerFunctions
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Gameplay Event")
	FGameplayEventHandlerFunction OnEventReceived;

	UPROPERTY(EditAnywhere, Category="Gameplay Event")
	FGameplayEventHandlerFunction OnStatefulEventApplied;

	UPROPERTY(EditAnywhere, Category="Gameplay Event")
	FGameplayEventHandlerFunction OnStatefulEventCleared;

};


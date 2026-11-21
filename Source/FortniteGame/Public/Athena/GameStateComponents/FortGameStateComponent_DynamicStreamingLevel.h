// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/GameStateComponent.h"
#include "GameplayTagContainer.h"
#include "FrontEnd/FrontEndTypes.h"
#include "FortGameStateComponent_DynamicStreamingLevel.generated.h"

class UWorld;

USTRUCT()
struct FDynamicCompositeWorld
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="DynamicCompositeWorld")
	TSoftObjectPtr<UWorld> MainCompositeWorld;

	UPROPERTY(EditDefaultsOnly, Category="DynamicCompositeWorld")
	TArray<TSoftObjectPtr<UWorld>> AdditionalCompositeWorlds;

	UPROPERTY(EditDefaultsOnly, Category="DynamicCompositeWorld")
	FString CalendarEventName;

	UPROPERTY(EditDefaultsOnly, Category="DynamicCompositeWorld")
	FName CameraName;

	UPROPERTY(EditDefaultsOnly, Category="DynamicCompositeWorld")
	EFrontEndCamera CameraOverride;

	UPROPERTY(EditDefaultsOnly, Category="DynamicCompositeWorld")
	float GetDefaultLevelTransitionTime;

	UPROPERTY(EditDefaultsOnly, Category="DynamicCompositeWorld")
	bool bStreamInOnDemand;

	UPROPERTY(EditDefaultsOnly, Category="DynamicCompositeWorld")
	FGameplayTag StreamingInLevelTag;

	UPROPERTY(EditDefaultsOnly, Category="DynamicCompositeWorld")
	FGameplayTag StreamingOutLevelTag;

	UPROPERTY(Transient)
	bool bStreamInLevel;

	UPROPERTY(Transient)
	bool bLevelStreamedIn;

};

UCLASS(Config=Game, BlueprintType, Blueprintable, HideCategories=("Trigger", "PhysicsVolume"))
class UFortGameStateComponent_DynamicStreamingLevel : public UGameStateComponent
{
	GENERATED_BODY()

public:
	UFortGameStateComponent_DynamicStreamingLevel(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

protected:
	UPROPERTY(EditDefaultsOnly, Category="Worlds", meta=(TitleProperty="MainCompositeWorld"))
	TArray<FDynamicCompositeWorld> DynamicWorlds;

	UPROPERTY(Config)
	bool bDisableDynamicStreamingLevels;

	UPROPERTY(Config)
	bool bAlwaysLoadDynamicAsyncStreamingLevels;

};


// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameplayTagContainer.h"
#include "LevelSaveSpawnableInterface.h"
#include "FortMinigameLogicComponent.generated.h"

class AActor;
class AFortMinigame;
class UFortMinigameLogicComponent;
class UFortMinigameStatFilter;
enum class EFortMinigameState : uint8;

UENUM(BlueprintType, meta=(IsBlueprintBase="true"))
enum class EMinigameCaptureObjectiveState : uint8
{
	NotCaptured = 0,
	Captured = 1,
};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMinigameAssignmentChanged, AFortMinigame*, Minigame);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMinigameComponentStateChanged, UFortMinigameLogicComponent*, MinigameComponent);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnMinigameStateChanged, AFortMinigame*, Minigame, EFortMinigameState, NewMinigameState);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnResetMinigameComponent, UFortMinigameLogicComponent*, MinigameComponent);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FSimpleDynamicMulticastDelegate);

UCLASS(Config=Creative, MinimalAPI, BlueprintType, Blueprintable, ClassGroup=("Minigame"), meta=(BlueprintSpawnableComponent))
class UFortMinigameLogicComponent : public UActorComponent, public ILevelSaveSpawnable
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Minigame")
	FORTNITEGAME_API void AddMinigameTag(const FGameplayTag& Tag);

	UFUNCTION(BlueprintNativeEvent, Category="Minigame")
	FORTNITEGAME_API void HandleMinigameEnded();

	UFUNCTION(BlueprintNativeEvent, Category="Minigame")
	FORTNITEGAME_API void HandleMinigameStarted();

	UFUNCTION(BlueprintNativeEvent, Category="Minigame")
	FORTNITEGAME_API void HandleMinigameStateChanged(AFortMinigame* Minigame, EFortMinigameState NewMinigameState);

	UFUNCTION(BlueprintNativeEvent, Category="Minigame")
	FORTNITEGAME_API void HandlePostMinigameStarted();

	UFUNCTION(BlueprintCallable, Category="Minigame")
	FORTNITEGAME_API void RemoveMinigameTag(const FGameplayTag& Tag);

	UFUNCTION(BlueprintCallable)
	FORTNITEGAME_API bool TryAttachToMinigame();

	UPROPERTY(BlueprintAssignable, Category="Minigame")
	FOnMinigameStateChanged MinigameStateChangedDelegate;

	UPROPERTY(BlueprintAssignable, Category="Minigame")
	FSimpleDynamicMulticastDelegate MinigameStartedDelegate;

	UPROPERTY(BlueprintAssignable, Category="Minigame")
	FSimpleDynamicMulticastDelegate PostMinigameStartedDelegate;

	UPROPERTY(BlueprintAssignable, Category="Minigame")
	FSimpleDynamicMulticastDelegate MinigameEndedDelegate;

	UPROPERTY(BlueprintAssignable, Category="Minigame")
	FOnMinigameAssignmentChanged OnAddedToMinigame;

	UPROPERTY(BlueprintAssignable, Category="Minigame")
	FOnMinigameAssignmentChanged OnRemovedFromMinigame;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, SaveGame, Replicated, Category="Minigame")
	FGameplayTagContainer MinigameTags;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, SaveGame, Category="Minigame")
	TArray<TSubclassOf<UFortMinigameStatFilter>> DesiredStats;

	UPROPERTY(EditDefaultsOnly, Category="FortMinigameLogicComponent")
	bool bIsRelevantForMinigameInitialization;

	UPROPERTY(EditDefaultsOnly, Category="FortMinigameLogicComponent")
	bool bForceAlwaysRelevantInVolume;

	UPROPERTY(EditDefaultsOnly, Category="FortMinigameLogicComponent")
	bool bAlwaysTryHandleDelayedStateChange;

protected:
	UFUNCTION(BlueprintNativeEvent, Category="Minigame")
	FORTNITEGAME_API void HandleMinigameSet();

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Transient, ReplicatedUsing=HandleMinigameSet, Category="Minigame")
	TObjectPtr<AFortMinigame> CurrentMinigame;

private:
	UFUNCTION()
	FORTNITEGAME_API void OnCurrentMinigameDestroyed(AActor* DestroyedActor);

};


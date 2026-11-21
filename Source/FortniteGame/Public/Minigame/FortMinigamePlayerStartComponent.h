// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Misc/DateTime.h"
#include "Minigame/FortMinigameLogicComponent.h"
#include "FortMinigamePlayerStartComponent.generated.h"

class AFortPlayerStartCreative;
class APlayerState;

UINTERFACE(BlueprintType, Blueprintable)
class UCreativeIgnoreEnabledInterface : public UInterface
{
	GENERATED_BODY()
};

class ICreativeIgnoreEnabledInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent)
	bool ShouldIgnoreEnabledState();

};

UCLASS(meta=(BlueprintSpawnableComponent))
class UFortMinigamePlayerStartComponent : public UFortMinigameLogicComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Minigame")
	bool GetPlayerCheckpointLastUsedTime(APlayerState* Player, FDateTime& OutTime) const;

	UFUNCTION(BlueprintPure, Category="Minigame")
	bool HasAnyCheckpointValue() const;

	UFUNCTION(BlueprintCallable, Category="Minigame")
	void StorePlayerCheckpoint(APlayerState* Player);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Minigame")
	uint8 bIsCheckpoint : 1;

	UPROPERTY(BlueprintReadWrite, Transient, Category="Minigame")
	TArray<TObjectPtr<AFortPlayerStartCreative>> PlayerStarts;

};


// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Building/BuildingPropMusicPlayer.h"
#include "BuildingPropPlaygroundMusicPlayer.generated.h"

class AController;
class AFortMinigame;
class UFortGameplayReceiverMessageComponent;
class UFortMinigameLogicComponent;
enum class EFortMinigameState : uint8;

UCLASS(BlueprintType, Blueprintable, HideCategories=("Game|Damage"), PrioritizeCategories=("Instance"), SparseClassDataType=BuildingPropActorClassData)
class ABuildingPropPlaygroundMusicPlayer : public ABuildingPropMusicPlayer
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void ConditionallyLoadSongBasedOnMinigameState();

	UFUNCTION(BlueprintCallable)
	void OnMinigameStateChanged(AFortMinigame* Minigame, EFortMinigameState NewMinigameState);

	UFUNCTION(BlueprintCallable)
	void Play();

	UFUNCTION()
	void PlayReceiver(AController* TriggerInstigator);

	UFUNCTION(BlueprintCallable)
	void Stop();

	UFUNCTION()
	void StopReceiver(AController* TriggerInstigator);

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Export, Category="BuildingPropPlaygroundMusicPlayer", meta=(EditInline="true"))
	TObjectPtr<UFortMinigameLogicComponent> MinigameLogicComponent;

	UPROPERTY(EditDefaultsOnly, Export, Category="BuildingPropPlaygroundMusicPlayer", meta=(EditInline="true"))
	TObjectPtr<UFortGameplayReceiverMessageComponent> PlayReceiverComponent;

	UPROPERTY(EditDefaultsOnly, Export, Category="BuildingPropPlaygroundMusicPlayer", meta=(EditInline="true"))
	TObjectPtr<UFortGameplayReceiverMessageComponent> StopReceiverComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="UserOptions")
	bool PlayDuringWaitingForPlayers;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="UserOptions")
	bool PlayDuringGameCountdown;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="UserOptions")
	bool PlayDuringGameplay;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="UserOptions")
	bool PlayDuringRoundEnd;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="UserOptions")
	bool PlayDuringGameEnd;

};


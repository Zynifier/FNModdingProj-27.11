// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/AthenaGameMessage.h"
#include "Athena/Modifiers/FortAthenaMutator.h"
#include "FortAthenaMutator_CreativeTutorial.generated.h"

class AFortVolume;
class APlayerState;

UCLASS(MinimalAPI, BlueprintType, HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_CreativeTutorial : public AFortAthenaMutator
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	float ServerShutdownTimeRemaining;

protected:
	UFUNCTION()
	void DisplayBackToHubMessage();

	UFUNCTION()
	void OnActorEnteredVolume(APlayerState* PS, AFortVolume* Volume);

	UFUNCTION()
	void OnEndSkydiving();

	UFUNCTION()
	void OnMutatorGameplayEvent(int32 EventId, int32 EventParam1, int32 EventParam2, int32 EventParam3);

	UFUNCTION()
	void OnPlayerCreativeVolumeChanged(AFortVolume* Volume);

	UFUNCTION()
	void OnPlayerJoinedCreativeIsland();

	UFUNCTION()
	void OnVolumeManagerReplicated();

	UFUNCTION()
	void StartTrackingEndSkydiving();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="TutorialMessages")
	FAthenaGameMessageData GameMsg_LandOnHub;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="TutorialMessages")
	FAthenaGameMessageData GameMsg_LandOnIsland;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="TutorialMessages")
	FAthenaGameMessageData GameMsg_Inventory;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="TutorialMessages")
	FAthenaGameMessageData GameMsg_IslandMenu;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="TutorialMessages")
	FAthenaGameMessageData GameMsg_BackToHub;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="TutorialMessages")
	FAthenaGameMessageData GameMsg_ExploreFriendsIslands;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="TutorialMessages")
	FAthenaGameMessageData GameMsg_Permissions;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="TutorialMessages")
	FAthenaGameMessageData ServerShutdownInitiated;

	UPROPERTY(Transient)
	bool bHasSeenInventoryTutorial;

	UPROPERTY(Transient)
	bool bHasSeenReturnToCreativeHubTutorial;

	UPROPERTY(Transient)
	bool bHasSeenMyIslandTutorial;

	UPROPERTY(Transient)
	bool bHasSeenWelcomeTutorial;

	UPROPERTY(Transient)
	bool bHasSeenPermissionsTutorial;

	UPROPERTY(Transient)
	bool bCanShowMyIslandMessage;

};


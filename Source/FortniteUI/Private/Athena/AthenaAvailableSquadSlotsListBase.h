// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/OnlineReplStructs.h"
#include "FortHUDElementWidget.h"
#include "AthenaAvailableSquadSlotsListBase.generated.h"

class AFortMinigame;
class AFortPlayerStateAthena;
class AFortVolume;
class APlayerState;
class UAthenaPlayerViewModel;
class UDynamicEntryBox;
enum class EFortMinigameState : uint8;

UCLASS(meta=(DisableNativeTick))
class UAthenaAvailableSquadSlotsListBase : public UFortHUDElementWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(EditInstanceOnly, Category="AthenaAvailableSquadSlotsListBase")
	int32 MaxNumberOfAvailableSquadSlots;

	UPROPERTY(EditInstanceOnly, Category="AthenaAvailableSquadSlotsListBase")
	bool bAlwaysDisplayTopEntryAsDetailed;

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void HandleSquadMemberDisconnected(const AFortPlayerStateAthena* Player);

private:
	UFUNCTION()
	void HandleGameMemberChanged(uint8 InSquadId, uint8 InTeamIndex, AFortPlayerStateAthena* ChangedPS);

	UFUNCTION()
	void HandlePlayerEnterVolume(APlayerState* ClientPlayerState, AFortVolume* Volume);

	UFUNCTION()
	void HandlePlayerExitVolume(APlayerState* ClientPlayerState, AFortVolume* Volume);

	UFUNCTION()
	void HandlePlayerUniqueIdReplicated(const FUniqueNetIdRepl& UniqueId);

	UFUNCTION()
	void UpdateIsTeamMiniGameOnGameStateChanged(AFortMinigame* Minigame, EFortMinigameState MiniGameState);

	UFUNCTION()
	void UpdateIsTeamMiniGameOnMinigameVolumeChanged(AFortVolume* Volume);

	UFUNCTION()
	void UpdateSquadFromMinigameOptionChange();

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UDynamicEntryBox> EntryBox_AvailableSlotsList;

	UPROPERTY(Transient)
	TObjectPtr<UAthenaPlayerViewModel> CachedPlayerVM;

};


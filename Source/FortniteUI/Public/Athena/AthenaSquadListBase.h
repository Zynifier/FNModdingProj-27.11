// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/SlateWrapperTypes.h"
#include "GameFramework/OnlineReplStructs.h"
#include "FortHUDElementWidget.h"
#include "AthenaSquadListBase.generated.h"

class AFortPlayerStateAthena;
class AFortVolume;
class APlayerState;
class UAthenaPlayerInfoBase;
class UAthenaPlayerViewModel;
class UDynamicEntryBox;
class UUserWidget;
enum class EUIExtensionSlot : uint8;

UCLASS(meta=(DisableNativeTick))
class UAthenaSquadListBase : public UFortHUDElementWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="AthenaSquadListBase")
	ESlateVisibility LocalPlayerVisibility;

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void HandleSquadMemberDisconnected(const AFortPlayerStateAthena* Player);

	UFUNCTION(BlueprintImplementableEvent)
	void OnExtensionWidgetAdded(const EUIExtensionSlot SlotType, UUserWidget* Widget);

	UFUNCTION(BlueprintImplementableEvent)
	void OnExtensionWidgetRemoved(UUserWidget* Widget);

private:
	UFUNCTION()
	void HandleGameMemberChanged(uint8 InSquadId, uint8 InTeamIndex, AFortPlayerStateAthena* ChangedPS);

	UFUNCTION()
	void HandlePlayerEnterVolume(APlayerState* Client, AFortVolume* Volume);

	UFUNCTION()
	void HandlePlayerExitVolume(APlayerState* Client, AFortVolume* Volume);

	UFUNCTION()
	void HandlePlayerUniqueIdReplicated(const FUniqueNetIdRepl& UniqueId);

	UFUNCTION()
	void UpdateIsTeamMiniGameOnMinigameVolumeChanged(AFortVolume* Volume);

	UFUNCTION()
	void UpdateSquadFromMinigameOptionChange();

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UAthenaPlayerInfoBase> LocalPlayerInfo;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true", EntryClass="AthenaTeamMemberInfo"))
	TObjectPtr<UDynamicEntryBox> EntryBox_SquadList;

	UPROPERTY(Transient)
	TObjectPtr<UAthenaPlayerViewModel> CachedPlayerVM;

};


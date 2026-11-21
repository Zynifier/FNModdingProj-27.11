// Copyright Epic Games, Inc. All Rights Reserved.

#include "Minigame/FortMinigameSettingsBuilding.h"
#include "Net/UnrealNetwork.h"

void AFortMinigameSettingsBuilding::CheckPublishedIslandCodeDisplayChanged()
{
}

TArray<FText> AFortMinigameSettingsBuilding::GetGameDescription()
{
	return TArray<FText>();
}

FText AFortMinigameSettingsBuilding::GetGameName()
{
	return FText();
}

AFortMinigame* AFortMinigameSettingsBuilding::GetMinigame() const
{
	return nullptr;
}

const FMinigamePostGameSettings& AFortMinigameSettingsBuilding::GetPostGameSettings() const
{
	static FMinigamePostGameSettings Dummy;
	return Dummy;
}

UDataTable* AFortMinigameSettingsBuilding::GetSelectedTextStyleSet() const
{
	return nullptr;
}

bool AFortMinigameSettingsBuilding::HasUpgradedDevices() const
{
	return false;
}

void AFortMinigameSettingsBuilding::OnLinkedVolumeSet(AFortVolume* PreviousVolume, AFortVolume* NewVolume)
{
}

void AFortMinigameSettingsBuilding::OnMinigameEnded()
{
}

void AFortMinigameSettingsBuilding::OnMinigameStarted()
{
}

void AFortMinigameSettingsBuilding::OnRep_GameDescriptionData()
{
}

void AFortMinigameSettingsBuilding::OnRep_GameNameData()
{
}

void AFortMinigameSettingsBuilding::OnRep_SettingsVolume()
{
}

void AFortMinigameSettingsBuilding::OnSaveComponentFinishSpawning(FEventMessageTag Channel, const FSpatialGameplayInterfaceContext& Context)
{
}

void AFortMinigameSettingsBuilding::OverridePostGameSettings(const FMinigamePostGameSettings& NewSettings)
{
}

void AFortMinigameSettingsBuilding::SetGameDescription(const FText& GameName, const TArray<FText>& GameDescriptionText)
{
}

void AFortMinigameSettingsBuilding::UpdateMatchmakingSetings()
{
}

void AFortMinigameSettingsBuilding::UpdateMatchmakingSettings()
{
}

void AFortMinigameSettingsBuilding::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortMinigameSettingsBuilding, GameDescriptionData);
	DOREPLIFETIME(AFortMinigameSettingsBuilding, GameNameData);
	DOREPLIFETIME(AFortMinigameSettingsBuilding, EventSystem);
	DOREPLIFETIME(AFortMinigameSettingsBuilding, SettingsVolume);
	DOREPLIFETIME(AFortMinigameSettingsBuilding, PostGameSettingsOverride);
}

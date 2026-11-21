// Copyright Epic Games, Inc. All Rights Reserved.

#include "Player/FortPlayerControllerGameplay.h"
#include "Net/UnrealNetwork.h"

void AFortPlayerControllerGameplay::ActivateCreativePreviewScreenshot(bool bActivate)
{
}

bool AFortPlayerControllerGameplay::CanFollowAPlayer(const bool bOnlyCheckTeammates) const
{
	return false;
}

bool AFortPlayerControllerGameplay::CanPlayerCreateInCurrentExperience() const
{
	return false;
}

void AFortPlayerControllerGameplay::CheckGhostModeItemRemoved(UFortWorldItemDefinition* GhostModeItemDef)
{
}

void AFortPlayerControllerGameplay::CheckGhostModeItemReplicated()
{
}

void AFortPlayerControllerGameplay::ClientApplyItemAbilitySet_Implementation(UFortAbilitySet* AbilitySet, FGuid Guid)
{
}

void AFortPlayerControllerGameplay::ClientCreativePhoneCreated_Implementation()
{
}

void AFortPlayerControllerGameplay::ClientCreativeSetUIMetricsDisplayIndex_Implementation(int32 Index)
{
}

void AFortPlayerControllerGameplay::ClientCreativeStopFly_Implementation()
{
}

void AFortPlayerControllerGameplay::ClientRemoveItemAbilitySet_Implementation(UFortAbilitySet* AbilitySet, FGuid Guid)
{
}

void AFortPlayerControllerGameplay::CreativeToggleFly(const bool bEnableOnly)
{
}

void AFortPlayerControllerGameplay::DisableTrickCredit(float Duration)
{
}

void AFortPlayerControllerGameplay::DisplayNPCNumbers(bool bDisplay)
{
}

void AFortPlayerControllerGameplay::EndGhostMode()
{
}

void AFortPlayerControllerGameplay::ExitSpawnedVehicle()
{
}

bool AFortPlayerControllerGameplay::FollowPlayer(const EPlayerControllerFollow Follow)
{
	return false;
}

UFortAmbientAudioController* AFortPlayerControllerGameplay::GetAmbientAudioController() const
{
	return nullptr;
}

int32 AFortPlayerControllerGameplay::GetFlyingModifierIndex()
{
	return int32();
}

AFortMinigame* AFortPlayerControllerGameplay::GetMinigame() const
{
	return nullptr;
}

FString AFortPlayerControllerGameplay::GetSettingsFilteredPlayerName(const AFortPlayerState* OtherPlayerState) const
{
	return FString();
}

FString AFortPlayerControllerGameplay::GetSpectatingPlayerName()
{
	return FString();
}

FVehicleTrickInfo AFortPlayerControllerGameplay::GetVehicleTrickInfo()
{
	return FVehicleTrickInfo();
}

void AFortPlayerControllerGameplay::HandlePoiTagContainerTableFinishedReplicating(AFortPoiManager* PoiManager)
{
}

bool AFortPlayerControllerGameplay::HasCreativeFlyingInputComponent() const
{
	return false;
}

void AFortPlayerControllerGameplay::InitializeAmbientAudioController()
{
}

bool AFortPlayerControllerGameplay::IsAllowedToFly() const
{
	return false;
}

bool AFortPlayerControllerGameplay::IsCreativeIslandExporterEnabled() const
{
	return false;
}

bool AFortPlayerControllerGameplay::IsCreativeModeEnabled() const
{
	return false;
}

bool AFortPlayerControllerGameplay::IsCreativeModeratorModeActive() const
{
	return false;
}

bool AFortPlayerControllerGameplay::IsCreativeModeratorModeAllowed() const
{
	return false;
}

bool AFortPlayerControllerGameplay::IsCreativeModeratorModeEnabled() const
{
	return false;
}

bool AFortPlayerControllerGameplay::IsCreativePhoneAndHarvestHoldSwapped() const
{
	return false;
}

bool AFortPlayerControllerGameplay::IsCreativePhotoModeAvailable() const
{
	return false;
}

bool AFortPlayerControllerGameplay::IsCreativePreviewScreenshotAvailable() const
{
	return false;
}

bool AFortPlayerControllerGameplay::IsCreativeQuickbarActive() const
{
	return false;
}

bool AFortPlayerControllerGameplay::IsCreativeQuickbarEnabled() const
{
	return false;
}

bool AFortPlayerControllerGameplay::IsCreativeQuickmenuEnabled() const
{
	return false;
}

bool AFortPlayerControllerGameplay::IsCreativeThermometerNewUIEnabled() const
{
	return false;
}

bool AFortPlayerControllerGameplay::IsInGhostMode() const
{
	return false;
}

bool AFortPlayerControllerGameplay::IsUsingHideOtherPlayerNames() const
{
	return false;
}

void AFortPlayerControllerGameplay::OnEnterAircraft(AController* EnteringController)
{
}

void AFortPlayerControllerGameplay::OnExitAircraft(AController* ExitingController)
{
}

void AFortPlayerControllerGameplay::OnRep_CreativeQuickbarComponent()
{
}

void AFortPlayerControllerGameplay::OnRep_FlyingModifierIndex()
{
}

void AFortPlayerControllerGameplay::OnRep_GhostModeRepData()
{
}

void AFortPlayerControllerGameplay::OnRep_IsCreativeModeEnabled()
{
}

void AFortPlayerControllerGameplay::OnRep_IsCreativeModeratorModeActive()
{
}

void AFortPlayerControllerGameplay::OnRep_IsCreativeQuickbarEnabled(bool bPrevIsEnabled)
{
}

void AFortPlayerControllerGameplay::OnRep_IsFlightSprinting()
{
}

void AFortPlayerControllerGameplay::OnRep_PoiTagContainerTableID(int16 PreviousPoiTagContainerTableID)
{
}

void AFortPlayerControllerGameplay::OnRep_UIMetricsDisplayIndex()
{
}

void AFortPlayerControllerGameplay::OnVerifyAllowedToBeInvulnerable()
{
}

void AFortPlayerControllerGameplay::OnVerifyAllowedToFly()
{
}

void AFortPlayerControllerGameplay::OnVerifyAllowModeratorMode()
{
}

void AFortPlayerControllerGameplay::OnWantedFlightSpeedChanged(UFortCreativeOption* CreativeOption, uint8 IndexValue)
{
}

void AFortPlayerControllerGameplay::OnWantedToSwapPhoneAndHarvestHoldChanged(UFortCreativeOption* CreativeOption, uint8 IndexValue)
{
}

void AFortPlayerControllerGameplay::OnWantedUIMetricsDisplayChanged(UFortCreativeOption* CreativeOption, uint8 IndexValue)
{
}

void AFortPlayerControllerGameplay::OnWantsToBeInvulnerableChanged(UFortCreativeOption* CreativeOption, uint8 IndexValue)
{
}

void AFortPlayerControllerGameplay::OnWantsToGhostModeChanged(UFortCreativeOption* CreativeOption, uint8 IndexValue)
{
}

void AFortPlayerControllerGameplay::PopCreativeReadyCheckInputMode()
{
}

void AFortPlayerControllerGameplay::PushCreativeReadyCheckInputMode()
{
}

void AFortPlayerControllerGameplay::ResetTrick(AActor* VehicleActor)
{
}

void AFortPlayerControllerGameplay::Server_CreativeModeratorModeSetActive_Implementation(bool bActive)
{
}

void AFortPlayerControllerGameplay::ServerAwardVehicleTrickPoints_Implementation(int32 InPoints, int32 InAirTimeX1000, int32 NumberOfTricks, float AirDistance, float AirHeight)
{
}
bool AFortPlayerControllerGameplay::ServerAwardVehicleTrickPoints_Validate(int32 InPoints, int32 InAirTimeX1000, int32 NumberOfTricks, float AirDistance, float AirHeight)
{
	return true;
}

void AFortPlayerControllerGameplay::ServerCreativeSetFlightSpeedIndex_Implementation(int32 Index)
{
}
bool AFortPlayerControllerGameplay::ServerCreativeSetFlightSpeedIndex_Validate(int32 Index)
{
	return true;
}

void AFortPlayerControllerGameplay::ServerCreativeSetFlightSprint_Implementation(bool bSprint)
{
}
bool AFortPlayerControllerGameplay::ServerCreativeSetFlightSprint_Validate(bool bSprint)
{
	return true;
}

void AFortPlayerControllerGameplay::ServerCreativeSetGhost_Implementation(bool bWantsToGhost)
{
}
bool AFortPlayerControllerGameplay::ServerCreativeSetGhost_Validate(bool bWantsToGhost)
{
	return true;
}

void AFortPlayerControllerGameplay::ServerCreativeStartFlyDown_Implementation()
{
}
bool AFortPlayerControllerGameplay::ServerCreativeStartFlyDown_Validate()
{
	return true;
}

void AFortPlayerControllerGameplay::ServerCreativeStartFlyUp_Implementation()
{
}
bool AFortPlayerControllerGameplay::ServerCreativeStartFlyUp_Validate()
{
	return true;
}

void AFortPlayerControllerGameplay::ServerCreativeStartInvulnerable_Implementation()
{
}
bool AFortPlayerControllerGameplay::ServerCreativeStartInvulnerable_Validate()
{
	return true;
}

void AFortPlayerControllerGameplay::ServerCreativeStopFly_Implementation()
{
}
bool AFortPlayerControllerGameplay::ServerCreativeStopFly_Validate()
{
	return true;
}

void AFortPlayerControllerGameplay::ServerCreativeStopFlyDown_Implementation()
{
}
bool AFortPlayerControllerGameplay::ServerCreativeStopFlyDown_Validate()
{
	return true;
}

void AFortPlayerControllerGameplay::ServerCreativeStopFlyUp_Implementation()
{
}
bool AFortPlayerControllerGameplay::ServerCreativeStopFlyUp_Validate()
{
	return true;
}

void AFortPlayerControllerGameplay::ServerCreativeStopGhost_Implementation()
{
}
bool AFortPlayerControllerGameplay::ServerCreativeStopGhost_Validate()
{
	return true;
}

void AFortPlayerControllerGameplay::ServerCreativeStopInvulnerable_Implementation()
{
}
bool AFortPlayerControllerGameplay::ServerCreativeStopInvulnerable_Validate()
{
	return true;
}

void AFortPlayerControllerGameplay::ServerCreativeToggleFly_Implementation(const bool bEnableOnly)
{
}
bool AFortPlayerControllerGameplay::ServerCreativeToggleFly_Validate(const bool bEnableOnly)
{
	return true;
}

void AFortPlayerControllerGameplay::ServerDespawnModeratorBot_Implementation()
{
}

void AFortPlayerControllerGameplay::ServerRPCSetDisplayNPCNumbers_Implementation(bool bEnable)
{
}
bool AFortPlayerControllerGameplay::ServerRPCSetDisplayNPCNumbers_Validate(bool bEnable)
{
	return true;
}

void AFortPlayerControllerGameplay::ServerSpawnModeratorBot_Implementation()
{
}

void AFortPlayerControllerGameplay::SetCanStreamBuildingFoundationsIn(bool bCanStream)
{
}

void AFortPlayerControllerGameplay::SetCreativeModeratorModeActive(bool bActive)
{
}

void AFortPlayerControllerGameplay::SetCreativePhotoModeActivateState(bool bIsActive)
{
}

AFortAthenaVehicle* AFortPlayerControllerGameplay::SpawnVehicleAndEnter(TSubclassOf<AFortAthenaVehicle> VehicleClass, const bool bHidePawn, const bool bSetPawnAsVehicleOwner, const EVehicleSeats SeatToEnter, const bool bIgnoreDBNOCheck, const bool bCheckForNonBlockingSpawnPosition, const bool bForceToWaterSurfaceOnSpawn)
{
	return nullptr;
}

void AFortPlayerControllerGameplay::StartGhostMode(UFortWorldItemDefinition* ItemProvidingGhostMode)
{
}

bool AFortPlayerControllerGameplay::Validation_IsFlyingPossible() const
{
	return false;
}

void AFortPlayerControllerGameplay::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortPlayerControllerGameplay, PoiTagContainerTableID);
	DOREPLIFETIME(AFortPlayerControllerGameplay, CreativeQuickbarComponent);
	DOREPLIFETIME(AFortPlayerControllerGameplay, GhostModeRepData);
	DOREPLIFETIME(AFortPlayerControllerGameplay, ServerNumNPCs);
	DOREPLIFETIME(AFortPlayerControllerGameplay, ServerMaxNumNPCs);
	DOREPLIFETIME(AFortPlayerControllerGameplay, bDisplayNPCNumbers);
	DOREPLIFETIME(AFortPlayerControllerGameplay, FlyingModifierIndex);
	DOREPLIFETIME(AFortPlayerControllerGameplay, UIMetricsDisplayIndex);
	DOREPLIFETIME(AFortPlayerControllerGameplay, bIsFlightSprinting);
	DOREPLIFETIME(AFortPlayerControllerGameplay, bIsCreativeModeEnabled);
	DOREPLIFETIME(AFortPlayerControllerGameplay, bIsCreativeQuickbarEnabled);
	DOREPLIFETIME(AFortPlayerControllerGameplay, bCreativeMCPProfileIsMatchamkingEnabled);
	DOREPLIFETIME(AFortPlayerControllerGameplay, bIsCreativeThermometerNewUIEnabled);
	DOREPLIFETIME(AFortPlayerControllerGameplay, bIsCreativeIslandExporterEnabled);
	DOREPLIFETIME(AFortPlayerControllerGameplay, bIsCreativeModeratorModeEnabled);
	DOREPLIFETIME(AFortPlayerControllerGameplay, bIsCreativeModeratorModeActive);
}

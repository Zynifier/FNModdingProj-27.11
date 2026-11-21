// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/FortAthenaCreativePortal.h"
#include "Net/UnrealNetwork.h"

void AFortAthenaCreativePortal::AttemptCancelMatchmakingToEdit(AFortPlayerController* PlayerToMatchmake)
{
}

void AFortAthenaCreativePortal::CheckMinigameOnTeleportComplete(AFortPlayerPawn* PlayerPawn, bool bTeleportedToIslandStart)
{
}

void AFortAthenaCreativePortal::Client_OnIsValkyrieEditPortalChanged()
{
}

void AFortAthenaCreativePortal::ClientSaveStateChanged(bool bSaving)
{
}

void AFortAthenaCreativePortal::FinishedReadingCloudFiles(const FAsyncTaskResult& Result)
{
}

const FText& AFortAthenaCreativePortal::GetCachedEditIslandDataIslandName() const
{
	static FText Dummy;
	return Dummy;
}

FText AFortAthenaCreativePortal::GetCreatorName() const
{
	return FText();
}

TArray<FString> AFortAthenaCreativePortal::GetDescriptionTags() const
{
	return TArray<FString>();
}

FVector AFortAthenaCreativePortal::GetHUDPointerOrigin()
{
	return FVector();
}

FString AFortAthenaCreativePortal::GetImageURL() const
{
	return FString();
}

TArray<FCreativeIslandDescriptionTag> AFortAthenaCreativePortal::GetIslandDescriptionTags() const
{
	return TArray<FCreativeIslandDescriptionTag>();
}

FString AFortAthenaCreativePortal::GetIslandID() const
{
	return FString();
}

bool AFortAthenaCreativePortal::GetIsPublishedPortal() const
{
	return false;
}

AFortVolume* AFortAthenaCreativePortal::GetLinkedVolume() const
{
	return nullptr;
}

FString AFortAthenaCreativePortal::GetMnemonic() const
{
	return FString();
}

AFortPlayerStateAthena* AFortAthenaCreativePortal::GetPlayerState()
{
	return nullptr;
}

uint8 AFortAthenaCreativePortal::GetPopulation() const
{
	return uint8();
}

EMMSPrivacy AFortAthenaCreativePortal::GetPrivacy() const
{
	return EMMSPrivacy();
}

FText AFortAthenaCreativePortal::GetTagline() const
{
	return FText();
}

int32 AFortAthenaCreativePortal::GetThumbnailHeight() const
{
	return int32();
}

int32 AFortAthenaCreativePortal::GetThumbnailWidth() const
{
	return int32();
}

FText AFortAthenaCreativePortal::GetVolumeDisplayName() const
{
	return FText();
}

bool AFortAthenaCreativePortal::IsInErrorStateForRole() const
{
	return false;
}

bool AFortAthenaCreativePortal::IsPortalInteractable() const
{
	return false;
}

bool AFortAthenaCreativePortal::IsPortalOpen() const
{
	return false;
}

bool AFortAthenaCreativePortal::IsPortalOpenForRole() const
{
	return false;
}

bool AFortAthenaCreativePortal::IsRunningMatchmakingFlowToEdit(AFortPlayerController* PlayerToMatchmake) const
{
	return false;
}

void AFortAthenaCreativePortal::LogIslandTeleportation()
{
}

void AFortAthenaCreativePortal::NotifyTeleportedVehicle_Implementation(AActor* VehicleActor)
{
}

void AFortAthenaCreativePortal::OnClientLoadedStateChanged()
{
}

void AFortAthenaCreativePortal::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
}

void AFortAthenaCreativePortal::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
}

void AFortAthenaCreativePortal::OnRep_CachedEditIslandData()
{
}

void AFortAthenaCreativePortal::OnRep_ErrorState()
{
}

void AFortAthenaCreativePortal::OnRep_IslandInfo()
{
}

void AFortAthenaCreativePortal::OnRep_IsUsingUGC()
{
}

void AFortAthenaCreativePortal::OnRep_MaxAvailablePopulationChanged()
{
}

void AFortAthenaCreativePortal::OnRep_OwningPlayer()
{
}

void AFortAthenaCreativePortal::OnRep_PlayersReady()
{
}

void AFortAthenaCreativePortal::OnRep_PopulationChanged()
{
}

void AFortAthenaCreativePortal::OnRep_PortalOpen()
{
}

void AFortAthenaCreativePortal::OnRep_PublishedPortal()
{
}

void AFortAthenaCreativePortal::OnRep_VolumeStatus()
{
}

void AFortAthenaCreativePortal::OnUGCPaletteChanged(const TArray<FString>& UpdatedLinkCodes)
{
}

void AFortAthenaCreativePortal::OnUnloadPlotComplete()
{
}

void AFortAthenaCreativePortal::OnUserGeneratedContentRestrictionsChanged(bool bRestrictionEnabled)
{
}

void AFortAthenaCreativePortal::OnVolumeManagerUserGeneratedContentRestrictionsChanged(AFortVolume* Volume, bool bRestrictionEnabled)
{
}

void AFortAthenaCreativePortal::SetHUDPointerOrigin(FVector NewPointerOrigin)
{
}

void AFortAthenaCreativePortal::SetInteractionDisplayWidget(UUserWidget* DisplayWidget)
{
}

void AFortAthenaCreativePortal::SetInteractionInteractComponent(UPrimitiveComponent* PrimitiveComponent)
{
}

void AFortAthenaCreativePortal::SetOverlapComponent(UCapsuleComponent* InOverlapComponent)
{
}

bool AFortAthenaCreativePortal::ShouldPausePortalUpdates_Client() const
{
	return false;
}

void AFortAthenaCreativePortal::StartedPlotLoadForUser(const FAsyncTaskResult& Result)
{
}

void AFortAthenaCreativePortal::TeleportPlayer(AFortPlayerPawn* PlayerPawn, const FRotator& TeleportRotation)
{
}

void AFortAthenaCreativePortal::TeleportPlayerForPlotLoadComplete(AFortPlayerPawn* PlayerPawn)
{
}

void AFortAthenaCreativePortal::TeleportPlayerToLinkedVolume(AFortPlayerPawn* PlayerPawn, bool bUseSpawnTags)
{
}

void AFortAthenaCreativePortal::TeleportVehicle(AFortAthenaVehicle* Vehicle)
{
}

void AFortAthenaCreativePortal::UpdateIslandDisplayName()
{
}

void AFortAthenaCreativePortal::UpdateThumbnail()
{
}

void AFortAthenaCreativePortal::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortAthenaCreativePortal, bReturnToCreativeHub);
	DOREPLIFETIME(AFortAthenaCreativePortal, bInErrorState);
	DOREPLIFETIME(AFortAthenaCreativePortal, bUserInitiatedLoad);
	DOREPLIFETIME(AFortAthenaCreativePortal, CachedEditIslandData);
	DOREPLIFETIME(AFortAthenaCreativePortal, IslandInfo);
	DOREPLIFETIME(AFortAthenaCreativePortal, VolumeStatus);
	DOREPLIFETIME(AFortAthenaCreativePortal, EditOverridePlaylist);
	DOREPLIFETIME(AFortAthenaCreativePortal, bIsPlotLoadTimeOut);
	DOREPLIFETIME(AFortAthenaCreativePortal, CurrentPopulation);
	DOREPLIFETIME(AFortAthenaCreativePortal, MaxAvailablePopulation);
	DOREPLIFETIME(AFortAthenaCreativePortal, OwningPlayer);
	DOREPLIFETIME(AFortAthenaCreativePortal, PlayersReady);
	DOREPLIFETIME(AFortAthenaCreativePortal, bIsPublishedPortal);
	DOREPLIFETIME(AFortAthenaCreativePortal, bIsUsingUGC);
	DOREPLIFETIME(AFortAthenaCreativePortal, TeleportLocation);
	DOREPLIFETIME(AFortAthenaCreativePortal, bPortalOpen);
}

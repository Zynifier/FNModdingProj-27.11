// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/FortAthenaPartyRiftPortal.h"
#include "Net/UnrealNetwork.h"

FText AFortAthenaPartyRiftPortal::GetCreatorName() const
{
	return FText();
}

const int32 AFortAthenaPartyRiftPortal::GetCurrentPartySize() const
{
	return int32();
}

FVector AFortAthenaPartyRiftPortal::GetHUDPointerOrigin()
{
	return FVector();
}

bool AFortAthenaPartyRiftPortal::GetIsPublishedPortal() const
{
	return false;
}

const int32 AFortAthenaPartyRiftPortal::GetMaxPartySize() const
{
	return int32();
}

FText AFortAthenaPartyRiftPortal::GetPartyJoinPrompt() const
{
	return FText();
}

TArray<AFortPlayerStateAthena*> AFortAthenaPartyRiftPortal::GetPartyMemberPlayerStateList() const
{
	return TArray<AFortPlayerStateAthena*>();
}

AFortPlayerStateAthena* AFortAthenaPartyRiftPortal::GetPortalOwnerPlayerState() const
{
	return nullptr;
}

FText AFortAthenaPartyRiftPortal::GetTagline() const
{
	return FText();
}

int32 AFortAthenaPartyRiftPortal::GetThumbnailHeight() const
{
	return int32();
}

int32 AFortAthenaPartyRiftPortal::GetThumbnailWidth() const
{
	return int32();
}

bool AFortAthenaPartyRiftPortal::IsPartyJoinable() const
{
	return false;
}

bool AFortAthenaPartyRiftPortal::IsPartyJoinRequestable() const
{
	return false;
}

bool AFortAthenaPartyRiftPortal::IsPlayerInOwnerParty(const AFortPlayerController* InteractingController) const
{
	return false;
}

bool AFortAthenaPartyRiftPortal::IsPortalInteractable() const
{
	return false;
}

bool AFortAthenaPartyRiftPortal::IsPortalOpen() const
{
	return false;
}

bool AFortAthenaPartyRiftPortal::OnInteractWithPartyRiftPortal(AFortPlayerController* InteractingController)
{
	return false;
}

void AFortAthenaPartyRiftPortal::OnRep_bIsPublishedPortal()
{
}

void AFortAthenaPartyRiftPortal::OnRep_bPortalOpen()
{
}

void AFortAthenaPartyRiftPortal::OnRep_ErrorState()
{
}

void AFortAthenaPartyRiftPortal::OnRep_MaxPartySize()
{
}

void AFortAthenaPartyRiftPortal::OnRep_OwningPlayerNetId(const FUniqueNetIdRepl InOldOwningPlayerNetId)
{
}

void AFortAthenaPartyRiftPortal::OnRep_PartyJoinInfoJSON()
{
}

void AFortAthenaPartyRiftPortal::OnRep_PartyMemberNetIdList()
{
}

void AFortAthenaPartyRiftPortal::ReleasePortal(const FString& Reason)
{
}

void AFortAthenaPartyRiftPortal::ServerCacheMaxPartySize_Implementation(const int32 NewMaxPartySize)
{
}

void AFortAthenaPartyRiftPortal::ServerCachePartyJoinInfo_Implementation(const FString& NewPartyJoinInfo)
{
}

void AFortAthenaPartyRiftPortal::ServerCachePartyMemberNetIdList_Implementation(const TArray<FUniqueNetIdRepl>& NewPartyMemberNetIdList)
{
}

void AFortAthenaPartyRiftPortal::SetHUDPointerOrigin(const FVector NewPointerOrigin)
{
}

void AFortAthenaPartyRiftPortal::SetInteractionDisplayWidget(UUserWidget* DisplayWidget)
{
}

void AFortAthenaPartyRiftPortal::SetInteractionInteractComponent(UPrimitiveComponent* PrimitiveComponent)
{
}

void AFortAthenaPartyRiftPortal::UpdatePartyJoinInfo()
{
}

void AFortAthenaPartyRiftPortal::UpdateThumbnail()
{
}

void AFortAthenaPartyRiftPortal::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortAthenaPartyRiftPortal, bInErrorState);
	DOREPLIFETIME(AFortAthenaPartyRiftPortal, OwningPlayerNetId);
	DOREPLIFETIME(AFortAthenaPartyRiftPortal, bIsPublishedPortal);
	DOREPLIFETIME(AFortAthenaPartyRiftPortal, bPortalOpen);
	DOREPLIFETIME(AFortAthenaPartyRiftPortal, PartyJoinInfoJSON);
	DOREPLIFETIME(AFortAthenaPartyRiftPortal, MaxPartySize);
	DOREPLIFETIME(AFortAthenaPartyRiftPortal, PartyMemberNetIdList);
	DOREPLIFETIME(AFortAthenaPartyRiftPortal, InitialDeploymentTime);
}

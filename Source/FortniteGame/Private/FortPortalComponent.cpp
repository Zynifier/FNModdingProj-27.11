// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortPortalComponent.h"
#include "Net/UnrealNetwork.h"

bool UFortPortalComponent::CanSetLinkCode() const
{
	return false;
}

void UFortPortalComponent::CheckIslandModeration(const FCreativeLoadedLinkData& LinkData, const FOnIslandModerationCheckComplete& OnIslandModerationCheckComplete)
{
}

void UFortPortalComponent::ExpireLinkCodeLock()
{
}

FString UFortPortalComponent::GetAccountIdOwnerOfIsland() const
{
	return FString();
}

FTimespan UFortPortalComponent::GetRemainingLockDuration() const
{
	return FTimespan();
}

bool UFortPortalComponent::HasValidLinkData() const
{
	return false;
}

bool UFortPortalComponent::IsPartyEligibleForMatchmaking() const
{
	return false;
}

bool UFortPortalComponent::IsPlayerEligibleToBeginMatchmaking(const AFortPlayerController* FortPC) const
{
	return false;
}

bool UFortPortalComponent::IsWellKnownNameSupported() const
{
	return false;
}

bool UFortPortalComponent::LinkRequiresCreativeContent()
{
	return false;
}

FString UFortPortalComponent::MakeLinkCodeWithVersioning(const FString& LinkCode, int32 Version) const
{
	return FString();
}

void UFortPortalComponent::OnLinkCodeLockExpired()
{
}

void UFortPortalComponent::OnLinkThumbnailDownloaded(bool bSuccess, UTexture2DDynamic* InThumbnailTexture)
{
}

void UFortPortalComponent::OnMinigameStarted()
{
}

void UFortPortalComponent::OnRep_LinkCodeLockStatus()
{
}

void UFortPortalComponent::OnRep_LinkDataErrorStatus()
{
}

void UFortPortalComponent::OnRep_LoadedLinkData()
{
}

void UFortPortalComponent::ServerSetLinkCode(const FOnlineLinkId& InLinkId, bool bIgnoreCanSetLinkCode, bool bFromDAD, bool bCalledByModerator)
{
}

void UFortPortalComponent::ServerSetLinkCode_Complete(bool bSuccess, const FString& ErrorMessage, const FCreativeLoadedLinkData& InLinkData)
{
}

void UFortPortalComponent::SetLinkDataLoaded(const FCreativeLoadedLinkData& InLinkData)
{
}

void UFortPortalComponent::SetLockExpirationSecondsToNotOverrideCVar()
{
}

void UFortPortalComponent::SetLockOverrideExpirationSeconds(int32 NewExpirationSeconds)
{
}

void UFortPortalComponent::SetResetCodeAfterCooldown(bool bNewResetCodeAfterCooldown)
{
}

void UFortPortalComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortPortalComponent, LoadedLinkData);
	DOREPLIFETIME(UFortPortalComponent, LinkDataErrorStatus);
	DOREPLIFETIME(UFortPortalComponent, LinkCodeLockMode);
	DOREPLIFETIME(UFortPortalComponent, LinkCodeLockStatus);
	DOREPLIFETIME(UFortPortalComponent, bHasValidLinkData);
	DOREPLIFETIME(UFortPortalComponent, bLinkRequiresCreativeContent);
	DOREPLIFETIME(UFortPortalComponent, LinkCodeLockExpirationTime);
}

// Copyright Epic Games, Inc. All Rights Reserved.

#include "UPictureInPictureSubsystem.h"

void UPictureInPictureSubsystem::EnableFullScreenPiPOption(const bool bEnable)
{
}

bool UPictureInPictureSubsystem::GetAutoEnableSetting()
{
	return false;
}

UPictureInPictureClient* UPictureInPictureSubsystem::GetCurrentPartnerClient()
{
	return nullptr;
}

UPictureInPictureMediaController* UPictureInPictureSubsystem::GetCurrentPartnerController()
{
	return nullptr;
}

UPictureInPicturePartnerControls* UPictureInPictureSubsystem::GetCurrentPartnerControls()
{
	return nullptr;
}

UPictureInPicturePartnerDataAsset* UPictureInPictureSubsystem::GetCurrentPartnerItem()
{
	return nullptr;
}

void UPictureInPictureSubsystem::GetLastUsedPartner(FString& OutPartnerName)
{
}

void UPictureInPictureSubsystem::GetLastUsedSource(FString& OutPartnerSourceName)
{
}

UPictureInPictureClient* UPictureInPictureSubsystem::GetPartnerClient(const FString& PartnerName)
{
	return nullptr;
}

UPictureInPictureMediaController* UPictureInPictureSubsystem::GetPartnerController(const FString& PartnerName)
{
	return nullptr;
}

UPictureInPicturePartnerControls* UPictureInPictureSubsystem::GetPartnerControls(const FString& PartnerName)
{
	return nullptr;
}

UPictureInPicturePartnerDataAsset* UPictureInPictureSubsystem::GetPartnerItem(const FString& PartnerName)
{
	return nullptr;
}

const TArray<UPictureInPicturePartnerDataAsset*>& UPictureInPictureSubsystem::GetPartnerItemList()
{
	static TArray<UPictureInPicturePartnerDataAsset*> Dummy;
	return Dummy;
}

void UPictureInPictureSubsystem::HandleFNEventsSetCurrentMediaControllerEnabled(bool InEnabled)
{
}

void UPictureInPictureSubsystem::HandleMediaSourceRequest()
{
}

bool UPictureInPictureSubsystem::IsPartnerListUpdated()
{
	return false;
}

void UPictureInPictureSubsystem::OnCMSEventInvalid(const UMediaCMSEvent* InvalidEvent)
{
}

void UPictureInPictureSubsystem::OnCMSEventValid(const UMediaCMSEvent* ValidEvent)
{
}

void UPictureInPictureSubsystem::OnCurrentPartnerSourceSelected(const FPiPPartnerSource& SelectedSource)
{
}

void UPictureInPictureSubsystem::ResumeCurrentMediaController()
{
}

void UPictureInPictureSubsystem::ShutdownAllPartners()
{
}

void UPictureInPictureSubsystem::StoreAutoEnableSetting(bool InUserEnabled)
{
}

void UPictureInPictureSubsystem::StoreLastUsedPartner(const FString& InPartnerName)
{
}

void UPictureInPictureSubsystem::StoreLastUsedSource(const FString& InPartnerSourceName)
{
}

void UPictureInPictureSubsystem::SuspendCurrentMediaController()
{
}

void UPictureInPictureSubsystem::ToggleFullScreenPiP()
{
}

void UPictureInPictureSubsystem::UpdatePartnerItemList(UObject* InWorldContext, bool bForce)
{
}

// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortCreativeMiniGameInfo.h"

UFortCreativeMiniGameInfo::UFortCreativeMiniGameInfo(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

bool UFortCreativeMiniGameInfo::AreDetailsToggleable() const
{
	return false;
}

bool UFortCreativeMiniGameInfo::ForceRefresh(bool bSetupInputComponent)
{
	return false;
}

void UFortCreativeMiniGameInfo::GetCreatorInformation(FString& OutCreatorName, FString& OutSupportCode) const
{
}

void UFortCreativeMiniGameInfo::GetIslandDescriptionLocationData(FMargin& Margin, TEnumAsByte<EHorizontalAlignment>& Alignment)
{
}

TArray<FCreativeIslandDescriptionTag> UFortCreativeMiniGameInfo::GetIslandDescriptionTags() const
{
	return TArray<FCreativeIslandDescriptionTag>();
}

void UFortCreativeMiniGameInfo::HandleCreativePlotLinkedVolumeChanged(AFortVolume* CreativeLinkedVolume)
{
}

bool UFortCreativeMiniGameInfo::IsStartGameEnabled() const
{
	return false;
}

void UFortCreativeMiniGameInfo::OnCreatorNameChanged_Implementation(const FText& CreatorName)
{
}

void UFortCreativeMiniGameInfo::OnGameInfoBulletsChanged_Implementation(const TArray<FString>& GameInfoBullets)
{
}

void UFortCreativeMiniGameInfo::OnIslandTitleChanged_Implementation(const FText& IslandName)
{
}

void UFortCreativeMiniGameInfo::OnSupportCodeChanged_Implementation(const FText& SupportCode)
{
}

void UFortCreativeMiniGameInfo::OnVisible()
{
}

void UFortCreativeMiniGameInfo::PopPanelInputComponent()
{
}

void UFortCreativeMiniGameInfo::PushPanelInputComponent()
{
}

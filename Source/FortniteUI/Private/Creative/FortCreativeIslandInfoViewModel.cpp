// Copyright Epic Games, Inc. All Rights Reserved.

#include "Creative/FortCreativeIslandInfoViewModel.h"

FText UFortCreativeIslandInfoViewModel::GetIslandCode() const
{
	return FText();
}

TArray<FCreativeIslandDescriptionTag> UFortCreativeIslandInfoViewModel::GetIslandDescriptionTags() const
{
	return TArray<FCreativeIslandDescriptionTag>();
}

FText UFortCreativeIslandInfoViewModel::GetIslandTitle() const
{
	return FText();
}

void UFortCreativeIslandInfoViewModel::HandleDownloadThumbnailComplete(const bool bSuccess, UTexture2DDynamic* InThumbnailTexture)
{
}

void UFortCreativeIslandInfoViewModel::HandleIslandMetaDataUpdateComplete(const FString& Error)
{
}

void UFortCreativeIslandInfoViewModel::HandleLinkDataQueryComplete(const bool bSuccess, const FString& ErrorMessage, const FCreativeLoadedLinkData& LinkData)
{
}

void UFortCreativeIslandInfoViewModel::InitializeViewModel()
{
}

bool UFortCreativeIslandInfoViewModel::IsPlayerInAnExperienceTheyOwn() const
{
	return false;
}

void UFortCreativeIslandInfoViewModel::SetIslandDescriptionTags(const TArray<FCreativeIslandDescriptionTag>& IslandDescriptionTags)
{
}

void UFortCreativeIslandInfoViewModel::UnbindViewModel()
{
}

void UFortCreativeIslandInfoViewModel::UpdateCreativePlotData(const FString& NewIslandTitle, const TArray<FString>& NewIslandIntroductions)
{
}

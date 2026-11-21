// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortLinkDataManager.h"

void UFortLinkDataManager::DownloadThumbnail(const FCreativeLoadedLinkData& LinkData, const FOnDownloadLinkThumbnailComplete& Callback)
{
}

TArray<FCreativeIslandDescriptionTag> UFortLinkDataManager::GetIslandDescriptionTags(const FCreativeLoadedLinkData& LinkData) const
{
	return TArray<FCreativeIslandDescriptionTag>();
}

FText UFortLinkDataManager::GetLinkIntroduction(const FCreativeLoadedLinkData& LinkData) const
{
	return FText();
}

FText UFortLinkDataManager::GetLinkTagline(const FCreativeLoadedLinkData& LinkData) const
{
	return FText();
}

FText UFortLinkDataManager::GetLinkTitle(const FCreativeLoadedLinkData& LinkData) const
{
	return FText();
}

void UFortLinkDataManager::QueryLinkDataByCode(const FOnlineLinkId& LinkId, const FOnQueryLinkDataComplete& Callback, bool bCalledByModerator)
{
}

void UFortLinkDataManager::QueryQueuedLinkData()
{
}

void UFortLinkDataManager::QueueLinkDataQueryByCode(const FOnlineLinkId& LinkId, const FOnQueryLinkDataComplete& Callback, bool bCalledByModerator)
{
}

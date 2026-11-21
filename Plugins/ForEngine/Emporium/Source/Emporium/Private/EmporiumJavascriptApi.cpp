// Copyright Epic Games, Inc. All Rights Reserved.

#include "EmporiumJavascriptApi.h"

void UEmporiumJavascriptApi::AddSourceToProject(const FString& Url, const FString& AssetMetadataJson)
{
}

void UEmporiumJavascriptApi::AddVersePathToProject(const FString& VersePath, const FString& AssetMetadataJson)
{
}

void UEmporiumJavascriptApi::AnalyticsOpen3dViewer(const FString& AssetNamespace, const FString& AssetId, const FString& OfferId)
{
}

void UEmporiumJavascriptApi::AnalyticsPdpPageView(const FString& AssetNamespace, const FString& AssetId, const FString& OfferId, const FString& PointOfOrigin)
{
}

void UEmporiumJavascriptApi::AnalyticsSearchQueried(const FString& SearchText, const FString& Categories, const FString& Tags, const FString& Filters, const FString& SortValue, const FString& SearchResults)
{
}

void UEmporiumJavascriptApi::CopyToClipboard(const FString& Content)
{
}

void UEmporiumJavascriptApi::DragStart(const FString& VersePath, const FString& AssetMetadataJson)
{
}

int32 UEmporiumJavascriptApi::GetApiVersion()
{
	return int32();
}

FString UEmporiumJavascriptApi::GetAuthToken()
{
	return FString();
}

TArray<FString> UEmporiumJavascriptApi::GetProjectVersePaths()
{
	return TArray<FString>();
}

void UEmporiumJavascriptApi::LocalDownload(const FString& Url, const FString& AssetMetadataJson)
{
}

void UEmporiumJavascriptApi::LogDisplay(const FString& Message)
{
}

void UEmporiumJavascriptApi::LogError(const FString& Message)
{
}

void UEmporiumJavascriptApi::LogVerbose(const FString& Message)
{
}

void UEmporiumJavascriptApi::LogWarning(const FString& Message)
{
}

void UEmporiumJavascriptApi::OpenPluginSettings()
{
}

bool UEmporiumJavascriptApi::OpenURLInBrowser(const FString& Url)
{
	return false;
}

void UEmporiumJavascriptApi::SendAnalyticsEvent(const FString& EventName, const FString& AssetMetadataJson)
{
}

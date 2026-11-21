// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "EmporiumJavascriptApi.generated.h"

UCLASS()
class UEmporiumJavascriptApi : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void AddSourceToProject(const FString& Url, const FString& AssetMetadataJson);

	UFUNCTION()
	void AddVersePathToProject(const FString& VersePath, const FString& AssetMetadataJson);

	UFUNCTION()
	void AnalyticsOpen3dViewer(const FString& AssetNamespace, const FString& AssetId, const FString& OfferId);

	UFUNCTION()
	void AnalyticsPdpPageView(const FString& AssetNamespace, const FString& AssetId, const FString& OfferId, const FString& PointOfOrigin);

	UFUNCTION()
	void AnalyticsSearchQueried(const FString& SearchText, const FString& Categories, const FString& Tags, const FString& Filters, const FString& SortValue, const FString& SearchResults);

	UFUNCTION()
	void CopyToClipboard(const FString& Content);

	UFUNCTION()
	void DragStart(const FString& VersePath, const FString& AssetMetadataJson);

	UFUNCTION()
	int32 GetApiVersion();

	UFUNCTION()
	FString GetAuthToken();

	UFUNCTION()
	TArray<FString> GetProjectVersePaths();

	UFUNCTION()
	void LocalDownload(const FString& Url, const FString& AssetMetadataJson);

	UFUNCTION()
	void LogDisplay(const FString& Message);

	UFUNCTION()
	void LogError(const FString& Message);

	UFUNCTION()
	void LogVerbose(const FString& Message);

	UFUNCTION()
	void LogWarning(const FString& Message);

	UFUNCTION()
	void OpenPluginSettings();

	UFUNCTION()
	bool OpenURLInBrowser(const FString& Url);

	UFUNCTION()
	void SendAnalyticsEvent(const FString& EventName, const FString& AssetMetadataJson);

};


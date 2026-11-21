// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Creative/FortCreativeLoadedLinkData.h"
#include "Creative/FortCreativeTypes.h"
#include "OnlineLinkId.h"
#include "FortLinkDataManager.generated.h"

class UTexture2DDynamic;

UDELEGATE()
DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnDownloadLinkThumbnailComplete, bool, bSuccess, UTexture2DDynamic*, InThumbnailTexture);

UDELEGATE()
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FOnQueryLinkDataComplete, bool, bSuccess, FString, ErrorMessage, const FCreativeLoadedLinkData&, LinkData);

UCLASS(Config=Game, BlueprintType)
class UFortLinkDataManager : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void DownloadThumbnail(const FCreativeLoadedLinkData& LinkData, const FOnDownloadLinkThumbnailComplete& Callback);

	UFUNCTION(BlueprintPure)
	TArray<FCreativeIslandDescriptionTag> GetIslandDescriptionTags(const FCreativeLoadedLinkData& LinkData) const;

	UFUNCTION(BlueprintPure)
	FText GetLinkIntroduction(const FCreativeLoadedLinkData& LinkData) const;

	UFUNCTION(BlueprintPure)
	FText GetLinkTagline(const FCreativeLoadedLinkData& LinkData) const;

	UFUNCTION(BlueprintPure)
	FText GetLinkTitle(const FCreativeLoadedLinkData& LinkData) const;

	UFUNCTION(BlueprintCallable)
	void QueryLinkDataByCode(const FOnlineLinkId& LinkId, const FOnQueryLinkDataComplete& Callback, bool bCalledByModerator = false);

	UFUNCTION(BlueprintCallable)
	void QueueLinkDataQueryByCode(const FOnlineLinkId& LinkId, const FOnQueryLinkDataComplete& Callback, bool bCalledByModerator);

private:
	UFUNCTION()
	void QueryQueuedLinkData();

};


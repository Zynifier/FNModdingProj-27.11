// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "FMUEFNResolver.generated.h"

class AFortPlayerState;

UCLASS()
class FMCORERUNTIME_API UFMUEFNResolver : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="FMUEFNResolver")
	const TSet<FString>& GetFinishedDownloads() const;

	UFUNCTION(BlueprintPure, Category="FMUEFNResolver")
	const TSet<FString>& GetInProgressDownloads() const;

	UFUNCTION(BlueprintPure, Category="FMUEFNResolver")
	bool IsDownloadInProgress() const;

	UFUNCTION(BlueprintCallable, Category="FMUEFNResolver")
	bool ResolveAndLoadLinkCode(const FString& LinkCode, const AFortPlayerState* PlayerState);

protected:
	UPROPERTY()
	TSet<FString> DownloadingLinkCodes;

	UPROPERTY()
	TSet<FString> DownloadedLinkCodes;

private:
	UFUNCTION()
	void HandleGameFeatureLoadComplete(bool bSuccess, const FString& LinkCode);

	UFUNCTION()
	void HandleResolveComplete(bool bSuccess, const FString& LinkCode, const TArray<FString>& PluginURLs);

};


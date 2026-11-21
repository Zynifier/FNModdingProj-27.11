// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "EpicMediaMetadataTypes.h"
#include "EpicMediaOptions.h"
#include "EpicMediaMetadataResolver.generated.h"

class UEpicMediaCDNHostnames;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnMetadataResultExt, const FEpicMediaMetadataExt&, FullMetaData, bool, Succeeded);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnRetrieveMediaUrlResult, FString, RetrievedUrl);

UCLASS(BlueprintType)
class EPICMEDIAMETADATARESOLVER_API UEpicMediaMetadataResolver : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="MediaMetadataResolver")
	bool GetBlurl(const FString& InVUID, const bool bInBlurlLive, const FEpicMediaOptions InMediaOptions);

	UFUNCTION(BlueprintCallable, Category="MediaMetadataResolver")
	bool GetData(const FString& UID, const bool bLive, const FEpicMediaOptions InMediaOptions);

	UPROPERTY(BlueprintAssignable)
	FOnRetrieveMediaUrlResult OnSuccess;

	UPROPERTY(BlueprintAssignable)
	FOnRetrieveMediaUrlResult OnFailure;

	UPROPERTY(BlueprintAssignable)
	FOnMetadataResultExt MetadataResultExt;

	UPROPERTY(BlueprintReadOnly, Transient, Category="MediaMetadataResolver")
	TObjectPtr<UEpicMediaCDNHostnames> CDNHostNames;

};


// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonButtonBase.h"
#include "FortGameUserSettings.h"
#include "FortQualityModeTile.generated.h"

class UTexture2D;

UCLASS(meta=(DisableNativeTick))
class UFortQualityModeTile : public UCommonButtonBase
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent, Category="FortQualityModeTile", meta=(DisplayName="On Selected State Changed"))
	void OnSelectedStateChanged(bool bIsSelected);

	UFUNCTION(BlueprintImplementableEvent, Category="FortQualityModeTile", meta=(DisplayName="On Size Info Received"))
	void OnSizeInfoReceived();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Quality Mode Info")
	EFortContentQualityLevel QualityModeLevel;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Quality Mode Info")
	FText QualityLevelName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Quality Mode Info")
	FText QualityLevelDescription;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Quality Mode Info")
	TObjectPtr<UTexture2D> QualityLevelImage;

	UPROPERTY(BlueprintReadOnly, Category="FortQualityModeTile")
	FText AdditionalDownloadSize;

	UPROPERTY(BlueprintReadOnly, Category="FortQualityModeTile")
	FText TotalBuildSize;

};


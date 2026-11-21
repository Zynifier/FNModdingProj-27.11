// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "UObject/NoExportTypes.h"
#include "PictureInPicturePartnerData.h"
#include "PictureInPicturePlayer.generated.h"

class UFortClientSettingsRecord;
class UPictureInPictureMediaPlayerCtrl;
class USoundSubmixBase;

UCLASS(BlueprintType, Blueprintable)
class PICTUREINPICTURECORE_API UPictureInPicturePlayer : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void FlushPlayerAssetConfig();

	UFUNCTION(BlueprintCallable)
	bool IsAssetConfigSet();

	UFUNCTION(BlueprintCallable)
	bool SetPlayerAssetConfig(UPARAM(ref) FPIPVideoPlayerAssetConfig& InAssetConfig);

	UFUNCTION(BlueprintCallable)
	void UpdateStreamingPlayerSize(const FVector2D& InVector);

private:
	UFUNCTION()
	void HandleUCPAudioChanged(UFortClientSettingsRecord* Settings);

	UFUNCTION()
	void StreamedVideoOnUrlFailure(const FString URL);

	UFUNCTION()
	void StreamedVideoOnUrlSuccess(const FString URL);

	UPROPERTY(Transient)
	FPIPVideoPlayerAssetConfig AssetConfig;

	UPROPERTY(Transient)
	TObjectPtr<UPictureInPictureMediaPlayerCtrl> MediaController;

	UPROPERTY(EditAnywhere, Category="PictureInPicturePlayer")
	TObjectPtr<USoundSubmixBase> DefaultSubmix;

	UPROPERTY(EditAnywhere, Category="PictureInPicturePlayer")
	TObjectPtr<USoundSubmixBase> LicensedSubmix;

};


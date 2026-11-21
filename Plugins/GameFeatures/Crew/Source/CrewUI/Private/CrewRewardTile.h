// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonButtonBase.h"
#include "CrewRewardTile.generated.h"

class UCommonTextBlock;
class UImage;
class UTexture2D;

UCLASS(Abstract, BlueprintType, Blueprintable)
class UCrewRewardTile : public UCommonButtonBase
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintPure)
	bool IsMonthlyBenefit() const;

	UFUNCTION(BlueprintImplementableEvent)
	void OnDownloadTileImageComplete(UTexture2D* Texture);

	UFUNCTION(BlueprintImplementableEvent)
	void OnStartingDownloadTileImage();

	UFUNCTION(BlueprintImplementableEvent)
	void OnUpdateOwnedState(bool bOwned);

private:
	UPROPERTY(EditDefaultsOnly, Category="CrewRewardTile")
	float TileImageStreamoutSeconds;

	UPROPERTY(BlueprintReadOnly, Export, Category="CrewRewardTile", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_TileImage;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_TileLabel;

};


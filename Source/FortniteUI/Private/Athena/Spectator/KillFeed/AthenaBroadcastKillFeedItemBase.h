// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortHUDElementWidget.h"
#include "Spectator/AthenaBroadcastKillFeedEntryInfo.h"
#include "AthenaBroadcastKillFeedItemBase.generated.h"

class UCommonTextBlock;
class UImage;
class UMaterialInterface;

UCLASS(Abstract, MinimalAPI)
class UAthenaBroadcastKillFeedItemBase : public UFortHUDElementWidget
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="AthenaBroadcastKillFeedItemBase")
	TSoftObjectPtr<UMaterialInterface> EliminationIcon;

	UPROPERTY(EditAnywhere, Category="AthenaBroadcastKillFeedItemBase")
	TSoftObjectPtr<UMaterialInterface> StormIcon;

	UPROPERTY(EditAnywhere, Category="AthenaBroadcastKillFeedItemBase")
	TSoftObjectPtr<UMaterialInterface> FallDamageIcon;

	UPROPERTY(EditAnywhere, Category="AthenaBroadcastKillFeedItemBase")
	TSoftObjectPtr<UMaterialInterface> ExplosionIcon;

	UPROPERTY(EditAnywhere, Category="AthenaBroadcastKillFeedItemBase")
	TSoftObjectPtr<UMaterialInterface> DbnoIcon;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_InstigatorName;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_VictimName;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_EntryIcon;

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Design Time", meta=(DisplayName="Entry Info"))
	FAthenaBroadcastKillFeedEntryInfo DesignTime_EntryInfo;
#endif

};


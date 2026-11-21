// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "FortProfileStatsMainTile.generated.h"

class UCommonTextBlock;

UCLASS(meta=(DisableNativeTick))
class UFortProfileStatsMainTile : public UCommonUserWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortProfileStatsMainTile", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> ValueTextBlock;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortProfileStatsMainTile", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> NameTextBlock;

	UPROPERTY(EditAnywhere, Category="FortProfileStatsMainTile")
	int32 TileTier;

};


// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "FortActivityCategoryTilePanel.generated.h"

class UCommonTextBlock;
class UFortActivityTileView;
class UFortCreativeDiscoveryActivityProvider;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortActivityCategoryTilePanel : public UCommonUserWidget
{
	GENERATED_BODY()

private:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortActivityCategoryTilePanel", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UFortActivityTileView> TileView_Categories;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortActivityCategoryTilePanel", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_Title;

	UPROPERTY(EditInstanceOnly, Category="FortActivityCategoryTilePanel")
	int32 TileViewQueryThreshold;

	UPROPERTY(Transient)
	TObjectPtr<UFortCreativeDiscoveryActivityProvider> CachedActivityProvider;

};


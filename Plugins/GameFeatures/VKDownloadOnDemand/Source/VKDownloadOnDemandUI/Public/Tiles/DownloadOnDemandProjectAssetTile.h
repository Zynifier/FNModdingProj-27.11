// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/IUserObjectListEntry.h"
#include "UObject/NoExportTypes.h"
#include "CommonButtonLegacy.h"
#include "DownloadOnDemandProjectAssetTile.generated.h"

class UCommonNumericTextBlock;
class UDownloadOnDemandProjectAssetTileInitializer;
class UFortPlaysetPropItemDefinition;
class UImage;

UCLASS()
class UDownloadOnDemandProjectAssetTile : public UCommonButtonLegacy, public IUserObjectListEntry
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	TObjectPtr<UDownloadOnDemandProjectAssetTileInitializer> Initializer;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_Item;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_Spinner;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonNumericTextBlock> NumericTextBlock_ItemCount;

};

UCLASS()
class UDownloadOnDemandProjectAssetTileInitializer : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	TObjectPtr<UFortPlaysetPropItemDefinition> PropItemDefinition;

};


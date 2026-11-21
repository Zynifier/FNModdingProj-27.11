// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortRarityEnum.h"
#include "MakeDesignAsset/FortEditorTool_MakeAssetBase.h"
#include "FortEditorTool_MakeItemAssetBase.generated.h"

UCLASS(Abstract)
class UFortEditorTool_MakeItemAssetBase : public UFortEditorTool_MakeAssetBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Item Definition", meta=(MustModify))
	FText DisplayName;

	UPROPERTY(EditAnywhere, Category="Item Definition", meta=(MustModify))
	FText LongDescription;

	UPROPERTY(EditAnywhere, Category="Item Definition")
	EFortRarity Rarity;

};


// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "STW/Items/FortHomebaseNodeItemDefinition.h"
#include "SFortGenerateHomebaseNodeItemDefinitionsForm.generated.h"

class UTexture2D;

USTRUCT()
struct FGenHBNodeItemDefsDesignerData
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, Category="GenHBNodeItemDefsDesignerData")
	FString CSVFileLocation;

	UPROPERTY(VisibleAnywhere, Category="GenHBNodeItemDefsDesignerData")
	FString ItemDefinitionDestinationPath;

	UPROPERTY(EditAnywhere, Category="GenHBNodeItemDefsDesignerData")
	bool bDeleteUnreferencedHomebaseNodes;

};

USTRUCT()
struct FHomebaseNodeImportData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString DisplayName;

	UPROPERTY()
	TArray<FHomebaseNodeLevel> LevelData;

	UPROPERTY()
	EHomebaseNodeType DisplayType;

	UPROPERTY()
	TSoftObjectPtr<UTexture2D> SmallPreviewImage;

	UPROPERTY()
	TSoftObjectPtr<UTexture2D> LargePreviewImage;

};


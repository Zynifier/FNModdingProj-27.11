// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "CommonActivatablePanelLegacy.h"
#include "EpicCMSScreen.generated.h"

class UDataTable;
class UEpicCMSLayoutBase;
class UUserWidget;

USTRUCT()
struct FEpicCMSLayoutTypeMapping : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Layout")
	TSoftClassPtr<UEpicCMSLayoutBase> LayoutType;

};

UCLASS(Abstract)
class EPICCMSUIFRAMEWORK_API UEpicCMSScreenBase : public UCommonActivatablePanelLegacy
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="CMS Screen")
	FString TileSetFieldName;

protected:
	UPROPERTY(EditAnywhere, Category="CMS Screen")
	TSoftObjectPtr<UDataTable> TileTypeToTileClassDataTable;

	UPROPERTY(EditAnywhere, Category="Layout")
	TSoftClassPtr<UUserWidget> LayoutErrorClass;

	UPROPERTY(EditAnywhere, Category="Layout")
	TSoftObjectPtr<UDataTable> LayoutTypeToLayoutClassDataTable;

};


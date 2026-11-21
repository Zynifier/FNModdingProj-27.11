// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Engine/DataTable.h"
#include "EpicCMSLayout.generated.h"

class UEpicCMSTileBase;
class UEpicCMSTileCarousel;

USTRUCT()
struct FEpicCMSTileTypeMapping : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="CMS Tile")
	TSoftClassPtr<UEpicCMSTileBase> TileClass;

};

USTRUCT()
struct FSlotDescription
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Layout")
	FName SlotName;

	UPROPERTY(EditAnywhere, Category="Layout")
	int32 ColumnCount;

	UPROPERTY(EditAnywhere, Category="Layout")
	int32 RowCount;

	UPROPERTY(EditAnywhere, Category="Layout")
	bool bUseFeaturedTextStyle;

	UPROPERTY(EditAnywhere, Category="Layout")
	bool bEnableAutoScroll;

};

UCLASS(Abstract)
class EPICCMSUIFRAMEWORK_API UEpicCMSLayoutBase : public UUserWidget
{
	GENERATED_BODY()

public:
	UEpicCMSLayoutBase(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UPROPERTY(EditAnywhere, Category="Layout")
	TArray<FSlotDescription> CarouselSlotDescriptions;

protected:
	UPROPERTY(EditAnywhere, Category="Layout")
	TSubclassOf<UEpicCMSTileCarousel> CarouselClass;

};


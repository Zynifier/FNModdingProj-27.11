// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ListViewBase.h"
#include "Types/SlateEnums.h"
#include "FortActivityListView.generated.h"

class UFortActivityBrowserTileBase;
enum class EActivityBrowserTileStyle : uint8;

UENUM(BlueprintType)
enum class EActivityBrowserTileStyle : uint8
{
	// When adding something here, make sure its string is defined in ActivityBrowserTileStyleUtility::ConvertFromFName

	Default = 0,
	Minimal = 1,
	Detailed = 2,
};

UCLASS(meta=(EntryClass="FortActivityBrowserTileBase"))
class UFortActivityListView : public UListViewBase
{
	GENERATED_BODY()

public:
	UFortActivityListView(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UFUNCTION(BlueprintCallable)
	void AddTileType(EActivityBrowserTileStyle Style, TSubclassOf<UFortActivityBrowserTileBase> WidgetClass);

	UFUNCTION(BlueprintPure)
	int32 GetInViewCount() const;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Input", meta=(DisplayName="Directional Navigation Time Threshold"))
	float DirectionalNavigationTimeThreshold;

protected:
	UPROPERTY(EditAnywhere, Category="ListView")
	TEnumAsByte<EOrientation> Orientation;

	UPROPERTY(EditAnywhere, Category="ListEntries", meta=(ClampMin="0"))
	float EntrySpacing;

private:
	UPROPERTY(EditAnywhere, Category="ListView")
	bool bCircularNavigationEnabled;

	UPROPERTY(EditAnywhere, Category="ListEntries")
	TMap<EActivityBrowserTileStyle, TSubclassOf<UFortActivityBrowserTileBase>> TileTypes;

};


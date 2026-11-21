// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ListViewBase.h"
#include "Types/SlateEnums.h"
#include "AthenaCollectionListView.generated.h"

UCLASS(meta=(EntryClass="AthenaCollectionListGroupEntry"))
class UAthenaCollectionListView : public UListViewBase
{
	GENERATED_BODY()

public:
	UAthenaCollectionListView(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

protected:
	UPROPERTY(EditAnywhere, Category="AthenaCollectionListView")
	float EntrySpacing;

	UPROPERTY(EditAnywhere, Category="AthenaCollectionListView")
	float FinalEntrySpacing;

	UPROPERTY(EditAnywhere, Category="AthenaCollectionListView")
	TEnumAsByte<EOrientation> Orientation;

private:
	UPROPERTY(EditAnywhere, Category="AthenaCollectionListView", meta=(ClampMin="1", EditCondition="Orientation == EOrientation::Orient_Horizontal", EditConditionHides))
	int32 NumRows;

	UPROPERTY(EditAnywhere, Category="AthenaCollectionListView", meta=(EditCondition="Orientation == EOrientation::Orient_Horizontal", EditConditionHides))
	bool bOverrideNumRowsMobile;

	UPROPERTY(EditAnywhere, Category="AthenaCollectionListView", meta=(ClampMin="1", EditCondition="Orientation == EOrientation::Orient_Horizontal && bOverrideNumRowsMobile", EditConditionHides))
	int32 NumRowsMobile;

	UPROPERTY(EditAnywhere, Category="AthenaCollectionListView", meta=(ClampMin="1", EditCondition="Orientation == EOrientation::Orient_Vertical", EditConditionHides))
	int32 NumColumns;

	UPROPERTY(EditAnywhere, Category="AthenaCollectionListView", meta=(EditCondition="Orientation == EOrientation::Orient_Vertical", EditConditionHides))
	bool bOverrideNumColumnsMobile;

	UPROPERTY(EditAnywhere, Category="AthenaCollectionListView", meta=(ClampMin="1", EditCondition="Orientation == EOrientation::Orient_Vertical && bOverrideNumColumnsMobile", EditConditionHides))
	int32 NumColumnsMobile;

	UPROPERTY(EditAnywhere, Category="AthenaCollectionListView")
	bool bSelectEntryOnFocusForTouch;

};


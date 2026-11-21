// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/PanelSlot.h"
#include "Types/SlateEnums.h"
#include "FortActorCanvasSlot.generated.h"

UCLASS(MinimalAPI)
class UFortActorCanvasSlot : public UPanelSlot
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Layout|Actor Canvas Slot")
	void SetCanAutoRemove(bool bAllowAutoRemove);

	UFUNCTION(BlueprintCallable, Category="Layout|Actor Canvas Slot")
	void SetHorizontalAlignment(EHorizontalAlignment InHorizontalAlignment);

	UFUNCTION(BlueprintCallable, Category="Layout|Actor Canvas Slot")
	void SetVerticalAlignment(EVerticalAlignment InVerticalAlignment);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Layout|Actor Canvas Slot")
	TEnumAsByte<EHorizontalAlignment> HorizontalAlignment;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Layout|Actor Canvas Slot")
	TEnumAsByte<EVerticalAlignment> VerticalAlignment;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Layout|Actor Canvas Slot")
	bool bCanAutoRemove;

};


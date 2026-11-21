// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Types/SlateEnums.h"
#include "GridPicker/FortGridWidgetBase.h"
#include "FortGridPickerButton.generated.h"

class UFortGridPickerGrid;

UCLASS()
class UFortGridPickerButton : public UFortGridWidgetBase
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_DELEGATE_RetVal(UFortGridPickerGrid*, FCreateGridWidget);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnIsGridPickerOpenChanged, bool, IsOpen);

public:
	UFUNCTION(BlueprintCallable, Category="Interaction")
	void OnButtonClicked();

	UFUNCTION(BlueprintCallable, Category="Interaction")
	void SetIsOpen(const bool ShouldBeOpen);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Layout")
	TEnumAsByte<EMenuPlacement> GridPlacement;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Export, Category="Behavior", meta=(EditInline="true"))
	TObjectPtr<UFortGridPickerGrid> GridWidget;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Behavior")
	bool bCloseOnTileClicked;

	UPROPERTY()
	FCreateGridWidget GridWidgetDelegate;

	UPROPERTY(BlueprintAssignable, Category="Grid Picker|Event")
	FOnIsGridPickerOpenChanged OnGridPickerOpenChanged;

};


// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/NamedSlotInterface.h"
#include "Components/Widget.h"
#include "FortModalContainerData.h"
#include "FortUITypes.h"
#include "FortModalContainerWidget.generated.h"

class UFortModalContainerData;
class UWidget;

UENUM()
enum class EModalContainerSlot : uint8
{
	Top = 0,
	Middle = 1,
	Bottom = 2,
	Background = 3,
	Max = 4 UMETA(Hidden),
};

UCLASS(ClassGroup=("UI"), meta=(Category="Fortnite UI", DisplayName="Modal Container"))
class UFortModalContainerWidget : public UWidget, public INamedSlotInterface
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Modal Container Data", meta=(DesignerRebuild="TRUE", DisplayName="Apply Size Constraints"))
	EModalContainerSize SizeConstraint;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Modal Container Data", meta=(DisplayName="Size Constraint Defaults"))
	TArray<FFortModalContainerSizeEntry> DefaultSizeEntries;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Modal Container Data", meta=(DisplayName="Size Constraint Overrides"))
	TObjectPtr<UFortModalContainerData> OverrideSizeEntries;

	virtual void GetSlotNames(TArray<FName>& SlotNames) const override;

	virtual UWidget* GetContentForSlot(FName SlotName) const override;

	virtual void SetContentForSlot(FName SlotName, UWidget* Content) override;

private:
	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UWidget> TopContent;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UWidget> MiddleContent;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UWidget> BottomContent;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UWidget> BackgroudContent;

};


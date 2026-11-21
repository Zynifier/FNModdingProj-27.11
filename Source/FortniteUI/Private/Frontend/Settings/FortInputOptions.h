// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonInputTypeEnum.h"
#include "InputCoreTypes.h"
#include "Frontend/Settings/FortOptionsTab.h"
#include "FortInputOptions.generated.h"

class UCommonListView;
class UCommonTextBlock;
class UFortOptionsMenuInputData;
class UObject;
class UUserWidget;
class UWidget;
enum class EFortInputActionGroup : uint8;

USTRUCT(BlueprintType)
struct FFortActionBeingUnbound
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="FortActionBeingUnbound")
	FName ActionName;

	UPROPERTY(BlueprintReadOnly, Category="FortActionBeingUnbound")
	int32 InputIndex;

};

UCLASS(meta=(DisableNativeTick))
class UFortInputOptions : public UFortOptionsTab
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable, Category="FortInputOptions")
	virtual void ChangeBinding(bool bIsPrimarySlot, int32 Input, FKey NewKey);

	UFUNCTION(BlueprintCallable, Category="FortInputOptions")
	virtual void ConstructKeyBindList();

	UFUNCTION(BlueprintPure, Category="FortInputOptions")
	virtual FFortActionBeingUnbound GetActionBeingUnbound(bool bIsPrimarySlot, int32 Input, FKey NewKey) const;

	UFUNCTION(BlueprintPure, Category="FortInputOptions")
	TArray<UFortOptionsMenuInputData*> GetActionItemsInGroup(const EFortInputActionGroup InputActionGroup) const;

	UFUNCTION(BlueprintPure, Category="FortInputOptions", meta=(DisplayName="GetBindedKeyName"))
	FText GetBoundKeyNameBP(int32 RowIndex, bool IsPrimary) const;

	UFUNCTION(BlueprintPure, Category="FortInputOptions")
	int32 GetInputDataIndexForActionName(const FName ActionName) const;

	UFUNCTION(BlueprintPure, Category="FortInputOptions", meta=(DisplayName="GetInputDisplayText"))
	FText GetInputDisplayTextBP(int32 RowIndex) const;

	UFUNCTION(BlueprintCallable, Category="FortInputOptions")
	UWidget* GetListWidget(UObject* Item);

	UFUNCTION(BlueprintImplementableEvent, Category="FOrtInputOptions")
	void HandleUsingGamepadChanged(ECommonInputType NewInputType);

	UPROPERTY(BlueprintReadOnly, Category="FortInputOptions")
	TArray<TObjectPtr<UFortOptionsMenuInputData>> InputData;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortInputOptions", meta=(BindWidget, EditInline="true", OptionalWidget="TRUE"))
	TObjectPtr<UCommonListView> InputCommonListView;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortInputOptions", meta=(BindWidget, EditInline="true", OptionalWidget="TRUE"))
	TObjectPtr<UCommonTextBlock> TooltipDisplay;

	UPROPERTY(EditAnywhere, Category="FortInputOptions")
	TSubclassOf<UUserWidget> InputCategoryWidgetClass;

};


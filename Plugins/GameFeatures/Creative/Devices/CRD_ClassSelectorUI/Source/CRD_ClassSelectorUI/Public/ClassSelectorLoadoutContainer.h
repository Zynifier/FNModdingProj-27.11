// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "ClassSelectorLoadoutContainer.generated.h"

class UAthenaItemElementWidgetBase;
class UFortItemDefinition;
class UWrapBox;

UCLASS()
class UClassSelectorLoadoutContainer : public UCommonUserWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UWrapBox> WrapBox;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="ClassSelectorLoadoutContainer")
	TSubclassOf<UAthenaItemElementWidgetBase> EntryWidgetClass;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TArray<TObjectPtr<UAthenaItemElementWidgetBase>> EntryWidgets;

	UPROPERTY(EditAnywhere, Category="ClassSelectorLoadoutContainer")
	TObjectPtr<UFortItemDefinition> PreviewItemDef;

	UPROPERTY(EditAnywhere, Category="ClassSelectorLoadoutContainer")
	int32 NumPreviewEntries;

};


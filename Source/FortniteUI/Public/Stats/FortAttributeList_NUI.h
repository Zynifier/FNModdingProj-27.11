// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "FortUITypes.h"
#include "FortAttributeList_NUI.generated.h"

class UFortAttributeListItem_NUI;

UCLASS(Abstract, MinimalAPI, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortAttributeList_NUI : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Fort Attribute List")
	void ClearPreviewData();

	UFUNCTION(BlueprintImplementableEvent, Category="Fort Attribute List")
	void OnAddShownAttributeListItem(UFortAttributeListItem_NUI* AttributeListItemWidget);

	UFUNCTION(BlueprintImplementableEvent, Category="Fort Attribute List")
	void OnRemoveShownAttributeListItem(UFortAttributeListItem_NUI* AttributeListItemWidget, int32 AtIndex);

	UFUNCTION(BlueprintCallable, Category="Fort Attribute List")
	void SetData(const TArray<FFortDisplayAttribute>& Data);

	UFUNCTION(BlueprintCallable, Category="Fort Attribute List")
	void SetPreviewData(const TArray<FFortDisplayAttribute>& Data);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Fort Attribute List")
	TSubclassOf<UFortAttributeListItem_NUI> AttributeItemClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Fort Attribute List")
	bool bHoverEnabledOnElements;

protected:
	UFUNCTION(BlueprintImplementableEvent, Category="Fort Attribute List")
	void OnClearShownAttributes();

private:
	UPROPERTY(Export, meta=(EditInline="true"))
	TArray<TObjectPtr<UFortAttributeListItem_NUI>> ShownAttributeWidgets;

};


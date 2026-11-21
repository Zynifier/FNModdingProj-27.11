// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortUITypes.h"
#include "FortUserWidget.h"
#include "FortAttributeList.generated.h"

class UFortAttributeListItem;
class UVerticalBox;

UCLASS(Abstract, BlueprintType, Blueprintable)
class UFortAttributeList : public UFortUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Fort Attribute List")
	void Clear();

	UFUNCTION(BlueprintCallable, Category="Fort Attribute List")
	void ClearPreviewData();

	UFUNCTION(BlueprintCallable, Category="Fort Attribute List")
	TArray<FFortDisplayAttribute> SetData(const TArray<FFortDisplayAttribute>& Data);

	UFUNCTION(BlueprintCallable, Category="Fort Attribute List")
	void SetPreviewData(const TArray<FFortDisplayAttribute>& Data);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Fort Attribute List")
	TSubclassOf<UFortAttributeListItem> AttributeItemClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Fort Attribute List")
	bool bHoverEnabledOnElements;

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UVerticalBox> AttributeContainer;

};


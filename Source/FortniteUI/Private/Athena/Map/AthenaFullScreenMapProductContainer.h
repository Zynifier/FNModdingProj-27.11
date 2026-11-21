// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidgetPool.h"
#include "CommonActivatableWidget.h"
#include "AthenaFullScreenMapProductContainer.generated.h"

class UAthenaFullScreenMapProductGroup;
class UQuestProductGroup;
class UScrollBox;
class UVerticalBox;

UCLASS(Abstract, meta=(Category="Fortnite UI"))
class UAthenaFullScreenMapProductContainer : public UCommonActivatableWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="Product Groups")
	TSubclassOf<UAthenaFullScreenMapProductGroup> ProductGroupType;

	UPROPERTY(EditDefaultsOnly, Category="Product Groups")
	float ProductGroupPadding;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaFullScreenMapProductContainer", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UVerticalBox> VB_ProductGroups;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UScrollBox> ScrollBox_ProductGroups;

private:
	UPROPERTY(Transient)
	FUserWidgetPool ProductGroupWidgetPool;

	UPROPERTY(Export, meta=(EditInline="true"))
	TMap<UQuestProductGroup*, TObjectPtr<UAthenaFullScreenMapProductGroup>> ProductGroupInstanceMap;

};


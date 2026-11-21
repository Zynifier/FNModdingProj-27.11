// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/DynamicEntryBox.h"
#include "GameplayTagContainer.h"
#include "Cosmetics/Variants/FortMcpVariantChannelInfo.h"
#include "FortVariantEntryBox.generated.h"

class UAthenaCosmeticAccountItem;
class UAthenaCosmeticItemDefinition;
class UFortVariantEditorWidgetBase;

USTRUCT()
struct FFortVariantFilterContext
{
	GENERATED_BODY()

};

UCLASS()
class UFortVariantEntryBox : public UDynamicEntryBox
{
	GENERATED_BODY()

private:
	UPROPERTY()
	TObjectPtr<UAthenaCosmeticAccountItem> CurrentItem;

	UPROPERTY()
	TObjectPtr<UAthenaCosmeticItemDefinition> CurrentItemDef;

	UPROPERTY()
	TArray<FMcpVariantChannelInfo> CurrentItemVariants;

	UPROPERTY(Export, meta=(EditInline="true"))
	TMap<FGameplayTag, TObjectPtr<UFortVariantEditorWidgetBase>> ChannelWidgets;

};


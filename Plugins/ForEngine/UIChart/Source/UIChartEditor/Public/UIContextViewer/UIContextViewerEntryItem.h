// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/IUserObjectListEntry.h"
#include "Blueprint/UserWidget.h"
#include "GameplayTagContainer.h"
#include "Styling/SlateColor.h"
#include "UObject/NoExportTypes.h"
#include "UIContextViewerEntryItem.generated.h"

class ULocalPlayer;
class UTextBlock;
class UUIContextViewerEntryInfo;
class UUIStateChartContext;
class UUIStateChartContextEntry;

UCLASS()
class UUIContextViewerEntryInfo : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TSoftObjectPtr<UUIStateChartContext> Context;

	UPROPERTY()
	FGameplayTag Key;

	UPROPERTY()
	TSoftObjectPtr<UUIStateChartContextEntry> Entry;

	UPROPERTY()
	TSoftObjectPtr<ULocalPlayer> LocalPlayer;

};

UCLASS()
class UICHARTEDITOR_API UUIContextViewerEntryItem : public UUserWidget, public IUserObjectListEntry
{
	GENERATED_BODY()

public:
	UUIContextViewerEntryItem(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="UIContextViewerEntryItem")
	FSlateColor EmptyTextColor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="UIContextViewerEntryItem")
	FSlateColor NonEmptyTextColor;

	UPROPERTY(BlueprintReadOnly, Transient, Export, Category="UIContextViewerEntryItem", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UTextBlock> KeyTextBlock;

	UPROPERTY(BlueprintReadOnly, Transient, Export, Category="UIContextViewerEntryItem", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UTextBlock> ValueTextBlock;

	UPROPERTY(Transient)
	TObjectPtr<UUIContextViewerEntryInfo> EntryInfo;

};


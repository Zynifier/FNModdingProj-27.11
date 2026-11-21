// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/IUserObjectListEntry.h"
#include "Blueprint/UserWidget.h"
#include "GameplayTagContainer.h"
#include "UObject/NoExportTypes.h"
#include "UIContextViewerEntryList.generated.h"

class UImage;
class UListView;
class ULocalPlayer;
class UTextBlock;
class UTexture2D;
class UUIContextViewerContextInfo;
class UUIContextViewerEntryInfo;
class UUIStateChartContext;

UCLASS()
class UUIContextViewerContextInfo : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TSoftObjectPtr<ULocalPlayer> LocalPlayer;

	UPROPERTY()
	TSoftObjectPtr<UUIStateChartContext> Context;

	UPROPERTY()
	FText TitleText;

};

UCLASS()
class UICHARTEDITOR_API UUIContextViewerEntryList : public UUserWidget, public IUserObjectListEntry
{
	GENERATED_BODY()

public:
	UUIContextViewerEntryList(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="UIContextViewerEntryList")
	TObjectPtr<UTexture2D> ExpandedArrowTexture;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="UIContextViewerEntryList")
	TObjectPtr<UTexture2D> CollapsedArrowTexture;

protected:
	UFUNCTION(BlueprintCallable)
	void ToggleListExpanded();

	UPROPERTY(BlueprintReadOnly, Transient, Export, Category="UIContextViewerEntryList", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UTextBlock> TitleTextBlock;

	UPROPERTY(BlueprintReadOnly, Transient, Export, Category="UIContextViewerEntryList", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UTextBlock> QuantityTextBlock;

	UPROPERTY(BlueprintReadOnly, Transient, Export, Category="UIContextViewerEntryList", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UListView> EntryListView;

	UPROPERTY(BlueprintReadOnly, Export, Category="UIContextViewerEntryList", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> ArrowIcon;

	UPROPERTY(Transient)
	TObjectPtr<UUIContextViewerContextInfo> ContextInfo;

	UPROPERTY(Transient)
	TArray<UUIContextViewerEntryInfo*> EntryInfos;

	UPROPERTY(Transient)
	TSet<FGameplayTag> DisplayedEntryKeys;

};


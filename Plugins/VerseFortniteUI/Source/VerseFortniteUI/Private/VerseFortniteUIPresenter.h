// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UIFPresenter.h"
#include "VerseFortniteUIPresenter.generated.h"

class UCommonInputActionDomain;
class UVerseFortniteUIActivableWidgetBase;
class UVerseFortniteUINamedSlot;
class UVerseFortniteUIOverlay;
class UWidget;

USTRUCT()
struct FVerseFortniteUIPresenterElement
{
	GENERATED_BODY()

public:
	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UVerseFortniteUINamedSlot> SlotWidget;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UWidget> UMGWidget;

};

UCLASS(Config=Game)
class UVerseFortniteUIPresenter : public UUIFrameworkGameViewportPresenter
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	TArray<FVerseFortniteUIPresenterElement> Pending;

	UPROPERTY(Transient)
	TArray<FVerseFortniteUIPresenterElement> Created;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UVerseFortniteUIOverlay> PlayerGameViewport;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UVerseFortniteUIOverlay> ContentGameViewport;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UVerseFortniteUIActivableWidgetBase> PopupContainer;

	UPROPERTY(Config)
	TSoftClassPtr<UVerseFortniteUIActivableWidgetBase> WidgetForDynamicUI;

	UPROPERTY(Config)
	TSoftObjectPtr<UCommonInputActionDomain> ActionDomainForDynamicUI;

};


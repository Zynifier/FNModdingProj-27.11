// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonListView.h"
#include "FortEmporiumHomeListView.generated.h"

class UFortEmporiumItemListTabPanel;
class UWidget;

UCLASS(BlueprintType)
class UFortEmporiumHomeListView : public UCommonListView
{
	GENERATED_BODY()

public:
	UFortEmporiumHomeListView(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UFUNCTION(BlueprintCallable)
	virtual UWidget* GetFocusWidget();

private:
	UPROPERTY(Export, meta=(EditInline="true"))
	TArray<UFortEmporiumItemListTabPanel*> TabPanelList;

};

